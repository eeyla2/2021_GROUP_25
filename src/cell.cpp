#include <vector>

// classes are capital letters
class Vector3d
{
public:
  //constructor
  Vector3d();
  Vector3d(int &vectorID, float &x, float &y, float &z);
  ~Vector3d();
  //public here for ease of use

  int get_vectorID();
  float get_x();
  float get_y();
  float get_z();

private:
  int vectorID;
  float x;
  float y;
  float z;
};

Vector3d::Vector3d() {}

Vector3d::Vector3d(int &vectorID, float &x, float &y, float &z)
{
  this->vectorID = vectorID;
  this->x = x;
  this->y = y;
  this->z = z;
}

//accessor functions
int Vector3d::get_vectorID() { return this->vectorID; }
float Vector3d::get_x() { return this->x; }
float Vector3d::get_y() { return this->y; }
float Vector3d::get_z() { return this->z; }

Vector3d::~Vector3d() {}

// ONLY AN ABSTRACT FOR CLARITY
// this will be class material and i will inherit the characteristics to different types of material according to the indexID it has
class Cell
{
public:
    // Cell constructor for different Cell variants
    Cell();
    // cell class constructor for a tetrahedron
    Cell(char &cCellLetter, int &cCellIndex, Material &cTheMaterial, Vector3d &cP0, Vector3d &Cp1, Vector3d &cP2, Vector3d &cP3); // tetrahedron

    // cell class constructor for a hexahedron
    Cell(char &cCellLetter, int &cCellIndex, Material &cTheMaterial, Vector3d &cP0, Vector3d &cP1, Vector3d &cP2, Vector3d &cP3,
         Vector3d &cP4, Vector3d &cP5, Vector3d &cP6, Vector3d &cP7); // hexahedron

    // cell class constructor for pyramid
    Cell(char &cCellLetter, int &cCellIndex, Material &cTheMaterial, Vector3d &cP0, Vector3d &Cp1, Vector3d &cP2, Vector3d &cP3, Vector3d &cP4); // pyramid

    ~Cell(); // destructor for the cell called (works for the three constructors)

    // first get returns the value of cell Index, while second get returns the value of cell Letter and third one reteurns the Material Index
    int get_cellIndex();
    char get_cellLetter();
    int get_cellMaterialIndex();

    // get functions for all the points
    int get_cellp0();
    int get_cellp1();
    int get_cellp2();
    int get_cellp3();
    int get_cellp4();
    int get_cellp5();
    int get_cellp6();
    int get_cellp7();

    Material get_cellMaterial();

    // virtual function allows the correct version of volume and center of massto be called for each shape
    virtual double volume();
    virtual double centerofMass();
    double weight();

    // weight of the cell calculated

protected:
    int cellIndex;                           // the cell Index
    char cellLetter;                         // the cell letter
    Material theMaterial;                    // the material
    Vector3d p0, p1, p2, p3, p4, p5, p6, p7; // all possible points that could be used in a shape

    // the weight function that is currently in the Cell classes will actually be inherited
}

// incase the cell class is empty
Cell::Cell()
{
}

// tetrahedron
Cell::Cell(char &cCellLetter, int &cCellIndex, Material &cTheMaterial, Vector3d &cP0, Vector3d &Cp1, Vector3d &cP2, Vector3d &cP3)
{
    this->cellIndex = cCellIndex;
    this->cellLetter = cCellLetter;
    this->theMaterial = theMaterial;
    this->p0 = p0;
    this->p1 = p1;
    this->p2 = p2;
    this->p3 = p3;
}

// hexahedron
Cell::Cell(char &cCellLetter, int &cCellIndex, Material &cTheMaterial, Vector3d &cP0, Vector3d &cP1, Vector3d &cP2, Vector3d &cP3,
         Vector3d &cP4, Vector3d &cP5, Vector3d &cP6, Vector3d &cP7)
{
    this->cellIndex = cCellIndex;
    this->cellLetter = cellLetter;
    this->theMaterial = cTheMaterial;
    this->p0 = cP0;
    this->p1 = cP1;
    this->p2 = cP2;
    this->p3 = cP3;
    this->p4 = cP4;
    this->p5 = cP5;
    this->p6 = cP6;
    this->p7 = cP7;
}

