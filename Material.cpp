#include <iostream>
#include <string>

using namespace std;


class material{
private:
    int materialIndex;
    float density;
    string materialName;
    string colour;

public:
    material(int materialIndex, float density, string colour, string materialName);
    ~material();

    int getMaterialIndex();
    float getDensity();
    string getMaterialName();
    string colour();

    void setMaterialIndex( int i);
    void setDensity(float d);
    void setMaterialName(string n);
    void setColour(string c);
  };

int material :: getMaterialIndex() {
    return this-> materialIndex;
}

void material :: setMaterialIndex( int i ) {
    this->materialIndex = i;
}

float material :: getDensity() {
    return this->density;
}

void material :: setdensity( float d ) {
    this->density = d;
}

string material :: getMaterialName() {
    return this-> materialName;
}

void material :: setMaterialName( string n ) {
    this->materialName = n;
}

string materials :: getColour() {
    return this-> colour;
}

void material :: setColour( string c ) {
    this->colour = c;
}
