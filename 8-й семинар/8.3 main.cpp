#include "8.3 Header.hpp"
#include <iomanip>

int main()
{
	
	/*frac::Fraction a;
	std::cout << "Enter your fraction\n";
	std::cin >> a;
	frac::Fraction b(-3, 9);
	frac::Fraction c = 1;
	std::cout << "a = " << a << " b = " << b << " c = " << c << '\n';

	std::cout << "(a + b++) = " << a + b++ << "  (a - --c) = " << (a - --c) << '\n';
	std::cout << "a * c = " << a * c << " b/a = " << b / a << '\n';

	std::cout << "b = " << (double)b << " a = " << a << '\n';
	std::cout << "b < a ? " << std::boolalpha << (b < a) << '\n';
	a += 3;
	std::cout << "(a += 3) " << a;*/

	frac::Fraction a = 2;
	frac::Fraction b(0, 8);

	try
	{
		frac::Fraction fr_1(1, 0);
	}
	catch (const frac::Fraction_exception& exception)
	{
		std::cerr << "Error : " << exception.what() << '\n';
	}

	try
	{
		frac::Fraction c = a / b;
	}
	catch (const frac::Fraction_exception& exception)
	{
		std::cerr << "Error : " << exception.what() << '\n';
	}

	try
	{
		std::cout << "Enter the fraction\n";
		std::cin >> a;
	}
	catch (const frac::Fraction_exception& exception)
	{
		std::cerr << "Error : " << exception.what() << '\n';
	}
	
	return 0;
}