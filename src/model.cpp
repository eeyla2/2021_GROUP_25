//Model class - Daniel

/*
Current status:
Can succesfully read from file, counting number of each of the relevant letters
Based on this list (std::vector), appropriate amount of memory is allocated
Reread file, extracting data necessary to create objects - so far only done for material class
Create instances of the material class based on this data
Save this data to a new file in the required format
*/

/*
//TODO:

*/

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

//##################################################
//actual classes will be defined in header files but doing it here for testing purposes
class Material
{

public:
  Material();                                                                                         //constructor for when we are allocating memory but don't know values
  Material(int &materialIndex, float &materialDensity, string &materialColour, string &materialName); //example constructor - construcotr overloading
  ~Material();                                                                                        //Destructor

  int get_materialIndex();
  float get_materialDensity();
  string get_materialColour();
  string get_materialName();

private:
  int materialIndex;
  float materialDensity;
  string materialColour;
  string materialName;
};

Material::Material() {} //constructor for when values arent known and we are creating list of materials

Material::Material(int &materialIndex, float &materialDensity, string &materialColour, string &materialName)
{
  this->materialIndex = materialIndex;
  this->materialDensity = materialDensity;
  this->materialColour = materialColour;
  this->materialName = materialName;
}

Material::~Material() {} //Destructor code does nothing - good practice

//Accessor functions
int Material::get_materialIndex() { return this->materialIndex; }
float Material::get_materialDensity() { return this->materialDensity; }
string Material::get_materialColour() { return this->materialColour; }
string Material::get_materialName() { return this->materialName; }
//###########################################################

/*
class Vector3d
{

};
*/

class Vector3d
{
public:
  //constructor
  Vector3d();
  Vector3d(int &vectorID, float &x, float &y, float &z);
  ~Vector3d();
  //public here for ease of use

  int get_vectorID();
  float get_x();
  float get_y();
  float get_z();

private:
  int vectorID;
  float x;
  float y;
  float z;
};

Vector3d::Vector3d() {}

Vector3d::Vector3d(int &vectorID, float &x, float &y, float &z)
{
  this->vectorID = vectorID;
  this->x = x;
  this->y = y;
  this->z = z;
}

//accessor functions
int Vector3d::get_vectorID() { return this->vectorID; }
float Vector3d::get_x() { return this->x; }
float Vector3d::get_y() { return this->y; }
float Vector3d::get_z() { return this->z; }

Vector3d::~Vector3d() {}

class Cell
{
public:
  Cell();
  Cell(char &cellLetter, int &cellIndex);
  ~Cell();

  //Cell constructor with number of arguments for creating tetrahedron

  int get_cellIndex();
  char get_cellLetter();

private:
  int cellIndex;
  char cellLetter;
};

Cell::Cell()
{
}

Cell::Cell(char &cellLetter, int &cellIndex)
{
  this->cellLetter = cellLetter;
  this->cellIndex = cellIndex;
}

int Cell::get_cellIndex() { return this->cellIndex; }
char Cell::get_cellLetter() { return this->cellLetter; }

Cell::~Cell() {}

//The Tetrahedron class is a child of the Cell class

class Tetrahedron : public Cell
{
public:
  Tetrahedron();
  ~Tetrahedron();

  Tetrahedron(int &cellIndex, char &cellLetter, Material &theMaterial, Vector3d &p0, Vector3d &p1, Vector3d &p2, Vector3d &p3);
  
  customFunction() { return 3; }
  //cellIndex materialIndex  vectorIndexP0  vectorIndexP1 vectorIndexP2  vectorIndexP3
private:
  int cellIndex;
  char cellLetter;
  Material theMaterial;
  Vector3d p0;
  Vector3d p1;
  Vector3d p2;
  Vector3d p3;
};

Tetrahedron::Tetrahedron() {}

Tetrahedron::Tetrahedron(int &cellIndex, char &cellLetter, Material &theMaterial, Vector3d &p0, Vector3d &p1, Vector3d &p2, Vector3d &p3) 
            : Cell(cellLetter, cellIndex)
{
  this->cellIndex = cellIndex;
  this->cellLetter = cellLetter;
  this->theMaterial = theMaterial;
  this->p0 = p0;
  this->p1 = p1;
  this->p2 = p2;
  this->p3 = p3;
}

