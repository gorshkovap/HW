#include <iostream>
#include <type_traits>

template <bool B, typename T = void> //common
struct enable_if
{
	using type = T;
};

template <typename T>
struct enable_if<false, T>{}; //specialization for false

template <bool B, typename T = void>
using enable_if_t = typename enable_if<B, T>::type; //type alias (template)

template <typename T1, typename T2>
inline const bool is_same_v = std::is_same<T1, T2>::value; //variable template

template <typename T>
enable_if_t<is_same_v<T, int>, T> f(T t)
{
	return t;
}

int f(double d)
{
	return 7;
}

int main()
{
	std::cout << std::boolalpha;

	std::cout << is_same_v <enable_if_t<(1 > 0), int>, int> << '\n';

	if (f('c') == 7)
	{
		std::cout << "All right, char became double because T=char != int and SFINAE allowed compiler to choose f(double)\n";
	}

	return 0;
}