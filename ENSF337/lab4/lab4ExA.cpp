// ENSF 337 Spring 2024 - Lab 4 exercise A

#include "cplx.h"

void global_print(const Cplx& n);


int main(void)
{
    Cplx num1;
    
    num1.setRealPart(666);
    
    Cplx num2(34, 5);

    num1.setImaginaryPart(500);
    
    return 0;
}

