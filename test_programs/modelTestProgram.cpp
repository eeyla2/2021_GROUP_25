// Test executable for Model / testing building with Cmake - Daniel
#include "../src/model.hpp"

//This was a test program used with only the vector class in model.cpp
//More to test how things would fit together


int main()
{
	int ID = 0;
	float x_coord = 1;
	float y_coord = 2;
	float z_coord = 3;
	Vector3d myVector = Vector3d(ID, x_coord, y_coord, z_coord);
	cout << "Vector ID: " << myVector.get_vectorID() << "\n";
	cout << "Vector y coord: " << myVector.get_y() << "\n";
	
	

	int index = 12;
    float density = 10.23;
    string name = "Cheese";
    string colour = "yellow";
	Material myMaterial = Material(index, density, colour, name);
	cout << "Material density: " << myMaterial.get_materialDensity() << "\n";
	cout << "Material name: " << myMaterial.get_materialName() << "\n";


	return 0;
}