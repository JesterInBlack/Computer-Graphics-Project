//Planet header

#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <math.h>
//#include "point3.h"
#include "colour.h"
#include "orbit.h"

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
    orbit = Orbit( 0.0, 0.0, 0.0, 5.0, 0.0, 0.0314 );
    ambient = Colour( 0.0, 0.0, 0.0, 1.0 );
    diffuse = Colour( 0.5, 0.5, 1.0, 1.0 );
    specular = Colour( 1.0, 1.0, 1.0, 1.0 );
    emissive = Colour( 0.0, 0.0, 0.0, 1.0 );
    shininess = 50;
  }; //constructor

  Planet( float p_x, float p_y, float p_z, float p_r, float p_mass ) 
  { 
    x = p_x; y = p_y; z = p_z; 
    radius = p_r; 
    mass = p_mass; 
    orbit = Orbit( 0.0, 0.0, 0.0, 5.0, 0.0, 0.0314 );
    ambient = Colour( 0.0, 0.0, 0.0, 1.0 );
    diffuse = Colour( 0.5, 0.5, 1.0, 1.0 );
    specular = Colour( 1.0, 1.0, 1.0, 1.0 );
    emissive = Colour( 0.0, 0.0, 0.0, 1.0 );
    shininess = 50;
  };
  float mass; //in kg?
  float radius; //in "units"
  float x, y, z; //center point: f( orbit )
  //Orbit
  Orbit orbit;
  //Colors
  Colour ambient;  //ambient color
  Colour diffuse;  //diffuse color
  Colour specular; //specular highlight color
  Colour emissive; //emissive color
  int shininess;   //0-128 shininess exponent for spectral lighting
  //---------------------
  //Function prototypes
  //---------------------
  void draw();
  void update();
private:
};