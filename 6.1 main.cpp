#include "Header 6.1.hpp"

int main()
{
	int a[] = { 1, 2, 3, 4 };
	std::vector <int> v(3, 1);
	Arrays Array_0(a, 4, v);
	std::cout << "Array_0: " << Array_0 << '\n';
	Arrays Array_1(Array_0);
	std::cout << "Array_0 copied to Array_1\n" << "Array_0: " << Array_0 << "\nArray_1: " << Array_1 << '\n';
	Arrays Array_2(std::move(Array_1));
	std::cout << "Array_1 moved to Array_2\n" << "Array_1: " << Array_1 << "\nArray_2: " << Array_2 << '\n';
	Array_1 = Array_2;
	std::cout << "Array_1 equals Array_2 (copy)\n" << "Array_1: " << Array_1 << "\nArray_2: " << Array_2 << '\n';
	Array_0 = std::move(Array_2);
	std::cout << "Array_0 equals Array_2 (move)\n" << "Array_0: " << Array_0 << "\nArray_2: " << Array_2 << '\n';
}
