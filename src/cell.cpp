#include <vector>

//classes are capital letters

//ONLY AN ABSTRACT FOR CLARITY
//this will be class material and i will inherit the characteristics to different types of material according to the indexID it has
class Cell
{
public:
    //Cell constructor for the cell letter and Index called
    Cell(char &CcellLetter, int &CcellIndex);
    ~Cell(); //destructor for the cell called

    //first get returns the value of cell Index, while second get returns the value of cell Letter

    int get_cellIndex();
    char get_cellLetter();

    //virtual function allows the correct version of volume and center of massto be called for each shape
    virtual double volume();
    virtual double centerofMass();
    double weight();

    //weight of the cell calculated

protected:
    int cellIndex;   //the cell Index
    char cellLetter; //the cell letter

    //the weight function that is currently in the Cell classes will actually be inherited
}

//constructor for the cell letter and cell index
Cell::Cell(char &CcellLetter, int &CcellIndex)
{
    this->cellLetter = CcellLetter;
    this->cellIndex = CcellIndex;
}

//an accessor/get function to access the data for Index in the private part of the Cell class
int Cell::get_cellIndex() { return this->cellIndex; }

//an accessor/get function to access the data for Letter in the private part of the Cell class
char Cell::get_cellLetter() { return this->cellLetter; }

//volume left empty because it is determined inside the cell that inherit the function
double Cell::volume()
{
}

//center of mass left empty because it is determined inside the cell that inherit the function
double Cell::centerOfMass()
{
}

//center of mass left empty because it is determined inside the cell that inherit the function
double Cell::weight()
{
    float mass = 0; //mass is declared

    mass = volume * density; //mass is found by multiplying the volume and the density

    double weight = mass * 9.81; // the weight is found by multiplying the mass and the gravity of earth

    return weight;
}

//destructor for the cell class
Cell::~Cell() {}

//tetrahedron class declared and has its contents defined
class Tetrahedron : public Cell
{
public:
    Tetrahedron(vector<int> &CTpoints); //constructor for tetrahedron vectors is called
    ~Tetrahedron();                     //destructor for tetrahedron vector constructor called

    vector<int> get_Tpoints(unsigned int i); //returns the value of the vector i from the set of vectors

    void set_Tpoints(unsigned int i, int val); //changes the value of the vector i from the set of vectors

    Tetrahedron(const Tetrahedron &instance); // copying constructor applied (Note: this is the same function
    //as the normal constructor but with an instance argument where a whole instance is supplied)

    const Tetrahedron &operator=(const Tetrahedron &instance); //assignment operator for Pyramid

    //operators for subtraction, addition, dotmulitplication, cross multiplication
    //all have to be applied here

    //private variables and functions of the tetrahedron class
private:
    vector<int> Tpoints; // instance of vectors

    double volume(vector<int> Tpoints); //volume of a tetrahedron

    vector3d centerOfMass(vector<int> Tpoints);
};

//constructor for tetrahedron vectors declared
Tetrahedron ::Tetrahedron(vector<int> &CTpoints)
{
    for (auto i = CTpoints.begin(); i != CTpoints.end(); ++i)
        this->Tpoints.pushback(i);
}

//destructor for the tetrahedron vectors
Tetrahedron ::~Tetrahedron() {}

//definition of the volume of a tetrahedron
double Tetrahedron::volume(vector<int> &CTpoints)
{

    //the edges coming out of the same vector are calcualted(still abstract)
    float a = Tpoints[0] - Tpoints[1]; //first edge is calculated and given the name 'a' in accordance to the equation v=(1/3!)|a.(bxc| which will be used later
    float b = Tpoints[0] - Tpoints[2]; //second edge is calculated and given the name 'a' in accordance to the equation v=(1/3!)|a.(bxc| which will be used later
    float c = Tpoints[0] - Tpoints[3]; //third edge is calculated and given the name 'a' in accordance to the equation v=(1/3!)|a.(bxc| which will be used later

    double crossmult = bxc; //cross multiplication which is set up by pisit

    double dotmult = a.crossmult; //dot multiplication which is set up by pisit

    //apply absolute value on the variable
    if (dotmult < 0)
        dotmult = -dotmult; //if the variable is negative make it +ve otherwise keep it as is

    //calculate the volume by dividing the absolut value of the dot multiplication result
    //by dividing by 3 factorial which is 6
    double volume = dotmult / 6;

    //return the volume as a float
    return volume;
} //####### im 95% sure its right #############

//an accessor/get function to access the data for the vectors in the private part of the Tetrahedron class
vector<int> Tetrahedron::get_Tpoints(unsigned int i) return Tpoints[i];

