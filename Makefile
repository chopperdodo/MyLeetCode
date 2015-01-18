CXX=g++

CPPFLAGS =  -I. -Ibase
CPPFLAGS += -I101_125 -I151_175

SRC = base/BaseUse.cpp base/main.cpp
SRC += 101_125/Flattern_Binary_Tree_to_Linked_List.cpp
SRC += 151_175/Dungeon_Game_P174.cpp

OBJS=$(SRC:.cpp=.o)

all: lc clear_o

lc: $(OBJS)
	$(CXX) $(CPPFLAGS) -o $@ $^

clear_o:
	rm -f $(OBJS)

clean:
	rm -f $(OBJS) lc
