#include<iostream>
#include<iomanip>

template < typename F, typename ... Types>
void call(F f, Types...elements)
{
	f(elements...);
}

void function(int i, char c)
{
	std::cout << i + c - '0' << '\n';
}

int main()
{
	auto lambda = [](std::string statement, bool b) {std::cout << "the statement \""<< statement << "\" is " << std::boolalpha << b << '\n'; };

	call(function, 4, '8'); // 4 + '8' - '0' == 12
	call(lambda, "Bjarne Stroustrup was born in 1950", true);

	return 0;
}