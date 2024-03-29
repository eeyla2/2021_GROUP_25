//cell.cpp


#include "cell.hpp"

Cell::Cell() {} //default cell constructor

// tetrahedron
Cell::Cell(char &cCellLetter, int &cCellIndex, Material &cTheMaterial, Vector3d &cP0, Vector3d &cP1, Vector3d &cP2, Vector3d &cP3)
{
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

// hexahedron
Cell::Cell(char &cCellLetter, int &cCellIndex, Material &cTheMaterial, Vector3d &cP0, Vector3d &cP1, Vector3d &cP2, Vector3d &cP3,
           Vector3d &cP4, Vector3d &cP5, Vector3d &cP6, Vector3d &cP7)
{
    this->cellIndex = cCellIndex;
    this->cellLetter = cCellLetter;
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

//accessor functions
int Cell::get_cellIndex() const { return this->cellIndex; }     // an accessor/get function to access the data for Index in the private part of the Cell class
char Cell::get_cellLetter() const { return this->cellLetter; }  // an accessor/get function to access the data for Letter in the private part of the Cell class
Material Cell::get_cellMaterial() const { return theMaterial; } //get the material inside the cell class
Vector3d Cell::get_cellp0() const { return p0; }                // accessors/get functions for points
Vector3d Cell::get_cellp1() const { return p1; }
Vector3d Cell::get_cellp2() const { return p2; }
Vector3d Cell::get_cellp3() const { return p3; }
Vector3d Cell::get_cellp4() const { return p4; }
Vector3d Cell::get_cellp5() const { return p5; }
Vector3d Cell::get_cellp6() const { return p6; }
Vector3d Cell::get_cellp7() const { return p7; }

// volume left empty because it is determined inside the cell that inherit the function
float Cell::calculateVolume()
{
    return 0.; // function must return something - even though inherited
}

// virtual center of mass function - correct calculate volume will be called depending on shape object (child class of cell)
Vector3d Cell::centerOfMass()
{
    Vector3d undefinedVector;
    return undefinedVector;
}

float Cell::weight() // weight is calcuated using density and volume
{
    float mass = 0;                                               // mass is declared
    mass = calculateVolume() * theMaterial.get_materialDensity(); // mass is found by multiplying the volume and the density
    float weight = mass * float(9.81);                                  // the weight is found by multiplying the mass and the gravity of earth
    return weight;
}

// destructor for the cell class
Cell::~Cell() {}

// constructors
Tetrahedron::Tetrahedron() {}

Tetrahedron::Tetrahedron(int &tCellIndex, char &tCellLetter, Material &tTheMaterial, Vector3d &tP0, Vector3d &tP1, Vector3d &tP2, Vector3d &tP3)
    : Cell(tCellLetter, tCellIndex, tTheMaterial, tP0, tP1, tP2, tP3)
{
    this->cellIndex = tCellIndex;
    this->cellLetter = tCellLetter;
    this->theMaterial = tTheMaterial;
    this->p0 = tP0;
    this->p1 = tP1;
    this->p2 = tP2;
    this->p3 = tP3;
}

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

    // if the instance we have is exactly the same instance we are equating it to then return the address of the instance we have
    if (this == &instance)
        return (*this);

    //extract the x,y and z coordinates of every point from the parameter
    //and store them inside a float each then appoint the floats to the x,y and z points of the new instance
    float x = instance.get_cellp0().get_x();
    float y = instance.get_cellp0().get_y();
    float z = instance.get_cellp0().get_z();
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

float Tetrahedron::calculateVolume()
{
    // the edges coming out of the same vector are calcualted(still abstract)
    Vector3d a = this->p0 - this->p1; // first edge is calculated and given the name 'a' in accordance to the equation v=(1/3!)|a.(bxc| which will be used later
    Vector3d b = this->p0 - this->p2; // second edge is calculated and given the name 'a' in accordance to the equation v=(1/3!)|a.(bxc| which will be used later
    Vector3d c = this->p0 - this->p3; // third edge is calculated and given the name 'a' in accordance to the equation v=(1/3!)|a.(bxc| which will be used later

    Vector3d crossProductResult = crossProductResult.crossProduct(b, c); // cross multiplication which is set up by pisit

    float dotProductResult = a.dotProduct(crossProductResult); // dot multiplication which is set up by pisit
    // apply absolute value on the variable
    if (dotProductResult < 0)
        dotProductResult = -dotProductResult; // if the variable is negative make it +ve otherwise keep it as is

    // calculate the volume by dividing the absolut value of the dot multiplication result
    // by dividing by 3 factorial which is 6
    float volume = dotProductResult / 6;
    return volume;
}

// definition of the volume of a Hexahedron
Vector3d Tetrahedron::centerOfMass()
{

    Vector3d center; // create a vector instance to store the x, y and z of the center in

    float x = (this->p0.get_x() + this->p1.get_x() + this->p2.get_x() + this->p3.get_x()) / 4;
    float y = (this->p0.get_y() + this->p1.get_y() + this->p2.get_y() + this->p3.get_y()) / 4;
    float z = (this->p0.get_z() + this->p1.get_z() + this->p2.get_z() + this->p3.get_z()) / 4;
    center.set_x(x); // set the x of the center

    center.set_y(y); // set the y of the center

    center.set_z(z); // set the z of the center

    return center; // return the center instance
}

//constructors
Pyramid::Pyramid() {}

Pyramid::Pyramid(int &pCellIndex, char &pCellLetter, Material &pTheMaterial, Vector3d &pP0, Vector3d &pP1, Vector3d &pP2, Vector3d &pP3, Vector3d &pP4)
    : Cell(pCellLetter, pCellIndex, pTheMaterial, pP0, pP1, pP2, pP3, pP4)
{
    this->cellIndex = cellIndex;
    this->cellLetter = cellLetter;
    this->theMaterial = theMaterial;

    this->p0 = pP0;
    this->p1 = pP1;
    this->p2 = pP2;
    this->p3 = pP3;
    this->p4 = pP4;
}

Pyramid::~Pyramid() {} //destructor

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
    //and store them inside a float each then appoint the floats to the x,y and z points of the new instance
    float x = instance.get_cellp0().get_x();
    float y = instance.get_cellp0().get_y();
    float z = instance.get_cellp0().get_z();
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

    return (*this);
}

//NOTE: this assumes that the base of the pyramid lies on the x and y axis(future possible upgrade for code)
float Pyramid::calculateVolume()
{

    // the base's area has to be calculated which is 2D
    //a vector of vertices is made for easier implementation
    std::vector<Vector3d> points;

    //points are entered into the vector
    points.push_back(this->p0);
    points.push_back(this->p1);
    points.push_back(this->p2);
    points.push_back(this->p3);
    points.push_back(this->p4);

    Vector3d center; //vector made to store the x, y and z coordinates of the center of mass

    float summation=0; // variables needed for the calculations
    float summationX=0;
    float summationY=0;

    // for loop to go through vertices performing a summation calculation
    for (int i = 0; i < 3; ++i)
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
    float area = summation / 2;

    // for loop to go through vertices performing a summation calculation
    for (int i = 0; i < 3; ++i)
    {
        summationX += (points[i].get_x() + points[i + 1].get_x()) * ((points[i].get_x()) * (points[i + 1].get_y())) - ((points[i + 1].get_x()) * (points[i].get_y()));
    }

    summationX += ((points[3].get_x()) * (points[0].get_y())) - ((points[0].get_x()) * (points[3].get_y())); // first vertex needs to be the last vertex too
    center.set_x((1 / (6 * area)) * summationX);

    // for loop to go through vertices performing a summation calculation
    for (int i = 0; i < 3; ++i)
    {
        summationY += (points[i].get_y() + points[i + 1].get_y()) * ((points[i].get_x()) * (points[i + 1].get_y())) - ((points[i + 1].get_x()) * (points[i].get_y()));
    }

    summationY += ((points[3].get_x()) * (points[0].get_y())) - ((points[0].get_x()) * (points[3].get_y())); // first vertex needs to be the last vertex too
    Vector3d distanceBetweenBaseAndTip = center - points[4];                                                 // the distance between the tip and the base
    center.set_y((1 / (6 * area)) * summationY);                                                             // equation to find the y coordinate of the centriod of the base

    // to calculate the volume (assumes that point number 5 is the top of the pyramid)
    float volume = (distanceBetweenBaseAndTip.get_y() * area) / 3;

    return volume;
}

// definition of a center of mass function
Vector3d Pyramid::centerOfMass()
{

    // the center for the Y, X and Z
    // summation method has to be applied twice, once for the area of the base and once for use in the centroid equation

    std::vector<Vector3d> points;    //a vector of vertices is made for easier implementation
    points.push_back(this->p0); //points are entered into the vector
    points.push_back(this->p1);
    points.push_back(this->p2);
    points.push_back(this->p3);
    points.push_back(this->p4);

    Vector3d center; //vertex made in which the x, y and z coordinates are stored inside
    Vector3d centerBase;
    Vector3d centerDistanceFromBase;
    // variables needed for the calculations
    float summationX=0;
    float summationY=0;
    float areaSummation=0;

    // for loop to go through vertices performing a summation calculation
    for (int i = 0; i < 4; ++i)
    {
        summationX += (points[i].get_x() + points[i + 1].get_x()) * ((points[i].get_x()) * (points[i + 1].get_y())) - ((points[i + 1].get_x()) * (points[i].get_y()));
    }

    summationX += ((points[3].get_x()) * (points[0].get_y())) - ((points[0].get_x()) * (points[3].get_y())); // first vertex needs to be the last vertex too

    // the base's area has to be calculated which is 2D

    // for loop to go through vertices performing a summation calculation
    for (int i = 0; i < 3; ++i)
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
    float area = areaSummation / 2;

    center.set_x((1 / (6 * area)) * summationX);

    // for loop to go through vertices performing a summation calculation
    for (int i = 0; i < 3; ++i)
    {
        summationY += (points[i].get_y() + points[i + 1].get_y()) * ((points[i].get_x()) * (points[i + 1].get_y())) - ((points[i + 1].get_x()) * (points[i].get_y()));
    }

    summationY += ((points[3].get_x()) * (points[0].get_y())) - ((points[0].get_x()) * (points[3].get_y())); // first vertex needs to be the last vertex too

    center.set_y((1 / (6 * area)) * summationY); // equation to find the y coordinate of the centriod of the base

    center.set_z(0); // since its the base its z has to be 0

    Vector3d distanceBetweenBaseAndTip = (points[4] - centerBase) / 4; // the distance between the tip and the base

    Vector3d centerOfMass = (centerBase + centerDistanceFromBase); //add the distance to the center of Base to get the coordinates

    return centerOfMass; // return the center instance
}

Hexahedron::Hexahedron()
{
}

// constructor for hexahedron vectors declared
Hexahedron::Hexahedron(int &hCellIndex, char &hCellLetter, Material &hTheMaterial, Vector3d &hP0, Vector3d &hP1, Vector3d &hP2, Vector3d &hP3,
                       Vector3d &hP4, Vector3d &hP5, Vector3d &hP6, Vector3d &hP7)
    : Cell(hCellLetter, hCellIndex, hTheMaterial, hP0, hP1, hP2, hP3, hP4, hP5, hP6, hP7)
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
Hexahedron::~Hexahedron() {}

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
    if (this == &instance)
        return (*this);

    //extract the x,y and z coordinates of every point from the parameter
    //and store them inside a float each then appoint the floats to the x,y and z points of the new instance
    float x = instance.get_cellp0().get_x();
    float y = instance.get_cellp0().get_y();
    float z = instance.get_cellp0().get_z();
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

    return (*this);
}

