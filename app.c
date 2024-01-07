/* Copyright (c) 2023 Kurth4cker <kurth4cker@gmail.com>
 * Licensed under terms of GPLv3+. See file COPYING for details.
 */

#include <X11/Xlib.h>

#include "app.h"

int
app_init(struct app *app, const char *display_name)
{
	app->display = XOpenDisplay(display_name);
	if (!app->display)
		return 0;

	app->screen = XDefaultScreen(app->display);
	app->window = XCreateSimpleWindow(app->display,
			XDefaultRootWindow(app->display),
			0, 0,
			500, 300,
			0,
			WhitePixel(app->display, app->screen),
			WhitePixel(app->display, app->screen));

	return 1;
}

void
app_end(struct app *app)
{
	XDestroyWindow(app->display, app->window);
	XCloseDisplay(app->display);
}
