#include <iostream>
using namespace std;

double func4(double x) {
    double result; 
    const double log2_e = 1.44;

    _asm {
        fld qword ptr[x]
        fld1
        fyl2x

        fst qword ptr[result]

        fld qword ptr[x]
        fldln2
        fdiv

        fld qword ptr[result]
        fadd    // log2(x) + ln(x)

        fstp qword ptr[result]
    }
    return result;
}
