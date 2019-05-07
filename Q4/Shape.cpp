#include "Shape.h"
#include <iostream>

std::ostream& operator << (std::ostream& out,Shape& instance) {
    // Forward the call to a virtual member function
    return instance.print(out);
}