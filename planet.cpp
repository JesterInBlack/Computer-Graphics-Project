//Planet Implementation

#include "planet.h"

void Planet::update()
{
  Planet::orbit.update();
  Planet::x = Planet::orbit.x + Planet::orbit.r * cos( Planet::orbit.angle );
  Planet::y = Planet::orbit.y + Planet::orbit.r * sin( Planet::orbit.angle );
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

  //glMatrixMode(GL_MODELVIEW);
  //glLoadIdentity();
  glTranslatef( Planet::x, Planet::y, Planet::z );

  //SHADING
  //Material Properties
  GLfloat mat_ambient[] = { Planet::ambient.r, Planet::ambient.g, Planet::ambient.b, Planet::ambient.a }; //set this to planet colors?
  GLfloat mat_diffuse[] = { Planet::diffuse.r, Planet::diffuse.g, Planet::diffuse.b, Planet::diffuse.a };
  GLfloat mat_specular[] = { Planet::specular.r, Planet::specular.g, Planet::specular.b, Planet::specular.a };
  GLfloat mat_shininess[] = { Planet::shininess };
  GLfloat mat_emission[] = { Planet::emissive.r, Planet::emissive.g, Planet::emissive.b, Planet::emissive.a };
  //Material calls
  glMaterialfv( GL_FRONT, GL_AMBIENT, mat_ambient );
  glMaterialfv( GL_FRONT, GL_DIFFUSE, mat_diffuse );
  glMaterialfv( GL_FRONT, GL_SPECULAR, mat_specular);
  glMaterialfv( GL_FRONT, GL_SHININESS, mat_shininess );
  glMaterialfv( GL_FRONT, GL_EMISSION, mat_emission );

  //Light Properties
  GLfloat light_ambient[] = { 0.5, 0.5, 0.5, 1.0 };
  GLfloat light_position[] = { Planet::x, Planet::y, Planet::z, 1.0 };

  //set up GL_LIGHT0
  glLightfv( GL_LIGHT0, GL_POSITION, light_position );
  glLightfv( GL_LIGHT0, GL_AMBIENT, light_ambient );

  //Light model stuff
  glLightModelfv( GL_LIGHT_MODEL_AMBIENT, light_ambient ); // Global ambient light.
  glLightModeli( GL_LIGHT_MODEL_LOCAL_VIEWER, 1 ); // Enable local viewpoint

  //Turn on the lights (after all the params have been set)
  glEnable( GL_LIGHT0 );
  glEnable( GL_LIGHTING );   //enable lighting

  glutSolidSphere( Planet::radius, 25, 25 );

  glDisable( GL_LIGHT0 );    //turn off light 0
  glDisable( GL_LIGHTING );  //disable lighting
  glDisable( GL_CULL_FACE ); //disable culling
}