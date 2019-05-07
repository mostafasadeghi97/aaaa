CXX = g++
CXXFLAGS = -std=c++17 -Wall -c
LXXFLAGS = -std=c++17
OBJECTS = q1.o Shape.o TwoDimensionalShape.o ThreeDimensionalShape.o circle.o square.o cube.o sphere.o
TARGET = q1


$(TARGET): $(OBJECTS)
	$(CXX) $(LXXFLAGS) $(OBJECTS) -o $(TARGET)
main.o: q1.cpp
	$(CXX) $(CXXFLAGS) q1.cpp
Shape.o: Shape.cpp Shape.h
	$(CXX) $(CXXFLAGS) Shape.cpp
TwoDimensionalShape.o: TwoDimensionalShape.cpp TwoDimensionalShape.h
	$(CXX) $(CXXFLAGS) TwoDimensionalShape.cpp
ThreeDimensionalShape.o: ThreeDimensionalShape.cpp ThreeDimensionalShape.h
	$(CXX) $(CXXFLAGS) ThreeDimensionalShape.cpp
circle.o: circle.cpp circle.h
	$(CXX) $(CXXFLAGS) circle.cpp
cube.o: cube.cpp cube.h
	$(CXX) $(CXXFLAGS) cube.cpp
square.o: square.cpp square.h
	$(CXX) $(CXXFLAGS) square.cpp
sphere.o: sphere.cpp sphere.h
	$(CXX) $(CXXFLAGS) sphere.cpp

clean:
	rm -f $(TARGET) $(OBJECTS)