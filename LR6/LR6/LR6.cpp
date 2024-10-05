#include <iostream>

void main()
{
	long X = 3;				
	long REZ[7];

	_asm {
		lea EBX, REZ
		mov ECX, 7
		m1 : mov EAX, 2
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
		add EBX, 4
		add X, 3
		loop m1
	}

	for (size_t i = 0; i < 7; i++)
	{
		std::cout << REZ[i] << std::endl;
	}
}
