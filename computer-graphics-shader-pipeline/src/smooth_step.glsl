// Filter an input value to perform a smooth step. This function should be a
// cubic polynomial with smooth_step(0) = 0, smooth_step(1) = 1, and zero first
// derivatives at f=0 and f=1. 
//
// Inputs:
//   f  input value
// Returns filtered output value
float smooth_step( float f)
{
  /////////////////////////////////////////////////////////////////////////////
  // Replace with your code 

  // Cubic poly is ax^3 + bx^2 +cx + d -> 3x^2 + 2bx + c

  float answer = -2 * pow(f, 3) + 3 * pow(f, 2) + 0 * f + 0;
  return answer;
  /////////////////////////////////////////////////////////////////////////////
}

vec3 smooth_step( vec3 f)
{
  /////////////////////////////////////////////////////////////////////////////
  // Replace with your code 

  float x = smooth_step(f.x);
  float y = smooth_step(f.y);
  float z = smooth_step(f.z);

  vec3 answer = vec3(x, y, z);
  return answer;
  /////////////////////////////////////////////////////////////////////////////
}
