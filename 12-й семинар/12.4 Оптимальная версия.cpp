#include <iostream>
#include <array>

constexpr int integer_sqrt(int N) //rounded up
{
	int result = 1;
	while (result * result <= N)
	{
		++result;
	}
	return result;
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
	int current_number = 2;
	for (auto index = 1; index < N; ++index)
	{
		do
		{
			++current_number;
		} while (!(is_prime(current_number, primes, index)));
		primes[index] = current_number;
	}
	return primes[N - 1];
}

int main()
{
	constexpr int primes_1_10[] = { prime<1U>(), prime<2U>(), prime<3U>(), prime<4U>(), prime<5U>(), prime<6U>(), prime<7U>(), prime<8U>(), prime<9U>(), prime<10U>() };
	constexpr int prime_20 = prime<20U>();
	constexpr int prime_100 = prime<100U>();

	std::cout << "1st-10th primes: ";
	for (auto i = 0U; i < 10U; ++i)
	{
		std::cout << primes_1_10[i] << ' ';
	}
	std::cout << '\n';

	std::cout << "The 20th prime: " << prime_20 << '\n';
	std::cout << "The 100th prime: " << prime_100 << '\n';

	return 0;
}