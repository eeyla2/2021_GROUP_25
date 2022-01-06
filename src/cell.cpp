#include <Vector>
// Vector class - Best

#include <iostream>
#include <string>
//#include <vector>
using namespace std;

// ONLY AN ABSTRACT FOR CLARITY
// this will be class material and i will inherit the characteristics to different types of material according to the indexID it has
class Cell
{
public:
    // Cell constructor for different Cell variants
    Cell();
    // cell class constructor for a tetrahedron
    Cell(char &cCellLetter, int &cCellIndex, Material &cTheMaterial, Vector3d &cP0, Vector3d &cp1, Vector3d &cP2, Vector3d &cP3); // tetrahedron

    // cell class constructor for a hexahedron
    Cell(char &cCellLetter, int &cCellIndex, Material &cTheMaterial, Vector3d &cP0, Vector3d &cP1, Vector3d &cP2, Vector3d &cP3,
         Vector3d &cP4, Vector3d &cP5, Vector3d &cP6, Vector3d &cP7); // hexahedron

    // cell class constructor for pyramid
    Cell(char &cCellLetter, int &cCellIndex, Material &cTheMaterial, Vector3d &cP0, Vector3d &cP1, Vector3d &cP2, Vector3d &cP3, Vector3d &cP4); // pyramid

    ~Cell(); // destructor for the cell called (works for the three constructors)

    // first get returns the value of cell Index, while second get returns the value of cell Letter and third one reteurns the Material Index
    int get_cellIndex() const;
    char get_cellLetter() const;
    int get_cellMaterialIndex() const;

    // get functions for all the points
    Vector3d get_cellp0() const;
    Vector3d get_cellp1() const;
    Vector3d get_cellp2() const;
    Vector3d get_cellp3() const;
    Vector3d get_cellp4() const;
    Vector3d get_cellp5() const;
    Vector3d get_cellp6() const;
    Vector3d get_cellp7() const;

    // get the material inside the cell class
    Material get_cellMaterial() const;

    // virtual function allows the correct version of volume and center of massto be called for each shape
    virtual double volume();
    virtual double centerOfMass();

    // weight of the cell calculated
    double weight();

protected:
    int cellIndex;                           // the cell Index
    char cellLetter;                         // the cell letter
    Material theMaterial;                    // the material
    Vector3d p0, p1, p2, p3, p4, p5, p6, p7; // all possible points that could be used in a shape

    // the weight function that is currently in the Cell classes will actually be inherited
};

// incase the cell class is empty
Cell::Cell()
{
}

// tetrahedron
Cell::Cell(char &cCellLetter, int &cCellIndex, Material &cTheMaterial, Vector3d &cP0, Vector3d &cP1, Vector3d &cP2, Vector3d &cP3)
{
    // constructor for all the points and other data necessary to make sure the data is initialized correctly

    // necessary data for identification
    this->cellIndex = cCellIndex;
    this->cellLetter = cCellLetter;
    this->theMaterial = cTheMaterial;

    // points
    this->p0 = cP0;
    this->p1 = cP1;
    this->p2 = cP2;
    this->p3 = cP3;
}

// hexahedron
Cell::Cell(char &cCellLetter, int &cCellIndex, Material &cTheMaterial, Vector3d &cP0, Vector3d &cP1, Vector3d &cP2, Vector3d &cP3,
           Vector3d &cP4, Vector3d &cP5, Vector3d &cP6, Vector3d &cP7)
{
    // constructor for all the points and other data necessary to make sure the data is initialized correctly

    // necessary data for identification
    this->cellIndex = cCellIndex;
    this->cellLetter = cellLetter;
    this->theMaterial = cTheMaterial;

    // points
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
    // constructor for all the points and other data necessary to make sure the data is initialized correctly

    // necessary data for identification
    this->cellIndex = cCellIndex;
    this->cellLetter = cCellLetter;
    this->theMaterial = cTheMaterial;

    // points
    this->p0 = cP0;
    this->p1 = cP1;
    this->p2 = cP2;
    this->p3 = cP3;
    this->p4 = cP4;
}

// an accessor/get function to access the data for Index in the private part of the Cell class
int Cell::get_cellIndex() const { return this->cellIndex; }

