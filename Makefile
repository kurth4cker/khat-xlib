CC = cc
LDFLAGS = -lX11

BIN = khat-xlib
OBJ = \
	app_end.o \
	app_init.o \
	event_loop.o \
	main.o

all: $(BIN)

app_end.o: app.h
app_init.o: app.h
event_loop.o: event.h
main.o: app.h event.h

$(BIN): $(OBJ)
	$(CC) -o $@ $(OBJ) $(LDFLAGS)

clean:
	rm -f $(BIN) *.o

.SUFFIXES: .c .o
.c.o:
	$(CC) $(CFLAGS) -c $<