Tetrahedron::~Tetrahedron() {}

//####################################################
class Model
{

public:
  //Model constructor - creating a model from your own set of cells?
  //Model Destructor

  int readFile(string &filePath); //funtion for reading from file - pass string of file name/path as argument

  int saveToFile(string &newFilePath);

  //Once we know how many of each letter we have, we go about creating them
  int declareMaterials(string &filePath);
  int declareVectors(string &filePath);
  int declareCells(string &filePath);
  //##############################
  //Accessor functions
  //Format get_
  vector<Material> get_listOfMaterials();
  vector<Vector3d> get_listOfVectors();
  vector<Cell> get_listOfCells();

  int get_numMaterials();
  int get_numVectors();
  int get_numCells();

private:
  int currentLine = 1;

  //std::vector is a convenient way of dynamically allocating arrays & manipulating
  //the following list of indexes tells us on which line in the file the desired letters are
  vector<int> materialLineIndexes;
  vector<int> vectorLineIndexes;
  vector<int> cellLineIndexes;

  //List to store the objects that are created once data is read from file
  vector<Material> listOfMaterials;
  vector<Vector3d> listOfVectors;
  vector<Cell> listOfCells;

  //Once we have read file and know how many of each object there are, we will need to resize above vector
  int numMaterials = 0, numVectors = 0, numCells = 0;
};

//Accessor functions
vector<Material> Model::get_listOfMaterials() { return this->listOfMaterials; }
vector<Vector3d> Model::get_listOfVectors() { return this->listOfVectors; }
vector<Cell> Model::get_listOfCells() { return this->listOfCells; }

int Model::get_numMaterials() { return this->numMaterials; }
int Model::get_numVectors() { return this->numVectors; }
int Model::get_numCells() { return this->numCells; }

//Function to read from file
int Model::readFile(string &filePath) //arguments - file name/path as a string)
{
  //We first want to allocate all the memory necessary for the objects in the file
  //To do this, check for all the relevant letters and count them, assign relevant
  //Keep a track of the line on which the letters occur, so when we come to actually extract the data we already know which line it is on

  ifstream inputFile(filePath); //Open file

  string line; //declare string to represent each line in the file

  if (!inputFile.is_open())
  {
    cout << "Failed to open file";
    return (-1);
  }

  if (currentLine != 1)
  {
    currentLine = 1; //ensure we are reading from the beginning of the file
  }

  while (getline(inputFile, line))
  {
    //cout << "Current line: " << currentLine << "\n";
    if (!line.empty())
    {
      //cout << line[0];  //displays first character of each line
      //cout << '\n';
      switch (line[0])
      {
      case 'm':
        numMaterials++;
        materialLineIndexes.push_back(currentLine);
        break;
      case 'v':
        numVectors++;
        vectorLineIndexes.push_back(currentLine);
        break;
      case 'c':
        numCells++;
        cellLineIndexes.push_back(currentLine);
        break;
      }
    }
    currentLine++; //we have completed reading from a line, increment for next loop round
  }
  cout << "\nRead " << currentLine << " lines from file\n";
  cout << "\nNum m: " << numMaterials << "\tNum v: " << numVectors << "\tNum c: " << numCells << "\n";

  //dynamically allocating memory for the lists of objects we will need using std::vector wrapper/container
  //doing all at once due to overheads with dynamic memory allocation
  listOfMaterials.resize(numMaterials); //will this be private as vector<Material> listOfMaterials, then number done here?
  listOfVectors.resize(numVectors);
  listOfCells.resize(numCells);

  //cout << "List of materials size " << listOfMaterials.size() << "\n";

  currentLine = 1; //reset current line back to 1 for future reads of the file
  return 0;
}

