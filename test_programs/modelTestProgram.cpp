// Test executable for Model / testing building with Cmake - Daniel
#include "../src/model.hpp"

//This was a test program used with only the vector class in model.cpp
//More to test how things would fit together

int main()
{
	/*
	//testing vector class - done in model test code below
	int ID = 0;
	float x_coord = 1;
	float y_coord = 2;
	float z_coord = 3;
	Vector3d myVector = Vector3d(ID, x_coord, y_coord, z_coord);
	cout << "Vector ID: " << myVector.get_vectorID() << "\n";
	cout << "Vector y coord: " << myVector.get_y() << "\n";

	//testing material class - done in model test code below
	int index = 12;
	float density = 10.23;
	string name = "Cheese";
	string colour = "yellow";
	Material myMaterial = Material(index, density, colour, name);
	cout << "Material density: " << myMaterial.get_materialDensity() << "\n";
	cout << "Material name: " << myMaterial.get_materialName() << "\n";
	*/

	//--------------------------------------------------
	//Model test

	string filePath = "../proprietary_files/testFile.mod"; //  ExampleModel1.mod  //  testFile.mod
	
	Model myModel = Model(filePath);


	cout << "\n-------------------Testing Functionality-----------------\n";

	//------------------------------------------

	string nameOfMaterial1 = myModel.get_listOfMaterials().at(0).get_materialName();
	cout << "\n\nName of material 0: " << nameOfMaterial1 << "\n\n";

	int numberOfMaterials = myModel.get_numMaterials();
	cout << "Number of materials: " << numberOfMaterials << "\n\n";

	//--------------------------------------

	float vector_idk_xValue = myModel.get_listOfVectors().at(2).get_x();
	cout << "The vector at index idk (currently 2) has x value: " << vector_idk_xValue << "\n";
	//----------------------------------

	char cell_idk_letter = myModel.get_listOfCells().at(0)->get_cellLetter();
	cout << "\nThe cell at index idk (currently 0) has the letter " << cell_idk_letter << "\n";

/*
	//Testing inheritance
	double vol0 = myModel.get_listOfCells().at(0)->calculateVolume();
	cout << "Vol 0: " << vol0 << "\n";

	//below only vlaid if there are 2 cells present
	double vol1 = myModel.get_listOfCells().at(1)->calculateVolume();
	cout << "Density 1: " << vol1 << "\n";
*/

	//Saving data to file
	string newFilePath = "../proprietary_files/saveFile.mod";

	myModel.saveToFile(newFilePath);
	

	return 0;
}