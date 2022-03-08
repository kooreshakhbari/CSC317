// Set the pixel color using Blinn-Phong shading (e.g., with constant blue and
// gray material color) with a bumpy texture.
// 
// Uniforms:
uniform mat4 view;
uniform mat4 proj;
uniform float animation_seconds;
uniform bool is_moon;
// Inputs:
//                     linearly interpolated from tessellation evaluation shader
//                     output
in vec3 sphere_fs_in;
in vec3 normal_fs_in;
in vec4 pos_fs_in; 
in vec4 view_pos_fs_in; 
// Outputs:
//               rgb color of this pixel
out vec3 color;
// expects: model, blinn_phong, bump_height, bump_position,
// improved_perlin_noise, tangent
void main()
{
  /////////////////////////////////////////////////////////////////////////////
  // Replace with your code 
  float light_theta = ((mod(animation_seconds, 4.0)*M_PI)/2);

  mat4 light_trans = mat4(
    cos(light_theta),0,-sin(light_theta),0,
    0,1,0,0,
    sin(light_theta),0,cos(light_theta),0,
    0,0,0,1);
  
  
  float noise_moon = improved_perlin_noise(68465 * sphere_fs_in);
  float noise_earth = improved_perlin_noise(3 * sphere_fs_in);

  float epsilion = 0.0001;

  // Tangent
  vec3 T, B;
  tangent(sphere_fs_in, T, B);

  // Bump
  vec3 bump_pos = bump_position(is_moon, sphere_fs_in);
  vec3 bump_pos_T = (bump_position(is_moon, sphere_fs_in + T*epsilion) - bump_pos)/epsilion;
  vec3 bump_pos_B = (bump_position(is_moon, sphere_fs_in + B*epsilion) - bump_pos)/epsilion;

  // From lab readme calculate perceieved normal
  vec3 perceieved_normal;
  perceieved_normal = normalize(cross(bump_pos_T, bump_pos_B));

  // Check direction
  if (dot(sphere_fs_in, perceieved_normal) < 0)
    perceieved_normal *= -1;


  vec3 n = perceieved_normal;
  vec3 v = -normalize(view_pos_fs_in.xyz);
  vec3 l = normalize((view * light_trans * vec4(3.0, 3.0, 3.0, 0))).xyz;
  

// Don't put noise for kd. It will look much better.
  if (is_moon) {
    vec3 ka = vec3(1.8, 1.9, 2.1);
    vec3 ks = vec3(3.0, 5.0, 2.0) * noise_moon;
    vec3 kd = vec3(0.3, 0.3, 0.3);
    float p = 1500;
    color = blinn_phong(ka, kd, ks, p, n, v, l);
  } else{
    vec3 ka = vec3(0.5, 0.3, 0.8);
    vec3 ks = vec3(0.8, 0.6, 0.9) * noise_earth;
    vec3 kd = vec3(0.15, 0.3, 0.8);
    float p = 600;
    color = blinn_phong(ka, kd, ks, p, n, v, l);
  }
  /////////////////////////////////////////////////////////////////////////////
}