//Function to declare materials
int Model::declareMaterials(string &filePath)
{
  ifstream inputFile(filePath); //Open file

  string line; //declare string to represent each line in the file

  if (currentLine != 1)
  {
    currentLine = 1; //ensure we are reading from the beginning of the file
  }

  if (!inputFile.is_open())
  {
    cout << "Failed to open file";
    return (-1);
  }

  while (getline(inputFile, line))
  {
    //cout << "\nCurrent line: " << currentLine << "\n";

    if (!line.empty())
    {
      //cout << "Material line Indexes size: " << materialLineIndexes.size() << "\n";
      for (int i = 0; i < int(materialLineIndexes.size()); i++)
      {
        //cout << "Line index at i: " << materialLineIndexes.at(i) << "\n";

        if (int(materialLineIndexes.at(i)) == currentLine) //if the current line is one we previously determined was a material line
        {
          cout << "\nLine " << currentLine << " contains material\n"; //displays line on which materials are

          istringstream iss(line);
          char lineLetter;
          int materialIndex;
          float materialDensity;
          string materialColour;
          string materialName;

          //currently assuming that the file is in the specified format - TODO?: Make it very robust to random whitespaces etc.?
          if (!(iss >> lineLetter >> materialIndex >> materialDensity >> materialColour >> materialName))
          {
            cout << "File formatting is wrong\n";
            return (-1);
          }
          else
          {
            cout << "We have: " << lineLetter << " " << materialIndex << " " << materialDensity << " " << materialColour << " " << materialName << "\n";
            //call the constructor for the material class
            listOfMaterials.at(i) = Material(materialIndex, materialDensity, materialColour, materialName);
          }
        }
      }
    }
    currentLine++; //we have completed a line, increment for next loop round
  }
  return 0;
}

//Function to declare vectors
int Model::declareVectors(string &filePath)
{
  ifstream inputFile(filePath); //Open file

  string line; //declare string to represent each line in the file

  if (currentLine != 1)
  {
    currentLine = 1; //ensure we are reading from the beginning of the file
  }

  if (!inputFile.is_open())
  {
    cout << "Failed to open file";
    return (-1);
  }

  while (getline(inputFile, line))
  {
    //cout << "\nCurrent line: " << currentLine << "\n";

    if (!line.empty())
    {
      //cout
      for (int i = 0; i < int(vectorLineIndexes.size()); i++)
      {
        //cout <<

        if (int(vectorLineIndexes.at(i)) == currentLine) //if the current line is one we previously determined was a vectorline
        {
          //cout << "\nLine " << currentLine << " contains vector\n"; //displays line on which vectors are

          istringstream iss(line);
          char lineLetter;
          int vectorID;
          float x, y, z;

          //currently assuming that the file is in the specified format - TODO?: Make it very robust to random whitespaces etc.?
          if (!(iss >> lineLetter >> vectorID >> x >> y >> z))
          {
            cout << "File formatting is wrong\n";
            return (-1);
          }
          else
          {
            //cout << "We have: " << lineLetter << " " << vectorID << " "
            //                    << x  << " " << y << " " << z << "\n";
            //call the constructor for the vector class
            listOfVectors.at(i) = Vector3d(vectorID, x, y, z);
          }
        }
      }
    }
    currentLine++; //we have completed a line, increment for next loop round
  }

  return 0;
}

