/* See file COPYING for license instructions */

#include <X11/Xlib.h>
#include <X11/keysym.h>

#include "event.h"

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
			if (key == XK_q)
				return;
			break;
		}
	}
}
