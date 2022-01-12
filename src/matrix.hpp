//Matrix header - Best & Daniel
#include <iostream>
#include <math.h>
#include "vector.hpp"

//Reminder: Trig functions require arguments in radians

class Matrix3x3
{
public:
    /// Constructor
    Matrix3x3();
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
    Matrix3x3(char letter, float theta);

    /// Copy Constructor
    Matrix3x3(const Matrix3x3 &M);

    /// Assignment Operator
    Matrix3x3 &operator=(const Matrix3x3 &M);

    /// Mutators
    void set_i00(float _i00);
    void set_i01(float _i01);
    void set_i02(float _i02);
    void set_i10(float _i10);
    void set_i11(float _i11);
    void set_i12(float _i12);
    void set_i20(float _i20);
    void set_i21(float _i21);
    void set_i22(float _i22);

    /// Accessors
    float get_i00();
    float get_i01();
    float get_i02();
    float get_i10();
    float get_i11();
    float get_i12();
    float get_i20();
    float get_i21();
    float get_i22();

    /// Matrix Addition
    Matrix3x3 operator+(const Matrix3x3 &M);
    Matrix3x3 &operator+=(const Matrix3x3 &M);

    /// Matrix Subtraction
    Matrix3x3 operator-(const Matrix3x3 &M);
    Matrix3x3 &operator-=(const Matrix3x3 &M);

    /// Matrix Multiplication
    //we can assume that matrix multpication is always valid as 3x3 matrix and vector is 3x1
    Matrix3x3 operator*(const Matrix3x3 &M); //     matrix*matrix   - return matrix
    Vector3d operator*(const Vector3d &V);   //      matrix*vector   - return vector
    Matrix3x3 operator*(const float &f);     //      matrix*constant - return matrix

    //determinant
    float det3x3();

    //Matrix Inversion
    Matrix3x3 inverse();

    // Matrix Transpose
    Matrix3x3 transpose();

    /// Print Result in Matrix Format
    void printMatrix();

    /// Destructor
    ~Matrix3x3();

private:
    float matrix[3][3];
};