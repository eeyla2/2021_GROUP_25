//Model class - Daniel

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

//actual classes will be defined in header files but doing it here for testing purposes
class Material
{
public:
  //Material(int materialIndex, float density, string colour, string materialName); //example constructor
};

class Vector3d
{
};

class Cell
{
};

class Model
{
private:
  int currentLine = 1;

public:
  //funtion for reading from file - pass string of file name/path as argument
  //within this file - will call constructors of the other classes

  //Model constructor - creating a model from your own set of cells

  //member functions
  //e.g. Model::readFile()

  int readFile(string &filePath);
  int declareMaterials(string &filePath);

  vector<int> materialLineIndexes;
  vector<int> vectorLineIndexes;
  vector<int> cellLineIndexes;

  int numMaterials = 0, numVectors = 0, numCells = 0;

  // vector<Material> listOfMaterials(numMaterials); //will this be private as vector<Material> listOfMaterials, then number done here?
  // vector<Vector3d> listOfVectors(numVectors);
  // vector<Cell> listOfCells(numCells);

  //##############################
  //Accessor functions
  //Format get_


};

//Accessor functions



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

  //int numMaterials = 0, numVectors = 0, numCells = 0; //this will be obsolete, we can just determine size of below vector - maybe not for vectors of objects

  //the following list of indexes tells us on which line in the file the desired letters are
  //vector is a convenient way of dynamically allocating arrays & manipulating

  //TODO: make this data private with get functions for it
  // vector<int> fileMaterialIndexes;
  // vector<int> fileVectorIndexes;
  // vector<int> fileCellIndexes;

  //moved below to funciton variables, will need to be made private too
  int currentLine = 1; //first line of file
  

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
        break;
      case 'c':
        numCells++;
        break;
      }
    }
    currentLine++; //now currentline is private, we need to use set function//we have completed a line, increment for next loop round
    //set_currentLine()
  }
  cout << "\nRead " << currentLine << " lines from file\n";
  cout << "\nNum m: " << numMaterials << "\tNum v: " << numVectors << "\tNum c: " << numCells << "\n";

  //dynamically allocating memory for the lists of objects we will need using std::vector wrapper/container
  //doing all at once due to overheads with dynamic memory allocation

  //again below moved to main class instead of this function
  vector<Material> listOfMaterials(numMaterials); //will this be private as vector<Material> listOfMaterials, then number done here?
  vector<Vector3d> listOfVectors(numVectors);
  vector<Cell> listOfCells(numCells);

  currentLine = 1; //reset current line back to 1, this will need to be a function once data is private
  return 0;
}

int Model::declareMaterials(string &filePath)
{
  ifstream inputFile(filePath); //Open file

  string line; //declare string to represent each line in the file

  if (!inputFile.is_open())
  {
    cout << "Failed to open file";
    return (-1);
  }
  //do we need to check the file is open?
  while (getline(inputFile, line))
  {
    //cout << "Current line: " << currentLine << "\n";

    for (int i = 0; i < materialLineIndexes.size(); i++)
    {
      //cout << materialLineIndexes.at(i) << "\n";
      if (materialLineIndexes.at(i) == currentLine) //if the current line is one we previously determined was a material line
      {
        cout << "\nLine " << currentLine << " contains material\n"; //displays line on which materials are

        istringstream iss(line);
        char materialLetter;
        int materialIndex;
        float materialDensity;
        string materialColour;
        string materialName;

        if (!(iss >> materialLetter >> materialIndex >> materialDensity >> materialColour >> materialName))
        {
          cout << "File formatting is wrong\n";
          break;
        }
        else
        {
          cout << "We have: " << materialLetter << " " << materialIndex << " " << materialDensity << " " << materialColour << " " << materialName << "\n";
          //call the constructor for the material class
          //listOfMaterials.at(i) = Material(materialIndex, materialDensity, materialColour, materialName);
        }
      }
    }

    currentLine++; //we have completed a line, increment for next loop round
  }
  return (0);
}

int main()
{
  Model myModel;

  string filePath = "../model_files/ExampleModel1.mod";

  int fileResult = myModel.readFile(filePath);
  if (fileResult) //if the file is not read successfully
  {
    cout << "Now what?\n";
  }

  int modelResult = myModel.declareMaterials(filePath);
}