#include "7.1 Header.hpp"
#include <cmath>

Point::Point() : x(0.0), y(0.0) {}
Point::Point(const double a,const double b) : x(a), y(b){}

std::ostream& operator<<(std::ostream& stream, const Point& point)
{
	std::cout << '(' << point.x << ", " << point.y << ')';
	return stream;
}

Vector::Vector() : x(0.0), y(0.0) {}
Vector::Vector(double a, double b) : x(a), y(b) {}

std::ostream& operator<<(std::ostream& stream, const Vector& vector)
{
	std::cout << '(' << vector.x << ", " << vector.y << ')';
	return stream;
}

double Vector::len() const
{
	return std::sqrt(x * x + y * y);
}

double vec_mul(const Vector& v_1, const Vector& v_2)
{
	return std::abs(v_1.x * v_2.y - v_1.y * v_2.x);
}

double scal_mul(const Vector& v_1, const Vector& v_2)
{
	return v_1.x * v_2.x + v_1.y * v_2.y;
}

bool is_coll(const Vector& v_1, const Vector& v_2)
{
	return is_equal(0, vec_mul(v_1, v_2));
}

bool is_perp(const Vector& v_1, const Vector& v_2)
{
	return is_equal(0, scal_mul(v_1, v_2));
}

Vector operator-(const Vector& v_1, const Vector& v_2)
{
	Vector v = {v_1.x - v_2.x, v_1.y - v_2.y};
	return v;
}

Shape::Shape() : m_point(){}
Shape::Shape(const Point & point) : m_point(point){}

std::ostream& operator<<(std::ostream& stream, const Shape& shape)
{
	shape.print();
	return stream;
}

Circle::Circle() : m_a(0.0), Shape() {}
Circle::Circle(const Point & point, const double r): m_a(r), Shape(point) {}

void Circle::print() const
{
	std::cout << "Circle: O = " << m_point << " r = " << m_a << " P = " << P() << " S = " << S();
}

double Circle::P() const
{
	return 2 * pi * m_a;
}

double Circle::S() const
{
	return pi * m_a * m_a;
}

const double Circle::pi = 3.1416;

Ellipse::Ellipse() : m_b(0.0), Circle() {}
Ellipse::Ellipse(const Point & point ,const double a,const double b) : m_b(b), Circle(point, a) {}

void Ellipse::print() const
{
	std::cout << "Ellipse: O = " << m_point << " a = " << Circle::m_a << " b = " << m_b << " P = " << P() << " S = " << S();
}

double Ellipse::P() const
{
	return 4 * ((pi * m_a * m_b) + (m_a - m_b) * (m_a - m_b)) / (m_a + m_b);
}

double Ellipse::S() const
{
	return pi * m_a * m_b;
}

Polygon::Polygon() : Shape(), side_1(), side_2() {}
Polygon::Polygon(const Point & point, const Vector & v_1, const Vector & v_2)
		: Shape(point), side_1(v_1), side_2(v_2) 
{
	if (is_coll(v_1, v_2))
	{
		std::cerr << "\nerror: vectors are collinear\n";
		std::abort();
	}
}

Triangle::Triangle() : Polygon(){}
Triangle::Triangle(const Point& point, const Vector &v_1, const Vector &v_2) : Polygon(point, v_1, v_2){}

void Triangle::print() const
{
	std::cout << "Triangle: Starting point = " << m_point << " vector of side 1 = " << side_1 << " vector of side 2 = " << side_2 <<
		" P = " << P() << " S = " << S();
}

double Triangle::P() const
{
	Vector side_3 = side_1 - side_2;
	return side_1.len() + side_2.len() + side_3.len();
}

double Triangle::S() const
{
	return vec_mul(side_1, side_2) / 2;
}

Square::Square() : Polygon() {}
Square::Square(const Point& point, const Vector& v_1, const Vector& v_2) : Polygon(point, v_1, v_2)
{
	if (!(is_equal(side_1.len(), side_2.len())) || !(is_perp(v_1, v_2)))
	{
		std::cerr << "\nerror: different lenght of square's sides or the angle isn't right\n";
		std::abort();
	}
}

void Square::print() const
{
	std::cout << "Square: Starting point = " << m_point << " vector of side 1 = " << side_1 << " vector of side 2 = " << side_2 <<
		" lenght of sides = " << side_1.len() << " P = " << P() << " S = " << S();
}

double Square::P() const
{
	return 4 * side_1.len();
}

double Square::S() const
{
	return side_1.len() * side_1.len();
}

Rectangle::Rectangle() : Polygon() {}
Rectangle::Rectangle(const Point& point, const Vector& v_1, const Vector& v_2) : Polygon(point, v_1, v_2) {}

void Rectangle::print() const
{
	std::cout << "Rectangle: Starting point = " << m_point << " vector of side 1 = " << side_1 << " vector of side 2 = " << side_2 <<
		" lenght of side 1 = " << side_1.len() << " lenght of side 2 = " << side_2.len() << " P = " << P() << " S = " << S();
}

double Rectangle::P() const
{
	return 2 * (side_1.len() + side_2.len());
}

double Rectangle::S() const
{
	return side_1.len() * side_2.len();
}

Parallelogram::Parallelogram() : Polygon() {}
Parallelogram::Parallelogram(const Point& point, const Vector& v_1, const Vector& v_2) : Polygon(point, v_1, v_2) {}

void Parallelogram::print() const
{
	std::cout << "Parallelogram: Starting point = " << m_point << " vector of side 1 = " << side_1 << " vector of side 2 = " << side_2 <<
		" lenght of side 1 = " << side_1.len() << " lenght of side 2 = " << side_2.len() << " small angle = " <<
		std::asin(S() / (side_1.len() * side_2.len())) << "rad" << " P = " << P() << " S = " << S();
}

double Parallelogram::P() const
{
	return 2 * (side_1.len() + side_2.len());
}

double Parallelogram::S() const
{
	return vec_mul(side_1, side_2);
}

Rhombus::Rhombus() : Polygon() {}
Rhombus::Rhombus(const Point& point, const Vector& v_1, const Vector& v_2) : Polygon(point, v_1, v_2)
{
	if (!(is_equal(side_1.len(), side_2.len())))
	{
		std::cerr << "error: different lenght of sides of rhombus";
		std::abort();
	}
}

void Rhombus::print() const
{
	std::cout << "Rhombus: Starting point = " << m_point << " vector of side 1 = " << side_1 << " vector of side 2 = " << side_2 <<
		" lenght of side 1 = " << side_1.len() << " lenght of side 2 = " << side_2.len() << " small angle = " <<
		std::asin(S() / (side_1.len() * side_2.len())) << "rad" << " P = " << P() << " S = " << S();
}

double Rhombus::P() const
{
	return 2 * (side_1.len() + side_2.len());
}

double Rhombus::S() const
{
	return vec_mul(side_1, side_2);
}

bool is_equal(double a, double b)
{
	return std::abs(a - b) <= 10 * std::numeric_limits <double> ::epsilon();
}