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
  void draw();
private:
};