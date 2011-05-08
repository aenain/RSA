# Components of the library.
bigint-library-objects = \
	bigint/BigUnsigned.o \
	bigint/BigInteger.o \
	bigint/BigIntegerAlgorithms.o \
	bigint/BigUnsignedInABase.o \
	bigint/BigIntegerUtils.o

# Main part of Makefile.

rsa: rsa.cpp key_pair_generator.o cipher.o $(bigint-library-objects)
	g++ -O2 rsa.cpp key_pair_generator.o cipher.o io.o prime.o numbers.o $(bigint-library-objects) -o rsa

key_pair_generator.o: key_pair_generator.cpp key_pair_generator.h prime.o io.o
	g++ -O2 -c key_pair_generator.cpp

cipher.o: cipher.cpp cipher.h prime.o io.o
	g++ -O2 -c cipher.cpp

io.o: io.cpp io.h numbers.o
	g++ -O2 -c io.cpp

prime.o: prime.cpp prime.h numbers.o
	g++ -O2 -c prime.cpp

numbers.o: numbers.cpp numbers.h
	g++ -O2 -c numbers.cpp
