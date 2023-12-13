/* Copyright (c) 2023 Kurth4cker <kurth4cker@gmail.com>
 * Licensed under terms of GPLv3+. See file COPYING for details.
 */

#include <X11/Xlib.h>

#include "app.h"

void
app_end(struct app *app)
{
	XDestroyWindow(app->display, app->window);
	XCloseDisplay(app->display);
}
