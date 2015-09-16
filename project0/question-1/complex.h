#ifndef CSC330_COMPLEX
#define CSC330_COMPLEX

class Complex
{
	double real;
	double imaginary_p;

	public:
	Complex();
	Complex(double real, double imaginary_p);

	double getReal();
	void setReal(double real);

	double getImaginary_p();
	void setImaginary_p(double imag);

	Complex operator+(Complex &lh);
	Complex operator-(Complex &lh);

	void printVal();
};

#endif
