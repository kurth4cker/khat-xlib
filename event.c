/* Copyright (c) 2023 Kurth4cker <kurth4cker@gmail.com>
 * Licensed under terms of GPLv3+. See file COPYING for details.
 */

#include <X11/Xlib.h>
#include <X11/keysym.h>

#include "event.h"

enum {
	EVENT_QUIT,
	EVENT_CONT,
};

static int
key_press(KeySym key)
{
	switch (key) {
	case XK_q:
		return EVENT_QUIT;
	};
	return EVENT_CONT;
}

void
event_loop(Display *dpy, Window win)
{
	XEvent event;

	XSelectInput(dpy, win, KeyPressMask);

	for (;;) {
		XNextEvent(dpy, &event);
		switch (event.type) {
		case KeyPress:
			KeySym key = XLookupKeysym(&event.xkey, 0);
			if (key_press(key) == EVENT_QUIT)
				return;
			break;
		}
	}
}
