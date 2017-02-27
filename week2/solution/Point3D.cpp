#include <iostream>
#include <cmath>

using std::cout;
using std::pow;
using std::sqrt;

struct Point3D {
	double x;
	double y;
	double z;

	Point3D(double _x, double _y, double _z) {
		x =  _x;
		y = _y;
		z = _z;
	}

	void translatePoint(double dx, double dy, double dz) {
		x += dx;
		y += dy;
		z += dz; 
	}

	double distanceToPoint(Point3D otherPoint) {
		return sqrt(
					pow (x - otherPoint.x, 2 ) + 
					pow (y - otherPoint.y, 2 ) +
					pow (z - otherPoint.z, 2)
				);
	}

};

Point3D createTranslatedPoint(Point3D point , double dx, double dy, double dz) {
	point.x += dx;
	point.y += dy;
	point.z += dz;

	return point;
}

//Бонус: подаваме конкретната точка, а не нейното копие
void translatePoint(Point3D &point, double dx, double dy, double dz) {
	point.x += dx;
	point.y += dy;
	point.z += dz;
}

double DistanceBetweenTwoPoints(Point3D p1 , Point3D p2) {
	return sqrt(
		pow(p1.x - p2.x, 2) +
		pow(p1.y - p2.y, 2) +
		pow(p1.z - p2.z, 2)
	);
}

class Point{
//по подразбиране тези полета са private: и не могат да се достъпят
	double x;
	double y;
	double z;

public:
	Point(double _x, double _y, double _z) : x(_x), y(_y), z(_z)
	{
	}
	/*
		Този запис е същия като:
		Point(double _x, double _y, double _z) {
			x = _x;
			y = _y;
			z = _z;
		}
	
	*/

	//функции(селектори) за достъпване на private: данните
	double getX() { return x; };
	double getY() { return y; };
	double getZ() { return z; };


	//функции(манипулатори) за промяна на private: данните
	void setX(double _x) {
		x = _x;
	}

	void setY(double _y) {
		y = _y;
	}

	void setZ(double _z) {
		z = _z;
	}

	void translatePoint(double dx, double dy, double dz) {
		setX(getX() + dx);
		setY(getY() + dy);
		setZ(getZ() + dz);
	}

	double distance(Point otherPoint) {
		//използваме this като пояснение, че става дума за нашата точка от класа.
		return sqrt(
			pow(this->x - otherPoint.getX(), 2) +
			pow(this->y - otherPoint.getY(), 2) +
			pow(this->z - otherPoint.getZ(), 2)
		);
	}
};



int main() {

	//инициализираме си 2 структури
	Point3D point(1,2,3);
	Point3D point2(2, 3, 4);

	//създаваме транслирана точка
	Point3D point3 = createTranslatedPoint(point, 3, 4, 5);

	//транслираме точка
	point3.translatePoint(-1, 0, 5);

	//БОНУС: транслираме подадената точка, без да създаваме нова
	translatePoint(point, 2, 3, 4);

	//пресмята разстоянието м/у нашата точка и подадена друга
	double distance = point.distanceToPoint(point2);

	//пресмята разстоянието м/у кои да е 2 точки
	double distance2 = DistanceBetweenTwoPoints(point, point2);

	//инициализираме си 2 точки използвайли class
	Point p1(1,2,3);
	Point p2(2, 3, 4);

	//преместваме нашата точка
	p2.translatePoint(1, 2, 3);

	//пресмятаме разстоянието м/у нашата и коя да е друга точка
	p1.distance(p2);




	system("pause");
	return 0;
}