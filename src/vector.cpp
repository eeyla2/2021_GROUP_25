//Vector class - Best

#include "vector.hpp"

/// Constructors
Vector3d::Vector3d() {}

Vector3d::Vector3d(int _vectorID, float _x, float _y, float _z)
{
    vectorID = _vectorID;
    x = _x;
    y = _y;
    z = _z;
}

Vector3d::Vector3d(float _x, float _y, float _z) //constructor without ID - for maths
{
    x = _x;
    y = _y;
    z = _z;
}

// Copy Constructor
Vector3d::Vector3d(const Vector3d &V) 
{
    vectorID = V.vectorID;
    x = V.x;
    y = V.y;
    z = V.z;
}

/// Assignment Operator
Vector3d &Vector3d::operator=(const Vector3d &V)
{
    if(this==&V) return(*this);

    vectorID = V.vectorID;
    x = V.x;
    y = V.y;
    z = V.z;
    return *this;
}

/// Mutators
void Vector3d::set_vectorID(int _vectorID) { vectorID = _vectorID; }
void Vector3d::set_x(float _x) { x = _x; }
void Vector3d::set_y(float _y) { y = _y; }
void Vector3d::set_z(float _z) { z = _z; }

/// Accessors
int Vector3d::get_vectorID() { return this->vectorID; }
float Vector3d::get_x() { return this->x; }
float Vector3d::get_y() { return this->y; }
float Vector3d::get_z() { return this->z; }

/// Vector Addition
Vector3d Vector3d::operator+(const Vector3d &V)
{
    return Vector3d(x + V.x, y + V.y, z + V.z); 
}

Vector3d &Vector3d::operator+=(const Vector3d &V)
{
    x += V.x;
    y += V.y;
    z += V.z;
    return *this;
}

/// Vector Subtraction
Vector3d Vector3d::operator-(const Vector3d &V)
{
    return Vector3d(x - V.x, y - V.y, z - V.z);
}

Vector3d &Vector3d::operator-=(const Vector3d &V)
{
    x -= V.x;
    y -= V.y;
    z -= V.z;
    return *this;
}

//Vector Multiplication (multiplying vectors)
Vector3d Vector3d::operator*(const Vector3d &V) //, float num
{
    return Vector3d(x * V.x, y * V.y, z * V.z);
}

Vector3d Vector3d::operator*(const float &f) //for multiplying a vector by a constant
{
    return Vector3d(x * f, y * f, z * f);
}

//Vector division
Vector3d Vector3d::operator/(const Vector3d &V)
{
    return Vector3d(x / V.x, y / V.y, z / V.z);
}

Vector3d Vector3d::operator/(const float &f)
{
    return Vector3d(x / f, y / f, z / f);
}

/// Inner/Scalar/Dot Product
float Vector3d::dotProduct(const Vector3d &V)
{
    return x * V.x + y * V.y + z * V.z;
}

/// Outer/Vector/Cross Product
Vector3d Vector3d::crossProduct(const Vector3d &Va, const Vector3d &Vb)
{
    Vector3d resultCrossProduct;
    resultCrossProduct.x = Va.y * Vb.z - Va.z * Vb.y;
    resultCrossProduct.y = Va.z * Vb.x - Va.x * Vb.z;
    resultCrossProduct.z = Va.x * Vb.y - Va.y * Vb.x;
    return resultCrossProduct;
}

/// Print Result in Vector Format
void Vector3d::print()
{
    cout << "[" << x << "," << y << "," << z << "]\n";
}

//------------------------------------------------------------------------------

/*
// Test program to test Vector3d class functionalities
int main()
{
    
    // Initialize Vector Coordinates
    int vectorID;
    float x,y,z;

    //Vector3d A=Vector3d(vectorID, x, y, z);
    Vector3d A;  
    // Ask user to enter Coordinates of Vector A
    cout<<"Enter x y z Coordinates of Vector A: ";
    cin>>x>>y>>z;

    // Set user defined Coordinates of Vector A
    A.set_x(x);
    A.set_y(y);
    A.set_z(z);
    cout<<"Vector A = ["<<A.get_x()<<","<<A.get_y()<<","<<A.get_z()<<"]\n\n";

    // Initialize and ask user to enter Coordinates of Vector B
    cout<<"Enter x y z Coordinates of vector B: ";
    cin>>x>>y>>z;
    //Vector3d B(vectorID, x, y, z);
    Vector3d B;

    // Set user defined Coordinates of Vector B
    B.set_x(x);
    B.set_y(y);
    B.set_z(z);
    cout<<"Vector B = ["<<B.get_x()<<","<<B.get_y()<<","<<B.get_z()<<"]\n\n";

    //------------------------------------------------------------------------------

    // Perform Vector Addition
    Vector3d add=A+B;
    cout<<"Vector Addition A+B = ";
    add.print();

    // Perform Vector Subtraction
    Vector3d sub=A-B;
    cout<<"Vector Subtraction A-B = ";
    sub.print();

    // Perform Inner/Scalar/Dot Product
    float dotProductResult=A.dotProduct(B);
    cout<<"Dot Product = "<<dotProductResult<<"\n";

    //testing multiplication
    Vector3d mult = A*B;
    cout << "A x B = ";
    mult.print();

    Vector3d multByConstant = A*3;
    cout << "A x 3 = ";
    multByConstant.print();

    //testing division
    Vector3d division = A/B;
    cout << "A/B = ";
    division.print();

    Vector3d divByConstant = B/1.34;
    cout << "B/1.34 = ";
    divByConstant.print();

    // Perform Outer/Vector/Cross Product
    Vector3d crossProductResult = crossProductResult.crossProduct(A, B);

    cout<<"Cross Product = ";
    crossProductResult.print();


}
*/