// an accessor/get function to access the data for Letter in the private part of the Cell class
char Cell::get_cellLetter() const { return this->cellLetter; }

// accessors/get functions for points and materialIndex
int Cell::get_cellMaterialIndex() const { return theMaterial.get_materialIndex(); }
Vector3d Cell::get_cellp0() const { return p0; }
Vector3d Cell::get_cellp1() const { return p1; }
Vector3d Cell::get_cellp2() const { return p2; }
Vector3d Cell::get_cellp3() const { return p3; }
Vector3d Cell::get_cellp4() const { return p4; }
Vector3d Cell::get_cellp5() const { return p5; }
Vector3d Cell::get_cellp6() const { return p6; }
Vector3d Cell::get_cellp7() const { return p7; }


//get the material inside the cell class
Material Cell::get_cellMaterial() const { return theMaterial; }

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

    mass = volume() * theMaterial.get_materialDensity(); // mass is found by multiplying the volume and the density

    double weight = mass * 9.81; // the weight is found by multiplying the mass and the gravity of earth

    return weight;
}

// destructor for the cell class
Cell::~Cell() {}

// tetrahedron class declared and has its contents defined
class Tetrahedron : public Cell
{
public:
    Tetrahedron();//incase of empty argument

    Tetrahedron(int &tCellIndex, char &tCellLetter, Material &tTheMaterial, Vector3d &tP0, Vector3d &tP1, Vector3d &tP2, Vector3d &tP3); // constructor for tetrahedron vectors is called
    ~Tetrahedron();                                                                                                                      // destructor for tetrahedron vector constructor called

    Tetrahedron(const Tetrahedron &instance); // copying constructor applied (Note: this is the same function
    // as the normal constructor but with an instance argument where a whole instance is supplied)

    const Tetrahedron &operator=(const Tetrahedron &instance); // assignment operator for Tetrahedron

    // operators for subtraction, addition, dotmulitplication, cross multiplication
    // all have to be applied here

    // private variables and functions of the tetrahedron class
private:
    int cellIndex;
    char cellLetter;
    Material theMaterial;
    Vector3d p0, p1, p2, p3;

    double volume(Vector3d &p0, Vector3d &p1, Vector3d &p2, Vector3d &p3); // volume of a tetrahedron

    Vector3d centerOfMass(Vector3d &p0, Vector3d &p1, Vector3d &p2, Vector3d &p3); //center of mass of a tetrahedron
};

// incase no data is entered
Tetrahedron::Tetrahedron()
{
}

// constructor for tetrahedron vectors declared
Tetrahedron::Tetrahedron(int &tCellIndex, char &tCellLetter, Material &tTheMaterial, Vector3d &tP0, Vector3d &tP1, Vector3d &tP2, Vector3d &tP3)
    : Cell(cellLetter, cellIndex, theMaterial, p0, p1, p2, p3)
{
    // necessary data for identification
    this->cellIndex = tCellIndex;
    this->cellLetter = tCellLetter;
    this->theMaterial = tTheMaterial;

    // points
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
    // necessary data for identification
    cellIndex = instance.get_cellIndex();
    cellLetter = instance.get_cellLetter();
    theMaterial = instance.get_cellMaterial();


    //the points are assigned to each other
    p0 = instance.get_cellp0();
    p1 = instance.get_cellp1();
    p2 = instance.get_cellp2();
    p3 = instance.get_cellp3();
}

// assignment operator which tells the compiler how to equate two instances of a tetrahedron properly if asked to
const Tetrahedron &Tetrahedron::operator=(const Tetrahedron &instance)
{

    // if the instance we have is exactly the same instance we are equating it to then return the
    // address of the instance we have
    // example if we want x to be x=x, then we are equating a variable to itself
    if (this == &instance)
        return (*this);


//extract the x,y and z coordinates of every point from the parameter 
//and store them inside a double each then appoint the doubles to the x,y and z points of the new instance

    double x = instance.get_cellp0().get_x();
    double y = instance.get_cellp0().get_y();
    double z = instance.get_cellp0().get_z();
    p0.set_x(x);
    p0.set_y(y);
    p0.set_z(z);

    x = instance.get_cellp1().get_x();
    y = instance.get_cellp1().get_y();
    z = instance.get_cellp1().get_z();
    p1.set_x(x);
    p1.set_y(y);
    p1.set_z(z);

    x = instance.get_cellp2().get_x();
    y = instance.get_cellp2().get_y();
    z = instance.get_cellp2().get_z();
    p2.set_x(x);
    p2.set_y(y);
    p2.set_z(z);

    x = instance.get_cellp3().get_x();
    y = instance.get_cellp3().get_y();
    z = instance.get_cellp3().get_z();
    p3.set_x(x);
    p3.set_y(y);
    p3.set_z(z);

    return (*this); // returns the address of the instance we are in
} 

