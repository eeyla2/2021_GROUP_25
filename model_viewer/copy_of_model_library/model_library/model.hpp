//Model header - Daniel

#ifndef MODEL_HPP
#define MODEL_HPP

//Other classes of library

//Commented for the time being so they don't interfere with my tests   -no longer true
#include "material.hpp"
//#include "vector.hpp" - included via matrix
#include "cell.hpp"
#include "matrix.hpp"

// includes - some could propaly go back to .cpp
//#include <iostream> - included in material.hpp
#include <fstream>
#include <sstream>
//#include <string>   - included in material.hpp
//#include <vector> - included in cell.hpp
#include <memory> //for managing vector list of different classes for shared_ptr


class Model
{

public:
  Model();
  Model(std::string &filePath); //model constructor - reads files and declares objects
  ~Model();//Model Destructor

  int readFile(std::string &filePath); //funtion for reading from file - pass string of file name/path as argument

  int saveToFile(std::string &newFilePath);

  //Once we know how many of each letter we have, we go about creating them
  int declareMaterials(std::string &filePath);
  int declareVectors(std::string &filePath);
  int declareCells(std::string &filePath);


  //Accessor functions
  std::vector<Material> get_listOfMaterials();
  std::vector<Vector3d> get_listOfVectors();
  std::vector<std::shared_ptr<Cell>> get_listOfCells();

  int get_numMaterials();
  int get_numVectors();
  int get_numCells();

private:
  int currentLine = 1;

  //std::vector is a convenient way of dynamically allocating arrays & manipulating
  //the following list of indexes tells us on which line in the file the desired letters are
  std::vector<int> materialLineIndexes;
  std::vector<int> vectorLineIndexes;
  std::vector<int> cellLineIndexes;

  //List to store the objects that are created once data is read from file
  std::vector<Material> listOfMaterials;
  std::vector<Vector3d> listOfVectors;

  std::vector<std::shared_ptr<Cell>> listOfCells;
  //Once we have read file and know how many of each object there are, we will need to resize above vector
  int numMaterials = 0, numVectors = 0, numCells = 0;
};


#endif