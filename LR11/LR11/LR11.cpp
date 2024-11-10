#include <iostream>

void main()
{
	// 15 / (x^2 + 3.7) < 0.1

	float A = 15, B = 3.7, C = 0.1;
	long N = 0;
	float Y = 0;

	__asm {
		step: 
		finit
		inc N
		fild N
		fimul N

		fld B
		fadd
		
		fld A
		fdivr

		fcom C
		fstsw ax
		sahf
		ja step

		fstp Y
	}

	std::cout << N << std::endl;
	std::cout << Y << std::endl;
}
