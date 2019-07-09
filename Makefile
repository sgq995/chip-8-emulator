CC      = gcc
CFLAGS  = -std=c11 -Wall -Wextra -Wpedantic -Iinclude
LDFLAGS = -lSDL2

SRCDIR = src
INCDIR = include
OBJDIR = obj
BINDIR = bin

BINFILE = chip8

SRC = $(wildcard $(SRCDIR)/*.c)
OBJ = $(patsubst $(SRCDIR)/%.c,$(OBJDIR)/%.o,$(SRC))
BIN = $(BINDIR)/$(BINFILE)

all: $(BIN)

$(BIN): $(OBJ)
	@echo Building binary file $@
	@$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $^
	@echo $@ [OK]

$(OBJ): | $(OBJDIR)

$(OBJDIR):
	@mkdir $@

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@echo Building C object $@
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo $@ [OK]

.PHONY: clean
clean:
	@-rm $(BIN) $(OBJ)
