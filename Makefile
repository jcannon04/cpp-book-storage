CC=g++

DEBUG=-g

TARGET=library

CFLAGS= -c -Wall $(DEBUG)


$(TARGET): main.o library.o
	$(CC) main.o library.o -o $(TARGET)

newMain1.o: main.cpp library.h book.h
	$(CC) $(CFLAGS) main.cpp

library.o: library.cpp book.h library.h
	$(CC) $(CFLAGS) library.cpp

clean:
	rm *.o *~ $(TARGET)
