#pragma once

#include <iostream>
#include <vector>

bool is_equal(double a, double b);

struct Point
{
	Point();
	Point(const double a, const double b);

	friend std::ostream& operator<<(std::ostream& stream, const Point& point);

	double x;
	double y;
};

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

	virtual void print() const = 0;
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
	
	virtual void print() const override;
	virtual double P() const override;
	virtual double S() const override;

protected:
	static const double pi;
	double m_a; //������
};

class Ellipse : public Circle
{
public:
	Ellipse();
	Ellipse(const Point& point, const double a, const double b);
	virtual ~Ellipse() = default;

	virtual void print() const override;
	virtual double P() const override;
	virtual double S() const override;

protected:
	double m_b; //����� �������
};

class Polygon : public Shape
{
protected:
	Polygon();
	Polygon(const Point& point, const Vector& v_1, const Vector& v_2);
	virtual ~Polygon() = default;

	virtual void print() const override = 0;
	virtual double P() const = 0;
	virtual double S() const = 0;

protected:
	Vector side_1;
	Vector side_2;
};

class Triangle : public Polygon
{
public:
	Triangle();
	Triangle(const Point& point, const Vector& v_1, const Vector& v_2);
	virtual ~Triangle() = default;

	virtual void print() const override;
	virtual double P() const override;
	virtual double S() const override;
};

class Square : public Polygon
{
public:
	Square();
	Square(const Point& point, const Vector& v_1, const Vector& v_2);
	virtual ~Square() = default;

	virtual void print() const override;
	virtual double P() const override;
	virtual double S() const override;
};

class Rectangle : public Polygon
{
public:
	Rectangle();
	Rectangle(const Point& point, const Vector& v_1, const Vector& v_2);
	virtual ~Rectangle() = default;

	virtual void print() const override;
	virtual double P() const override;
	virtual double S() const override;
};

class Parallelogram : public Polygon
{
public:
	Parallelogram();
	Parallelogram(const Point& point, const Vector& v_1, const Vector& v_2);
	virtual ~Parallelogram() = default;

	virtual void print() const override;
	virtual double P() const override;
	virtual double S() const override;
};

class Rhombus : public Polygon
{
public:
	Rhombus();
	Rhombus(const Point& point, const Vector& v_1, const Vector& v_2);
	virtual ~Rhombus() = default;

	virtual void print() const override;
	virtual double P() const override;
	virtual double S() const override;
};