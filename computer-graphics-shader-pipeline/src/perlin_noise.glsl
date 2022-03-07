// Given a 3d position as a seed, compute a smooth procedural noise
// value: "Perlin Noise", also known as "Gradient noise".
//
// Inputs:
//   st  3D seed
// Returns a smooth value between (-1,1)
//
// expects: random_direction, smooth_step

float interpolate(float n0, float n1, float w) {
  return (n1 - n0) * w + n0;
}

float perlin_noise( vec3 st) 
{
  /////////////////////////////////////////////////////////////////////////////
  // Replace with your code 
  // https://en.wikipedia.org/wiki/Perlin_noise

  // Grid cell coords
  int x0 = (int(floor(st.x)));
  int y0 = (int(floor(st.y)));
  int z0 = (int(floor(st.z)));
  int x1 = x0 + 1;
  int y1 = y0 + 1;
  int z1 = z0 + 1;
  
  // Interpolation weights
  float sx = st.x - (float(x0));
  float sy = st.y - (float(y0));
  float sz = st.z - (float(z0));

  // All corners points
  vec3 p0 = vec3(x0, y0, z0);
  vec3 p1 = vec3(x0, y0, z1);
  vec3 p2 = vec3(x0, y1, z0);
  vec3 p3 = vec3(x0, y1, z1);
  vec3 p4 = vec3(x1, y0, z0);
  vec3 p5 = vec3(x1, y0, z1);
  vec3 p6 = vec3(x1, y1, z0);
  vec3 p7 = vec3(x1, y1, z1);

  // dot gradient with distance vectors
  float n0 = dot(random_direction(p0), st - p0);
  float n1 = dot(random_direction(p1), st - p1);
  float n2 = dot(random_direction(p2), st - p2);
  float n3 = dot(random_direction(p3), st - p3);
  float n4 = dot(random_direction(p4), st - p4);
  float n5 = dot(random_direction(p5), st - p5);
  float n6 = dot(random_direction(p6), st - p6);
  float n7 = dot(random_direction(p7), st - p7);

  // Interpolation
  float int1 = interpolate(n0, n1, sx);
  float int2 = interpolate(n2, n3, sx);
  float int3 = interpolate(n4, n5, sx);
  float int4 = interpolate(n6, n7, sx);

  float int5 = interpolate(int1, int2, sy);
  float int6 = interpolate(int3, int4, sy);

  float int7 = interpolate(int5, int6, sz);
  return int7;
  /////////////////////////////////////////////////////////////////////////////
}

