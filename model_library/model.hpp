// model.hpp
#ifndef MODEL_HPP
#define MODEL_HPP

/** @file
 * Header file for model class
 */

/** Brief description
 * The model class is the largest and uses all of the others
 * Lists of material, vectors and cells are defined and stored in the model
 */

// Other classes of library

// Commented for the time being so they don't interfere with my tests   -no longer true
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

  /** @brief The model class constructor
   *
   *  Constructor that reads files as strings
   *  and declares the objects accordingly setting up
   *  a Model Class
   *
   *  @param filePath the path to the .mod file being opened
   */
  Model(std::string &filePath);

  /** @brief The model class destructor
   * 
   */
  ~Model();


  /** @brief blah
 *
 * reads through the file and determines the number of 
 * materials, vectors, cells and assigns relevant size
 * std::vectors to store them in
 *
 *  @param filePath the path to the .mod file being opened
 *  @return whether the file was read successfuly
 */
  int readFile(std::string &filePath);


  /** @brief saves the data, which may have been modified to a new file
 *
 * saves the data, which may have been modified to a new file
 *
 *  @param newFilePath the new file path
 *  @return whether the data was saved to the file successfully
 */
  int saveToFile(std::string &newFilePath);

  /*
   * Once it is known how many of each letter we have, we declare Materials using this function
   */
  int declareMaterials(std::string &filePath);

  /*
   * Once it is known how many of each letter we have, we declare Vectors using this function
   */
  int declareVectors(std::string &filePath);

  /*
   * Once it is known how many of each letter we have, we declare Cells using this function
   */
  int declareCells(std::string &filePath);

  // Accessor functions

  /**
   * Gets value for the private listOfMaterials Variable
   */
  std::vector<Material> get_listOfMaterials();

  /**
   * Gets value for the private listOVectors Variable
   */
  std::vector<Vector3d> get_listOfVectors();

  /**
   * Gets values for the private listOfCells Variable
   */
  std::vector<std::shared_ptr<Cell>> get_listOfCells();

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
  int currentLine = 1; /*!< a int currentLine which is used to make sure we are reading from the beginning of the line */

  // std::vector is a convenient way of dynamically allocating arrays & manipulating

  std::vector<int> materialLineIndexes; /*!< a vector materialLineIndexes which tells us which line in the file the desired letters are for, for material to read from */

  std::vector<int> vectorLineIndexes; /*!< a vector cellLineIndexes which tells us which line in the file the desired letters are for, for vector to read from */

  std::vector<int> cellLineIndexes; /*!< a vector cellLineIndexes which tells us which line in the file the desired letters are for, for cell to read from */

  std::vector<Material> listOfMaterials; /*!< a vector listofMaterials that stores the Materials for the object created once data is read from file */

  std::vector<Vector3d> listOfVectors; /*!< a vector listofvectors that stores the vectors for the object created once data is read from file */

  std::vector<std::shared_ptr<Cell>> listOfCells; /*!< a vector listofCells that stores the Cells for the object created once data is read from file */

  int numMaterials = 0; /*!< a float numMaterials that stores number of materials */
  int numVectors = 0;   /*!< a float numVectors that stores number of vectors */
  int numCells = 0;     /*!< a float numCells that stores number of cells */
};

#endif