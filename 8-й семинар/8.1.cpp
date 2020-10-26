#include <iostream>

class Array
{
public:
	Array() : m_ptr(nullptr), m_size(0U) {}
	Array(int* ptr, int n) : m_size(n), m_ptr(ptr) {}

	Array(const Array& other) : m_size(other.m_size)
	{
		m_ptr = new int[m_size];
		for (std::size_t i = 0U; i < m_size; ++i)
			m_ptr[i] = other.m_ptr[i];
	}
	void clear()
	{
		if (m_size != 0)
		{
			delete[] m_ptr;
			m_ptr = nullptr;
			m_size = 0U;
		}
	}
	int* m_ptr;
	std::size_t m_size;
};

std::ostream& operator<<(std::ostream& stream, const Array& arr)
{
	for (auto i = 0U; i < arr.m_size; ++i)
	{
		stream << arr.m_ptr[i] << ' ';
	}
	return stream;
}

enum class Errors
{
	correct_work,
	too_big_index,
	too_big_size,
	unknown_error
};

struct Error_and_result
{
	Error_and_result() : m_error(Errors::unknown_error){}
	Error_and_result(const Array &arr) : m_arr(arr), m_error(Errors::correct_work) {}
	Error_and_result(Errors error) : m_error(error) {}
	Array m_arr;
	Errors m_error;
};

union Res_or_err
{
	Res_or_err() : m_error(Errors::unknown_error) {}
	Res_or_err(const Array& arr) : m_arr(arr) {}
	Res_or_err(Errors error) : m_error(error) {} 
	Array m_arr;
	Errors m_error;
};

struct Result_or_error
{
	Result_or_error() : m_data(Errors::unknown_error), m_error_exists(true) {}
	Result_or_error(const Array& arr) : m_data(arr), m_error_exists(false) {}
	Result_or_error(Errors error) : m_data(error), m_error_exists(true) {}
	Res_or_err m_data;
	bool m_error_exists;
};

Error_and_result struct_function(const Array &arr_1, const Array &arr_2, std::size_t index)
{
	if (index > arr_1.m_size)
	{
		return Errors::too_big_index;
	}

	if (arr_2.m_size != 0U)
	{
		Error_and_result ear;
		ear.m_arr.m_size = index + arr_2.m_size;
		ear.m_arr.m_ptr = new int[ear.m_arr.m_size];
		if (ear.m_arr.m_ptr == nullptr)
		{
			return Errors::too_big_size;
		}
		for (auto i = 0U; i < index; ++i)
		{
			ear.m_arr.m_ptr[i] = arr_1.m_ptr[i];
		}
		for (auto i = 0U; i < arr_2.m_size; ++i)
		{
			ear.m_arr.m_ptr[index + i] = arr_2.m_ptr[i];
		}
		ear.m_error = Errors::correct_work;
		return ear;
	}
	else
	{
		return arr_1;
	}
}

Result_or_error union_function(const Array& arr_1, const Array& arr_2, std::size_t index)
{
	if (index > arr_1.m_size)
	{
		return Errors::too_big_index;
	}

	if (arr_2.m_size != 0U)
	{
		Result_or_error roe;
		roe.m_data.m_arr.m_size = index + arr_2.m_size;
		roe.m_data.m_arr.m_ptr = new int[roe.m_data.m_arr.m_size];
		if (roe.m_data.m_arr.m_ptr == nullptr)
		{
			return Errors::too_big_size;
		}
		for (auto i = 0U; i < index; ++i)
		{
			roe.m_data.m_arr.m_ptr[i] = arr_1.m_ptr[i];
		}
		for (auto i = 0U; i < arr_2.m_size; ++i)
		{
			roe.m_data.m_arr.m_ptr[index + i] = arr_2.m_ptr[i];
		}
		roe.m_error_exists = false;

		return roe.m_data.m_arr;
	}
	else
	{
		return arr_1;
	}
}

void Error_check(const Error_and_result& ear, Array &p)
{
	switch (ear.m_error)
	{
	case Errors::correct_work:
		p = ear.m_arr;
		break;
	case Errors::too_big_index:
		std::cerr << "Error: too big index\n";
		break;
	case Errors::too_big_size:
		std::cerr << "Error: too big size of result\n";
		break;
	default:
		std::cerr << "Unknown error\n";
		break;
	}
}

void Error_check(const Result_or_error& roe, Array &p)
{
	if (roe.m_error_exists)
	{
		switch (roe.m_data.m_error)
		{
		case Errors::too_big_index:
			std::cerr << "Error: too big index\n";
			break;
		case Errors::too_big_size:
			std::cerr << "Error: too big size of result\n";
			break;
		default:
			std::cerr << "Unknown error\n";
			break;
		}
	}
	else
	{
		p = roe.m_data.m_arr;
	}
}
int main()
{
	int x[] = { 1,2,3 };
	int y[] = { 4,5,6,7 };

	Array a(x, 3);
	Array b(y, 4);

	Array c;

	Error_check(union_function(a, b, 9), c);
	std::cout << c << '\n';
	Error_check(union_function(a, b, 2), c);
	std::cout << c << '\n';

	c.clear();

	Error_check(struct_function(a, b, 9), c);
	std::cout << c << '\n';
	Error_check(struct_function(a, b, 2), c);
	std::cout << c << '\n';
	

	return 0;
}