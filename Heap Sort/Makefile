##############################################################################
# Makefile for sort application
# CMP_SC 3050
# SP 2023
# By Jim Ries (RiesJ@missouri.edu)
##############################################################################
CC = gcc
CFLAGS = -Wall -Werror -c -g -std=c11 -I.
LDFLAGS = -lm -lcs3050 -L.

%.o : %.c 
	@echo Compiling $^ ...
	@$(CC) $(CFLAGS) $^

mysort : main.o sort.o
	@echo Linking $@ ...
	@$(CC) $^ $(LDFLAGS) -o $@
	@echo Done!

libcs3050.a : cs3050.o
	@echo Building library $@
	@ar -crs libcs3050.a cs3050.o

clean : 
	@rm -rf *.o
	@rm -rf mysort
	@echo All Clean!
