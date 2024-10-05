#include <iostream>

int main()
{
    double N = 2;
    double Y = 0;
	double A = 2.5;
	double B = 5.3;
	double C = 21;

	// 2,5n^2 + 5.3n - 21

	__asm {
		finit
		fld N
		fmul N
		fmul A
		
		fld N
		fmul B
		fadd

		fld C
		fsub

		fstp Y
	}

	std::cout << Y << std::endl;
}