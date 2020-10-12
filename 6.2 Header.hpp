#pragma once

#include <iostream>

class Fraction
{
public:
	Fraction();

	Fraction(int n, std::size_t d = 1U);

	~Fraction() = default;

	Fraction(const Fraction& other);
	Fraction(Fraction&& other) = default;

	Fraction& operator=(Fraction& other) = default;
	Fraction& operator=(Fraction&& other) = default;

	void reduction();
	
	explicit operator int() const;

	explicit operator double() const;

	friend std::ostream& operator<<(std::ostream& stream, const Fraction& fraction);

	friend std::istream& operator>>(std::istream& stream, Fraction& fraction);

	friend Fraction operator+(const Fraction& lhs, const Fraction& rhs);
	friend Fraction operator-(const Fraction& lhs, const Fraction& rhs);
	friend Fraction operator*(const Fraction& lhs, const Fraction& rhs);
	friend Fraction operator/(const Fraction& lhs, const Fraction& rhs);

	Fraction & operator+=(const Fraction& other);
	Fraction & operator-=(const Fraction& other);
	Fraction & operator*=(const Fraction& other);
	Fraction & operator/=(const Fraction& other);

	Fraction & operator++();
	Fraction & operator--();

	Fraction  operator++(int);
	Fraction  operator--(int);
	

	friend bool operator==(const Fraction& lhs, const Fraction& rhs);
	friend bool operator!=(const Fraction& lhs, const Fraction& rhs);
	friend bool operator>=(const Fraction& lhs, const Fraction& rhs);
	friend bool operator<=(const Fraction& lhs, const Fraction& rhs);
	friend bool operator<(const Fraction& lhs, const Fraction& rhs);
	friend bool operator>(const Fraction& lhs, const Fraction& rhs);


	int get_numerator();
	std::size_t get_denominator();


private:
	int numerator;
	std::size_t denominator;
};

int gcd(int a, int b);