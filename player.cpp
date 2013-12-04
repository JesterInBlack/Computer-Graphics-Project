//Player implementation

#include "player.h"


void Player::draw()
{
  //DO STUFF
  glTranslatef(Player::position.x, Player::position.y, Player::position.z );

  //set up culling
  glEnable( GL_CULL_FACE );
  glCullFace( GL_BACK );

  //SHADING
  //Material Properties
  GLfloat mat_ambient[] = { 0.0, 0.0, 0.0, 1.0 };
  GLfloat mat_diffuse[] = { 0.5, 1.0, 0.0, 1.0 };
  GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
  GLfloat mat_shininess[] = { 0 };
  GLfloat mat_emission[] = { 0.25, 0.5, 0.0, 1.0 };

  //Material calls
  glMaterialfv( GL_FRONT, GL_AMBIENT, mat_ambient );
  glMaterialfv( GL_FRONT, GL_DIFFUSE, mat_diffuse );
  glMaterialfv( GL_FRONT, GL_SPECULAR, mat_specular);
  glMaterialfv( GL_FRONT, GL_SHININESS, mat_shininess );
  glMaterialfv( GL_FRONT, GL_EMISSION, mat_emission );

  //Light Properties
  GLfloat light_ambient[] = { 0.0, 0.0, 0.0, 1.0 };

  //Light model stuff
  glLightModelfv( GL_LIGHT_MODEL_AMBIENT, light_ambient ); // Global ambient light.
  glLightModeli( GL_LIGHT_MODEL_LOCAL_VIEWER, 1 ); // Enable local viewpoint

  glutSolidSphere( 0.1, 10, 10 );

  glDisable( GL_CULL_FACE ); //disable culling
}


void Player::update()
{
  //DO STUFF
  return;
}
