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
	position.x = 17;
    velocity = Point3();
	acceleration = Point3();
	force = Point3();

	for (int i = 0; i < 20; i++)
	{
		distances[i] = 0;
	}
	//velocity_x = 0;
	//velocity_y = 0;
  }; //constructor

  Point3 position;
  Point3 velocity;
  Point3 acceleration;
  Point3 force;

  bool grounded;
  void draw();
  float distances[20];
  int closest_planet;
  void update(float deltaX, float deltaY);
  //float velocity_x;
  //float velocity_y;

private:
};