// pyramid
Cell::Cell(char &cCellLetter, int &cCellIndex, Material &cTheMaterial, Vector3d &cP0, Vector3d &cP1, Vector3d &cP2, Vector3d &cP3, Vector3d &cP4)
{
    this->cellIndex = cCellIndex;
    this->cellLetter = cCellLetter;
    this->theMaterial = cTheMaterial;
    this->p0 = cP0;
    this->p1 = cP1;
    this->p2 = cP2;
    this->p3 = cP3;
    this->p4 = cP4;
}

// an accessor/get function to access the data for Index in the private part of the Cell class
int Cell::get_cellIndex() { return this->cellIndex; }

// an accessor/get function to access the data for Letter in the private part of the Cell class
char Cell::get_cellLetter() { return this->cellLetter; }

//accessors/get functions for points and materialIndex
int Cell::get_cellMaterialIndex() { return theMaterial.get_materialIndex(); }
int Cell::get_cellp0() { return p0; }
int Cell::get_cellp1() { return p1; }
int Cell::get_cellp2() { return p2; }
int Cell::get_cellp3() { return p3; }
int Cell::get_cellp4() { return p4; }
int Cell::get_cellp5() { return p5; }
int Cell::get_cellp6() { return p6; }
int Cell::get_cellp7() { return p7; }

Material Cell::get_cellMaterial() { return theMaterial; }



// volume left empty because it is determined inside the cell that inherit the function
double Cell::volume()
{
}

// center of mass left empty because it is determined inside the cell that inherit the function
double Cell::centerOfMass()
{
}

// center of mass left empty because it is determined inside the cell that inherit the function
double Cell::weight()
{
    float mass = 0; // mass is declared

    mass = volume * density; // mass is found by multiplying the volume and the density

    double weight = mass * 9.81; // the weight is found by multiplying the mass and the gravity of earth

    return weight;
}

// destructor for the cell class
Cell::~Cell() {}

// tetrahedron class declared and has its contents defined
class Tetrahedron : public Cell
{
public:
    Tetrahedron();

    Tetrahedron(int &tCellIndex, char &tCellLetter, Material &tTheMaterial, Vector3d &tP0, Vector3d &tP1, Vector3d &tP2, Vector3d &tP3); // constructor for tetrahedron vectors is called
    ~Tetrahedron();                                                                                                               // destructor for tetrahedron vector constructor called

    Tetrahedron(const Tetrahedron &instance); // copying constructor applied (Note: this is the same function
    // as the normal constructor but with an instance argument where a whole instance is supplied)

    const Tetrahedron &operator=(const Tetrahedron &instance); // assignment operator for Pyramid

    // operators for subtraction, addition, dotmulitplication, cross multiplication
    // all have to be applied here

    // private variables and functions of the tetrahedron class
private:

  int cellIndex;
  char cellLetter;
  Material theMaterial;
  Vector3d p0, p1, p2, p3;

    double volume(Vector3d &p0, Vector3d &p1, Vector3d &p2, Vector3d &p3); // volume of a tetrahedron

    vector3d centerOfMass(Vector3d &p0, Vector3d &p1, Vector3d &p2, Vector3d &p3);
};

// constructor for tetrahedron vectors declared
Tetrahedron::Tetrahedron(int &tCellIndex, char &tCellLetter, Material &tTheMaterial, Vector3d &tP0, Vector3d &tP1, Vector3d &tP2, Vector3d &tP3)
 :Cell(cellLetter, cellIndex, theMaterial, p0, p1, p2, p3)
{
  this->cellIndex = tCellIndex;
  this->cellLetter = tCellLetter;
  this->theMaterial = tTheMaterial;

  this->p0 = tP0;
  this->p1 = tP1;
  this->p2 = tP2;
  this->p3 = tP3;
}

