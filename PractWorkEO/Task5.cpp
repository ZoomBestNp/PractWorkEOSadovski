#include <iostream>
using namespace std;

double func5(int x) {
    double result = 0.0; 
    double temp_x2;      
    double temp_n2;      

    _asm {
        fldz
        mov ecx, 1 

        loop_start:
        cmp ecx, x
            jg loop_end

           
            mov eax, x
            fld qword ptr[eax]
            fmul st(0), st(0) // x ^ 2
            fstp qword ptr[temp_x2] _

            
            mov eax, ecx
            fld dword ptr[eax]
            fmul st(0), st(0)   // n ^ 2
            fstp qword ptr[temp_n2]

           
            fld qword ptr[temp_x2]
            fld qword ptr[temp_n2]
            fadd //x ^ 2 + n ^ 2

          
            fadd st(1), st(0)
            fstp st(0)

            inc ecx
            jmp loop_start

            loop_end :
        fstp qword ptr[result]
    }
    return result;
}
