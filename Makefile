CC = cc
LDFLAGS = -lX11

BIN = khat-xlib
OBJ = \
	app.o \
	event.o \
	main.o

all: $(BIN)

app.o: app.h
event.o: event.h
main.o: app.h event.h

$(BIN): $(OBJ)
	$(CC) -o $@ $(OBJ) $(LDFLAGS)

clean:
	rm -f $(BIN) *.o

.SUFFIXES: .c .o
.c.o:
	$(CC) $(CFLAGS) -c $<
