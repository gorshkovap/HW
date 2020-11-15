#include <iostream>
#include <functional>

template <typename T > //common choice
struct Is_function : std::false_type {}; 

template <typename F, typename ... Args> //when the argument is function, this template specialization is chosen and value = Is_function::value = true
struct Is_function<F(Args...)> : std::true_type {};

template <typename T> 
inline const bool is_function = Is_function<T>::value; // variable template

void f(){}

int g(int i) { return 8; }

int main()
{
	struct X {};
	std::function <int(int, int)> lambda_1;
	auto lambda_2 = [](){};

	std::cout << std::boolalpha;

	std::cout << is_function<X> << '\n';                  //false
	std::cout << is_function<decltype(lambda_1)> << '\n'; //false
	std::cout << is_function<decltype(lambda_2)> << '\n'; //false
	std::cout << is_function<int> << '\n';                //false 

	std::cout << is_function<decltype(f)> << '\n';        //true
	std::cout << is_function<decltype(g)> << '\n';        //true 
	std::cout << is_function<int(int, int)> << '\n';      //true 
	std::cout << is_function<int()> << '\n';              //true

	return 0;
}