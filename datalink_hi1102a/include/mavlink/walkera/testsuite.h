/** @file
 *    @brief MAVLink comm protocol testsuite generated from walkera.xml
 *    @see http://qgroundcontrol.org/mavlink/
 */
#pragma once
#ifndef WALKERA_TESTSUITE_H
#define WALKERA_TESTSUITE_H

#ifdef __cplusplus
extern "C" {
#endif

#ifndef MAVLINK_TEST_ALL
#define MAVLINK_TEST_ALL
static void mavlink_test_common(uint8_t, uint8_t, mavlink_message_t *last_msg);
static void mavlink_test_walkera(uint8_t, uint8_t, mavlink_message_t *last_msg);

static void mavlink_test_all(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
    mavlink_test_common(system_id, component_id, last_msg);
    mavlink_test_walkera(system_id, component_id, last_msg);
}
#endif

#include "../common/testsuite.h"


static void mavlink_test_ntrip_config(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_NTRIP_CONFIG >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_ntrip_config_t packet_in = {
        17235,"CDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLM","OPQRSTUVWXYZABCDEFGHIJKLMNOPQRS","UVWXYZABCDEFGHIJKLMNOPQRSTUVWXY","ABCDEFGHIJKLMNOPQRSTUVWXYZABCDE"
    };
    mavlink_ntrip_config_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.port = packet_in.port;
        
        mav_array_memcpy(packet1.url, packet_in.url, sizeof(char)*64);
        mav_array_memcpy(packet1.mount_point, packet_in.mount_point, sizeof(char)*32);
        mav_array_memcpy(packet1.user, packet_in.user, sizeof(char)*32);
        mav_array_memcpy(packet1.password, packet_in.password, sizeof(char)*32);
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_NTRIP_CONFIG_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_NTRIP_CONFIG_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_ntrip_config_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_ntrip_config_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_ntrip_config_pack(system_id, component_id, &msg , packet1.url , packet1.port , packet1.mount_point , packet1.user , packet1.password );
    mavlink_msg_ntrip_config_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_ntrip_config_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.url , packet1.port , packet1.mount_point , packet1.user , packet1.password );
    mavlink_msg_ntrip_config_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_ntrip_config_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_ntrip_config_send(MAVLINK_COMM_1 , packet1.url , packet1.port , packet1.mount_point , packet1.user , packet1.password );
    mavlink_msg_ntrip_config_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_network_status(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_NETWORK_STATUS >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_network_status_t packet_in = {
        963497464,17,84,151,218,29,"JK"
    };
    mavlink_network_status_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.expired_time = packet_in.expired_time;
        packet1.state = packet_in.state;
        packet1.rssi = packet_in.rssi;
        packet1.wkcloud_state = packet_in.wkcloud_state;
        packet1.ntrip_state = packet_in.ntrip_state;
        packet1.account_active = packet_in.account_active;
        
        mav_array_memcpy(packet1.reserved, packet_in.reserved, sizeof(char)*3);
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_NETWORK_STATUS_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_NETWORK_STATUS_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_network_status_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_network_status_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_network_status_pack(system_id, component_id, &msg , packet1.state , packet1.rssi , packet1.wkcloud_state , packet1.ntrip_state , packet1.account_active , packet1.reserved , packet1.expired_time );
    mavlink_msg_network_status_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_network_status_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.state , packet1.rssi , packet1.wkcloud_state , packet1.ntrip_state , packet1.account_active , packet1.reserved , packet1.expired_time );
    mavlink_msg_network_status_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_network_status_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_network_status_send(MAVLINK_COMM_1 , packet1.state , packet1.rssi , packet1.wkcloud_state , packet1.ntrip_state , packet1.account_active , packet1.reserved , packet1.expired_time );
    mavlink_msg_network_status_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_wk_product_version(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_WK_PRODUCT_VERSION >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_wk_product_version_t packet_in = {
        963497464,45.0,73.0,17859,17963,{ 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68 },101
    };
    mavlink_wk_product_version_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.active_timestamps = packet_in.active_timestamps;
        packet1.version = packet_in.version;
        packet1.build_date = packet_in.build_date;
        packet1.product_type = packet_in.product_type;
        packet1.product_subtype = packet_in.product_subtype;
        packet1.activated = packet_in.activated;
        
        mav_array_memcpy(packet1.product_id, packet_in.product_id, sizeof(uint8_t)*16);
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_WK_PRODUCT_VERSION_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_WK_PRODUCT_VERSION_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_product_version_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_wk_product_version_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_product_version_pack(system_id, component_id, &msg , packet1.active_timestamps , packet1.product_type , packet1.product_subtype , packet1.version , packet1.build_date , packet1.product_id , packet1.activated );
    mavlink_msg_wk_product_version_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_product_version_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.active_timestamps , packet1.product_type , packet1.product_subtype , packet1.version , packet1.build_date , packet1.product_id , packet1.activated );
    mavlink_msg_wk_product_version_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_wk_product_version_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_product_version_send(MAVLINK_COMM_1 , packet1.active_timestamps , packet1.product_type , packet1.product_subtype , packet1.version , packet1.build_date , packet1.product_id , packet1.activated );
    mavlink_msg_wk_product_version_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_wk_obstacle_avidance(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_WK_OBSTACLE_AVIDANCE >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_wk_obstacle_avidance_t packet_in = {
        963497464,963497672,963497880,963498088,963498296,963498504,18483,18587,89,156,{ 223, 224, 225, 226, 227, 228, 229, 230 }
    };
    mavlink_wk_obstacle_avidance_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.avoid_dist_cm = packet_in.avoid_dist_cm;
        packet1.front_radar_cm = packet_in.front_radar_cm;
        packet1.below_radar_cm = packet_in.below_radar_cm;
        packet1.behind_radar_cm = packet_in.behind_radar_cm;
        packet1.left_radar_cm = packet_in.left_radar_cm;
        packet1.right_radar_cm = packet_in.right_radar_cm;
        packet1.warning_position_bitmask = packet_in.warning_position_bitmask;
        packet1.angle = packet_in.angle;
        packet1.enable = packet_in.enable;
        packet1.radar_type = packet_in.radar_type;
        
        mav_array_memcpy(packet1.warning_flag, packet_in.warning_flag, sizeof(uint8_t)*8);
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_WK_OBSTACLE_AVIDANCE_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_WK_OBSTACLE_AVIDANCE_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_obstacle_avidance_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_wk_obstacle_avidance_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_obstacle_avidance_pack(system_id, component_id, &msg , packet1.enable , packet1.radar_type , packet1.warning_flag , packet1.warning_position_bitmask , packet1.angle , packet1.avoid_dist_cm , packet1.front_radar_cm , packet1.below_radar_cm , packet1.behind_radar_cm , packet1.left_radar_cm , packet1.right_radar_cm );
    mavlink_msg_wk_obstacle_avidance_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_obstacle_avidance_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.enable , packet1.radar_type , packet1.warning_flag , packet1.warning_position_bitmask , packet1.angle , packet1.avoid_dist_cm , packet1.front_radar_cm , packet1.below_radar_cm , packet1.behind_radar_cm , packet1.left_radar_cm , packet1.right_radar_cm );
    mavlink_msg_wk_obstacle_avidance_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_wk_obstacle_avidance_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_obstacle_avidance_send(MAVLINK_COMM_1 , packet1.enable , packet1.radar_type , packet1.warning_flag , packet1.warning_position_bitmask , packet1.angle , packet1.avoid_dist_cm , packet1.front_radar_cm , packet1.below_radar_cm , packet1.behind_radar_cm , packet1.left_radar_cm , packet1.right_radar_cm );
    mavlink_msg_wk_obstacle_avidance_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_wk_mission_break_point(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_WK_MISSION_BREAK_POINT >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_wk_mission_break_point_t packet_in = {
        963497464,963497672,963497880,963498088,963498296,963498504
    };
    mavlink_wk_mission_break_point_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.trig_timestamp = packet_in.trig_timestamp;
        packet1.break_cmd_seq = packet_in.break_cmd_seq;
        packet1.latitude = packet_in.latitude;
        packet1.longitude = packet_in.longitude;
        packet1.altitude_relative = packet_in.altitude_relative;
        packet1.altitude_abs = packet_in.altitude_abs;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_WK_MISSION_BREAK_POINT_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_WK_MISSION_BREAK_POINT_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_mission_break_point_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_wk_mission_break_point_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_mission_break_point_pack(system_id, component_id, &msg , packet1.trig_timestamp , packet1.break_cmd_seq , packet1.latitude , packet1.longitude , packet1.altitude_relative , packet1.altitude_abs );
    mavlink_msg_wk_mission_break_point_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_mission_break_point_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.trig_timestamp , packet1.break_cmd_seq , packet1.latitude , packet1.longitude , packet1.altitude_relative , packet1.altitude_abs );
    mavlink_msg_wk_mission_break_point_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_wk_mission_break_point_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_mission_break_point_send(MAVLINK_COMM_1 , packet1.trig_timestamp , packet1.break_cmd_seq , packet1.latitude , packet1.longitude , packet1.altitude_relative , packet1.altitude_abs );
    mavlink_msg_wk_mission_break_point_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_wk_mission_state(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_WK_MISSION_STATE >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_wk_mission_state_t packet_in = {
        963497464,45.0,73.0,963498088,963498296,65
    };
    mavlink_wk_mission_state_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.next_cmd_seq = packet_in.next_cmd_seq;
        packet1.total_distance = packet_in.total_distance;
        packet1.complete_distance = packet_in.complete_distance;
        packet1.complete_percent = packet_in.complete_percent;
        packet1.photo_counts = packet_in.photo_counts;
        packet1.status = packet_in.status;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_WK_MISSION_STATE_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_WK_MISSION_STATE_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_mission_state_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_wk_mission_state_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_mission_state_pack(system_id, component_id, &msg , packet1.status , packet1.next_cmd_seq , packet1.total_distance , packet1.complete_distance , packet1.complete_percent , packet1.photo_counts );
    mavlink_msg_wk_mission_state_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_mission_state_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.status , packet1.next_cmd_seq , packet1.total_distance , packet1.complete_distance , packet1.complete_percent , packet1.photo_counts );
    mavlink_msg_wk_mission_state_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_wk_mission_state_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_mission_state_send(MAVLINK_COMM_1 , packet1.status , packet1.next_cmd_seq , packet1.total_distance , packet1.complete_distance , packet1.complete_percent , packet1.photo_counts );
    mavlink_msg_wk_mission_state_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_wk_flight_state(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_WK_FLIGHT_STATE >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_wk_flight_state_t packet_in = {
        5
    };
    mavlink_wk_flight_state_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.flight_state = packet_in.flight_state;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_WK_FLIGHT_STATE_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_WK_FLIGHT_STATE_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_flight_state_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_wk_flight_state_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_flight_state_pack(system_id, component_id, &msg , packet1.flight_state );
    mavlink_msg_wk_flight_state_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_flight_state_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.flight_state );
    mavlink_msg_wk_flight_state_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_wk_flight_state_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_flight_state_send(MAVLINK_COMM_1 , packet1.flight_state );
    mavlink_msg_wk_flight_state_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_wk_smart_battery_status(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_WK_SMART_BATTERY_STATUS >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_wk_smart_battery_status_t packet_in = {
        963497464,963497672,963497880,963498088,129.0,157.0,185.0,{ 213.0, 214.0, 215.0, 216.0, 217.0, 218.0, 219.0, 220.0, 221.0, 222.0, 223.0, 224.0, 225.0, 226.0, 227.0, 228.0 },22019,22123,{ 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48 },{ 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84 },109
    };
    mavlink_wk_smart_battery_status_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.fault_bitmasks = packet_in.fault_bitmasks;
        packet1.capacity_design = packet_in.capacity_design;
        packet1.capacity_full_charge = packet_in.capacity_full_charge;
        packet1.capacity_remaining = packet_in.capacity_remaining;
        packet1.voltage = packet_in.voltage;
        packet1.current = packet_in.current;
        packet1.temperature = packet_in.temperature;
        packet1.version = packet_in.version;
        packet1.cycle_count = packet_in.cycle_count;
        packet1.cell_count = packet_in.cell_count;
        
        mav_array_memcpy(packet1.cell_volt, packet_in.cell_volt, sizeof(float)*16);
        mav_array_memcpy(packet1.serial_number, packet_in.serial_number, sizeof(uint8_t)*12);
        mav_array_memcpy(packet1.production_date, packet_in.production_date, sizeof(uint8_t)*12);
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_WK_SMART_BATTERY_STATUS_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_WK_SMART_BATTERY_STATUS_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_smart_battery_status_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_wk_smart_battery_status_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_smart_battery_status_pack(system_id, component_id, &msg , packet1.serial_number , packet1.production_date , packet1.cell_count , packet1.fault_bitmasks , packet1.version , packet1.capacity_design , packet1.capacity_full_charge , packet1.capacity_remaining , packet1.cycle_count , packet1.voltage , packet1.current , packet1.temperature , packet1.cell_volt );
    mavlink_msg_wk_smart_battery_status_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_smart_battery_status_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.serial_number , packet1.production_date , packet1.cell_count , packet1.fault_bitmasks , packet1.version , packet1.capacity_design , packet1.capacity_full_charge , packet1.capacity_remaining , packet1.cycle_count , packet1.voltage , packet1.current , packet1.temperature , packet1.cell_volt );
    mavlink_msg_wk_smart_battery_status_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_wk_smart_battery_status_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_smart_battery_status_send(MAVLINK_COMM_1 , packet1.serial_number , packet1.production_date , packet1.cell_count , packet1.fault_bitmasks , packet1.version , packet1.capacity_design , packet1.capacity_full_charge , packet1.capacity_remaining , packet1.cycle_count , packet1.voltage , packet1.current , packet1.temperature , packet1.cell_volt );
    mavlink_msg_wk_smart_battery_status_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_wk_mount_status(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_WK_MOUNT_STATUS >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_wk_mount_status_t packet_in = {
        963497464
    };
    mavlink_wk_mount_status_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.mount_bitmasks = packet_in.mount_bitmasks;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_WK_MOUNT_STATUS_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_WK_MOUNT_STATUS_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_mount_status_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_wk_mount_status_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_mount_status_pack(system_id, component_id, &msg , packet1.mount_bitmasks );
    mavlink_msg_wk_mount_status_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_mount_status_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.mount_bitmasks );
    mavlink_msg_wk_mount_status_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_wk_mount_status_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_mount_status_send(MAVLINK_COMM_1 , packet1.mount_bitmasks );
    mavlink_msg_wk_mount_status_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_wk_module_set_serial_number(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_WK_MODULE_SET_SERIAL_NUMBER >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_wk_module_set_serial_number_t packet_in = {
        17235,{ 139, 140, 141, 142, 143, 144, 145, 146, 147, 148, 149, 150, 151, 152, 153, 154, 155, 156, 157, 158, 159, 160, 161, 162, 163, 164, 165, 166, 167, 168, 169, 170 }
    };
    mavlink_wk_module_set_serial_number_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.dev_type = packet_in.dev_type;
        
        mav_array_memcpy(packet1.serial_number, packet_in.serial_number, sizeof(uint8_t)*32);
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_WK_MODULE_SET_SERIAL_NUMBER_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_WK_MODULE_SET_SERIAL_NUMBER_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_module_set_serial_number_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_wk_module_set_serial_number_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_module_set_serial_number_pack(system_id, component_id, &msg , packet1.dev_type , packet1.serial_number );
    mavlink_msg_wk_module_set_serial_number_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_module_set_serial_number_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.dev_type , packet1.serial_number );
    mavlink_msg_wk_module_set_serial_number_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_wk_module_set_serial_number_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_module_set_serial_number_send(MAVLINK_COMM_1 , packet1.dev_type , packet1.serial_number );
    mavlink_msg_wk_module_set_serial_number_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_wk_module_version(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_WK_MODULE_VERSION >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_wk_module_version_t packet_in = {
        963497464,963497672,963497880,17859,{ 175, 176, 177, 178, 179, 180, 181, 182, 183, 184, 185, 186, 187, 188, 189, 190, 191, 192, 193, 194, 195, 196, 197, 198, 199, 200, 201, 202, 203, 204, 205, 206 }
    };
    mavlink_wk_module_version_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.dev_id = packet_in.dev_id;
        packet1.sw_ver = packet_in.sw_ver;
        packet1.hw_ver = packet_in.hw_ver;
        packet1.dev_type = packet_in.dev_type;
        
        mav_array_memcpy(packet1.serial_number, packet_in.serial_number, sizeof(uint8_t)*32);
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_WK_MODULE_VERSION_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_WK_MODULE_VERSION_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_module_version_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_wk_module_version_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_module_version_pack(system_id, component_id, &msg , packet1.dev_type , packet1.dev_id , packet1.sw_ver , packet1.hw_ver , packet1.serial_number );
    mavlink_msg_wk_module_version_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_module_version_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.dev_type , packet1.dev_id , packet1.sw_ver , packet1.hw_ver , packet1.serial_number );
    mavlink_msg_wk_module_version_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_wk_module_version_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_module_version_send(MAVLINK_COMM_1 , packet1.dev_type , packet1.dev_id , packet1.sw_ver , packet1.hw_ver , packet1.serial_number );
    mavlink_msg_wk_module_version_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_wk_upgrade_request(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_WK_UPGRADE_REQUEST >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_wk_upgrade_request_t packet_in = {
        963497464,17443
    };
    mavlink_wk_upgrade_request_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.dev_id = packet_in.dev_id;
        packet1.dev_type = packet_in.dev_type;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_WK_UPGRADE_REQUEST_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_WK_UPGRADE_REQUEST_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_upgrade_request_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_wk_upgrade_request_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_upgrade_request_pack(system_id, component_id, &msg , packet1.dev_type , packet1.dev_id );
    mavlink_msg_wk_upgrade_request_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_upgrade_request_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.dev_type , packet1.dev_id );
    mavlink_msg_wk_upgrade_request_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_wk_upgrade_request_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_upgrade_request_send(MAVLINK_COMM_1 , packet1.dev_type , packet1.dev_id );
    mavlink_msg_wk_upgrade_request_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_wk_upgrade_request_ack(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_WK_UPGRADE_REQUEST_ACK >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_wk_upgrade_request_ack_t packet_in = {
        963497464,17443
    };
    mavlink_wk_upgrade_request_ack_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.dev_id = packet_in.dev_id;
        packet1.dev_type = packet_in.dev_type;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_WK_UPGRADE_REQUEST_ACK_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_WK_UPGRADE_REQUEST_ACK_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_upgrade_request_ack_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_wk_upgrade_request_ack_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_upgrade_request_ack_pack(system_id, component_id, &msg , packet1.dev_type , packet1.dev_id );
    mavlink_msg_wk_upgrade_request_ack_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_upgrade_request_ack_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.dev_type , packet1.dev_id );
    mavlink_msg_wk_upgrade_request_ack_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_wk_upgrade_request_ack_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_upgrade_request_ack_send(MAVLINK_COMM_1 , packet1.dev_type , packet1.dev_id );
    mavlink_msg_wk_upgrade_request_ack_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_wk_upgrade_fw_info(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_WK_UPGRADE_FW_INFO >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_wk_upgrade_fw_info_t packet_in = {
        963497464,963497672,963497880,963498088,963498296,963498504,18483
    };
    mavlink_wk_upgrade_fw_info_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.dev_id = packet_in.dev_id;
        packet1.sw_ver = packet_in.sw_ver;
        packet1.hw_ver = packet_in.hw_ver;
        packet1.length = packet_in.length;
        packet1.crc32 = packet_in.crc32;
        packet1.total_fragments = packet_in.total_fragments;
        packet1.dev_type = packet_in.dev_type;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_WK_UPGRADE_FW_INFO_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_WK_UPGRADE_FW_INFO_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_upgrade_fw_info_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_wk_upgrade_fw_info_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_upgrade_fw_info_pack(system_id, component_id, &msg , packet1.dev_type , packet1.dev_id , packet1.sw_ver , packet1.hw_ver , packet1.length , packet1.crc32 , packet1.total_fragments );
    mavlink_msg_wk_upgrade_fw_info_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_upgrade_fw_info_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.dev_type , packet1.dev_id , packet1.sw_ver , packet1.hw_ver , packet1.length , packet1.crc32 , packet1.total_fragments );
    mavlink_msg_wk_upgrade_fw_info_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_wk_upgrade_fw_info_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_upgrade_fw_info_send(MAVLINK_COMM_1 , packet1.dev_type , packet1.dev_id , packet1.sw_ver , packet1.hw_ver , packet1.length , packet1.crc32 , packet1.total_fragments );
    mavlink_msg_wk_upgrade_fw_info_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_wk_upgrade_frag_request(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_WK_UPGRADE_FRAG_REQUEST >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_wk_upgrade_frag_request_t packet_in = {
        963497464,963497672,17651
    };
    mavlink_wk_upgrade_frag_request_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.dev_id = packet_in.dev_id;
        packet1.seq = packet_in.seq;
        packet1.dev_type = packet_in.dev_type;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_WK_UPGRADE_FRAG_REQUEST_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_WK_UPGRADE_FRAG_REQUEST_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_upgrade_frag_request_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_wk_upgrade_frag_request_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_upgrade_frag_request_pack(system_id, component_id, &msg , packet1.dev_type , packet1.dev_id , packet1.seq );
    mavlink_msg_wk_upgrade_frag_request_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_upgrade_frag_request_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.dev_type , packet1.dev_id , packet1.seq );
    mavlink_msg_wk_upgrade_frag_request_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_wk_upgrade_frag_request_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_upgrade_frag_request_send(MAVLINK_COMM_1 , packet1.dev_type , packet1.dev_id , packet1.seq );
    mavlink_msg_wk_upgrade_frag_request_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_wk_upgrade_frag_data(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_WK_UPGRADE_FRAG_DATA >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_wk_upgrade_frag_data_t packet_in = {
        963497464,963497672,17651,"KLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNO"
    };
    mavlink_wk_upgrade_frag_data_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.dev_id = packet_in.dev_id;
        packet1.seq = packet_in.seq;
        packet1.dev_type = packet_in.dev_type;
        
        mav_array_memcpy(packet1.payload, packet_in.payload, sizeof(char)*240);
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_WK_UPGRADE_FRAG_DATA_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_WK_UPGRADE_FRAG_DATA_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_upgrade_frag_data_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_wk_upgrade_frag_data_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_upgrade_frag_data_pack(system_id, component_id, &msg , packet1.dev_type , packet1.dev_id , packet1.seq , packet1.payload );
    mavlink_msg_wk_upgrade_frag_data_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_upgrade_frag_data_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.dev_type , packet1.dev_id , packet1.seq , packet1.payload );
    mavlink_msg_wk_upgrade_frag_data_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_wk_upgrade_frag_data_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_upgrade_frag_data_send(MAVLINK_COMM_1 , packet1.dev_type , packet1.dev_id , packet1.seq , packet1.payload );
    mavlink_msg_wk_upgrade_frag_data_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_wk_upgrade_end_report(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_WK_UPGRADE_END_REPORT >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_wk_upgrade_end_report_t packet_in = {
        963497464,17443,151
    };
    mavlink_wk_upgrade_end_report_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.dev_id = packet_in.dev_id;
        packet1.dev_type = packet_in.dev_type;
        packet1.result = packet_in.result;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_WK_UPGRADE_END_REPORT_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_WK_UPGRADE_END_REPORT_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_upgrade_end_report_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_wk_upgrade_end_report_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_upgrade_end_report_pack(system_id, component_id, &msg , packet1.dev_type , packet1.dev_id , packet1.result );
    mavlink_msg_wk_upgrade_end_report_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_upgrade_end_report_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.dev_type , packet1.dev_id , packet1.result );
    mavlink_msg_wk_upgrade_end_report_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_wk_upgrade_end_report_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_upgrade_end_report_send(MAVLINK_COMM_1 , packet1.dev_type , packet1.dev_id , packet1.result );
    mavlink_msg_wk_upgrade_end_report_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_wk_upgrade_end_ack(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_WK_UPGRADE_END_ACK >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_wk_upgrade_end_ack_t packet_in = {
        963497464,17443
    };
    mavlink_wk_upgrade_end_ack_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.dev_id = packet_in.dev_id;
        packet1.dev_type = packet_in.dev_type;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_WK_UPGRADE_END_ACK_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_WK_UPGRADE_END_ACK_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_upgrade_end_ack_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_wk_upgrade_end_ack_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_upgrade_end_ack_pack(system_id, component_id, &msg , packet1.dev_type , packet1.dev_id );
    mavlink_msg_wk_upgrade_end_ack_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_upgrade_end_ack_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.dev_type , packet1.dev_id );
    mavlink_msg_wk_upgrade_end_ack_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_wk_upgrade_end_ack_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_upgrade_end_ack_send(MAVLINK_COMM_1 , packet1.dev_type , packet1.dev_id );
    mavlink_msg_wk_upgrade_end_ack_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_wk_selfchk_state(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_WK_SELFCHK_STATE >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_wk_selfchk_state_t packet_in = {
        5,72,139,206,17,84,151,218,{ 29, 30, 31, 32, 33 }
    };
    mavlink_wk_selfchk_state_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.gps_healthy = packet_in.gps_healthy;
        packet1.inav_healthy = packet_in.inav_healthy;
        packet1.compass_healthy = packet_in.compass_healthy;
        packet1.battery_healthy = packet_in.battery_healthy;
        packet1.imu_healthy = packet_in.imu_healthy;
        packet1.gyro_calib_flag = packet_in.gyro_calib_flag;
        packet1.acc_calib_flag = packet_in.acc_calib_flag;
        packet1.compass_calib_flag = packet_in.compass_calib_flag;
        
        mav_array_memcpy(packet1.reserved, packet_in.reserved, sizeof(uint8_t)*5);
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_WK_SELFCHK_STATE_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_WK_SELFCHK_STATE_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_selfchk_state_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_wk_selfchk_state_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_selfchk_state_pack(system_id, component_id, &msg , packet1.gps_healthy , packet1.inav_healthy , packet1.compass_healthy , packet1.battery_healthy , packet1.imu_healthy , packet1.gyro_calib_flag , packet1.acc_calib_flag , packet1.compass_calib_flag , packet1.reserved );
    mavlink_msg_wk_selfchk_state_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_selfchk_state_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.gps_healthy , packet1.inav_healthy , packet1.compass_healthy , packet1.battery_healthy , packet1.imu_healthy , packet1.gyro_calib_flag , packet1.acc_calib_flag , packet1.compass_calib_flag , packet1.reserved );
    mavlink_msg_wk_selfchk_state_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_wk_selfchk_state_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_selfchk_state_send(MAVLINK_COMM_1 , packet1.gps_healthy , packet1.inav_healthy , packet1.compass_healthy , packet1.battery_healthy , packet1.imu_healthy , packet1.gyro_calib_flag , packet1.acc_calib_flag , packet1.compass_calib_flag , packet1.reserved );
    mavlink_msg_wk_selfchk_state_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_wk_target_posvel(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_WK_TARGET_POSVEL >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_wk_target_posvel_t packet_in = {
        963497464,963497672,17651,17755,17859,17963,53
    };
    mavlink_wk_target_posvel_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.latitude = packet_in.latitude;
        packet1.longitude = packet_in.longitude;
        packet1.velx = packet_in.velx;
        packet1.vely = packet_in.vely;
        packet1.velz = packet_in.velz;
        packet1.heading = packet_in.heading;
        packet1.valid = packet_in.valid;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_WK_TARGET_POSVEL_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_WK_TARGET_POSVEL_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_target_posvel_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_wk_target_posvel_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_target_posvel_pack(system_id, component_id, &msg , packet1.valid , packet1.latitude , packet1.longitude , packet1.velx , packet1.vely , packet1.velz , packet1.heading );
    mavlink_msg_wk_target_posvel_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_target_posvel_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.valid , packet1.latitude , packet1.longitude , packet1.velx , packet1.vely , packet1.velz , packet1.heading );
    mavlink_msg_wk_target_posvel_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_wk_target_posvel_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_target_posvel_send(MAVLINK_COMM_1 , packet1.valid , packet1.latitude , packet1.longitude , packet1.velx , packet1.vely , packet1.velz , packet1.heading );
    mavlink_msg_wk_target_posvel_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_wk_followme_cmd(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_WK_FOLLOWME_CMD >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_wk_followme_cmd_t packet_in = {
        5
    };
    mavlink_wk_followme_cmd_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.command = packet_in.command;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_WK_FOLLOWME_CMD_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_WK_FOLLOWME_CMD_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_followme_cmd_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_wk_followme_cmd_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_followme_cmd_pack(system_id, component_id, &msg , packet1.command );
    mavlink_msg_wk_followme_cmd_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_followme_cmd_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.command );
    mavlink_msg_wk_followme_cmd_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_wk_followme_cmd_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_followme_cmd_send(MAVLINK_COMM_1 , packet1.command );
    mavlink_msg_wk_followme_cmd_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_wk_oilmass_state(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_WK_OILMASS_STATE >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_wk_oilmass_state_t packet_in = {
        963497464,963497672,963497880,963498088
    };
    mavlink_wk_oilmass_state_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.current_oil_mass = packet_in.current_oil_mass;
        packet1.total_oil_mass = packet_in.total_oil_mass;
        packet1.percent = packet_in.percent;
        packet1.remainder_range = packet_in.remainder_range;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_WK_OILMASS_STATE_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_WK_OILMASS_STATE_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_oilmass_state_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_wk_oilmass_state_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_oilmass_state_pack(system_id, component_id, &msg , packet1.current_oil_mass , packet1.total_oil_mass , packet1.percent , packet1.remainder_range );
    mavlink_msg_wk_oilmass_state_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_oilmass_state_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.current_oil_mass , packet1.total_oil_mass , packet1.percent , packet1.remainder_range );
    mavlink_msg_wk_oilmass_state_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_wk_oilmass_state_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_oilmass_state_send(MAVLINK_COMM_1 , packet1.current_oil_mass , packet1.total_oil_mass , packet1.percent , packet1.remainder_range );
    mavlink_msg_wk_oilmass_state_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_wk_rtk_beacon_state(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_WK_RTK_BEACON_STATE >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_wk_rtk_beacon_state_t packet_in = {
        963497464,963497672,963497880,41,108,175
    };
    mavlink_wk_rtk_beacon_state_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.distance = packet_in.distance;
        packet1.distance_x = packet_in.distance_x;
        packet1.distance_y = packet_in.distance_y;
        packet1.fix_type = packet_in.fix_type;
        packet1.sv_nums = packet_in.sv_nums;
        packet1.beacon_rate = packet_in.beacon_rate;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_WK_RTK_BEACON_STATE_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_WK_RTK_BEACON_STATE_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_rtk_beacon_state_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_wk_rtk_beacon_state_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_rtk_beacon_state_pack(system_id, component_id, &msg , packet1.fix_type , packet1.sv_nums , packet1.beacon_rate , packet1.distance , packet1.distance_x , packet1.distance_y );
    mavlink_msg_wk_rtk_beacon_state_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_rtk_beacon_state_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.fix_type , packet1.sv_nums , packet1.beacon_rate , packet1.distance , packet1.distance_x , packet1.distance_y );
    mavlink_msg_wk_rtk_beacon_state_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_wk_rtk_beacon_state_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_rtk_beacon_state_send(MAVLINK_COMM_1 , packet1.fix_type , packet1.sv_nums , packet1.beacon_rate , packet1.distance , packet1.distance_x , packet1.distance_y );
    mavlink_msg_wk_rtk_beacon_state_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_wk_heartbeat_ext(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_WK_HEARTBEAT_EXT >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_wk_heartbeat_ext_t packet_in = {
        963497464,963497672,73.0,101.0,18067,18171,65,132,199,10,77,{ 144, 145, 146, 147, 148, 149, 150, 151, 152, 153, 154, 155, 156, 157, 158, 159, 160, 161, 162, 163, 164, 165, 166, 167, 168, 169, 170, 171, 172, 173, 174, 175 },{ 240, 241, 242, 243, 244, 245, 246, 247, 248, 249, 250, 251, 252, 253, 254, 255 },32,99,166
    };
    mavlink_wk_heartbeat_ext_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.custom_mode = packet_in.custom_mode;
        packet1.active_timestamps = packet_in.active_timestamps;
        packet1.version = packet_in.version;
        packet1.build_date = packet_in.build_date;
        packet1.product_type = packet_in.product_type;
        packet1.product_subtype = packet_in.product_subtype;
        packet1.type = packet_in.type;
        packet1.autopilot = packet_in.autopilot;
        packet1.base_mode = packet_in.base_mode;
        packet1.system_status = packet_in.system_status;
        packet1.mavlink_version = packet_in.mavlink_version;
        packet1.activated = packet_in.activated;
        packet1.bound = packet_in.bound;
        packet1.locked = packet_in.locked;
        
        mav_array_memcpy(packet1.user_name, packet_in.user_name, sizeof(uint8_t)*32);
        mav_array_memcpy(packet1.product_id, packet_in.product_id, sizeof(uint8_t)*16);
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_WK_HEARTBEAT_EXT_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_WK_HEARTBEAT_EXT_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_heartbeat_ext_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_wk_heartbeat_ext_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_heartbeat_ext_pack(system_id, component_id, &msg , packet1.type , packet1.autopilot , packet1.base_mode , packet1.custom_mode , packet1.system_status , packet1.mavlink_version , packet1.active_timestamps , packet1.product_type , packet1.product_subtype , packet1.version , packet1.build_date , packet1.user_name , packet1.product_id , packet1.activated , packet1.bound , packet1.locked );
    mavlink_msg_wk_heartbeat_ext_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_heartbeat_ext_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.type , packet1.autopilot , packet1.base_mode , packet1.custom_mode , packet1.system_status , packet1.mavlink_version , packet1.active_timestamps , packet1.product_type , packet1.product_subtype , packet1.version , packet1.build_date , packet1.user_name , packet1.product_id , packet1.activated , packet1.bound , packet1.locked );
    mavlink_msg_wk_heartbeat_ext_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_wk_heartbeat_ext_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_heartbeat_ext_send(MAVLINK_COMM_1 , packet1.type , packet1.autopilot , packet1.base_mode , packet1.custom_mode , packet1.system_status , packet1.mavlink_version , packet1.active_timestamps , packet1.product_type , packet1.product_subtype , packet1.version , packet1.build_date , packet1.user_name , packet1.product_id , packet1.activated , packet1.bound , packet1.locked );
    mavlink_msg_wk_heartbeat_ext_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_wk_heartbeat_ext_new_rule(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_WK_HEARTBEAT_EXT_NEW_RULE >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_wk_heartbeat_ext_new_rule_t packet_in = {
        963497464,963497672,73.0,101.0,18067,18171,65,132,199,10,77,{ 144, 145, 146, 147, 148, 149, 150, 151, 152, 153, 154, 155, 156, 157, 158, 159, 160, 161, 162, 163, 164, 165, 166, 167, 168, 169, 170, 171, 172, 173, 174, 175 },240,{ 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80 },13,80,147
    };
    mavlink_wk_heartbeat_ext_new_rule_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.custom_mode = packet_in.custom_mode;
        packet1.active_timestamps = packet_in.active_timestamps;
        packet1.version = packet_in.version;
        packet1.build_date = packet_in.build_date;
        packet1.product_type = packet_in.product_type;
        packet1.product_subtype = packet_in.product_subtype;
        packet1.type = packet_in.type;
        packet1.autopilot = packet_in.autopilot;
        packet1.base_mode = packet_in.base_mode;
        packet1.system_status = packet_in.system_status;
        packet1.mavlink_version = packet_in.mavlink_version;
        packet1.product_id_len = packet_in.product_id_len;
        packet1.activated = packet_in.activated;
        packet1.bound = packet_in.bound;
        packet1.locked = packet_in.locked;
        
        mav_array_memcpy(packet1.user_name, packet_in.user_name, sizeof(uint8_t)*32);
        mav_array_memcpy(packet1.product_id, packet_in.product_id, sizeof(uint8_t)*30);
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_WK_HEARTBEAT_EXT_NEW_RULE_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_WK_HEARTBEAT_EXT_NEW_RULE_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_heartbeat_ext_new_rule_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_wk_heartbeat_ext_new_rule_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_heartbeat_ext_new_rule_pack(system_id, component_id, &msg , packet1.type , packet1.autopilot , packet1.base_mode , packet1.custom_mode , packet1.system_status , packet1.mavlink_version , packet1.active_timestamps , packet1.product_type , packet1.product_subtype , packet1.version , packet1.build_date , packet1.user_name , packet1.product_id_len , packet1.product_id , packet1.activated , packet1.bound , packet1.locked );
    mavlink_msg_wk_heartbeat_ext_new_rule_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_heartbeat_ext_new_rule_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.type , packet1.autopilot , packet1.base_mode , packet1.custom_mode , packet1.system_status , packet1.mavlink_version , packet1.active_timestamps , packet1.product_type , packet1.product_subtype , packet1.version , packet1.build_date , packet1.user_name , packet1.product_id_len , packet1.product_id , packet1.activated , packet1.bound , packet1.locked );
    mavlink_msg_wk_heartbeat_ext_new_rule_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_wk_heartbeat_ext_new_rule_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_heartbeat_ext_new_rule_send(MAVLINK_COMM_1 , packet1.type , packet1.autopilot , packet1.base_mode , packet1.custom_mode , packet1.system_status , packet1.mavlink_version , packet1.active_timestamps , packet1.product_type , packet1.product_subtype , packet1.version , packet1.build_date , packet1.user_name , packet1.product_id_len , packet1.product_id , packet1.activated , packet1.bound , packet1.locked );
    mavlink_msg_wk_heartbeat_ext_new_rule_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_wk_buoy_recgonize_state(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_WK_BUOY_RECGONIZE_STATE >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_wk_buoy_recgonize_state_t packet_in = {
        17235,139
    };
    mavlink_wk_buoy_recgonize_state_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.cmd_index = packet_in.cmd_index;
        packet1.state = packet_in.state;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_WK_BUOY_RECGONIZE_STATE_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_WK_BUOY_RECGONIZE_STATE_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_buoy_recgonize_state_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_wk_buoy_recgonize_state_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_buoy_recgonize_state_pack(system_id, component_id, &msg , packet1.cmd_index , packet1.state );
    mavlink_msg_wk_buoy_recgonize_state_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_buoy_recgonize_state_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.cmd_index , packet1.state );
    mavlink_msg_wk_buoy_recgonize_state_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_wk_buoy_recgonize_state_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_buoy_recgonize_state_send(MAVLINK_COMM_1 , packet1.cmd_index , packet1.state );
    mavlink_msg_wk_buoy_recgonize_state_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_wk_gnss_signal_strength(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_WK_GNSS_SIGNAL_STRENGTH >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_wk_gnss_signal_strength_t packet_in = {
        5,72,139,{ 206, 207, 208, 209, 210, 211, 212, 213, 214, 215, 216, 217, 218, 219, 220, 221, 222, 223, 224, 225, 226, 227, 228, 229, 230, 231, 232, 233, 234, 235, 236, 237, 238, 239, 240, 241, 242, 243, 244, 245, 246, 247, 248, 249, 250, 251, 252, 253, 254, 255, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29 },{ 190, 191, 192, 193, 194, 195, 196, 197, 198, 199, 200, 201, 202, 203, 204, 205, 206, 207, 208, 209, 210, 211, 212, 213, 214, 215, 216, 217, 218, 219, 220, 221, 222, 223, 224, 225, 226, 227, 228, 229, 230, 231, 232, 233, 234, 235, 236, 237, 238, 239, 240, 241, 242, 243, 244, 245, 246, 247, 248, 249, 250, 251, 252, 253, 254, 255, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13 },{ 174, 175, 176, 177, 178, 179, 180, 181, 182, 183, 184, 185, 186, 187, 188, 189, 190, 191, 192, 193, 194, 195, 196, 197, 198, 199, 200, 201, 202, 203, 204, 205, 206, 207, 208, 209, 210, 211, 212, 213, 214, 215, 216, 217, 218, 219, 220, 221, 222, 223, 224, 225, 226, 227, 228, 229, 230, 231, 232, 233, 234, 235, 236, 237, 238, 239, 240, 241, 242, 243, 244, 245, 246, 247, 248, 249, 250, 251, 252, 253 }
    };
    mavlink_wk_gnss_signal_strength_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.index = packet_in.index;
        packet1.gnss_type = packet_in.gnss_type;
        packet1.sv_nums = packet_in.sv_nums;
        
        mav_array_memcpy(packet1.sv_id, packet_in.sv_id, sizeof(uint8_t)*80);
        mav_array_memcpy(packet1.sig_id, packet_in.sig_id, sizeof(uint8_t)*80);
        mav_array_memcpy(packet1.cno, packet_in.cno, sizeof(uint8_t)*80);
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_WK_GNSS_SIGNAL_STRENGTH_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_WK_GNSS_SIGNAL_STRENGTH_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_gnss_signal_strength_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_wk_gnss_signal_strength_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_gnss_signal_strength_pack(system_id, component_id, &msg , packet1.index , packet1.gnss_type , packet1.sv_nums , packet1.sv_id , packet1.sig_id , packet1.cno );
    mavlink_msg_wk_gnss_signal_strength_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_gnss_signal_strength_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.index , packet1.gnss_type , packet1.sv_nums , packet1.sv_id , packet1.sig_id , packet1.cno );
    mavlink_msg_wk_gnss_signal_strength_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_wk_gnss_signal_strength_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_gnss_signal_strength_send(MAVLINK_COMM_1 , packet1.index , packet1.gnss_type , packet1.sv_nums , packet1.sv_id , packet1.sig_id , packet1.cno );
    mavlink_msg_wk_gnss_signal_strength_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_wk_rtk_beacon_inav_data(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_WK_RTK_BEACON_INAV_DATA >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_wk_rtk_beacon_inav_data_t packet_in = {
        963497464,963497672,963497880,963498088,18067,18171,18275,18379,77,144,211
    };
    mavlink_wk_rtk_beacon_inav_data_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.seq = packet_in.seq;
        packet1.latitude = packet_in.latitude;
        packet1.longitude = packet_in.longitude;
        packet1.gnss_height = packet_in.gnss_height;
        packet1.velocity_ef_x = packet_in.velocity_ef_x;
        packet1.velocity_ef_y = packet_in.velocity_ef_y;
        packet1.velocity_ef_z = packet_in.velocity_ef_z;
        packet1.yaw = packet_in.yaw;
        packet1.gps_fix_type = packet_in.gps_fix_type;
        packet1.sv_nums = packet_in.sv_nums;
        packet1.battery_capacity = packet_in.battery_capacity;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_WK_RTK_BEACON_INAV_DATA_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_WK_RTK_BEACON_INAV_DATA_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_rtk_beacon_inav_data_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_wk_rtk_beacon_inav_data_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_rtk_beacon_inav_data_pack(system_id, component_id, &msg , packet1.seq , packet1.latitude , packet1.longitude , packet1.gnss_height , packet1.gps_fix_type , packet1.sv_nums , packet1.velocity_ef_x , packet1.velocity_ef_y , packet1.velocity_ef_z , packet1.yaw , packet1.battery_capacity );
    mavlink_msg_wk_rtk_beacon_inav_data_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_rtk_beacon_inav_data_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.seq , packet1.latitude , packet1.longitude , packet1.gnss_height , packet1.gps_fix_type , packet1.sv_nums , packet1.velocity_ef_x , packet1.velocity_ef_y , packet1.velocity_ef_z , packet1.yaw , packet1.battery_capacity );
    mavlink_msg_wk_rtk_beacon_inav_data_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_wk_rtk_beacon_inav_data_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_rtk_beacon_inav_data_send(MAVLINK_COMM_1 , packet1.seq , packet1.latitude , packet1.longitude , packet1.gnss_height , packet1.gps_fix_type , packet1.sv_nums , packet1.velocity_ef_x , packet1.velocity_ef_y , packet1.velocity_ef_z , packet1.yaw , packet1.battery_capacity );
    mavlink_msg_wk_rtk_beacon_inav_data_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_wk_rtk_beacon_antenna_offset(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_WK_RTK_BEACON_ANTENNA_OFFSET >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_wk_rtk_beacon_antenna_offset_t packet_in = {
        963497464,963497672,963497880,963498088
    };
    mavlink_wk_rtk_beacon_antenna_offset_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.ant_offset_x = packet_in.ant_offset_x;
        packet1.ant_offset_y = packet_in.ant_offset_y;
        packet1.ant_offset_z = packet_in.ant_offset_z;
        packet1.land_offset = packet_in.land_offset;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_WK_RTK_BEACON_ANTENNA_OFFSET_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_WK_RTK_BEACON_ANTENNA_OFFSET_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_rtk_beacon_antenna_offset_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_wk_rtk_beacon_antenna_offset_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_rtk_beacon_antenna_offset_pack(system_id, component_id, &msg , packet1.ant_offset_x , packet1.ant_offset_y , packet1.ant_offset_z , packet1.land_offset );
    mavlink_msg_wk_rtk_beacon_antenna_offset_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_rtk_beacon_antenna_offset_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.ant_offset_x , packet1.ant_offset_y , packet1.ant_offset_z , packet1.land_offset );
    mavlink_msg_wk_rtk_beacon_antenna_offset_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_wk_rtk_beacon_antenna_offset_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_rtk_beacon_antenna_offset_send(MAVLINK_COMM_1 , packet1.ant_offset_x , packet1.ant_offset_y , packet1.ant_offset_z , packet1.land_offset );
    mavlink_msg_wk_rtk_beacon_antenna_offset_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_wk_param_value(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_WK_PARAM_VALUE >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_wk_param_value_t packet_in = {
        17.0,45.0,73.0,17859,17963,"QRSTUVWXYZABCDE",101,168
    };
    mavlink_wk_param_value_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.param_value = packet_in.param_value;
        packet1.param_maximum = packet_in.param_maximum;
        packet1.param_minimum = packet_in.param_minimum;
        packet1.param_count = packet_in.param_count;
        packet1.param_index = packet_in.param_index;
        packet1.attribute = packet_in.attribute;
        packet1.param_type = packet_in.param_type;
        
        mav_array_memcpy(packet1.param_id, packet_in.param_id, sizeof(char)*16);
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_WK_PARAM_VALUE_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_WK_PARAM_VALUE_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_param_value_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_wk_param_value_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_param_value_pack(system_id, component_id, &msg , packet1.param_id , packet1.param_value , packet1.param_maximum , packet1.param_minimum , packet1.attribute , packet1.param_type , packet1.param_count , packet1.param_index );
    mavlink_msg_wk_param_value_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_param_value_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.param_id , packet1.param_value , packet1.param_maximum , packet1.param_minimum , packet1.attribute , packet1.param_type , packet1.param_count , packet1.param_index );
    mavlink_msg_wk_param_value_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_wk_param_value_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_param_value_send(MAVLINK_COMM_1 , packet1.param_id , packet1.param_value , packet1.param_maximum , packet1.param_minimum , packet1.attribute , packet1.param_type , packet1.param_count , packet1.param_index );
    mavlink_msg_wk_param_value_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_mission_item_int_ext(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_MISSION_ITEM_INT_EXT >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_mission_item_int_ext_t packet_in = {
        17.0,45.0,73.0,101.0,963498296,963498504,185.0,18691,18795,101,168,235,46,113,{ 180, 181, 182, 183, 184, 185, 186, 187, 188, 189, 190, 191, 192, 193, 194, 195, 196, 197, 198, 199, 200, 201, 202, 203, 204, 205, 206, 207, 208, 209, 210, 211, 212, 213, 214, 215, 216, 217, 218, 219, 220, 221, 222, 223, 224, 225, 226, 227, 228, 229, 230, 231, 232, 233, 234, 235, 236, 237, 238, 239, 240, 241, 242, 243, 244, 245, 246, 247, 248, 249, 250, 251, 252, 253, 254, 255, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51 },52
    };
    mavlink_mission_item_int_ext_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.param1 = packet_in.param1;
        packet1.param2 = packet_in.param2;
        packet1.param3 = packet_in.param3;
        packet1.param4 = packet_in.param4;
        packet1.x = packet_in.x;
        packet1.y = packet_in.y;
        packet1.z = packet_in.z;
        packet1.seq = packet_in.seq;
        packet1.command = packet_in.command;
        packet1.target_system = packet_in.target_system;
        packet1.target_component = packet_in.target_component;
        packet1.frame = packet_in.frame;
        packet1.current = packet_in.current;
        packet1.autocontinue = packet_in.autocontinue;
        packet1.mission_type = packet_in.mission_type;
        
        mav_array_memcpy(packet1.name, packet_in.name, sizeof(uint8_t)*128);
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_MISSION_ITEM_INT_EXT_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_MISSION_ITEM_INT_EXT_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_mission_item_int_ext_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_mission_item_int_ext_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_mission_item_int_ext_pack(system_id, component_id, &msg , packet1.target_system , packet1.target_component , packet1.seq , packet1.frame , packet1.command , packet1.current , packet1.autocontinue , packet1.param1 , packet1.param2 , packet1.param3 , packet1.param4 , packet1.x , packet1.y , packet1.z , packet1.name , packet1.mission_type );
    mavlink_msg_mission_item_int_ext_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_mission_item_int_ext_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.target_system , packet1.target_component , packet1.seq , packet1.frame , packet1.command , packet1.current , packet1.autocontinue , packet1.param1 , packet1.param2 , packet1.param3 , packet1.param4 , packet1.x , packet1.y , packet1.z , packet1.name , packet1.mission_type );
    mavlink_msg_mission_item_int_ext_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_mission_item_int_ext_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_mission_item_int_ext_send(MAVLINK_COMM_1 , packet1.target_system , packet1.target_component , packet1.seq , packet1.frame , packet1.command , packet1.current , packet1.autocontinue , packet1.param1 , packet1.param2 , packet1.param3 , packet1.param4 , packet1.x , packet1.y , packet1.z , packet1.name , packet1.mission_type );
    mavlink_msg_mission_item_int_ext_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_wk_camera_state(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_WK_CAMERA_STATE >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_wk_camera_state_t packet_in = {
        963497464,963497672,29,96
    };
    mavlink_wk_camera_state_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.takephoto_resp_timestamp = packet_in.takephoto_resp_timestamp;
        packet1.video_resp_timestamp = packet_in.video_resp_timestamp;
        packet1.takephoto_ack_flag = packet_in.takephoto_ack_flag;
        packet1.vidio_ack_flag = packet_in.vidio_ack_flag;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_WK_CAMERA_STATE_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_WK_CAMERA_STATE_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_camera_state_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_wk_camera_state_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_camera_state_pack(system_id, component_id, &msg , packet1.takephoto_ack_flag , packet1.takephoto_resp_timestamp , packet1.vidio_ack_flag , packet1.video_resp_timestamp );
    mavlink_msg_wk_camera_state_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_camera_state_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.takephoto_ack_flag , packet1.takephoto_resp_timestamp , packet1.vidio_ack_flag , packet1.video_resp_timestamp );
    mavlink_msg_wk_camera_state_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_wk_camera_state_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_camera_state_send(MAVLINK_COMM_1 , packet1.takephoto_ack_flag , packet1.takephoto_resp_timestamp , packet1.vidio_ack_flag , packet1.video_resp_timestamp );
    mavlink_msg_wk_camera_state_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_wk_camera_capture_state(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_WK_CAMERA_CAPTURE_STATE >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_wk_camera_capture_state_t packet_in = {
        963497464,963497672,963497880,963498088,53,120
    };
    mavlink_wk_camera_capture_state_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.takephoto_ack_value1 = packet_in.takephoto_ack_value1;
        packet1.takephoto_ack_value2 = packet_in.takephoto_ack_value2;
        packet1.takephoto_ack_value3 = packet_in.takephoto_ack_value3;
        packet1.takephoto_resp_timestamp = packet_in.takephoto_resp_timestamp;
        packet1.takephoto_ack_mode = packet_in.takephoto_ack_mode;
        packet1.takephoto_ack_flag = packet_in.takephoto_ack_flag;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_WK_CAMERA_CAPTURE_STATE_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_WK_CAMERA_CAPTURE_STATE_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_camera_capture_state_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_wk_camera_capture_state_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_camera_capture_state_pack(system_id, component_id, &msg , packet1.takephoto_ack_mode , packet1.takephoto_ack_flag , packet1.takephoto_ack_value1 , packet1.takephoto_ack_value2 , packet1.takephoto_ack_value3 , packet1.takephoto_resp_timestamp );
    mavlink_msg_wk_camera_capture_state_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_camera_capture_state_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.takephoto_ack_mode , packet1.takephoto_ack_flag , packet1.takephoto_ack_value1 , packet1.takephoto_ack_value2 , packet1.takephoto_ack_value3 , packet1.takephoto_resp_timestamp );
    mavlink_msg_wk_camera_capture_state_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_wk_camera_capture_state_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_camera_capture_state_send(MAVLINK_COMM_1 , packet1.takephoto_ack_mode , packet1.takephoto_ack_flag , packet1.takephoto_ack_value1 , packet1.takephoto_ack_value2 , packet1.takephoto_ack_value3 , packet1.takephoto_resp_timestamp );
    mavlink_msg_wk_camera_capture_state_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_wk_camera_time_lapse_state(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_WK_CAMERA_TIME_LAPSE_STATE >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_wk_camera_time_lapse_state_t packet_in = {
        963497464,963497672,29,96
    };
    mavlink_wk_camera_time_lapse_state_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.time_lapse_time = packet_in.time_lapse_time;
        packet1.time_lapse_timestamp = packet_in.time_lapse_timestamp;
        packet1.time_lapse_mode = packet_in.time_lapse_mode;
        packet1.time_lapse_state = packet_in.time_lapse_state;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_WK_CAMERA_TIME_LAPSE_STATE_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_WK_CAMERA_TIME_LAPSE_STATE_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_camera_time_lapse_state_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_wk_camera_time_lapse_state_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_camera_time_lapse_state_pack(system_id, component_id, &msg , packet1.time_lapse_mode , packet1.time_lapse_state , packet1.time_lapse_time , packet1.time_lapse_timestamp );
    mavlink_msg_wk_camera_time_lapse_state_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_camera_time_lapse_state_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.time_lapse_mode , packet1.time_lapse_state , packet1.time_lapse_time , packet1.time_lapse_timestamp );
    mavlink_msg_wk_camera_time_lapse_state_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_wk_camera_time_lapse_state_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_camera_time_lapse_state_send(MAVLINK_COMM_1 , packet1.time_lapse_mode , packet1.time_lapse_state , packet1.time_lapse_time , packet1.time_lapse_timestamp );
    mavlink_msg_wk_camera_time_lapse_state_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_wk_camera_hardware_params(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_WK_CAMERA_HARDWARE_PARAMS >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_wk_camera_hardware_params_t packet_in = {
        17.0,45.0,73.0,101.0,129.0,963498504,963498712
    };
    mavlink_wk_camera_hardware_params_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.sensor_width = packet_in.sensor_width;
        packet1.sensor_height = packet_in.sensor_height;
        packet1.pixel_size = packet_in.pixel_size;
        packet1.aperture_size = packet_in.aperture_size;
        packet1.focal_length = packet_in.focal_length;
        packet1.pictrue_width = packet_in.pictrue_width;
        packet1.pictrue_height = packet_in.pictrue_height;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_WK_CAMERA_HARDWARE_PARAMS_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_WK_CAMERA_HARDWARE_PARAMS_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_camera_hardware_params_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_wk_camera_hardware_params_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_camera_hardware_params_pack(system_id, component_id, &msg , packet1.sensor_width , packet1.sensor_height , packet1.pixel_size , packet1.aperture_size , packet1.focal_length , packet1.pictrue_width , packet1.pictrue_height );
    mavlink_msg_wk_camera_hardware_params_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_camera_hardware_params_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.sensor_width , packet1.sensor_height , packet1.pixel_size , packet1.aperture_size , packet1.focal_length , packet1.pictrue_width , packet1.pictrue_height );
    mavlink_msg_wk_camera_hardware_params_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_wk_camera_hardware_params_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_camera_hardware_params_send(MAVLINK_COMM_1 , packet1.sensor_width , packet1.sensor_height , packet1.pixel_size , packet1.aperture_size , packet1.focal_length , packet1.pictrue_width , packet1.pictrue_height );
    mavlink_msg_wk_camera_hardware_params_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_wk_camera_takephoto_record_info(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_WK_CAMERA_TAKEPHOTO_RECORD_INFO >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_wk_camera_takephoto_record_info_t packet_in = {
        963497464,963497672,963497880,963498088,963498296,963498504,963498712,963498920,963499128,963499336,{ 125, 126, 127, 128, 129, 130, 131, 132, 133, 134, 135, 136, 137, 138, 139, 140, 141, 142, 143, 144, 145, 146, 147, 148, 149, 150, 151, 152, 153, 154, 155, 156, 157, 158, 159, 160, 161, 162, 163, 164, 165, 166, 167, 168, 169, 170, 171, 172, 173, 174, 175, 176, 177, 178, 179, 180, 181, 182, 183, 184, 185, 186, 187, 188, 189, 190, 191, 192, 193, 194, 195, 196, 197, 198, 199, 200, 201, 202, 203, 204, 205, 206, 207, 208, 209, 210, 211, 212, 213, 214, 215, 216, 217, 218, 219, 220, 221, 222, 223, 224, 225, 226, 227, 228, 229, 230, 231, 232, 233, 234, 235, 236, 237, 238, 239, 240, 241, 242, 243, 244, 245, 246, 247, 248, 249, 250, 251, 252 },{ 253, 254, 255, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12 }
    };
    mavlink_wk_camera_takephoto_record_info_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.uav_longitude = packet_in.uav_longitude;
        packet1.uav_lattitude = packet_in.uav_lattitude;
        packet1.uav_altitude = packet_in.uav_altitude;
        packet1.uav_roll = packet_in.uav_roll;
        packet1.uav_pitch = packet_in.uav_pitch;
        packet1.uav_yaw = packet_in.uav_yaw;
        packet1.gimbal_roll = packet_in.gimbal_roll;
        packet1.gimbal_pitch = packet_in.gimbal_pitch;
        packet1.gimbal_yaw = packet_in.gimbal_yaw;
        packet1.timestamp = packet_in.timestamp;
        
        mav_array_memcpy(packet1.filename, packet_in.filename, sizeof(uint8_t)*128);
        mav_array_memcpy(packet1.reserved, packet_in.reserved, sizeof(uint8_t)*16);
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_WK_CAMERA_TAKEPHOTO_RECORD_INFO_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_WK_CAMERA_TAKEPHOTO_RECORD_INFO_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_camera_takephoto_record_info_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_wk_camera_takephoto_record_info_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_camera_takephoto_record_info_pack(system_id, component_id, &msg , packet1.uav_longitude , packet1.uav_lattitude , packet1.uav_altitude , packet1.uav_roll , packet1.uav_pitch , packet1.uav_yaw , packet1.gimbal_roll , packet1.gimbal_pitch , packet1.gimbal_yaw , packet1.timestamp , packet1.filename , packet1.reserved );
    mavlink_msg_wk_camera_takephoto_record_info_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_camera_takephoto_record_info_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.uav_longitude , packet1.uav_lattitude , packet1.uav_altitude , packet1.uav_roll , packet1.uav_pitch , packet1.uav_yaw , packet1.gimbal_roll , packet1.gimbal_pitch , packet1.gimbal_yaw , packet1.timestamp , packet1.filename , packet1.reserved );
    mavlink_msg_wk_camera_takephoto_record_info_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_wk_camera_takephoto_record_info_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_camera_takephoto_record_info_send(MAVLINK_COMM_1 , packet1.uav_longitude , packet1.uav_lattitude , packet1.uav_altitude , packet1.uav_roll , packet1.uav_pitch , packet1.uav_yaw , packet1.gimbal_roll , packet1.gimbal_pitch , packet1.gimbal_yaw , packet1.timestamp , packet1.filename , packet1.reserved );
    mavlink_msg_wk_camera_takephoto_record_info_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_wk_camera_params_rpt(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_WK_CAMERA_PARAMS_RPT >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_wk_camera_params_rpt_t packet_in = {
        963497464,45.0,73.0,963498088,963498296,65,132,199,10,77,144,211,22,89,156,223,34,101,168,235,46,113,180,247,{ 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73 }
    };
    mavlink_wk_camera_params_rpt_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.serial_number = packet_in.serial_number;
        packet1.focal_length = packet_in.focal_length;
        packet1.focal_length_35mm = packet_in.focal_length_35mm;
        packet1.iso = packet_in.iso;
        packet1.shutter = packet_in.shutter;
        packet1.cap_mode = packet_in.cap_mode;
        packet1.cap_continues = packet_in.cap_continues;
        packet1.cap_save_format = packet_in.cap_save_format;
        packet1.cap_resolution = packet_in.cap_resolution;
        packet1.cap_rotation = packet_in.cap_rotation;
        packet1.major_ver = packet_in.major_ver;
        packet1.minor_ver = packet_in.minor_ver;
        packet1.stream_enc_type = packet_in.stream_enc_type;
        packet1.preview_resolution = packet_in.preview_resolution;
        packet1.preview_bitrate = packet_in.preview_bitrate;
        packet1.record_resolution = packet_in.record_resolution;
        packet1.record_bitrate = packet_in.record_bitrate;
        packet1.csc_luma = packet_in.csc_luma;
        packet1.csc_contrast = packet_in.csc_contrast;
        packet1.csc_hue = packet_in.csc_hue;
        packet1.csc_aturation = packet_in.csc_aturation;
        packet1.awb_mode = packet_in.awb_mode;
        packet1.ev_mode = packet_in.ev_mode;
        packet1.ev_value = packet_in.ev_value;
        
        mav_array_memcpy(packet1.reserved, packet_in.reserved, sizeof(uint8_t)*16);
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_WK_CAMERA_PARAMS_RPT_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_WK_CAMERA_PARAMS_RPT_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_camera_params_rpt_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_wk_camera_params_rpt_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_camera_params_rpt_pack(system_id, component_id, &msg , packet1.cap_mode , packet1.cap_continues , packet1.cap_save_format , packet1.cap_resolution , packet1.cap_rotation , packet1.major_ver , packet1.minor_ver , packet1.serial_number , packet1.focal_length , packet1.focal_length_35mm , packet1.stream_enc_type , packet1.preview_resolution , packet1.preview_bitrate , packet1.record_resolution , packet1.record_bitrate , packet1.csc_luma , packet1.csc_contrast , packet1.csc_hue , packet1.csc_aturation , packet1.awb_mode , packet1.ev_mode , packet1.ev_value , packet1.iso , packet1.shutter , packet1.reserved );
    mavlink_msg_wk_camera_params_rpt_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_camera_params_rpt_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.cap_mode , packet1.cap_continues , packet1.cap_save_format , packet1.cap_resolution , packet1.cap_rotation , packet1.major_ver , packet1.minor_ver , packet1.serial_number , packet1.focal_length , packet1.focal_length_35mm , packet1.stream_enc_type , packet1.preview_resolution , packet1.preview_bitrate , packet1.record_resolution , packet1.record_bitrate , packet1.csc_luma , packet1.csc_contrast , packet1.csc_hue , packet1.csc_aturation , packet1.awb_mode , packet1.ev_mode , packet1.ev_value , packet1.iso , packet1.shutter , packet1.reserved );
    mavlink_msg_wk_camera_params_rpt_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_wk_camera_params_rpt_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_camera_params_rpt_send(MAVLINK_COMM_1 , packet1.cap_mode , packet1.cap_continues , packet1.cap_save_format , packet1.cap_resolution , packet1.cap_rotation , packet1.major_ver , packet1.minor_ver , packet1.serial_number , packet1.focal_length , packet1.focal_length_35mm , packet1.stream_enc_type , packet1.preview_resolution , packet1.preview_bitrate , packet1.record_resolution , packet1.record_bitrate , packet1.csc_luma , packet1.csc_contrast , packet1.csc_hue , packet1.csc_aturation , packet1.awb_mode , packet1.ev_mode , packet1.ev_value , packet1.iso , packet1.shutter , packet1.reserved );
    mavlink_msg_wk_camera_params_rpt_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_wk_camera_cmd_common_params(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_WK_CAMERA_CMD_COMMON_PARAMS >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_wk_camera_cmd_common_params_t packet_in = {
        963497464,963497672,29,96,163,230,41,108,175,242,53,120,187,254,65,132,199,10,77,{ 144, 145, 146, 147, 148, 149, 150, 151, 152, 153, 154, 155, 156, 157, 158, 159 }
    };
    mavlink_wk_camera_cmd_common_params_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.iso = packet_in.iso;
        packet1.shutter = packet_in.shutter;
        packet1.cap_mode = packet_in.cap_mode;
        packet1.cap_continues = packet_in.cap_continues;
        packet1.cap_save_format = packet_in.cap_save_format;
        packet1.cap_resolution = packet_in.cap_resolution;
        packet1.cap_rotation = packet_in.cap_rotation;
        packet1.stream_enc_type = packet_in.stream_enc_type;
        packet1.preview_resolution = packet_in.preview_resolution;
        packet1.preview_bitrate = packet_in.preview_bitrate;
        packet1.record_resolution = packet_in.record_resolution;
        packet1.record_bitrate = packet_in.record_bitrate;
        packet1.csc_luma = packet_in.csc_luma;
        packet1.csc_contrast = packet_in.csc_contrast;
        packet1.csc_hue = packet_in.csc_hue;
        packet1.csc_aturation = packet_in.csc_aturation;
        packet1.awb_mode = packet_in.awb_mode;
        packet1.ev_mode = packet_in.ev_mode;
        packet1.ev_value = packet_in.ev_value;
        
        mav_array_memcpy(packet1.reserved, packet_in.reserved, sizeof(uint8_t)*16);
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_WK_CAMERA_CMD_COMMON_PARAMS_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_WK_CAMERA_CMD_COMMON_PARAMS_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_camera_cmd_common_params_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_wk_camera_cmd_common_params_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_camera_cmd_common_params_pack(system_id, component_id, &msg , packet1.cap_mode , packet1.cap_continues , packet1.cap_save_format , packet1.cap_resolution , packet1.cap_rotation , packet1.stream_enc_type , packet1.preview_resolution , packet1.preview_bitrate , packet1.record_resolution , packet1.record_bitrate , packet1.csc_luma , packet1.csc_contrast , packet1.csc_hue , packet1.csc_aturation , packet1.awb_mode , packet1.ev_mode , packet1.ev_value , packet1.iso , packet1.shutter , packet1.reserved );
    mavlink_msg_wk_camera_cmd_common_params_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_camera_cmd_common_params_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.cap_mode , packet1.cap_continues , packet1.cap_save_format , packet1.cap_resolution , packet1.cap_rotation , packet1.stream_enc_type , packet1.preview_resolution , packet1.preview_bitrate , packet1.record_resolution , packet1.record_bitrate , packet1.csc_luma , packet1.csc_contrast , packet1.csc_hue , packet1.csc_aturation , packet1.awb_mode , packet1.ev_mode , packet1.ev_value , packet1.iso , packet1.shutter , packet1.reserved );
    mavlink_msg_wk_camera_cmd_common_params_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_wk_camera_cmd_common_params_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_camera_cmd_common_params_send(MAVLINK_COMM_1 , packet1.cap_mode , packet1.cap_continues , packet1.cap_save_format , packet1.cap_resolution , packet1.cap_rotation , packet1.stream_enc_type , packet1.preview_resolution , packet1.preview_bitrate , packet1.record_resolution , packet1.record_bitrate , packet1.csc_luma , packet1.csc_contrast , packet1.csc_hue , packet1.csc_aturation , packet1.awb_mode , packet1.ev_mode , packet1.ev_value , packet1.iso , packet1.shutter , packet1.reserved );
    mavlink_msg_wk_camera_cmd_common_params_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_wk_camera_cmd_takephoto(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_WK_CAMERA_CMD_TAKEPHOTO >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_wk_camera_cmd_takephoto_t packet_in = {
        963497464,963497672,963497880,963498088,129.0,157.0,185.0,213.0,241.0,269.0,125
    };
    mavlink_wk_camera_cmd_takephoto_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.trig_timestamps = packet_in.trig_timestamps;
        packet1.longitude = packet_in.longitude;
        packet1.latitude = packet_in.latitude;
        packet1.altitude = packet_in.altitude;
        packet1.UavRoll = packet_in.UavRoll;
        packet1.UavPitch = packet_in.UavPitch;
        packet1.UavYaw = packet_in.UavYaw;
        packet1.GimbalRoll = packet_in.GimbalRoll;
        packet1.GimbalPitch = packet_in.GimbalPitch;
        packet1.GimbalYaw = packet_in.GimbalYaw;
        packet1.response_code = packet_in.response_code;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_WK_CAMERA_CMD_TAKEPHOTO_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_WK_CAMERA_CMD_TAKEPHOTO_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_camera_cmd_takephoto_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_wk_camera_cmd_takephoto_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_camera_cmd_takephoto_pack(system_id, component_id, &msg , packet1.trig_timestamps , packet1.response_code , packet1.longitude , packet1.latitude , packet1.altitude , packet1.UavRoll , packet1.UavPitch , packet1.UavYaw , packet1.GimbalRoll , packet1.GimbalPitch , packet1.GimbalYaw );
    mavlink_msg_wk_camera_cmd_takephoto_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_camera_cmd_takephoto_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.trig_timestamps , packet1.response_code , packet1.longitude , packet1.latitude , packet1.altitude , packet1.UavRoll , packet1.UavPitch , packet1.UavYaw , packet1.GimbalRoll , packet1.GimbalPitch , packet1.GimbalYaw );
    mavlink_msg_wk_camera_cmd_takephoto_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_wk_camera_cmd_takephoto_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_camera_cmd_takephoto_send(MAVLINK_COMM_1 , packet1.trig_timestamps , packet1.response_code , packet1.longitude , packet1.latitude , packet1.altitude , packet1.UavRoll , packet1.UavPitch , packet1.UavYaw , packet1.GimbalRoll , packet1.GimbalPitch , packet1.GimbalYaw );
    mavlink_msg_wk_camera_cmd_takephoto_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_wk_camera_cmd_video_rec(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_WK_CAMERA_CMD_VIDEO_REC >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_wk_camera_cmd_video_rec_t packet_in = {
        963497464,17,84
    };
    mavlink_wk_camera_cmd_video_rec_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.trig_timestamps = packet_in.trig_timestamps;
        packet1.cmd_type = packet_in.cmd_type;
        packet1.response_code = packet_in.response_code;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_WK_CAMERA_CMD_VIDEO_REC_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_WK_CAMERA_CMD_VIDEO_REC_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_camera_cmd_video_rec_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_wk_camera_cmd_video_rec_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_camera_cmd_video_rec_pack(system_id, component_id, &msg , packet1.cmd_type , packet1.trig_timestamps , packet1.response_code );
    mavlink_msg_wk_camera_cmd_video_rec_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_camera_cmd_video_rec_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.cmd_type , packet1.trig_timestamps , packet1.response_code );
    mavlink_msg_wk_camera_cmd_video_rec_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_wk_camera_cmd_video_rec_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_camera_cmd_video_rec_send(MAVLINK_COMM_1 , packet1.cmd_type , packet1.trig_timestamps , packet1.response_code );
    mavlink_msg_wk_camera_cmd_video_rec_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_wk_camera_cmd_sdcard_format(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_WK_CAMERA_CMD_SDCARD_FORMAT >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_wk_camera_cmd_sdcard_format_t packet_in = {
        5,72
    };
    mavlink_wk_camera_cmd_sdcard_format_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.format_type = packet_in.format_type;
        packet1.response_code = packet_in.response_code;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_WK_CAMERA_CMD_SDCARD_FORMAT_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_WK_CAMERA_CMD_SDCARD_FORMAT_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_camera_cmd_sdcard_format_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_wk_camera_cmd_sdcard_format_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_camera_cmd_sdcard_format_pack(system_id, component_id, &msg , packet1.format_type , packet1.response_code );
    mavlink_msg_wk_camera_cmd_sdcard_format_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_camera_cmd_sdcard_format_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.format_type , packet1.response_code );
    mavlink_msg_wk_camera_cmd_sdcard_format_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_wk_camera_cmd_sdcard_format_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_camera_cmd_sdcard_format_send(MAVLINK_COMM_1 , packet1.format_type , packet1.response_code );
    mavlink_msg_wk_camera_cmd_sdcard_format_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_wk_camera_status_report(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_WK_CAMERA_STATUS_REPORT >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_wk_camera_status_report_t packet_in = {
        963497464,963497672,963497880,963498088,53,120,{ 187, 188, 189, 190, 191, 192, 193, 194, 195, 196, 197, 198, 199, 200, 201, 202 }
    };
    mavlink_wk_camera_status_report_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.sdcard_capacity_total_bytes = packet_in.sdcard_capacity_total_bytes;
        packet1.sdcard_capacity_free_bytes = packet_in.sdcard_capacity_free_bytes;
        packet1.video_record_time = packet_in.video_record_time;
        packet1.capability_flags = packet_in.capability_flags;
        packet1.sdcard_status = packet_in.sdcard_status;
        packet1.sdcard_filesystem = packet_in.sdcard_filesystem;
        
        mav_array_memcpy(packet1.reserved, packet_in.reserved, sizeof(uint8_t)*16);
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_WK_CAMERA_STATUS_REPORT_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_WK_CAMERA_STATUS_REPORT_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_camera_status_report_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_wk_camera_status_report_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_camera_status_report_pack(system_id, component_id, &msg , packet1.sdcard_status , packet1.sdcard_filesystem , packet1.sdcard_capacity_total_bytes , packet1.sdcard_capacity_free_bytes , packet1.video_record_time , packet1.capability_flags , packet1.reserved );
    mavlink_msg_wk_camera_status_report_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_camera_status_report_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.sdcard_status , packet1.sdcard_filesystem , packet1.sdcard_capacity_total_bytes , packet1.sdcard_capacity_free_bytes , packet1.video_record_time , packet1.capability_flags , packet1.reserved );
    mavlink_msg_wk_camera_status_report_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_wk_camera_status_report_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_camera_status_report_send(MAVLINK_COMM_1 , packet1.sdcard_status , packet1.sdcard_filesystem , packet1.sdcard_capacity_total_bytes , packet1.sdcard_capacity_free_bytes , packet1.video_record_time , packet1.capability_flags , packet1.reserved );
    mavlink_msg_wk_camera_status_report_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_wk_camera_cmd_focus(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_WK_CAMERA_CMD_FOCUS >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_wk_camera_cmd_focus_t packet_in = {
        5
    };
    mavlink_wk_camera_cmd_focus_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.type = packet_in.type;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_WK_CAMERA_CMD_FOCUS_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_WK_CAMERA_CMD_FOCUS_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_camera_cmd_focus_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_wk_camera_cmd_focus_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_camera_cmd_focus_pack(system_id, component_id, &msg , packet1.type );
    mavlink_msg_wk_camera_cmd_focus_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_camera_cmd_focus_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.type );
    mavlink_msg_wk_camera_cmd_focus_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_wk_camera_cmd_focus_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_camera_cmd_focus_send(MAVLINK_COMM_1 , packet1.type );
    mavlink_msg_wk_camera_cmd_focus_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_wk_camera_cmd_utc_time_sync(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_WK_CAMERA_CMD_UTC_TIME_SYNC >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_wk_camera_cmd_utc_time_sync_t packet_in = {
        17235,139,206,17,84,151
    };
    mavlink_wk_camera_cmd_utc_time_sync_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.year = packet_in.year;
        packet1.month = packet_in.month;
        packet1.day = packet_in.day;
        packet1.hour = packet_in.hour;
        packet1.min = packet_in.min;
        packet1.sec = packet_in.sec;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_WK_CAMERA_CMD_UTC_TIME_SYNC_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_WK_CAMERA_CMD_UTC_TIME_SYNC_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_camera_cmd_utc_time_sync_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_wk_camera_cmd_utc_time_sync_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_camera_cmd_utc_time_sync_pack(system_id, component_id, &msg , packet1.year , packet1.month , packet1.day , packet1.hour , packet1.min , packet1.sec );
    mavlink_msg_wk_camera_cmd_utc_time_sync_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_camera_cmd_utc_time_sync_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.year , packet1.month , packet1.day , packet1.hour , packet1.min , packet1.sec );
    mavlink_msg_wk_camera_cmd_utc_time_sync_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_wk_camera_cmd_utc_time_sync_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_camera_cmd_utc_time_sync_send(MAVLINK_COMM_1 , packet1.year , packet1.month , packet1.day , packet1.hour , packet1.min , packet1.sec );
    mavlink_msg_wk_camera_cmd_utc_time_sync_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_wk_camera_cmd_create_folder(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_WK_CAMERA_CMD_CREATE_FOLDER >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_wk_camera_cmd_create_folder_t packet_in = {
        { 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68 }
    };
    mavlink_wk_camera_cmd_create_folder_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        
        mav_array_memcpy(packet1.folder_name, packet_in.folder_name, sizeof(uint8_t)*64);
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_WK_CAMERA_CMD_CREATE_FOLDER_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_WK_CAMERA_CMD_CREATE_FOLDER_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_camera_cmd_create_folder_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_wk_camera_cmd_create_folder_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_camera_cmd_create_folder_pack(system_id, component_id, &msg , packet1.folder_name );
    mavlink_msg_wk_camera_cmd_create_folder_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_camera_cmd_create_folder_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.folder_name );
    mavlink_msg_wk_camera_cmd_create_folder_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_wk_camera_cmd_create_folder_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_camera_cmd_create_folder_send(MAVLINK_COMM_1 , packet1.folder_name );
    mavlink_msg_wk_camera_cmd_create_folder_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_wk_camera_cmd_cap_param(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_WK_CAMERA_CMD_CAP_PARAM >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_wk_camera_cmd_cap_param_t packet_in = {
        5,72,139,206,17
    };
    mavlink_wk_camera_cmd_cap_param_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.cap_mode = packet_in.cap_mode;
        packet1.cap_continues = packet_in.cap_continues;
        packet1.cap_save_format = packet_in.cap_save_format;
        packet1.cap_resolution = packet_in.cap_resolution;
        packet1.cap_rotation = packet_in.cap_rotation;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_WK_CAMERA_CMD_CAP_PARAM_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_WK_CAMERA_CMD_CAP_PARAM_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_camera_cmd_cap_param_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_wk_camera_cmd_cap_param_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_camera_cmd_cap_param_pack(system_id, component_id, &msg , packet1.cap_mode , packet1.cap_continues , packet1.cap_save_format , packet1.cap_resolution , packet1.cap_rotation );
    mavlink_msg_wk_camera_cmd_cap_param_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_camera_cmd_cap_param_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.cap_mode , packet1.cap_continues , packet1.cap_save_format , packet1.cap_resolution , packet1.cap_rotation );
    mavlink_msg_wk_camera_cmd_cap_param_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_wk_camera_cmd_cap_param_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_camera_cmd_cap_param_send(MAVLINK_COMM_1 , packet1.cap_mode , packet1.cap_continues , packet1.cap_save_format , packet1.cap_resolution , packet1.cap_rotation );
    mavlink_msg_wk_camera_cmd_cap_param_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_wk_camera_cmd_preview_param(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_WK_CAMERA_CMD_PREVIEW_PARAM >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_wk_camera_cmd_preview_param_t packet_in = {
        5,72
    };
    mavlink_wk_camera_cmd_preview_param_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.preview_resolution = packet_in.preview_resolution;
        packet1.preview_bitrate = packet_in.preview_bitrate;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_WK_CAMERA_CMD_PREVIEW_PARAM_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_WK_CAMERA_CMD_PREVIEW_PARAM_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_camera_cmd_preview_param_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_wk_camera_cmd_preview_param_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_camera_cmd_preview_param_pack(system_id, component_id, &msg , packet1.preview_resolution , packet1.preview_bitrate );
    mavlink_msg_wk_camera_cmd_preview_param_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_camera_cmd_preview_param_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.preview_resolution , packet1.preview_bitrate );
    mavlink_msg_wk_camera_cmd_preview_param_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_wk_camera_cmd_preview_param_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_camera_cmd_preview_param_send(MAVLINK_COMM_1 , packet1.preview_resolution , packet1.preview_bitrate );
    mavlink_msg_wk_camera_cmd_preview_param_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_wk_camera_cmd_record_param(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_WK_CAMERA_CMD_RECORD_PARAM >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_wk_camera_cmd_record_param_t packet_in = {
        5,72
    };
    mavlink_wk_camera_cmd_record_param_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.record_resolution = packet_in.record_resolution;
        packet1.record_bitrate = packet_in.record_bitrate;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_WK_CAMERA_CMD_RECORD_PARAM_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_WK_CAMERA_CMD_RECORD_PARAM_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_camera_cmd_record_param_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_wk_camera_cmd_record_param_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_camera_cmd_record_param_pack(system_id, component_id, &msg , packet1.record_resolution , packet1.record_bitrate );
    mavlink_msg_wk_camera_cmd_record_param_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_camera_cmd_record_param_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.record_resolution , packet1.record_bitrate );
    mavlink_msg_wk_camera_cmd_record_param_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_wk_camera_cmd_record_param_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_camera_cmd_record_param_send(MAVLINK_COMM_1 , packet1.record_resolution , packet1.record_bitrate );
    mavlink_msg_wk_camera_cmd_record_param_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_wk_camera_cmd_iso(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_WK_CAMERA_CMD_ISO >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_wk_camera_cmd_iso_t packet_in = {
        963497464
    };
    mavlink_wk_camera_cmd_iso_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.iso = packet_in.iso;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_WK_CAMERA_CMD_ISO_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_WK_CAMERA_CMD_ISO_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_camera_cmd_iso_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_wk_camera_cmd_iso_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_camera_cmd_iso_pack(system_id, component_id, &msg , packet1.iso );
    mavlink_msg_wk_camera_cmd_iso_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_camera_cmd_iso_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.iso );
    mavlink_msg_wk_camera_cmd_iso_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_wk_camera_cmd_iso_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_camera_cmd_iso_send(MAVLINK_COMM_1 , packet1.iso );
    mavlink_msg_wk_camera_cmd_iso_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_wk_camera_cmd_shutter(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_WK_CAMERA_CMD_SHUTTER >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_wk_camera_cmd_shutter_t packet_in = {
        963497464
    };
    mavlink_wk_camera_cmd_shutter_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.shutter = packet_in.shutter;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_WK_CAMERA_CMD_SHUTTER_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_WK_CAMERA_CMD_SHUTTER_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_camera_cmd_shutter_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_wk_camera_cmd_shutter_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_camera_cmd_shutter_pack(system_id, component_id, &msg , packet1.shutter );
    mavlink_msg_wk_camera_cmd_shutter_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_camera_cmd_shutter_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.shutter );
    mavlink_msg_wk_camera_cmd_shutter_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_wk_camera_cmd_shutter_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_camera_cmd_shutter_send(MAVLINK_COMM_1 , packet1.shutter );
    mavlink_msg_wk_camera_cmd_shutter_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_wk_camera_cmd_ev_mode(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_WK_CAMERA_CMD_EV_MODE >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_wk_camera_cmd_ev_mode_t packet_in = {
        5
    };
    mavlink_wk_camera_cmd_ev_mode_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.ev_mode = packet_in.ev_mode;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_WK_CAMERA_CMD_EV_MODE_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_WK_CAMERA_CMD_EV_MODE_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_camera_cmd_ev_mode_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_wk_camera_cmd_ev_mode_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_camera_cmd_ev_mode_pack(system_id, component_id, &msg , packet1.ev_mode );
    mavlink_msg_wk_camera_cmd_ev_mode_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_camera_cmd_ev_mode_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.ev_mode );
    mavlink_msg_wk_camera_cmd_ev_mode_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_wk_camera_cmd_ev_mode_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_camera_cmd_ev_mode_send(MAVLINK_COMM_1 , packet1.ev_mode );
    mavlink_msg_wk_camera_cmd_ev_mode_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_wk_camera_cmd_ev_value(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_WK_CAMERA_CMD_EV_VALUE >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_wk_camera_cmd_ev_value_t packet_in = {
        5
    };
    mavlink_wk_camera_cmd_ev_value_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.ev_value = packet_in.ev_value;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_WK_CAMERA_CMD_EV_VALUE_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_WK_CAMERA_CMD_EV_VALUE_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_camera_cmd_ev_value_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_wk_camera_cmd_ev_value_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_camera_cmd_ev_value_pack(system_id, component_id, &msg , packet1.ev_value );
    mavlink_msg_wk_camera_cmd_ev_value_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_camera_cmd_ev_value_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.ev_value );
    mavlink_msg_wk_camera_cmd_ev_value_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_wk_camera_cmd_ev_value_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_camera_cmd_ev_value_send(MAVLINK_COMM_1 , packet1.ev_value );
    mavlink_msg_wk_camera_cmd_ev_value_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_wk_camera_cmd_awb_mode(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_WK_CAMERA_CMD_AWB_MODE >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_wk_camera_cmd_awb_mode_t packet_in = {
        5
    };
    mavlink_wk_camera_cmd_awb_mode_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.awb_mode = packet_in.awb_mode;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_WK_CAMERA_CMD_AWB_MODE_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_WK_CAMERA_CMD_AWB_MODE_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_camera_cmd_awb_mode_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_wk_camera_cmd_awb_mode_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_camera_cmd_awb_mode_pack(system_id, component_id, &msg , packet1.awb_mode );
    mavlink_msg_wk_camera_cmd_awb_mode_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_camera_cmd_awb_mode_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.awb_mode );
    mavlink_msg_wk_camera_cmd_awb_mode_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_wk_camera_cmd_awb_mode_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_camera_cmd_awb_mode_send(MAVLINK_COMM_1 , packet1.awb_mode );
    mavlink_msg_wk_camera_cmd_awb_mode_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_wk_camera_cmd_csc(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_WK_CAMERA_CMD_CSC >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_wk_camera_cmd_csc_t packet_in = {
        5,72,139,206
    };
    mavlink_wk_camera_cmd_csc_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.csc_luma = packet_in.csc_luma;
        packet1.csc_contrast = packet_in.csc_contrast;
        packet1.csc_hue = packet_in.csc_hue;
        packet1.csc_aturation = packet_in.csc_aturation;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_WK_CAMERA_CMD_CSC_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_WK_CAMERA_CMD_CSC_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_camera_cmd_csc_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_wk_camera_cmd_csc_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_camera_cmd_csc_pack(system_id, component_id, &msg , packet1.csc_luma , packet1.csc_contrast , packet1.csc_hue , packet1.csc_aturation );
    mavlink_msg_wk_camera_cmd_csc_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_camera_cmd_csc_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.csc_luma , packet1.csc_contrast , packet1.csc_hue , packet1.csc_aturation );
    mavlink_msg_wk_camera_cmd_csc_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_wk_camera_cmd_csc_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_camera_cmd_csc_send(MAVLINK_COMM_1 , packet1.csc_luma , packet1.csc_contrast , packet1.csc_hue , packet1.csc_aturation );
    mavlink_msg_wk_camera_cmd_csc_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_wk_camera_cmd_hsyk_dualcam_params(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_WK_CAMERA_CMD_HSYK_DUALCAM_PARAMS >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_wk_camera_cmd_hsyk_dualcam_params_t packet_in = {
        5,72
    };
    mavlink_wk_camera_cmd_hsyk_dualcam_params_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.pip_mode = packet_in.pip_mode;
        packet1.pcolor = packet_in.pcolor;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_WK_CAMERA_CMD_HSYK_DUALCAM_PARAMS_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_WK_CAMERA_CMD_HSYK_DUALCAM_PARAMS_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_camera_cmd_hsyk_dualcam_params_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_wk_camera_cmd_hsyk_dualcam_params_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_camera_cmd_hsyk_dualcam_params_pack(system_id, component_id, &msg , packet1.pip_mode , packet1.pcolor );
    mavlink_msg_wk_camera_cmd_hsyk_dualcam_params_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_camera_cmd_hsyk_dualcam_params_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.pip_mode , packet1.pcolor );
    mavlink_msg_wk_camera_cmd_hsyk_dualcam_params_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_wk_camera_cmd_hsyk_dualcam_params_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_camera_cmd_hsyk_dualcam_params_send(MAVLINK_COMM_1 , packet1.pip_mode , packet1.pcolor );
    mavlink_msg_wk_camera_cmd_hsyk_dualcam_params_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_wk_camera_qrcode_pos(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_WK_CAMERA_QRCODE_POS >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_wk_camera_qrcode_pos_t packet_in = {
        17.0,45.0,{ 29, 30, 31, 32, 33, 34, 35, 36 }
    };
    mavlink_wk_camera_qrcode_pos_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.xPos = packet_in.xPos;
        packet1.yPos = packet_in.yPos;
        
        mav_array_memcpy(packet1.reserved, packet_in.reserved, sizeof(uint8_t)*8);
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_WK_CAMERA_QRCODE_POS_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_WK_CAMERA_QRCODE_POS_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_camera_qrcode_pos_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_wk_camera_qrcode_pos_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_camera_qrcode_pos_pack(system_id, component_id, &msg , packet1.xPos , packet1.yPos , packet1.reserved );
    mavlink_msg_wk_camera_qrcode_pos_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_camera_qrcode_pos_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.xPos , packet1.yPos , packet1.reserved );
    mavlink_msg_wk_camera_qrcode_pos_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_wk_camera_qrcode_pos_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_camera_qrcode_pos_send(MAVLINK_COMM_1 , packet1.xPos , packet1.yPos , packet1.reserved );
    mavlink_msg_wk_camera_qrcode_pos_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_wk_5ginfo_status(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_WK_5GINFO_STATUS >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_wk_5ginfo_status_t packet_in = {
        5,72,139,206,17,{ 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99 }
    };
    mavlink_wk_5ginfo_status_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.sim_card_status = packet_in.sim_card_status;
        packet1.network_status = packet_in.network_status;
        packet1.signal_value = packet_in.signal_value;
        packet1.camera_status = packet_in.camera_status;
        packet1.uart_status = packet_in.uart_status;
        
        mav_array_memcpy(packet1.reserved, packet_in.reserved, sizeof(uint8_t)*16);
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_WK_5GINFO_STATUS_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_WK_5GINFO_STATUS_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_5ginfo_status_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_wk_5ginfo_status_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_5ginfo_status_pack(system_id, component_id, &msg , packet1.sim_card_status , packet1.network_status , packet1.signal_value , packet1.camera_status , packet1.uart_status , packet1.reserved );
    mavlink_msg_wk_5ginfo_status_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_5ginfo_status_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.sim_card_status , packet1.network_status , packet1.signal_value , packet1.camera_status , packet1.uart_status , packet1.reserved );
    mavlink_msg_wk_5ginfo_status_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_wk_5ginfo_status_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_5ginfo_status_send(MAVLINK_COMM_1 , packet1.sim_card_status , packet1.network_status , packet1.signal_value , packet1.camera_status , packet1.uart_status , packet1.reserved );
    mavlink_msg_wk_5ginfo_status_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_wk_product_id(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_WK_PRODUCT_ID >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_wk_product_id_t packet_in = {
        { 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34 },223
    };
    mavlink_wk_product_id_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.len = packet_in.len;
        
        mav_array_memcpy(packet1.product_id, packet_in.product_id, sizeof(uint8_t)*30);
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_WK_PRODUCT_ID_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_WK_PRODUCT_ID_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_product_id_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_wk_product_id_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_product_id_pack(system_id, component_id, &msg , packet1.product_id , packet1.len );
    mavlink_msg_wk_product_id_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_product_id_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.product_id , packet1.len );
    mavlink_msg_wk_product_id_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_wk_product_id_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_product_id_send(MAVLINK_COMM_1 , packet1.product_id , packet1.len );
    mavlink_msg_wk_product_id_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_wk_product_bound(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_WK_PRODUCT_BOUND >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_wk_product_bound_t packet_in = {
        { 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36 },101
    };
    mavlink_wk_product_bound_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.bound = packet_in.bound;
        
        mav_array_memcpy(packet1.user_name, packet_in.user_name, sizeof(uint8_t)*32);
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_WK_PRODUCT_BOUND_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_WK_PRODUCT_BOUND_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_product_bound_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_wk_product_bound_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_product_bound_pack(system_id, component_id, &msg , packet1.user_name , packet1.bound );
    mavlink_msg_wk_product_bound_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_product_bound_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.user_name , packet1.bound );
    mavlink_msg_wk_product_bound_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_wk_product_bound_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_product_bound_send(MAVLINK_COMM_1 , packet1.user_name , packet1.bound );
    mavlink_msg_wk_product_bound_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_wk_product_lock(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_WK_PRODUCT_LOCK >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_wk_product_lock_t packet_in = {
        { 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36 },101
    };
    mavlink_wk_product_lock_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.locked = packet_in.locked;
        
        mav_array_memcpy(packet1.user_name, packet_in.user_name, sizeof(uint8_t)*32);
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_WK_PRODUCT_LOCK_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_WK_PRODUCT_LOCK_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_product_lock_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_wk_product_lock_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_product_lock_pack(system_id, component_id, &msg , packet1.user_name , packet1.locked );
    mavlink_msg_wk_product_lock_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_product_lock_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.user_name , packet1.locked );
    mavlink_msg_wk_product_lock_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_wk_product_lock_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_product_lock_send(MAVLINK_COMM_1 , packet1.user_name , packet1.locked );
    mavlink_msg_wk_product_lock_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_wk_product_active(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_WK_PRODUCT_ACTIVE >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_wk_product_active_t packet_in = {
        963497464,{ 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48 },{ 113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 123, 124, 125, 126, 127, 128 }
    };
    mavlink_wk_product_active_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.active_timestamps = packet_in.active_timestamps;
        
        mav_array_memcpy(packet1.user_name, packet_in.user_name, sizeof(uint8_t)*32);
        mav_array_memcpy(packet1.product_id, packet_in.product_id, sizeof(uint8_t)*16);
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_WK_PRODUCT_ACTIVE_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_WK_PRODUCT_ACTIVE_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_product_active_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_wk_product_active_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_product_active_pack(system_id, component_id, &msg , packet1.active_timestamps , packet1.user_name , packet1.product_id );
    mavlink_msg_wk_product_active_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_product_active_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.active_timestamps , packet1.user_name , packet1.product_id );
    mavlink_msg_wk_product_active_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_wk_product_active_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_product_active_send(MAVLINK_COMM_1 , packet1.active_timestamps , packet1.user_name , packet1.product_id );
    mavlink_msg_wk_product_active_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_wk_test(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_WK_TEST >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_wk_test_t packet_in = {
        5,{ 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99, 100, 101, 102, 103 }
    };
    mavlink_wk_test_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.test_flag = packet_in.test_flag;
        
        mav_array_memcpy(packet1.user_name, packet_in.user_name, sizeof(uint8_t)*32);
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_WK_TEST_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_WK_TEST_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_test_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_wk_test_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_test_pack(system_id, component_id, &msg , packet1.test_flag , packet1.user_name );
    mavlink_msg_wk_test_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_test_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.test_flag , packet1.user_name );
    mavlink_msg_wk_test_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_wk_test_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_test_send(MAVLINK_COMM_1 , packet1.test_flag , packet1.user_name );
    mavlink_msg_wk_test_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_wk_camera_cmd_camera_control(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_WK_CAMERA_CMD_CAMERA_CONTROL >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_wk_camera_cmd_camera_control_t packet_in = {
        963497464,963497672,963497880,963498088,963498296,963498504,185.0,213.0,241.0,269.0,297.0,325.0,963499960,161,228
    };
    mavlink_wk_camera_cmd_camera_control_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.cam_ctrl_value1 = packet_in.cam_ctrl_value1;
        packet1.cam_ctrl_value2 = packet_in.cam_ctrl_value2;
        packet1.cam_ctrl_value3 = packet_in.cam_ctrl_value3;
        packet1.longitude = packet_in.longitude;
        packet1.latitude = packet_in.latitude;
        packet1.altitude = packet_in.altitude;
        packet1.UavRoll = packet_in.UavRoll;
        packet1.UavPitch = packet_in.UavPitch;
        packet1.UavYaw = packet_in.UavYaw;
        packet1.GimbalRoll = packet_in.GimbalRoll;
        packet1.GimbalPitch = packet_in.GimbalPitch;
        packet1.GimbalYaw = packet_in.GimbalYaw;
        packet1.cam_ctrl_timestamps = packet_in.cam_ctrl_timestamps;
        packet1.cam_ctrl_type = packet_in.cam_ctrl_type;
        packet1.cam_ctrl_sub_type = packet_in.cam_ctrl_sub_type;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_WK_CAMERA_CMD_CAMERA_CONTROL_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_WK_CAMERA_CMD_CAMERA_CONTROL_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_camera_cmd_camera_control_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_wk_camera_cmd_camera_control_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_camera_cmd_camera_control_pack(system_id, component_id, &msg , packet1.cam_ctrl_type , packet1.cam_ctrl_sub_type , packet1.cam_ctrl_value1 , packet1.cam_ctrl_value2 , packet1.cam_ctrl_value3 , packet1.longitude , packet1.latitude , packet1.altitude , packet1.UavRoll , packet1.UavPitch , packet1.UavYaw , packet1.GimbalRoll , packet1.GimbalPitch , packet1.GimbalYaw , packet1.cam_ctrl_timestamps );
    mavlink_msg_wk_camera_cmd_camera_control_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_camera_cmd_camera_control_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.cam_ctrl_type , packet1.cam_ctrl_sub_type , packet1.cam_ctrl_value1 , packet1.cam_ctrl_value2 , packet1.cam_ctrl_value3 , packet1.longitude , packet1.latitude , packet1.altitude , packet1.UavRoll , packet1.UavPitch , packet1.UavYaw , packet1.GimbalRoll , packet1.GimbalPitch , packet1.GimbalYaw , packet1.cam_ctrl_timestamps );
    mavlink_msg_wk_camera_cmd_camera_control_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_wk_camera_cmd_camera_control_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_camera_cmd_camera_control_send(MAVLINK_COMM_1 , packet1.cam_ctrl_type , packet1.cam_ctrl_sub_type , packet1.cam_ctrl_value1 , packet1.cam_ctrl_value2 , packet1.cam_ctrl_value3 , packet1.longitude , packet1.latitude , packet1.altitude , packet1.UavRoll , packet1.UavPitch , packet1.UavYaw , packet1.GimbalRoll , packet1.GimbalPitch , packet1.GimbalYaw , packet1.cam_ctrl_timestamps );
    mavlink_msg_wk_camera_cmd_camera_control_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_wk_time_lapse_dire_param(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_WK_TIME_LAPSE_DIRE_PARAM >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_wk_time_lapse_dire_param_t packet_in = {
        17.0,45.0
    };
    mavlink_wk_time_lapse_dire_param_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.Uavspeed = packet_in.Uavspeed;
        packet1.UavYaw = packet_in.UavYaw;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_WK_TIME_LAPSE_DIRE_PARAM_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_WK_TIME_LAPSE_DIRE_PARAM_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_time_lapse_dire_param_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_wk_time_lapse_dire_param_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_time_lapse_dire_param_pack(system_id, component_id, &msg , packet1.Uavspeed , packet1.UavYaw );
    mavlink_msg_wk_time_lapse_dire_param_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_time_lapse_dire_param_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.Uavspeed , packet1.UavYaw );
    mavlink_msg_wk_time_lapse_dire_param_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_wk_time_lapse_dire_param_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_time_lapse_dire_param_send(MAVLINK_COMM_1 , packet1.Uavspeed , packet1.UavYaw );
    mavlink_msg_wk_time_lapse_dire_param_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_wk_time_lapse_dire_param_ack(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_WK_TIME_LAPSE_DIRE_PARAM_ACK >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_wk_time_lapse_dire_param_ack_t packet_in = {
        17.0,45.0
    };
    mavlink_wk_time_lapse_dire_param_ack_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.Uavspeed = packet_in.Uavspeed;
        packet1.UavYaw = packet_in.UavYaw;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_WK_TIME_LAPSE_DIRE_PARAM_ACK_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_WK_TIME_LAPSE_DIRE_PARAM_ACK_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_time_lapse_dire_param_ack_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_wk_time_lapse_dire_param_ack_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_time_lapse_dire_param_ack_pack(system_id, component_id, &msg , packet1.Uavspeed , packet1.UavYaw );
    mavlink_msg_wk_time_lapse_dire_param_ack_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_time_lapse_dire_param_ack_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.Uavspeed , packet1.UavYaw );
    mavlink_msg_wk_time_lapse_dire_param_ack_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_wk_time_lapse_dire_param_ack_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_time_lapse_dire_param_ack_send(MAVLINK_COMM_1 , packet1.Uavspeed , packet1.UavYaw );
    mavlink_msg_wk_time_lapse_dire_param_ack_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_wk_camera_cmd_focus2(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_WK_CAMERA_CMD_FOCUS2 >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_wk_camera_cmd_focus2_t packet_in = {
        5,72,139,206
    };
    mavlink_wk_camera_cmd_focus2_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.direction = packet_in.direction;
        packet1.type = packet_in.type;
        packet1.zoom_level = packet_in.zoom_level;
        packet1.focus_type = packet_in.focus_type;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_WK_CAMERA_CMD_FOCUS2_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_WK_CAMERA_CMD_FOCUS2_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_camera_cmd_focus2_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_wk_camera_cmd_focus2_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_camera_cmd_focus2_pack(system_id, component_id, &msg , packet1.direction , packet1.type , packet1.zoom_level , packet1.focus_type );
    mavlink_msg_wk_camera_cmd_focus2_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_camera_cmd_focus2_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.direction , packet1.type , packet1.zoom_level , packet1.focus_type );
    mavlink_msg_wk_camera_cmd_focus2_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_wk_camera_cmd_focus2_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_camera_cmd_focus2_send(MAVLINK_COMM_1 , packet1.direction , packet1.type , packet1.zoom_level , packet1.focus_type );
    mavlink_msg_wk_camera_cmd_focus2_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_wk_camera_mini_dual_parameter(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_WK_CAMERA_MINI_DUAL_PARAMETER >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_wk_camera_mini_dual_parameter_t packet_in = {
        17235,139,206,17,84,151
    };
    mavlink_wk_camera_mini_dual_parameter_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.alarm_value = packet_in.alarm_value;
        packet1.direction = packet_in.direction;
        packet1.colorize_type = packet_in.colorize_type;
        packet1.pip_mode = packet_in.pip_mode;
        packet1.alarm_onoff = packet_in.alarm_onoff;
        packet1.alarm_status = packet_in.alarm_status;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_WK_CAMERA_MINI_DUAL_PARAMETER_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_WK_CAMERA_MINI_DUAL_PARAMETER_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_camera_mini_dual_parameter_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_wk_camera_mini_dual_parameter_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_camera_mini_dual_parameter_pack(system_id, component_id, &msg , packet1.direction , packet1.colorize_type , packet1.pip_mode , packet1.alarm_onoff , packet1.alarm_status , packet1.alarm_value );
    mavlink_msg_wk_camera_mini_dual_parameter_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_camera_mini_dual_parameter_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.direction , packet1.colorize_type , packet1.pip_mode , packet1.alarm_onoff , packet1.alarm_status , packet1.alarm_value );
    mavlink_msg_wk_camera_mini_dual_parameter_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_wk_camera_mini_dual_parameter_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_camera_mini_dual_parameter_send(MAVLINK_COMM_1 , packet1.direction , packet1.colorize_type , packet1.pip_mode , packet1.alarm_onoff , packet1.alarm_status , packet1.alarm_value );
    mavlink_msg_wk_camera_mini_dual_parameter_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_wk_camera_mini_dual_measure_mode(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_WK_CAMERA_MINI_DUAL_MEASURE_MODE >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_wk_camera_mini_dual_measure_mode_t packet_in = {
        17235,17339,17443,17547,29,96
    };
    mavlink_wk_camera_mini_dual_measure_mode_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.measure_area_x = packet_in.measure_area_x;
        packet1.measure_area_y = packet_in.measure_area_y;
        packet1.measure_area_width = packet_in.measure_area_width;
        packet1.measure_area_height = packet_in.measure_area_height;
        packet1.direction = packet_in.direction;
        packet1.measure_mode = packet_in.measure_mode;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_WK_CAMERA_MINI_DUAL_MEASURE_MODE_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_WK_CAMERA_MINI_DUAL_MEASURE_MODE_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_camera_mini_dual_measure_mode_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_wk_camera_mini_dual_measure_mode_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_camera_mini_dual_measure_mode_pack(system_id, component_id, &msg , packet1.direction , packet1.measure_mode , packet1.measure_area_x , packet1.measure_area_y , packet1.measure_area_width , packet1.measure_area_height );
    mavlink_msg_wk_camera_mini_dual_measure_mode_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_camera_mini_dual_measure_mode_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.direction , packet1.measure_mode , packet1.measure_area_x , packet1.measure_area_y , packet1.measure_area_width , packet1.measure_area_height );
    mavlink_msg_wk_camera_mini_dual_measure_mode_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_wk_camera_mini_dual_measure_mode_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_camera_mini_dual_measure_mode_send(MAVLINK_COMM_1 , packet1.direction , packet1.measure_mode , packet1.measure_area_x , packet1.measure_area_y , packet1.measure_area_width , packet1.measure_area_height );
    mavlink_msg_wk_camera_mini_dual_measure_mode_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_wk_camera_mini_dual_state(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_WK_CAMERA_MINI_DUAL_STATE >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_wk_camera_mini_dual_state_t packet_in = {
        17235,17339,17443,17547,17651,17755,17859,17963,18067,18171,65
    };
    mavlink_wk_camera_mini_dual_state_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.max_temper_x_pos = packet_in.max_temper_x_pos;
        packet1.max_temper_y_pos = packet_in.max_temper_y_pos;
        packet1.max_temperature = packet_in.max_temperature;
        packet1.min_temper_x_pos = packet_in.min_temper_x_pos;
        packet1.min_temper_y_pos = packet_in.min_temper_y_pos;
        packet1.min_temperature = packet_in.min_temperature;
        packet1.cur_x_pos = packet_in.cur_x_pos;
        packet1.cur_y_pos = packet_in.cur_y_pos;
        packet1.cur_temperature = packet_in.cur_temperature;
        packet1.area_average_temperature = packet_in.area_average_temperature;
        packet1.measure_mode = packet_in.measure_mode;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_WK_CAMERA_MINI_DUAL_STATE_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_WK_CAMERA_MINI_DUAL_STATE_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_camera_mini_dual_state_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_wk_camera_mini_dual_state_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_camera_mini_dual_state_pack(system_id, component_id, &msg , packet1.measure_mode , packet1.max_temper_x_pos , packet1.max_temper_y_pos , packet1.max_temperature , packet1.min_temper_x_pos , packet1.min_temper_y_pos , packet1.min_temperature , packet1.cur_x_pos , packet1.cur_y_pos , packet1.cur_temperature , packet1.area_average_temperature );
    mavlink_msg_wk_camera_mini_dual_state_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_camera_mini_dual_state_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.measure_mode , packet1.max_temper_x_pos , packet1.max_temper_y_pos , packet1.max_temperature , packet1.min_temper_x_pos , packet1.min_temper_y_pos , packet1.min_temperature , packet1.cur_x_pos , packet1.cur_y_pos , packet1.cur_temperature , packet1.area_average_temperature );
    mavlink_msg_wk_camera_mini_dual_state_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_wk_camera_mini_dual_state_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_camera_mini_dual_state_send(MAVLINK_COMM_1 , packet1.measure_mode , packet1.max_temper_x_pos , packet1.max_temper_y_pos , packet1.max_temperature , packet1.min_temper_x_pos , packet1.min_temper_y_pos , packet1.min_temperature , packet1.cur_x_pos , packet1.cur_y_pos , packet1.cur_temperature , packet1.area_average_temperature );
    mavlink_msg_wk_camera_mini_dual_state_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_wk_scout_state(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_WK_SCOUT_STATE >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_wk_scout_state_t packet_in = {
        963497464,963497672,963497880,41
    };
    mavlink_wk_scout_state_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.longitude = packet_in.longitude;
        packet1.latitude = packet_in.latitude;
        packet1.altitude = packet_in.altitude;
        packet1.scout_state = packet_in.scout_state;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_WK_SCOUT_STATE_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_WK_SCOUT_STATE_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_scout_state_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_wk_scout_state_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_scout_state_pack(system_id, component_id, &msg , packet1.scout_state , packet1.longitude , packet1.latitude , packet1.altitude );
    mavlink_msg_wk_scout_state_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_scout_state_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.scout_state , packet1.longitude , packet1.latitude , packet1.altitude );
    mavlink_msg_wk_scout_state_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_wk_scout_state_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_scout_state_send(MAVLINK_COMM_1 , packet1.scout_state , packet1.longitude , packet1.latitude , packet1.altitude );
    mavlink_msg_wk_scout_state_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_wk_rc_parameter(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_WK_RC_PARAMETER >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_wk_rc_parameter_t packet_in = {
        5,{ 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87 }
    };
    mavlink_wk_rc_parameter_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.rc_control_mode = packet_in.rc_control_mode;
        
        mav_array_memcpy(packet1.reserved, packet_in.reserved, sizeof(uint8_t)*16);
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_WK_RC_PARAMETER_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_WK_RC_PARAMETER_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_rc_parameter_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_wk_rc_parameter_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_rc_parameter_pack(system_id, component_id, &msg , packet1.rc_control_mode , packet1.reserved );
    mavlink_msg_wk_rc_parameter_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_rc_parameter_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.rc_control_mode , packet1.reserved );
    mavlink_msg_wk_rc_parameter_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_wk_rc_parameter_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_rc_parameter_send(MAVLINK_COMM_1 , packet1.rc_control_mode , packet1.reserved );
    mavlink_msg_wk_rc_parameter_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_wk_engine_control_state(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_WK_ENGINE_CONTROL_STATE >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_wk_engine_control_state_t packet_in = {
        17.0,45.0,73.0,101.0,129.0
    };
    mavlink_wk_engine_control_state_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.state = packet_in.state;
        packet1.speed = packet_in.speed;
        packet1.acce = packet_in.acce;
        packet1.reserved1 = packet_in.reserved1;
        packet1.reserved2 = packet_in.reserved2;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_WK_ENGINE_CONTROL_STATE_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_WK_ENGINE_CONTROL_STATE_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_engine_control_state_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_wk_engine_control_state_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_engine_control_state_pack(system_id, component_id, &msg , packet1.state , packet1.speed , packet1.acce , packet1.reserved1 , packet1.reserved2 );
    mavlink_msg_wk_engine_control_state_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_engine_control_state_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.state , packet1.speed , packet1.acce , packet1.reserved1 , packet1.reserved2 );
    mavlink_msg_wk_engine_control_state_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_wk_engine_control_state_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_engine_control_state_send(MAVLINK_COMM_1 , packet1.state , packet1.speed , packet1.acce , packet1.reserved1 , packet1.reserved2 );
    mavlink_msg_wk_engine_control_state_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_wk_camera_cmd_utc_time_sync1(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_WK_CAMERA_CMD_UTC_TIME_SYNC1 >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_wk_camera_cmd_utc_time_sync1_t packet_in = {
        17235,139,206,17,84,151,'H'
    };
    mavlink_wk_camera_cmd_utc_time_sync1_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.year = packet_in.year;
        packet1.month = packet_in.month;
        packet1.day = packet_in.day;
        packet1.hour = packet_in.hour;
        packet1.min = packet_in.min;
        packet1.sec = packet_in.sec;
        packet1.time_zone = packet_in.time_zone;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_WK_CAMERA_CMD_UTC_TIME_SYNC1_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_WK_CAMERA_CMD_UTC_TIME_SYNC1_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_camera_cmd_utc_time_sync1_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_wk_camera_cmd_utc_time_sync1_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_camera_cmd_utc_time_sync1_pack(system_id, component_id, &msg , packet1.year , packet1.month , packet1.day , packet1.hour , packet1.min , packet1.sec , packet1.time_zone );
    mavlink_msg_wk_camera_cmd_utc_time_sync1_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_camera_cmd_utc_time_sync1_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.year , packet1.month , packet1.day , packet1.hour , packet1.min , packet1.sec , packet1.time_zone );
    mavlink_msg_wk_camera_cmd_utc_time_sync1_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_wk_camera_cmd_utc_time_sync1_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_camera_cmd_utc_time_sync1_send(MAVLINK_COMM_1 , packet1.year , packet1.month , packet1.day , packet1.hour , packet1.min , packet1.sec , packet1.time_zone );
    mavlink_msg_wk_camera_cmd_utc_time_sync1_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_wk_camera_focusing(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_WK_CAMERA_FOCUSING >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_wk_camera_focusing_t packet_in = {
        963497464,45.0,73.0,41,108,175
    };
    mavlink_wk_camera_focusing_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.timestamp = packet_in.timestamp;
        packet1.focusing_x = packet_in.focusing_x;
        packet1.focusing_y = packet_in.focusing_y;
        packet1.direction = packet_in.direction;
        packet1.focusing_type = packet_in.focusing_type;
        packet1.tropism = packet_in.tropism;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_WK_CAMERA_FOCUSING_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_WK_CAMERA_FOCUSING_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_camera_focusing_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_wk_camera_focusing_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_camera_focusing_pack(system_id, component_id, &msg , packet1.direction , packet1.timestamp , packet1.focusing_type , packet1.tropism , packet1.focusing_x , packet1.focusing_y );
    mavlink_msg_wk_camera_focusing_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_camera_focusing_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.direction , packet1.timestamp , packet1.focusing_type , packet1.tropism , packet1.focusing_x , packet1.focusing_y );
    mavlink_msg_wk_camera_focusing_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_wk_camera_focusing_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_camera_focusing_send(MAVLINK_COMM_1 , packet1.direction , packet1.timestamp , packet1.focusing_type , packet1.tropism , packet1.focusing_x , packet1.focusing_y );
    mavlink_msg_wk_camera_focusing_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_wk_camera_laser_ranging(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_WK_CAMERA_LASER_RANGING >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_wk_camera_laser_ranging_t packet_in = {
        17.0,45.0,29,{ 96, 97, 98, 99, 100, 101, 102, 103 }
    };
    mavlink_wk_camera_laser_ranging_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.x = packet_in.x;
        packet1.y = packet_in.y;
        packet1.direction = packet_in.direction;
        
        mav_array_memcpy(packet1.reserved, packet_in.reserved, sizeof(uint8_t)*8);
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_WK_CAMERA_LASER_RANGING_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_WK_CAMERA_LASER_RANGING_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_camera_laser_ranging_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_wk_camera_laser_ranging_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_camera_laser_ranging_pack(system_id, component_id, &msg , packet1.direction , packet1.x , packet1.y , packet1.reserved );
    mavlink_msg_wk_camera_laser_ranging_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_camera_laser_ranging_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.direction , packet1.x , packet1.y , packet1.reserved );
    mavlink_msg_wk_camera_laser_ranging_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_wk_camera_laser_ranging_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_camera_laser_ranging_send(MAVLINK_COMM_1 , packet1.direction , packet1.x , packet1.y , packet1.reserved );
    mavlink_msg_wk_camera_laser_ranging_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_wk_camera_laser_ranging_state(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_WK_CAMERA_LASER_RANGING_STATE >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_wk_camera_laser_ranging_state_t packet_in = {
        963497464,963497672,73.0,101.0,53
    };
    mavlink_wk_camera_laser_ranging_state_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.latitude = packet_in.latitude;
        packet1.longitude = packet_in.longitude;
        packet1.altitude = packet_in.altitude;
        packet1.distance = packet_in.distance;
        packet1.state = packet_in.state;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_WK_CAMERA_LASER_RANGING_STATE_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_WK_CAMERA_LASER_RANGING_STATE_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_camera_laser_ranging_state_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_wk_camera_laser_ranging_state_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_camera_laser_ranging_state_pack(system_id, component_id, &msg , packet1.state , packet1.latitude , packet1.longitude , packet1.altitude , packet1.distance );
    mavlink_msg_wk_camera_laser_ranging_state_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_camera_laser_ranging_state_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.state , packet1.latitude , packet1.longitude , packet1.altitude , packet1.distance );
    mavlink_msg_wk_camera_laser_ranging_state_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_wk_camera_laser_ranging_state_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_camera_laser_ranging_state_send(MAVLINK_COMM_1 , packet1.state , packet1.latitude , packet1.longitude , packet1.altitude , packet1.distance );
    mavlink_msg_wk_camera_laser_ranging_state_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_wk_set_connect_param(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_WK_SET_CONNECT_PARAM >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_wk_set_connect_param_t packet_in = {
        17235,17339,17443,17547,29,96,{ 163, 164, 165, 166, 167, 168, 169, 170, 171, 172, 173, 174, 175, 176, 177, 178, 179, 180, 181, 182, 183, 184, 185, 186, 187, 188, 189, 190, 191, 192, 193, 194, 195, 196, 197, 198, 199, 200, 201, 202 },{ 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66 },{ 147, 148, 149, 150, 151, 152, 153, 154, 155, 156, 157, 158, 159, 160, 161, 162, 163, 164, 165, 166, 167, 168, 169, 170, 171, 172, 173, 174, 175, 176, 177, 178, 179, 180, 181, 182, 183, 184, 185, 186 },{ 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50 },{ 131, 132, 133, 134, 135, 136, 137, 138, 139, 140, 141, 142, 143, 144, 145, 146, 147, 148, 149, 150, 151, 152, 153, 154, 155, 156, 157, 158, 159, 160, 161, 162 },{ 227, 228, 229, 230, 231, 232, 233, 234, 235, 236, 237, 238, 239, 240, 241, 242 },{ 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34 }
    };
    mavlink_wk_set_connect_param_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.cmd_port = packet_in.cmd_port;
        packet1.video1_port = packet_in.video1_port;
        packet1.video2_port = packet_in.video2_port;
        packet1.video3_port = packet_in.video3_port;
        packet1.direction = packet_in.direction;
        packet1.param_type = packet_in.param_type;
        
        mav_array_memcpy(packet1.cmd_url, packet_in.cmd_url, sizeof(uint8_t)*40);
        mav_array_memcpy(packet1.video1_url, packet_in.video1_url, sizeof(uint8_t)*40);
        mav_array_memcpy(packet1.video2_url, packet_in.video2_url, sizeof(uint8_t)*40);
        mav_array_memcpy(packet1.video3_url, packet_in.video3_url, sizeof(uint8_t)*40);
        mav_array_memcpy(packet1.id, packet_in.id, sizeof(uint8_t)*32);
        mav_array_memcpy(packet1.user, packet_in.user, sizeof(uint8_t)*16);
        mav_array_memcpy(packet1.password, packet_in.password, sizeof(uint8_t)*16);
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_WK_SET_CONNECT_PARAM_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_WK_SET_CONNECT_PARAM_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_set_connect_param_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_wk_set_connect_param_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_set_connect_param_pack(system_id, component_id, &msg , packet1.direction , packet1.param_type , packet1.cmd_url , packet1.cmd_port , packet1.video1_url , packet1.video1_port , packet1.video2_url , packet1.video2_port , packet1.video3_url , packet1.video3_port , packet1.id , packet1.user , packet1.password );
    mavlink_msg_wk_set_connect_param_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_set_connect_param_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.direction , packet1.param_type , packet1.cmd_url , packet1.cmd_port , packet1.video1_url , packet1.video1_port , packet1.video2_url , packet1.video2_port , packet1.video3_url , packet1.video3_port , packet1.id , packet1.user , packet1.password );
    mavlink_msg_wk_set_connect_param_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_wk_set_connect_param_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_set_connect_param_send(MAVLINK_COMM_1 , packet1.direction , packet1.param_type , packet1.cmd_url , packet1.cmd_port , packet1.video1_url , packet1.video1_port , packet1.video2_url , packet1.video2_port , packet1.video3_url , packet1.video3_port , packet1.id , packet1.user , packet1.password );
    mavlink_msg_wk_set_connect_param_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_wk_set_ai_tracking_cmd(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_WK_SET_AI_TRACKING_CMD >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_wk_set_ai_tracking_cmd_t packet_in = {
        17.0,45.0,73.0,101.0,18067,18171,65,132,{ 199, 200, 201, 202, 203, 204, 205, 206 }
    };
    mavlink_wk_set_ai_tracking_cmd_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.x = packet_in.x;
        packet1.y = packet_in.y;
        packet1.width = packet_in.width;
        packet1.height = packet_in.height;
        packet1.resolutionWidth = packet_in.resolutionWidth;
        packet1.resolutionHeight = packet_in.resolutionHeight;
        packet1.isTracking = packet_in.isTracking;
        packet1.mode = packet_in.mode;
        
        mav_array_memcpy(packet1.reserved, packet_in.reserved, sizeof(uint8_t)*8);
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_WK_SET_AI_TRACKING_CMD_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_WK_SET_AI_TRACKING_CMD_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_set_ai_tracking_cmd_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_wk_set_ai_tracking_cmd_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_set_ai_tracking_cmd_pack(system_id, component_id, &msg , packet1.isTracking , packet1.x , packet1.y , packet1.width , packet1.height , packet1.resolutionWidth , packet1.resolutionHeight , packet1.mode , packet1.reserved );
    mavlink_msg_wk_set_ai_tracking_cmd_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_set_ai_tracking_cmd_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.isTracking , packet1.x , packet1.y , packet1.width , packet1.height , packet1.resolutionWidth , packet1.resolutionHeight , packet1.mode , packet1.reserved );
    mavlink_msg_wk_set_ai_tracking_cmd_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_wk_set_ai_tracking_cmd_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_set_ai_tracking_cmd_send(MAVLINK_COMM_1 , packet1.isTracking , packet1.x , packet1.y , packet1.width , packet1.height , packet1.resolutionWidth , packet1.resolutionHeight , packet1.mode , packet1.reserved );
    mavlink_msg_wk_set_ai_tracking_cmd_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_wk_set_vr_param(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_WK_SET_VR_PARAM >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_wk_set_vr_param_t packet_in = {
        17.0,45.0,73.0,101.0,129.0,157.0
    };
    mavlink_wk_set_vr_param_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.gyroscopeX = packet_in.gyroscopeX;
        packet1.gyroscopeY = packet_in.gyroscopeY;
        packet1.gyroscopeZ = packet_in.gyroscopeZ;
        packet1.accelerationX = packet_in.accelerationX;
        packet1.accelerationY = packet_in.accelerationY;
        packet1.accelerationZ = packet_in.accelerationZ;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_WK_SET_VR_PARAM_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_WK_SET_VR_PARAM_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_set_vr_param_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_wk_set_vr_param_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_set_vr_param_pack(system_id, component_id, &msg , packet1.gyroscopeX , packet1.gyroscopeY , packet1.gyroscopeZ , packet1.accelerationX , packet1.accelerationY , packet1.accelerationZ );
    mavlink_msg_wk_set_vr_param_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_set_vr_param_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.gyroscopeX , packet1.gyroscopeY , packet1.gyroscopeZ , packet1.accelerationX , packet1.accelerationY , packet1.accelerationZ );
    mavlink_msg_wk_set_vr_param_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_wk_set_vr_param_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_set_vr_param_send(MAVLINK_COMM_1 , packet1.gyroscopeX , packet1.gyroscopeY , packet1.gyroscopeZ , packet1.accelerationX , packet1.accelerationY , packet1.accelerationZ );
    mavlink_msg_wk_set_vr_param_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_wk_mini_4g_authentication(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_WK_MINI_4G_AUTHENTICATION >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_wk_mini_4g_authentication_t packet_in = {
        5,72,{ 139, 140, 141, 142, 143, 144, 145, 146, 147, 148, 149, 150, 151, 152, 153, 154, 155, 156, 157, 158, 159, 160, 161, 162, 163, 164, 165, 166, 167, 168, 169, 170 },{ 235, 236, 237, 238, 239, 240, 241, 242 },{ 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34 },{ 99, 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 123, 124, 125, 126, 127, 128, 129, 130 },195,{ 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99, 100, 101, 102, 103, 104, 105 }
    };
    mavlink_wk_mini_4g_authentication_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.type = packet_in.type;
        packet1.id_length = packet_in.id_length;
        packet1.url_length = packet_in.url_length;
        
        mav_array_memcpy(packet1.sn_id, packet_in.sn_id, sizeof(uint8_t)*32);
        mav_array_memcpy(packet1.password, packet_in.password, sizeof(uint8_t)*8);
        mav_array_memcpy(packet1.user_id, packet_in.user_id, sizeof(uint8_t)*32);
        mav_array_memcpy(packet1.md5_chk, packet_in.md5_chk, sizeof(uint8_t)*32);
        mav_array_memcpy(packet1.video_url, packet_in.video_url, sizeof(uint8_t)*100);
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_WK_MINI_4G_AUTHENTICATION_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_WK_MINI_4G_AUTHENTICATION_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_mini_4g_authentication_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_wk_mini_4g_authentication_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_mini_4g_authentication_pack(system_id, component_id, &msg , packet1.type , packet1.id_length , packet1.sn_id , packet1.password , packet1.user_id , packet1.md5_chk , packet1.url_length , packet1.video_url );
    mavlink_msg_wk_mini_4g_authentication_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_mini_4g_authentication_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.type , packet1.id_length , packet1.sn_id , packet1.password , packet1.user_id , packet1.md5_chk , packet1.url_length , packet1.video_url );
    mavlink_msg_wk_mini_4g_authentication_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_wk_mini_4g_authentication_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_mini_4g_authentication_send(MAVLINK_COMM_1 , packet1.type , packet1.id_length , packet1.sn_id , packet1.password , packet1.user_id , packet1.md5_chk , packet1.url_length , packet1.video_url );
    mavlink_msg_wk_mini_4g_authentication_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_wk_log_flight_state(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_WK_LOG_FLIGHT_STATE >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_wk_log_flight_state_t packet_in = {
        93372036854775807ULL,73.0,101.0,129.0,157.0,185.0,213.0,241.0,269.0,297.0,325.0,353.0,381.0,{ 409.0, 410.0, 411.0 },{ 493.0, 494.0, 495.0 },{ 577.0, 578.0, 579.0 },{ 661.0, 662.0, 663.0 },{ 745.0, 746.0, 747.0 },{ 829.0, 830.0, 831.0 },23891,11,78,145,212
    };
    mavlink_wk_log_flight_state_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.timestamp = packet_in.timestamp;
        packet1.roll_rate = packet_in.roll_rate;
        packet1.pitch_rate = packet_in.pitch_rate;
        packet1.yaw_rate = packet_in.yaw_rate;
        packet1.roll_rate_sp = packet_in.roll_rate_sp;
        packet1.pitch_rate_sp = packet_in.pitch_rate_sp;
        packet1.yaw_rate_sp = packet_in.yaw_rate_sp;
        packet1.roll = packet_in.roll;
        packet1.pitch = packet_in.pitch;
        packet1.yaw = packet_in.yaw;
        packet1.roll_sp = packet_in.roll_sp;
        packet1.pitch_sp = packet_in.pitch_sp;
        packet1.yaw_sp = packet_in.yaw_sp;
        packet1.time_cnt = packet_in.time_cnt;
        packet1.flag_arm = packet_in.flag_arm;
        packet1.flight_mode = packet_in.flight_mode;
        packet1.failsafe = packet_in.failsafe;
        packet1.inav_health = packet_in.inav_health;
        
        mav_array_memcpy(packet1.accel_ef, packet_in.accel_ef, sizeof(float)*3);
        mav_array_memcpy(packet1.velocity, packet_in.velocity, sizeof(float)*3);
        mav_array_memcpy(packet1.velocity_sp, packet_in.velocity_sp, sizeof(float)*3);
        mav_array_memcpy(packet1.position, packet_in.position, sizeof(float)*3);
        mav_array_memcpy(packet1.position_sp, packet_in.position_sp, sizeof(float)*3);
        mav_array_memcpy(packet1.position_obver, packet_in.position_obver, sizeof(float)*3);
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_WK_LOG_FLIGHT_STATE_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_WK_LOG_FLIGHT_STATE_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_log_flight_state_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_wk_log_flight_state_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_log_flight_state_pack(system_id, component_id, &msg , packet1.timestamp , packet1.time_cnt , packet1.flag_arm , packet1.flight_mode , packet1.failsafe , packet1.inav_health , packet1.roll_rate , packet1.pitch_rate , packet1.yaw_rate , packet1.roll_rate_sp , packet1.pitch_rate_sp , packet1.yaw_rate_sp , packet1.roll , packet1.pitch , packet1.yaw , packet1.roll_sp , packet1.pitch_sp , packet1.yaw_sp , packet1.accel_ef , packet1.velocity , packet1.velocity_sp , packet1.position , packet1.position_sp , packet1.position_obver );
    mavlink_msg_wk_log_flight_state_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_log_flight_state_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.timestamp , packet1.time_cnt , packet1.flag_arm , packet1.flight_mode , packet1.failsafe , packet1.inav_health , packet1.roll_rate , packet1.pitch_rate , packet1.yaw_rate , packet1.roll_rate_sp , packet1.pitch_rate_sp , packet1.yaw_rate_sp , packet1.roll , packet1.pitch , packet1.yaw , packet1.roll_sp , packet1.pitch_sp , packet1.yaw_sp , packet1.accel_ef , packet1.velocity , packet1.velocity_sp , packet1.position , packet1.position_sp , packet1.position_obver );
    mavlink_msg_wk_log_flight_state_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_wk_log_flight_state_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_log_flight_state_send(MAVLINK_COMM_1 , packet1.timestamp , packet1.time_cnt , packet1.flag_arm , packet1.flight_mode , packet1.failsafe , packet1.inav_health , packet1.roll_rate , packet1.pitch_rate , packet1.yaw_rate , packet1.roll_rate_sp , packet1.pitch_rate_sp , packet1.yaw_rate_sp , packet1.roll , packet1.pitch , packet1.yaw , packet1.roll_sp , packet1.pitch_sp , packet1.yaw_sp , packet1.accel_ef , packet1.velocity , packet1.velocity_sp , packet1.position , packet1.position_sp , packet1.position_obver );
    mavlink_msg_wk_log_flight_state_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_wk_log_gnss(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_WK_LOG_GNSS >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_wk_log_gnss_t packet_in = {
        93372036854775807ULL,73.0,963498088,963498296,157.0,185.0,213.0,241.0,269.0,297.0,325.0,353.0,381.0,409.0,437.0,465.0,209,20,87,154
    };
    mavlink_wk_log_gnss_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.timestamp = packet_in.timestamp;
        packet1.height = packet_in.height;
        packet1.latitude = packet_in.latitude;
        packet1.longitude = packet_in.longitude;
        packet1.timegap = packet_in.timegap;
        packet1.horizontal_acc = packet_in.horizontal_acc;
        packet1.vertical_acc = packet_in.vertical_acc;
        packet1.velocity_acc = packet_in.velocity_acc;
        packet1.gps_pos_dop = packet_in.gps_pos_dop;
        packet1.ground_speed = packet_in.ground_speed;
        packet1.alt_vel = packet_in.alt_vel;
        packet1.vel_e = packet_in.vel_e;
        packet1.vel_n = packet_in.vel_n;
        packet1.vel_d = packet_in.vel_d;
        packet1.rtk_yaw = packet_in.rtk_yaw;
        packet1.rtk_yaw_health = packet_in.rtk_yaw_health;
        packet1.gnss_detected = packet_in.gnss_detected;
        packet1.numsv = packet_in.numsv;
        packet1.fixtype = packet_in.fixtype;
        packet1.update_flag = packet_in.update_flag;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_WK_LOG_GNSS_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_WK_LOG_GNSS_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_log_gnss_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_wk_log_gnss_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_log_gnss_pack(system_id, component_id, &msg , packet1.timestamp , packet1.gnss_detected , packet1.numsv , packet1.fixtype , packet1.height , packet1.latitude , packet1.longitude , packet1.update_flag , packet1.timegap , packet1.horizontal_acc , packet1.vertical_acc , packet1.velocity_acc , packet1.gps_pos_dop , packet1.ground_speed , packet1.alt_vel , packet1.vel_e , packet1.vel_n , packet1.vel_d , packet1.rtk_yaw , packet1.rtk_yaw_health );
    mavlink_msg_wk_log_gnss_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_log_gnss_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.timestamp , packet1.gnss_detected , packet1.numsv , packet1.fixtype , packet1.height , packet1.latitude , packet1.longitude , packet1.update_flag , packet1.timegap , packet1.horizontal_acc , packet1.vertical_acc , packet1.velocity_acc , packet1.gps_pos_dop , packet1.ground_speed , packet1.alt_vel , packet1.vel_e , packet1.vel_n , packet1.vel_d , packet1.rtk_yaw , packet1.rtk_yaw_health );
    mavlink_msg_wk_log_gnss_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_wk_log_gnss_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_log_gnss_send(MAVLINK_COMM_1 , packet1.timestamp , packet1.gnss_detected , packet1.numsv , packet1.fixtype , packet1.height , packet1.latitude , packet1.longitude , packet1.update_flag , packet1.timegap , packet1.horizontal_acc , packet1.vertical_acc , packet1.velocity_acc , packet1.gps_pos_dop , packet1.ground_speed , packet1.alt_vel , packet1.vel_e , packet1.vel_n , packet1.vel_d , packet1.rtk_yaw , packet1.rtk_yaw_health );
    mavlink_msg_wk_log_gnss_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_wk_log_gps_raw(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_WK_LOG_GPS_RAW >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_wk_log_gps_raw_t packet_in = {
        93372036854775807ULL,963497880,963498088,963498296,963498504,963498712,963498920,18899,19003,19107,19211,19315,3,70
    };
    mavlink_wk_log_gps_raw_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.timestamp = packet_in.timestamp;
        packet1.latitude = packet_in.latitude;
        packet1.longitude = packet_in.longitude;
        packet1.altitude = packet_in.altitude;
        packet1.vel_n = packet_in.vel_n;
        packet1.vel_e = packet_in.vel_e;
        packet1.vel_d = packet_in.vel_d;
        packet1.heading = packet_in.heading;
        packet1.hAcc = packet_in.hAcc;
        packet1.vAcc = packet_in.vAcc;
        packet1.sAcc = packet_in.sAcc;
        packet1.cAcc = packet_in.cAcc;
        packet1.fix_type = packet_in.fix_type;
        packet1.numSv = packet_in.numSv;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_WK_LOG_GPS_RAW_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_WK_LOG_GPS_RAW_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_log_gps_raw_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_wk_log_gps_raw_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_log_gps_raw_pack(system_id, component_id, &msg , packet1.timestamp , packet1.latitude , packet1.longitude , packet1.altitude , packet1.vel_n , packet1.vel_e , packet1.vel_d , packet1.heading , packet1.hAcc , packet1.vAcc , packet1.sAcc , packet1.cAcc , packet1.fix_type , packet1.numSv );
    mavlink_msg_wk_log_gps_raw_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_log_gps_raw_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.timestamp , packet1.latitude , packet1.longitude , packet1.altitude , packet1.vel_n , packet1.vel_e , packet1.vel_d , packet1.heading , packet1.hAcc , packet1.vAcc , packet1.sAcc , packet1.cAcc , packet1.fix_type , packet1.numSv );
    mavlink_msg_wk_log_gps_raw_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_wk_log_gps_raw_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_log_gps_raw_send(MAVLINK_COMM_1 , packet1.timestamp , packet1.latitude , packet1.longitude , packet1.altitude , packet1.vel_n , packet1.vel_e , packet1.vel_d , packet1.heading , packet1.hAcc , packet1.vAcc , packet1.sAcc , packet1.cAcc , packet1.fix_type , packet1.numSv );
    mavlink_msg_wk_log_gps_raw_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_wk_log_rtk_raw(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_WK_LOG_RTK_RAW >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_wk_log_rtk_raw_t packet_in = {
        93372036854775807ULL,179.0,235.0,963498712,213.0,241.0,269.0,297.0,325.0,353.0,963500168,409.0,437.0,465.0,493.0,521.0,21187,21291,21395,123,190
    };
    mavlink_wk_log_rtk_raw_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.timestamp = packet_in.timestamp;
        packet1.lat = packet_in.lat;
        packet1.lng = packet_in.lng;
        packet1.time_week_ms = packet_in.time_week_ms;
        packet1.alt = packet_in.alt;
        packet1.ground_speed = packet_in.ground_speed;
        packet1.ground_course = packet_in.ground_course;
        packet1.speed_accuracy = packet_in.speed_accuracy;
        packet1.horizontal_accuracy = packet_in.horizontal_accuracy;
        packet1.vertical_accuracy = packet_in.vertical_accuracy;
        packet1.diff_age = packet_in.diff_age;
        packet1.heading = packet_in.heading;
        packet1.hdg_sd = packet_in.hdg_sd;
        packet1.velocity_x = packet_in.velocity_x;
        packet1.velocity_y = packet_in.velocity_y;
        packet1.velocity_z = packet_in.velocity_z;
        packet1.time_week = packet_in.time_week;
        packet1.hdop = packet_in.hdop;
        packet1.vdop = packet_in.vdop;
        packet1.status = packet_in.status;
        packet1.num_sats = packet_in.num_sats;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_WK_LOG_RTK_RAW_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_WK_LOG_RTK_RAW_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_log_rtk_raw_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_wk_log_rtk_raw_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_log_rtk_raw_pack(system_id, component_id, &msg , packet1.timestamp , packet1.status , packet1.num_sats , packet1.time_week , packet1.time_week_ms , packet1.lat , packet1.lng , packet1.alt , packet1.ground_speed , packet1.ground_course , packet1.hdop , packet1.vdop , packet1.speed_accuracy , packet1.horizontal_accuracy , packet1.vertical_accuracy , packet1.diff_age , packet1.heading , packet1.hdg_sd , packet1.velocity_x , packet1.velocity_y , packet1.velocity_z );
    mavlink_msg_wk_log_rtk_raw_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_log_rtk_raw_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.timestamp , packet1.status , packet1.num_sats , packet1.time_week , packet1.time_week_ms , packet1.lat , packet1.lng , packet1.alt , packet1.ground_speed , packet1.ground_course , packet1.hdop , packet1.vdop , packet1.speed_accuracy , packet1.horizontal_accuracy , packet1.vertical_accuracy , packet1.diff_age , packet1.heading , packet1.hdg_sd , packet1.velocity_x , packet1.velocity_y , packet1.velocity_z );
    mavlink_msg_wk_log_rtk_raw_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_wk_log_rtk_raw_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_log_rtk_raw_send(MAVLINK_COMM_1 , packet1.timestamp , packet1.status , packet1.num_sats , packet1.time_week , packet1.time_week_ms , packet1.lat , packet1.lng , packet1.alt , packet1.ground_speed , packet1.ground_course , packet1.hdop , packet1.vdop , packet1.speed_accuracy , packet1.horizontal_accuracy , packet1.vertical_accuracy , packet1.diff_age , packet1.heading , packet1.hdg_sd , packet1.velocity_x , packet1.velocity_y , packet1.velocity_z );
    mavlink_msg_wk_log_rtk_raw_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_wk_log_beacon(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_WK_LOG_BEACON >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_wk_log_beacon_t packet_in = {
        93372036854775807ULL,963497880,963498088,963498296,157.0,185.0,213.0,241.0,269.0,125,192
    };
    mavlink_wk_log_beacon_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.timestamp = packet_in.timestamp;
        packet1.latitude = packet_in.latitude;
        packet1.longitude = packet_in.longitude;
        packet1.alt = packet_in.alt;
        packet1.velx = packet_in.velx;
        packet1.vely = packet_in.vely;
        packet1.velz = packet_in.velz;
        packet1.yaw = packet_in.yaw;
        packet1.distance = packet_in.distance;
        packet1.numsv = packet_in.numsv;
        packet1.fixtype = packet_in.fixtype;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_WK_LOG_BEACON_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_WK_LOG_BEACON_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_log_beacon_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_wk_log_beacon_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_log_beacon_pack(system_id, component_id, &msg , packet1.timestamp , packet1.numsv , packet1.fixtype , packet1.latitude , packet1.longitude , packet1.alt , packet1.velx , packet1.vely , packet1.velz , packet1.yaw , packet1.distance );
    mavlink_msg_wk_log_beacon_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_log_beacon_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.timestamp , packet1.numsv , packet1.fixtype , packet1.latitude , packet1.longitude , packet1.alt , packet1.velx , packet1.vely , packet1.velz , packet1.yaw , packet1.distance );
    mavlink_msg_wk_log_beacon_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_wk_log_beacon_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_log_beacon_send(MAVLINK_COMM_1 , packet1.timestamp , packet1.numsv , packet1.fixtype , packet1.latitude , packet1.longitude , packet1.alt , packet1.velx , packet1.vely , packet1.velz , packet1.yaw , packet1.distance );
    mavlink_msg_wk_log_beacon_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_wk_log_mission(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_WK_LOG_MISSION >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_wk_log_mission_t packet_in = {
        93372036854775807ULL,963497880,963498088,963498296,963498504
    };
    mavlink_wk_log_mission_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.timestamp = packet_in.timestamp;
        packet1.seq = packet_in.seq;
        packet1.latitude = packet_in.latitude;
        packet1.longitude = packet_in.longitude;
        packet1.altitude = packet_in.altitude;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_WK_LOG_MISSION_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_WK_LOG_MISSION_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_log_mission_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_wk_log_mission_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_log_mission_pack(system_id, component_id, &msg , packet1.timestamp , packet1.seq , packet1.latitude , packet1.longitude , packet1.altitude );
    mavlink_msg_wk_log_mission_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_log_mission_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.timestamp , packet1.seq , packet1.latitude , packet1.longitude , packet1.altitude );
    mavlink_msg_wk_log_mission_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_wk_log_mission_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_log_mission_send(MAVLINK_COMM_1 , packet1.timestamp , packet1.seq , packet1.latitude , packet1.longitude , packet1.altitude );
    mavlink_msg_wk_log_mission_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_wk_log_motors(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_WK_LOG_MOTORS >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_wk_log_motors_t packet_in = {
        93372036854775807ULL,17651,17755,17859,17963,18067,18171,18275,18379,18483,18587,18691,18795
    };
    mavlink_wk_log_motors_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.timestamp = packet_in.timestamp;
        packet1.MOT01 = packet_in.MOT01;
        packet1.MOT02 = packet_in.MOT02;
        packet1.MOT03 = packet_in.MOT03;
        packet1.MOT04 = packet_in.MOT04;
        packet1.MOT05 = packet_in.MOT05;
        packet1.MOT06 = packet_in.MOT06;
        packet1.MOT07 = packet_in.MOT07;
        packet1.MOT08 = packet_in.MOT08;
        packet1.MOT09 = packet_in.MOT09;
        packet1.MOT10 = packet_in.MOT10;
        packet1.MOT11 = packet_in.MOT11;
        packet1.MOT12 = packet_in.MOT12;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_WK_LOG_MOTORS_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_WK_LOG_MOTORS_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_log_motors_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_wk_log_motors_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_log_motors_pack(system_id, component_id, &msg , packet1.timestamp , packet1.MOT01 , packet1.MOT02 , packet1.MOT03 , packet1.MOT04 , packet1.MOT05 , packet1.MOT06 , packet1.MOT07 , packet1.MOT08 , packet1.MOT09 , packet1.MOT10 , packet1.MOT11 , packet1.MOT12 );
    mavlink_msg_wk_log_motors_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_log_motors_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.timestamp , packet1.MOT01 , packet1.MOT02 , packet1.MOT03 , packet1.MOT04 , packet1.MOT05 , packet1.MOT06 , packet1.MOT07 , packet1.MOT08 , packet1.MOT09 , packet1.MOT10 , packet1.MOT11 , packet1.MOT12 );
    mavlink_msg_wk_log_motors_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_wk_log_motors_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_log_motors_send(MAVLINK_COMM_1 , packet1.timestamp , packet1.MOT01 , packet1.MOT02 , packet1.MOT03 , packet1.MOT04 , packet1.MOT05 , packet1.MOT06 , packet1.MOT07 , packet1.MOT08 , packet1.MOT09 , packet1.MOT10 , packet1.MOT11 , packet1.MOT12 );
    mavlink_msg_wk_log_motors_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_wk_log_rcin(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_WK_LOG_RCIN >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_wk_log_rcin_t packet_in = {
        93372036854775807ULL,963497880,17859,17963,18067,18171,18275,18379,18483,18587,18691,18795,18899,19003,19107,19211,19315,19419
    };
    mavlink_wk_log_rcin_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.timestamp = packet_in.timestamp;
        packet1.update_ms = packet_in.update_ms;
        packet1.ch01 = packet_in.ch01;
        packet1.ch02 = packet_in.ch02;
        packet1.ch03 = packet_in.ch03;
        packet1.ch04 = packet_in.ch04;
        packet1.ch05 = packet_in.ch05;
        packet1.ch06 = packet_in.ch06;
        packet1.ch07 = packet_in.ch07;
        packet1.ch08 = packet_in.ch08;
        packet1.ch09 = packet_in.ch09;
        packet1.ch10 = packet_in.ch10;
        packet1.ch11 = packet_in.ch11;
        packet1.ch12 = packet_in.ch12;
        packet1.ch13 = packet_in.ch13;
        packet1.ch14 = packet_in.ch14;
        packet1.ch15 = packet_in.ch15;
        packet1.ch16 = packet_in.ch16;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_WK_LOG_RCIN_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_WK_LOG_RCIN_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_log_rcin_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_wk_log_rcin_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_log_rcin_pack(system_id, component_id, &msg , packet1.timestamp , packet1.update_ms , packet1.ch01 , packet1.ch02 , packet1.ch03 , packet1.ch04 , packet1.ch05 , packet1.ch06 , packet1.ch07 , packet1.ch08 , packet1.ch09 , packet1.ch10 , packet1.ch11 , packet1.ch12 , packet1.ch13 , packet1.ch14 , packet1.ch15 , packet1.ch16 );
    mavlink_msg_wk_log_rcin_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_log_rcin_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.timestamp , packet1.update_ms , packet1.ch01 , packet1.ch02 , packet1.ch03 , packet1.ch04 , packet1.ch05 , packet1.ch06 , packet1.ch07 , packet1.ch08 , packet1.ch09 , packet1.ch10 , packet1.ch11 , packet1.ch12 , packet1.ch13 , packet1.ch14 , packet1.ch15 , packet1.ch16 );
    mavlink_msg_wk_log_rcin_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_wk_log_rcin_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_log_rcin_send(MAVLINK_COMM_1 , packet1.timestamp , packet1.update_ms , packet1.ch01 , packet1.ch02 , packet1.ch03 , packet1.ch04 , packet1.ch05 , packet1.ch06 , packet1.ch07 , packet1.ch08 , packet1.ch09 , packet1.ch10 , packet1.ch11 , packet1.ch12 , packet1.ch13 , packet1.ch14 , packet1.ch15 , packet1.ch16 );
    mavlink_msg_wk_log_rcin_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_wk_log_sensor_raw(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_WK_LOG_SENSOR_RAW >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_wk_log_sensor_raw_t packet_in = {
        93372036854775807ULL,{ 73.0, 74.0, 75.0 },{ 157.0, 158.0, 159.0 },{ 241.0, 242.0, 243.0 },{ 325.0, 326.0, 327.0 },409.0,437.0,465.0,493.0,521.0,549.0,577.0,605.0,633.0,{ 661.0, 662.0, 663.0, 664.0, 665.0, 666.0, 667.0, 668.0, 669.0, 670.0, 671.0, 672.0 },997.0,1025.0,1053.0,1081.0,1109.0
    };
    mavlink_wk_log_sensor_raw_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.timestamp = packet_in.timestamp;
        packet1.raw_baro_temperature = packet_in.raw_baro_temperature;
        packet1.raw_baro_pressure_alt = packet_in.raw_baro_pressure_alt;
        packet1.raw_baro_alt = packet_in.raw_baro_alt;
        packet1.raw_tof_below_alt = packet_in.raw_tof_below_alt;
        packet1.raw_tof_front_alt = packet_in.raw_tof_front_alt;
        packet1.raw_battery_voltage = packet_in.raw_battery_voltage;
        packet1.fly_time_s_by_current = packet_in.fly_time_s_by_current;
        packet1.smart_bat_voltage = packet_in.smart_bat_voltage;
        packet1.smart_bat_current = packet_in.smart_bat_current;
        packet1.smart_bat_capacity_full_charge = packet_in.smart_bat_capacity_full_charge;
        packet1.smart_bat_temperature = packet_in.smart_bat_temperature;
        packet1.smart_bat_capacity_remainng = packet_in.smart_bat_capacity_remainng;
        packet1.smart_bat_capacity_percen = packet_in.smart_bat_capacity_percen;
        packet1.main_mcu_temprature = packet_in.main_mcu_temprature;
        
        mav_array_memcpy(packet1.imu_raw_mag, packet_in.imu_raw_mag, sizeof(float)*3);
        mav_array_memcpy(packet1.imu_raw_mag_ext, packet_in.imu_raw_mag_ext, sizeof(float)*3);
        mav_array_memcpy(packet1.imu_raw_acc, packet_in.imu_raw_acc, sizeof(float)*3);
        mav_array_memcpy(packet1.imu_raw_gyro, packet_in.imu_raw_gyro, sizeof(float)*3);
        mav_array_memcpy(packet1.smart_bat_cell_voltage, packet_in.smart_bat_cell_voltage, sizeof(float)*12);
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_WK_LOG_SENSOR_RAW_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_WK_LOG_SENSOR_RAW_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_log_sensor_raw_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_wk_log_sensor_raw_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_log_sensor_raw_pack(system_id, component_id, &msg , packet1.timestamp , packet1.imu_raw_mag , packet1.imu_raw_mag_ext , packet1.imu_raw_acc , packet1.imu_raw_gyro , packet1.raw_baro_temperature , packet1.raw_baro_pressure_alt , packet1.raw_baro_alt , packet1.raw_tof_below_alt , packet1.raw_tof_front_alt , packet1.raw_battery_voltage , packet1.fly_time_s_by_current , packet1.smart_bat_voltage , packet1.smart_bat_current , packet1.smart_bat_cell_voltage , packet1.smart_bat_capacity_full_charge , packet1.smart_bat_temperature , packet1.smart_bat_capacity_remainng , packet1.smart_bat_capacity_percen , packet1.main_mcu_temprature );
    mavlink_msg_wk_log_sensor_raw_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_log_sensor_raw_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.timestamp , packet1.imu_raw_mag , packet1.imu_raw_mag_ext , packet1.imu_raw_acc , packet1.imu_raw_gyro , packet1.raw_baro_temperature , packet1.raw_baro_pressure_alt , packet1.raw_baro_alt , packet1.raw_tof_below_alt , packet1.raw_tof_front_alt , packet1.raw_battery_voltage , packet1.fly_time_s_by_current , packet1.smart_bat_voltage , packet1.smart_bat_current , packet1.smart_bat_cell_voltage , packet1.smart_bat_capacity_full_charge , packet1.smart_bat_temperature , packet1.smart_bat_capacity_remainng , packet1.smart_bat_capacity_percen , packet1.main_mcu_temprature );
    mavlink_msg_wk_log_sensor_raw_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_wk_log_sensor_raw_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_log_sensor_raw_send(MAVLINK_COMM_1 , packet1.timestamp , packet1.imu_raw_mag , packet1.imu_raw_mag_ext , packet1.imu_raw_acc , packet1.imu_raw_gyro , packet1.raw_baro_temperature , packet1.raw_baro_pressure_alt , packet1.raw_baro_alt , packet1.raw_tof_below_alt , packet1.raw_tof_front_alt , packet1.raw_battery_voltage , packet1.fly_time_s_by_current , packet1.smart_bat_voltage , packet1.smart_bat_current , packet1.smart_bat_cell_voltage , packet1.smart_bat_capacity_full_charge , packet1.smart_bat_temperature , packet1.smart_bat_capacity_remainng , packet1.smart_bat_capacity_percen , packet1.main_mcu_temprature );
    mavlink_msg_wk_log_sensor_raw_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_wk_log_mode(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_WK_LOG_MODE >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_wk_log_mode_t packet_in = {
        93372036854775807ULL,29,96
    };
    mavlink_wk_log_mode_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.timestamp = packet_in.timestamp;
        packet1.mode = packet_in.mode;
        packet1.reason = packet_in.reason;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_WK_LOG_MODE_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_WK_LOG_MODE_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_log_mode_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_wk_log_mode_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_log_mode_pack(system_id, component_id, &msg , packet1.timestamp , packet1.mode , packet1.reason );
    mavlink_msg_wk_log_mode_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_log_mode_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.timestamp , packet1.mode , packet1.reason );
    mavlink_msg_wk_log_mode_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_wk_log_mode_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_log_mode_send(MAVLINK_COMM_1 , packet1.timestamp , packet1.mode , packet1.reason );
    mavlink_msg_wk_log_mode_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_wk_log_pos_ctrl(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_WK_LOG_POS_CTRL >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_wk_log_pos_ctrl_t packet_in = {
        93372036854775807ULL,73.0,101.0,129.0,157.0,185.0,213.0,241.0,269.0,297.0,325.0,353.0,381.0
    };
    mavlink_wk_log_pos_ctrl_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.timestamp = packet_in.timestamp;
        packet1.target_vel_yaw = packet_in.target_vel_yaw;
        packet1.target_yaw_rate = packet_in.target_yaw_rate;
        packet1.target_vel_ef_x = packet_in.target_vel_ef_x;
        packet1.target_vel_ef_y = packet_in.target_vel_ef_y;
        packet1.target_vel_ef_z = packet_in.target_vel_ef_z;
        packet1.target_vel_bf_x = packet_in.target_vel_bf_x;
        packet1.target_vel_bf_y = packet_in.target_vel_bf_y;
        packet1.target_bf_acc_x = packet_in.target_bf_acc_x;
        packet1.target_bf_acc_y = packet_in.target_bf_acc_y;
        packet1.target_pos_x = packet_in.target_pos_x;
        packet1.target_pos_y = packet_in.target_pos_y;
        packet1.target_pos_z = packet_in.target_pos_z;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_WK_LOG_POS_CTRL_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_WK_LOG_POS_CTRL_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_log_pos_ctrl_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_wk_log_pos_ctrl_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_log_pos_ctrl_pack(system_id, component_id, &msg , packet1.timestamp , packet1.target_vel_yaw , packet1.target_yaw_rate , packet1.target_vel_ef_x , packet1.target_vel_ef_y , packet1.target_vel_ef_z , packet1.target_vel_bf_x , packet1.target_vel_bf_y , packet1.target_bf_acc_x , packet1.target_bf_acc_y , packet1.target_pos_x , packet1.target_pos_y , packet1.target_pos_z );
    mavlink_msg_wk_log_pos_ctrl_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_log_pos_ctrl_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.timestamp , packet1.target_vel_yaw , packet1.target_yaw_rate , packet1.target_vel_ef_x , packet1.target_vel_ef_y , packet1.target_vel_ef_z , packet1.target_vel_bf_x , packet1.target_vel_bf_y , packet1.target_bf_acc_x , packet1.target_bf_acc_y , packet1.target_pos_x , packet1.target_pos_y , packet1.target_pos_z );
    mavlink_msg_wk_log_pos_ctrl_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_wk_log_pos_ctrl_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_log_pos_ctrl_send(MAVLINK_COMM_1 , packet1.timestamp , packet1.target_vel_yaw , packet1.target_yaw_rate , packet1.target_vel_ef_x , packet1.target_vel_ef_y , packet1.target_vel_ef_z , packet1.target_vel_bf_x , packet1.target_vel_bf_y , packet1.target_bf_acc_x , packet1.target_bf_acc_y , packet1.target_pos_x , packet1.target_pos_y , packet1.target_pos_z );
    mavlink_msg_wk_log_pos_ctrl_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_wk_log_image_geo(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_WK_LOG_IMAGE_GEO >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_wk_log_image_geo_t packet_in = {
        93372036854775807ULL,963497880,963498088,963498296,963498504,963498712,963498920,963499128
    };
    mavlink_wk_log_image_geo_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.timestamp = packet_in.timestamp;
        packet1.index = packet_in.index;
        packet1.latitude = packet_in.latitude;
        packet1.longitude = packet_in.longitude;
        packet1.altitude = packet_in.altitude;
        packet1.roll = packet_in.roll;
        packet1.pitch = packet_in.pitch;
        packet1.yaw = packet_in.yaw;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_WK_LOG_IMAGE_GEO_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_WK_LOG_IMAGE_GEO_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_log_image_geo_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_wk_log_image_geo_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_log_image_geo_pack(system_id, component_id, &msg , packet1.timestamp , packet1.index , packet1.latitude , packet1.longitude , packet1.altitude , packet1.roll , packet1.pitch , packet1.yaw );
    mavlink_msg_wk_log_image_geo_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_log_image_geo_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.timestamp , packet1.index , packet1.latitude , packet1.longitude , packet1.altitude , packet1.roll , packet1.pitch , packet1.yaw );
    mavlink_msg_wk_log_image_geo_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_wk_log_image_geo_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_log_image_geo_send(MAVLINK_COMM_1 , packet1.timestamp , packet1.index , packet1.latitude , packet1.longitude , packet1.altitude , packet1.roll , packet1.pitch , packet1.yaw );
    mavlink_msg_wk_log_image_geo_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_wk_log_text(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_WK_LOG_TEXT >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_wk_log_text_t packet_in = {
        93372036854775807ULL,{ 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 123, 124, 125, 126, 127, 128, 129, 130, 131, 132, 133, 134, 135, 136, 137, 138, 139, 140, 141, 142, 143, 144, 145, 146, 147, 148, 149, 150, 151, 152, 153, 154, 155, 156, 157, 158, 159, 160, 161, 162, 163, 164, 165, 166, 167, 168, 169, 170, 171, 172, 173, 174, 175, 176, 177, 178, 179, 180, 181, 182, 183, 184, 185, 186, 187, 188, 189, 190, 191, 192, 193, 194, 195, 196, 197, 198, 199, 200, 201, 202, 203, 204, 205, 206, 207, 208, 209, 210, 211, 212, 213, 214, 215, 216, 217, 218, 219, 220, 221, 222, 223, 224, 225, 226, 227, 228, 229, 230, 231, 232, 233, 234, 235, 236, 237, 238, 239, 240, 241, 242, 243, 244, 245, 246, 247, 248, 249, 250, 251, 252, 253, 254, 255, 0, 1, 2 }
    };
    mavlink_wk_log_text_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.timestamp = packet_in.timestamp;
        
        mav_array_memcpy(packet1.text, packet_in.text, sizeof(uint8_t)*230);
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_WK_LOG_TEXT_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_WK_LOG_TEXT_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_log_text_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_wk_log_text_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_log_text_pack(system_id, component_id, &msg , packet1.timestamp , packet1.text );
    mavlink_msg_wk_log_text_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_log_text_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.timestamp , packet1.text );
    mavlink_msg_wk_log_text_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_wk_log_text_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_log_text_send(MAVLINK_COMM_1 , packet1.timestamp , packet1.text );
    mavlink_msg_wk_log_text_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_wk_log_params_request(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_WK_LOG_PARAMS_REQUEST >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_wk_log_params_request_t packet_in = {
        17235
    };
    mavlink_wk_log_params_request_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.seq = packet_in.seq;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_WK_LOG_PARAMS_REQUEST_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_WK_LOG_PARAMS_REQUEST_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_log_params_request_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_wk_log_params_request_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_log_params_request_pack(system_id, component_id, &msg , packet1.seq );
    mavlink_msg_wk_log_params_request_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_log_params_request_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.seq );
    mavlink_msg_wk_log_params_request_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_wk_log_params_request_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_log_params_request_send(MAVLINK_COMM_1 , packet1.seq );
    mavlink_msg_wk_log_params_request_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_wk_log_params_data(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_WK_LOG_PARAMS_DATA >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_wk_log_params_data_t packet_in = {
        { 17.0, 18.0, 19.0, 20.0, 21.0, 22.0, 23.0, 24.0, 25.0, 26.0 },19315,19419,137,{ 204, 205, 206, 207, 208, 209, 210, 211, 212, 213, 214, 215, 216, 217, 218, 219, 220, 221, 222, 223, 224, 225, 226, 227, 228, 229, 230, 231, 232, 233, 234, 235, 236, 237, 238, 239, 240, 241, 242, 243, 244, 245, 246, 247, 248, 249, 250, 251, 252, 253, 254, 255, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107 }
    };
    mavlink_wk_log_params_data_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.start_seq = packet_in.start_seq;
        packet1.total_cnt = packet_in.total_cnt;
        packet1.param_counts = packet_in.param_counts;
        
        mav_array_memcpy(packet1.param_value, packet_in.param_value, sizeof(float)*10);
        mav_array_memcpy(packet1.param_name, packet_in.param_name, sizeof(uint8_t)*160);
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_WK_LOG_PARAMS_DATA_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_WK_LOG_PARAMS_DATA_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_log_params_data_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_wk_log_params_data_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_log_params_data_pack(system_id, component_id, &msg , packet1.start_seq , packet1.total_cnt , packet1.param_counts , packet1.param_name , packet1.param_value );
    mavlink_msg_wk_log_params_data_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_log_params_data_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.start_seq , packet1.total_cnt , packet1.param_counts , packet1.param_name , packet1.param_value );
    mavlink_msg_wk_log_params_data_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_wk_log_params_data_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_log_params_data_send(MAVLINK_COMM_1 , packet1.start_seq , packet1.total_cnt , packet1.param_counts , packet1.param_name , packet1.param_value );
    mavlink_msg_wk_log_params_data_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_wk_20t_ranging_param(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_WK_20T_RANGING_PARAM >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_wk_20t_ranging_param_t packet_in = {
        963497464,963497672,963497880,101.0,129.0,157.0,185.0,89
    };
    mavlink_wk_20t_ranging_param_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.alt = packet_in.alt;
        packet1.lat = packet_in.lat;
        packet1.lng = packet_in.lng;
        packet1.yaw_angle = packet_in.yaw_angle;
        packet1.gimbal_pitch = packet_in.gimbal_pitch;
        packet1.gimbal_roll = packet_in.gimbal_roll;
        packet1.gimbal_yaw = packet_in.gimbal_yaw;
        packet1.direction = packet_in.direction;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_WK_20T_RANGING_PARAM_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_WK_20T_RANGING_PARAM_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_20t_ranging_param_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_wk_20t_ranging_param_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_20t_ranging_param_pack(system_id, component_id, &msg , packet1.alt , packet1.lat , packet1.lng , packet1.yaw_angle , packet1.gimbal_pitch , packet1.gimbal_roll , packet1.gimbal_yaw , packet1.direction );
    mavlink_msg_wk_20t_ranging_param_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_20t_ranging_param_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.alt , packet1.lat , packet1.lng , packet1.yaw_angle , packet1.gimbal_pitch , packet1.gimbal_roll , packet1.gimbal_yaw , packet1.direction );
    mavlink_msg_wk_20t_ranging_param_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_wk_20t_ranging_param_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_20t_ranging_param_send(MAVLINK_COMM_1 , packet1.alt , packet1.lat , packet1.lng , packet1.yaw_angle , packet1.gimbal_pitch , packet1.gimbal_roll , packet1.gimbal_yaw , packet1.direction );
    mavlink_msg_wk_20t_ranging_param_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_wk_assist_function_state(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_WK_ASSIST_FUNCTION_STATE >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_wk_assist_function_state_t packet_in = {
        5,72,139,206,17,84,151,218,29,96,163
    };
    mavlink_wk_assist_function_state_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.cruise_en = packet_in.cruise_en;
        packet1.target_lock_en = packet_in.target_lock_en;
        packet1.auto_circle_en = packet_in.auto_circle_en;
        packet1.auto_rise_en = packet_in.auto_rise_en;
        packet1.auto_far_away_en = packet_in.auto_far_away_en;
        packet1.auto_drift_en = packet_in.auto_drift_en;
        packet1.reserve_function1 = packet_in.reserve_function1;
        packet1.reserve_function2 = packet_in.reserve_function2;
        packet1.reserve_function3 = packet_in.reserve_function3;
        packet1.reserve_function4 = packet_in.reserve_function4;
        packet1.reserve_function5 = packet_in.reserve_function5;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_WK_ASSIST_FUNCTION_STATE_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_WK_ASSIST_FUNCTION_STATE_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_assist_function_state_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_wk_assist_function_state_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_assist_function_state_pack(system_id, component_id, &msg , packet1.cruise_en , packet1.target_lock_en , packet1.auto_circle_en , packet1.auto_rise_en , packet1.auto_far_away_en , packet1.auto_drift_en , packet1.reserve_function1 , packet1.reserve_function2 , packet1.reserve_function3 , packet1.reserve_function4 , packet1.reserve_function5 );
    mavlink_msg_wk_assist_function_state_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_assist_function_state_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.cruise_en , packet1.target_lock_en , packet1.auto_circle_en , packet1.auto_rise_en , packet1.auto_far_away_en , packet1.auto_drift_en , packet1.reserve_function1 , packet1.reserve_function2 , packet1.reserve_function3 , packet1.reserve_function4 , packet1.reserve_function5 );
    mavlink_msg_wk_assist_function_state_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_wk_assist_function_state_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_assist_function_state_send(MAVLINK_COMM_1 , packet1.cruise_en , packet1.target_lock_en , packet1.auto_circle_en , packet1.auto_rise_en , packet1.auto_far_away_en , packet1.auto_drift_en , packet1.reserve_function1 , packet1.reserve_function2 , packet1.reserve_function3 , packet1.reserve_function4 , packet1.reserve_function5 );
    mavlink_msg_wk_assist_function_state_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_wk_rc_customize(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_WK_RC_CUSTOMIZE >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_wk_rc_customize_t packet_in = {
        5,72
    };
    mavlink_wk_rc_customize_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.single_click = packet_in.single_click;
        packet1.double_click = packet_in.double_click;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_WK_RC_CUSTOMIZE_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_WK_RC_CUSTOMIZE_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_rc_customize_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_wk_rc_customize_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_rc_customize_pack(system_id, component_id, &msg , packet1.single_click , packet1.double_click );
    mavlink_msg_wk_rc_customize_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_rc_customize_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.single_click , packet1.double_click );
    mavlink_msg_wk_rc_customize_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_wk_rc_customize_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_rc_customize_send(MAVLINK_COMM_1 , packet1.single_click , packet1.double_click );
    mavlink_msg_wk_rc_customize_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_wk_log_ultrasonic_raw_data(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_WK_LOG_ULTRASONIC_RAW_DATA >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_wk_log_ultrasonic_raw_data_t packet_in = {
        93372036854775807ULL,{ 17651, 17652, 17653, 17654, 17655, 17656, 17657, 17658, 17659, 17660, 17661, 17662, 17663, 17664, 17665, 17666, 17667, 17668, 17669, 17670, 17671, 17672, 17673, 17674, 17675, 17676, 17677, 17678, 17679, 17680, 17681, 17682, 17683, 17684, 17685, 17686, 17687, 17688, 17689, 17690, 17691, 17692, 17693, 17694, 17695, 17696, 17697, 17698, 17699, 17700, 17701, 17702, 17703, 17704, 17705, 17706, 17707, 17708, 17709, 17710, 17711, 17712, 17713, 17714, 17715, 17716, 17717, 17718, 17719, 17720, 17721, 17722, 17723, 17724, 17725, 17726, 17727, 17728, 17729, 17730, 17731, 17732, 17733, 17734, 17735, 17736, 17737, 17738, 17739, 17740, 17741, 17742, 17743, 17744, 17745, 17746, 17747, 17748, 17749, 17750 }
    };
    mavlink_wk_log_ultrasonic_raw_data_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.timestamp = packet_in.timestamp;
        
        mav_array_memcpy(packet1.data, packet_in.data, sizeof(uint16_t)*100);
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_WK_LOG_ULTRASONIC_RAW_DATA_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_WK_LOG_ULTRASONIC_RAW_DATA_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_log_ultrasonic_raw_data_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_wk_log_ultrasonic_raw_data_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_log_ultrasonic_raw_data_pack(system_id, component_id, &msg , packet1.timestamp , packet1.data );
    mavlink_msg_wk_log_ultrasonic_raw_data_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_log_ultrasonic_raw_data_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.timestamp , packet1.data );
    mavlink_msg_wk_log_ultrasonic_raw_data_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_wk_log_ultrasonic_raw_data_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_log_ultrasonic_raw_data_send(MAVLINK_COMM_1 , packet1.timestamp , packet1.data );
    mavlink_msg_wk_log_ultrasonic_raw_data_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_wk_r500_nest_landing_state(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_WK_R500_NEST_LANDING_STATE >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_wk_r500_nest_landing_state_t packet_in = {
        17.0,17,{ 84, 85, 86, 87, 88, 89, 90, 91 }
    };
    mavlink_wk_r500_nest_landing_state_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.diatance_to_nest = packet_in.diatance_to_nest;
        packet1.land_time = packet_in.land_time;
        
        mav_array_memcpy(packet1.resever, packet_in.resever, sizeof(uint8_t)*8);
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_WK_R500_NEST_LANDING_STATE_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_WK_R500_NEST_LANDING_STATE_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_r500_nest_landing_state_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_wk_r500_nest_landing_state_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_r500_nest_landing_state_pack(system_id, component_id, &msg , packet1.diatance_to_nest , packet1.land_time , packet1.resever );
    mavlink_msg_wk_r500_nest_landing_state_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_r500_nest_landing_state_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.diatance_to_nest , packet1.land_time , packet1.resever );
    mavlink_msg_wk_r500_nest_landing_state_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_wk_r500_nest_landing_state_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_r500_nest_landing_state_send(MAVLINK_COMM_1 , packet1.diatance_to_nest , packet1.land_time , packet1.resever );
    mavlink_msg_wk_r500_nest_landing_state_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_wk_tof_cali_state(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_WK_TOF_CALI_STATE >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_wk_tof_cali_state_t packet_in = {
        17.0,17,84,151,218,29,96
    };
    mavlink_wk_tof_cali_state_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.phase_temperature = packet_in.phase_temperature;
        packet1.mag_cali_state = packet_in.mag_cali_state;
        packet1.xtalk_cali_state = packet_in.xtalk_cali_state;
        packet1.distance_cali_state = packet_in.distance_cali_state;
        packet1.temp_cali_state = packet_in.temp_cali_state;
        packet1.light_cali_state = packet_in.light_cali_state;
        packet1.crosstalkgainMSB = packet_in.crosstalkgainMSB;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_WK_TOF_CALI_STATE_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_WK_TOF_CALI_STATE_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_tof_cali_state_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_wk_tof_cali_state_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_tof_cali_state_pack(system_id, component_id, &msg , packet1.mag_cali_state , packet1.xtalk_cali_state , packet1.distance_cali_state , packet1.temp_cali_state , packet1.light_cali_state , packet1.crosstalkgainMSB , packet1.phase_temperature );
    mavlink_msg_wk_tof_cali_state_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_tof_cali_state_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.mag_cali_state , packet1.xtalk_cali_state , packet1.distance_cali_state , packet1.temp_cali_state , packet1.light_cali_state , packet1.crosstalkgainMSB , packet1.phase_temperature );
    mavlink_msg_wk_tof_cali_state_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_wk_tof_cali_state_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_tof_cali_state_send(MAVLINK_COMM_1 , packet1.mag_cali_state , packet1.xtalk_cali_state , packet1.distance_cali_state , packet1.temp_cali_state , packet1.light_cali_state , packet1.crosstalkgainMSB , packet1.phase_temperature );
    mavlink_msg_wk_tof_cali_state_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_wk_tof_csv_data(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_WK_TOF_CSV_DATA >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_wk_tof_csv_data_t packet_in = {
        17.0,17,84,151,218,29,96
    };
    mavlink_wk_tof_csv_data_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.magnitude = packet_in.magnitude;
        packet1.type = packet_in.type;
        packet1.index = packet_in.index;
        packet1.type_value = packet_in.type_value;
        packet1.D8 = packet_in.D8;
        packet1.D9 = packet_in.D9;
        packet1.total_num = packet_in.total_num;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_WK_TOF_CSV_DATA_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_WK_TOF_CSV_DATA_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_tof_csv_data_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_wk_tof_csv_data_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_tof_csv_data_pack(system_id, component_id, &msg , packet1.type , packet1.index , packet1.type_value , packet1.D8 , packet1.D9 , packet1.total_num , packet1.magnitude );
    mavlink_msg_wk_tof_csv_data_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_tof_csv_data_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.type , packet1.index , packet1.type_value , packet1.D8 , packet1.D9 , packet1.total_num , packet1.magnitude );
    mavlink_msg_wk_tof_csv_data_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_wk_tof_csv_data_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_tof_csv_data_send(MAVLINK_COMM_1 , packet1.type , packet1.index , packet1.type_value , packet1.D8 , packet1.D9 , packet1.total_num , packet1.magnitude );
    mavlink_msg_wk_tof_csv_data_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_wk_tof_cali_value(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_WK_TOF_CALI_VALUE >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_wk_tof_cali_value_t packet_in = {
        5,72,139,206,17,84,151,218
    };
    mavlink_wk_tof_cali_value_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.type = packet_in.type;
        packet1.temp_reg_31 = packet_in.temp_reg_31;
        packet1.temp_reg_34 = packet_in.temp_reg_34;
        packet1.temp_reg_33 = packet_in.temp_reg_33;
        packet1.temp_reg_39 = packet_in.temp_reg_39;
        packet1.light_reg_36 = packet_in.light_reg_36;
        packet1.light_reg_33 = packet_in.light_reg_33;
        packet1.light_reg_3B = packet_in.light_reg_3B;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_WK_TOF_CALI_VALUE_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_WK_TOF_CALI_VALUE_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_tof_cali_value_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_wk_tof_cali_value_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_tof_cali_value_pack(system_id, component_id, &msg , packet1.type , packet1.temp_reg_31 , packet1.temp_reg_34 , packet1.temp_reg_33 , packet1.temp_reg_39 , packet1.light_reg_36 , packet1.light_reg_33 , packet1.light_reg_3B );
    mavlink_msg_wk_tof_cali_value_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_tof_cali_value_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.type , packet1.temp_reg_31 , packet1.temp_reg_34 , packet1.temp_reg_33 , packet1.temp_reg_39 , packet1.light_reg_36 , packet1.light_reg_33 , packet1.light_reg_3B );
    mavlink_msg_wk_tof_cali_value_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_wk_tof_cali_value_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_tof_cali_value_send(MAVLINK_COMM_1 , packet1.type , packet1.temp_reg_31 , packet1.temp_reg_34 , packet1.temp_reg_33 , packet1.temp_reg_39 , packet1.light_reg_36 , packet1.light_reg_33 , packet1.light_reg_3B );
    mavlink_msg_wk_tof_cali_value_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_wk_tof_cali_data_request(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_WK_TOF_CALI_DATA_REQUEST >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_wk_tof_cali_data_request_t packet_in = {
        5
    };
    mavlink_wk_tof_cali_data_request_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.num = packet_in.num;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_WK_TOF_CALI_DATA_REQUEST_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_WK_TOF_CALI_DATA_REQUEST_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_tof_cali_data_request_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_wk_tof_cali_data_request_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_tof_cali_data_request_pack(system_id, component_id, &msg , packet1.num );
    mavlink_msg_wk_tof_cali_data_request_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_tof_cali_data_request_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.num );
    mavlink_msg_wk_tof_cali_data_request_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_wk_tof_cali_data_request_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wk_tof_cali_data_request_send(MAVLINK_COMM_1 , packet1.num );
    mavlink_msg_wk_tof_cali_data_request_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_walkera(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
    mavlink_test_ntrip_config(system_id, component_id, last_msg);
    mavlink_test_network_status(system_id, component_id, last_msg);
    mavlink_test_wk_product_version(system_id, component_id, last_msg);
    mavlink_test_wk_obstacle_avidance(system_id, component_id, last_msg);
    mavlink_test_wk_mission_break_point(system_id, component_id, last_msg);
    mavlink_test_wk_mission_state(system_id, component_id, last_msg);
    mavlink_test_wk_flight_state(system_id, component_id, last_msg);
    mavlink_test_wk_smart_battery_status(system_id, component_id, last_msg);
    mavlink_test_wk_mount_status(system_id, component_id, last_msg);
    mavlink_test_wk_module_set_serial_number(system_id, component_id, last_msg);
    mavlink_test_wk_module_version(system_id, component_id, last_msg);
    mavlink_test_wk_upgrade_request(system_id, component_id, last_msg);
    mavlink_test_wk_upgrade_request_ack(system_id, component_id, last_msg);
    mavlink_test_wk_upgrade_fw_info(system_id, component_id, last_msg);
    mavlink_test_wk_upgrade_frag_request(system_id, component_id, last_msg);
    mavlink_test_wk_upgrade_frag_data(system_id, component_id, last_msg);
    mavlink_test_wk_upgrade_end_report(system_id, component_id, last_msg);
    mavlink_test_wk_upgrade_end_ack(system_id, component_id, last_msg);
    mavlink_test_wk_selfchk_state(system_id, component_id, last_msg);
    mavlink_test_wk_target_posvel(system_id, component_id, last_msg);
    mavlink_test_wk_followme_cmd(system_id, component_id, last_msg);
    mavlink_test_wk_oilmass_state(system_id, component_id, last_msg);
    mavlink_test_wk_rtk_beacon_state(system_id, component_id, last_msg);
    mavlink_test_wk_heartbeat_ext(system_id, component_id, last_msg);
    mavlink_test_wk_heartbeat_ext_new_rule(system_id, component_id, last_msg);
    mavlink_test_wk_buoy_recgonize_state(system_id, component_id, last_msg);
    mavlink_test_wk_gnss_signal_strength(system_id, component_id, last_msg);
    mavlink_test_wk_rtk_beacon_inav_data(system_id, component_id, last_msg);
    mavlink_test_wk_rtk_beacon_antenna_offset(system_id, component_id, last_msg);
    mavlink_test_wk_param_value(system_id, component_id, last_msg);
    mavlink_test_mission_item_int_ext(system_id, component_id, last_msg);
    mavlink_test_wk_camera_state(system_id, component_id, last_msg);
    mavlink_test_wk_camera_capture_state(system_id, component_id, last_msg);
    mavlink_test_wk_camera_time_lapse_state(system_id, component_id, last_msg);
    mavlink_test_wk_camera_hardware_params(system_id, component_id, last_msg);
    mavlink_test_wk_camera_takephoto_record_info(system_id, component_id, last_msg);
    mavlink_test_wk_camera_params_rpt(system_id, component_id, last_msg);
    mavlink_test_wk_camera_cmd_common_params(system_id, component_id, last_msg);
    mavlink_test_wk_camera_cmd_takephoto(system_id, component_id, last_msg);
    mavlink_test_wk_camera_cmd_video_rec(system_id, component_id, last_msg);
    mavlink_test_wk_camera_cmd_sdcard_format(system_id, component_id, last_msg);
    mavlink_test_wk_camera_status_report(system_id, component_id, last_msg);
    mavlink_test_wk_camera_cmd_focus(system_id, component_id, last_msg);
    mavlink_test_wk_camera_cmd_utc_time_sync(system_id, component_id, last_msg);
    mavlink_test_wk_camera_cmd_create_folder(system_id, component_id, last_msg);
    mavlink_test_wk_camera_cmd_cap_param(system_id, component_id, last_msg);
    mavlink_test_wk_camera_cmd_preview_param(system_id, component_id, last_msg);
    mavlink_test_wk_camera_cmd_record_param(system_id, component_id, last_msg);
    mavlink_test_wk_camera_cmd_iso(system_id, component_id, last_msg);
    mavlink_test_wk_camera_cmd_shutter(system_id, component_id, last_msg);
    mavlink_test_wk_camera_cmd_ev_mode(system_id, component_id, last_msg);
    mavlink_test_wk_camera_cmd_ev_value(system_id, component_id, last_msg);
    mavlink_test_wk_camera_cmd_awb_mode(system_id, component_id, last_msg);
    mavlink_test_wk_camera_cmd_csc(system_id, component_id, last_msg);
    mavlink_test_wk_camera_cmd_hsyk_dualcam_params(system_id, component_id, last_msg);
    mavlink_test_wk_camera_qrcode_pos(system_id, component_id, last_msg);
    mavlink_test_wk_5ginfo_status(system_id, component_id, last_msg);
    mavlink_test_wk_product_id(system_id, component_id, last_msg);
    mavlink_test_wk_product_bound(system_id, component_id, last_msg);
    mavlink_test_wk_product_lock(system_id, component_id, last_msg);
    mavlink_test_wk_product_active(system_id, component_id, last_msg);
    mavlink_test_wk_test(system_id, component_id, last_msg);
    mavlink_test_wk_camera_cmd_camera_control(system_id, component_id, last_msg);
    mavlink_test_wk_time_lapse_dire_param(system_id, component_id, last_msg);
    mavlink_test_wk_time_lapse_dire_param_ack(system_id, component_id, last_msg);
    mavlink_test_wk_camera_cmd_focus2(system_id, component_id, last_msg);
    mavlink_test_wk_camera_mini_dual_parameter(system_id, component_id, last_msg);
    mavlink_test_wk_camera_mini_dual_measure_mode(system_id, component_id, last_msg);
    mavlink_test_wk_camera_mini_dual_state(system_id, component_id, last_msg);
    mavlink_test_wk_scout_state(system_id, component_id, last_msg);
    mavlink_test_wk_rc_parameter(system_id, component_id, last_msg);
    mavlink_test_wk_engine_control_state(system_id, component_id, last_msg);
    mavlink_test_wk_camera_cmd_utc_time_sync1(system_id, component_id, last_msg);
    mavlink_test_wk_camera_focusing(system_id, component_id, last_msg);
    mavlink_test_wk_camera_laser_ranging(system_id, component_id, last_msg);
    mavlink_test_wk_camera_laser_ranging_state(system_id, component_id, last_msg);
    mavlink_test_wk_set_connect_param(system_id, component_id, last_msg);
    mavlink_test_wk_set_ai_tracking_cmd(system_id, component_id, last_msg);
    mavlink_test_wk_set_vr_param(system_id, component_id, last_msg);
    mavlink_test_wk_mini_4g_authentication(system_id, component_id, last_msg);
    mavlink_test_wk_log_flight_state(system_id, component_id, last_msg);
    mavlink_test_wk_log_gnss(system_id, component_id, last_msg);
    mavlink_test_wk_log_gps_raw(system_id, component_id, last_msg);
    mavlink_test_wk_log_rtk_raw(system_id, component_id, last_msg);
    mavlink_test_wk_log_beacon(system_id, component_id, last_msg);
    mavlink_test_wk_log_mission(system_id, component_id, last_msg);
    mavlink_test_wk_log_motors(system_id, component_id, last_msg);
    mavlink_test_wk_log_rcin(system_id, component_id, last_msg);
    mavlink_test_wk_log_sensor_raw(system_id, component_id, last_msg);
    mavlink_test_wk_log_mode(system_id, component_id, last_msg);
    mavlink_test_wk_log_pos_ctrl(system_id, component_id, last_msg);
    mavlink_test_wk_log_image_geo(system_id, component_id, last_msg);
    mavlink_test_wk_log_text(system_id, component_id, last_msg);
    mavlink_test_wk_log_params_request(system_id, component_id, last_msg);
    mavlink_test_wk_log_params_data(system_id, component_id, last_msg);
    mavlink_test_wk_20t_ranging_param(system_id, component_id, last_msg);
    mavlink_test_wk_assist_function_state(system_id, component_id, last_msg);
    mavlink_test_wk_rc_customize(system_id, component_id, last_msg);
    mavlink_test_wk_log_ultrasonic_raw_data(system_id, component_id, last_msg);
    mavlink_test_wk_r500_nest_landing_state(system_id, component_id, last_msg);
    mavlink_test_wk_tof_cali_state(system_id, component_id, last_msg);
    mavlink_test_wk_tof_csv_data(system_id, component_id, last_msg);
    mavlink_test_wk_tof_cali_value(system_id, component_id, last_msg);
    mavlink_test_wk_tof_cali_data_request(system_id, component_id, last_msg);
}

#ifdef __cplusplus
}
#endif // __cplusplus
#endif // WALKERA_TESTSUITE_H
