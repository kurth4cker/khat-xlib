#ifndef APP_H
#define APP_H

#include <X11/Xlib.h>

struct app {
	Display *display;
	int screen;
	Window window;
};

int app_init(struct app *, const char *);
void app_end(struct app *);

#endif /* APP_H */
