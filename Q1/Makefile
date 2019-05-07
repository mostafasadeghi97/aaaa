CXX = g++
CXXFLAGS = -std=c++17 -Wall -c
LXXFLAGS = -std=c++17
OBJECTS = q1.o MaxHeap.o
TARGET = q1


$(TARGET): $(OBJECTS)
	$(CXX) $(LXXFLAGS) $(OBJECTS) -o $(TARGET)
main.o: q1.cpp
	$(CXX) $(CXXFLAGS) q1.cpp
MaxHeap.o: MaxHeap.cpp MaxHeap.h
	$(CXX) $(CXXFLAGS) MaxHeap.cpp
clean:
	rm -f $(TARGET) $(OBJECTS)