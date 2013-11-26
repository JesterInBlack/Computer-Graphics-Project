//Gabriel Violette + Geo Kersey
//TODO: reference where you stole the code from (gupta loadtextures.cpp)
//Core Game Code

#include <iostream>
#include <fstream>
#include <stdlib.h>
#include "planet.h"
#include "player.h"

#ifdef __APPLE__
#  include <GLUT/glut.h>
#  include <OpenGL/glext.h>
#else
#  include <GL/glut.h>
#endif

using namespace std;

Planet planets[10];
Player noob;

void gameLogic()
{
  //handles game logic
  noob.grounded = false;

  for ( int i = 0; i < 10; i++ )
  {
    if ( sqrt( pow( noob.position.x - planets[i].x, 2 ) + pow( noob.position.y - planets[i].y, 2 ) + pow ( noob.position.z - planets[i].z, 2 ) ) < planets[i].radius )
    {
      noob.grounded = true;
      //set pos to planet pos + r * a unit vector in the direction of the player.
      //later, we'll also want to move the player with the planet.
    }

    //move the planets in their orbits.
    //Orbit should be in the form pt, radius, angular velocity. (keep it planar for simplicity?)
    //rotation speed should be in the form of angular velocity. (keep it planar for simplicity?)

    //Do gravitation, acceleration, velocity, position!
  }
}

void draw()
{
  //Do game logic
  gameLogic();

  //Draw the scene
  glClear( GL_COLOR_BUFFER_BIT ); //clear the buffer

  glLoadIdentity(); //reset orientation

  //For each object
  //glBegin(), glEnd()
  //glBegin();

  //draw all the stars in the background

  //draw the planets
  for ( int i = 0; i < 10; i++ )
  {
    planets[i].draw();
  }

  //draw the player
  noob.draw();

  //glEnd();

  glutSwapBuffers(); //swap buffers: display the drawing.
}

void resize( int width, int height)
{
  //Handles resizing the window
  glViewport( 0, 0, (GLsizei) width, (GLsizei) height);
  glMatrixMode( GL_PROJECTION );
  glLoadIdentity();

  glFrustum( -5.0, 5.0, -5.0, 5.0, 5.0, 100.0 );
  glMatrixMode( GL_MODELVIEW );
  glLoadIdentity();
}

void handleInput( unsigned char key, int x, int y )
{
  //handles ASCII key input
  if ( key == 65 )
  {
    //TODO: A
  }
  if ( key == 32 )
  {
    //TODO: SPACE
    if ( noob.grounded )
    {
      //jump
    }
  }
}

void specialInput( int key, int x, int y )
{
  //handles non-ASCII key input. (use GLUT_KEY_w/e constants)
}

void setup()
{

  //Initialization logic.
  for ( int i = 0; i < 10; i++ )
  {
    planets[i] = Planet( i * 3, 0.0, -5.0, 1.0, 100.0 ); //fill array with objects?
  }
}

//Main routine
int main(int argc, char** argv)
{
  //Initialization
  glutInit( &argc, argv );  //initialize glut
  glutInitDisplayMode( GLUT_DOUBLE | GLUT_RGB ); //Set display mode

  //Set up window
  glutInitWindowPosition( 0, 0 ); //set window's position
  glutInitWindowSize( 500, 500 ); //set window's size
  glutCreateWindow("Title!");

  //setup game stuff
  setup();

  //Setup callbacks
  glutDisplayFunc(draw);
  glutReshapeFunc(resize);
  glutKeyboardFunc(handleInput);
  glutSpecialFunc(specialInput);
  glutMainLoop();

  return 0; 
}