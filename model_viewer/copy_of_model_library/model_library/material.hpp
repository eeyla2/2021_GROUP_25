//Material header - Afolabi

#ifndef MATERIAL_HPP
#define MATERIAL_HPP

/** @file
* This file contains the declarations of all exported functions.
*/
/** Brief description
* This description will hopefully be picked up on by doxygen
*/

//Class definition, class member functions in Material.cpp
#include <iostream>
#include <string> 

// using namespace std;

// using std::cout;
// using std::cin;
// using std::string;

class Material
{
public:
    Material();
    Material(int &materialIndex, float &materialDensity, std::string &materialColour, std::string &materialName);
    ~Material();

    int get_materialIndex();
    float get_materialDensity();
    std::string get_materialName();
    std::string get_materialColour();

    void set_materialIndex(int index);
    void set_materialDensity(float density);
    void set_materialColour(std::string colour);
    void set_materialName(std::string name);

private:
    int materialIndex;
    float materialDensity;
    std::string materialName;
    std::string materialColour;
};

#endif