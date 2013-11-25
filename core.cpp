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

void draw()
{
  //Draw the scene
  glClear( GL_COLOR_BUFFER_BIT ); //clear the buffer

  glLoadIdentity(); //reset orientation

  //For each object
  //glBegin(), glEnd()
  //glBegin();

  for ( int i = 0; i < 10; i++ )
  {
    planets[i].draw();
  }

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