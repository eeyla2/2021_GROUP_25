//cell.hpp
#ifndef CELL_HPP
#define CELL_HPP

/** @file
* Header file for cell class
*/

/** Brief description
* Declaration of the cell class
* Uses inheritance, cell is the parent of the classes for the 3 shape types
* Calculations about the cell are also defined
*/

#include <vector>

#include "material.hpp"
#include "vector.hpp"


class Cell
{
public:
    
    Cell();
    // Cell constructor for different Cell variants
    Cell(char &cCellLetter, int &cCellIndex, Material &cTheMaterial, Vector3d &cP0, Vector3d &cP1, Vector3d &cP2, Vector3d &cP3); // tetrahedron

    Cell(char &cCellLetter, int &cCellIndex, Material &cTheMaterial, Vector3d &cP0, Vector3d &cP1, Vector3d &cP2, Vector3d &cP3, Vector3d &cP4); // pyramid

    Cell(char &cCellLetter, int &cCellIndex, Material &cTheMaterial, Vector3d &cP0, Vector3d &cP1, Vector3d &cP2, Vector3d &cP3,
         Vector3d &cP4, Vector3d &cP5, Vector3d &cP6, Vector3d &cP7); // hexahedron

    ~Cell(); // destructor

    int get_cellIndex() const;
    char get_cellLetter() const;
    int get_cellMaterialIndex() const;

    // get functions for all the points
    Vector3d get_cellp0() const;
    Vector3d get_cellp1() const;
    Vector3d get_cellp2() const;
    Vector3d get_cellp3() const;
    Vector3d get_cellp4() const;
    Vector3d get_cellp5() const;
    Vector3d get_cellp6() const;
    Vector3d get_cellp7() const;

    // get the material inside the cell class
    Material get_cellMaterial() const;

    // virtual function allows the correct version of volume and center of mass to be called for each shape
    virtual float calculateVolume();
    virtual Vector3d centerOfMass();

    // weight of the cell calculated
    float weight();

protected:
    int cellIndex;                           
    char cellLetter;                         
    Material theMaterial;                    
    Vector3d p0, p1, p2, p3, p4, p5, p6, p7; // all possible points that could be used in a shape

};

class Tetrahedron : public Cell
{
public:
    Tetrahedron();//incase of empty argument

    Tetrahedron(int &tCellIndex, char &tCellLetter, Material &tTheMaterial, Vector3d &tP0, Vector3d &tP1, Vector3d &tP2, Vector3d &tP3); // constructor for tetrahedron vectors is called
    ~Tetrahedron();                                                                                                                      // destructor for tetrahedron vector constructor called

    Tetrahedron(const Tetrahedron &instance); // copying constructor 

    const Tetrahedron &operator=(const Tetrahedron &instance); // assignment operator for Tetrahedron

    float calculateVolume(); // volume of a tetrahedron

    Vector3d centerOfMass(); //center of mass of a tetrahedron

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

    Pyramid(int &pCellIndex, char &pCellLetter, Material &pTheMaterial, Vector3d &pP0, Vector3d &pP1, Vector3d &pP2, Vector3d &pP3, Vector3d &pP4); // constructor for tetrahedron vectors is called
    ~Pyramid();                                                                                                                                     // destructor for pyramid vectors is called

    Pyramid(const Pyramid &instance); // copying constructor applied

    const Pyramid &operator=(const Pyramid &instance); // assignment operator for Pyramid

    float calculateVolume(); // volume of a pyramid

    Vector3d centerOfMass(); // center of mass of a pyramid
    
private:
    int cellIndex;
    char cellLetter;
    Material theMaterial;
    Vector3d p0, p1, p2, p3, p4;
};

class Hexahedron : public Cell
{
public:
    Hexahedron();

    Hexahedron(int &hCellIndex, char &hCellLetter, Material &tTheMaterial, Vector3d &hP0, Vector3d &hP1, Vector3d &hP2, Vector3d &hP3, Vector3d &hP4, Vector3d &hP5, Vector3d &hP6, Vector3d &hP7); // vector constructor called

    ~Hexahedron(); // hexahedron destructor applied to the vector constructor

    Hexahedron(const Hexahedron &instance); // copying constructor applied

    const Hexahedron &operator=(const Hexahedron &instance); // assignment operator for Pyramid
    
    float calculateVolume();
    Vector3d centerOfMass(); // center of mass of a hexahedron

private:
    int cellIndex;
    char cellLetter;
    Material theMaterial;
    Vector3d p0, p1, p2, p3, p4, p5, p6, p7;

};

#endif