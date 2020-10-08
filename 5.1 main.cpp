#include "5.1header.hpp"

int main()
{
	int n = 0;
	std::cout << "Enter the number of enrollees" << '\n';
	std::cin >> n;
	std::vector < Enrollee > enr(n);
	std::cout << '\n' << "Enter the enrollees in format (last_name first_name score1 score2 score3), where priority of scores decreases" << '\n';
	for (auto& p : enr)
	{
		std::cin >> p; //чтение данных об абитуриенте
	}
	std::sort(enr.begin(), enr.end(), [](const auto& s1, const auto& s2) {return comp(s1, s2); });

	std::cout << '\n' << "Ranked list of enrollees:" << '\n';
	print("Last Name", "First Name", "Score1", "Score2", "Score3", "SUM");
	for (auto& p : enr) //вывод ранжированного списка поступающих
	{
		std::cout << p;
	}
	
	return 0;
}