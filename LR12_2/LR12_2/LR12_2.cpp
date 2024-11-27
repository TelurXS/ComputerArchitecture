#include <iostream>
#include <cmath>

double custom_pow(double base, int exponent) {
    double result;
    int abs_exp = std::abs(exponent);

    __asm {
        fld1
        fstp result

        mov eax, exponent
        test eax, eax
        jz done

        fld base

        mov ecx, abs_exp

        power_loop :
            fld result      
            fmul ST, ST(1) 
            fstp result 

            dec ecx
            jnz power_loop

            mov eax, exponent
            test eax, eax
            jns done

            fld1
            fdiv result
            fstp result

        done :
    }

    return result;
}

int main() {
    std::cout << "2^3 = " << custom_pow(2, 3) << std::endl;  
    std::cout << "2^0 = " << custom_pow(2, 0) << std::endl;  
    std::cout << "2^-2 = " << custom_pow(2, -2) << std::endl;
    std::cout << "5^2 = " << custom_pow(5, 2) << std::endl;  
    std::cout << "3^4 = " << custom_pow(3, 4) << std::endl;  
    std::cout << "10^1 = " << custom_pow(10, 1) << std::endl;
    std::cout << "7^3 = " << custom_pow(7, 3) << std::endl;  

    return 0;
}