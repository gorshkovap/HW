#pragma once

#include <iostream>

namespace frac
{
	class Fraction
	{
	public:
		Fraction();

		Fraction(int n, int d = 1);

		~Fraction() = default;

		Fraction(const Fraction& other) = default;
		Fraction(Fraction&& other) = default;

		Fraction& operator=(Fraction& other) = default;
		Fraction& operator=(Fraction&& other) = default;

		explicit operator int() const;

		explicit operator double() const;

	private:
		void reduction();

	public:
		friend Fraction reverse(Fraction& fr);
		friend Fraction minus(Fraction& fr);

		friend std::ostream& operator<<(std::ostream& stream, const Fraction& fraction);

		friend std::istream& operator>>(std::istream& stream, Fraction& fraction);

		Fraction& operator+=(const Fraction& other);
		Fraction& operator-=(const Fraction& other);
		Fraction& operator*=(const Fraction& other);
		Fraction& operator/=(const Fraction& other);

		Fraction& operator++();
		Fraction& operator--();

		Fraction  operator++(int);
		Fraction  operator--(int);

		friend bool operator==(const Fraction& lhs, const Fraction& rhs);
		friend bool operator!=(const Fraction& lhs, const Fraction& rhs);
		friend bool operator>=(const Fraction& lhs, const Fraction& rhs);
		friend bool operator<=(const Fraction& lhs, const Fraction& rhs);
		friend bool operator<(const Fraction& lhs, const Fraction& rhs);
		friend bool operator>(const Fraction& lhs, const Fraction& rhs);

		int get_numerator() const
		{
			return m_numerator;
		}

		int get_denominator() const
		{
			return m_denominator;
		}

	private:
		int m_numerator;
		int m_denominator;
	};

	Fraction operator+(const Fraction& lhs, const Fraction& rhs);
	Fraction operator-(const Fraction& lhs, const Fraction& rhs);
	Fraction operator*(const Fraction& lhs, const Fraction& rhs);
	Fraction operator/(const Fraction& lhs, const Fraction& rhs);

	Fraction reverse(Fraction& fr);

	Fraction minus(Fraction& fr);
}