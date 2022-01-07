//Cell header - Laith
#ifndef CELL_HPP
#define CELL_HPP

#include <Vector>

#include "material.hpp"
#include "vector.hpp"



//cell class
class Cell
{
public:
    // Cell constructor for different Cell variants
    Cell();

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

    // virtual function allows the correct version of volume and center of massto be called for each shape
    virtual double volume();
    virtual double centerOfMass();

    // weight of the cell calculated
    double weight();

protected:
    int cellIndex;                           // the cell Index
    char cellLetter;                         // the cell letter
    Material theMaterial;                    // the material
    Vector3d p0, p1, p2, p3, p4, p5, p6, p7; // all possible points that could be used in a shape

    // the weight function that is currently in the Cell classes will actually be inherited
};

class Tetrahedron : public Cell
{
public:
    Tetrahedron();//incase of empty argument

    Tetrahedron(int &tCellIndex, char &tCellLetter, Material &tTheMaterial, Vector3d &tP0, Vector3d &tP1, Vector3d &tP2, Vector3d &tP3); // constructor for tetrahedron vectors is called
    ~Tetrahedron();                                                                                                                      // destructor for tetrahedron vector constructor called

    Tetrahedron(const Tetrahedron &instance); // copying constructor applied (Note: this is the same function
    // as the normal constructor but with an instance argument where a whole instance is supplied)

    const Tetrahedron &operator=(const Tetrahedron &instance); // assignment operator for Tetrahedron

    // operators for subtraction, addition, dotmulitplication, cross multiplication
    // all have to be applied here

    double volume(Vector3d &p0, Vector3d &p1, Vector3d &p2, Vector3d &p3); // volume of a tetrahedron

    Vector3d centerOfMass(Vector3d &p0, Vector3d &p1, Vector3d &p2, Vector3d &p3); //center of mass of a tetrahedron

    // private variables and functions of the tetrahedron class
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

    // operators for subtraction, addition, dotmulitplication, cross multiplication
    // all have to be applied here
    double volume(Vector3d &p0, Vector3d &p1, Vector3d &p2, Vector3d &p3, Vector3d &p4); // volume of a pyramid

    Vector3d centerOfMass(Vector3d &p0, Vector3d &p1, Vector3d &p2, Vector3d &p3, Vector3d &p4); // center of mass of a pyramid
    
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

    // operators for subtraction, addition, dotmulitplication, cross multiplication
    // all have to be applied here
    double volume(Vector3d &p0, Vector3d &p1, Vector3d &p2, Vector3d &p3, Vector3d &p4, Vector3d &p5, Vector3d &p6, Vector3d &p7); // volume of a Hexahedron

    Vector3d centerOfMass(Vector3d &p0, Vector3d &p1, Vector3d &p2, Vector3d &p3, Vector3d &p4, Vector3d &p5, Vector3d &p6, Vector3d &p7); // center of mass of a hexahedron

private:
    int cellIndex;
    char cellLetter;
    Material theMaterial;
    Vector3d p0, p1, p2, p3, p4, p5, p6, p7;

};


#endif