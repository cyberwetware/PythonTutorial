# The Makefile was created for Ubuntu SMP x86_64 GNU/Linux
CC  	= gcc
CFLAGS  = -g -Wall -fPIC
LDFLAGS = -shared
LDLIBS	= -lpython2.7

PY_INC	= -I/usr/include/python2.7
TARGET  = pyfoo.so 
OBJECTS = pyfoo.o

$(TARGET) : $(OBJECTS)
	$(CC) $(LDFLAGS) -o $(TARGET) $(OBJECTS) $(LDLIBS)

%.o : %.c
	$(CC) $(CFLAGS) $(PY_INC) -c $<

clean:
	$(RM) $(OBJECTS) $(TARGET)

