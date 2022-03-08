// Filter an input value to perform an even smoother step. This function should
// be a quintic polynomial with improved_smooth_step(0) = 0,
// improved_smooth_step(1) = 1, and zero first _and_ second derivatives at f=0
// and f=1. "Improving Noise" [Perlin 2002].
//
// Inputs:
//   f  input value
// Returns filtered output value
// g(x)=ax^5+bx^4+cx^3+dx^2+ex+f
// 0 -> 0 = f
// 1 -> a + b + c + d + e + f = 1
// 0' -> e = 0
// 1' = 5a + 4b + 3c + 2d + e = 0
// 0'' -> d = 0
// 1'' -> 20a + 12b + 6c + 2d = 0 
float improved_smooth_step( float f)
{
  /////////////////////////////////////////////////////////////////////////////
  // Replace with your code 
  if (f >= 0 && f <= 1){
    return 6 * pow(f, 5) -15*pow(f, 4) + 10*pow(f, 3);
  }
  else if (f > 1) {
    return 1.0;
  }
  else {
    return 0.0;
  }
  
  /////////////////////////////////////////////////////////////////////////////
}
vec3 improved_smooth_step( vec3 f)
{
  /////////////////////////////////////////////////////////////////////////////
  // Replace with your code 
  vec3 answer = vec3(improved_smooth_step(f.x), improved_smooth_step(f.y), improved_smooth_step(f.z));
  return answer;
  /////////////////////////////////////////////////////////////////////////////
}
