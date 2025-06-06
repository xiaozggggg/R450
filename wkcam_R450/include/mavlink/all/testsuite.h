/** @file
 *    @brief MAVLink comm protocol testsuite generated from all.xml
 *    @see http://qgroundcontrol.org/mavlink/
 */
#pragma once
#ifndef ALL_TESTSUITE_H
#define ALL_TESTSUITE_H

#ifdef __cplusplus
extern "C" {
#endif

#ifndef MAVLINK_TEST_ALL
#define MAVLINK_TEST_ALL
static void mavlink_test_ardupilotmega(uint8_t, uint8_t, mavlink_message_t *last_msg);
static void mavlink_test_common(uint8_t, uint8_t, mavlink_message_t *last_msg);
static void mavlink_test_standard(uint8_t, uint8_t, mavlink_message_t *last_msg);
static void mavlink_test_walkera(uint8_t, uint8_t, mavlink_message_t *last_msg);
static void mavlink_test_all(uint8_t, uint8_t, mavlink_message_t *last_msg);

static void mavlink_test_all(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
    mavlink_test_ardupilotmega(system_id, component_id, last_msg);
    mavlink_test_common(system_id, component_id, last_msg);
    mavlink_test_standard(system_id, component_id, last_msg);
    mavlink_test_walkera(system_id, component_id, last_msg);
    mavlink_test_all(system_id, component_id, last_msg);
}
#endif

#include "../ardupilotmega/testsuite.h"
#include "../common/testsuite.h"
#include "../standard/testsuite.h"
#include "../walkera/testsuite.h"



static void mavlink_test_all(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{

}

#ifdef __cplusplus
}
#endif // __cplusplus
#endif // ALL_TESTSUITE_H
