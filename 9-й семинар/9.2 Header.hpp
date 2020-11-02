#pragma once

#include <iostream> 
#include <vector>
#include <algorithm>
#include <exception>
#include <stdexcept>

template <typename T> 
class Array
{
public:

	using value_type             = T;
	using reference              = T&;
	using const_reference        = const T&;

	Array() : m_arr_size(0U), m_arr(nullptr) {};

	Array(std::size_t n) : m_arr_size(n) 
	{
		m_arr = new value_type[m_arr_size];
	}

	Array(const std::vector <value_type>& v) : m_arr_size(v.size())
	{
		m_arr = new value_type[m_arr_size];
		if (m_arr)
		{
			for (auto i = 0U; i < m_arr_size; ++i)
			{
				m_arr[i] = v[i];
			}
		}
	}

	Array(const value_type* arr, std::size_t n) : m_arr_size(n)
	{
		m_arr = new value_type[m_arr_size];
		for (auto i = 0U; i < m_arr_size; ++i)
		{
			m_arr[i] = arr[i];
		}
	}

	~Array() noexcept
	{
		if (m_arr)
		{
			delete[] m_arr;
		}
	}

	Array(const Array& other) : m_arr_size(other.m_arr_size)
	{
		m_arr = new value_type[m_arr_size];
		for (auto i = 0U; i < m_arr_size; ++i)
		{
			m_arr[i] = other.m_arr[i];
		}
	}

	Array(Array&& other) noexcept : m_arr_size(other.m_arr_size), m_arr(other.m_arr)
	{
		other.m_arr_size = 0U;
		other.m_arr = nullptr;
	}

	Array& operator=(const Array& other)
	{
		if (this == &other)
		{
			return *this;
		}
		if (m_arr)
		{
			delete[] m_arr;
		}
		m_arr_size = other.m_arr_size;
		m_arr = new value_type[m_arr_size];
		for (auto i = 0U; i < m_arr_size; ++i)
		{
			m_arr[i] = other.m_arr[i];
		}

		return *this;
	}

	Array& operator=(Array&& other)
	{
		if (this == &other)
		{
			return *this;
		}
		if (m_arr)
		{
			delete[] m_arr;
		}
		m_arr_size = other.m_arr_size;
		m_arr = other.m_arr;
		other.m_arr_size = 0U;
		other.m_arr = nullptr;

		return *this;
	}

	const value_type& operator[] (std::size_t index) const
	{
		if (index >= m_arr_size)
		{
			throw std::out_of_range("too big index for reading element of array");
		}
		return m_arr [index];
	}

	value_type& operator[] (std::size_t index)
	{
		if (index >= m_arr_size)
		{
			throw std::out_of_range("too big index for changing element of array");
		}
		return m_arr [index];
	}

	std::size_t size() const noexcept
	{
		return m_arr_size;
	}

	void resize(std::size_t new_size)
	{
		if (new_size != m_arr_size)
		{
			auto arr = new value_type[new_size];
			auto max_index = std::min(new_size, m_arr_size);
			for (auto i = 0U; i < max_index; ++i)
			{
				arr[i] = m_arr[i];
			}
			delete[] m_arr;
			m_arr = arr;
			m_arr_size = new_size;
		}
	}

	void swap(Array &other) noexcept
	{
		std::swap(m_arr_size, other.m_arr_size);
		std::swap(m_arr, other.m_arr);
	}

	friend void swap(Array &lhs, Array &rhs) noexcept
	{
		std::swap(lhs.m_arr_size, rhs.m_arr_size);
		std::swap(lhs.m_arr, rhs.m_arr);
	}
	
	friend std::ostream& operator<<(std::ostream& stream, const Array& array)
	{
		stream << "array size = " << array.m_arr_size << ", array elemements: ";
		for (auto i = 0U; i < array.m_arr_size; ++i)
		{
			stream << array.m_arr[i] << ' ';
		}
		return stream;
	}

private:
	value_type* m_arr;
	std::size_t m_arr_size;
};