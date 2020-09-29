/**
 * \file devices/vdml_distance.cpp
 *
 * Contains functions for interacting with the V5 ADI.
 *
 * Copyright (c) 2017-2020, Purdue University ACM SIGBots.
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

#include "pros/distance.hpp"

namespace pros {
using namespace pros::c;

Distance::Distance(const std::uint8_t port):_port(port){}

Distance::get(){
  return distance_get(_port);
}

Distance::get_confidence(){
  return distance_get_confidence(_port);
}

Distance::get_object_size(){
  return distance_get_object_size(_port);
}

Distance::get_object_velocity(){
  return distance_get_object_velocity(_port);
}

Distance::get_port(){
  return _port;
}
}