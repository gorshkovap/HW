#include "9.2 Header.hpp"

int main()
{
	try
	{
		std::vector <double> v = { 2.2, 3.3, 4.4, 1.1, 8.8 };
		Array <double>arr(v);

		std::cout << arr[3] << '\n';

		arr[3] = 5.5;
		std::cout << arr;

		arr.resize(5);
		std::cout << '\n' << arr;

		arr.resize(7);
		std::cout << '\n' << arr;

		arr.resize(3);
		std::cout << '\n' << arr;
		std::cout << '\n' << arr.size();

		auto arr_2 = arr;
		std::cout << '\n' << arr_2;

		auto arr_3 = std::move(arr_2);
		std::cout << '\n' << arr_2;
		std::cout << '\n' << arr_3;

		swap(arr_2, arr_3);
		std::cout << '\n' << arr_2;
		std::cout << '\n' << arr_3;

		Array <int> ar(1'000'000'000U);
	}
	catch (std::exception& exception)
	{
		std::cerr << "\nError : " << exception.what() << '\n';
	}

	return 0;
}