CC = gcc
name =landscape
TARGET = ./$(name)
DEPEND = .depend
LIBS=-lGL -lGLU -lglut
LDFLAGS =-L/usr/X11R6/lib $(LIBS)
CFLAGS = -Wall -O2
OBJ = ./loadtexture.o

.c.o:
	$(CC) $(CFLAGS) -Wall -O2 -c -o $@ $<

$(TARGET): $(name).o $(OBJ)
	$(CC) $(LDFLAGS) $^ -o  $@
	rm  -R -f  *.o


clean:
	rm  -R -f  *.o
