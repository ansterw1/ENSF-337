// ENSF 337 Spring 2024 - Exercise B Lab 4
// File: lab4ExB.cpp


#include "lab4String.h"

int main()
{
    // There are unsed varibales in this code, you may ignore the
    // compiler warnings for these cases, as we would rather to keep this exercise
    // relatively simple and short.
    
    Lab7String a("Hi");
    Lab7String *p;
    
    {
        Lab7String d[2];
        Lab7String b("red");
        Lab7String *c = new Lab7String("glue");
        Lab7String *g = new Lab7String ("Blue");
        p = g;
        delete c;
    }
    
    delete p;

    return 0;
}

