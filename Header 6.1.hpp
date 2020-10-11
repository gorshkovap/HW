#pragma once
#include <iostream> 
#include <vector>

class Arrays
{
public:
	Arrays();

	Arrays(std::size_t n);
	Arrays(const std::vector <int> &v);
	Arrays(const int* arr, std::size_t n);
	Arrays(const int* arr, std::size_t n, const std::vector <int>& v);

	~Arrays();

	Arrays(const Arrays& other);

	Arrays(Arrays&& other);

	Arrays & operator=(const Arrays& other);

	Arrays & operator=(Arrays&& other);

	friend std::ostream& operator<<(std::ostream& stream, Arrays& Array);

private:
	int* m_arr;
	std::size_t m_arr_size;
	std::vector <int> m_v;
};


