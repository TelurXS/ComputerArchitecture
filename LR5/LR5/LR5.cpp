#include <iostream>

int main()		
{
	long X = 3;
	long REZ;

	_asm {

		lea EBX, REZ
		mov EAX, 2
		imul X
		imul X
		add EAX, 15
		mov EDI, EAX

		mov EAX, 7500
		cdq

		div EDI
		shr EDI, 1
		cmp EDI, EDX
		adc EAX, 0
		mov dword ptr[EBX], EAX
	}

	std::cout << REZ;
}
