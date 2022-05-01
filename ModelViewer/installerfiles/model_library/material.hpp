//material.hpp
#ifndef MATERIAL_HPP
#define MATERIAL_HPP

/** @file
* Header file for material
*/

/** Brief description
* Contains class declaration for the material class
*/

//Class definition, class member functions in Material.cpp
#include <iostream>
#include <string> 
using namespace std;


class Material
{
public:
    Material();
    Material(int &materialIndex, float &materialDensity, string &materialColour, string &materialName);
    ~Material();

    int get_materialIndex();
    float get_materialDensity();
    string get_materialName();
    string get_materialColour();

    void set_materialIndex(int index);
    void set_materialDensity(float density);
    void set_materialColour(string colour);
    void set_materialName(string name);

private:
    int materialIndex;
    float materialDensity;
    string materialName;
    string materialColour;
};

#endif