//an mutator/set function to change the value of the data for the vectors in the private part of the Tetrahedron class
vector<int> Tetrahedron::set_Tpoints(unsigned int i, int val)
{
    Tpoints[i] = val;
}

//constructor copies the contents of instance into the new instance for a tetrahedron
Tetrahedron::Tetrahedron(const Tetrahedron &instance) :
{
    for (auto i = instance.Tpoints.begins(); i < instance.Tpoints.ends(); ++i)
        Tpoints[i] = instance.Tpoints[i];
}

//assignment operator which tells the compiler how to equate two instances of a tetrhedron properly if asked to
const Tetrahedron &operator=(const Tetrahedron &instance)
{

    //if the instance we have is exactly the same instance we are equating it to then return the
    //address of the instance we have
    //example if we want x to be x=x, then we are equating a variable to itself
    if (this == &instance)
        return (*this);

    for (auto i = instance.Tpoints.begins(); i < instance.Tpoints.ends(); ++i)
        Tpoints[i] = instance.Tpoints[i];

    return (*this); //returns the address of the instance we are in
}

//definition of the volume of a Hexahedron
vector3d Tetrahedron::centerOfMass(vector<int> &Tpoints)
{

    vector3d center; // create a vector instance to store the x, y and z of the center in

    center.x = (Ppoints[0].get_x() + Ppoints[1].get_x() + Ppoints[2].get_x() + Ppoints[3].get_x()) / 4; // set the x of the center

    center.y = (Ppoints[0].get_y() + Ppoints[1].get_y() + Ppoints[2].get_y() + Ppoints[3].get_y()) / 4; //set the y of the center

    center.z = (Ppoints[0].get_z() + Ppoints[1].get_z() + Ppoints[2].get_z() + Ppoints[3].get_z()) / 4; // set the z of the center

    return center; // return the center instance
}//########## not 100% if its alright since 

//hexahedron class declared and has its contents defined
class Hexahedron : public Cell
{
public:
    Hexahedron(vector<int> &CHpoints); //vector constructor called
    ~Hexahedron();                     //hexahedron destructor applied to the vector constructor

    vector<int> get_Hpoints(unsigned int i); //returns the value of the vector i from the set of vectors

    void set_Hpoints(unsigned int i, int val); //changes the value of the vector i from the set of vectors

    Hexahedron(const Hexahedron &instance); // copying constructor applied

    const Hexahedron &operator=(const Hexahedron &instance); //assignment operator for Pyramid

    //operators for subtraction, addition, dotmulitplication, cross multiplication
    //all have to be applied here

private:
    vector<int> Hpoints; //instances of vectors

    double volume(vector<int> Hpoints); //volume of a Hexahedron
};

//constructor for hexahedron vectors declared
Hexahedron ::Hexahedron(vector<int> &CHpoints)
{
    for (auto i = CHpoints.begin(); i != CHpoints.end(); ++i)
        this->Hpoints.pushback(i);
}

//destructor for the hexahedron vector constructor declared
Hexahedron ::~Hexahedron() {}

//an accessor/get function to access the data for the vectors in the private part of the hexahedron class
vector<int> Hexahedron::get_Hpoints(unsigned int i) return Hpoints[i];

//an mutator/set function to change the value of the data for the vectors in the private part of the Hexahedron class
void Hexahedron::set_Hpoints(unsigned int i, int val)
{
    Hpoints[i] = val;
}

//constructor copies the contents of instance into the new instance for a hexahedron
Hexahedron::Hexahedron(const Hexahedron &instance) :
{

    for (auto i = instance.Hpoints.begins(); i < instance.Hpoints.ends(); ++i)
        Hpoints[i] = instance.Hpoints[i];
}

//assignment operator which tells the compiler how to equate two instances of a hexahedron properly if asked to
const Hexahedron &operator=(const Hexahedron &instance)
{

    //if the instance we have is exactly the same instance we are equating it to then return the
    //address of the instance we have
    //example if we want x to be x=x, then we are equating a variable to itself
    if (this == &instance)
        return (*this);

    for (auto i = instance.Hpoints.begins(); i < instance.Hpoints.ends(); ++i)
        Hpoints[i] = instance.Hpoints[i];

    return (*this); //returns the address of the instance we are in
}

