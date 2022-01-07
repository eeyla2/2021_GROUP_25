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

    /// Print Result in Matrix Format
   void printMatrix();

    /// Destructor
    ~Matrix3x3(){}

private:
    float i11, i12, i13, i21, i22, i23, i31, i32, i33;
};

/// Constructors
Matrix3x3::Matrix3x3(){}

Matrix3x3::Matrix3x3(float _i11, float _i12, float _i13,
                     float _i21, float _i22, float _i23,
                     float _i31, float _i32, float _i33)
{
    i11 = _i11;
    i12 = _i12;
    i13 = _i13;
    i21 = _i21;
    i22 = _i22;
    i23 = _i23;
    i31 = _i31;
    i32 = _i32;
    i33 = _i33;
}

/// Copy Constructor
Matrix3x3::Matrix3x3(const Matrix3x3 &M)
{
    i11 = M.i11;
    i12 = M.i12;
    i13 = M.i13;
    i21 = M.i21;
    i22 = M.i22;
    i23 = M.i23;
    i31 = M.i31;
    i32 = M.i32;
    i33 = M.i33;
}

/// Assignment Operator
Matrix3x3 &Matrix3x3::operator=(const Matrix3x3& M)
{
    i11 = M.i11;
    i12 = M.i12;
    i13 = M.i13;
    i21 = M.i21;
    i22 = M.i22;
    i23 = M.i23;
    i31 = M.i31;
    i32 = M.i32;
    i33 = M.i33;
    return *this;
}

/// Mutators
void Matrix3x3::set_i11(float _i11) {i11 = _i11;}
void Matrix3x3::set_i12(float _i12) {i12 = _i12;}
void Matrix3x3::set_i13(float _i13) {i13 = _i13;}
void Matrix3x3::set_i21(float _i21) {i21 = _i21;}
void Matrix3x3::set_i22(float _i22) {i22 = _i22;}
void Matrix3x3::set_i23(float _i23) {i23 = _i23;}
void Matrix3x3::set_i31(float _i31) {i31 = _i31;}
void Matrix3x3::set_i32(float _i32) {i32 = _i32;}
void Matrix3x3::set_i33(float _i33) {i33 = _i33;}

/// Accessors
float Matrix3x3::get_i11() {return i11;}
float Matrix3x3::get_i12() {return i12;}
float Matrix3x3::get_i13() {return i13;}
float Matrix3x3::get_i21() {return i21;}
float Matrix3x3::get_i22() {return i22;}
float Matrix3x3::get_i23() {return i23;}
float Matrix3x3::get_i31() {return i31;}
float Matrix3x3::get_i32() {return i32;}
float Matrix3x3::get_i33() {return i33;}

/// Matrix Addition
Matrix3x3 Matrix3x3::operator+(const Matrix3x3& M)
{
    return Matrix3x3(i11+M.i11, i12+M.i12, i13+M.i13,
                     i21+M.i21, i22+M.i22, i23+M.i23,
                     i31+M.i31, i32+M.i32, i33+M.i33);
}
Matrix3x3 &Matrix3x3::operator+=(const Matrix3x3& M)
{
    i11+=M.i11;
    i12+=M.i12;
    i13+=M.i13;
    i21+=M.i21;
    i22+=M.i22;
    i23+=M.i23;
    i31+=M.i31;
    i32+=M.i32;
    i33+=M.i33;
    return *this;
}

/// Matrix Subtraction
Matrix3x3 Matrix3x3::operator-(const Matrix3x3& M)
{
    return Matrix3x3(i11-M.i11, i12-M.i12, i13-M.i13,
                     i21-M.i21, i22-M.i22, i23-M.i23,
                     i31-M.i31, i32-M.i32, i33-M.i33);
}

Matrix3x3 &Matrix3x3::operator-=(const Matrix3x3& M)
{
    i11-=M.i11;
    i12-=M.i12;
    i13-=M.i13;
    i21-=M.i21;
    i22-=M.i22;
    i23-=M.i23;
    i31-=M.i31;
    i32-=M.i32;
    i33-=M.i33;
    return *this;
}

/// Matrix Multiplication

/// Matrix Inversion

/// Matrix Transpose

/// Print Result in Matrix Format
void Matrix3x3::printMatrix()
{
    cout<<"["<<i11<<","<<i12<<","<<i13<<" \n";
    cout<<" "<<i21<<","<<i22<<","<<i23<<" \n";
    cout<<" "<<i31<<","<<i32<<","<<i33<<"]\n";
}

//------------------------------------------------------------------------------

// Test program to test Matrix3x3 class functionalities
int main()
{
    float i11, i12, i13, i21, i22, i23, i31, i32, i33;

    Matrix3x3 A=Matrix3x3(i11, i12, i13, i21, i22, i23, i31, i32, i33);

    // Ask user to enter Coordinates of Matrix A
    cout<<"Enter i11, i12, i13, i21, i22, i23, i31, i32, i33 Coordinates of Matrix A: ";
    cin>>i11>>i12>>i13>>i21>>i22>>i23>>i31>>i32>>i33;

    // Set user defined Coordinates of Matrix A
    A.set_i11(i11);
    A.set_i12(i12);
    A.set_i13(i13);
    A.set_i21(i21);
    A.set_i22(i22);
    A.set_i23(i23);
    A.set_i31(i31);
    A.set_i32(i32);
    A.set_i33(i33);

    cout<<"\nMatrix A = \n";
    A.printMatrix();

    // Initialize and ask user to enter Coordinates of Matrix B
    cout<<"\nEnter i11, i12, i13, i21, i22, i23, i31, i32, i33 Coordinates of Matrix B: ";
    cin>>i11>>i12>>i13>>i21>>i22>>i23>>i31>>i32>>i33;
    Matrix3x3 B(i11, i12, i13, i21, i22, i23, i31, i32, i33);

    // Set user defined Coordinates of Matrix B
    B.set_i11(i11);
    B.set_i12(i12);
    B.set_i13(i13);
    B.set_i21(i21);
    B.set_i22(i22);
    B.set_i23(i23);
    B.set_i31(i31);
    B.set_i32(i32);
    B.set_i33(i33);

    cout<<"\nMatrix B = \n";
    B.printMatrix();

    //------------------------------------------------------------------------------

    // Perform Matrix Addition
    Matrix3x3 add = A+B;
    cout<<"\n\nMatrix Addition A+B = \n";
    add.printMatrix();

    // Perform Matrix Subtraction
    Matrix3x3 sub = A-B;
    cout<<"\nMatrix Subtraction A-B = \n";
    sub.printMatrix();
}
