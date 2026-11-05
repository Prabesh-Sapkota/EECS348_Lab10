CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra

TARGET = lab10
OBJS = main.cpp Matrix.cpp

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

clean:
	rm -f $(TARGET) *.o