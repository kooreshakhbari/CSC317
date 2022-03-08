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
  
  vec3 n = normalize(normal_fs_in);
  vec3 v = -normalize(view_pos_fs_in.xyz);
  vec3 l = normalize((view * light_trans * vec4(3.0, 3.0, 3.0, 0))).xyz;
  float noise_moon = improved_perlin_noise(43 * bump_position(is_moon, sphere_fs_in));
  float noise_earth = improved_perlin_noise(3 * bump_position(is_moon, sphere_fs_in));
  if (is_moon) {
    vec3 ka = vec3(0.8, 0.4, 0.5);
    vec3 ks = vec3(2.0, 2.0, 2.0) * noise_moon;
    vec3 kd = vec3(0.3, 0.3, 0.3) * noise_moon;
    float p = 1500;
    color = blinn_phong(ka, kd, ks, p, n, v, l);
  } else{
    vec3 ka = vec3(0.5, 0.3, 0.8);
    vec3 ks = vec3(0.8, 0.6, 0.9) * noise_earth;
    vec3 kd = vec3(0.15, 0.3, 0.8) * noise_earth;
    float p = 600;
    color = blinn_phong(ka, kd, ks, p, n, v, l);
  }
  /////////////////////////////////////////////////////////////////////////////
}
