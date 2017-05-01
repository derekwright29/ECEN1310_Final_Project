CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -pedantic -g

PROG = run_crypto
SRC = run_crypto.c crypto.c caesar.c vigenere.c affine.c stream.c
HDR = crypto.h
OBJ = $(SRC:.c=.o)

$(PROG): $(OBJ)
$(OBJ): $(HDR)
TAGS: $(SRC) $(HDR)
	etags $^
tags: $(SRC) $(HDR)
	ctags $^
.PHONY: clean
clean:
	$(RM) $(PROG) $(OBJ)