// destructor for the tetrahedron vectors
Tetrahedron ::~Tetrahedron() {}



// constructor copies the contents of instance into the new instance for a tetrahedron
Tetrahedron::Tetrahedron(const Tetrahedron &instance) 
{
        p0 = instance.get_p0;
        p1 = instance.get_p1;
        p2 = instance.get_p2;
        p3 = instance.get_p3;
}

// assignment operator which tells the compiler how to equate two instances of a tetrhedron properly if asked to
const Tetrahedron &operator=(const Tetrahedron &instance)
{

    // if the instance we have is exactly the same instance we are equating it to then return the
    // address of the instance we have
    // example if we want x to be x=x, then we are equating a variable to itself
    if (this == &instance)
        return (*this);

        p0.set_x()= instance.get_p0.get_x();
        p0.set_y()= instance.get_p0.get_y();
        p0.set_z()= instance.get_p0.get_z();


        p1.set_x()= instance.get_p1.get_x();
        p1.set_y()= instance.get_p1.get_y();
        p1.set_z()= instance.get_p1.get_z();

        p2.set_x()= instance.get_p2.get_x();
        p2.set_y()= instance.get_p2.get_y();
        p2.set_z()= instance.get_p2.get_z();

        p3.set_x()= instance.get_p3.get_x();
        p3.set_y()= instance.get_p3.get_y();
        p3.set_z()= instance.get_p3.get_z();

    return (*this); // returns the address of the instance we are in
}//###################### do i have to acces the x y and z of each of the points?? #########################

// definition of the volume of a tetrahedron
double Tetrahedron::volume(Vector3d &p0, Vector3d &p1, Vector3d &p2, Vector3d &p3)
{

    // the edges coming out of the same vector are calcualted(still abstract)
    Vector3d a = p0 - p1; // first edge is calculated and given the name 'a' in accordance to the equation v=(1/3!)|a.(bxc| which will be used later
    Vector3d b = p0 - p2; // second edge is calculated and given the name 'a' in accordance to the equation v=(1/3!)|a.(bxc| which will be used later
    Vector3d c = p0 - p3; // third edge is calculated and given the name 'a' in accordance to the equation v=(1/3!)|a.(bxc| which will be used later

    Vector3d crossmult = bxc; // cross multiplication which is set up by pisit

    double dotmult = a.crossmult; // dot multiplication which is set up by pisit

    // apply absolute value on the variable
    if (dotmult < 0)
        dotmult = -dotmult; // if the variable is negative make it +ve otherwise keep it as is

    // calculate the volume by dividing the absolut value of the dot multiplication result
    // by dividing by 3 factorial which is 6
    double volume = dotmult / 6;

    // return the volume as a float
    return volume;
} //####### im 95% sure its right #############


// definition of the volume of a Hexahedron
vector3d Tetrahedron::centerOfMass(Vector3d &p0, Vector3d &p1, Vector3d &p2, Vector3d &p3)
{

    vector3d center; // create a vector instance to store the x, y and z of the center in

    center.set_x = (p0.get_x() + p1.get_x() + p2.get_x() + p3.get_x()) / 4; // set the x of the center

    center.set_y = (p0.get_y() + p1.get_y() + p2.get_y() + p3.get_y()) / 4; // set the y of the center

    center.set_z = (p0.get_z() + p1.get_z() + p2.get_z() + p3.get_z()) / 4; // set the z of the center

    return center; // return the center instance
} //########## not 100% if its alright since can't be tested #########

// hexahedron class declared and has its contents defined
class Hexahedron : public Cell
{
public:
    Hexahedron(int &hCellIndex, char &hCellLetter, Material &tTheMaterial, Vector3d &hP0, Vector3d &hP1, Vector3d &hP2, Vector3d &hP3, Vector3d &hP4
    Vector3d &hP4, Vector3d &hP5, Vector3d &hP6, Vector3d &hP7); // vector constructor called

    ~Hexahedron();                     // hexahedron destructor applied to the vector constructor

