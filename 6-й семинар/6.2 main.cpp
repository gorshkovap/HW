#include "6.2 Header.hpp"
#include <iomanip>

int main()
{
	frac::Fraction a;
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
	std::cout << "(a += 3) " << a;
	
	return 0;
}