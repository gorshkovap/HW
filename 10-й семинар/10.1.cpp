#include<iostream>

template < typename ... Types>
std::size_t size_of_tuple(Types...elements)
{
	return (... + sizeof(elements));
}

template < typename T, typename ... Types>
std::size_t sizeOfTuple(T element, Types...elements)
{
	if constexpr (sizeof...(Types))
	{
		return sizeof(T) + sizeOfTuple(elements...);
	}
	else
	{
		return sizeof(T);
	}
}

int main()
{
	std::cout << size_of_tuple(5, 18, "Bjarne Stroustrup" /*sizeof(char*) == 4*/, 5.1) << '\n'; /* 4 + 4 + 4 + 8 == 20 */
	std::cout << sizeOfTuple(5, 18, "Bjarne Stroustrup", 5.1) << '\n';

	return 0;
}