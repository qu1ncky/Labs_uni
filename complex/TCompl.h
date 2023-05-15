#ifndef TCOMPL_H
#define TCOMPL_H

#include <iostream>
#include <ostream>
#include <istream>
#include <exception>

class TCompl {
public:
    double Re;
    double Im;

    TCompl(double re, double im);
    TCompl();
    TCompl(const TCompl& ob);
    TCompl(double x);
    ~TCompl();

    TCompl operator+(const TCompl& op2) const;
    TCompl operator-(const TCompl& op2) const;
    TCompl operator*(const TCompl& op2) const;
    TCompl operator/(const TCompl& op2) const;

    TCompl& operator=(const TCompl& op2);
    TCompl& operator+=(const TCompl& op2);
    TCompl& operator-=(const TCompl& op2);
    TCompl& operator*=(const TCompl& op2);
    TCompl& operator/=(const TCompl& op2);

    bool operator==(const TCompl& op2) const;
    void print() const;
    TCompl& input();
};

TCompl operator+(double op1, const TCompl& op2);

#endif