// Generate a procedural planet and orbiting moon. Use layers of (improved)
// Perlin noise to generate planetary features such as vegetation, gaseous
// clouds, mountains, valleys, ice caps, rivers, oceans. Don't forget about the
// moon. Use `animation_seconds` in your noise input to create (periodic)
// temporal effects.
//
// Uniforms:
uniform mat4 view;
uniform mat4 proj;
uniform float animation_seconds;
uniform bool is_moon;
// Inputs:
in vec3 sphere_fs_in;
in vec3 normal_fs_in;
in vec4 pos_fs_in; 
in vec4 view_pos_fs_in; 
// Outputs:
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
  
  
  float noise_moon = improved_perlin_noise(24.654 * sphere_fs_in);
  float noise_earth = improved_perlin_noise(3.651 * sphere_fs_in);

  float noise_moon_normal = improved_perlin_noise(5.98 * sphere_fs_in);
  float noise_earth_normal = improved_perlin_noise(9.36 * sphere_fs_in);
  
  float noise_color_moon = improved_perlin_noise(4.6574 * sphere_fs_in);
  float noise_color_earth = improved_perlin_noise(1.9865 * sphere_fs_in);

  float noise_moon_diffuse = improved_perlin_noise(1.68 * sphere_fs_in);
  float noise_earth_diffuse = improved_perlin_noise(1.24 * sphere_fs_in);

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

  // Check normal direction
  if (dot(sphere_fs_in, perceieved_normal) < 0)
    perceieved_normal *= -1;
  
  vec3 v = -normalize(view_pos_fs_in.xyz);
  vec3 l = normalize((view * light_trans * vec4(3.0, 3.0, 3.0, 0))).xyz;
  
  if (is_moon) {
    vec3 ka = vec3(4.8, 5.9, 2.1);
    vec3 ks = vec3(3.0, 5.0, 2.0) * noise_moon;
    vec3 kd = vec3(0.3, 0.5, 0.7) * noise_moon_diffuse;
    vec3 n = perceieved_normal * noise_moon_normal;
    float p = 1500;
    color = blinn_phong(ka, kd, ks, p, n, v, l) * noise_color_moon;
  } else{
    vec3 ka = vec3(0.5, 0.3, 0.8);
    vec3 ks = vec3(0.8, 0.6, 0.9) * noise_earth;
    vec3 kd = vec3(1.4, 2.9, 3.8);
    vec3 n = perceieved_normal * noise_earth_normal;
    float p = 900 * noise_earth;
    color = blinn_phong(ka, kd, ks, p, n, v, l);
  }
  /////////////////////////////////////////////////////////////////////////////
}
