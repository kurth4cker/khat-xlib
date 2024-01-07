VERSION = 0.0.0_git

CC = cc
LIBS = -lX11

BIN = khat-xlib
OBJ = \
	app.o \
	event.o \
	main.o

SRC = $(OBJ:.o=.c)
INC = app.h event.h
DISTFILES = \
	COPYING \
	README.md \
	Makefile \
	$(SRC) \
	$(INC)
DISTNAME = $(BIN)-$(VERSION)

all: $(BIN)

app.o: app.h
event.o: event.h
main.o: app.h event.h

$(BIN): $(OBJ)
	$(CC) $(LDFLAGS) -o $@ $(OBJ) $(LIBS)

clean:
	rm -f $(BIN) *.o $(DISTNAME).tar.gz

dist: $(DISTFILES)
	mkdir $(DISTNAME)
	cp -f $(DISTFILES) $(DISTNAME)
	tar -c $(DISTNAME) | gzip -c > $(DISTNAME).tar.gz
	rm -r $(DISTNAME)

.SUFFIXES: .c .o
.c.o:
	$(CC) $(CFLAGS) -c $<