    Hexahedron(const Hexahedron &instance); // copying constructor applied

    const Hexahedron &operator=(const Hexahedron &instance); // assignment operator for Pyramid

    // operators for subtraction, addition, dotmulitplication, cross multiplication
    // all have to be applied here

private:
    int cellIndex;
    char cellLetter;
    Material theMaterial;
    Vector3d p0, p1, p2, p3, p4, p5, p6, p7;


    double volume(Vector3d &p0, Vector3d &p1, Vector3d &p2, Vector3d &p3, Vector3d &p4, Vector3d &p5, Vector3d &p6, Vector3d &p7 ); // volume of a Hexahedron

    vector3d centerOfMass(Vector3d &p0, Vector3d &p1, Vector3d &p2, Vector3d &p3, Vector3d &p4, Vector3d &p5, Vector3d &p6, Vector3d &p7);//center of mass of a hexahedron
};

// constructor for hexahedron vectors declared
Hexahedron ::Hexahedron(int &hCellIndex, char &hCellLetter, Material &hTheMaterial, Vector3d &hP0, Vector3d &hP1, Vector3d &hP2, Vector3d &hP3, Vector3d &hP4, Vector3d &hP4, Vector3d &hP5, Vector3d &hP6, Vector3d &hP7)
:Cell(cellLetter, cellIndex, theMaterial, p0, p1, p2, p3, p4, p5, p6, p7)
{
  this->cellIndex = hCellIndex;
  this->cellLetter = hCellLetter;
  this->theMaterial = hTheMaterial;

  this->p0 = hP0;
  this->p1 = hP1;
  this->p2 = hP2;
  this->p3 = hP3;
  this->p4 = hP4;
  this->p5 = hP5;
  this->p6 = hP6;
  this->p7 = hP7;

}

// destructor for the hexahedron vector constructor declared
Hexahedron ::~Hexahedron() {}


// constructor copies the contents of instance into the new instance for a hexahedron
Hexahedron::Hexahedron(const Hexahedron &instance)  
{
      cellIndex = instance.get_cellIndex;
      cellLetter = instance.get_cellLetter;
      theMaterial = instance.get_theMaterial;

        p0 = instance.get_p0;
        p1 = instance.get_p1;
        p2 = instance.get_p2;
        p3 = instance.get_p3;
        p4 = instance.get_p4;
        p5 = instance.get_p5;
        p6 = instance.get_p6;
        p7 = instance.get_p7;
 
}

// assignment operator which tells the compiler how to equate two instances of a hexahedron properly if asked to
const Hexahedron &operator=(const Hexahedron &instance)
{

    // if the instance we have is exactly the same instance we are equating it to then return the
    // address of the instance we have
    // example if we want x to be x=x, then we are equating a variable to itself
    if (this == &instance)
        return (*this);

        p0.set_x()= instance.get_p0.get_x();
        p0.set_y()= instance.get_p0.get_y();
        p0.set_z()= instance.get_p0.get_z();


        p1.set_x()= instance.get_p1.get_x();
        p1.set_y()= instance.get_p1.get_y();
        p1.set_z()= instance.get_p1.get_z();

        p2.set_x()= instance.get_p2.get_x();
        p2.set_y()= instance.get_p2.get_y();
        p2.set_z()= instance.get_p2.get_z();

        p3.set_x()= instance.get_p3.get_x();
        p3.set_y()= instance.get_p3.get_y();
        p3.set_z()= instance.get_p3.get_z();

        p4.set_x()= instance.get_p4.get_x();
        p4.set_y()= instance.get_p4.get_y();
        p4.set_z()= instance.get_p4.get_z();

        p5.set_x()= instance.get_p5.get_x();
        p5.set_y()= instance.get_p5.get_y();
        p5.set_z()= instance.get_p5.get_z();

        p6.set_x()= instance.get_p6.get_x();
        p6.set_y()= instance.get_p6.get_y();
        p6.set_z()= instance.get_p6.get_z();

        p7.set_x()= instance.get_p7.get_x();
        p7.set_y()= instance.get_p7.get_y();
        p7.set_z()= instance.get_p7.get_z();
    

    return (*this); // returns the address of the instance we are in
}

