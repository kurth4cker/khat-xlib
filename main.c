/* Copyright (c) 2023 Kurth4cker <kurth4cker@gmail.com>
 * Licensed under terms of GPLv3+. See file COPYING for details.
 */

#include <assert.h>
#include <unistd.h>
#include <X11/Xlib.h>

#include "event.h"

int
main(void)
{
	Display *dpy;
	Window main_window;
	unsigned long white;
	int screen = -1;

	dpy = XOpenDisplay(NULL);
	assert(dpy != NULL);

	screen = DefaultScreen(dpy);
	assert(screen >= 0);

	white = WhitePixel(dpy, screen);

	main_window = XCreateSimpleWindow(dpy, DefaultRootWindow(dpy),
			0, 0, 500, 300,
			0, white,
			white);
	XMapWindow(dpy, main_window);
	XFlush(dpy);

	event_loop(dpy, main_window);

	XCloseDisplay(dpy);
}
