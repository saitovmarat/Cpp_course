#include <iostream>


int main(int argc, char** argv)
{
	int i[][2] = { { 1, 2 }, { 3, 4 }, { 5, 6 } };
	int* j = (int*) i;
	using matrix = int(*)[2];
	matrix k = (matrix) i;
	// ??
	std::cout << j[6] << "=> " << k[0]<< std::endl;
	return 0;
}
