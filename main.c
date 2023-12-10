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
