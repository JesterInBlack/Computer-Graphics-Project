//Planet header

#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <math.h>
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
  Planet() 
  { 
    radius = 1.0; 
    mass = 100; 
    x = 0.0; y = 0.0; z = -1.0; 
    orbit_x = 0.0; 
    orbit_y = 0.0; 
    orbit_z = -5.0; 
    orbit_r = 5.0; 
    orbit_angle = 0.0; 
    orbit_omega = 0.0314;
  }; //constructor

  Planet( float p_x, float p_y, float p_z, float p_r, float p_mass ) 
  { 
    x = p_x; y = p_y; z = p_z; 
    radius = p_r; 
    mass = p_mass; 
    orbit_x = 0.0; 
    orbit_y = 0.0; 
    orbit_z = -5.0; 
    orbit_r = 5.0; 
    orbit_angle = 0.0; 
    orbit_omega = 0.0314;
  };
  float mass; //in kg?
  float radius; //in "units"
  float x, y, z;
  //Orbit
  float orbit_x, orbit_y, orbit_z; //center point x, y, z
  float orbit_r; //orbit radius
  float orbit_angle, orbit_omega;  //orbit angular speed
  //Point3 center;
  void draw();
  void update();
private:
};