//definition of the volume of a Hexahedron
double Hexahedron::volume(vector<int> &Hpoints)
{

    //three implementations of a triple product have to be implemented then added

    //implementation of the first triple product

    //a vector is declared to store the three parts of the first triple product inside
    vector<int> firstTriple;

    firstTriple[0] = Hpoints[7] - Hpoints[0]; //first part is calculated by subtracting the vertex 0 from the vertex 7
    firstTriple[1] = Hpoints[1] - Hpoints[0]; //second edge is calculated by subtracting the vertex 0 from the vertex 1
    firstTriple[2] = Hpoints[3] - Hpoints[5]; //third edge is calculated by subtracting the vertex 5 from the vertex 3

    double firstCrossMult = firstTriple[1] x firstTriple[2]; //cross multiplication which is set up by pisit

    double firstDotMult = firstTriple[0].firstCrossMult; //dot multiplication which is set up by pisit

    //implementation of the second triple product

    //a vector is declared to store the three parts of the second triple product inside
    vector<int> secondTriple;

    secondTriple[0] = Hpoints[7] - Hpoints[0]; //first part is calculated  by subtracting the vertex 0 from the vertex 7
    secondTriple[1] = Hpoints[4] - Hpoints[0]; //second edge is calculated  by subtracting the vertex 0 from the vertex 4
    secondTriple[2] = Hpoints[5] - Hpoints[6]; //third edge is calculated  by subtracting the vertex 6 from the vertex 5

    double secondCrossMult = secondTriple[1] x secondTriple[2]; //cross multiplication which is set up by pisit

    double secondDotMult = secondTriple[0].secondCrossMult; //dot multiplication which is set up by pisit

    //implementation of the third triple product

    //a vector is declared to store the three parts of the third triple product inside
    vector<int> thirdTriple;

    thirdTriple[0] = Hpoints[7] - Hpoints[0]; //first part is calculated by subtracting the vertex 0 from the vertex 7
    thirdTriple[1] = Hpoints[2] - Hpoints[0]; //second edge is calculated by subtracting the vertex 0 from the vertex 2
    thirdTriple[2] = Hpoints[6] - Hpoints[3]; //third edge is calculated by subtracting the vertex 3 from the vertex 6

    double thirdCrossMult = thirdTriple[1] x thirdTriple[2]; //cross multiplication which is set up by pisit

    double thirdDotMult = thirdTriple[0].thirdCrossMult; //dot multiplication which is set up by pisit

    //calculate the volume by adding the three Dot multiplication products of the triple products and then
    //by dividing by 3 factorial which is 6
    double volume = (firstDotMult + secondDotMult + thirdDotMult) / 6;

    //return the volume as a float
    return volume;
} //######################### not 100% sure if its all right since its necessary that the vertices are in the right order #############

//pyramid class declared and has its contents defined
class Pyramid : public Cell
{
public:
    Pyramid(vector<int> CPpoints); //constructor for tetrahedron vectors is called
    ~Pyramid();                    //destructor for pyramid vectors is called

    vector<int> get_Ppoints(unsigned int i); //returns the value of the vector i from the set of vectors

    void set_Ppoints(unsigend int i, int val); //changes the value of the vector i from the set of vectors

    Pyramid(const Pyramid &instance); // copying constructor applied

    const Pyramid &operator=(const Pyramid &instance); //assignment operator for Pyramid

    //operators for subtraction, addition, dotmulitplication, cross multiplication
    //all have to be applied here

private:
    vector<int> Ppoints; //instances of vectors

    double volume(vector<int> Ppoints); //volume of a pyramid

    double Pyramid::centerOfMass(vector<int> &Ppoints); //center of mass of a pyramid

}

//constructor for Pyramid vectors declared
Pyramid::Pyramid(vector<int> &CPpoints)
{

    for (auto i = CPpoints.begin(); i != CPpoints.end(); ++i)
        this->Ppoints.pushback(i);
}

//an accessor/get function to access the data for the vectors in the private part of the Pyramid class
vector<int> Pyramid::get_Ppoints(unsigned int i) return Ppoints[i];

//an mutator/set function to change the value of the data for the vectors in the private part of the Pyramid class
void Pyramid::set_Ppoints(unsigned int i, int val)
{
    Ppoints[i] = val;
}

//constructor copies the contents of instance into the new instance for a Pyramid
Pyramid::Pyramid(const Pyramid &instance) :
{

    for (auto i = instance.Ppoints.begins(); i < instance.Ppoints.ends(); ++i)
        Ppoints[i] = instance.Ppoints[i];
}

