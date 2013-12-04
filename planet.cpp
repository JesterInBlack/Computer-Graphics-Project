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
  float save_radius, save_r, save_g, save_b, save_a;
  if ( Planet::transparent )
  {
    //set up blending
    glEnable( GL_BLEND );
    glBlendFunc( GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA );

    //randomize size and rgb slightly.
    save_radius = Planet::radius;
    Planet::radius = Planet::radius * (0.995 + rand() % 2000 / 200000.0);
    save_r = Planet::diffuse.r;
    Planet::diffuse.r = Planet::diffuse.r * (0.9 + rand() % 2000 / 10000.0);
    save_g = Planet::diffuse.g;
    Planet::diffuse.g = Planet::diffuse.g * (0.9 + rand() % 2000 / 10000.0);
    save_b = Planet::diffuse.b;
    Planet::diffuse.b = Planet::diffuse.b * (0.9 + rand() % 2000 / 10000.0);
    save_a = Planet::diffuse.a;
    Planet::diffuse.a = Planet::diffuse.a * (0.9 + rand() % 2000 / 10000.0);
  }
  else
  {
    //set up culling
    glEnable( GL_CULL_FACE );
    glCullFace( GL_BACK );
  }

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
  GLfloat light_ambient[] = { 0.1, 0.1, 0.1, 1.0 };

  //Light model stuff
  glLightModelfv( GL_LIGHT_MODEL_AMBIENT, light_ambient ); // Global ambient light.
  glLightModeli( GL_LIGHT_MODEL_LOCAL_VIEWER, 1 ); // Enable local viewpoint

  glutSolidSphere( Planet::radius, 50, 50 );
  //glutWireSphere( Planet::radius, 50, 50 ); //DEBUG

  glDisable( GL_CULL_FACE ); //disable culling
  glDisable( GL_BLEND ); //disable blending

  if ( Planet::transparent )
  {
    Planet::radius = save_radius;
    Planet::diffuse.r = save_r;
    Planet::diffuse.g = save_g;
    Planet::diffuse.b = save_b;
    Planet::diffuse.a = save_a;
  }
}