CC=clang++
CFLAGS=-Wall -Wextra 
BIN=app

OBJDIR=build
SRCDIR=src
INCLDIR=include

SRCS=$(wildcard $(SRCDIR)/*.cpp)
OBJS=$(patsubst $(SRCDIR)/%.cpp, $(OBJDIR)/%.o, $(SRCS))
LIBS=-lraylib

default: $(BIN)
	
$(BIN): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -I$(INCLDIR) -o $@ $(LIBS)

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	$(CC) $(CFLAGS) -c -I$(INCLDIR) $< -o $@

clean:
	rm $(OBJDIR)/* $(BIN)


