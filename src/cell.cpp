//Cell class - Laith
#include <vector>

//classes are capital letters

//ONLY AN ABSTRACT FOR CLARITY
//this will be class material and i will inherit the characteristics to different types of material according to the indexID it has
class shapes
{
private:
    //indexID
    //Name
    //colour
    //density

public:
    //the weight function that is currently in the shape classes will actually be inherited
}

//tetrahedron class declared and has its contents defined
class Tetrahedron : public shapes
{

    //private variables and functions of the tetrahedron class
private:
    vector<int> Tpoints; // instance of vectors

    volume(vector<int> Tpoints); //volume of a tetrahedron

public:
    Tetrahedron(vector<int> &CTpoints); //constructor for tetrahedron vectors is called
    ~Tetrahedron();                     //destructor for tetrahedron vector constructor called

    vector<int> get_Tpoints(unsigned int i); //returns the value of the vector i from the set of vectors

    void set_Tpoints(unsigned int i, int val); //changes the value of the vector i from the set of vectors

    Tetrahedron(const Tetrahedron &instance); // copying constructor applied (Note: this is the same function
    //as the normal constructor but with an instance argument where a whole instance is supplied)

    const Tetrahedron &operator=(const Tetrahedron &instance);//assignment operator for Pyramid
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
Tetrahedron::volume(vector<int> &CTpoints)
{

    //the edges coming out of the same vector are calcualted(still abstract)
    a = p1 - p2; //first edge is calculated and given the name 'a' in accordance to the equation v=(1/3!)|a.(bxc| which will be used later
    b = p1 - p3; //second edge is calculated and given the name 'a' in accordance to the equation v=(1/3!)|a.(bxc| which will be used later
    c = p1 - p4; //third edge is calculated and given the name 'a' in accordance to the equation v=(1/3!)|a.(bxc| which will be used later

} //continued later##########

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

    return (*this);//returns the address of the instance we are in 
}

//hexahedron class declared and has its contents defined
class Hexahedron : public shapes
{
private:
    vector<int> Hpoints; //instances of vectors

    volume(vector<int> Hpoints); //volume of a Hexahedronhedron

public:
    Hexahedron(vector<int> &CHpoints); //vector constructor called
    ~Hexahedron();                     //hexahedron destructor applied to the vector constructor

    vector<int> get_Hpoints(unsigned int i); //returns the value of the vector i from the set of vectors

    void set_Hpoints(unsigned int i, int val); //changes the value of the vector i from the set of vectors

    Hexahedron(const Hexahedron &instance); // copying constructor applied

    const Hexahedron &operator=(const Hexahedron &instance);//assignment operator for Pyramid

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

    return (*this);//returns the address of the instance we are in 
}

//pyramid class declared and has its contents defined
class Pyramid : public shapes
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

    const Pyramid &operator=(const Pyramid &instance);//assignment operator for Pyramid

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

    return (*this);//returns the address of the instance we are in 
}