// definition of the volume of a Hexahedron
double Hexahedron::volume(Vector3d &p0, Vector3d &p1, Vector3d &p2, Vector3d &p3, Vector3d &p4, Vector3d &p5, Vector3d &p6, Vector3d &p7)
{

    // three implementations of a triple product have to be implemented then added

    // implementation of the first triple product

    // a vector is declared to store the three parts of the first triple product inside
    Vector<int> firstTriple;

    firstTriple[0] = p6 - p0; // first part is calculated by subtracting the vertex 0 from the vertex 6
    firstTriple[1] = p1 - p0; // second edge is calculated by subtracting the vertex 0 from the vertex 1
    firstTriple[2] = p2 - p5; // third edge is calculated by subtracting the vertex 5 from the vertex 2

    Vector3d firstCrossMult = firstTriple[1] x firstTriple[2]; // cross multiplication which is set up by pisit

    double firstDotMult = firstTriple[0].firstCrossMult; // dot multiplication which is set up by pisit

    // implementation of the second triple product

    // a vector is declared to store the three parts of the second triple product inside
    Vector<int> secondTriple;

    secondTriple[0] = p6 - p0; // first part is calculated  by subtracting the vertex 0 from the vertex 6
    secondTriple[1] = p4 - p0; // second edge is calculated  by subtracting the vertex 0 from the vertex 4
    secondTriple[2] = p5 - p7; // third edge is calculated  by subtracting the vertex 7 from the vertex 5

    Vector3d secondCrossMult = secondTriple[1] x secondTriple[2]; // cross multiplication which is set up by pisit

    double secondDotMult = secondTriple[0].secondCrossMult; // dot multiplication which is set up by pisit

    // implementation of the third triple product

    // a vector is declared to store the three parts of the third triple product inside
    Vector<int> thirdTriple;

    thirdTriple[0] = p6 - p0; // first part is calculated by subtracting the vertex 0 from the vertex 7
    thirdTriple[1] = p3 - p0; // second edge is calculated by subtracting the vertex 0 from the vertex 3
    thirdTriple[2] = p7 - p2; // third edge is calculated by subtracting the vertex 2 from the vertex 7

    Vector3d thirdCrossMult = thirdTriple[1] x thirdTriple[2]; // cross multiplication which is set up by pisit

    double thirdDotMult = thirdTriple[0].thirdCrossMult; // dot multiplication which is set up by pisit

    // calculate the volume by adding the three Dot multiplication products of the triple products and then
    // by dividing by 3 factorial which is 6
    double volume = (firstDotMult + secondDotMult + thirdDotMult) / 6;

    // return the volume as a float
    return volume;
} //######################### not 100% sure if its all right since its necessary that the vertices are in the right order #############

