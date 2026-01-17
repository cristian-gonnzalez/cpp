#include <iostream>


int point(int x, int y, int z=0)
{
	std::cout << x << std::endl;
	std::cout << y << std::endl;
	std::cout << z << std::endl;
}

/*
int point(int x=1, int y=2, int z=0);
int point(int x, int y=2, int z=0);
int point(int x, int y, int z=0);


// ERROR: only can assign defuault argument at the trailing arguments
int point(int x, int y=0, int z);
int point(int x=0, int y=0, int z);
int point(int x=0, int y, int z);

*/

int main()
{
	point(2, 7);
}