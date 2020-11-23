#include <iostream>

template <int N>
struct Fibonacci
{
	static const int value = Fibonacci<N - 1>::value + Fibonacci<N - 2>::value;
};

template<>
struct Fibonacci<0>
{
	static const int value = 0;
};

template<>
struct Fibonacci<1>
{
	static const int value = 1;
};

template <int N>
inline constexpr int fibonacci = Fibonacci<N>::value;

template </* from */ int I, /* to */ int N>
void Fibonacci_print()
{
	if constexpr (N >= I)
	{
		std::cout << fibonacci<I> << ' ';
		Fibonacci_print<I + 1, N>();
	}
}

int main()
{
	std::cout << "the Fibonacci numbers 0 - 10 : ";
	Fibonacci_print<0, 10>();
	std::cout << '\n';

	return 0;
}