CC = cc
LDFLAGS = -lX11

BIN = khat-xlib
OBJ = \
	event_loop.o \
	main.o

all: $(BIN)

event_loop.o: event.h
main.o: event.h

$(BIN): $(OBJ)
	$(CC) -o $@ $(OBJ) $(LDFLAGS)

clean:
	rm -f $(BIN) *.o

.SUFFIXES: .c .o
.c.o:
	$(CC) $(CFLAGS) -c $<
