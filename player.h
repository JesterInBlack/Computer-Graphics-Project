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
  Player()
  { 
	  position = Point3();
	  position.x = 7.0;
    velocity = Point3();
	  acceleration = Point3();

    prev_planet = 1; //default respawn position.
    closest_planet = 1; //default stick.

	  for (int i = 0; i < 31; i++)
	  {
		  distances[i] = 0;
	  }
  }; //constructor

  Point3 position;
  Point3 velocity;
  Point3 acceleration;

  bool grounded;
  float distances[31];
  int closest_planet;  //index of planet you're attached to.
  int prev_planet;     //index of previous planet.

  void draw();
  void update();
private:
};