//model.hpp
#ifndef MODEL_HPP
#define MODEL_HPP

/** @file
* Header file for model class
*/

/** Brief description
* The model class is the largest and uses all of the others
* Lists of material, vectors and cells are defined and stored in the model
*/

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

/**
* Blank constructor for creating a new empty Model class
*/
  Model();


/**
*  Constructor that reads files as strings 
*  and declares the objects accordingly setting up 
*  a Model Class
*/
  Model(string &filePath); 
/**
*  //Model Destructor
*/  
  ~Model();

/**
* reads file from the string of the file path or name
*/
  int readFile(string &filePath); 


/**
* saves file to a certin name assigned by the string argument 
*/
  int saveToFile(string &newFilePath);

/*
* Once it is known how many of each letter we have, we declare Materials using this function
*/
  int declareMaterials(string &filePath);

/*
* Once it is known how many of each letter we have, we declare Vectors using this function
*/
  int declareVectors(string &filePath);

/*
* Once it is known how many of each letter we have, we declare Cells using this function
*/
  int declareCells(string &filePath);


  //Accessor functions

  /**
  * Gets value for the private listOfMaterials Variable
  */
  vector<Material> get_listOfMaterials();

  /**
  * Gets value for the private listOVectors Variable
  */
  vector<Vector3d> get_listOfVectors();

  /**
  * Gets values for the private listOfCells Variable
  */
  vector<shared_ptr<Cell>> get_listOfCells();

/**
* Gets values for the private numMaterials Variable
*/
  int get_numMaterials();

/**
* Gets values for the private numVectors Variable
*/
  int get_numVectors();

/**
* Gets values for the private numCells Variable
*/
  int get_numCells();




private:

/**
* variable that indictaes line position for reading
*/
  int currentLine = 1;


  //std::vector is a convenient way of dynamically allocating arrays & manipulating
/**
* Tells us which line in the file the desired letters are for material to read from
*/
  vector<int> materialLineIndexes;

/**
* Tells us which line in the file the desired letters are for vector to read from
*/
  vector<int> vectorLineIndexes;

/**
* Tells us which line in the file the desired letters are for vector to read from
*/
  vector<int> cellLineIndexes;

/**
* List to store the Material for the object  created once data is read from file
*/
  
  vector<Material> listOfMaterials;

/**
* List to store the vectors for the object created once data is read from file
*/
  vector<Vector3d> listOfVectors;

/**
* List to store the Cells for the object created once data is read from file
*/
  vector<shared_ptr<Cell>> listOfCells;
  
  
  //Once we have read file and know how many of each object there are, we will need to resize above vector
/**
* Stores the number of different material vectors and Cells
*/
  int numMaterials = 0, numVectors = 0, numCells = 0;
};


#endif