// definition of the volume of a tetrahedron
double Tetrahedron::volume(Vector3d &p0, Vector3d &p1, Vector3d &p2, Vector3d &p3)
{

    // the edges coming out of the same vector are calcualted(still abstract)
    Vector3d a = p0 - p1; // first edge is calculated and given the name 'a' in accordance to the equation v=(1/3!)|a.(bxc| which will be used later
    Vector3d b = p0 - p2; // second edge is calculated and given the name 'a' in accordance to the equation v=(1/3!)|a.(bxc| which will be used later
    Vector3d c = p0 - p3; // third edge is calculated and given the name 'a' in accordance to the equation v=(1/3!)|a.(bxc| which will be used later

    Vector3d crossmult = b.crossProduct(c); // cross multiplication which is set up by pisit

    double dotmult = a.dotProduct(crossmult); // dot multiplication which is set up by pisit

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
Vector3d Tetrahedron::centerOfMass(Vector3d &p0, Vector3d &p1, Vector3d &p2, Vector3d &p3)
{

    Vector3d center; // create a vector instance to store the x, y and z of the center in

    double x = (p0.get_x() + p1.get_x() + p2.get_x() + p3.get_x()) / 4;
    double y = (p0.get_y() + p1.get_y() + p2.get_y() + p3.get_y()) / 4;
    double z = (p0.get_z() + p1.get_z() + p2.get_z() + p3.get_z()) / 4;
    center.set_x(x); // set the x of the center

    center.set_y(y); // set the y of the center

    center.set_z(z); // set the z of the center

    return center; // return the center instance
} //########## not 100% if its alright since can't be tested #########

// hexahedron class declared and has its contents defined
class Hexahedron : public Cell
{
public:
    Hexahedron();

    Hexahedron(int &hCellIndex, char &hCellLetter, Material &tTheMaterial, Vector3d &hP0, Vector3d &hP1, Vector3d &hP2, Vector3d &hP3, Vector3d &hP4, Vector3d &hP5, Vector3d &hP6, Vector3d &hP7); // vector constructor called

    ~Hexahedron(); // hexahedron destructor applied to the vector constructor

    Hexahedron(const Hexahedron &instance); // copying constructor applied

    const Hexahedron &operator=(const Hexahedron &instance); // assignment operator for Pyramid

    // operators for subtraction, addition, dotmulitplication, cross multiplication
    // all have to be applied here

private:
    int cellIndex;
    char cellLetter;
    Material theMaterial;
    Vector3d p0, p1, p2, p3, p4, p5, p6, p7;

    double volume(Vector3d &p0, Vector3d &p1, Vector3d &p2, Vector3d &p3, Vector3d &p4, Vector3d &p5, Vector3d &p6, Vector3d &p7); // volume of a Hexahedron

    Vector3d centerOfMass(Vector3d &p0, Vector3d &p1, Vector3d &p2, Vector3d &p3, Vector3d &p4, Vector3d &p5, Vector3d &p6, Vector3d &p7); // center of mass of a hexahedron
};

Hexahedron::Hexahedron()
{
}

// constructor for hexahedron vectors declared
Hexahedron ::Hexahedron(int &hCellIndex, char &hCellLetter, Material &hTheMaterial, Vector3d &hP0, Vector3d &hP1, Vector3d &hP2, Vector3d &hP3, Vector3d &hP4, Vector3d &hP5, Vector3d &hP6, Vector3d &hP7)
    : Cell(cellLetter, cellIndex, theMaterial, p0, p1, p2, p3, p4, p5, p6, p7)
{
    // necessary data for identification
    this->cellIndex = hCellIndex;
    this->cellLetter = hCellLetter;
    this->theMaterial = hTheMaterial;

    // points
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
    // necessary data for identification
    cellIndex = instance.get_cellIndex();
    cellLetter = instance.get_cellLetter();
    theMaterial = instance.get_cellMaterial();

    // points
    p0 = instance.get_cellp0();
    p1 = instance.get_cellp1();
    p2 = instance.get_cellp2();
    p3 = instance.get_cellp3();
    p4 = instance.get_cellp4();
    p5 = instance.get_cellp5();
    p6 = instance.get_cellp6();
    p7 = instance.get_cellp7();
}

// assignment operator which tells the compiler how to equate two instances of a hexahedron properly if asked to
const Hexahedron &Hexahedron::operator=(const Hexahedron &instance)
{

    // if the instance we have is exactly the same instance we are equating it to then return the
    // address of the instance we have
    // example if we want x to be x=x, then we are equating a variable to itself
    if (this == &instance)
        return (*this);



//extract the x,y and z coordinates of every point from the parameter 
//and store them inside a double each then appoint the doubles to the x,y and z points of the new instance

    double x = instance.get_cellp0().get_x();
    double y = instance.get_cellp0().get_y();
    double z = instance.get_cellp0().get_z();
    p0.set_x(x);
    p0.set_y(y);
    p0.set_z(z);

    x = instance.get_cellp1().get_x();
    y = instance.get_cellp1().get_y();
    z = instance.get_cellp1().get_z();
    p1.set_x(x);
    p1.set_y(y);
    p1.set_z(z);

    x = instance.get_cellp2().get_x();
    y = instance.get_cellp2().get_y();
    z = instance.get_cellp2().get_z();
    p2.set_x(x);
    p2.set_y(y);
    p2.set_z(z);

    x = instance.get_cellp3().get_x();
    y = instance.get_cellp3().get_y();
    z = instance.get_cellp3().get_z();
    p3.set_x(x);
    p3.set_y(y);
    p3.set_z(z);

    x= instance.get_cellp4().get_x();
    y = instance.get_cellp4().get_y();
    z = instance.get_cellp4().get_z();
    p4.set_x(x);
    p4.set_y(y);
    p4.set_z(z);

    x = instance.get_cellp5().get_x();
    y = instance.get_cellp5().get_y();
    z = instance.get_cellp5().get_z();
    p5.set_x(x);
    p5.set_y(y);
    p5.set_z(z);

    x = instance.get_cellp6().get_x();
    y = instance.get_cellp6().get_y();
    z = instance.get_cellp6().get_z();
    p6.set_x(x);
    p6.set_y(y);
    p6.set_z(z);

    x = instance.get_cellp7().get_x();
    y = instance.get_cellp7().get_y();
    z = instance.get_cellp7().get_z();
    p7.set_x(x);
    p7.set_y(y);
    p7.set_z(z);

    return (*this); // returns the address of the instance we are in
}

// definition of the volume of a Hexahedron
double Hexahedron::volume(Vector3d &p0, Vector3d &p1, Vector3d &p2, Vector3d &p3, Vector3d &p4, Vector3d &p5, Vector3d &p6, Vector3d &p7)
{

    // three implementations of a triple product have to be implemented then added

    // implementation of the first triple product

    // a vector is declared to store the three parts of the first triple product inside
    vector<Vector3d> firstTriple;

    firstTriple[0] = p6 - p0; // first part is calculated by subtracting the vertex 0 from the vertex 6
    firstTriple[1] = p1 - p0; // second edge is calculated by subtracting the vertex 0 from the vertex 1
    firstTriple[2] = p2 - p5; // third edge is calculated by subtracting the vertex 5 from the vertex 2

    Vector3d firstCrossMult = firstTriple[1].crossProduct(firstTriple[2]); // cross multiplication which is set up by pisit

    double firstDotMult = firstTriple[0].dotProduct(firstCrossMult); // dot multiplication which is set up by pisit

    // implementation of the second triple product

    // a vector is declared to store the three parts of the second triple product inside
    vector<Vector3d> secondTriple;

    secondTriple[0] = p6 - p0; // first part is calculated  by subtracting the vertex 0 from the vertex 6
    secondTriple[1] = p4 - p0; // second edge is calculated  by subtracting the vertex 0 from the vertex 4
    secondTriple[2] = p5 - p7; // third edge is calculated  by subtracting the vertex 7 from the vertex 5

    Vector3d secondCrossMult = secondTriple[1].crossProduct(secondTriple[2]); // cross multiplication which is set up by pisit

    double secondDotMult = secondTriple[0].dotProduct(secondCrossMult); // dot multiplication which is set up by pisit

    // implementation of the third triple product

    // a vector is declared to store the three parts of the third triple product inside
    vector<Vector3d> thirdTriple;

    thirdTriple[0] = p6 - p0; // first part is calculated by subtracting the vertex 0 from the vertex 7
    thirdTriple[1] = p3 - p0; // second edge is calculated by subtracting the vertex 0 from the vertex 3
    thirdTriple[2] = p7 - p2; // third edge is calculated by subtracting the vertex 2 from the vertex 7

    Vector3d thirdCrossMult = thirdTriple[1].crossProduct(thirdTriple[2]); // cross multiplication which is set up by pisit

    double thirdDotMult = thirdTriple[0].dotProduct(thirdCrossMult); // dot multiplication which is set up by pisit

    // calculate the volume by adding the three Dot multiplication products of the triple products and then
    // by dividing by 3 factorial which is 6
    double volume = (firstDotMult + secondDotMult + thirdDotMult) / 6;

    // return the volume as a double
    return volume;
} //######################### not 100% sure if its all right since its necessary that the vertices are in the right order #############

// definition of a center of mass function
Vector3d Hexahedron::centerOfMass(Vector3d &p0, Vector3d &p1, Vector3d &p2, Vector3d &p3, Vector3d &p4, Vector3d &p5, Vector3d &p6, Vector3d &p7)
{

    // the center for the Y, X and Z
    // summation method has to be applied twice, once for the area of the base and once for use in the centroid equation

    //a vector of vertices is made for easier implementation 
    vector<Vector3d> points;

    //points are entered
    points.push_back(p0);
    points.push_back(p1);
    points.push_back(p2);
    points.push_back(p3);
    points.push_back(p4);
    points.push_back(p5);
    points.push_back(p6);
    points.push_back(p7);

    // store the coordinates of the center of the base inside the centerBase variable
    Vector3d centerBase;

    // variables needed for the calculations
    double areaSummationBase;
    double summationXBase;
    double summationYBase;

    // for loop to go through vertices performing a summation calculation
    for (int i = 0; i < 4; ++i)
    {
        summationXBase += (points[i].get_x() + points[i + 1].get_x()) * ((points[i].get_x()) * (points[i + 1].get_y())) - ((points[i + 1].get_x()) * (points[i].get_y()));
    }

    summationXBase += ((points[3].get_x()) * (points[0].get_y())) - ((points[0].get_x()) * (points[3].get_y())); // first vertex needs to be the last vertex too

    // the base's area has to be calculated which is 2D

    // for loop to go through vertices performing a summation calculation
    for (int i = 0; i < 4; ++i)
    {
        areaSummationBase += ((points[i].get_x()) * (points[i + 1].get_y())) - ((points[i + 1].get_x()) * (points[i].get_y()));
    }

    areaSummationBase += ((points[3].get_x()) * (points[0].get_y())) - ((points[0].get_x()) * (points[3].get_y())); // first vertex needs to be the last vertex too

    // take the absolut value of the summation if the summation is -ve
    if (areaSummationBase < 0)
    {

        areaSummationBase = -areaSummationBase;
    }

    // the area is then calculated by dividing the absolut value of the summation by 2
    double areaBase = areaSummationBase / 2;

    centerBase.set_x((1 / (6 * areaBase)) * summationXBase);

    // for loop to go through vertices performing a summation calculation
    for (int i = 0; i < 4; ++i)
    {
        summationYBase += (points[i].get_y() + points[i + 1].get_y()) * ((points[i].get_x()) * (points[i + 1].get_y())) - ((points[i + 1].get_x()) * (points[i].get_y()));
    }

    summationYBase += ((points[3].get_x()) * (points[0].get_y())) - ((points[0].get_x()) * (points[3].get_y())); // first vertex needs to be the last vertex too

    centerBase.set_y((1 / (6 * areaBase)) * summationYBase); // equation to find the y coordinate of the

    centerBase.set_z(0);

    // the center for the Y, X and Z
    // summation method has to be applied twice, once for the area of the base and once for use in the centroid equation

    Vector3d centerTop;

    double areaSummationTop;
    double summationXTop;
    double summationYTop;

    // for loop to go through vertices performing a summation calculation
    for (int i = 4; i < 8; ++i)
    {
        summationXTop += (points[i].get_x() + points[i + 1].get_x()) * ((points[i].get_x()) * (points[i + 1].get_y())) - ((points[i + 1].get_x()) * (points[i].get_y()));
    }

    summationXTop += ((points[3].get_x()) * (points[0].get_y())) - ((points[0].get_x()) * (points[3].get_y())); // first vertex needs to be the last vertex too

    // the base's area has to be calculated which is 2D

    // for loop to go through vertices performing a summation calculation
    for (int i = 4; i < 8; ++i)
    {
        areaSummationTop += ((points[i].get_x()) * (points[i + 1].get_y())) - ((points[i + 1].get_x()) * (points[i].get_y()));
    }

    areaSummationTop += ((points[7].get_x()) * (points[0].get_y())) - ((points[0].get_x()) * (points[7].get_y())); // first vertex needs to be the last vertex too

    // take the absolut value of the summation if the summation is -ve
    if (areaSummationTop < 0)
    {

        areaSummationTop = -areaSummationTop;
    }

    // the area is then calculated by dividing the absolut value of the summation by 2
    double areaTop = areaSummationTop / 2;

    centerTop.set_x((1 / (6 * areaTop)) * summationXTop);

    // for loop to go through vertices performing a summation calculation
    for (int i = 4; i < 8; ++i)
    {
        summationYTop += (points[i].get_y() + points[i + 1].get_y()) * ((points[i].get_x()) * (points[i + 1].get_y())) - ((points[i + 1].get_x()) * (points[i].get_y()));
    }

    summationYTop += ((points[7].get_x()) * (points[0].get_y())) - ((points[0].get_x()) * (points[7].get_y())); // first vertex needs to be the last vertex too

    centerTop.set_y((1 / (6 * areaTop)) * summationYTop); // equation to find the y coordinate of the

    // for loop to go through vertices performing a summation calculation
    // for (int i = 4; i < 8; ++i)
    {
        // double summationYTop += (Ppoints[i].get_z() + Ppoints[i+1].get_z()) * ((Ppoints[i].get_x()) * (Ppoints[i + 1].get_y())) - ((Ppoints[i + 1].get_x()) * (Ppoints[i].get_y()));
    }

    // summationYTop += ((Ppoints[7].get_x()) * (Ppoints[0].get_y())) - ((Ppoints[0].get_x()) * (Ppoints[7].get_y())); // first vertex needs to be the last vertex too

    // centerTop.y = (1/(6*Area))* summationYTop; //equation to find the y coordinate of the
}

// pyramid class declared and has its contents defined
class Pyramid : public Cell
{
public:
    Pyramid();

    Pyramid(int &pCellIndex, char &pCellLetter, Material &pTheMaterial, Vector3d &pP0, Vector3d &pP1, Vector3d &pP2, Vector3d &pP3, Vector3d &pP4); // constructor for tetrahedron vectors is called
    ~Pyramid();                                                                                                                                     // destructor for pyramid vectors is called

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

    Vector3d centerOfMass(Vector3d &p0, Vector3d &p1, Vector3d &p2, Vector3d &p3, Vector3d &p4); // center of mass of a pyramid
};

Pyramid::Pyramid()
{
}

// constructor for Pyramid vectors declared
Pyramid::Pyramid(int &pCellIndex, char &pCellLetter, Material &pTheMaterial, Vector3d &pP0, Vector3d &pP1, Vector3d &pP2, Vector3d &pP3, Vector3d &pP4)
: Cell(cellLetter, cellIndex, theMaterial, p0, p1, p2, p3, p4)
{
    // necessary data for identification
    this->cellIndex = cellIndex;
    this->cellLetter = cellLetter;
    this->theMaterial = theMaterial;

    // points
    this->p0 = pP0;
    this->p1 = pP1;
    this->p2 = pP2;
    this->p3 = pP3;
    this->p4 = pP4;
}

// constructor copies the contents of instance into the new instance for a Pyramid
Pyramid::Pyramid(const Pyramid &instance)
{
    // necessary data for identification
    cellIndex = instance.get_cellIndex();
    cellLetter = instance.get_cellLetter();
    theMaterial = instance.get_cellMaterial();

    // points
    p0 = instance.get_cellp0();
    p1 = instance.get_cellp1();
    p2 = instance.get_cellp2();
    p3 = instance.get_cellp3();
    p4 = instance.get_cellp4();
}

// assignment operator which tells the compiler how to equate two instances of a pyramid properly if asked to
const Pyramid &Pyramid::operator=(const Pyramid &instance)
{

    // if the instance we have is exactly the same instance we are equating it to then return the
    // address of the instance we have
    // example if we want x to be x=x, then we are equating a variable to itself
    if (this == &instance)
        return (*this);


//extract the x,y and z coordinates of every point from the parameter 
//and store them inside a double each then appoint the doubles to the x,y and z points of the new instance
    double x = instance.get_cellp0().get_x();
    double y = instance.get_cellp0().get_y();
    double z = instance.get_cellp0().get_z();
    p0.set_x(x);
    p0.set_y(y);
    p0.set_z(z);

    x = instance.get_cellp1().get_x();
    y = instance.get_cellp1().get_y();
    z = instance.get_cellp1().get_z();
    p1.set_x(x);
    p1.set_y(y);
    p1.set_z(z);

    x = instance.get_cellp2().get_x();
    y = instance.get_cellp2().get_y();
    z = instance.get_cellp2().get_z();
    p2.set_x(x);
    p2.set_y(y);
    p2.set_z(z);

    x = instance.get_cellp3().get_x();
    y = instance.get_cellp3().get_y();
    z = instance.get_cellp3().get_z();
    p3.set_x(x);
    p3.set_y(y);
    p3.set_z(z);

    x = instance.get_cellp4().get_x();
    y = instance.get_cellp4().get_y();
    z = instance.get_cellp4().get_z();
    p4.set_x(x);
    p4.set_y(y);
    p4.set_z(z);

    return (*this); // returns the address of the instance we are in
}

//######################## NOTE: this assumes that the base of the pyramid lies on the x and y axis #################################
// definition of the volume of a pyramid
double Pyramid::volume(Vector3d &p0, Vector3d &p1, Vector3d &p2, Vector3d &p3, Vector3d &p4)
{

    // the base's area has to be calculated which is 2D
    //a vector of vertices is made for easier implementation 
    vector<Vector3d> points;

//points are entered into the vector
    points.push_back(p0);
    points.push_back(p1);
    points.push_back(p2);
    points.push_back(p3);
    points.push_back(p4);

//vertex made to store the x, y and z coordinates of teh center of mass
    Vector3d center;

    // variables needed for the calculations
    double summation;
    double summationX;
    double summationY;

    // for loop to go through vertices performing a summation calculation
    for (int i = 0; i < 4; ++i)
    {
        summation += ((points[i].get_x()) * (points[i + 1].get_y())) - ((points[i + 1].get_x()) * (points[i].get_y()));
    }

    summation += ((points[3].get_x()) * (points[0].get_y())) - ((points[0].get_x()) * (points[3].get_y())); // first vertex needs to be the last vertex too

    // take the absolut value of the summation if the summation is -ve
    if (summation < 0)
    {

        summation = -summation;
    }

    // the area is then calculate by dividing the absolut value of the summation by 2
    double area = summation / 2;

    // for loop to go through vertices performing a summation calculation
    for (int i = 0; i < 4; ++i)
    {
        summationX += (points[i].get_x() + points[i + 1].get_x()) * ((points[i].get_x()) * (points[i + 1].get_y())) - ((points[i + 1].get_x()) * (points[i].get_y()));
    }

    summationX += ((points[3].get_x()) * (points[0].get_y())) - ((points[0].get_x()) * (points[3].get_y())); // first vertex needs to be the last vertex too

    center.set_x((1 / (6 * area)) * summationX);

    // for loop to go through vertices performing a summation calculation
    for (int i = 0; i < 4; ++i)
    {
        summationY += (points[i].get_y() + points[i + 1].get_y()) * ((points[i].get_x()) * (points[i + 1].get_y())) - ((points[i + 1].get_x()) * (points[i].get_y()));
    }

    summationY += ((points[3].get_x()) * (points[0].get_y())) - ((points[0].get_x()) * (points[3].get_y())); // first vertex needs to be the last vertex too

    Vector3d distanceBetweenBaseAndTip = center - points[4]; // the distance between the tip and the base

    center.set_y((1 / (6 * area)) * summationY); // equation to find the y coordinate of the centriod of the base

    // to calculate the volume (assumes that point number 5 is the top of the pyramid)
    double volume = (distanceBetweenBaseAndTip.get_y() * area) / 3;

    return volume;
} // not sure if it's right might have to do take the height as the distance between the center of the base and the tip instead of a plane y coordinate

//######################## NOTE: this assumes that the base of the pyramid lies on the x and y axis #################################

// definitoin of a center of mass function
Vector3d Pyramid::centerOfMass(Vector3d &p0, Vector3d &p1, Vector3d &p2, Vector3d &p3, Vector3d &p4)
{

    // the center for the Y, X and Z
    // summation method has to be applied twice, once for the area of the base and once for use in the centroid equation

    //a vector of vertices is made for easier implementation 
    vector<Vector3d> points;

//points are entered into the vector
    points.push_back(p0);
    points.push_back(p1);
    points.push_back(p2);
    points.push_back(p3);
    points.push_back(p4);

//vertex made in which the x, y and z coordinates are stored inside
    Vector3d center;

    // variables needed for the calculations
    double summationX;
    double summationY;
    double areaSummation;

    // for loop to go through vertices performing a summation calculation
    for (int i = 0; i < 4; ++i)
    {
        summationX += (points[i].get_x() + points[i + 1].get_x()) * ((points[i].get_x()) * (points[i + 1].get_y())) - ((points[i + 1].get_x()) * (points[i].get_y()));
    }

    summationX += ((points[3].get_x()) * (points[0].get_y())) - ((points[0].get_x()) * (points[3].get_y())); // first vertex needs to be the last vertex too

    // the base's area has to be calculated which is 2D

    // for loop to go through vertices performing a summation calculation
    for (int i = 0; i < 4; ++i)
    {
        areaSummation += ((points[i].get_x()) * (points[i + 1].get_y())) - ((points[i + 1].get_x()) * (points[i].get_y()));
    }

    areaSummation += ((points[3].get_x()) * (points[0].get_y())) - ((points[0].get_x()) * (points[3].get_y())); // first vertex needs to be the last vertex too

    // take the absolut value of the summation if the summation is -ve
    if (areaSummation < 0)
    {

        areaSummation = -areaSummation;
    }

    // the area is then calculated by dividing the absolut value of the summation by 2
    double area = areaSummation / 2;

    center.set_x((1 / (6 * area)) * summationX);

    // for loop to go through vertices performing a summation calculation
    for (int i = 0; i < 4; ++i)
    {
        summationY += (points[i].get_y() + points[i + 1].get_y()) * ((points[i].get_x()) * (points[i + 1].get_y())) - ((points[i + 1].get_x()) * (points[i].get_y()));
    }

    summationY += ((points[3].get_x()) * (points[0].get_y())) - ((points[0].get_x()) * (points[3].get_y())); // first vertex needs to be the last vertex too

    center.set_y((1 / (6 * area)) * summationY); // equation to find the y coordinate of the centriod of the base

    center.set_z(0); // since its the base its z has to be 0

    Vector3d distanceBetweenBaseAndTip = points[4] - center; // the distance between the tip and the base

    center.set_x(distanceBetweenBaseAndTip.get_x() / 4); // the center is now changed to include the z axis and changes the x and y values
    center.set_y(distanceBetweenBaseAndTip.get_y() / 4);
    center.set_z(distanceBetweenBaseAndTip.get_z() / 4);

    return center; // return the center instance
}
//######################### also no way of validating if this is working or not ###############################

