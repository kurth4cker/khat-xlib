/* Copyright (c) 2023 Kurth4cker <kurth4cker@gmail.com>
 * Licensed under terms of GPLv3+. See file COPYING for details.
 */

#include <assert.h>
#include <stdio.h>
#include <unistd.h>
#include <X11/Xlib.h>

#include "app.h"
#include "event.h"

int
main(void)
{
	struct app app;

	if (!app_init(&app, NULL) && !app.display) {
		fprintf(stderr, "can't open display\n");
		return 1;
	}
	XMapWindow(app.display, app.window);
	XFlush(app.display);

	event_loop(app.display, app.window);

	app_end(&app);
}
