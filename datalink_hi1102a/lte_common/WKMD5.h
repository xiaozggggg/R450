#ifndef _WKMD5_H
#define _WKMD5_H

extern "C"{
    #include <string.h>
    #include <stdio.h>
    #include <stdlib.h>
}
#include "Protocol.h"

typedef struct{
    unsigned int count[2];
    unsigned int state[4];
    unsigned char buffer[64];
}MD5_CTX;


#define F(x,y,z) ((x & y) | (~x & z))
#define G(x,y,z) ((x & z) | (y & ~z))
#define H(x,y,z) (x^y^z)
#define I(x,y,z) (y ^ (x | ~z))
#define ROTATE_LEFT(x,n) ((x << n) | (x >> (32-n)))
#define FF(a,b,c,d,x,s,ac) \
          { \
          a += F(b,c,d) + x + ac; \
          a = ROTATE_LEFT(a,s); \
          a += b; \
          }
#define GG(a,b,c,d,x,s,ac) \
          { \
          a += G(b,c,d) + x + ac; \
          a = ROTATE_LEFT(a,s); \
          a += b; \
          }
#define HH(a,b,c,d,x,s,ac) \
          { \
          a += H(b,c,d) + x + ac; \
          a = ROTATE_LEFT(a,s); \
          a += b; \
          }
#define II(a,b,c,d,x,s,ac) \
          { \
          a += I(b,c,d) + x + ac; \
          a = ROTATE_LEFT(a,s); \
          a += b; \
          }

class WKMD5
{
public:
    WKMD5(){}
    ~WKMD5(){}

    void _init(MD5_CTX *context);
    void _update(MD5_CTX *context,unsigned char *input,unsigned int inputlen);
    void _final(MD5_CTX *context,unsigned char digest[16]);
    void _transform(unsigned int state[4],unsigned char block[64]);
    void _encode(unsigned char *output,unsigned int *input,unsigned int len);
    void _decode(unsigned int *output,unsigned char *input,unsigned int len);

    // new
    void _toString(unsigned char *output ,unsigned char *input ,unsigned int len);
    unsigned char* _encryptionToString(unsigned char *Encryp ,unsigned int len);


};



#endif





















