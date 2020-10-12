#include "6.2 Header.hpp"

int gcd(int a, int b)
{ 
	return b != 0 ? gcd(b, a % b) : a;
}

Fraction::Fraction() : numerator(0), denominator(1U) {}

Fraction::Fraction(int n, std::size_t d) : numerator(n), denominator(d) { reduction(); }

Fraction::Fraction(const Fraction& other) : numerator(other.numerator), denominator(other.denominator) { reduction(); }

std::ostream& operator<<(std::ostream& stream, const Fraction& fraction)
{
	if (fraction.denominator == 0)
	{
		std::cerr << "undefined";
	}
	else
	{
		fraction.denominator == 1 ? std::cout << fraction.numerator
			: std::cout << fraction.numerator << '/' << fraction.denominator;
	}
	return stream;	
}

std::istream& operator>>(std::istream& stream, Fraction& fraction)
{
	std::cin >> fraction.numerator >> fraction.denominator;
	fraction.reduction();
	return stream;
}

void Fraction::reduction()
{
	int div = 1;
	numerator ? div = gcd(std::abs(numerator), static_cast <int> (denominator)) : div = denominator;
	gcd(std::abs(numerator), static_cast <int> (denominator));
	numerator = numerator / div;
	denominator = denominator / div;
}

Fraction::operator int() const
{
	return numerator / denominator;
}

Fraction::operator double() const
{
	return static_cast <double> (numerator) / static_cast <double> (denominator);
}

Fraction operator+(const Fraction& lhs, const Fraction& rhs)
{
	Fraction fr;
	fr.numerator = lhs.numerator * rhs.denominator + lhs.denominator * rhs.numerator;
	fr.denominator = lhs.denominator * rhs.denominator;
	fr.reduction();
	return fr;
}

Fraction operator-(const Fraction& lhs, const Fraction& rhs)
{
	Fraction fr;
	fr.numerator = lhs.numerator * rhs.denominator - lhs.denominator * rhs.numerator;
	fr.denominator = lhs.denominator * rhs.denominator;
	fr.reduction();
	return fr;
}

Fraction operator*(const Fraction& lhs, const Fraction& rhs)
{
	Fraction fr;
	fr.numerator = lhs.numerator * rhs.numerator;
	fr.denominator = lhs.denominator * rhs.denominator;
	fr.reduction();
	return fr;
}

Fraction operator/(const Fraction& lhs, const Fraction& rhs)
{
	Fraction fr;
	if (rhs.numerator * rhs.denominator)
	{
		fr.numerator = lhs.numerator * rhs.denominator;
		fr.denominator = lhs.denominator * rhs.numerator;
		fr.reduction();
	}
	else
	{
		fr.numerator = 0;
		fr.denominator = 0;
	}
	return fr;
}

Fraction& Fraction::operator+=(const Fraction& other)
{
	*this = *this + other;
	return *this;
}

Fraction& Fraction::operator-=(const Fraction& other)
{
	*this = *this - other;
	return *this;
}

Fraction& Fraction::operator*=(const Fraction& other)
{
	*this = *this * other;
	return *this;
}

Fraction& Fraction::operator/=(const Fraction& other)
{
	*this = *this / other;
	return *this;
}

Fraction& Fraction::operator++()
{
	*this += 1;
	return *this;
}

Fraction& Fraction::operator--()
{
	*this -= 1;
	return *this;
}

Fraction Fraction::operator++(int)
{
	Fraction copy (*this);
	++(*this);
	return copy;
}

Fraction Fraction::operator--(int)
{
	Fraction copy(*this);
	--(*this);
	return copy;
}

bool operator==(const Fraction& lhs, const Fraction& rhs)
{
	return (lhs.numerator * rhs.denominator == rhs.numerator * lhs.denominator);
}

bool operator!=(const Fraction& lhs, const Fraction& rhs)
{
	return (lhs.numerator * rhs.denominator != rhs.numerator * lhs.denominator);
}

bool operator>=(const Fraction& lhs, const Fraction& rhs)
{
	return (lhs.numerator * rhs.denominator >= rhs.numerator * lhs.denominator);
}

bool operator<=(const Fraction& lhs, const Fraction& rhs)
{
	return (lhs.numerator * rhs.denominator <= rhs.numerator * lhs.denominator);
}

bool operator<(const Fraction& lhs, const Fraction& rhs)
{
	return (lhs.numerator * rhs.denominator < rhs.numerator * lhs.denominator);
}

bool operator>(const Fraction& lhs, const Fraction& rhs)
{
	return (lhs.numerator * rhs.denominator > rhs.numerator * lhs.denominator);
}

int Fraction::get_numerator()
{
	return numerator;
}

std::size_t Fraction::get_denominator()
{
	return denominator;
}