// definition of a center of mass function
Vector3d Hexahedron::centerOfMass(Vector3d &p0, Vector3d &p1, Vector3d &p2, Vector3d &p3, Vector3d &p4, Vector3d &p5, Vector3d &p6, Vector3d &p7)
{

    // the center for the Y, X and Z
    // summation method has to be applied twice, once for the area of the base and once for use in the centroid equation
    vector <Vector3d> points;
    points.pushback(p0);
    points.pushback(p1);
    points.pushback(p2);
    points.pushback(p3);
    points.pushback(p4);
    points.pushback(p5);
    points.pushback(p6);
    points.pushback(p7);
    
    vector3d centerBase;
    // for loop to go through vertices performing a summation calculation
    for (i = 0; i < 4; ++i)
    {
        double summationXBase += (points[i].get_x() + points[i + 1].get_x()) * ((Hpoints[i].get_x()) * (points[i + 1].get_y())) - ((points[i + 1].get_x()) * (points[i].get_y()));
    }

    summationXBase += ((points[3].get_x()) * (points[0].get_y())) - ((points[0].get_x()) * (points[3].get_y())); // first vertex needs to be the last vertex too

    // the base's area has to be calculated which is 2D

    // for loop to go through vertices performing a summation calculation
    for (i = 0; i < 4; ++i)
    {
        double areaSummationBase += ((points[i].get_x()) * (points[i + 1].get_y())) - ((points[i + 1].get_x()) * (points[i].get_y()));
    }

    areaSummationBase += ((points[3].get_x()) * (points[0].get_y())) - ((points[0].get_x()) * (points[3].get_y())); // first vertex needs to be the last vertex too

    // take the absolut value of the summation if the summation is -ve
    if (areaSummation < 0)
    {

        areaSummation = -areaSummation;
    }

    // the area is then calculated by dividing the absolut value of the summation by 2
    double Area = areaSummationBase / 2;

    centerBase.set_x = (1 / (6 * Area)) * summationXBase;

    // for loop to go through vertices performing a summation calculation
    for (i = 0; i < 4; ++i)
    {
        double summationYBase += (points[i].get_y() + points[i + 1].get_y()) * ((points[i].get_x()) * (points[i + 1].get_y())) - ((points[i + 1].get_x()) * (points[i].get_y()));
    }

    summationYBase += ((points[3].get_x()) * (points[0].get_y())) - ((points[0].get_x()) * (points[3].get_y())); // first vertex needs to be the last vertex too

    centerBase.set_y = (1 / (6 * Area)) * summationYBase; // equation to find the y coordinate of the

    centerBase.set_z = 0;

    // the center for the Y, X and Z
    // summation method has to be applied twice, once for the area of the base and once for use in the centroid equation

    vector3d centerTop;
    // for loop to go through vertices performing a summation calculation
    for (i = 4; i < 8; ++i)
    {
        double summationXTop += (points[i].get_x() + points[i + 1].get_x()) * ((points[i].get_x()) * (points[i + 1].get_y())) - ((points[i + 1].get_x()) * (points[i].get_y()));
    }

    summationXTop += ((points[3].get_x()) * (points[0].get_y())) - ((points[0].get_x()) * (points[3].get_y())); // first vertex needs to be the last vertex too

    // the base's area has to be calculated which is 2D

    // for loop to go through vertices performing a summation calculation
    for (i = 4; i < 8; ++i)
    {
        double areaSummationTop += ((points[i].get_x()) * (points[i + 1].get_y())) - ((points[i + 1].get_x()) * (points[i].get_y()));
    }

    areaSummationTop += ((points[7].get_x()) * (points[0].get_y())) - ((points[0].get_x()) * (points[7].get_y())); // first vertex needs to be the last vertex too

    // take the absolut value of the summation if the summation is -ve
    if (areaSummationTop < 0)
    {

        areaSummationTop = -areaSummationTop;
    }

    // the area is then calculated by dividing the absolut value of the summation by 2
    double areaTop = areaSummationTop / 2;

    centerTop.x = (1 / (6 * areaTop)) * summationXTop;

    // for loop to go through vertices performing a summation calculation
    for (i = 4; i < 8; ++i)
    {
        double summationYTop += (points[i].get_y() + points[i + 1].get_y()) * ((points[i].get_x()) * (points[i + 1].get_y())) - ((points[i + 1].get_x()) * (points[i].get_y()));
    }

    summationYTop += ((points[7].get_x()) * (points[0].get_y())) - ((points[0].get_x()) * (points[7].get_y())); // first vertex needs to be the last vertex too

    centerTop.set_y() = (1 / (6 * Area)) * summationYTop; // equation to find the y coordinate of the

    // for loop to go through vertices performing a summation calculation
    // for (int i = 4; i < 8; ++i)
    {
        // double summationYTop += (Ppoints[i].get_z() + Ppoints[i+1].get_z()) * ((Ppoints[i].get_x()) * (Ppoints[i + 1].get_y())) - ((Ppoints[i + 1].get_x()) * (Ppoints[i].get_y()));
    }

    // summationYTop += ((Ppoints[7].get_x()) * (Ppoints[0].get_y())) - ((Ppoints[0].get_x()) * (Ppoints[7].get_y())); // first vertex needs to be the last vertex too

    // centerTop.y = (1/(6*Area))* summationYTop; //equation to find the y coordinate of the
}
}

