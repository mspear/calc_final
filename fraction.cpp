#include "fraction.h"
#include <ostream>

int gcd(int x, int y) {
  if (y==0) 
    return x;

  return gcd(y, x%y);
}

Fraction::Fraction() {
	top = 0;
	bottom = 1;
}

Fraction::Fraction(int numerator){
	top = numerator;
	bottom = 1;
}

Fraction::Fraction(int numerator, int denominator) {
	int divisor = gcd(numerator, denominator);
	top = numerator / divisor;
	bottom = denominator / divisor;
}

int Fraction::numerator() const{
	return top;
}
int Fraction::denominator() const{
	return bottom;
}
double Fraction::asDouble() const{
	return (double)top/(double)bottom;
}
Fraction Fraction::add(const Fraction& other) const{
	int newTop = top * other.denominator() + other.numerator() * bottom;
	int newBottom = bottom * other.denominator();
	return Fraction(newTop, newBottom);
}
Fraction Fraction::subtract(const Fraction& other) const{
	int newTop = top * other.denominator() - other.numerator() * bottom;
	int newBottom = bottom * other.denominator();
	return Fraction(newTop, newBottom);
}
Fraction Fraction::multiply(const Fraction& other) const{
	int newTop = top * other.numerator();
	int newBottom = bottom * other.denominator();
	return Fraction(newTop, newBottom);
}
Fraction Fraction::divide(const Fraction& other) const{
	int newTop = top * other.denominator();
	int newBottom = bottom * other.numerator();
	return Fraction(newTop, newBottom);
}


Fraction operator+(const Fraction& a, const Fraction& b){
	return a.add(b);
}
Fraction operator-(const Fraction& a, const Fraction& b){
	return a.subtract(b);
}
Fraction operator*(const Fraction& a, const Fraction& b){
	return a.multiply(b);
}
Fraction operator/(const Fraction& a, const Fraction& b){
	return a.divide(b);
}
ostream& operator<<(ostream& out, const Fraction& f){
	if (f.denominator() == 1)
		out << f.numerator();
	else
		out << f.numerator() << "/" << f.denominator();
	return out;
}