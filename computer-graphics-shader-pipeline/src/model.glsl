// Construct the model transformation matrix. The moon should orbit around the
// origin. The other object should stay still.
//
// Inputs:
//   is_moon  whether we're considering the moon
//   time  seconds on animation clock
// Returns affine model transformation as 4x4 matrix
//
// expects: identity, rotate_about_y, translate, PI
mat4 model(bool is_moon, float time)
{
  /////////////////////////////////////////////////////////////////////////////
  // Replace with your code 
  // The 4 second, 2 translation, and scale came from model view projection comments
  float theta = ((mod(time, 4.0)*M_PI)/2);
  if (is_moon) {
    return rotate_about_y(theta) * translate(vec3(2, 0, 0)) * uniform_scale(0.3);
  }
  else {
    return identity();
  }
    
  /////////////////////////////////////////////////////////////////////////////
}
