#ifndef APP_H
#define APP_H

#include <X11/Xlib.h>

struct app {
	Display *display;
	int screen;
	Window window;
};

int app_open(struct app *, const char *);
void app_close(struct app *);

#endif /* APP_H */
