//matrix.cpp


#include <iostream>

#include "matrix.hpp"

/// Constructors
Matrix3x3::Matrix3x3() {}

Matrix3x3::Matrix3x3(float _i00, float _i01, float _i02,
                     float _i10, float _i11, float _i12,
                     float _i20, float _i21, float _i22)
{
    matrix[0][0] = _i00;
    matrix[0][1] = _i01;
    matrix[0][2] = _i02;
    matrix[1][0] = _i10;
    matrix[1][1] = _i11;
    matrix[1][2] = _i12;
    matrix[2][0] = _i20;
    matrix[2][1] = _i21;
    matrix[2][2] = _i22;
}

Matrix3x3::Matrix3x3(char letter, float theta)
{
    switch (letter)
    {
    case ' ':
        //zero matrix
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                matrix[i][j] = 0;
            }
        }
        break;
    case 'i':
        //identity matrix
        matrix[0][0] = 1;
        matrix[0][1] = 0;
        matrix[0][2] = 0;
        matrix[1][0] = 0;
        matrix[1][1] = 1;
        matrix[1][2] = 0;
        matrix[2][0] = 0;
        matrix[2][1] = 0;
        matrix[2][2] = 1;
        break;
    case 'x':
        //create matrix for rotation about x axis
        matrix[0][0] = 1;
        matrix[0][1] = 0;
        matrix[0][2] = 0;
        matrix[1][0] = 0;
        matrix[1][1] = cos(theta);
        matrix[1][2] = -sin(theta);
        matrix[2][0] = 0;
        matrix[2][1] = sin(theta);
        matrix[2][2] = cos(theta);
        break;
    case 'y':
        //rotation about y-axis matrix
        matrix[0][0] = cos(theta);
        matrix[0][1] = 0;
        matrix[0][2] = sin(theta);
        matrix[1][0] = 0;
        matrix[1][1] = 1;
        matrix[1][2] = 0;
        matrix[2][0] = -sin(theta);
        matrix[2][1] = 0;
        matrix[2][2] = cos(theta);
        break;
    case 'z':
        //rotation about z-axis matrix
        matrix[0][0] = cos(theta);
        matrix[0][1] = -sin(theta);
        matrix[0][2] = 0;
        matrix[1][0] = sin(theta);
        matrix[1][1] = cos(theta);
        matrix[1][2] = 0;
        matrix[2][0] = 0;
        matrix[2][1] = 0;
        matrix[2][2] = 1;
        break;
    }
}

/// Copy Constructor
Matrix3x3::Matrix3x3(const Matrix3x3 &M)
{
    matrix[0][0] = M.matrix[0][0];
    matrix[0][1] = M.matrix[0][1];
    matrix[0][2] = M.matrix[0][2];
    matrix[1][0] = M.matrix[1][0];
    matrix[1][1] = M.matrix[1][1];
    matrix[1][2] = M.matrix[1][2];
    matrix[2][0] = M.matrix[2][0];
    matrix[2][1] = M.matrix[2][1];
    matrix[2][2] = M.matrix[2][2];
}

/// Assignment Operator
Matrix3x3 &Matrix3x3::operator=(const Matrix3x3 &M)
{
    matrix[0][0] = M.matrix[0][0];
    matrix[0][1] = M.matrix[0][1];
    matrix[0][2] = M.matrix[0][2];
    matrix[1][0] = M.matrix[1][0];
    matrix[1][1] = M.matrix[1][1];
    matrix[1][2] = M.matrix[1][2];
    matrix[2][0] = M.matrix[2][0];
    matrix[2][1] = M.matrix[2][1];
    matrix[2][2] = M.matrix[2][2];
    return *this;
}

