#include "5.1header.hpp"

std::istream& operator>>(std::istream& stream, Enrollee& enr)
{
	stream >> enr.last_name >> enr.first_name >> enr.score_1 >> enr.score_2 >> enr.score_3;
	return stream;
}

std::ostream& operator<<(std::ostream& stream, Enrollee& enr)
{
	std::cout << std::left << std::setw(15) << std::setfill(' ') << enr.last_name
		<< std::setw(15) << std::setfill(' ') << enr.first_name
		<< std::setw(8) << std::setfill(' ') << enr.score_1
		<< std::setw(8) << std::setfill(' ') << enr.score_2
		<< std::setw(8) << std::setfill(' ') << enr.score_3
		<< enr.sum() << '\n';
	return stream;
}

//свободные функции

bool comp(const Enrollee& s1, const Enrollee& s2) //функция сравнения абитуриентов по баллам
{
	return ((s1.sum() - s2.sum()) * 1'000'000 + (s1.get_score_1() - s2.get_score_1()) * 1'000 + (s1.get_score_2() - s1.get_score_2()) > 0);
}

void print(const std::string& str_1, const std::string& str_2, const std::string& str_3, const std::string& str_4,
	const std::string& str_5, const std::string& str_6)
{
	std::cout << '\n' << std::left << std::setw(15) << std::setfill(' ') << str_1 //шапка таблицы
		<< std::setw(15) << std::setfill(' ') << str_2
		<< std::setw(8) << std::setfill(' ') << str_3
		<< std::setw(8) << std::setfill(' ') << str_4
		<< std::setw(8) << std::setfill(' ') << str_5
		<< str_6 << '\n' << '\n';
}