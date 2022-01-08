//Matrix.cpp - Best

//Some comments / thoughts

// You will want constructors for different standard matricies
// some examples are where diagonals are 1, rest 0, (gets used in some operations)
// all zeros etc.

// How do we want to store data in matrix, array, std::vector (be careful to avoid confusion with Vector3d)

/// Objectives:
// Class Matrix3x3 to store 3x3 matrix data
// Range of Constructos to initialize different standard matrix types
// Perform Matrix Operations
// Ability to Initialize/Set a rotation matrix

#include <iostream>
using namespace std;

class Matrix3x3
{
public:

    /// Constructor
    Matrix3x3();
    Matrix3x3(float _i11, float _i12, float _i13,
              float _i21, float _i22, float _i23,
              float _i31, float _i32, float _i33);

    /// Copy Constructor
    Matrix3x3(const Matrix3x3& M);

    /// Assignment Operator
    Matrix3x3& operator=(const Matrix3x3& M);

    /// Mutators
    void set_i11(float _i11);
    void set_i12(float _i12);
    void set_i13(float _i13);
    void set_i21(float _i21);
    void set_i22(float _i22);
    void set_i23(float _i23);
    void set_i31(float _i31);
    void set_i32(float _i32);
    void set_i33(float _i33);

    /// Accessors
    float get_i11();
    float get_i12();
    float get_i13();
    float get_i21();
    float get_i22();
    float get_i23();
    float get_i31();
    float get_i32();
    float get_i33();

    /// Matrix Addition
    Matrix3x3 operator+(const Matrix3x3& M);
    Matrix3x3 &operator+=(const Matrix3x3& M);

    /// Matrix Subtraction
    Matrix3x3 operator-(const Matrix3x3& M);
    Matrix3x3 &operator-=(const Matrix3x3& M);

    /// Matrix Multiplication

    /// Matrix Inversion

    /// Matrix Transpose

   //Rotation Operations

   //Rotation about x-axis by angle theta
    //thinking
    /*
    Vector 3d myVector;
    Vector3d Matrix::rotate(vector3d, angle, axis)

    rotationX_byTheta()

    */


    /// Print Result in Matrix Format
   void printMatrix();

    /// Destructor
    ~Matrix3x3(){}

private:
    // float i11, i12, i13, i21, i22, i23, i31, i32, i33;

    // Restructured: from storing separate points into multidimensional arrays
    float matrix[3][3] = {};
};

/// Constructors
Matrix3x3::Matrix3x3(){}

Matrix3x3::Matrix3x3(float _i11, float _i12, float _i13,
                     float _i21, float _i22, float _i23,
                     float _i31, float _i32, float _i33)
{
    /*
    float storageMatrix[3][3] = { {_i11, _i12, _i13},
                            {_i21, _i22, _i23},
                            {_i31, _i32, _i33} };

    matrix = storageMatrix;
    */

    matrix[1][1] = _i11;
    matrix[1][2] = _i12;
    matrix[1][3] = _i13;
    matrix[2][1] = _i21;
    matrix[2][2] = _i22;
    matrix[2][3] = _i23;
    matrix[3][1] = _i31;
    matrix[3][2] = _i32;
    matrix[3][3] = _i33;
}

/// Copy Constructor
Matrix3x3::Matrix3x3(const Matrix3x3 &M)
{
    matrix[1][1] = M.matrix[1][1];
    matrix[1][2] = M.matrix[1][2];
    matrix[1][3] = M.matrix[1][3];
    matrix[2][1] = M.matrix[2][1];
    matrix[2][2] = M.matrix[2][2];
    matrix[2][3] = M.matrix[2][3];
    matrix[3][1] = M.matrix[3][1];
    matrix[3][2] = M.matrix[3][2];
    matrix[3][3] = M.matrix[3][3];
}

/// Assignment Operator
Matrix3x3 &Matrix3x3::operator=(const Matrix3x3& M)
{
    matrix[1][1] = M.matrix[1][1];
    matrix[1][2] = M.matrix[1][2];
    matrix[1][3] = M.matrix[1][3];
    matrix[2][1] = M.matrix[2][1];
    matrix[2][2] = M.matrix[2][2];
    matrix[2][3] = M.matrix[2][3];
    matrix[3][1] = M.matrix[3][1];
    matrix[3][2] = M.matrix[3][2];
    matrix[3][3] = M.matrix[3][3];
    return *this;
}

/// Mutators
void Matrix3x3::set_i11(float _i11) {matrix[1][1] = _i11;}
void Matrix3x3::set_i12(float _i12) {matrix[1][2] = _i12;}
void Matrix3x3::set_i13(float _i13) {matrix[1][3] = _i13;}
void Matrix3x3::set_i21(float _i21) {matrix[2][1] = _i21;}
void Matrix3x3::set_i22(float _i22) {matrix[2][2] = _i22;}
void Matrix3x3::set_i23(float _i23) {matrix[2][3] = _i23;}
void Matrix3x3::set_i31(float _i31) {matrix[3][1] = _i31;}
void Matrix3x3::set_i32(float _i32) {matrix[3][2] = _i32;}
void Matrix3x3::set_i33(float _i33) {matrix[3][3] = _i33;}

