//matrix.hpp
#ifndef MATRIX_HPP
#define MATRIX_HPP

/** @file
* Header file for matrix
*/

/** Brief description
* Contains class declartion for the Matrix calss
* Reminder: Trig functions require arguments in radians
*/

#include <iostream>
#include <math.h>
#include "vector.hpp"


class Matrix3x3
{
public:
  /**
    * Blank constructor for creating a new empty Matrix3x3 class
    */
    Matrix3x3();

    /**
    *  Constructor for storing the elements of a 3x3 matrix and accoridngly set up
    *  a Matrix3x3 Class
    */
    Matrix3x3(float _i00, float _i01, float _i02,
              float _i10, float _i11, float _i12,
              float _i20, float _i21, float _i22);

    //constructor for creating default matricies
    /* letter = ' ' - all zeros
              = 'i' - identity
              = 'x' - rotate about x by theta
              = 'y' - rotate about y by theta
              = 'z' - rotate about z by theta
    */

    /**
    *  Constructor for default/well known matricies(e.g identity matrix) inside the matrix and accoridngly set up a
    *  a Matrix3x3 Class
    */
    Matrix3x3(char letter, float theta);

    /** Copy Constructor which creates a copy of the Vector3d "V"
    */
    Matrix3x3(const Matrix3x3 &M);

    /** Assignment Operator which assigns the values of the variables of the matrix3x3 "M"
    * to the Matrix3x3 class on the right hand side of the operand
    */
    Matrix3x3 &operator=(const Matrix3x3 &M);

    /** Mutator which sets the value for private variable "i00" to be that of the variable "_i00"
    */
    void set_i00(float _i00);

    /** Mutator which sets the value for private variable "i01" to be that of the variable "_i01"
    */
    void set_i01(float _i01);

    /** Mutator which sets the value for private variable "i02" to be that of the variable "_i02"
    */
    void set_i02(float _i02);

    /** Mutator which sets the value for private variable "i10" to be that of the variable "_i10"
    */
    void set_i10(float _i10);

    /** Mutator which sets the value for private variable "i11" to be that of the variable "_i11"
    */
    void set_i11(float _i11);

    /** Mutator which sets the value for private variable "i12" to be that of the variable "_i12"
    */
    void set_i12(float _i12);

    /** Mutator which sets the value for private variable "i20" to be that of the variable "_i20"
    */
    void set_i20(float _i20);

    /** Mutator which sets the value for private variable "i21" to be that of the variable "_i21"
    */
    void set_i21(float _i21);

    /** Mutator which sets the value for private variable "i22" to be that of the variable "_i22"
    */
    void set_i22(float _i22);

    /** Accessor which gets the value stored in the private variable "i00" wthout affecting its value
    */
    float get_i00();

    /** Accessor which gets the value stored in the private variable "i01" wthout affecting its value
    */
    float get_i01();

    /** Accessor which gets the value stored in the private variable "i02" wthout affecting its value
    */
    float get_i02();

    /** Accessor which gets the value stored in the private variable "i10" wthout affecting its value
    */
    float get_i10();

    /** Accessor which gets the value stored in the private variable "i11" wthout affecting its value
    */
    float get_i11();

    /** Accessor which gets the value stored in the private variable "i12" wthout affecting its value
    */
    float get_i12();

    /** Accessor which gets the value stored in the private variable "i20" wthout affecting its value
    */
    float get_i20();

    /** Accessor which gets the value stored in the private variable "i21" wthout affecting its value
    */
    float get_i21();

    /** Accessor which gets the value stored in the private variable "i22" wthout affecting its value
    */
    float get_i22();

    /** tells addition operand how to add Matrix3x3 classes to each other
    */
    Matrix3x3 operator+(const Matrix3x3 &M);

    /** tells addition operand how to add Matrix3x3 classes to each other and store it inside the
    * the class at right hand of the operand
    */
    Matrix3x3 &operator+=(const Matrix3x3 &M);

    /** tells subtraction operand how to subtract Matrix3x3 classes from each other
    */
    Matrix3x3 operator-(const Matrix3x3 &M);

    /** tells subtract operand how to subtract Matrix3x3 classes from each other and store it inside the
    * the class at right hand of the operand
    */
    Matrix3x3 &operator-=(const Matrix3x3 &M);

    
    //we can assume that matrix multpication is always valid as 3x3 matrix and vector is 3x1
    /** tells multiplication operand how to multiply Matrix classes with each other
    */
    Matrix3x3 operator*(const Matrix3x3 &M); //     matrix*matrix   - return matrix

    /** tells multiplication operand how to multiply Matrix3x3 with a vector3d class
    */
    Vector3d operator*(const Vector3d &V);   //      matrix*vector   - return vector

    /** tells multiplication operand how to multiply Matrix3x3 classes with a float
    */
    Matrix3x3 operator*(const float &f);     //      matrix*constant - return matrix

    //determinant
    /** function that performs determinant operation on a Matrix3x3
    */
    float det3x3();

    
    /** function that performs Matrix inversion operation on a Matrix3x3
    */
    Matrix3x3 inverse();

    
    /** function that performs Matrix transpose operation on a Matrix3x3
    */
    Matrix3x3 transpose();

    /// Print Result in Matrix Format
    /** function that prints results in Matrix Format Matrix3x3
    */
    void printMatrix();

    /// Destructor
    ~Matrix3x3();

private:
    float matrix[3][3];/*!< a float 2D array matrix that stores matrix elements for each matrix */
};

#endif