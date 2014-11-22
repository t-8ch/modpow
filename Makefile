LDLIBS=-lgmp
CFLAGS=-std=c89 -Werror -Wall -Wpedantic -O3

all: main test

main: modpow.c
test: modpow.c

modpow.c: modpow.h
