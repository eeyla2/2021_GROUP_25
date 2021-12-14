//Vector class - Best

////Sample

#include <iostream>
#include <vector>

using namespace std;

class Vector3d 
{
public:
   //constructor
   Vector3d();
   vector3d(int &vectorID, float x, float y, float z);
   //destructor
   ~vector3d();

private:
   int vectorID;
   float x;
   float y;
   float z;
};

Vector3d::Vector3d(int vectorID, float &x, float &y, float &z){
   this->vectorID = vectorID;
   this->x = x;
   this->y = y;
   this->z = z;
}

//mutator
void Vector3d::set_vectorID() {this->vectorID = vectorID; }
void Vector3d::set_x {this->x = x; }
void Vector3d::set_y {this->y = y; }
void Vector3d::set_z {this->z = z; }

//accessor
int Vector3d::get_vectorID() { return this->vectorID; }
float Vector3d::get_x() { return this->x; }
float Vector3d::get_y() { return this->y; }
float Vector3d::get_z() { return this->z; }


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