// definition of the volume of a Hexahedron
float Hexahedron::calculateVolume()
{

    // three implementations of a triple product have to be implemented then added

    std::vector<Vector3d> firstTriple; // a vector is declared to store the three parts of the first triple product inside

    firstTriple.push_back(this->p6 - this->p0);
    firstTriple.push_back(this->p1 - this->p0);
    firstTriple.push_back(this->p2 - this->p5);

    Vector3d firstCrossProduct = firstCrossProduct.crossProduct(firstTriple.at(1), firstTriple.at(2));

    float firstDotProduct = firstTriple.at(0).dotProduct(firstCrossProduct);

    // implementation of the second triple product
    // a vector is declared to store the three parts of the second triple product inside
    std::vector<Vector3d> secondTriple;

    secondTriple.push_back(this->p6 - this->p0);
    secondTriple.push_back(this->p4 - this->p0);
    secondTriple.push_back(this->p5 - this->p7);

    Vector3d secondCrossProduct = secondCrossProduct.crossProduct(secondTriple.at(1), secondTriple.at(2));
    float secondDotProduct = secondTriple.at(0).dotProduct(secondCrossProduct);

    //implementation of the third triple product
    // a vector is declared to store the three parts of the third triple product inside

    std::vector<Vector3d> thirdTriple;

    thirdTriple.push_back(this->p6 - this->p0);
    thirdTriple.push_back(this->p3 - this->p0);
    thirdTriple.push_back(this->p7 - this->p2);

    Vector3d thirdCrossProduct = thirdCrossProduct.crossProduct(thirdTriple.at(1), thirdTriple.at(2));
    float thirdDotProduct = thirdTriple.at(0).dotProduct(thirdCrossProduct);

    // calculate the volume by adding the three Dot multiplication products of the triple products and then
    // by dividing by 3 factorial which is 6
    float volume = (firstDotProduct + secondDotProduct + thirdDotProduct) / 6;

    return volume;
}

