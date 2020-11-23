#include <iostream>
#include <array>

constexpr int sqrt_binary(int n, int left, int right)
{
	if (left == right)
	{
		return right;
	}

	const int middle = left + ((right - left) / 2);

	return (n / middle < middle ? sqrt_binary(n, left, middle) : sqrt_binary(n, middle + 1, right));
}

constexpr int integer_sqrt(int n) //rounded up
{
	return sqrt_binary(n, 1, n - 1);
}

template< const std::size_t N >
constexpr bool is_prime(int n, std::array <int, N> arr, std::size_t elem_num)
{
	for (auto i = 0U; (i < elem_num) && arr[i] < integer_sqrt(n); ++i)
	{
		if (n % arr[i] == 0)
		{
			return false;
		}
	}
	return true;
}

template< const std::size_t N >
constexpr int prime()
{
	std::array<int, N> primes{};
	primes[0] = 2;

	auto current_number = 3;

	for (auto index = 1; index < N; ++index)
	{
		for (; !(is_prime(current_number, primes, index)); current_number+=2);
		primes[index] = current_number;
		current_number += 2;
	}

	return primes[N - 1];
}

int main()
{
	constexpr int primes_1_10[] = { prime<1U>(), prime<2U>(), prime<3U>(), prime<4U>(), prime<5U>(), prime<6U>(), prime<7U>(), prime<8U>(), prime<9U>(), prime<10U>() };
	constexpr int prime_20 = prime<20U>();
	constexpr int prime_100 = prime<100U>();
	constexpr int prime_200 = prime<200U>();
	constexpr int prime_300 = prime<300U>();

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