/*
 * \file display/error.c
 *
 * Error display handling. Prints an error message to the screen when the kernel
 * is put in an error state.
 *
 * Copyright (c) 2017-2021, Purdue University ACM SIGBots.
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

#include "kapi.h"
#include "v5_api.h"

void display_fatal_error(const char* text) {
	// in fatal error state, cannot rely on integrity of the RTOS
	char s[50];
	strncpy(s, text, 50);
	vexDisplayForegroundColor(0x00FF0000); // red
	vexDisplayRectFill(0, 0, 480, 240);
	vexDisplayForegroundColor(0x00FFFFFF); //white
	vexDisplayCenteredString(6, s);
}

void display_error(const char* text) {
	// proceed if there's not another error showing and there's an error message
	// to show
	if (!text[0]) {
		return;
	}
	char s[50];
	strncpy(s, text, 50);
	vexDisplayForegroundColor(0x00FF0000); // red
	vexDisplayRectFill(0, 0, 480, 240);
	vexDisplayForegroundColor(0x00FFFFFF); //white
	vexDisplayCenteredString(6, s);
}
