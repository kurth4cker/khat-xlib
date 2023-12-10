/* main.c -- khat-xlib, simple drawing program
 * Copyright (C) 2023 Kurth4cker
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

#include <assert.h>
#include <unistd.h>
#include <X11/Xlib.h>
#include <X11/keysym.h>

#include "window.h"

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

	main_window = create_main_window(dpy, screen, white);
	XMapWindow(dpy, main_window);
	XFlush(dpy);

	XSelectInput(dpy, main_window, ExposureMask | KeyPressMask
			| ButtonPressMask | Button1MotionMask
			| Button2MotionMask | StructureNotifyMask);

	int done = 0;
	XEvent event;
	while (!done) {
		XNextEvent(dpy, &event);
		switch (event.type) {
		case KeyPress:
			if (XLookupKeysym(&event.xkey, 0) == XK_q)
				done = 1;
			break;
		}
	}

	XCloseDisplay(dpy);
}
