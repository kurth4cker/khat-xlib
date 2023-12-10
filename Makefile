CC = cc
LDFLAGS = -lX11

BIN = khat-xlib
OBJ = main.o event_loop.o

all: $(BIN)
$(OBJ): event.h


$(BIN): $(OBJ)
	$(CC) -o $@ $(OBJ) $(LDFLAGS)

clean:
	rm -f $(BIN) *.o

.SUFFIXES: .c .o
.c.o:
	$(CC) $(CFLAGS) -c $<
