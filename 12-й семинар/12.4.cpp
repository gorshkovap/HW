#include <iostream>

constexpr int integer_sqrt(int N) //rounded up
{
	int result = 1;
	while (result * result <= N)
	{
		++result;
	}
	return result;
}

constexpr bool is_prime(int n)
{
	for (auto i = 2; i < integer_sqrt(n); i += 1)
	{
		if (n % i == 0)
		{
			return false;
		}
	}
	return true;
}

constexpr int prime(const std::size_t N)
{
	if (N == 1U)
	{
		return 2;
	}
	int current_number = 1;
	for (auto i = 1U; i < N; ++i)
	{
		do
		{
			current_number += 2;
		} while (!(is_prime(current_number)));
	}
	return current_number;
}

int main()
{
	constexpr int primes_1_10[] = { prime(1U), prime(2U), prime(3U), prime(4U), prime(5U), prime(6U), prime(7U), prime(8U), prime(9U), prime(10U) };
	constexpr int prime_20 = prime(20U);
	constexpr int prime_100 = prime(100U);

	std::cout << "1st-10th primes: ";
	for (auto i = 0U; i < 10U; ++i)
	{
		std::cout << primes_1_10[i];
	}
	std::cout << '\n';

	std::cout << "The 20th prime: " << prime_20 << '\n';
	std::cout << "The 100th prime: " << prime_100 << '\n';

	return 0;
}