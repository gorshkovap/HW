#include <iostream>
#include <iomanip>

constexpr bool is_0(double d)
{
	return d <= std::numeric_limits <double> ::epsilon();
}

constexpr double exp()
{
	int N = 0;
	double current = 1.0;
	double result = current;
	while (!(is_0(current)))
	{
		++N;
		current /= N;
		result += current;
	}
	return result;
}

constexpr int max_accuracy()
{
	double d = std::numeric_limits <double> ::epsilon();
	int n = 0;
	while (d < 1)
	{
		d *= 10;
		++n;
	}
	return n;
}

int main()
{
	constexpr double result = exp();
	const double e = 2.71828182845904523536028747135266249775724709369995;

	std::cout << "calculated e = " << std::fixed << std::setprecision(max_accuracy()) << result << '\n';
	std::cout << "true       e = " << std::fixed << std::setprecision(max_accuracy()) << e      << '\n';
	std::cout << "accuracy     = " << std::fixed << std::setprecision(max_accuracy()) << std::abs(e - result) << '\n';

	return 0;
}