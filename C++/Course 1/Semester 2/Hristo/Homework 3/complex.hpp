#pragma once

class Complex
{
public:
    void create();
    void addition(Complex first, Complex second);
    void subtraction(Complex first, Complex second);
    void multiplication(Complex first, Complex second);
    void print();

private:
    int getA();
    int getB();

    void setA();
    void setB();

    int a = 0;
    int b = 0;
};