#include <iostream>

void main()
{
	long N = 0;
	long S = 0;

	// n^2 + 6n + 28

	_asm {
		m1 : inc N
		mov EAX, N
		imul N
		add S, EAX
		mov EAX, 6
		mul N
		add EAX, 28
		add S, EAX
		cmp S, 1000
		jc m1
	}

	std::cout << N << std::endl;
	std::cout << S << std::endl;
}
