#include <iostream>
#include <type_traits>

template <bool condition, int a, int b>
struct Var_if_then_else
{
	static constexpr int value = a;
};

template <int a, int b>
struct Var_if_then_else <false, a, b>
{
	static constexpr int value = b;
};

template <bool condition, int a, int b>
inline constexpr int var_if_then_else = Var_if_then_else <condition, a, b>::value;

template <int K, int N>
inline constexpr bool cond = (K <= N && K > N / 2);

template <int K, int N>
struct Combinations
{
	static constexpr int value = var_if_then_else<cond<K,N>, Combinations<N - K, N>::value /*error*/, Combinations<K - 1, N - 1>::value + Combinations<K, N - 1>::value>;
};

template <int N>
struct Combinations <0, N>
{
	static constexpr int value = 1;
};

template <int N>
struct Combinations <N, N>
{
	static constexpr int value = 1;
};

template <>
struct Combinations <0, 0>
{
	static constexpr int value = 1;
};

template <int K, int N>
inline constexpr int combinations = Combinations<K, N>::value;

template <int coeff_num, int power>
struct Binomial_coefficient
{
	static constexpr int value = combinations<coeff_num - 1, power>;
};

template <int coeff_num, int power>
inline constexpr int binomial_coefficient = Binomial_coefficient<coeff_num, power>::value;

int main()
{
	std::cout << "the first coefficient (a+b)^0 : " << binomial_coefficient<1, 0> << '\n';
	std::cout << "the second coefficient (a+b)^1 : " << binomial_coefficient<2, 1> << '\n';
	std::cout << "the second coefficient (a+b)^2 : " << binomial_coefficient<2, 2> << '\n';
	std::cout << "the second coefficient (a+b)^4 : " << binomial_coefficient<2, 4> << '\n';
	std::cout << "the third coefficient (a+b)^3 : " << binomial_coefficient<3, 3> << '\n';
	std::cout << "the fourth coefficient (a+b)^7 : " << binomial_coefficient<4, 7> << '\n';
	std::cout << "the sixth coefficient (a+b)^10 : " << binomial_coefficient<6, 10> << '\n';



	return 0;
}