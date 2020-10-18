#include "6.2 Header.hpp"
#include <numeric>

namespace frac
{
	Fraction::Fraction() : m_numerator(0), m_denominator(1) {}

	Fraction::Fraction(int n, int d) : m_numerator(n), m_denominator(d)
	{
		if (m_denominator == 0)
		{
			std::cerr << "Error: numerator = 0\n";
			std::abort();
		}
		if (m_denominator < 0)
		{
			m_numerator = -m_numerator;
			m_denominator = -m_denominator;
		}
		reduction();
	}

	std::ostream& operator<<(std::ostream& stream, const Fraction& fraction)
	{
		if (fraction.m_denominator == 0)
		{
			std::cerr << "undefined";
		}
		else
		{
			fraction.m_denominator == 1 ? std::cout << fraction.m_numerator
				: std::cout << fraction.m_numerator << '/' << fraction.m_denominator;
		}
		return stream;
	}

	std::istream& operator>>(std::istream& stream, Fraction& fraction)
	{
		char c = '\0';
		std::cin >> fraction.m_numerator >> c >> fraction.m_denominator;
		if (fraction.m_denominator == 0)
		{
			std::cerr << "Error: numerator = 0\n";
			std::abort();
		}
		fraction.reduction();
		return stream;
	}

	void Fraction::reduction()
	{
		int	div = (m_numerator ? std::gcd(m_numerator, m_denominator) : m_denominator);
		m_numerator /= div;
		m_denominator /= div;
	}

	Fraction::operator int() const
	{
		return m_numerator / m_denominator;
	}

	Fraction::operator double() const
	{
		return static_cast <double> (m_numerator) / static_cast <double> (m_denominator);
	}

	Fraction operator+(const Fraction& lhs, const Fraction& rhs)
	{
		Fraction fr = lhs;
		fr += rhs;
		return fr;
	}

	Fraction operator-(const Fraction& lhs, const Fraction& rhs)
	{
		Fraction fr = lhs;
		fr -= rhs;
		return fr;
	}

	Fraction operator*(const Fraction& lhs, const Fraction& rhs)
	{
		Fraction fr = lhs;
		fr *= rhs;
		return fr;
	}

	Fraction operator/(const Fraction& lhs, const Fraction& rhs)
	{
		Fraction fr = lhs;
		fr /= rhs;
		return fr;
	}

	Fraction& Fraction::operator+=(const Fraction& other)
	{
		m_numerator = m_numerator * other.m_denominator + m_denominator * other.m_numerator;
		m_denominator = m_denominator * other.m_denominator;
		reduction();
		return *this;
	}

	Fraction& Fraction::operator-=(const Fraction& other)
	{
		m_numerator = m_numerator * other.m_denominator - m_denominator * other.m_numerator;
		m_denominator = m_denominator * other.m_denominator;
		reduction();
		return *this;
	}

	Fraction& Fraction::operator*=(const Fraction& other)
	{
		m_numerator *= other.m_numerator;
		m_denominator *= other.m_denominator;
		reduction();
		return *this;
	}

	Fraction& Fraction::operator/=(const Fraction& other)
	{
		if (other == 0)
		{
			std::cerr << "Error: division by 0\n";
			std::abort();
		}
		m_numerator *= other.m_denominator;
		m_denominator *= other.m_numerator;
		reduction();
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
		Fraction copy(*this);
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
		return (lhs.m_numerator * rhs.m_denominator == rhs.m_numerator * lhs.m_denominator);
	}

	bool operator!=(const Fraction& lhs, const Fraction& rhs)
	{
		return !(lhs == rhs);
	}

	bool operator<(const Fraction& lhs, const Fraction& rhs)
	{
		return (lhs.m_numerator * rhs.m_denominator < rhs.m_numerator * lhs.m_denominator);
	}

	bool operator>(const Fraction& lhs, const Fraction& rhs)
	{
		return !((lhs == rhs) || (lhs < rhs));
	}

	bool operator<=(const Fraction& lhs, const Fraction& rhs)
	{
		return !(lhs > rhs);
	}

	bool operator>=(const Fraction& lhs, const Fraction& rhs)
	{
		return !(lhs < rhs);
	}

	Fraction reverse(const Fraction& fr)
	{
		return 1 / fr;
	}

	Fraction minus(const Fraction& fr)
	{
		return  -1 * fr;
	}
}

