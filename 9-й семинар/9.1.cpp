#include <iostream>
#include <iomanip>
#include <vector>

template <typename T, typename F>
void merger(T* arr, const std::size_t left, const std::size_t middle, const std::size_t right, F cmp)
{
	std::vector <T> subsidiary_array(right - left + 1U);
	for (auto i = 0U; i < right - left + 1U; ++i)
	{
		subsidiary_array[i] = arr[left + i];
	}
	std::size_t left_from_left = 0U;
	std::size_t left_from_right = middle - left + 1U;
	auto i = 0U;
	for (; i < right - left + 1U; ++i)
	{
		if ((left_from_left <= middle - left) && (left_from_right <= right - left)) //there are elements both in the left half and in the right half 
		{
			(cmp(subsidiary_array[left_from_left], subsidiary_array[left_from_right]) ? arr[left + i] = subsidiary_array[left_from_left++] : arr[left + i] = subsidiary_array[left_from_right++]);
		}
		else
		{
			break;
		}
	}
	if (left_from_right > right - left) //all emements from the right half have been included in the final array
	{
		for (; i < right - left + 1U; ++i)
		{
			arr[left + i] = subsidiary_array[left_from_left++];
		}
	}
	if (left_from_left > middle - left) //all emements from the left half have been included in the final array
	{
		for (; i < right - left + 1U; ++i)
		{
			arr[left + i] = subsidiary_array[left_from_right++];
		}
	}
}

template <typename T, typename F>
void merge_sort(T* arr, const std::size_t left, const std::size_t right, F cmp)
{
	if (left != right)
	{
		auto middle = left + (right - left) / 2U;
		merge_sort(arr, left, middle, cmp);
		merge_sort(arr, middle + 1U, right, cmp);
		merger(arr, left, middle, right, cmp);
	}
}

template <typename T, typename F>
void call_merge_sort(T* arr, std::size_t size, F cmp)
{
	if (size)
	{
		merge_sort(arr, 0U, size - 1U, cmp);
	}
}

template <typename T, std::size_t N, typename F>
void call_merge_sort(T(&arr)[N], F cmp)
{
	if (N > 1U)
	{
		merge_sort(arr, 0U, N - 1U, cmp);
	}
}

int main()
{
	int* int_array = new int[5];
	int_array[0] = 5;
	int_array[1] = 2;
	int_array[2] = 5;
	int_array[3] = 3;
	int_array[4] = 2;
	call_merge_sort(int_array, 5U, [](int a, int b) {return a > b; });
	for (auto i = 0U; i < 5U; ++i)
	{
		std::cout << int_array[i] << ' ';
	}

	std::cout << '\n';

	bool bool_array[] = { true, false, false, true, false };
	call_merge_sort(bool_array, [](bool a, bool b) {return (a <= b); });
	for (auto element : bool_array)
	{
		std::cout << std::boolalpha << element << ' ';
	}

	return 0;
}