/// Mutators
void Matrix3x3::set_i00(float _i00) { matrix[0][0] = _i00; }
void Matrix3x3::set_i01(float _i01) { matrix[0][1] = _i01; }
void Matrix3x3::set_i02(float _i02) { matrix[0][2] = _i02; }
void Matrix3x3::set_i10(float _i10) { matrix[1][0] = _i10; }
void Matrix3x3::set_i11(float _i11) { matrix[1][1] = _i11; }
void Matrix3x3::set_i12(float _i12) { matrix[1][2] = _i12; }
void Matrix3x3::set_i20(float _i20) { matrix[2][0] = _i20; }
void Matrix3x3::set_i21(float _i21) { matrix[2][1] = _i21; }
void Matrix3x3::set_i22(float _i22) { matrix[2][2] = _i22; }

/// Accessors
float Matrix3x3::get_i00() { return matrix[0][0]; }
float Matrix3x3::get_i01() { return matrix[0][1]; }
float Matrix3x3::get_i02() { return matrix[0][2]; }
float Matrix3x3::get_i10() { return matrix[1][0]; }
float Matrix3x3::get_i11() { return matrix[1][1]; }
float Matrix3x3::get_i12() { return matrix[1][2]; }
float Matrix3x3::get_i20() { return matrix[2][0]; }
float Matrix3x3::get_i21() { return matrix[2][1]; }
float Matrix3x3::get_i22() { return matrix[2][2]; }

/// Matrix Addition
Matrix3x3 Matrix3x3::operator+(const Matrix3x3 &M)
{
    return Matrix3x3(matrix[0][0] + M.matrix[0][0], matrix[0][1] + M.matrix[0][1], matrix[0][2] + M.matrix[0][2],
                     matrix[1][0] + M.matrix[1][0], matrix[1][1] + M.matrix[1][1], matrix[1][2] + M.matrix[1][2],
                     matrix[2][0] + M.matrix[2][0], matrix[2][1] + M.matrix[2][1], matrix[2][2] + M.matrix[2][2]);
}

Matrix3x3 &Matrix3x3::operator+=(const Matrix3x3 &M)
{
    matrix[0][0] += M.matrix[0][0];
    matrix[0][1] += M.matrix[0][1];
    matrix[0][2] += M.matrix[0][2];
    matrix[1][0] += M.matrix[1][0];
    matrix[1][1] += M.matrix[1][1];
    matrix[1][2] += M.matrix[1][2];
    matrix[2][0] += M.matrix[2][0];
    matrix[2][1] += M.matrix[2][1];
    matrix[2][2] += M.matrix[2][2];
    return *this;
}

/// Matrix Subtraction
Matrix3x3 Matrix3x3::operator-(const Matrix3x3 &M)
{
    return Matrix3x3(matrix[0][0] - M.matrix[0][0], matrix[0][1] - M.matrix[0][1], matrix[0][2] - M.matrix[0][2],
                     matrix[1][0] - M.matrix[1][0], matrix[1][1] - M.matrix[1][1], matrix[1][2] - M.matrix[1][2],
                     matrix[2][0] - M.matrix[2][0], matrix[2][1] - M.matrix[2][1], matrix[2][2] - M.matrix[2][2]);
}

Matrix3x3 &Matrix3x3::operator-=(const Matrix3x3 &M)
{
    matrix[0][0] -= M.matrix[0][0];
    matrix[0][1] -= M.matrix[0][1];
    matrix[0][2] -= M.matrix[0][2];
    matrix[1][0] -= M.matrix[1][0];
    matrix[1][1] -= M.matrix[1][1];
    matrix[1][2] -= M.matrix[1][2];
    matrix[2][0] -= M.matrix[2][0];
    matrix[2][1] -= M.matrix[2][1];
    matrix[2][2] -= M.matrix[2][2];
    return *this;
}

/// Matrix Multiplication
Matrix3x3 Matrix3x3::operator*(const Matrix3x3 &M) //matrix*matrix   - return matrix
{
    Matrix3x3 result;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            //float mult = f*matrix[i][j];
            result.matrix[i][j] = M.matrix[i][j] * matrix[i][j];
        }
    }
    return result;
}

