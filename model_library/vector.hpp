// vector.hpp
#ifndef VECTOR_HPP
#define VECTOR_HPP

/** @file
 * Header file for vector class
 */

/** Brief description
 * Declaration of class constructors, operators etc.
 * The vector class is a friend of the matrix class
 */

#include <iostream>
using namespace std;

class Vector3d
{
   friend class Matrix3x3;

public:
   /**
    * Blank constructor for creating a new empty Vector class
    */
   Vector3d();

   /**
    *  Constructor for identifying each Model through its ID
    *  and its x,y,x coordinates accoridngly to set up a
    *  a Vector3d Class
    */
   Vector3d(int _vectorID, float _x, float _y, float _z);

   /**
    *  constructor for when doing maths and not interested in ID only the
    *  x,y, and z coordinates and accoridngly to set up a Vector3d Class
    */
   Vector3d(float _x, float _y, float _z);

   /** Copy Constructor which creates a copy of the Vector3d "V"
    */
   Vector3d(const Vector3d &V);

   /** Assignment Operator which assigns the values of the variables of the Vector3d "V"
    * to the Vector3d class on the right hand side of the operand
    */
   Vector3d &operator=(const Vector3d &V);

   /** Mutators which sets the value for private variable vectorID to be that of the variable
    */
   void set_vectorID(int _vectorID);

   /** Mutator which sets the value for private variable "x" to be that of the variable "_x"
    */
   void set_x(float _x);
   /** Mutator which sets the value for private variable "y" to be that of the variable  "_y"
    */
   void set_y(float _y);
   /** Mutator which sets the value for private variable "z" to be that of the variable "_z"
    */
   void set_z(float _z);

   /** Accessor which gets the value stored in the private variable "vectorID" wthout affecting its value
    */
   int get_vectorID();

   /** Accessor which gets the value stored in the private variable "x" wthout affecting its value
    */
   float get_x();

   /** Accessor which gets the value stored in the private variable "y" wthout affecting its value
    */
   float get_y();

   /** Accessor which gets the value stored in the private variable "z" wthout affecting its value
    */
   float get_z();

   /** tells addition operand how to add vector3d classes to each other
    */
   Vector3d operator+(const Vector3d &V);

   /** tells addition operand how to add vector3d classes to each other and store it inside the
    * the class at right hand of the operand
    */
   Vector3d &operator+=(const Vector3d &V);

   /** tells subtraction operand how to subtract vector3d classes from each other
    */
   Vector3d operator-(const Vector3d &V);

   /** tells subtract operand how to subtract vector3d classes from each other and store it inside the
    * the class at right hand of the operand
    */
   Vector3d &operator-=(const Vector3d &V);

   /** tells multiplication operand how to subtract vector3d classes from each other
    */
   Vector3d operator*(const Vector3d &V); // const Vector3d& V, float num

   /** tells multiplication operand how to multiply vector3d classes with a float
    */
   Vector3d operator*(const float &f);

   /** tells division operand how to divide vector3d classes from each other
    */
   Vector3d operator/(const Vector3d &V); // dividing one vector by another

   /** tells division operand how to divide vector3d classes with a float
    */
   Vector3d operator/(const float &f);

   /** function that does scalar/Inner/Dot product on vector3d class
    */
   float dotProduct(const Vector3d &V);

   /** function that does Outer/Vector/Cross Product on vector3d class
    */
   Vector3d crossProduct(const Vector3d &Va, const Vector3d &Vb);

   /** function that Prints Result in Vector Format
    */
   void print();

   /** Destructor
    */
   ~Vector3d() {}

private:
   int vectorID; /*!< an integer vectorID that stores the vector Id for each model */

   float x; /*!< a float x that stores x coordinate for each model */
   float y; /*!< a float y float that stores y coordinate for each model */
   float z; /*!< a float z that stores z coordinate for each model */
};

#endif
