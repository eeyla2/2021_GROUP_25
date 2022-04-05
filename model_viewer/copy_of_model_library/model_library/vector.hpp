//Vector header - Best
#ifndef VECTOR_HPP
#define VECTOR_HPP

/** @file
* Declaration of vector class
*/
/** Brief description
* Constructors, operators, specific calcualtions (dot and cross product)
*/

#include <iostream>

// using namespace std;

// using std::cout;
// using std::cin;
// using std::string;

class Vector3d
{
    friend class Matrix3x3;

public:

   /// Constructor
   Vector3d();
   Vector3d(int _vectorID, float _x, float _y, float _z);
   Vector3d(float _x, float _y, float _z);    //constructor for when doing maths and not interested in ID

   /// Copy Constructor
   Vector3d(const Vector3d& V);

   /// Assignment Operator
   Vector3d& operator=(const Vector3d& V);

   /// Mutators
   void set_vectorID(int _vectorID);
   void set_x(float _x);
   void set_y(float _y);
   void set_z(float _z);

   /// Accessors
   int get_vectorID();
   float get_x();
   float get_y();
   float get_z();

   /// Vector Addition
   Vector3d operator+(const Vector3d& V);
   Vector3d &operator+=(const Vector3d& V);

   /// Vector Subtraction
   Vector3d operator-(const Vector3d& V);
   Vector3d &operator-=(const Vector3d& V);

   //Vector Multiplication (multiplying vectors)
   Vector3d operator*(const Vector3d& V); //const Vector3d& V, float num
   Vector3d operator*(const float& f);

   Vector3d operator/(const Vector3d& V); //dividing one vector by another
   Vector3d operator/(const float& f);


   /// Inner/Scalar/Dot Product
   float dotProduct(const Vector3d& V);

   /// Outer/Vector/Cross Product
   Vector3d crossProduct(const Vector3d& Va, const Vector3d& Vb);

   /// Print Result in Vector Format
   void print();

   /// Destructor
   ~Vector3d(){}

private:
   int vectorID;
   float x, y, z;
};

#endif
