#include <iostream>
using namespace std;

double func2(double x) {
    double result;
    const double pi = 3.1415;
    const double eight = 8.0;
    _asm {
       
        fld qword ptr[x]
        fsqrt   //sqrt(x)

        fld qword ptr[pi]
        fmul    //π * sqrt(x)
        fsin

        fld1
        fld qword ptr[eight]
        fadd        //sin(π * sqrt(x)) + 8

        fstp qword ptr[result]
    }
    return result;
}
