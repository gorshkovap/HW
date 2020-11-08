#include <iostream>

class BaseVirtual
{
public:
	virtual ~BaseVirtual() noexcept = default;
	virtual void print(std::ostream & stream) const = 0;
};

class DerivedVirtual : public BaseVirtual
{
public:
	DerivedVirtual() : m_i(0) {}
	DerivedVirtual(int i) : m_i(i) {}

	virtual void print(std::ostream& stream) const override
	{
		stream << m_i;
	}

private:
	int m_i;
};

template <typename Derived>
class BaseCRTP
{
public:
	virtual ~BaseCRTP() noexcept = default;

	void print(std::ostream& stream)
	{
		self()->print(stream);
	}
	
private:
	Derived* self()
	{
		return static_cast <Derived*>(this);
	}
};

class DerivedCRTP : public BaseCRTP<DerivedCRTP>
{
public:
	DerivedCRTP() : m_i(0) {}
	DerivedCRTP(int i) : m_i(i) {}

	void print(std::ostream& stream) const
	{
		stream << m_i;
	}

private:
	int m_i;
};

int main()
{
	BaseVirtual* ptr_1 = new DerivedVirtual(1);
	BaseCRTP<DerivedCRTP>* ptr_2 = new DerivedCRTP(2);

	ptr_1->print(std::cout);

	std::cout << '\n';

	ptr_2->print(std::cout);

	delete ptr_1;
	delete ptr_2;


	return 0;
}