//Vector class - Best

#include <iostream>
//#include <vector>

// To be done: Accessing Vector Data from Eg. ListOfVectors, vectorID

using namespace std;

class Vector3d
{
public:

   /// Constructor
//   Vector3d(int &vectorID, float x, float y, float z);
   Vector3d();
   Vector3d(float _x, float _y, float _z);

   /// Copy Constructor
   Vector3d(const Vector3d& V);

   /// Assignment Operator
   Vector3d& operator=(const Vector3d& V);

   /// Sets
//   void Vector3d::set_vectorID() {this->vectorID = vectorID; }
   void set_x(float _x);
   void set_y(float _y);
   void set_z(float _z);

   /// Gets
//   int Vector3d::get_vectorID() { return this->vectorID; }
   float get_x();
   float get_y();
   float get_z();

   /// Vector Addition
   Vector3d operator+(const Vector3d& V);
   Vector3d &operator+=(const Vector3d& V);

   /// Vector Subtraction
   Vector3d operator-(const Vector3d& V);
   Vector3d &operator-=(const Vector3d& V);

   /// Inner/Scalar/Dot Product
   float dotProduct(const Vector3d& V);

   /// Outer/Vector/Cross Product
   Vector3d crossProduct(const Vector3d& V);

   /// Print Result
   void print();

   /// Destructor
   ~Vector3d(){}

private:
   //int vectorID;
   float x, y, z;
};

//------------------------------------------------------------------------------

Vector3d::Vector3d(float _x, float _y, float _z)
{
    x = _x;
    y = _y;
    z = _z;
}

Vector3d::Vector3d(const Vector3d &V)
{
    x = V.x;
    y = V.y;
    z = V.z;
}

/// Sets
void Vector3d::set_x(float _x) {x = _x;}
void Vector3d::set_y(float _y) {y = _y;}
void Vector3d::set_z(float _z) {z = _z;}

/// Gets
float Vector3d::get_x() {return x;}
float Vector3d::get_y() {return y;}
float Vector3d::get_z() {return z;}

/// Vector Addition
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

/// Vector Subtraction
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

/// Inner/Scalar/Dot Product
float Vector3d::dotProduct(const Vector3d& V)
{
    return x*V.x + y*V.y + z*V.z;
}

/// Outer/Vector/Cross Product
Vector3d Vector3d::crossProduct(const Vector3d& V)
{
    Vector3d resultCrossProduct=Vector3d(resultCrossProduct.x,resultCrossProduct.y,resultCrossProduct.z);
    resultCrossProduct.x = y*V.z - z*V.y;
    resultCrossProduct.y = z*V.x - x*V.z;
    resultCrossProduct.z = x*V.y - y*V.x;
    return resultCrossProduct;
}

/// Print Result in Vector Format
void Vector3d::print()
{
    cout<<"["<<x<<","<<y<<","<<z<<"]\n";
}

//------------------------------------------------------------------------------

// Sample test main
int main()
{
    // Initialize Vector Coordinates
    float x,y,z;
    Vector3d A=Vector3d(x,y,z);

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
    Vector3d B(x,y,z);

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
    cout<<"Dot Product = "<<A.dotProduct(B)<<"\n";

    // Perform Outer/Vector/Cross Product
    Vector3d cross = A.crossProduct(B);
    cout<<"Cross Product = ";
    cross.print();
}