
#include "write_exif.h"

#if 0
/* Get an existing tag, or create one if it doesn't exist */
static ExifEntry *init_tag(ExifData *exif, ExifIfd ifd, ExifTag tag)
{
	ExifEntry *entry;
	/* Return an existing tag if one exists */
	if (!((entry = exif_content_get_entry (exif->ifd[ifd], tag)))) {
	    /* Allocate a new entry */
	    entry = exif_entry_new ();
	    assert(entry != NULL); /* catch an out of memory condition */
	    entry->tag = tag; /* tag must be set before calling
				 exif_content_add_entry */

	    /* Attach the ExifEntry to an IFD */
	    exif_content_add_entry (exif->ifd[ifd], entry);

	    /* Allocate memory for the entry and fill with default data */
	    exif_entry_initialize (entry, tag);

	    /* Ownership of the ExifEntry has now been passed to the IFD.
	     * One must be very careful in accessing a structure after
	     * unref'ing it; in this case, we know "entry" won't be freed
	     * because the reference count was bumped when it was added to
	     * the IFD.
	     */
	    exif_entry_unref(entry);
	}
	return entry;
}

/* Create a brand-new tag with a data field of the given length, in the
 * given IFD. This is needed when exif_entry_initialize() isn't able to create
 * this type of tag itself, or the default data length it creates isn't the
 * correct length.
 */
static ExifEntry *create_tag(ExifData *exif, ExifIfd ifd, ExifTag tag, size_t len)
{
	void *buf;
	ExifEntry *entry;
	
	/* Create a memory allocator to manage this ExifEntry */
	ExifMem *mem = exif_mem_new_default();
	assert(mem != NULL); /* catch an out of memory condition */

	/* Create a new ExifEntry using our allocator */
	entry = exif_entry_new_mem (mem);
	assert(entry != NULL);

	/* Allocate memory to use for holding the tag data */
	buf = exif_mem_alloc(mem, len);
	assert(buf != NULL);

	/* Fill in the entry */
	entry->data = buf;
	entry->size = len;
	entry->tag = tag;
	entry->components = len;
	entry->format = EXIF_FORMAT_UNDEFINED;

	/* Attach the ExifEntry to an IFD */
	exif_content_add_entry (exif->ifd[ifd], entry);

	/* The ExifMem and ExifEntry are now owned elsewhere */
	exif_mem_unref(mem);
	exif_entry_unref(entry);

	return entry;
}

