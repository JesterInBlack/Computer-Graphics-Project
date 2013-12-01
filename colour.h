//colour class
class Colour
{
public:
  Colour() {r = 0.0; g = 0.0; b = 0.0; a = 1.0;}; //default constructor: BLACK
  Colour( float p_r, float p_g, float p_b, float p_a ) //custom color constructor.
  { 
    r = p_r; 
    g = p_g; 
    b = p_b; 
    a = p_a; 
  };
  float r, g, b, a;
private:
};