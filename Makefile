CC = cc
LDFLAGS = -lX11

BIN = khat-xlib
OBJ = main.o create_main_window.o

all: $(BIN)
$(BIN): $(OBJ)
	$(CC) -o $@ $(OBJ) $(LDFLAGS)

clean:
	rm -f $(BIN) *.o

.SUFFIXES: .c .o
.c.o:
	$(CC) $(CFLAGS) -c $<
