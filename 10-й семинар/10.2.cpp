#include<iostream>

template < typename T, typename ... Types>
T* make(Types...elements)
{
	return new T(elements...);
}

class Data
{
public:
	Data() : m_i(0), m_d(0.0){}
	Data(int i) : m_i(i), m_d(0.0) {}
	Data(double d) : m_i(0), m_d(d) {}
	Data(int i, double d) : m_i(i), m_d(d){}

	friend std::ostream& operator<<(std::ostream& stream, const Data& data)
	{
		stream << "int = " << data.m_i << ", double = " << data.m_d << '\n';
		return stream;
	}

private:
	int m_i;
	double m_d;
};

int main()
{
	Data* data1 = make<Data>();
	Data* data2 = make<Data>(3);
	Data* data3 = make<Data>(3.0);
	Data* data4 = make<Data>(3, 3.0);

	std::cout << *data1 << *data2 << *data3 << *data4;

	delete data1;
	delete data2;
	delete data3;
	delete data4;

	return 0;
}