#pragma once

#include <algorithm>
#include <exception>
#include <iostream> 
#include <stdexcept>
#include <vector>

template <typename T> 
class Array
{
public:

	using value_type             = T;
	using reference              = value_type &;
	using const_reference        = const value_type &;
	using size_type              = std::size_t;

	Array() : m_arr_size(0U), m_arr(nullptr) {}

	Array(size_type  n) : m_arr_size(n)
	{
		m_arr = new value_type[m_arr_size];
	}

	Array(const std::vector <value_type>& v) : m_arr_size(v.size())
	{
		m_arr = new value_type[m_arr_size];
		for (auto i = 0U; i < m_arr_size; ++i)
		{
			m_arr[i] = v[i];
		}		
	}

	Array(const value_type* arr, size_type n) : m_arr_size(n)
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

	const value_type& operator[] (size_type index) const
	{
		return m_arr [index];
	}

	value_type& operator[] (size_type index)
	{
		return m_arr [index];
	}

	const value_type& at(size_type index) const
	{
		if (index >= m_arr_size)
		{
			throw std::out_of_range("too big index for reading element of array");
		}
		return m_arr[index];
	}

	value_type& at(size_type index)
	{
		if (index >= m_arr_size)
		{
			throw std::out_of_range("too big index for changing element of array");
		}
		return m_arr[index];
	}

	size_type size() const noexcept
	{
		return m_arr_size;
	}

	void resize(size_type new_size)
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
	
	friend std::ostream& operator<<(std::ostream& stream, const Array& array)
	{
		stream << "array size = " << array.m_arr_size << ", array elements: ";
		for (auto i = 0U; i < array.m_arr_size; ++i)
		{
			stream << array.m_arr[i] << ' ';
		}
		return stream;
	}

private:
	value_type* m_arr;
	size_type m_arr_size;
};

template<typename T>
void swap(Array<T>& lhs, Array<T>& rhs) noexcept
{
	lhs.swap(rhs);
}