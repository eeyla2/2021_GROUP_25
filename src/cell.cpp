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
    float mass=0; //mass is declared

    mass=volume*density; //mass is found by multiplying the volume and the density

    weight=mass*9.81;// the weight is found by multiplying the mass and the gravity of earth
    
    return weight;
}

//destructor for the cell class
Cell::~Cell() {}

//tetrahedron class declared and has its contents defined
class Tetrahedron : public Cell
{

    //private variables and functions of the tetrahedron class
private:
    vector<int> Tpoints; // instance of vectors

    double volume(vector<int> Tpoints); //volume of a tetrahedron

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
};

//constructor for tetrahedron vectors declared
Tetrahedron ::Tetrahedron(vector<int> &CTpoints)
{
    for (auto i = CTpoints.begin(); i != CTpoints.end(); ++i)
        this->Tpoints.pushback(i);
}

//destructor for the tetrhedron vectors
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
} //not 100% sure if its all right#############

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

//hexahedron class declared and has its contents defined
class Hexahedron : public Cell
{
private:
    vector<int> Hpoints; //instances of vectors

    double volume(vector<int> Hpoints); //volume of a Hexahedronhedron

public:
    Hexahedron(vector<int> &CHpoints); //vector constructor called
    ~Hexahedron();                     //hexahedron destructor applied to the vector constructor

    vector<int> get_Hpoints(unsigned int i); //returns the value of the vector i from the set of vectors

    void set_Hpoints(unsigned int i, int val); //changes the value of the vector i from the set of vectors

    Hexahedron(const Hexahedron &instance); // copying constructor applied

    const Hexahedron &operator=(const Hexahedron &instance); //assignment operator for Pyramid

    //operators for subtraction, addition, dotmulitplication, cross multiplication
    //all have to be applied here
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

//definition of the volume of a tetrahedron
double Hexahedron::volume(vector<int> &CHpoints)
{

    //three implementations of a triple product have to be implemented then added

    //implementation of the first triple product

    //a vector is declared to store the three parts of the first triple product inside
    vector<int> firstTriple;

    firstTriple[0] = Hpoints[7] - Hpoints[0]; //first part is calculated and by subtracting the vertex 0 from the vertex 7
    firstTriple[1] = Hpoints[1] - Hpoints[0]; //second edge is calculated and by subtracting the vertex 0 from the vertex 1
    firstTriple[2] = Hpoints[3] - Hpoints[5]; //third edge is calculated and by subtracting the vertex 5 from the vertex 3

    double firstCrossMult = firstTriple[1] x firstTriple[2]; //cross multiplication which is set up by pisit

    double firstDotMult = firstTriple[0].firstCrossMult; //dot multiplication which is set up by pisit

    //implementation of the second triple product

    //a vector is declared to store the three parts of the second triple product inside
    vector<int> secondTriple;

    secondTriple[0] = Hpoints[7] - Hpoints[0]; //first part is calculated and by subtracting the vertex 0 from the vertex 7
    secondTriple[1] = Hpoints[4] - Hpoints[0]; //second edge is calculated and by subtracting the vertex 0 from the vertex 4
    secondTriple[2] = Hpoints[5] - Hpoints[6]; //third edge is calculated and by subtracting the vertex 6 from the vertex 5

    double secondCrossMult = secondTriple[1] x secondTriple[2]; //cross multiplication which is set up by pisit

    double secondDotMult = secondTriple[0].secondCrossMult; //dot multiplication which is set up by pisit

    //implementation of the third triple product

    //a vector is declared to store the three parts of the third triple product inside
    vector<int> thirdTriple;

    thirdTriple[0] = Hpoints[7] - Hpoints[0]; //first part is calculated and by subtracting the vertex 0 from the vertex 7
    thirdTriple[1] = Hpoints[2] - Hpoints[0]; //second edge is calculated and by subtracting the vertex 0 from the vertex 2
    thirdTriple[2] = Hpoints[6] - Hpoints[3]; //third edge is calculated and by subtracting the vertex 3 from the vertex 6

    double thirdCrossMult = thirdTriple[1] x thirdTriple[2]; //cross multiplication which is set up by pisit

    double thirdDotMult = thirdTriple[0].thirdCrossMult; //dot multiplication which is set up by pisit

    //calculate the volume by adding the three Dot multiplication products of the triple products and then
    //by dividing by 3 factorial which is 6
    double volume = (firstDotMult + secondDotMult + thirdDotMult) / 6;

    //return the volume as a float
    return volume;
} //not 100% sure if its all right#############

//pyramid class declared and has its contents defined
class Pyramid : public Cell
{

private:
    vector<int> Ppoints; //instances of vectors

    volume(vector<int> Ppoints); //volume of a pyramid

public:
    Pyramid(vector<int> CPpoints); //constructor for tetrahedron vectors is called
    ~Pyramid();                    //destructor for pyramid vectors is called

    vector<int> get_Ppoints(unsigned int i); //returns the value of the vector i from the set of vectors

    void set_Ppoints(unsigend int i, int val); //changes the value of the vector i from the set of vectors

    Pyramid(const Pyramid &instance); // copying constructor applied

    const Pyramid &operator=(const Pyramid &instance); //assignment operator for Pyramid

    //operators for subtraction, addition, dotmulitplication, cross multiplication
    //all have to be applied here

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