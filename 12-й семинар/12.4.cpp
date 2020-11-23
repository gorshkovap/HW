#include <iostream>
#include <array>

constexpr int integer_sqrt(int n) //rounded up
{
	int left = 1, right = n - 1;
	int middle = left + ((right - left) / 2);
	while (left != right)
	{
		middle = left + ((right - left) / 2);
		n / middle < middle ? right = middle : left = middle + 1;
	}
	return right;
}

template< int N >
constexpr bool is_prime(int n, const std::array <int, N>& arr, int elem_num)
{
	for (auto i = 0; (i < elem_num) && arr[i] < integer_sqrt(n); ++i)
	{
		if (n % arr[i] == 0)
		{
			return false;
		}
	}
	return true;
}

template< int N >
constexpr int prime()
{
	std::array<int, N> primes{};
	primes[0] = 2;
	for (auto current_number = 3, index = 1; index < N; ++index, current_number += 2)
	{
		for (; !(is_prime(current_number, primes, index)); current_number+=2);
		primes[index] = current_number;
	}
	return primes[N - 1];
}

int main()
{
	constexpr int primes_1_10[] = { prime<1>(), prime<2>(), prime<3>(), prime<4>(), prime<5>(), prime<6>(), prime<7>(), prime<8>(), prime<9>(), prime<10>() };
	constexpr int prime_20 = prime<20>();
	constexpr int prime_100 = prime<100>();
	constexpr int prime_200 = prime<200>();
	constexpr int prime_300 = prime<300>();

	std::cout << "1st-10th primes: ";
	for (auto i = 0U; i < 10U; ++i)
	{
		std::cout << primes_1_10[i] << ' ';
	}
	std::cout << '\n';

	std::cout << "The 20th prime: " << prime_20 << '\n';
	std::cout << "The 100th prime: " << prime_100 << '\n';
	std::cout << "The 200th prime: " << prime_200 << '\n';
	std::cout << "The 300th prime: " << prime_300 << '\n';

	return 0;
}