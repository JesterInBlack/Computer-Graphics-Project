//Planet Implementation

#include "planet.h"

void Planet::draw()
{
  //use radius and GL junk to draw the planet with texture and diffuse + specular (phong?) lighting.
  //GLUquadric* q = gluNewQuadric();
  //gluQuadricOrientation( q, GLU_OUTSIDE ); //modifies q

  //gluSphere( gluNewQuadric(), Planet::radius, 100, 100 );

  glLoadIdentity();
  glTranslatef( Planet::x, Planet::y, Planet::z );

  //SHADING
  GLfloat mat_ambient[] = {0.5, 0.5, 0.5, 1.0};
  GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
  GLfloat mat_shininess[] = { 50.0 };
  GLfloat light_position[] = { 1.0, 1.0, 1.0, 0.0 };
  glClearColor (0.0, 0.0, 0.0, 0.0);
  glShadeModel (GL_SMOOTH);

  glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient );
  glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
  glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);

  //set up GL_LIGHT0
  glLightfv(GL_LIGHT0, GL_POSITION, light_position);
  glLightfv(GL_LIGHT0, GL_AMBIENT, mat_ambient);

  glEnable(GL_LIGHTING);
  glEnable(GL_LIGHT0);
  glEnable(GL_DEPTH_TEST);


  glutSolidSphere( Planet::radius, 100, 100 );
}
