/**
 * \file pros/rotation.h
 *
 * Contains prototypes for functions related to the VEX Rotation sensor.
 *
 * Visit https://pros.cs.purdue.edu/v5/tutorials/topical/rotation.html to learn
 * more.
 *
 * This file should not be modified by users, since it gets replaced whenever
 * a kernel upgrade occurs.
 *
 * Copyright (c) 2017-2020, Purdue University ACM SIGBots.
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

#ifndef _PROS_ROTATION_H_
#define _PROS_ROTATION_H_

#include <stdbool.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
namespace pros {
namespace c {
#endif

/**
 * Resets Rotation Sensor 
 *
 * Resets rotation sensor by multiplying the rotation reading by 
 * -1 and changes the angle by -180 degrees only if the direction 
 * was recently reversed. 
 *
 * This function uses the following values of errno when an error state is
 * reached:
 * ENXIO - The given value is not within the range of V5 ports (1-21).
 * ENODEV - The port cannot be configured as an Rotation Sensor
 *
 * \param port
 *        The V5 Rotation Sensor port number from 1-21
 * \return 1 if the operation was successful or PROS_ERR if the operation
 * failed, setting errno.
 */
int32_t rotation_reset(uint8_t port);

/**
 * Set the rotation sensor position reading to a desired rotation value.
 *
 * This function uses the following values of errno when an error state is
 * reached:
 * ENXIO - The given value is not within the range of V5 ports (1-21).
 * ENODEV - The port cannot be configured as an Rotation Sensor
 *
 * \param port
 *		  The V5 Rotation Sensor port number from 1-21
 * \param position 
 * 		  The position in terms of ticks
 * \return 1 if the operation was successful or PROS_ERR if the operation
 * failed, setting errno.
 */
int32_t rotation_set_position(uint8_t port, uint32_t position);

/**
 * Resets the rotation sensor position to 0.
 *
 * This function uses the following values of errno when an error state is
 * reached:
 * ENXIO - The given value is not within the range of V5 ports (1-21).
 * ENODEV - The port cannot be configured as an Rotation Sensor
 *
 * \param port
 *		  The V5 Rotation Sensor port number from 1-21

 * \return 1 if the operation was successful or PROS_ERR if the operation
 * failed, setting errno.
 */
int32_t rotation_reset_position(uint8_t port);

/**
 * Get the Rotation sensor's current position.  Specifically, in
 * terms of hundreths of degrees.
 *
 * This function uses the following values of errno when an error state is
 * reached:
 * ENXIO - The given value is not within the range of V5 ports (1-21).
 * ENODEV - The port cannot be configured as an Rotation Sensor
 *
 * \param  port
 * 				 The V5 Rotation Sensor port number from 1-21
 * \return The position value or PROS_ERR_F if the operation failed, setting
 * errno.
 */
int32_t rotation_get_position(uint8_t port);

/**
 * Get the Rotation sensor's current velocity in hundreths of
 * degrees per second.
 *
 * This function uses the following values of errno when an error state is
 * reached:
 * ENXIO - The given value is not within the range of V5 ports (1-21).
 * ENODEV - The port cannot be configured as an Rotation Sensor
 *
 * \param  port
 * 				 The V5 Rotation Sensor port number from 1-21
 * \return The velocity value or PROS_ERR_F if the operation failed, setting
 * errno.
 */
int32_t rotation_get_velocity(uint8_t port);

/**
 * Get the Rotation sensor's current position in terms of an angle
 * measured in hundreths of degrees.
 * 
 * This function uses the following values of errno when an error state is
 * reached:
 * ENXIO - The given value is not within the range of V5 ports (1-21).
 * ENODEV - The port cannot be configured as an Rotation Sensor
 *
 * \param  port
 * 				 The V5 Rotation Sensor port number from 1-21
 * \return The angle value or PROS_ERR_F if the operation failed, setting
 * errno.
 */
int32_t rotation_get_angle(uint8_t port);

/**
 * Set the rotation sensor's direction reversed flag
 * 
 * This function uses the following values of errno when an error state is
 * reached:
 * ENXIO - The given value is not within the range of V5 ports (1-21).
 * ENODEV - The port cannot be configured as an Rotation Sensor
 *
 * \param  port
 * 				 The V5 Rotation Sensor port number from 1-21
 * \param  value
 * 				 Determines if the direction of the rotation sensor is reversed or not.
 * 
 * \return 1 if operation succeeded or PROS_ERR if the operation failed, setting
 * errno.
 */
int32_t rotation_set_reversed(uint8_t port, bool value);

/**
 * Reverses the rotation sensor's direction.
 *
 * This function uses the following values of errno when an error state is
 * reached:
 * ENXIO - The given value is not within the range of V5 ports (1-21).
 * ENODEV - The port cannot be configured as an Rotation Sensor
 *
 * \param  port
 * 				 The V5 Rotation Sensor port number from 1-21
 *
 * \return 1 if the operation was successful or PROS_ERR if the operation
 * failed, setting errno.
 */
int32_t rotation_reverse(uint8_t port);

/**
 * Check whether the rotation sensor's direction is reversed.
 * 
 * This function uses the following values of errno when an error state is
 * reached:
 * ENXIO - The given value is not within the range of V5 ports (1-21).
 * ENODEV - The port cannot be configured as an Rotation Sensor
 *
 * \param  port
 * 				 The V5 Rotation Sensor port number from 1-21
 * 
 * \return Boolean value of if the rotation sensor's direction is reversed or not
 * or PROS_ERR if the operation failed, setting errno.
 */
int32_t rotation_get_reversed(uint8_t port);

#ifdef __cplusplus
} //namespace C
} //namespace pros
} //extern "C"
#endif

#endif
