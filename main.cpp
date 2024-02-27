#include <iostream>

using namespace std;

class Vector {
    public:
    
        float x, y;
        float magnitude();
        Vector AddVector(Vector vec);
        Vector SubtractVector(Vector vec);
        Vector ScaleBy(float value);
        Vector Normalize();

};

class Point {
    public:
        
        float x, y;
        Point AddVector(Vector vec);
        Point SubtractVector(Vector vec);
        Point DistanceToPoint(Point point);

};


float Vector::magnitude() {

    return sqrt(x*x + y*y);

}
Vector Vector::Normalize() {
    
    Vector resultVector;
    return resultVector;
}

Vector Vector::AddVector(Vector vec) {

    Vector newVector;

    newVector.x = x + vec.x;
    newVector.y = y + vec.y;

    return newVector;
}

Point Point::AddVector(Vector vec) {
    Point newPoint;

    newPoint.x = x + vec.x;
    newPoint.y = y + vec.y;

    return newPoint;
}


int main() {

    Point A;
    A.x = 3;
    A.y = 4;

    Vector B;
    B.x = 2;
    B.y = 4;

    Point C = A.AddVector(B);
    
    cout << "(" << C.x << ", " << C.y << ")";
    cout << B.magnitude();
}