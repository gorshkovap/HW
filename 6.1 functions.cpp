#include "Header 6.1.hpp"

Arrays::Arrays() : m_arr_size(0), m_arr(nullptr) {}

Arrays::Arrays(std::size_t n) : m_arr_size(n), m_arr(nullptr)
{
	m_arr = new int[m_arr_size];
	for (auto i = 0U; i < m_arr_size; ++i)
	{
		m_arr[i] = 0;
	}		
}

Arrays::Arrays(const std::vector <int> &v) : m_v(v) {}

Arrays::Arrays(const int* arr, std::size_t n): m_arr_size(n), m_arr(nullptr)
{
	arr = new int[m_arr_size];
	for (auto i = 0U; i < m_arr_size; ++i)
	{
		m_arr[i] = arr[i];
	}		
}

Arrays::Arrays(const int* arr, std::size_t n, const std::vector <int>& v) : m_arr_size (n), m_v(v)
{
	m_arr = new int[m_arr_size];
	for (auto i = 0U; i < m_arr_size; ++i)
	{
		m_arr[i] = arr[i];
	}
}

Arrays::~Arrays()
{
	if (m_arr)
	{
		delete[] m_arr;
	}
}

Arrays::Arrays(const Arrays& other) : m_arr_size(other.m_arr_size), m_v(other.m_v)
{
	m_arr = new int[m_arr_size];
	for (auto i = 0U; i < m_arr_size; ++i)
	{
		m_arr[i] = other.m_arr[i];
	}
}

Arrays::Arrays(Arrays&& other) : m_arr_size(other.m_arr_size), m_arr(other.m_arr), m_v(std::move(other.m_v)) 
{
	other.m_arr_size = 0U;
	other.m_arr = nullptr;
	other.m_v.clear();
}

Arrays& Arrays::operator=(const Arrays& other) 
{
	if (this == &other)
	{
		return *this;
	}
	if (m_arr != nullptr)
	{
		delete[] m_arr;
	}
	m_arr_size = other.m_arr_size;
	m_arr = new int[m_arr_size];
	for (auto i = 0U; i < m_arr_size; ++i)
	{
		m_arr[i] = other.m_arr[i];
	}
	m_v = other.m_v;

	return *this;
}
Arrays& Arrays::operator=(Arrays&& other)
{
	if (this == &other)
	{
		return *this;
	}
	if (m_arr != nullptr)
	{
		delete[] m_arr;
	}
	m_arr_size = other.m_arr_size;
	m_arr = other.m_arr;
	m_v = std::move(other.m_v);
	other.m_arr_size = 0;
	other.m_arr = nullptr;
	other.m_v.clear();
}

std::ostream& operator<<(std::ostream& stream, Arrays& array)
{
	std::cout << "array size = " << array.m_arr_size << " array elemements: ";
	for (auto i = 0U; i < array.m_arr_size; ++i)
	{
		std::cout << array.m_arr[i] << ' ';
	}
	std::cout << " vector elements:";
	for (auto& elem : array.m_v)
	{
		std::cout << ' ' << elem;
	}
	return stream;
}