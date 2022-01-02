//Material class - Afolabi

#include <iostream>
#include <string>

using namespace std;


class material{
private:
    int materialIndex;
    float materialDensity;
    string materialName;
    string materialColour;

public:
    material(int materialIndex, float materialDensity, string materialColour, string materialName);
    ~material();

    int get_materialIndex();
    float get_materialDensity();
    string get_materialName();
    string get_materialColour();

    void setmaterialIndex( int i);
    void setmaterialDensity(float d);
    void setmaterialName(string n);
    void setmaterialColour(string c);
  };

int material :: get_materialIndex() {
    return this-> materialIndex;
}

void material :: setmaterialIndex( int i ) {
    this->materialIndex = i;
}

float material :: get_materialDensity() {
    return this->materialDensity;
}

void material :: setmaterialDensity( float d ) {
    this->materialDensity = d;
}

string material :: get_materialName() {
    return this-> materialName;
}

void material :: setmaterialName( string n ) {
    this->materialName = n;
}

string materials :: get_materialColour() {
    return this-> materialColour;
}

void material :: setmaterialColour( string c ) {
    this->materialColour = c;
}