//assignment operator which tells the compiler how to equate two instances of a pyramid properly if asked to
const Pyramid &operator=(const Pyramid &instance)
{

    //if the instance we have is exactly the same instance we are equating it to then return the
    //address of the instance we have
    //example if we want x to be x=x, then we are equating a variable to itself
    if (this == &instance)
        return (*this);

    for (auto i = instance.Ppoints.begins(); i < instance.Ppoints.ends(); ++i)
        Ppoints[i] = instance.Ppoints[i];

    return (*this); //returns the address of the instance we are in
}

//######################## NOTE: this assumes that the base of the pyramid lies on the x and y axis #################################
// ############################ NOTE: may also assume the last point is the top of the pyramid #######################################
//definition of the volume of a pyramid
double Pyramid::volume(vector<int> &Ppoints)
{

    //the base's area has to be calculated which is 2D

    //for loop to go through vertices performing a summation calculation
    for (int i = 0; i < 4; ++i)
    {
        double summation += ((Ppoints[i].get_x()) * (Ppoints[i + 1].get_y())) - ((Ppoints[i + 1].get_x()) * (Ppoints[i].get_y()));
    }

    summation += ((Ppoints[3].get_x()) * (Ppoints[0].get_y())) - ((Ppoints[0].get_x()) * (Ppoints[3].get_y())); // first vertex needs to be the last vertex too

    //take the absolut value of the summation if the summation is -ve
    if (summation < 0)
    {

        summation = -summation;
    }

    //the area is then calculate by dividing the absolut value of the summation by 2
    double Area = summation / 2;

    //to calculate the volume (assumes that point number 5 is the top of the pyramid)
    double volume = (Ppoints[5].get_y * Area) / 3;

    return volume;
}//not sure if it's right might have to do take the height as the distance between the center of the base and the tip instead of a plane y coordinate


//######################## NOTE: this assumes that the base of the pyramid lies on the x and y axis #################################
// ############################ NOTE: may also assume the last point is the top of the pyramid #######################################
//definitoin of a center of mass function
vector3d Pyramid::centerOfMass(vector<int> &Ppoints)
{

  //the center for the Y, X and Z 
 //summation method has to be applied twice, once for the arwa of teh base and once for use in the centroid equation

    vector3d center;
    //for loop to go through vertices performing a summation calculation
    for (int i = 0; i < 4; ++i)
    {
        double summationX += (Ppoints[i].get_x() + Ppoints[i+1].get_x())*((Ppoints[i].get_x()) * (Ppoints[i + 1].get_y())) - ((Ppoints[i + 1].get_x()) * (Ppoints[i].get_y()));
    }

    summationX += ((Ppoints[3].get_x()) * (Ppoints[0].get_y())) - ((Ppoints[0].get_x()) * (Ppoints[3].get_y())); // first vertex needs to be the last vertex too

    //the base's area has to be calculated which is 2D 

    //for loop to go through vertices performing a summation calculation
    for (int i = 0; i < 4; ++i)
    {
        double Areasummation += ((Ppoints[i].get_x()) * (Ppoints[i + 1].get_y())) - ((Ppoints[i + 1].get_x()) * (Ppoints[i].get_y()));
    }

    Areasummation += ((Ppoints[3].get_x()) * (Ppoints[0].get_y())) - ((Ppoints[0].get_x()) * (Ppoints[3].get_y())); // first vertex needs to be the last vertex too

    //take the absolut value of the summation if the summation is -ve
    if (Areasummation < 0)
    {

        Areasummation = -Areasummation;
    }

    //the area is then calculated by dividing the absolut value of the summation by 2
    double Area = Areasummation / 2; 

    center.x = (1/(6*Area))* summationX;


     //for loop to go through vertices performing a summation calculation
    for (int i = 0; i < 4; ++i)
    {
        double summationY += (Ppoints[i].get_y() + Ppoints[i+1].get_y()) * ((Ppoints[i].get_x()) * (Ppoints[i + 1].get_y())) - ((Ppoints[i + 1].get_x()) * (Ppoints[i].get_y()));
    }

    summationY += ((Ppoints[3].get_x()) * (Ppoints[0].get_y())) - ((Ppoints[0].get_x()) * (Ppoints[3].get_y())); // first vertex needs to be the last vertex too


    center.y = (1/(6*Area))* summationY; //equation to find the y coordinate of the 

    center.z=0; //since its the base its z has to be 0

    vector3d distanceBetweenBaseAndTip = center - Ppoint[4]; //the distance between the tip and the base

    center = distanceBetweenBaseAndCenter/4;// the center is now changed to include the z axis and changes the x and y values

    return center; // return the center instance

};//################### not sure if i can subtract the a vector3d from vector regularly ##########################
//######################### also no way of validating if this is working or not ############################### 