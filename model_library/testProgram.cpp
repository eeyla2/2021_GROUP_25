// Test executable - Daniel
#include "../model_library/model.hpp"

int main()
{
	/*
	//testing vector class - done in model test code below
	int ID = 0;
	float x_coord = 1;
	float y_coord = 2;
	float z_coord = 3;
	Vector3d myVector = Vector3d(ID, x_coord, y_coord, z_coord);
	std::cout << "Vector ID: " << myVector.get_vectorID() << "\n";
	std::cout << "Vector y coord: " << myVector.get_y() << "\n";

	//testing material class - done in model test code below
	int index = 12;
	float density = 10.23;
	string name = "Cheese";
	string colour = "yellow";
	Material myMaterial = Material(index, density, colour, name);
	std::cout << "Material density: " << myMaterial.get_materialDensity() << "\n";
	std::cout << "Material name: " << myMaterial.get_materialName() << "\n";
	*/

	//--------------------------------------------------
	
	std::cout << "\n\n-------------------Reading file & decalring objects-----------------\n";

	std::string filePath = "../files/ExampleModel3.mod"; //  ExampleModel1.mod  //  testFile.mod

	Model myModel = Model(filePath);

	std::cout << "\n-------------------Testing Functionality-----------------\n";

	//------------------------------------------
	std::string nameOfMaterial0 = myModel.get_listOfMaterials().at(0).get_materialName();
	std::cout << "\n\nName of material 0: " << nameOfMaterial0 << "\n\n";

	// string colourOfMaterial0 = myModel.get_listOfMaterials().at(0).get_materialColour();
	// std::cout << "\n\nColour of material 0: " << colourOfMaterial0 << "\n\n";

	int numberOfMaterials = myModel.get_numMaterials();
	std::cout << "Number of materials: " << numberOfMaterials << "\n\n";

	//--------------------------------------

	float vector2_xValue = myModel.get_listOfVectors().at(2).get_x();
	std::cout << "The vector at index 2 has x value: " << vector2_xValue << "\n";

	//----------------------------------

	char cell0_letter = myModel.get_listOfCells().at(0)->get_cellLetter();
	std::cout << "\nThe cell at index 0 has the letter " << cell0_letter << "\n";

	char cell1_letter = myModel.get_listOfCells().at(1)->get_cellLetter();
	std::cout << "\nThe cell at index 1 has the letter " << cell1_letter << "\n\n";

	//Hexahedron Test - assuming using file 1
	std::cout << "Cell 0\n";
	double volH = myModel.get_listOfCells().at(0)->calculateVolume();
	std::cout << "\tVolume of " << cell0_letter << ": " << volH << "\n";
	
	double weightH = myModel.get_listOfCells().at(0)->weight();
	std::cout << "\tWeight of " << cell0_letter << ": " << weightH << "\n";

	Vector3d centreH = myModel.get_listOfCells().at(0)->centerOfMass();
	std::cout << "\tCentre of " << cell0_letter << ": ";
	centreH.print();

	double totalVolume=0;

	for(int i=0; i<myModel.get_numCells(); i++)
	{
		totalVolume += myModel.get_listOfCells().at(i)->calculateVolume();
	}

	std::cout << "\n\nTotal volume: " << totalVolume << "\n\n";


	//Tetrahedron Test
	std::cout << "Cell 1\n";
	double volT = myModel.get_listOfCells().at(1)->calculateVolume();
	std::cout << "\tVolume of " << cell1_letter << ": " << volT << "\n";

	double weightT = myModel.get_listOfCells().at(1)->weight();
	std::cout << "\tWeight of " << cell1_letter << ": " << weightT << "\n";

	Vector3d centreT = myModel.get_listOfCells().at(1)->centerOfMass();
	std::cout << "\tCentre of " << cell1_letter << ": ";
	centreT.print();

	//Saving data to file
	std::string newFilePath = "../files/saveFile.mod";

	myModel.saveToFile(newFilePath);


	std::cout << "\n\n------------------------Matrix functionality-------------------\n";
	
	Matrix3x3 zero = Matrix3x3(' ', 1);
	std::cout << "\nZero matrix:\n";
	zero.printMatrix();

	Matrix3x3 identity = Matrix3x3('i', 0);
	std::cout << "\nIdentitiy matrix:\n";
	identity.printMatrix();
	
	Vector3d myVector = Vector3d(1, 2, 3);
    Vector3d rotationResult;
    //Matrix3x3 myMatrix = Matrix3x3('x', 32);
	float angleRad=float(0.7);	//silly - to remove warning about truncation
	char axis = 'z';
    rotationResult = Matrix3x3(axis, angleRad) * myVector;
	std::cout << "\nVector: ";
	myVector.print(); 
	std::cout << "Rotated about axis " << axis << " by " << angleRad << " rad\n";
	rotationResult.print();

	Matrix3x3 A = Matrix3x3(1, 2, 3, 4, 5, 6, 7, 8, 9);
	Matrix3x3 B = Matrix3x3(9, 8, 7, 6, 5, 4, 3, 2, 1);
	std::cout << "\nMatrix A:\n";
	A.printMatrix();
	std::cout << "\nMatrix B:\n";
	B.printMatrix();

	Matrix3x3 result = A * 3;
	std::cout << "\n A * 3 =\n";
	result.printMatrix();

	Matrix3x3 result2 = A * B;
	std::cout << "\n A * B =\n";
	result2.printMatrix(); 

	Matrix3x3 anotherMatrix = Matrix3x3(1, 3, 2, -3, -1, -3, 2, 3, 1);
	float detOf3x3 = anotherMatrix.det3x3();
	std::cout << "\nAnother matrix:\n";
	anotherMatrix.printMatrix();
	std::cout << "Determinant: " << detOf3x3 << "\n";
	
	Matrix3x3 inverseAnother = anotherMatrix.inverse();
	std::cout << "\nInverse of matrix:\n";
	inverseAnother.printMatrix();

	Matrix3x3 aTranspose = A.transpose();
	std::cout << "\nTranpose of A:\n";
	aTranspose.printMatrix();
	return 0;
}