#include <iostream>

#include "circle.h"
#include "square.h"
#include "sphere.h"
#include "cube.h"
#include "Shape.h"

using std::cout;

int main()
{
	Square sqr( 12.0, 2.0, 2.0 );
	Sphere sph( 5.0, 1.5, 4.5,0.0 );
	Cube cub( 2.2 ,0.0,0.0,0.0);
	Circle cir( 3.5, 6, 9 );
	
	Shape *ptr[ 4 ] = { &cir, &sqr, &sph, &cub };

	for ( int x = 0; x < 4; ++x ){
		std::cout << *(ptr[x]) << '\n';
	}
	// (ptr[0])->print();
	// std::cout <<  << std::endl;
	return 0;
}