/// Accessors
float Matrix3x3::get_i11() {return matrix[1][1];}
float Matrix3x3::get_i12() {return matrix[1][2];}
float Matrix3x3::get_i13() {return matrix[1][3];}
float Matrix3x3::get_i21() {return matrix[2][1];}
float Matrix3x3::get_i22() {return matrix[2][2];}
float Matrix3x3::get_i23() {return matrix[2][3];}
float Matrix3x3::get_i31() {return matrix[3][1];}
float Matrix3x3::get_i32() {return matrix[3][2];}
float Matrix3x3::get_i33() {return matrix[3][3];}

/// Matrix Addition
Matrix3x3 Matrix3x3::operator+(const Matrix3x3& M)
{
    return Matrix3x3(matrix[1][1]+M.matrix[1][1], matrix[1][2]+M.matrix[1][2], matrix[1][3]+M.matrix[1][3],
                     matrix[2][1]+M.matrix[2][1], matrix[2][2]+M.matrix[2][2], matrix[2][3]+M.matrix[2][3],
                     matrix[3][1]+M.matrix[3][1], matrix[3][2]+M.matrix[3][2], matrix[3][3]+M.matrix[3][3]);
}

Matrix3x3 &Matrix3x3::operator+=(const Matrix3x3& M)
{
    matrix[1][1] += M.matrix[1][1];
    matrix[1][2] += M.matrix[1][2];
    matrix[1][3] += M.matrix[1][3];
    matrix[2][1] += M.matrix[2][1];
    matrix[2][2] += M.matrix[2][2];
    matrix[2][3] += M.matrix[2][3];
    matrix[3][1] += M.matrix[3][1];
    matrix[3][2] += M.matrix[3][2];
    matrix[3][3] += M.matrix[3][3];
    return *this;
}

/// Matrix Subtraction
Matrix3x3 Matrix3x3::operator-(const Matrix3x3& M)
{
    return Matrix3x3(matrix[1][1]-M.matrix[1][1], matrix[1][2]-M.matrix[1][2], matrix[1][3]-M.matrix[1][3],
                     matrix[2][1]-M.matrix[2][1], matrix[2][2]-M.matrix[2][2], matrix[2][3]-M.matrix[2][3],
                     matrix[3][1]-M.matrix[3][1], matrix[3][2]-M.matrix[3][2], matrix[3][3]-M.matrix[3][3]);
}

Matrix3x3 &Matrix3x3::operator-=(const Matrix3x3& M)
{
    matrix[1][1] -= M.matrix[1][1];
    matrix[1][2] -= M.matrix[1][2];
    matrix[1][3] -= M.matrix[1][3];
    matrix[2][1] -= M.matrix[2][1];
    matrix[2][2] -= M.matrix[2][2];
    matrix[2][3] -= M.matrix[2][3];
    matrix[3][1] -= M.matrix[3][1];
    matrix[3][2] -= M.matrix[3][2];
    matrix[3][3] -= M.matrix[3][3];
    return *this;
}

/// Matrix Multiplication

/// Matrix Inversion

/// Matrix Transpose

/// Print Result in Matrix Format
void Matrix3x3::printMatrix()
{
    cout<<"["<<matrix[1][1]<<","<<matrix[1][2]<<","<<matrix[1][3]<<" \n";
    cout<<" "<<matrix[2][1]<<","<<matrix[2][2]<<","<<matrix[2][3]<<" \n";
    cout<<" "<<matrix[3][1]<<","<<matrix[3][2]<<","<<matrix[3][3]<<"]\n";
}

//------------------------------------------------------------------------------

// Test program to test Matrix3x3 class functionalities

/*
// A successful run displays the following:

Matrix A =
[1,2,3
 4,5,6
 7,8,9]

Matrix B =
[9,8,7
 6,5,4
 3,2,1]


Matrix Addition A+B =
[10,10,10
 10,10,10
 10,10,10]

Matrix Subtraction A-B =
[-8,-6,-4
 -2,0,2
 4,6,8]
*/

int main()
{
    Matrix3x3 A(1, 2, 3, 4, 5, 6, 7, 8, 9);

    Matrix3x3 B(9, 8, 7, 6, 5, 4, 3, 2, 1);

    cout<<"\nMatrix A = \n";
    A.printMatrix();

    cout<<"\nMatrix B = \n";
    B.printMatrix();

    // Perform Matrix Addition
    Matrix3x3 add = A+B;
    cout<<"\n\nMatrix Addition A+B = \n";
    add.printMatrix();

    // Perform Matrix Subtraction
    Matrix3x3 sub = A-B;
    cout<<"\nMatrix Subtraction A-B = \n";
    sub.printMatrix();
}
