//Planet header

#include <iostream>
#include <fstream>
#include <stdlib.h>
//#include "point3.h"

#ifdef __APPLE__
#  include <GLUT/glut.h>
#  include <OpenGL/glext.h>
#else
#  include <GL/glut.h>
#endif

class Planet
{
public:
  Planet() { radius = 1.0; mass = 100; x = 0.0; y = 0.0; z = -1.0; }; //constructor
  Planet( float p_x, float p_y, float p_z, float p_r, float p_mass ) { x = p_x; y = p_y; z = p_z; radius = p_r; mass = p_mass; };
  float mass; //in kg?
  float radius; //in "units"
  float x, y, z;
  //Point3 center;
  void draw();
private:
};