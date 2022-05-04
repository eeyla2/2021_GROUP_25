// cell.hpp
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
#include <cmath>

#include "material.hpp"
#include "vector.hpp"

class Cell
{
public:
    /** @brief Blank constructor for creating a new empty Cell class
     *
     */
    Cell();

    /** @brief Cell constructor when object is a tetrahedron
     *
     *  Constructor for storing letter, Index and coordintaes if its a tetrahedron accoridngly to set up a
     *  a Cell Class
     *  @param cCellLetter the letter describing the cell type
     *  @param cCellIndex cell index
     *  @param cTheMaterial the material the cell is amde out of
     *  @param cP0 the vector for p0
     *  @param cP1 the vector for p1
     *  @param cP2 the vector for p2
     *  @param cP3 the vector for p3
     */
    Cell(char &cCellLetter, int &cCellIndex, Material &cTheMaterial, Vector3d &cP0, Vector3d &cP1, Vector3d &cP2, Vector3d &cP3); // tetrahedron

    /** @brief Cell constructor when object is a pyramid
     *
     *  Constructor for storing letter, Index and coordintaes if its a pyramid accoridngly to set up a
     *  a Cell Class
     */
    Cell(char &cCellLetter, int &cCellIndex, Material &cTheMaterial, Vector3d &cP0, Vector3d &cP1, Vector3d &cP2, Vector3d &cP3, Vector3d &cP4); // pyramid


    /** @brief Cell constructor when object is a hexahedron
     *
     *  Constructor for storing letter, Index and coordintaes if its a Hexahedron accoridngly to set up a
     *  a Cell Class
     */
    Cell(char &cCellLetter, int &cCellIndex, Material &cTheMaterial, Vector3d &cP0, Vector3d &cP1, Vector3d &cP2, Vector3d &cP3,
         Vector3d &cP4, Vector3d &cP5, Vector3d &cP6, Vector3d &cP7); // hexahedron


    /** @brief Destructor for Cell class
     */
    ~Cell();

    /** @brief Cell index accessor function
     *
     * Accessor which gets the value stored in the private variable "cellIndex" without affecting its value
     *
     *  @return the cell
     */
    int get_cellIndex() const;


    /** @brief Cell letter accessor function
     *
     * Accessor which gets the value stored in the private variable "cellLetter" wthout affecting its value
     *
     *  @return the cell
     */
    char get_cellLetter() const;

   
    /** @brief Cell material index accessor function
     *
     *Accessor which gets the value stored in the private variable "MaterialIndex" wthout affecting its value
     *
     *  @return the cell
     */
    int get_cellMaterialIndex() const;


    /** @brief Cell material index accessor function
     *
     * Accessor which gets the value stored in the private variable "p0" wthout affecting its value
     *
     *  @return the cell
     */
    Vector3d get_cellp0() const;

    /** Accessor which gets the value stored in the private variable "p1" wthout affecting its value
     */
    Vector3d get_cellp1() const;

    /** Accessor which gets the value stored in the private variable "p2" wthout affecting its value
     */
    Vector3d get_cellp2() const;

    /** Accessor which gets the value stored in the private variable "p3" wthout affecting its value
     */
    Vector3d get_cellp3() const;

    /** Accessor which gets the value stored in the private variable "p4" wthout affecting its value
     */
    Vector3d get_cellp4() const;

    /** Accessor which gets the value stored in the private variable "p5" wthout affecting its value
     */
    Vector3d get_cellp5() const;

    /** Accessor which gets the value stored in the private variable "p6" wthout affecting its value
     */
    Vector3d get_cellp6() const;

    /** Accessor which gets the value stored in the private variable "p7" wthout affecting its value
     */
    Vector3d get_cellp7() const;


    /** @brief Accessor of the cell's material
     *
     * Accessor which gets the value stored in the private class "theMaterial" wthout affecting its value

     *  @return the instance of the cell's material
     */
    Material get_cellMaterial() const;


    /** @brief Function to calculate volume of cell
     *
     *     /** virtual function which allows the correct version of volume to be called for each shape
     * when inherited and kept empty as it depends on each shapes method of calculation
     *
     *  @param
     *  @return the calcualted volume of the cell
     */
    virtual float calculateVolume();


    /** @brief Centre of mass function
     *
     * virtual function which allows the correct version of center of mass to be called for each shape
     * then inherited and kept empty as it depends on each shapes method of calculation
     *
     *  @param
     *  @return vector point of calcualted centre of mass 
     */
    virtual Vector3d centerOfMass();


    /** @brief function which calculates the weight for each shape using its density and volume
     *
     *  @return the cell's weight
     */
    float weight();

protected:
    int cellIndex;                           /*!< an integer cellIndex that stores the index for each cell */
    char cellLetter;                         /*!< a char cellLetter that stores the letter for each cell*/
    Material theMaterial;                    /*!< a Material Class theMaterial that stores the information about the material for each cell */
    Vector3d p0, p1, p2, p3, p4, p5, p6, p7; /*!< a group of Vector3d p0,p1,p2,p3,p4,p5,p6,p7 that stores all possible points of a shape for each cell*/
};

/** Brief description
 * Declaration of the tetrahedron class
 * Uses inheritance, tetrahedron is one of three child classes inheriting from the parent cell class
 * Calculations and properties for any tetrahedron shape is done in this class
 */
class Tetrahedron : public Cell
{
public:
    /**
     * Blank constructor for creating a new empty Tetraheron class
     */
    Tetrahedron();

