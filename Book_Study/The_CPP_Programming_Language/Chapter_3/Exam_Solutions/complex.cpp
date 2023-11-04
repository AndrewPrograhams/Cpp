#include "complex.h"
#include <stdexcept>
// convoluted implementation
// complex& complex::operator*=(complex v)
// {
//     return v = complex{(re*v.re - im*v.im), (re*v.im + im*v.re)};
// }

// clearer implementation
complex& complex::operator*=(complex v)
{
    double new_re = re*v.re - im*v.im;
    double new_im = re*v.im + im*v.re;
    re = new_re;
    im = new_im;
    return *this;
}

complex& complex::operator/=(complex v)
{
    if(v.re == 0 && v.im == 0)
        throw std::runtime_error("Divide by zero in operator/=");
    //(a * c - b * d) / (c^2 + d^2) + (b * c + a * d) / (c^2 + d^2)i
    double denom = v.re*v.re + v.im*v.im;
    double new_re = (re*v.re - im*v.im) / denom;
    double new_im = (im * v.re + re * v.im) / denom;
    re = new_re;
    im = new_im;
    return *this;

}

