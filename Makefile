CPP = g++
CPPFLAGS = -std=c++11 -c -g -Wall
GTKMM_FLAG = `pkg-config gtkmm-3.0 --cflags --libs`
LDFLAGS = -g

EXE = auto
SRCDIR := ./src
OBJDIR := ./obj
SRCS := $(wildcard $(SRCDIR)/*.cpp)
OBJS := $(patsubst $(SRCDIR)/%.cpp, $(OBJDIR)/%.o, $(SRCS)) $(OBJDIR)/main.o

all: $(EXE)

$(EXE): $(OBJS)
	$(CPP) $(LDFLAGS) -o $@ $^ $(GTKMM_FLAG)
	
$(OBJDIR)/main.o: ./main.cpp
	$(CPP) $(CPPFLAGS) -o $@ $^ $(GTKMM_FLAG)

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	$(CPP) $(CPPFLAGS) -o $@ $< $(GTKMM_FLAG)

clean:
	rm -rf $(OBJDIR)/*.o $(EXE) 