// pyramid class declared and has its contents defined
class Pyramid : public Cell
{
public:

     Pyramid();

     Pyramid(int &pCellIndex, char &pCellLetter, Material &pTheMaterial, Vector3d &pP0, Vector3d &pP1, Vector3d &pP2, Vector3d &pP3, Vector3d &pP4); // constructor for tetrahedron vectors is called
    ~Pyramid();                    // destructor for pyramid vectors is called


    Pyramid(const Pyramid &instance); // copying constructor applied

    const Pyramid &operator=(const Pyramid &instance); // assignment operator for Pyramid

    // operators for subtraction, addition, dotmulitplication, cross multiplication
    // all have to be applied here

private:

  int cellIndex;
  char cellLetter;
  Material theMaterial;
  Vector3d p0, p1, p2, p3, p4;

    double volume(Vector3d &p0, Vector3d &p1, Vector3d &p2, Vector3d &p3, Vector3d &p4); // volume of a pyramid

    vector3d centerOfMass(Vector3d &p0, Vector3d &p1, Vector3d &p2, Vector3d &p3, Vector3d &p4); // center of mass of a pyramid

}

// constructor for Pyramid vectors declared
Pyramid::Pyramid(int &pCellIndex, char &pCellLetter, Material &pTheMaterial, Vector3d &pP0, Vector3d &pP1, Vector3d &pP2, Vector3d &pP3, Vector3d &pP4)
{

    this->cellIndex = cellIndex;
    this->cellLetter = cellLetter;
    this->theMaterial = theMaterial;

    this->p0 = p0;
    this->p1 = p1;
    this->p2 = p2;
    this->p3 = p3;
    this->p4 = p4;
}

// constructor copies the contents of instance into the new instance for a Pyramid
Pyramid::Pyramid(const Pyramid &instance)
{

      cellIndex = instance.get_cellIndex;
      cellLetter = instance.get_cellLetter;
      theMaterial = instance.get_theMaterial;

        p0 = instance.get_p0;
        p1 = instance.get_p1;
        p2 = instance.get_p2;
        p3 = instance.get_p3;
        p4 = instance.get_p4;
}

// assignment operator which tells the compiler how to equate two instances of a pyramid properly if asked to
const Pyramid &operator=(const Pyramid &instance)
{

    // if the instance we have is exactly the same instance we are equating it to then return the
    // address of the instance we have
    // example if we want x to be x=x, then we are equating a variable to itself
    if (this == &instance)
        return (*this);

        p0.set_x()= instance.get_p0.get_x();
        p0.set_y()= instance.get_p0.get_y();
        p0.set_z()= instance.get_p0.get_z();


        p1.set_x()= instance.get_p1.get_x();
        p1.set_y()= instance.get_p1.get_y();
        p1.set_z()= instance.get_p1.get_z();

        p2.set_x()= instance.get_p2.get_x();
        p2.set_y()= instance.get_p2.get_y();
        p2.set_z()= instance.get_p2.get_z();

        p3.set_x()= instance.get_p3.get_x();
        p3.set_y()= instance.get_p3.get_y();
        p3.set_z()= instance.get_p3.get_z();

        p4.set_x()= instance.get_p4.get_x();
        p4.set_y()= instance.get_p4.get_y();
        p4.set_z()= instance.get_p4.get_z();
        
    

    return (*this); // returns the address of the instance we are in
}

