//Model header - Daniel

#ifndef MODEL_HPP
#define MODEL_HPP

//Other classes of library

//Commented for the time being so they don't interfere with my tests
#include "material.hpp"
//#include "vector.hpp"
//#include "cell.hpp"

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






#endif