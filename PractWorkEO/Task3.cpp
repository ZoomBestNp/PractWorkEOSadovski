#include <iostream>
using namespace std;

double func3(double x) {
    double result;
    const double six = 6.0;
    const double five = 5.0;
    const double seven = 7.0;

    __asm {
       
        fld qword ptr[x]
        fcos    //cos(x)
        fld st(0)
        fmul    //cos ^ 2(x)

        fld qword ptr[six]
        fmul        //6 * cos ^ 2(x)
        fstp st(1)

        fld qword ptr[x]
        fsin
        fld qword ptr[five]
        fmul    //5 * sin(x)

        fadd st(1), st(0)
        fstp st(0)

        fld qword ptr[seven]
        fsub

        fstp qword ptr[result]
    }
    return result;
}

