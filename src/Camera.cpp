#include "Camera.hpp"
#include <GL/glut.h>
namespace vd {

// Inicijalizacija kamere
// tako da bude na sredini prostora
Camera::Camera() {
  m_xyz_eye[0] = 10;
  m_xyz_eye[1] = 10;
  m_xyz_eye[2] = m_z_eye;

  m_xyz_position[0] = m_xyz_eye[0] + m_camera_pointing_vector[0];
  m_xyz_position[1] = m_xyz_eye[1] + m_camera_pointing_vector[1];

  m_xyz_position[2] = m_z_position;
}

void Camera::start_moving_north() {
  m_move_direction[0] += MovmentVectors::north[0];
  m_move_direction[1] += MovmentVectors::north[1];
}
void Camera::start_moving_east() {
  m_move_direction[0] += MovmentVectors::east[0];
  m_move_direction[1] += MovmentVectors::east[1];
}
void Camera::start_moving_west() {
  m_move_direction[0] += MovmentVectors::west[0];
  m_move_direction[1] += MovmentVectors::west[1];
}
void Camera::start_moving_south() {
  m_move_direction[0] += MovmentVectors::south[0];
  m_move_direction[1] += MovmentVectors::south[1];
}

void Camera::stop_moving_north() {
  m_move_direction[0] -= MovmentVectors::north[0];
  m_move_direction[1] -= MovmentVectors::north[1];
}
void Camera::stop_moving_east() {
  m_move_direction[0] -= MovmentVectors::east[0];
  m_move_direction[1] -= MovmentVectors::east[1];
}
void Camera::stop_moving_west() {
  m_move_direction[0] -= MovmentVectors::west[0];
  m_move_direction[1] -= MovmentVectors::west[1];
}
void Camera::stop_moving_south() {
  m_move_direction[0] -= MovmentVectors::south[0];
  m_move_direction[1] -= MovmentVectors::south[1];
}

// Poziva se svaki put u glavnoj metodi za crtanje
// kako bi se postavlia kamera
void Camera::setup() {
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  m_xyz_eye[0] += m_move_direction[0];
  m_xyz_eye[1] += m_move_direction[1];

  m_xyz_position[0] += m_move_direction[0];
  m_xyz_position[1] += m_move_direction[1];

  gluLookAt(m_xyz_eye[0], m_xyz_eye[1], m_xyz_eye[2], m_xyz_position[0],
            m_xyz_position[1], m_xyz_position[2], m_xyz_up[0], m_xyz_up[1],
            m_xyz_up[2]);
}

} // namespace vd
