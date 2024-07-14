#include <iostream>
using namespace std;

class Point {
public:
    float x, y;
    Point(float x=0, float y=0);
    void PrintCoordinates();
};

class Vector : public Point {
public:
    using Point::Point;
    Vector operator+(Vector vec);
    Vector operator-(Vector vec);
    Vector operator*(int scalar);
    float magnitude();
    Vector normalize();
};

Point::Point(float x, float y) {
    this -> x = x;
    this -> y = y;
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

float Vector::magnitude() {
    return sqrt(x*x + y*y);
};

Vector Vector::normalize() {
    float mag = magnitude();
    Vector result;
    result.x = x / mag;
    result.y = y / mag;
    return result;
};

int main() {

    Vector p1(1, 2), p2(3, 4);
    p1.PrintCoordinates();
    p2.PrintCoordinates();
    Vector p3 = p1 + p2;
    p3.PrintCoordinates();
    Vector p4 = p1 - p2;
    p4.PrintCoordinates();
    Vector p5 = p1 * 2;
    p5.PrintCoordinates();
    cout << p1.magnitude() << endl;
    Vector p6 = p1.normalize();
    p6.PrintCoordinates();
    cout << p6.magnitude() << endl;

    return 0;

};