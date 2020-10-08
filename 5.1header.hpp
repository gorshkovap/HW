#pragma once
#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <string>

class Enrollee
{
public:
	Enrollee() :
		last_name(""), first_name(""), score_1(0), score_2(0), score_3(0)
	{
	}
	Enrollee(const std::string& l, const std::string& f, int p, int m, int r) :
		last_name(l), first_name(f), score_1(p), score_2(m), score_3(r)
	{
	}

private:
	std::string last_name;
	std::string first_name;
	int score_1;
	int score_2;
	int score_3;

public:
	int sum() const
	{
		return score_1 + score_2 + score_3;
	}

	int get_score_1() const
	{
		return score_1;
	}

	int get_score_2() const
	{
		return score_2;
	}

	int get_score_3() const
	{
		return score_3;
	}

	friend std::istream& operator>>(std::istream& stream, Enrollee& enr);

	friend std::ostream& operator<<(std::ostream& stream, Enrollee& enr);	
};

void print(const std::string& str_1, const std::string& str_2, const std::string& str_3, const std::string& str_4,
	const std::string& str_5, const std::string& str_6);

bool comp(const Enrollee& s1, const Enrollee& s2);
