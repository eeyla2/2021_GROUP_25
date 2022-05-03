// material.hpp
#ifndef MATERIAL_HPP
#define MATERIAL_HPP

/** @file
 * Header file for material
 */

/** Brief description
 * Contains class declaration for the material class
 */

// Class definition, class member functions in Material.cpp
#include <iostream>
#include <string>

class Material
{
public:
    /**
     * Blank constructor for creating a new empty Material class
     */
    Material();

    /**
     *  Constructor for storing materialIndex of each for identification
     *  and its density, color and Name to accoridngly to set up a
     *  a Material Class
     */
    Material(int &materialIndex, float &materialDensity, std::string &materialColour, std::string &materialName);

    /** Destructor
     */
    ~Material();

    /** Accessor which gets the value stored in the private variable "matrialIndex" wthout affecting its value
     */
    int get_materialIndex();

    /** Accessor which gets the value stored in the private variable "materialDensity" wthout affecting its value
     */
    float get_materialDensity();

    /** Accessor which gets the value stored in the private variable "materialName" wthout affecting its value
     */
    std::string get_materialName();

    /** Accessor which gets the value stored in the private variable "materialColour" wthout affecting its value
     */
    std::string get_materialColour();

    /** Mutator which sets the value for private variable materialIndex to be that of the variable "index"
     */
    void set_materialIndex(int index);

    /** Mutator which sets the value for private variable materialDensity to be that of the variable "density"
     */
    void set_materialDensity(float density);

    /** Mutator which sets the value for private variable materialColour to be that of the variable "colour"
     */
    void set_materialColour(std::string colour);

    /** Mutator which sets the value for private variable materialName to be that of the variable "Name"
     */
    void set_materialName(std::string name);

private:
    int materialIndex; /*!< an integer materialIndex that stores the index for each material */

    float materialDensity; /*!< a float materialDensity that stores the density for each material */

    std::string materialName; /*!< a string materialName that stores the Name for each material */

    std::string materialColour; /*!< a string materialColour that stores the Colour for each material */
};

#endif