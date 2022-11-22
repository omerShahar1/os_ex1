CC=gcc
FLAGS= -Wall -g

all: cmp copy encode decode lib

cmp: cmp.c
	$(CC) $(FLAGS) -o cmp cmp.c

copy: copy.c
	$(CC) $(FLAGS) -o copy copy.c

encode: lib encode.c 
	$(CC) $(FLAGS) encode.c -ldl -o encode

decode: lib decode.c
	$(CC) $(FLAGS) decode.c -ldl -o decode

lib: codec1.c codec2.c codec.h 
	$(CC) $(FLAGS) -o libcodec1.so -shared -fPIC codec1.c
	$(CC) $(FLAGS) -o libcodec2.so -shared -fPIC codec2.c


.PHONY: all clean

clean:
	rm -f encode decode cmp copy libcodec1.so libcodec2.so