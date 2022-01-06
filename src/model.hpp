//Model header - Daniel

#ifndef MODEL_HPP
#define MODEL_HPP

//Other classes of library

//Commented for the time being so they don't interfere with my tests
#include "material.hpp"
//#include "vector.hpp"
//#include "cell.hpp"

// includes - some could propaly go back to .cpp
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <memory> //for managing vector list of different classes for shared_ptr

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

class Cell
{
public:
  Cell();

  Cell(char &cellLetter, int &cellIndex, Material &theMaterial, Vector3d &p0, Vector3d &p1, Vector3d &p2, Vector3d &p3); //tetrahdron
  Cell(char &cellLetter, int &cellIndex, Material &theMaterial, Vector3d &p0, Vector3d &p1, Vector3d &p2, Vector3d &p3, Vector3d &p4); //pyramid
  Cell(char &cellLetter, int &cellIndex, Material &theMaterial, Vector3d &p0, Vector3d &p1, Vector3d &p2, Vector3d &p3,
       Vector3d &p4, Vector3d &p5, Vector3d &p6, Vector3d &p7); //hexahedron

  ~Cell();

  //Cell constructor with number of arguments for creating tetrahedron

  int get_cellIndex();
  char get_cellLetter();
  int get_cellMaterialIndex();  //replaced below - actually return material
  int get_cellp0Index();
  int get_cellp1Index();
  int get_cellp2Index();
  int get_cellp3Index();
  int get_cellp4Index();
  int get_cellp5Index();
  int get_cellp6Index();
  int get_cellp7Index(); //this really doesnt feel sensible

  Material get_cellMaterial();

  //virtual function allows the correct version of calculateVolume to be called for each shape
  virtual double calculateVolume();

protected:
  int cellIndex;
  char cellLetter;
  Material theMaterial;
  Vector3d p0, p1, p2, p3, p4, p5, p6, p7;
  //This doesnt feel that intelligent - not quite using inheriitance correctly
  //Questions regarding dynamic casting, how to use shared pointers properly
  //supposedly i should be able to access the shapes using pointers, not currenly clear how
};

class Tetrahedron : public Cell
{
public:
  Tetrahedron();
  ~Tetrahedron();

  Tetrahedron(int &cellIndex, char &cellLetter, Material &theMaterial, Vector3d &p0, Vector3d &p1, Vector3d &p2, Vector3d &p3);

  double calculateVolume();

  //cellIndex materialIndex  vectorIndexP0  vectorIndexP1 vectorIndexP2  vectorIndexP3
private:
  int cellIndex;
  char cellLetter;
  Material theMaterial;
  Vector3d p0, p1, p2, p3;
};
class Pyramid : public Cell
{
public:
  Pyramid();
  ~Pyramid();

  Pyramid(int &cellIndex, char &cellLetter, Material &theMaterial, Vector3d &p0, Vector3d &p1, Vector3d &p2, Vector3d &p3, Vector3d &p4);

  double calculateVolume();

private:
  int cellIndex;
  char cellLetter;
  Material theMaterial;
  Vector3d p0, p1, p2, p3, p4, p5;
};
class Hexahedron : public Cell
{
public:
  Hexahedron();
  ~Hexahedron();

  Hexahedron(int &cellIndex, char &cellLetter, Material &theMaterial,
             Vector3d &p0, Vector3d &p1, Vector3d &p2, Vector3d &p3,
             Vector3d &p4, Vector3d &p5, Vector3d &p6, Vector3d &p7);

  double calculateVolume();
  float customFunc();

private:
  int cellIndex;
  char cellLetter;
  Material theMaterial;
  Vector3d p0, p1, p2, p3, p4, p5, p6, p7;
};

class Model
{

public:
  Model();
  Model(string &filePath); //model constructor - reads files and declares objects
  ~Model();//Model Destructor

  int readFile(string &filePath); //funtion for reading from file - pass string of file name/path as argument

  int saveToFile(string &newFilePath);

  //Once we know how many of each letter we have, we go about creating them
  int declareMaterials(string &filePath);
  int declareVectors(string &filePath);
  int declareCells(string &filePath);


  //Accessor functions
  vector<Material> get_listOfMaterials();
  vector<Vector3d> get_listOfVectors();
  vector<shared_ptr<Cell>> get_listOfCells();

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

  vector<shared_ptr<Cell>> listOfCells;
  //Once we have read file and know how many of each object there are, we will need to resize above vector
  int numMaterials = 0, numVectors = 0, numCells = 0;
};


#endif