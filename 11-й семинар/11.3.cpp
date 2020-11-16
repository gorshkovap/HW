#include <iostream>
#include <type_traits>

template <typename T> // common template
struct remove_const
{
	using type = T;
};

template <typename T>
struct remove_const<const T> //specialization for const types
{
	using type = T;
};

template <typename T>
using remove_const_t = typename remove_const<T>::type; //type alias (template)

template <typename T>
struct remove_reference
{
	using type = T;
};

template < typename T >
struct remove_reference < T& >
{
	using type = T;
};

template <typename T>
struct remove_reference < T&& >
{
	using type = T;
};

template <typename T>
using remove_reference_t = typename remove_reference<T>::type; //type alias (template)

template <typename T>
struct check_array
{
	using type = T;
};

template <typename T, std::size_t N>
struct check_array < T[N] > // changes arrays of T on T*
{
	using type = T*;
};

template <typename T>
struct check_array < T[] > // changes arrays of T on T*
{
	using type = T*;
};

template <typename T>
using ptr_if_array = typename check_array<T>::type; //type alias (template)

template <typename T>
struct check_function 
{
	using type = T;
};

template <typename F, typename ... Args>
struct check_function<F(Args...)> //adds * for functions
{
	using type = F*;
};

template <typename T>
using ptr_if_function = typename check_function<T>::type; //type alias (template)

template <typename T>
struct decay
{
	using T1 = remove_reference_t<T>; 
	using T2 = remove_const_t<T1>;
	using T3 = ptr_if_array<T2>;
	using type = ptr_if_function<T3>;
};

template <typename T>
using decay_t = typename decay<T>::type; 

template <typename T1, typename T2>
inline const bool is_same_v = std::is_same<T1, T2>::value; //variable template

void f(){}
int g(int i) { return 4; }

int main()
{
	const int x = 0;
	auto &y = x;
	int a[] = { 2, 5 };
	const int b[] = { 7, 8 };
	auto& c = a;

	std::cout << std::boolalpha;

	std::cout << is_same_v<decay_t<decltype(a)>, int*> << '\n';	
	std::cout << is_same_v<decay_t<decltype(b)>, int*> << '\n';
	std::cout << is_same_v<decay_t<decltype(g)>, int*> << '\n';
	std::cout << is_same_v<decay_t<decltype(f)>, void*> << '\n';
	std::cout << is_same_v<decay_t<decltype(x)>, int> << '\n';
	std::cout << is_same_v<decay_t<decltype(std::move(x))>, int> << '\n';
	std::cout << is_same_v<decay_t<decltype(y)>, int> << '\n';
	std::cout << is_same_v<decay_t<decltype(c)>, int*> << '\n';

	return 0;
}