//Vector class - Best
// To be done: Storing 3D Vectors in appropriate format, Scalar Product, Vector Product
#include <iostream>

#include <vector>

#include <math.h>

using namespace std;

class Vector3d
{
public:

   /// Constructor
   //Vector3d();
   //Vector3d(int &vectorID, float x, float y, float z);
   float x;
   float y;
   float z;

   Vector3d(float _x,float _y,float _z)
   {
        x=_x;
        y=_y;
        z=_z;
   }

   /// Copy Constructor
   Vector3d(const Vector3d& V);

   /// Assignment Operator
   Vector3d& operator=(const Vector3d& V);

   /// Destructor
//   ~Vector3d();

   /// Addition
   Vector3d operator+(const Vector3d &V);
   Vector3d &operator+=(const Vector3d &V);

   /// Subtraction
   Vector3d operator-(const Vector3d &V);
   Vector3d &operator-=(const Vector3d &V);

   /// Inner/Scalar Product
   Vector3d scalarProduct(const Vector3d& V);

   /// Outer/Cross Product
   Vector3d crossProduct(const Vector3d& V);

   /// Print Result
   void print();

private:
   //int vectorID;
//   float x;
//   float y;
//   float z;
};

//Vector3d::Vector3d(int vectorID, float &x, float &y, float &z){
//   this->vectorID = vectorID;
//   this->x = x;
//   this->y = y;
//   this->z = z;
//}

Vector3d::Vector3d(const Vector3d &V)
{
    x = V.x;
    y = V.y;
    z = V.z;
}

//mutator
//void Vector3d::set_vectorID() {this->vectorID = vectorID; }
//void Vector3d::set_x {this->x = x; }
//void Vector3d::set_y {this->y = y; }
//void Vector3d::set_z {this->z = z; }

// Accessor
//int Vector3d::get_vectorID() { return this->vectorID; }
//float Vector3d::get_x() { return this->x; }
//float Vector3d::get_y() { return this->y; }
//float Vector3d::get_z() { return this->z; }

/// Addition
Vector3d Vector3d::operator+(const Vector3d &V)
{
    return Vector3d(x+V.x,y+V.y,z+V.z);
}

Vector3d &Vector3d::operator+=(const Vector3d &V)
{
    x+=V.x;
    y+=V.y;
    z+=V.z;
    return *this;
}

/// Subtraction
Vector3d Vector3d::operator-(const Vector3d &V)
{
    return Vector3d(x-V.x,y-V.y,z-V.z);
}

Vector3d &Vector3d::operator-=(const Vector3d &V)
{
    x-=V.x;
    y-=V.y;
    z-=V.z;
    return *this;
}

void Vector3d::print()
{
    cout<<"["<<x<<","<<y<<","<<z<<"]\n";
}

// Sample test main
int main()
{

    Vector3d x1=Vector3d(6.2,2.8,4.3);
    Vector3d x2=Vector3d(3.7,8.3,1.7);

    Vector3d add1=x1+x2;
    add1.print();

    Vector3d sub1=x1-x2;
    sub1.print();
}

//        addition()
//        getSubtraction()
//        getScalarProduct()
//        getVectorProduct()
//        // Store vectors
//        // Addition: a+b = <x1+x2, y1+y2, z1+z2>
//        // Subtraction: a-b = <x1-x2, y1-y2, z1-z2>
//        // Scalar Product: a.b = x1x2 + y1y2 + z1z2
//        // Vector Product: axb = <>


// int main() {
//    float a1, a2, a3, b1, b2, b3, c1, c2, c3, d, addX, addY, addZ, subX, subY, subZ;
//    cout << "Enter components of first vector:\n";
//    cin >> a1 >> a2 >> a3;
//    cout << "Enter components of second vector:\n";
//    cin >> b1 >> b2 >> b3;

//    addX = a1+b1;
//    addY = a2+b2;
//    addZ = a3+b3;
//    cout << "\nAddition =" << "<" << addX << ", " << addY << ", " << addZ << ">";

//    subX = a1-b1;
//    subY = a2-b2;
//    subZ = a3-b3;
//    cout << "\nSubtraction =" << "<" << subX << ", " << subY << ", " << subZ << ">";

//    c1 = a2*b3-a3*b2;
//    c2 = a3*b1-a1*b3;
//    c3 = a1*b2-a2*b1;
//    cout << "\nCross Product =" << c1 << "i+ " << c2 << "j+ " << c3 << "k";

//    d = a1*b1 + a2*b2 + a3*b3;
//    cout << "\nDot Product = " << d;
// }