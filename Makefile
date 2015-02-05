CXX=g++

CPPFLAGS = -std=c++0x -I. -Ibase -g
CPPFLAGS += -I001_050 -I101_125 -I151_175

SRC = base/BaseUse.cpp base/main.cpp

SRC += 001_050/Two_Sum_P001.cpp
SRC += 001_050/Add_Two_Numbers_P002.cpp
SRC += 001_050/Longest_Substring_Without_Repeating_Characters_P003.cpp
SRC += 001_050/Median_Of_Two_Sorted_Arrays_P004.cpp
SRC += 001_050/Longest_Palindromic_Substring_P005.cpp

SRC += 101_125/Flattern_Binary_Tree_to_Linked_List_P114.cpp

SRC += 151_175/Dungeon_Game_P174.cpp


OBJS=$(SRC:.cpp=.o)

all: lc clear_o

lc: $(OBJS)
	$(CXX) ${DFLAGS} $(CPPFLAGS) -o $@ $^

clear_o:
	rm -f $(OBJS)

clean:
	rm -f $(OBJS) lc
