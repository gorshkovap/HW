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

template < bool C, typename True_Type, typename False_Type >
struct if_then_else
{
	using type = True_Type;
};

template < typename True_Type, typename False_Type >
struct if_then_else < false, True_Type, False_Type >
{
	using type = False_Type;
};

template < bool C, typename TT, typename FT >
using if_then_else_t = typename if_then_else < C, TT, FT >::type;

template < typename T >
struct Is_array : std::false_type
{};

template < typename T, std::size_t N >
struct Is_array < T[N] > : std::true_type
{
	using type = T;
};

template < typename T >
struct Is_array < T[] > : std::true_type
{
	using type = T;
};

template <typename T>
inline constexpr bool is_array = Is_array<T>::value; // variable template

template <typename T>
using is_array_t = typename Is_array<T>::type; //type alias (template)

template <typename T > //common choice
struct Is_function : std::false_type {};

template <typename F, typename ... Args> //when the argument is function, this template specialization is chosen and value = Is_function::value = true
struct Is_function<F(Args...)> : std::true_type 
{
	using type = F;
};

template <typename T>
inline constexpr bool is_function = Is_function<T>::value; // variable template

template <typename T>
using is_function_t = typename Is_function<T>::type; //type alias (template)

template <typename T>
struct decay
{
	using T1 = remove_reference_t<T>;
	using type = if_then_else_t < is_array<T1>, is_array_t<T1>*, if_then_else_t<is_function<T1>, is_function_t<T1>*, remove_const_t<T1> > >;
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
	std::cout << is_same_v<decay_t<decltype(b)>, const int*> << '\n';
	std::cout << is_same_v<decay_t<decltype(g)>, int*> << '\n';
	std::cout << is_same_v<decay_t<decltype(f)>, void*> << '\n';
	std::cout << is_same_v<decay_t<decltype(x)>, int> << '\n';
	std::cout << is_same_v<decay_t<decltype(std::move(x))>, int> << '\n';
	std::cout << is_same_v<decay_t<decltype(y)>, int> << '\n';
	std::cout << is_same_v<decay_t<decltype(c)>, int*> << '\n';

	return 0;
}