// double latitude = 113.898900;
// double longitude = 22.4522314;
// int altitude = 6654;
int wk_write_exif(ot_gps_info *gps_info, ot_isp_exp_info *exp_info, FILE *pfd)
{
	int rc = 1;
    time_t now;
	struct tm *timenow;
	unsigned char *exif_data;
	unsigned int exif_data_len;
	ExifEntry *entry;
	ExifData *exif = exif_data_new();
	if (!exif) {
		fprintf(stderr, "Out of memory\n");
		return 2;
	}

    time(&now);
	timenow = localtime(&now);

	/* Set the image options */
	exif_data_set_option(exif, EXIF_DATA_OPTION_FOLLOW_SPECIFICATION);
	exif_data_set_data_type(exif, EXIF_DATA_TYPE_COMPRESSED);
	exif_data_set_byte_order(exif, FILE_BYTE_ORDER);

	/* Create the mandatory EXIF fields with default data */
	exif_data_fix(exif);

	//制造商
    entry = create_tag(exif, EXIF_IFD_0,EXIF_TAG_MAKE,9);
	entry->format = EXIF_FORMAT_ASCII;	
	entry->components = 8;
	memcpy(entry->data,"WALKERA",8);
	//型号
	entry = create_tag(exif, EXIF_IFD_0,EXIF_TAG_MODEL,18);
	entry->format = EXIF_FORMAT_ASCII;
	entry->components = 17;
	memcpy(entry->data,"WALKERA MINI SE",13);
	//版本
	entry = create_tag(exif, EXIF_IFD_0,EXIF_TAG_SOFTWARE,18);
	entry->format = EXIF_FORMAT_ASCII;
	entry->components = 17;
	memcpy(entry->data,"v.1.1.0",15);

	//EXPOSURETIME
	entry = create_tag(exif, EXIF_IFD_EXIF,(ExifTag)EXIF_TAG_EXPOSURE_TIME,8);//
	entry->format = EXIF_FORMAT_RATIONAL;	
	entry->components = 1;
	ExifRational EXPOSURETIME;
	EXPOSURETIME.numerator = exp_info->exp_time;
	EXPOSURETIME.denominator = 1000000;
	exif_set_rational(entry->data,FILE_BYTE_ORDER,EXPOSURETIME);	

	//ISOֵ
	entry = create_tag(exif, EXIF_IFD_EXIF,(ExifTag) EXIF_TAG_ISO_SPEED_RATINGS,2);//
	entry->format = EXIF_FORMAT_SHORT;
	entry->components = 1;
	unsigned short iso = exp_info->iso;
	memcpy(entry->data,(char*)&iso, 2);

	//白平衡
	entry = create_tag(exif, EXIF_IFD_EXIF,(ExifTag) EXIF_TAG_WHITE_BALANCE, 2);
	entry->format = EXIF_FORMAT_SHORT;
    exif_set_sshort(entry->data, FILE_BYTE_ORDER, 1);

    // 光圈值
	entry = create_tag(exif, EXIF_IFD_EXIF, EXIF_TAG_FNUMBER, 1 * exif_format_get_size(EXIF_FORMAT_RATIONAL));
	entry->format = EXIF_FORMAT_RATIONAL;
	entry->components = 1;
    ExifRational fir;
	fir.numerator = 56;
    fir.denominator = 10;
	exif_set_rational(entry->data, FILE_BYTE_ORDER, fir);

    // 焦距
    entry = create_tag(exif, EXIF_IFD_EXIF, EXIF_TAG_FOCAL_LENGTH, 1 * exif_format_get_size(EXIF_FORMAT_RATIONAL));
    entry->format = EXIF_FORMAT_RATIONAL;
    entry->components = 1;
    fir.numerator = 4;
    fir.denominator = 1;
    exif_set_rational(entry->data, FILE_BYTE_ORDER, fir);
    printf("==== fnumber [%d]\n", fir.numerator);

	//FocalLengthIn35mmFilm
	entry = create_tag(exif, EXIF_IFD_EXIF,(ExifTag) EXIF_TAG_FOCAL_LENGTH_IN_35MM_FILM,2);//
	entry->format = EXIF_FORMAT_SHORT;
	entry->components = 1;
	short FocalLengthIn35mmFilm=25;
	memcpy(entry->data,(char*)&FocalLengthIn35mmFilm,2);
	
    // GPS 纬度
	entry = create_tag(exif, EXIF_IFD_GPS, (ExifTag)EXIF_TAG_GPS_LATITUDE_REF, 2);	
	entry->format = EXIF_FORMAT_ASCII;	
	entry->components = 2;
    if(gps_info->gps_latitude_ref == 'N'){
        memcpy(entry->data, "N", 2);
    }
    else{
        memcpy(entry->data, "S", 2);
    }

	ExifSRational a;	
	ExifSRational b;	
	ExifSRational c;
	a.numerator = gps_info->gps_latitude[0][0];	
	a.denominator = gps_info->gps_latitude[0][1];	
	b.numerator = gps_info->gps_latitude[1][0];	
	b.denominator = gps_info->gps_latitude[1][1];	
	c.numerator = gps_info->gps_latitude[2][0];	
	c.denominator = gps_info->gps_latitude[2][1];
	entry = create_tag(exif, EXIF_IFD_GPS, (ExifTag)EXIF_TAG_GPS_LATITUDE,24);	
	entry->format = EXIF_FORMAT_SRATIONAL;	
	entry->components = 3;	
	exif_set_srational(entry->data,FILE_BYTE_ORDER,a);	
	exif_set_srational(entry->data+8,FILE_BYTE_ORDER,b);	
	exif_set_srational(entry->data+16,FILE_BYTE_ORDER,c);

	// GPS 经度
	entry = create_tag(exif, EXIF_IFD_GPS, (ExifTag)EXIF_TAG_GPS_LONGITUDE_REF,2);	
	entry->format = EXIF_FORMAT_ASCII;	
	entry->components = 2;	
    if(gps_info->gps_longitude_ref == 'E'){
        memcpy(entry->data, "E", 2);
    }
    else{
        memcpy(entry->data, "W", 2);
    }

	a.numerator = gps_info->gps_longitude[0][0];	
	a.denominator = gps_info->gps_longitude[0][1];
	b.numerator = gps_info->gps_longitude[1][0];	
	b.denominator = gps_info->gps_longitude[1][1];
	c.numerator = gps_info->gps_longitude[2][0];
	c.denominator = gps_info->gps_longitude[2][1];
	entry = create_tag(exif, EXIF_IFD_GPS, (ExifTag)EXIF_TAG_GPS_LONGITUDE,24);
	entry->format = EXIF_FORMAT_SRATIONAL;
	entry->components = 3;
	exif_set_srational(entry->data,FILE_BYTE_ORDER,a);
	exif_set_srational(entry->data+8,FILE_BYTE_ORDER,b);
	exif_set_srational(entry->data+16,FILE_BYTE_ORDER,c);

	//GPS 高度
    entry = create_tag(exif, EXIF_IFD_GPS, (ExifTag)EXIF_TAG_GPS_ALTITUDE_REF,8);
	entry->format = EXIF_FORMAT_BYTE;	
	entry->components = 1;	
	exif_set_sshort(entry->data, FILE_BYTE_ORDER, gps_info->gps_altitude_ref);

	entry = create_tag(exif, EXIF_IFD_GPS, (ExifTag)EXIF_TAG_GPS_ALTITUDE,8);
	entry->format = EXIF_FORMAT_RATIONAL;	
	entry->components = 1;	
	ExifRational h;
	h.denominator = gps_info->gps_altitude[1];	
	h.numerator = gps_info->gps_altitude[0];
	exif_set_rational(entry->data,FILE_BYTE_ORDER,h);

    // GPS 时间	
	entry = create_tag(exif, EXIF_IFD_GPS, (ExifTag)EXIF_TAG_GPS_TIME_STAMP, 24);
	entry->format = EXIF_FORMAT_RATIONAL;	
	entry->components = 3;	
	ExifRational x;
	ExifRational y;	
	ExifRational z;	
	x.denominator = 1;	
	x.numerator = timenow->tm_hour;	
	y.denominator = 1;	
	y.numerator = timenow->tm_min;	
	z.denominator = 1;	
	z.numerator = timenow->tm_sec;	
	exif_set_rational(entry->data,FILE_BYTE_ORDER,x);	
	exif_set_rational(entry->data+8,FILE_BYTE_ORDER,y);	
	exif_set_rational(entry->data+16,FILE_BYTE_ORDER,z);

    // 原始时间
    char timebuf[30];
	memset(timebuf,0,30);
	sprintf(timebuf,"%04d:%02d:%02d %02d:%02d:%02d",timenow->tm_year+1900,timenow->tm_mon+1,timenow->tm_mday,timenow->tm_hour,timenow->tm_min,timenow->tm_sec);
	/*date time*/	
	entry = create_tag(exif, EXIF_IFD_EXIF,(ExifTag)EXIF_TAG_DATE_TIME_ORIGINAL, 20);	
	entry->format = EXIF_FORMAT_ASCII;	
	entry->components = 19;	
	memcpy(entry->data,timebuf,19);	

	/* Get a pointer to the EXIF data block we just created */
	exif_data_save_data(exif, &exif_data, &exif_data_len);
	assert(exif_data != NULL);

	if (!pfd) {
		fprintf(stderr, "Error creating file 1\n");
		exif_data_unref(exif);
		return rc;
	}
	/* Write EXIF header */
	if (fwrite(exif_header, exif_header_len, 1, pfd) != 1) {
		fprintf(stderr, "Error writing to file 1\n");
		goto errout;
	}
	/* Write EXIF block length in big-endian order */
	if (fputc((exif_data_len+2) >> 8, pfd) < 0) {
		fprintf(stderr, "Error writing to file 2\n");
		goto errout;
	}
	if (fputc((exif_data_len+2) & 0xff, pfd) < 0) {
		fprintf(stderr, "Error writing to file 3\n");
		goto errout;
	}
	/* Write EXIF data block */
	if (fwrite(exif_data, exif_data_len, 1, pfd) != 1) {
		fprintf(stderr, "Error writing to file 4\n");
		goto errout;
	}
    rc = 0;

errout:
    rc = 1;

	/* The allocator we're using for ExifData is the standard one, so use
	 * it directly to free this pointer.
	 */
	free(exif_data);
	exif_data_unref(exif);

	return rc;
}
#endif

