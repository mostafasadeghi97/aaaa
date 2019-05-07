CXX = g++
CXXFLAGS = -std=c++17 -Wall -c
LXXFLAGS = -std=c++17
OBJECTS = q1.o Human.o Oracle.o
TARGET = q1


$(TARGET): $(OBJECTS)
	$(CXX) $(LXXFLAGS) $(OBJECTS) -o $(TARGET)
main.o: q1.cpp
	$(CXX) $(CXXFLAGS) q1.cpp
Human.o: Human.cpp Human.h
	$(CXX) $(CXXFLAGS) Human.cpp
Oracle.o: Oracle.cpp Oracle.h
	$(CXX) $(CXXFLAGS) Oracle.cpp
clean:
	rm -f $(TARGET) $(OBJECTS)