//Player Header

#include <iostream>
#include <fstream>
#include <stdlib.h>
#include "point3.h"

#ifdef __APPLE__
#  include <GLUT/glut.h>
#  include <OpenGL/glext.h>
#else
#  include <GL/glut.h>
#endif

class Player
{
public:
  Player() { position = Point3(); }; //constructor
  Point3 position;
  bool grounded;
  void draw();
  void set_position(float new_x, float new_y, float new_z);
private:
};