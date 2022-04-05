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
Make most things const so we dont accidently change data
Freeing memory when program ends?
computing the centre of the model - weighted average of the indiviudal centres?

*/

#include "model.hpp"

// using namespace std;

// using std::vector;

Model::Model() {}

//model constructor - reads file and declares objects
Model::Model(std::string &filePath)
{
  int fileResult = readFile(filePath);
  if (fileResult) //if the file is not read successfully
  {
    std::cout << "\nFailed to create model\n"; //TODO - just a warning sufficent?
    exit(0);
  }
  int modelResultM = declareMaterials(filePath);
  int modelResultV = declareVectors(filePath);
  int modelResultC = declareCells(filePath);
  if (!(modelResultM && modelResultV && modelResultC)) //if above declare functions all returned zero
  {
    std::cout << "\nSuccessfuly declared materials, vectors & cells\n";
  }
}

Model::~Model() {} //destructor - TODO: freeing memory declared

//Accessor functions
std::vector<Material> Model::get_listOfMaterials() { return listOfMaterials; } 
std::vector<Vector3d> Model::get_listOfVectors() { return listOfVectors; }
std::vector<std::shared_ptr<Cell>> Model::get_listOfCells() { return this->listOfCells; }
//vector<Cell> Model::get_listOfCells() { return this->listOfCells; }

int Model::get_numMaterials() { return this->numMaterials; }
int Model::get_numVectors() { return this->numVectors; }
int Model::get_numCells() { return this->numCells; }

//#######################################

