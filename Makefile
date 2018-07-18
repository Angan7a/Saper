CXX = clang++
STD = 
#-std=c++14
CXXFLAGS = -Wall -Wpedantic -Wextra
SRCS = $(wildcard *.cpp)
OBJS = $(SRCS:.cpp=.o)
TARGET = saper.out

.PHONY: all
all:$(TARGET)

%.o: %.cpp %.hpp 
	$(CXX) $(CXXFLAGS) $(STD) -c -o $@ $<

$(TARGET): $(OBJS)
	$(CXX) $^ -o $@ 

.PHONY: clean
clean:
	rm $(TARGET) $(OBJS)
