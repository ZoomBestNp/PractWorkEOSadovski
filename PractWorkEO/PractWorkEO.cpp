#include <iostream>
using namespace std;

double func1(double x) {
    double result;       
    float temp2 = 4.0f;  
    float temp3 = 3.0f;  

    __asm {
        
        fld qword ptr[x]

        
        fld st(0)
        fadd st(0), st(0) // Умножение x на 2

        
        fld dword ptr[temp2] 
        fadd st(1), st(0) //2x + 4
        fstp st(0) 

       
        fsqrt 

        
        fld dword ptr[temp3] 
        fdiv st(1), st(0) //sqrt(2x + 4) / 3
        fstp st(0)

   
        fstp qword ptr[result]
    }
    return result;
}

int main() {
    setlocale(0, "ru");
    double x = 52.0;
    cout << "Результат (" << x << ") = " << func1(x) <<endl;

   

    return 0;
}