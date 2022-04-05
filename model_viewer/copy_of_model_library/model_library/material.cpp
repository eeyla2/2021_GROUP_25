// Material class - Afolabi

#include "material.hpp"

Material::Material() {} // constructor for when values arent known and we are creating list of materials

Material::Material(int &materialIndex, float &materialDensity, std::string &materialColour, std::string &materialName)
{
    this->materialIndex = materialIndex;
    this->materialDensity = materialDensity;
    this->materialColour = materialColour;
    this->materialName = materialName;
}

Material::~Material() {} // Destructor code does nothing - good practice

// Accessor functions
int Material::get_materialIndex() { return this->materialIndex; }
float Material::get_materialDensity() { return this->materialDensity; }
std::string Material::get_materialColour() { return this->materialColour; }
std::string Material::get_materialName() { return this->materialName; }

// Mutuator functions
void Material::set_materialIndex(int index) { this->materialIndex = index; }
void Material::set_materialDensity(float density) { this->materialDensity = density; }
void Material::set_materialColour(std::string colour) { this->materialColour = colour; }
void Material::set_materialName(std::string name) { this->materialName = name; }

/*
//Test program to ensure Material class works
int main()
{
    Material myMaterial;
    myMaterial.set_materialColour("Green");
    cout << myMaterial.get_materialColour() << "\n";
}
*/