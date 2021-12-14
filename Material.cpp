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