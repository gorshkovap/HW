#pragma once

#include <iostream>
#include <vector>

bool is_equal(double a, double b);

struct Point
{
	Point();
	Point(const double a, const double b);

	double x;
	double y;
};

std::ostream& operator<<(std::ostream& stream, const Point& point);

class Vector
{
public:
	Vector();
	Vector(double a, double b);

	double len() const;

	double x;
	double y;
};

double vec_mul(const Vector& v_1, const Vector& v_2);

double scal_mul(const Vector& v_1, const Vector& v_2);

Vector operator-(const Vector& v_1, const Vector& v_2);

bool is_coll(const Vector& v_1, const Vector& v_2);

bool is_perp(const Vector& v_1, const Vector& v_2);

class Shape
{
protected:
	Shape();
	Shape(const Point& point);

public:
	virtual ~Shape() = default;

protected:
	virtual void print(std::ostream& stream) const = 0;
	virtual double P() const = 0;
	virtual double S() const = 0;

	friend std::ostream& operator<<(std::ostream& stream, const Shape& shape);

protected:
	Point m_point;
};

class Circle : public Shape
{
public:
	Circle();
	Circle(const Point& point, const double r);
	virtual ~Circle() = default;
	
	virtual void print(std::ostream& stream) const override;
	virtual double P() const override;
	virtual double S() const override;

protected:
	static const double pi;
	double m_a; //radius
};

class Ellipse : public Circle
{
public:
	Ellipse();
	Ellipse(const Point& point, const double a, const double b);
	virtual ~Ellipse() = default;

	virtual void print(std::ostream& stream) const override;
	virtual double P() const override;
	virtual double S() const override;

protected:
	double m_b; //semi-minor axis
};

class Polygon : public Shape
{
protected:
	Polygon() = default;
	Polygon(const Point& point, const Vector& v_1, const Vector& v_2);
	virtual ~Polygon() = default;

	virtual void print(std::ostream& stream) const override = 0;
	virtual double P() const = 0;
	virtual double S() const = 0;

protected:
	Vector side_1;
	Vector side_2;
};

class Triangle : public Polygon
{
public:
	Triangle() = default;
	Triangle(const Point& point, const Vector& v_1, const Vector& v_2);
	virtual ~Triangle() = default;

	virtual void print(std::ostream& stream) const override;
	virtual double P() const override;
	virtual double S() const override;
};

class Square : public Polygon
{
public:
	Square() = default;
	Square(const Point& point, const Vector& v_1, const Vector& v_2);
	virtual ~Square() = default;

	virtual void print(std::ostream& stream) const override;
	virtual double P() const override;
	virtual double S() const override;
};

class Rectangle : public Polygon
{
public:
	Rectangle() = default;
	Rectangle(const Point& point, const Vector& v_1, const Vector& v_2);
	virtual ~Rectangle() = default;

	virtual void print(std::ostream& stream) const override;
	virtual double P() const override;
	virtual double S() const override;
};

class Parallelogram : public Polygon
{
public:
	Parallelogram() = default;
	Parallelogram(const Point& point, const Vector& v_1, const Vector& v_2);
	virtual ~Parallelogram() = default;

	virtual void print(std::ostream& stream) const override;
	virtual double P() const override;
	virtual double S() const override;
};

class Rhombus : public Polygon
{
public:
	Rhombus() = default;
	Rhombus(const Point& point, const Vector& v_1, const Vector& v_2);
	virtual ~Rhombus() = default;

	virtual void print(std::ostream& stream) const override;
	virtual double P() const override;
	virtual double S() const override;
};