#ifndef COMPLEX_H
#define COMPLEX_H

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

const double EPS = 0.0000001;

class Complex
{
public:
    Complex();
    Complex(double real, double imag = 0.0);
    double c_real() const { return real; }
    double c_imag() const { return imag; }
    vector<Complex> roots(int n);
    friend Complex operator+ (const Complex &a, const Complex &b);
    friend Complex operator- (const Complex &a, const Complex &b);
    friend Complex operator* (const Complex &a, const Complex &b);
    friend Complex operator/ (const Complex &a, const Complex &b);
    friend ostream& operator<< (ostream &os, const Complex &a);
    friend istream& operator>> (istream &is, const Complex &a);

    friend Complex pow(const Complex &z, int n);
    friend vector<Complex> roots(Complex &a, double n);

    Complex& operator+= (const Complex &other);
    Complex& operator-= (const Complex &other);
    Complex& operator*= (const Complex &other);
    Complex& operator/= (const Complex &other);
    bool operator== (const Complex &other) const;
    bool operator!= (const Complex &other) const;

    Complex conjugate() const;
protected:
    double real;
    double imag;
};

Complex polar(double r, double phi);
double fabs(const Complex &c);

#endif // COMPLEX_H
