#include <iostream>

int main() {
    double A = 2;
    double B = 2;
    double Y = 0;
    
    double TMP = 0;

    double C1 = 0.5;
    double C2 = 3;
    double C3 = 4;

    double RTD = 180 / 3.14;
    double DEG = 0;

    // y = 1/2 arccosec (3a^2 + 4b) = 1/2 arcsin (1 / 3a^2 + 4b)
    // arcsin(x) = arctan(x / sqrt(1 - x^2) )

    __asm {
        finit

        fld A
        fmul A
        fmul C2

        fld B
        fmul C3
        fadd

        fld1
        fdivr

        fstp TMP // 1 / 3a^2 + 4b

        fld1
        fld TMP
        fmul TMP
        fsub
        fsqrt

        fld TMP
        fdivr
        fld1
        fpatan

        fmul C1

        fstp Y

        fld Y
        fmul RTD
        fstp DEG
    }

    std::cout << Y << std::endl;
    std::cout << DEG << std::endl;

    return 0;
}