//Function to read from file
int Model::readFile(std::string &filePath) //arguments - file name/path as a string)
{
  //We first want to allocate all the memory necessary for the objects in the file
  //To do this, check for all the relevant letters and count them, assign relevant
  //Keep a track of the line on which the letters occur, so when we come to actually extract the data we already know which line it is on

  std::ifstream inputFile(filePath); //Open file

  std::string line; //declare string to represent each line in the file

  if (!inputFile.is_open())
  {
    std::cout << "Failed to open file";
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
      switch (line[0]) //determine the first letter of the line and assign relevant data
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
  std::cout << "\nRead " << currentLine << " lines from file\n";
  std::cout << "\nNum materials: " << numMaterials << "\tNum verticies: " << numVectors << "\tNum cells: " << numCells << "\n\n";

  //dynamically allocating memory for the lists of objects we will need using std::vector wrapper/container
  //doing all at once due to overheads with dynamic memory allocation

  listOfMaterials.resize(numMaterials);
  listOfVectors.resize(numVectors);

  //DOnt bother with allocating cell memory in advance as we have to create new shapes
  //listOfCells.resize(numCells);

  //cout << "List of materials size " << listOfMaterials.size() << "\n";

  currentLine = 1; //reset current line back to 1 for future reads of the file
  return 0;
}

//Function to declare materials
int Model::declareMaterials(std::string &filePath)
{
  std::ifstream inputFile(filePath); //Open file

  std::string line; //declare string to represent each line in the file

  if (currentLine != 1)
  {
    currentLine = 1; //ensure we are reading from the beginning of the file
  }

  if (!inputFile.is_open())
  {
    std::cout << "Failed to open file\n";
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
          //cout << "\nLine " << currentLine << " contains material\n"; //displays line on which materials are

          std::istringstream iss(line);
          char lineLetter;
          int materialIndex;
          float materialDensity;
          std::string materialColour;
          std::string materialName;

          //currently assuming that the file is in the specified format - TODO?: Make it very robust to random whitespaces etc.?
          if (!(iss >> lineLetter >> materialIndex >> materialDensity >> materialColour >> materialName))
          {
            std::cout << "File formatting is wrong\n";
            return (-1);
          }
          else
          {
            std::cout << "We have: " << lineLetter << " " << materialIndex << " " << materialDensity << " " << materialColour << " " << materialName << "\n";
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
int Model::declareVectors(std::string &filePath)
{
  std::ifstream inputFile(filePath); //Open file

  std::string line; //declare string to represent each line in the file

  if (currentLine != 1)
  {
    currentLine = 1; //ensure we are reading from the beginning of the file
  }

  if (!inputFile.is_open())
  {
    std::cout << "Failed to open file\n";
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

          std::istringstream iss(line);
          char lineLetter;
          int vectorID;
          float x, y, z;

          //currently assuming that the file is in the specified format - TODO?: Make it very robust to random whitespaces etc.?
          if (!(iss >> lineLetter >> vectorID >> x >> y >> z))
          {
            std::cout << "File formatting is wrong\n";
            return (-1);
          }
          else
          {
            std::cout << "We have: " << lineLetter << " " << vectorID << " "
                 << x << " " << y << " " << z << "\n";
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
int Model::declareCells(std::string &filePath)
{
  std::ifstream inputFile(filePath); //Open file
  std::string line;                  //declare string to represent each line in the file

  if (currentLine != 1)
  {
    currentLine = 1; //ensure we are reading from the beginning of the file
  }

  if (!inputFile.is_open())
  {
    std::cout << "Failed to open file\n";
    return (-1);
  }

  while (getline(inputFile, line))
  {
    //cout << "\nCurrent line: " << currentLine << "\n";

    if (!line.empty())
    {
      //cout << "Cell lineIndexes.size() " << cellLineIndexes.size() << "\n";
      for (int i = 0; i < int(cellLineIndexes.size()); i++)
      {
        //cout <<

        if (int(cellLineIndexes.at(i)) == currentLine) //if the current line is one we previously determined was a cell line
        {
          //cout << "\nLine " << currentLine << " contains cell\n"; //displays lines on which cels are

          std::istringstream iss(line);
          char lineLetter;
          int cellIndex;
          char cellLetter;
          int materialIndex;

          //currently assuming that the file is in the specified format - TODO?: Make it very robust to random whitespaces etc.?
          if (!(iss >> lineLetter >> cellIndex >> cellLetter))
          {
            std::cout << "File formatting is wrong\n";
            return (-1);
          }
          else
          {
            //cout << "We have: " << cellLetter << " with index " << cellIndex << "\n";

            int vectorIndexP0, vectorIndexP1, vectorIndexP2, vectorIndexP3,
                vectorIndexP4, vectorIndexP5, vectorIndexP6, vectorIndexP7; //defining all vector indices
            switch (cellLetter)                                             //how many verticies we need to read depends on shape
            {
            case 't':
              //tetrahedron has 4 points
              if (!(iss >> materialIndex >> vectorIndexP0 >> vectorIndexP1 >> vectorIndexP2 >> vectorIndexP3))
              {
                std::cout << "File formatting is wrong\n";
                return (-1);
              }
              else
              {
                std::cout << "We have: " << cellIndex << " " << cellLetter << " " << materialIndex << " "
                     << vectorIndexP0 << " " << vectorIndexP1 << " " << vectorIndexP2 << " " << vectorIndexP3 << "\n";

                //call constructor for tetrahedron
                //store tetrahedron in list of cells

                //Tetrahedron(int &cellIndex, Material &materialIndex, Vector3d &p0, Vector3d &p1, Vector3d &p2, Vector3d &p3);
                //cellIndex materialIndex  vectorIndexP0  vectorIndexP1 vectorIndexP2  vectorIndexP3

                //listOfCells.push_back(shared_ptr<Cell>(new Tetrahedron(arguments)));
                auto it = listOfCells.begin() + i;

                listOfCells.insert(it, std::shared_ptr<Cell>(new Tetrahedron(cellIndex, cellLetter,
                                                                        listOfMaterials.at(materialIndex),
                                                                        listOfVectors.at(vectorIndexP0), listOfVectors.at(vectorIndexP1),
                                                                        listOfVectors.at(vectorIndexP2), listOfVectors.at(vectorIndexP3))));
              }
              break;

            //TODO:still need to write code for creating pyramids and hexahedrons
            case 'p':
              //pyramid has 5 points
              if (!(iss >> materialIndex >> vectorIndexP0 >> vectorIndexP1 >> vectorIndexP2 >> vectorIndexP3 >> vectorIndexP4))
              {
                std::cout << "File formatting is wrong\n";
                return (-1);
              }
              else
              {
                std::cout << "We have: " << cellIndex << " " << cellLetter << " " << materialIndex << " "
                     << vectorIndexP0 << " " << vectorIndexP1 << " " << vectorIndexP2 << " " << vectorIndexP3 << " " << vectorIndexP4 << "\n";

                auto it = listOfCells.begin() + i;
                listOfCells.insert(it, std::shared_ptr<Cell>(new Pyramid(cellIndex, cellLetter,
                                                                    listOfMaterials.at(materialIndex),
                                                                    listOfVectors.at(vectorIndexP0), listOfVectors.at(vectorIndexP1),
                                                                    listOfVectors.at(vectorIndexP2), listOfVectors.at(vectorIndexP3),
                                                                    listOfVectors.at(vectorIndexP4))));
              }
              break;
            case 'h':

              //hexahedron has 8 points
              if (!(iss >> materialIndex >> vectorIndexP0 >> vectorIndexP1 >> vectorIndexP2 >> vectorIndexP3 >> vectorIndexP4 >> vectorIndexP5 >> vectorIndexP6 >> vectorIndexP7))
              {
                std::cout << "File formatting is wrong\n";
                return (-1);
              }
              else
              {
                std::cout << "We have: " << cellIndex << " " << cellLetter << " " << materialIndex << " "
                     << vectorIndexP0 << " " << vectorIndexP1 << " " << vectorIndexP2 << " " << vectorIndexP3 << " "
                     << vectorIndexP4 << " " << vectorIndexP5 << " " << vectorIndexP6 << " " << vectorIndexP7 << "\n";

                auto it = listOfCells.begin() + i;

                listOfCells.insert(it, std::shared_ptr<Cell>(new Hexahedron(cellIndex, cellLetter,
                                                                       listOfMaterials.at(materialIndex),
                                                                       listOfVectors.at(vectorIndexP0), listOfVectors.at(vectorIndexP1),
                                                                       listOfVectors.at(vectorIndexP2), listOfVectors.at(vectorIndexP3),
                                                                       listOfVectors.at(vectorIndexP4), listOfVectors.at(vectorIndexP5),
                                                                       listOfVectors.at(vectorIndexP6), listOfVectors.at(vectorIndexP7))));
              }
              break;
            }
          }
        }
      }
    }
    currentLine++; //we have completed a line, increment for next loop round
  }

  //as we have declared all objects and are done with this file it can be closed
  inputFile.close();
  return 0;
} //function end

//Function for saving read data to file
int Model::saveToFile(std::string &newFilePath)
{
  std::ofstream outputFile(newFilePath);
  outputFile << "# This is my file, there are many like it, but this one is mine\n"
             << std::endl;

  //write material data
  for (int i = 0; i < int(listOfMaterials.size()); i++)
  {
    outputFile << "m "
               << listOfMaterials.at(i).get_materialIndex() << " "
               << listOfMaterials.at(i).get_materialDensity() << " "
               << listOfMaterials.at(i).get_materialColour() << " "
               << listOfMaterials.at(i).get_materialName() << std::endl;
  }
  outputFile << "\n"; //sepeartae different parts of datat with newline

  //write vector data
  for (int i = 0; i < int(listOfVectors.size()); i++)
  {
    outputFile << "v "
               << listOfVectors.at(i).get_vectorID() << " "
               << listOfVectors.at(i).get_x() << " "
               << listOfVectors.at(i).get_y() << " "
               << listOfVectors.at(i).get_z() << std::endl;
  }

  outputFile << "\n";
  //write cell data
  //cout << "Num cells: " << listOfCells.size() << "\n";

  for (int i = 0; i < int(listOfCells.size()); i++)
  {
    outputFile << "c ";
    char myLetter = listOfCells.at(i)->get_cellLetter();
    //cout << myLetter << "\n";
    switch (myLetter)
    {

    case 't':
      outputFile << listOfCells.at(i)->get_cellIndex() << " "
                 << listOfCells.at(i)->get_cellLetter() << " "
                 << listOfCells.at(i)->get_cellMaterial().get_materialIndex() << " "
                 << listOfCells.at(i)->get_cellp0().get_vectorID() << " "
                 << listOfCells.at(i)->get_cellp1().get_vectorID() << " "
                 << listOfCells.at(i)->get_cellp2().get_vectorID() << " "
                 << listOfCells.at(i)->get_cellp3().get_vectorID() << "\n";

      break;

    case 'p':
      outputFile << listOfCells.at(i)->get_cellIndex() << " "
                 << listOfCells.at(i)->get_cellLetter() << " "
                 << listOfCells.at(i)->get_cellMaterial().get_materialIndex() << " "
                 << listOfCells.at(i)->get_cellp0().get_vectorID() << " "
                 << listOfCells.at(i)->get_cellp1().get_vectorID() << " "
                 << listOfCells.at(i)->get_cellp2().get_vectorID() << " "
                 << listOfCells.at(i)->get_cellp3().get_vectorID() << " "
                 << listOfCells.at(i)->get_cellp4().get_vectorID() << "\n";
      break;

    case 'h':
      outputFile << listOfCells.at(i)->get_cellIndex() << " "
                 << listOfCells.at(i)->get_cellLetter() << " "
                 << listOfCells.at(i)->get_cellMaterial().get_materialIndex() << " "
                 << listOfCells.at(i)->get_cellp0().get_vectorID() << " "
                 << listOfCells.at(i)->get_cellp1().get_vectorID() << " "
                 << listOfCells.at(i)->get_cellp2().get_vectorID() << " "
                 << listOfCells.at(i)->get_cellp3().get_vectorID() << " "
                 << listOfCells.at(i)->get_cellp4().get_vectorID() << " "
                 << listOfCells.at(i)->get_cellp5().get_vectorID() << " "
                 << listOfCells.at(i)->get_cellp6().get_vectorID() << " "
                 << listOfCells.at(i)->get_cellp7().get_vectorID() << "\n";
    }
  }

  outputFile.close();
  std::cout << "\nSaved to file\n\n";
  return 0;
}

//########################################################################################

/*
//Commented out main as currently testing use of Cmake lists
//linking etc.

int main()
{
  string filePath = "../proprietary_files/ExampleModel1.mod"; //  ExampleModel1.mod  //  testFile.mod
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

  //char cell_idk_letter = myModel.get_listOfCells().at(1).get_cellLetter();

  char cell_idk_letter = myModel.get_listOfCells().at(0)->get_cellLetter();
  cout << "\nThe cell at index idk (currently 0) has the letter " << cell_idk_letter << "\n";

  cout << "All zero means everything declared" << modelResultM << " " << modelResultV << " " << modelResultC << "\n";

  //Testing inheritance
  double vol0 = myModel.get_listOfCells().at(0)->calculateVolume();
  cout << "Vol 0: " << vol0 << "\n";

  
  //below only vlaid if there are 2 cells present 
  double vol1 = myModel.get_listOfCells().at(1)->calculateVolume();
  cout << "Density 1: " << vol1 << "\n";
  

   //float testing = myModel.get_listOfCells().at(0)->customFunc();
   //cout << "Testing: " << testing << "\n";

  //Saving data to file
  string newFilePath = "../model_files/saveFile.mod";

  myModel.saveToFile(newFilePath);
}
*/