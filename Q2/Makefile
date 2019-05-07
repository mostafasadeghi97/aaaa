CXX = g++
CXXFLAGS = -std=c++17 -Wall -c
LXXFLAGS = -std=c++17
OBJECTS = q1.o Vector.o
TARGET = q1


$(TARGET): $(OBJECTS)
	$(CXX) $(LXXFLAGS) $(OBJECTS) -o $(TARGET)
main.o: q1.cpp
	$(CXX) $(CXXFLAGS) q3.cpp
Vector.o: Vector.cpp Vector.h
	$(CXX) $(CXXFLAGS) Vector.cpp
clean:
	rm -f $(TARGET) $(OBJECTS)