    /**
     *  Constructor for storing letter, Index and coordinates if its a tetrahedron accoridngly to set up a
     *  a tetrahedon Class inherited from the cell constructor made for tetrahedron
     */
    Tetrahedron(int &tCellIndex, char &tCellLetter, Material &tTheMaterial, Vector3d &tP0, Vector3d &tP1, Vector3d &tP2, Vector3d &tP3);

    /** Destructor for Tetrahedron class applied to the vector constructor
     */
    ~Tetrahedron();

    /** Copy Constructor which creates a copy of the Tetrahedron "instance"
     */
    Tetrahedron(const Tetrahedron &instance);

    /** Assignment Operator which assigns the values of the variables of the Tetrahedron "instance"
     * to the tetrahedron class on the right hand side of the operand
     */
    const Tetrahedron &operator=(const Tetrahedron &instance);

    /** function that calculates volume of a tetrahedron
     */
    float calculateVolume();

    /** function that calculates center of mass of a tetrahedron
     */
    Vector3d centerOfMass();

private:
    int cellIndex;           /*!< an integer cellIndex that stores the index for each tetrahedron inherited from class cell()*/
    char cellLetter;         /*!< a char cellLetter that stores the letter for each shape tetrahedron from class cell()*/
    Material theMaterial;    /*!< a Material Class the Material that stores the information about the material for each tetrahedron inherited from class cell()*/
    Vector3d p0, p1, p2, p3; /*!< a group of Vector3d p0,p1,p2,p3 that stores the points of a tetrahedron for each cell*/
};

/** Brief description
 * Declaration of the Pyramid class
 * Uses inheritance, Pyramid is one of three child classes inheriting from the parent cell class
 * Calculations and properties for any Pyramid shape is done in this class
 */
class Pyramid : public Cell
{
public:
    /**
     * Blank constructor for creating a new empty Pyramid class
     */
    Pyramid();

    /**
     *  Constructor for storing letter, Index and coordinates if its a Pyramid accoridngly to set up a
     *  a Pyramid Class inherited from the cell constructor made for Pyramid
     */
    Pyramid(int &pCellIndex, char &pCellLetter, Material &pTheMaterial, Vector3d &pP0, Vector3d &pP1, Vector3d &pP2, Vector3d &pP3, Vector3d &pP4);

    /** Destructor for Pyramid class applied to the vector constructor
     */
    ~Pyramid();

    /** Copy Constructor which creates a copy of the Pyramid "instance"
     */
    Pyramid(const Pyramid &instance);

    /** Assignment Operator which assigns the values of the variables of the Pyramid "instance"
     * to the Pyramid class on the right hand side of the operand
     */
    const Pyramid &operator=(const Pyramid &instance);

    /** function that calculates volume of a Pyramid
     */
    float calculateVolume(); // volume of a pyramid

    /** function that calculates volume of a Pyramid
     */
    Vector3d centerOfMass();

private:
    int cellIndex;               /*!< an integer cellIndex that stores the index for each pyramid inherited from class cell()*/
    char cellLetter;             /*!< a char cellLetter that stores the letter for each pyramid inherited from class cell()*/
    Material theMaterial;        /*!< a Material Class the Material that stores the information about the material for each pyramid inherited from class cell()*/
    Vector3d p0, p1, p2, p3, p4; /*!< a group of Vector3d p0,p1,p2,p3,p4 that stores the points of a pyramid for each cell*/
};

/** Brief description
 * Declaration of the Hexahedron class
 * Uses inheritance, Hexahedron is one of three child classes inheriting from the parent cell class
 * Calculations and properties for any hexahedron shape is done in this class
 */
class Hexahedron : public Cell
{
public:
    /**
     * Blank constructor for creating a new empty Hexahedron class
     */
    Hexahedron();

    /**
     *  Constructor for storing letter, Index and coordinates if its a Hexahedron accoridngly to set up a
     *  a Hexahedron Class inherited from the cell constructor made for Hexahedron
     */
    Hexahedron(int &hCellIndex, char &hCellLetter, Material &tTheMaterial, Vector3d &hP0, Vector3d &hP1, Vector3d &hP2, Vector3d &hP3, Vector3d &hP4, Vector3d &hP5, Vector3d &hP6, Vector3d &hP7); // vector constructor called

    /** Destructor for Hexahedron class applied to the vector constructor
     */
    ~Hexahedron();

    /** Copy Constructor which creates a copy of the Hexahedron "instance"
     */
    Hexahedron(const Hexahedron &instance); // copying constructor applied

    /** Assignment Operator which assigns the values of the variables of the Hexahedron "instance"
     * to the Hexahedron class on the right hand side of the operand
     */
    const Hexahedron &operator=(const Hexahedron &instance);

    /** function that calculates volume of a Hexahedron
     */
    float calculateVolume();

    /** function that calculates center of Mass of a Hexahedron
     */
    Vector3d centerOfMass();

private:
    int cellIndex;                           /*!< an integer cellIndex that stores the index for each hexahedron inherited from class cell()*/
    char cellLetter;                         /*!< a char cellLetter that stores the letter for each hexahedron inherited from class cell()*/
    Material theMaterial;                    /*!< a Material Class the Material that stores the information about the material for each hexahedron inherited from class cell()*/
    Vector3d p0, p1, p2, p3, p4, p5, p6, p7; /*!< a group of Vector3d p0,p1,p2,p3,p4,p5,p6,p7 that stores the points of a hexahedron for each cell*/
};

#endif