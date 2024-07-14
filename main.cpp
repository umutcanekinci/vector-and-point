#include <iostream>
using namespace std;

class Point {
public:
    int x, y;
    Point(int x=0, int y=0);
    void PrintCoordinates();
};

class Vector : public Point {
public:
    using Point::Point;
    Vector operator+(Vector vec);
    Vector operator-(Vector vec);
    Vector operator*(int scalar);
};

Point::Point(int x, int y) {
    this->x = x;
    this->y = y;
};

void Point::PrintCoordinates() {
    cout << "(" << x << ", " << y << ")" << endl;
};

Vector Vector::operator+(Vector vec) {
    Vector result;
    result.x = x + vec.x;
    result.y = y + vec.y;
    return result;
};

Vector Vector::operator-(Vector vec) {
    Vector result;
    result.x = x - vec.x;
    result.y = y - vec.y;
    return result;
};

Vector Vector::operator*(int scalar) {
    Vector result;
    result.x = x * scalar;
    result.y = y * scalar;
    return result;
};

int main() {

    Vector p1(1, 2), p2(3, 4);
    p1.PrintCoordinates();
    p2.PrintCoordinates();
    Vector p3 = p1 + p2;
    p3.PrintCoordinates();
    return 0;

};