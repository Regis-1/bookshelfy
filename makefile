CXX=g++
LIBFLAGS=-lncurses
CXXFLAGS=-Wall -pedantic

OBJDIR=obj
SRCDIR=src
INCDIR=include

TARGET=bookshelfy
CORES=main Bookshelf AppManager IWindow InputWindow DialogWindow
SRCS=$(patsubst %,$(SRCDIR)/%.cpp,$(CORES))
OBJS=$(patsubst %,$(OBJDIR)/%.o,$(CORES))

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJS) $(LIBFLAGS)

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp 
	$(CXX) $(CXXFLAGS) -c $< -o $@ -I/$(INCDIR) $(LIBFLAGS)

.PHONY: clean

clean:
	rm -rf $(OBJDIR)/*.o $(TARGET)
