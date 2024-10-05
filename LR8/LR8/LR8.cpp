#include <iostream>

void main() {

	int x[10] = { 7, -23, 56, -33, 0, 15, -11, 74, 31, -12 };
	int CNT = 0;

	_asm {
		lea EBX, x
		mov ECX, 10
		mov ESI, 0

		loop_start:
			mov EAX, [EBX]
			cmp EAX, 0
			jl is_negative
			add EBX, 4
			loop loop_start
			jmp end_loop

		is_negative:
			inc ESI
			add EBX, 4
			loop loop_start

		end_loop:
			mov CNT, ESI
	}

	std::cout << CNT << std::endl;

}