//Function to declare cells
int Model::declareCells(string &filePath)
{
  ifstream inputFile(filePath); //Open file

  string line; //declare string to represent each line in the file

  if (currentLine != 1)
  {
    currentLine = 1; //ensure we are reading from the beginning of the file
  }

  if (!inputFile.is_open())
  {
    cout << "Failed to open file";
    return (-1);
  }

  while (getline(inputFile, line))
  {
    //cout << "\nCurrent line: " << currentLine << "\n";

    if (!line.empty())
    {
      //cout
      for (int i = 0; i < int(cellLineIndexes.size()); i++)
      {
        //cout <<

        if (int(cellLineIndexes.at(i)) == currentLine) //if the current line is one we previously determined was a cell line
        {
          //cout << "\nLine " << currentLine << " contains cell\n"; //displays lines on which cels are

          istringstream iss(line);
          char lineLetter;
          int cellIndex;
          char cellLetter;
          int materialIndex;

          //currently assuming that the file is in the specified format - TODO?: Make it very robust to random whitespaces etc.?
          if (!(iss >> lineLetter >> cellIndex >> cellLetter))
          {
            cout << "File formatting is wrong\n";
            return (-1);
          }
          else
          {
            cout << "We have: " << cellLetter << " with index " << cellIndex << "\n";

            switch (cellLetter) //how many verticies we need to read depends on shape
            {
            case 't':
              cout << "t\n";
              int vectorIndexP0, vectorIndexP1, vectorIndexP2, vectorIndexP3;
              if (!(iss >> materialIndex >> vectorIndexP0 >> vectorIndexP1 >> vectorIndexP2 >> vectorIndexP3))
              {
                cout << "File formatting is wrong\n";
                return (-1);
              }
              else
              {
                cout << "We have: " << cellIndex << " " << cellLetter << " " << materialIndex << " "
                     << vectorIndexP0 << " " << vectorIndexP1 << " " << vectorIndexP2 << " " << vectorIndexP3 << "\n";

                //call constructor for tetrahedron
                //store tetrahedron in list of cells

                //Tetrahedron(int &cellIndex, Material &materialIndex, Vector3d &p0, Vector3d &p1, Vector3d &p2, Vector3d &p3);
                //cellIndex materialIndex  vectorIndexP0  vectorIndexP1 vectorIndexP2  vectorIndexP3
                listOfCells.at(i) = Tetrahedron(cellIndex,
                                                cellLetter,
                                                listOfMaterials.at(materialIndex),
                                                listOfVectors.at(vectorIndexP0),
                                                listOfVectors.at(vectorIndexP1),
                                                listOfVectors.at(vectorIndexP2),
                                                listOfVectors.at(vectorIndexP3));
              }
              break;

            case 'p':
              cout << "p\n";
              break;
            case 'h':
              cout << "h\n";
              break;
            }

            //call the constructor for the cell class
            //will actually be calling constructors for individual shapes first
            //listOfCells.at(i) = Cell(cellLetter, cellIndex);
          }
        }
      }
    }
    currentLine++; //we have completed a line, increment for next loop round
  }

  return 0;
}

//Function for saving read data to file
//TODO: write vector and cell data to the file
int Model::saveToFile(string &newFilePath)
{
  ofstream outputFile(newFilePath);
  outputFile << "# This is my file, there are many like it, but this one is mine\n"
             << endl;

  //write material data
  for (int i = 0; i < int(listOfMaterials.size()); i++)
  {
    outputFile << "m "
               << listOfMaterials.at(i).get_materialIndex() << " "
               << listOfMaterials.at(i).get_materialDensity() << " "
               << listOfMaterials.at(i).get_materialColour() << " "
               << listOfMaterials.at(i).get_materialName() << endl;
  }
  //write vector data
  //write cell data
  cout << "\nSaved to file\n";
  return 0;
}

//########################################################################################

int main()
{
  Model myModel;

  string filePath = "../model_files/ExampleModel1.mod"; //  ExampleModel1.mod  //  testFile.mod

  int fileResult = myModel.readFile(filePath);
  if (fileResult) //if the file is not read successfully
  {
    cout << "Now what?\n";
  }

  //------------------------------------------
  int modelResultM = myModel.declareMaterials(filePath);

  string nameOfMaterial1 = myModel.get_listOfMaterials().at(0).get_materialName();
  cout << "\n\nName of material 0: " << nameOfMaterial1 << "\n\n";

  int numberOfMaterials = myModel.get_numMaterials();
  cout << "Number of materials: " << numberOfMaterials << "\n\n";

  //--------------------------------------
  //declaring vectors
  int modelResultV = myModel.declareVectors(filePath);
  float vector_idk_xValue = myModel.get_listOfVectors().at(10).get_x();
  cout << "The vector at index idk (currently 10) has x value: " << vector_idk_xValue << "\n";
  //----------------------------------

  //declaring cells
  int modelResultC = myModel.declareCells(filePath);
  char cell_idk_letter = myModel.get_listOfCells().at(1).get_cellLetter();
  cout << "\nThe cell at index idk (currently 1) has the letter " << cell_idk_letter << "\n";
  //int test = myModel.get_listOfCells().at(1).
//

  //Saving data to file
  string newFilePath = "../model_files/saveFile.mod";

  myModel.saveToFile(newFilePath);
}