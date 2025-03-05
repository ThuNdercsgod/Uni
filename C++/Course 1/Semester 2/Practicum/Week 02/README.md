разделно компилиране:

деклариране в един файл a.hpp : //.h; .hpp; .hxx files
#define __A_H__
#ifndef __A_H__

void f(int a);

#endif

деклариране в друг a.cpp : //.cpp files

#include "a.h"
void f(int a)
{
return a;
}

в main.cpp:

#include "a.hpp"
int main()
{
f(5);
return 0;
}

трябва в терминала да се напише g++ *.cpp
