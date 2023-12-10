#include <X11/Xlib.h>

#include "window.h"

Window
create_main_window(Display *dpy, int screen, unsigned long background)
{
	return XCreateSimpleWindow(dpy,
			RootWindow(dpy, screen),
			0, 0,
			500, 300,
			0, background,
			background);
}
