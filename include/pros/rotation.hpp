/**
 * \file pros/rotation.hpp
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
#ifndef _PROS_ROTATION_HPP_
#define _PROS_ROTATION_HPP_

#include <cstdint>

#include "pros/rotation.h"

namespace pros {
class Rotation {
	const std::uint8_t _port;

	public:
	Rotation(const std::uint8_t port) : _port(port){};

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
	 * \return 1 if the operation was successful or PROS_ERR if the operation
	 * failed, setting errno.
	 */
	virtual std::int32_t reset();

	/**
 	 * Set the rotation sensor position reading to a desired rotation value.
	 *
	 * This function uses the following values of errno when an error state is
	 * reached:
	 * ENXIO - The given value is not within the range of V5 ports (1-21).
	 * ENODEV - The port cannot be configured as an Rotation Sensor
	 *
	 * \param position
	 * 		  The position in terms of ticks
	 * \return 1 if the operation was successful or PROS_ERR if the operation
	 * failed, setting errno.
	 */
	virtual std::int32_t set_position(std::uint32_t position);

	/**
	 * Reset the rotation sensor to a desired rotation value.
	 *
	 * This function uses the following values of errno when an error state is
	 * reached:
	 * ENXIO - The given value is not within the range of V5 ports (1-21).
	 * ENODEV - The port cannot be configured as an Rotation Sensor
	 *
	 * \param position
	 * 		  The position in terms of ticks
	 * \return 1 if the operation was successful or PROS_ERR if the operation
	 * failed, setting errno.
	 */
	virtual std::int32_t reset_position(void);

	/**
 	 * Get the Rotation sensor's current position.  Specifically, in
 	 * terms of hundreths of degrees.
	 *
	 * This function uses the following values of errno when an error state is
	 * reached:
	 * ENXIO - The given value is not within the range of V5 ports (1-21).
	 * ENODEV - The port cannot be configured as an Rotation Sensor
	 *
	 * \return The position value or PROS_ERR if the operation failed, setting
	 * errno.
	 */
	virtual std::int32_t get_position();

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
	 * \return The 
	 value or PROS_ERR_F if the operation failed, setting
	 * errno.
	 */
	virtual std::int32_t get_velocity();

	/**
     * Get the Rotation sensor's current position in terms of an angle
     * measured in hundreths of degrees.
	 *
	 * This function uses the following values of errno when an error state is
	 * reached:
	 * ENXIO - The given value is not within the range of V5 ports (1-21).
	 * ENODEV - The port cannot be configured as an Rotation Sensor
	 *
	 * \return The angle value or PROS_ERR if the operation failed, setting
	 * errno.
	 */
	virtual std::int32_t get_angle();

	/**
	 * Sets if the rotation sensor's positive/negative direction is reversed or not.
	 *
	 * This function uses the following values of errno when an error state is
	 * reached:
	 * ENXIO - The given value is not within the range of V5 ports (1-21).
	 * ENODEV - The port cannot be configured as an Rotation Sensor
	 *
	 * \param  value
	 * 				 Determines if the direction of the rotational sensor is
	 * 				 reversed or not.
	 *
	 * \return 1 if the operation was successful or PROS_ERR if the operation
	 * failed, setting errno.
	 */
	virtual std::int32_t set_reversed(bool value);

	/**
	 * Reverses the rotation sensor's direction.
	 *
	 * This function uses the following values of errno when an error state is
	 * reached:
	 * ENXIO - The given value is not within the range of V5 ports (1-21).
	 * ENODEV - The port cannot be configured as an Rotation Sensor
	 *
	 * \return 1 if the operation was successful or PROS_ERR if the operation
	 * failed, setting errno.
	 */
	virtual std::int32_t reverse();

	/**
	 * Check whether the rotation sensor's direction is reversed.
	 *
	 * This function uses the following values of errno when an error state is
	 * reached:
	 * ENXIO - The given value is not within the range of V5 ports (1-21).
	 * ENODEV - The port cannot be configured as an Rotation Sensor
	 *
	 * \return Reversed value or PROS_ERR if the operation failed, setting
	 * errno.
	 */
	virtual std::int32_t get_reversed();
};
}  // namespace pros

#endif
