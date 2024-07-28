#include <iostream>
using namespace std;

class Point {
public:
    float x, y;
    Point(float x=0, float y=0);
    void printCoordinates();
};

class Vector : public Point {
public:
    using Point::Point;
    Vector operator+(Vector vec);
    Vector operator-(Vector vec);
    Vector operator*(int scalar);
    Vector operator/(int scalar);
    float magnitude();
    float magnitudeSquared();
    Vector normalize();
};




Point::Point(float x, float y) {
    this -> x = x;
    this -> y = y;
};

void Point::printCoordinates() {
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

Vector Vector::operator/(int scalar) {
    Vector result;
    result.x = x / scalar;
    result.y = y / scalar;
    return result;
};

float Vector::magnitude() {
    return sqrt(x*x + y*y);
};

float Vector::magnitudeSquared() {
    return x*x + y*y;
};

Vector Vector::normalize() {
    float mag = magnitude();
    Vector result;
    result.x = x / mag;
    result.y = y / mag;
    return result;
};









int main() {

    int movementSpeed = 5;

    Vector position = Vector(1, 2);
    Vector velocity = Vector(3, 4).normalize() * movementSpeed;
    Vector friction = Vector(0.1, 0.1);

    position.printCoordinates();
    velocity.printCoordinates();
    friction.printCoordinates();

    position = position + velocity - friction;

    position.printCoordinates();
    velocity.printCoordinates();
    friction.printCoordinates();

    cout << "Magnitude: " << position.magnitude() << endl;

    return 0;

};