//######################## NOTE: this assumes that the base of the pyramid lies on the x and y axis #################################
// definition of the volume of a pyramid
double Pyramid::volume(Vector3d &p0, Vector3d &p1, Vector3d &p2, Vector3d &p3, Vector3d &p4)
{

    // the base's area has to be calculated which is 2D

    // for loop to go through vertices performing a summation calculation
    for (int i = 0; i < 4; ++i)
    {
        double summation += ((Ppoints[i].get_x()) * (Ppoints[i + 1].get_y())) - ((Ppoints[i + 1].get_x()) * (Ppoints[i].get_y()));
    }

    summation += ((Ppoints[3].get_x()) * (Ppoints[0].get_y())) - ((Ppoints[0].get_x()) * (Ppoints[3].get_y())); // first vertex needs to be the last vertex too

    // take the absolut value of the summation if the summation is -ve
    if (summation < 0)
    {

        summation = -summation;
    }

    // the area is then calculate by dividing the absolut value of the summation by 2
    double Area = summation / 2;

    vector3d distanceBetweenBaseAndTip = center - Ppoint[4]; // the distance between the tip and the base

    // to calculate the volume (assumes that point number 5 is the top of the pyramid)
    double volume = (distanceBetweenBaseAndTip.get_y * Area) / 3;

    return volume;
} // not sure if it's right might have to do take the height as the distance between the center of the base and the tip instead of a plane y coordinate


//######################## NOTE: this assumes that the base of the pyramid lies on the x and y axis #################################
// ############################ NOTE: may also assume the last point is the top of the pyramid #######################################
// definitoin of a center of mass function
vector3d Pyramid::centerOfMass(Vector3d &p0, Vector3d &p1, Vector3d &p2, Vector3d &p3, Vector3d &p4)
{

    // the center for the Y, X and Z
    // summation method has to be applied twice, once for the area of the base and once for use in the centroid equation
    vector <Vector3d> points;
    points.pushback(p0);
    points.pushback(p1);
    points.pushback(p2);
    points.pushback(p3);
    points.pushback(p4);

    Vector3d center;
    // for loop to go through vertices performing a summation calculation
    for (int i = 0; i < 4; ++i)
    {
        double summationX += (points[i].get_x() + points[i + 1].get_x()) * ((points[i].get_x()) * (points[i + 1].get_y())) - ((points[i + 1].get_x()) * (points[i].get_y()));
    }

    summationX += ((points[3].get_x()) * (points[0].get_y())) - ((points[0].get_x()) * (points[3].get_y())); // first vertex needs to be the last vertex too

    // the base's area has to be calculated which is 2D

    // for loop to go through vertices performing a summation calculation
    for (int i = 0; i < 4; ++i)
    {
        double Areasummation += ((points[i].get_x()) * (points[i + 1].get_y())) - ((points[i + 1].get_x()) * (points[i].get_y()));
    }

    Areasummation += ((points[3].get_x()) * (points[0].get_y())) - ((points[0].get_x()) * (points[3].get_y())); // first vertex needs to be the last vertex too

    // take the absolut value of the summation if the summation is -ve
    if (Areasummation < 0)
    {

        Areasummation = -Areasummation;
    }

    // the area is then calculated by dividing the absolut value of the summation by 2
    double Area = Areasummation / 2;

    center.set_x = (1 / (6 * Area)) * summationX;

    // for loop to go through vertices performing a summation calculation
    for (int i = 0; i < 4; ++i)
    {
        double summationY += (points[i].get_y() + points[i + 1].get_y()) * ((points[i].get_x()) * (points[i + 1].get_y())) - ((points[i + 1].get_x()) * (points[i].get_y()));
    }

    summationY += ((points[3].get_x()) * (points[0].get_y())) - ((points[0].get_x()) * (points[3].get_y())); // first vertex needs to be the last vertex too

    center.set_y = (1 / (6 * Area)) * summationY; // equation to find the y coordinate of the centriod of the base

    center.set_z = 0; // since its the base its z has to be 0

    Vector3d distanceBetweenBaseAndTip = center - points[4]; // the distance between the tip and the base

    center = distanceBetweenBaseAndCenter / 4; // the center is now changed to include the z axis and changes the x and y values

    return center; // return the center instance

} 
//######################### also no way of validating if this is working or not ###############################
