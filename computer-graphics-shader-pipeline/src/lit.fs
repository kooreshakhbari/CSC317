// Add (hard code) an orbiting (point or directional) light to the scene. Light
// the scene using the Blinn-Phong Lighting Model.
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
// expects: PI, blinn_phong
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

  if (is_moon) {
    vec3 ka = vec3(0.2, 0.2, 0.2);
    vec3 ks = vec3(2.0, 2.0, 2.0);
    vec3 kd = vec3(0.3, 0.3, 0.3);
    float p = 1500;
    color = blinn_phong(ka, kd, ks, p, n, v, l);
  } else{
    vec3 ka = vec3(0.5, 0.3, 0.8);
    vec3 ks = vec3(0.8, 0.6, 0.9);
    vec3 kd = vec3(0.15, 0.3, 0.8);
    float p = 600;
    color = blinn_phong(ka, kd, ks, p, n, v, l);
  }


  
  
  /////////////////////////////////////////////////////////////////////////////
}