//NOTE: this assumes that the base is in the XY axis when it could be in e.g YZ axis (future point to consider when improving code)
// definition of a center of mass function
Vector3d Hexahedron::centerOfMass()
{

    // the center equation summation method for the Y and X coordinates
    // has to be applied twice, once for the area of the base and once for use in the centroid equation

    //a vector of vertices is made for easier implementation
    std::vector<Vector3d> points;
    points.push_back(this->p0);
    points.push_back(this->p1);
    points.push_back(this->p2);
    points.push_back(this->p3);
    points.push_back(this->p4);
    points.push_back(this->p5);
    points.push_back(this->p6);
    points.push_back(this->p7);

    // store the coordinates of the center of the base inside the centerBase variable
    Vector3d centerBase;

    // variables needed for the calculations

    float areaSummationBase = 0;
    float summationXBase = 0;
    float summationYBase = 0;

    // for loop to go through vertices performing a summation calculation
    for (int i = 0; i < 3; ++i)
    {
        summationXBase += (points[i].get_x() + points[i + 1].get_x()) * ((points[i].get_x()) * (points[i + 1].get_y())) - ((points[i + 1].get_x()) * (points[i].get_y()));
    }

    summationXBase += ((points[3].get_x()) * (points[0].get_y())) - ((points[0].get_x()) * (points[3].get_y())); // first vertex needs to be the last vertex too

    // the base's area has to be calculated which is 2D

    // for loop to go through vertices performing a summation calculation
    for (int i = 0; i < 3; ++i)
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
    float areaBase = areaSummationBase / 2;

    centerBase.set_x(float((1 / (6 * areaBase)) * summationXBase));

    // for loop to go through vertices performing a summation calculation
    for (int i = 0; i < 3; ++i)
    {
        summationYBase += (points[i].get_y() + points[i + 1].get_y()) * ((points[i].get_x()) * (points[i + 1].get_y())) - ((points[i + 1].get_x()) * (points[i].get_y()));
    }

    summationYBase += ((points[3].get_x()) * (points[0].get_y())) - ((points[0].get_x()) * (points[3].get_y())); // first vertex needs to be the last vertex too

    centerBase.set_y((1 / (6 * areaBase)) * summationYBase); // equation to find the y coordinate of the

    centerBase.set_z(float(0)); //set value to z to zero for base

    // the center equation summation method for the Y and X coordinates
    // has to be applied twice, once for the area of the base and once for use in the centroid equation

    Vector3d centerTop;

    float areaSummationTop = 0;
    float summationXTop = 0;
    float summationYTop = 0;

    // for loop to go through vertices performing a summation calculation
    for (int i = 4; i < 7; ++i)
    {
        summationXTop += (points[i].get_x() + points[i + 1].get_x()) * ((points[i].get_x()) * (points[i + 1].get_y())) - ((points[i + 1].get_x()) * (points[i].get_y()));
    }

    summationXTop += ((points[7].get_x()) * (points[4].get_y())) - ((points[4].get_x()) * (points[7].get_y())); // first vertex needs to be the last vertex too

    // the base's area has to be calculated which is 2D

    // for loop to go through vertices performing a summation calculation
    for (int i = 4; i < 7; ++i)
    {
        areaSummationTop += ((points[i].get_x()) * (points[i + 1].get_y())) - ((points[i + 1].get_x()) * (points[i].get_y()));
    }

    areaSummationTop += ((points[7].get_x()) * (points[4].get_y())) - ((points[4].get_x()) * (points[7].get_y())); // first vertex needs to be the last vertex too

    // take the absolut value of the summation if the summation is -ve
    if (areaSummationTop < 0)
    {

        areaSummationTop = -areaSummationTop;
    }

    // the area is then calculated by dividing the absolut value of the summation by 2
    float areaTop = areaSummationTop / 2;

    centerTop.set_x((1 / (6 * areaTop)) * summationXTop);

    // for loop to go through vertices performing a summation calculation
    for (int i = 4; i < 7; ++i)
    {
        summationYTop += (points[i].get_y() + points[i + 1].get_y()) * ((points[i].get_x()) * (points[i + 1].get_y())) - ((points[i + 1].get_x()) * (points[i].get_y()));
    }

    summationYTop += ((points[7].get_x()) * (points[4].get_y())) - ((points[4].get_x()) * (points[7].get_y())); // first vertex needs to be the last vertex too

    centerTop.set_y(float((1 / (6 * areaTop)) * summationYTop)); // equation to find the y coordinate of the center of the top

    //calculate sides as vectors
    Vector3d sideA = points[6] - points[5];
    Vector3d sideB = points[6] - points[7];
    Vector3d sideC = points[7] - points[4];
    Vector3d sideD = points[5] - points[4];

    //distance between side A and side C
    Vector3d distanceBetweenSidesAC = sideA - sideC;

    //distance between side B and D
    Vector3d distanceBetweenSidesBD = sideB - sideD;

    //################ Note: anything between brackets in the following explanation is merely a subset ####################################
    //apply equation y = m(yx)*x + c(yx) and equation z=m(zy)y + c(zy) then substitute y into the second equation
    // where we get the equation z = m(zy)*m(yx)*x + m(zy)*c(yx) + c(zy)

    if (0 != distanceBetweenSidesAC.get_z())
    {

        float mYX = distanceBetweenSidesAC.get_y() / distanceBetweenSidesAC.get_z(); //slope where y depends on x

        float cYX = sideA.get_y(); //the y-intersection for y and x relationship

        float mZY = distanceBetweenSidesAC.get_z() / distanceBetweenSidesAC.get_y(); //slope where z depends on x

        float cZY = sideA.get_z(); // the y-intersection for z and x relationship

        float z = mZY * mYX * centerTop.get_x() + mZY * cYX + cZY; // equation for z coordinate of the center of mass of the top

        centerTop.set_z(z); //store the z into the vector3d

        Vector3d centerDistanceFromBase = (centerTop - centerBase) / float(2); // the distance between the center and the base

        Vector3d centerOfMass = centerBase + centerDistanceFromBase; //add the distance to the center of Base to get the coordinates

        //error check for center of masses that don't work
        if (1 == ((std::isnan(centerOfMass.get_x())) || (std::isnan(centerOfMass.get_y())) || (std::isnan(centerOfMass.get_z()))))
        {

            std::cout << "Error in center of mass calculation !\n"
                 << std::endl;

            //set values
            centerOfMass.set_x(0);
            centerOfMass.set_y(0);
            centerOfMass.set_z(0);
        }

        return centerOfMass;
    }

    //if the difference between BD sides in terms of z coordinates is not zero then apply the following
    else if (0 != distanceBetweenSidesBD.get_z())
    {

        float mYX = distanceBetweenSidesBD.get_y() / distanceBetweenSidesBD.get_z(); //slope where y depends on x

        float cYX = sideA.get_y(); //the y-intersection for y and x relationship

        float mZY = distanceBetweenSidesBD.get_z() / distanceBetweenSidesBD.get_y(); //slope where z depends on x

        float cZY = sideA.get_z(); // the y-intersection for z and x relationship

        float z = mZY * mYX * centerTop.get_x() + mZY * cYX + cZY; // equation for z coordinate of the center of mass of the top

        centerTop.set_z(z); //store the z into the vector3d

        Vector3d centerDistanceFromBase = (centerTop - centerBase) / 2; // the distance between the center and the base

        Vector3d centerOfMass = centerBase + centerDistanceFromBase; //add the distance to the center of Base to get the coordinates

        //something is wrong with this calcualtion, maybe a divide by zero error, reuslt fro examplefile 1 Centre of H: [0.5,0.5,-nan(ind)] or just that centrebase not defined?
        return centerOfMass;
    }

    //this is applied when all the z coordinates of the points are the same
    else
    {
        centerTop.set_z(points[6].get_z()); // set the value of the center of the top identical
        //to the z of any random point on the top since in this case the base is straight

        Vector3d centerDistanceFromBase = (centerTop - centerBase) / 2; // the distance between the center and the base

        Vector3d centerOfMass = centerBase + centerDistanceFromBase; //add the distance to the center of Base to get the coordinates

        return centerOfMass;
    }
}

