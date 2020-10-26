#include <iostream>
#include <exception>
#include <stdexcept>
#include <cstdlib>
#include <functional>

struct Struct
{
	Struct(int i) : x(i) {}
	Struct(double d)
	{
		throw std::invalid_argument("it's very important to give me int, but you gave me double");
	}
	int x;
};

std::function <int(int)> lambda;

int main()
{
	try
	{
		Struct X(1.0);
	}
	catch (const std::invalid_argument& exception)
	{
		std::cerr << "Error : " << exception.what() << '\n';
	}

	try
	{
		int* ptr = new int[500'000'000];
		if (!ptr)
		{
			throw std::bad_alloc();
		}
	}
	catch (const std::bad_alloc& exception)
	{
		std::cerr << "Error : " << exception.what() << '\n';
	}

	try
	{
		int x = 1'500'000'000;
		int y = 1'000'000'000;
		if (x + y < 0)
		{
			throw std::overflow_error("too big value for int");
		}
		std::cout << "x + y = " << x + y << ' ';
	}
	catch (const std::overflow_error& exception)
	{
		std::cerr << "Error : " << exception.what() << '\n';
	}

	try
	{
		int i = std::rand();
		int a[] = { 0, 0 };
		if (i > 1)
		{
			throw std::out_of_range("too big index");
		}
		std::cout << a[i];	
	}
	catch (const std::out_of_range& exception)
	{
		std::cerr << "Error : " << exception.what() << '\n';
	}

	try
	{
		int a = lambda(4);
	}
	catch (const std::bad_function_call& exception)
	{
		std::cerr << "Error : " << exception.what() << '\n';
	}

	return 0;
}