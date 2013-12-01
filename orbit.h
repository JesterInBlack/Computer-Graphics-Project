//orbit class
class Orbit
{
public:
  //constructors
  Orbit() //default constructor: non-moving orbit at origin
  {
    x = 0.0;
    y = 0.0;
    z = 0.0;

    r = 0.0;
    angle = 0.0;
    omega = 0.0;
  };

  Orbit( float p_x, float p_y, float p_z, float p_r, float p_angle, float p_omega ) //explicit constructor
  {
    x = p_x;
    y = p_y;
    z = p_z;

    r = p_r;
    angle = p_angle;
    omega = p_omega;
  }; 

  //Data
  float x, y, z; //center point
  float r;       //radius of orbit
  float angle;   //position in the orbit
  float omega;   //angular velocity

  //----------
  //functions
  //----------
  void update()
  {
    angle += omega;
    //keep data size manageable
    if ( angle > 6.2831853 )
    {
      angle -= 6.2831853;
    }
  };
private:
};