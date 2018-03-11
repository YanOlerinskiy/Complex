#include <iostream>
#include <vector>
#include "complex.h"
#include <cmath>

using namespace std;

Complex::Complex() :
    real(0.0), imag(0.0)
{
}

Complex::Complex(double real, double imag) :
    real(real), imag(imag)
{
}

Complex operator+ (const Complex &a, const Complex &b) {
    Complex sum;
    sum.real = a.real + b.real;
    sum.imag = a.imag + b.imag;
    return sum;
}

Complex operator- (const Complex &a, const Complex &b) {
    Complex dif;
    dif.real = a.real - b.real;
    dif.imag = a.imag - b.imag;
    return dif;
}


ostream& operator<<(ostream &os, const Complex &a)
{
    std::string real_part;
    std::string imag_part;

    if (fabs(a.real) > EPS) {
        real_part = to_string(a.real);
    }

    // a.imag == 1?
    if (fabs(a.imag - 1) < EPS) {
        imag_part = "i";
    } else if (fabs(a.imag + 1) < EPS) {
            imag_part = "-i";
    } else if(fabs(a.imag) > EPS) {
        imag_part = to_string(a.imag) + "i";
    }
    bool flag = 1;
    if (real_part.empty() or imag_part.empty()) {
        flag = 0;
    }
    os << real_part;
    if (flag and a.imag > 0) {
        os << '+';
    }
    os << imag_part;
    return os;
}

Complex &Complex::operator+=(const Complex &other)
{
    real += other.c_real();
    imag += other.c_imag();
    return *this;
}

Complex &Complex::operator-=(const Complex &other)
{
    real -= other.c_real();
    imag -= other.c_imag();
    return *this;
}

Complex &Complex::operator*=(const Complex &other)
{
    double j = real*other.real + imag*other.imag;
    double k = real*other.imag + imag*other.real;
    real = j;
    imag = k;
    return *this;
}

Complex &Complex::operator/=(const Complex &other)
{
    double a = (real*other.real + imag*other.imag)/
            (other.real*other.real + other.imag*other.imag);
    double b = (imag*other.real - real*other.imag)/(other.real*other.real + other.imag*other.imag);
    real = a;
    imag = b;
    return *this;
}


bool Complex::operator==(const Complex &other) const
{
    if (fabs(real - other.real) < EPS and fabs(imag - other.imag) < EPS) {
        return true;
    } else {
        return false;
    }
}

bool Complex::operator!=(const Complex &other) const
{
    return !(*this == other);
}

Complex operator*(const Complex &a, const Complex &b)
{
    Complex mul;
    mul.real = (a.real * b.real - a.imag * b.imag);
    mul.imag = (a.real * b.imag + a.imag * b.real);
    return mul;
}

Complex operator/(const Complex &a, const Complex &b)
{
    Complex div;
    double l = (b.real*b.real + b.imag*b.imag);
    double c = (a.real*b.real + a.imag*b.imag)/l;
    double d = (a.imag*b.real - a.real*b.imag)/l;
    div.real = c;
    div.imag = d;
    return div;
}

double fabs(const Complex &c)
{
    double a = c.c_real();
    double b = c.c_imag();
    return sqrt(a*a + b*b);
}

Complex Complex::conjugate() const
{
    Complex res(real, -imag);
    return res;
}

Complex pow(const Complex &z, int n)
{
    double r = fabs(z);
    double rp = pow(r, n);
    double phi = atan2(z.imag, z.real);
    double cn = cos(n*phi) * rp;
    double sn = sin(n*phi) * rp;
    return Complex(cn, sn);
}

Complex polar(double r, double phi)
{
    double a = cos(phi) * r;
    double b = sin(phi) * r;
    Complex k(a,b);
    return k;
}


vector<Complex> Complex::roots(int n)
{
    double phi = atan2(imag, real);
    double r = fabs(*this);
    double pi = M_PI;
    vector<Complex> roots;
    Complex b;
    for (int k = 0; k < n; k++) {
        b.real = cos((phi + 2*pi*k)/n);
        b.imag = sin((phi + 2*pi*k)/n);
        b = b*pow(r, 1/n);
        roots.push_back(b);
    }
    return roots;
}

