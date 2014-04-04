#
# Makefile for picasm (Unix)
#

VERSION="106"
ARCHIVEFILES=LICENSE makefile.wat picasm.doc Makefile expr.c pic12bit.c \
	picasm.h config.c makefile.sas pic14bit.c symtab.c devices.c \
	makefile.w32 makefile.vc picasm.c token.c \
	examples/example.asm examples/morse.asm examples/morse.h \
	examples/pic16c84.h examples/picmac.h

OBJS = picasm.obj devices.obj config.obj token.obj symtab.obj expr.obj \
       pic12bit.obj pic14bit.obj

CC = gcc.exe
CFLAGS = -Wall -O3 -Zomf -Zsys -s -mpentium
RM = del

.SUFFIXES:
.SUFFIXES: .c .obj

TARGET=picasm.exe

picasm.exe: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@

clean:
	$(RM) $(OBJS) picasm.exe *~

archive: picasm$(VERSION).tar.gz picasm$(VERSION).zip

picasm$(VERSION).tar.gz: $(ARCHIVEFILES)
	tar czf picasm$(VERSION).tar.gz $(ARCHIVEFILES)

picasm$(VERSION).zip: $(ARCHIVEFILES)
	zip picasm$(VERSION).zip $(ARCHIVEFILES)

picasm.obj: picasm.c picasm.h
devices.obj: devices.c picasm.h
config.obj: config.c picasm.h
token.obj: token.c picasm.h
symtab.obj: symtab.c picasm.h
expr.obj: expr.c picasm.h
pic12bit.obj: pic12bit.c picasm.h
pic14bit.obj: pic14bit.c picasm.h

.c.obj:
	$(CC) $(CFLAGS) -c $<
