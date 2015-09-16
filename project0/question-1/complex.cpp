#include "complex.h"
#include <stdio.h>
#include <stdlib.h>

Complex::Complex()
{
	this->setReal(0);
	this->setImaginary_p(0);
}

Complex::Complex(double real, double imaginary_p)
{
	this->setReal(real);
	this->setImaginary_p(imaginary_p);
}

double Complex::getReal()
{
	return real;
}

void Complex::setReal(double real)
{
	this->real = real;
}

double Complex::getImaginary_p()
{
	return imaginary_p;
}

void Complex::setImaginary_p(double imaginary_p)
{
	this->imaginary_p = imaginary_p;
}

Complex Complex::operator+(Complex &lh)
{
	return Complex(this->getReal()+lh.getReal(), this->getImaginary_p()+lh.getImaginary_p());
}

Complex Complex::operator-(Complex &lh)
{
	return Complex(this->getReal()-lh.getReal(), this->getImaginary_p()-lh.getImaginary_p());
}

void Complex::printVal()
{
	printf("%lf + %lfi\n", getReal(), getImaginary_p());
}
