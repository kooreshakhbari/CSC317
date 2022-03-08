// Create a bumpy surface by using procedural noise to generate a height (
// displacement in normal direction).
//
// Inputs:
//   is_moon  whether we're looking at the moon or centre planet
//   s  3D position of seed for noise generation
// Returns elevation adjust along normal (values between -0.1 and 0.1 are
//   reasonable.
float bump_height( bool is_moon, vec3 s)
{
  /////////////////////////////////////////////////////////////////////////////
  // Replace with your code 

  if (is_moon) {
    vec3 moon_seed = vec3(2.66, 4.55, 9.11) + s*2.1;
    return improved_perlin_noise(moon_seed);
  }
  else {
    vec3 earth_seed = vec3(5.66, 2.55, 4.11) + s*5.3;
    return improved_perlin_noise(earth_seed);
  }

  /////////////////////////////////////////////////////////////////////////////
}
