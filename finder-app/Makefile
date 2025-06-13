# Makefile to build write.c with GNU make variable CROSS_COMPILE
# Whe CROSS_COMPILE is specified with aarch64-none-linux-gnu- :  compile with the cross compiler
# When the CROSS_COMPILE is not specified, compile use the native build platform

VPATH = .

#ifdef CROSS_COMPILE
#	CC := aarch64-none-linux-gnu-gcc
#else
#	CC := gcc
#endif

ifeq ($(CROSS_COMPILE), 1)
	CC := aarch64-none-linux-gnu-gcc
else
	CC := gcc
endif


CFLAGS = -Wall -g

TARGET = writer

SRC = ./writer.c

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRC)

clean:
	rm -f $(TARGET)
 
