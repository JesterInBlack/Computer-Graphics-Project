//Planet Implementation

#include "planet.h"

void Planet::update()
{
  Planet::orbit_angle += Planet::orbit_omega;
  Planet::x = Planet::orbit_x + Planet::orbit_r * cos( Planet::orbit_angle );
  Planet::y = Planet::orbit_y + Planet::orbit_r * sin( Planet::orbit_angle );
}

void Planet::draw()
{
  //use radius and GL junk to draw the planet with texture and diffuse + specular (phong?) lighting.
  //GLUquadric* q = gluNewQuadric();
  //gluQuadricOrientation( q, GLU_OUTSIDE ); //modifies q

  //gluSphere( gluNewQuadric(), Planet::radius, 100, 100 );

  //Enable culling.
  glEnable( GL_CULL_FACE );
  glCullFace( GL_FRONT );

  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  glTranslatef( Planet::x, Planet::y, Planet::z );

  //SHADING
  //Light and material properties
  GLfloat mat_ambient[] = { 0.0, 0.0, 0.5, 1.0 }; //set this to planet colors?
  GLfloat mat_diffuse[] = { 0.5, 0.5, 0.5, 1.0 };
  GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
  GLfloat mat_shininess[] = { 50.0 };
  GLfloat mat_emission[] = { 0.3, 0.3, 0.3, 1.0 };
  GLfloat light_ambient[] = { 0.5, 0.5, 0.5, 1.0 };
  GLfloat light_position[] = { Planet::x, Planet::y, Planet::z, 1.0 };

  //set up GL_LIGHT0
  glLightfv( GL_LIGHT0, GL_POSITION, light_position );
  glLightfv( GL_LIGHT0, GL_AMBIENT, light_ambient );

  //Light model stuff
  glLightModelfv( GL_LIGHT_MODEL_AMBIENT, light_ambient ); // Global ambient light.
  glLightModeli( GL_LIGHT_MODEL_LOCAL_VIEWER, 1 ); // Enable local viewpoint

  //Set up material properties
  glMaterialfv( GL_FRONT, GL_AMBIENT, mat_ambient );
  glMaterialfv( GL_FRONT, GL_DIFFUSE, mat_diffuse );
  glMaterialfv( GL_FRONT, GL_SPECULAR, mat_specular);
  glMaterialfv( GL_FRONT, GL_SHININESS, mat_shininess );
  glMaterialfv( GL_FRONT, GL_EMISSION, mat_emission );

  glEnable( GL_LIGHT0 );
  glEnable( GL_LIGHTING );   //enable lighting

  glutSolidSphere( Planet::radius, 100, 100 );

  glDisable( GL_LIGHT0 );    //turn off light 0
  glDisable( GL_LIGHTING );  //disable lighting
  glDisable( GL_CULL_FACE ); //disable culling
}
