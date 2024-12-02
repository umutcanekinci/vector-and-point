#include <iostream>
using namespace std;

class Point {
public:

    /* Other way to declare the constructor especially when the constructor is more complex

    Point(double x=0, double y=0);

    Point::Point(double x, double y) {
        this -> x = x;
        this -> y = y;
    }
    */
    double x, y;
    Point(double x=0, double y=0) : x(x), y(y) {}
    void printCoordinates();

};

class Vector : public Point {
public:

    /* Constant Member Functions and Constant Arguments
        Constant member functions are member functions that do not modify the object they are called on and its members.
        They are declared by adding the const keyword at the end of the function declaration.

        Constant arguments are arguments that are passed to a function as constant references.
        They are used to prevent the function from modifying the argument.
        They are declared by adding the const keyword before the type of the argument.

    */

    using Point::Point;

    double magnitude() const;
    double magnitudeSquared() const;

    Vector normalized() const;
    Vector Cross(const Vector &vector) const;

    Vector operator+(const Vector &vector) const; 
    Vector operator-(const Vector &vector) const;
    Vector operator*(double scalar) const;
    Vector operator/(double scalar) const;

};

void Point::printCoordinates() {
    cout << "(" << x << ", " << y << ")" << endl;
}

double Vector::magnitude() const {
    return sqrt(magnitudeSquared());
}

double Vector::magnitudeSquared() const {
    return x * x + y * y;
}

Vector Vector::normalized() const{
    return Vector(x / magnitude(), y / magnitude());
}

Vector Vector::Cross(const Vector &vector) const {
    return Vector(x * vector.y - y * vector.x);
}

#pragma region Operators

Vector Vector::operator+(const Vector &vector) const {
    return Vector(x + vector.x, y + vector.y);
};

Vector Vector::operator-(const Vector &vector) const {
    return Vector(x - vector.x, y - vector.y);
};

Vector Vector::operator*(double scalar) const {
    return Vector(x * scalar, y * scalar);
}

Vector Vector::operator/(double scalar) const {
    return Vector(x / scalar, y / scalar);
};

#pragma endregion

void test() {

    int movementSpeed = 5;

    Vector position = Vector(1, 2);
    Vector velocity = Vector(3, 4).normalized() * movementSpeed;
    Vector friction = Vector(0.1, 0.1);

    position.printCoordinates();
    velocity.printCoordinates();
    friction.printCoordinates();

    position = position + velocity - friction;

    position.printCoordinates();
    velocity.printCoordinates();
    friction.printCoordinates();

    cout << "Magnitude: " << position.magnitude() << endl;

}

int main() {

    test();
    return 0;

}