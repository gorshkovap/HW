#include "7.1 Header.hpp"

int main()
{
	Point point = { 0,0 };

	std::vector <Shape*> shapes;

	shapes.push_back(new Ellipse(point, 1.0, 2.0));
	shapes.push_back(new Circle(point, 5.0));

	Vector v_1 = { 5, 0 }, v_2 = { 0, 5 }, v_3 = { 4, 3 }, v_4 = { 0, 6 };


	shapes.push_back(new Square(point, v_1, v_2));
	shapes.push_back(new Triangle(point, v_1, v_2));
	shapes.push_back(new Rectangle(point, v_1, v_2));
	shapes.push_back(new Rhombus(point, v_1, v_2));
	shapes.push_back(new Parallelogram(point, v_1, v_2));
	/*shapes.push_back(new Square(point, v_1, v_3));*/        // - doesn't work
	/*shapes.push_back(new Square(point, v_1, v_4));*/        // - doesn't work
	/*shapes.push_back(new Parallelogram(point, v_2, v_4));*/ // - doesn't work
	/*shapes.push_back(new Rectangle(point, v_1, v_3));*/     // - doesn't work
	
	for (auto e : shapes)
	{
		std::cout << *e << "\n\n";
	}
	return 0;
}