Vector3d Matrix3x3::operator*(const Vector3d &V) //matrix*vector   - return vector
{
    float xResult = matrix[0][0] * V.x + matrix[0][1] * V.y + matrix[0][2] * V.z;
    float yResult = matrix[1][0] * V.x + matrix[1][1] * V.y + matrix[1][2] * V.z;
    float zResult = matrix[2][0] * V.x + matrix[2][1] * V.y + matrix[2][2] * V.z;
    Vector3d resultVector = Vector3d(xResult, yResult, zResult);
    return resultVector;
}

Matrix3x3 Matrix3x3::operator*(const float &f) //      matrix*constant - return matrix
{
    Matrix3x3 result;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            //float mult = f*matrix[i][j];
            result.matrix[i][j] = f * matrix[i][j];
        }
    }
    return result;
}

//determinant

float Matrix3x3::det3x3()
{
    float result = matrix[0][0] * matrix[1][1] * matrix[2][2] - matrix[0][0] * matrix[1][2] * matrix[2][1] - matrix[0][1] * matrix[1][0] * matrix[2][2] + matrix[0][1] * matrix[1][2] * matrix[2][0] + matrix[0][2] * matrix[1][0] * matrix[2][1] - matrix[0][2] * matrix[1][1] * matrix[2][0];
    return result;
}

// /// Matrix Transpose
Matrix3x3 Matrix3x3::transpose()
{
    Matrix3x3 transposed;
    float temp;
    for (int i = 0; i < 3; i++)
    {
        for (int j = i; j < 3; j++)
        {
            temp = matrix[i][j];
            transposed.matrix[i][j] = matrix[j][i];
            transposed.matrix[j][i] = temp;
        }
    }
    return transposed;
}

//Matrix Inversion
Matrix3x3 Matrix3x3::inverse()
{
    Matrix3x3 inverseMatrix;
    float det = this->det3x3();
    if (det == 0)
    {
        std::cout << "This matrix has no inverse (det is zero)";
        return inverseMatrix; //this is currently not ideal
    }
    else
    {
        //not the most efficent way of doing this
        inverseMatrix.matrix[0][0] = matrix[1][1] * matrix[2][2] - matrix[1][2] * matrix[2][1];
        inverseMatrix.matrix[0][1] = matrix[1][0] * matrix[2][2] - matrix[1][2] * matrix[2][0];
        inverseMatrix.matrix[0][2] = matrix[1][0] * matrix[2][1] - matrix[1][1] * matrix[2][0];
        inverseMatrix.matrix[1][0] = matrix[0][1] * matrix[2][2] - matrix[0][2] * matrix[2][1];
        inverseMatrix.matrix[1][1] = matrix[0][0] * matrix[2][2] - matrix[0][2] * matrix[2][0];
        inverseMatrix.matrix[1][2] = matrix[0][0] * matrix[2][1] - matrix[0][1] * matrix[2][0];
        inverseMatrix.matrix[2][0] = matrix[0][1] * matrix[1][2] - matrix[0][2] * matrix[1][1];
        inverseMatrix.matrix[2][1] = matrix[0][0] * matrix[1][2] - matrix[0][2] * matrix[1][0];
        inverseMatrix.matrix[2][2] = matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];
        inverseMatrix = inverseMatrix * (1 / det);
    }
    return inverseMatrix;
}

/// Print Result in Matrix Format
void Matrix3x3::printMatrix()
{
    std::cout << "[" << matrix[0][0] << "," << matrix[0][1] << "," << matrix[0][2] << " \n";
    std::cout << " " << matrix[1][0] << "," << matrix[1][1] << "," << matrix[1][2] << " \n";
    std::cout << " " << matrix[2][0] << "," << matrix[2][1] << "," << matrix[2][2] << "]\n";
}

Matrix3x3::~Matrix3x3() {}  //destructor

