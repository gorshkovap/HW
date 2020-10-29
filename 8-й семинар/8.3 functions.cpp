#include "8.3 Header.hpp"
#include <numeric>

namespace frac
{
	Fraction::Fraction() : m_numerator(0), m_denominator(1) {}

	Fraction::Fraction(int n, int d) : m_numerator(n), m_denominator(d)
	{
		if (m_denominator == 0)
		{
			throw Fraction_exception ("denominator = 0 in constructor Fraction(int, int)");
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
			throw Fraction_exception ("denominator = 0 in the fraction for output");
		}
		else
		{
			fraction.m_denominator == 1 ? stream << fraction.m_numerator
				: stream << fraction.m_numerator << '/' << fraction.m_denominator;
		}
		return stream;
	}

	std::istream& operator>>(std::istream& stream, Fraction& fraction)
	{
		char c = '\0';
		stream >> fraction.m_numerator >> c >> fraction.m_denominator;
		if (fraction.m_denominator == 0)
		{
			throw Fraction_exception ("denominator = 0 in the entered fraction");
		}
		fraction.reduction();
		return stream;
	}

	void Fraction::reduction()
	{
		int	div = std::gcd(m_numerator, m_denominator);
		try
		{
			m_numerator /= div;
			m_denominator /= div;
		}
		catch (const frac::Fraction_exception& exception)
		{
			std::cerr << "catched inside the function reduction of class Fraction : " << exception.what() << '\n';
			throw Fraction_exception("division by 0 inside the function reduction of class Fraction");
		}		
	}

	Fraction::operator int() const
	{
		try
		{
			return m_numerator / m_denominator;
		}
		catch (const frac::Fraction_exception& exception)
		{
			std::cerr << "catched inside the operator int() of class Fraction : " << exception.what() << '\n';
			throw Fraction_exception("denominator = 0 inside the operator int() of class Fraction");
		}
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
		try
		{
			fr /= rhs;
		}
		catch (const frac::Fraction_exception& exception)
		{
			std::cerr << "catched inside the operator/ : " << exception.what() << '\n';
			throw Fraction_exception("division by 0 inside the operator/");
		}
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
			throw Fraction_exception ("division by 0 inside the operator/=");
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
		try
		{
			return 1 / fr;
		}
		catch (const frac::Fraction_exception& exception)
		{
			std::cerr << "catched inside the function Fraction reverse(const Fraction&) : " << exception.what() << '\n';
			throw Fraction_exception("denominator = 0 inside the function Fraction reverse(const Fraction&)");
		}
	}

	Fraction minus(const Fraction& fr)
	{
		return  -1 * fr;
	}
}

