#ifndef GAME_HPP
#define GAME_HPP

#include "Camera.hpp"
#include "Cursor.hpp"
#include "GameVariables.hpp"
#include "KeyboardAction.hpp"
#include "Light.hpp"
#include "MouseAction.hpp"
#include "PassiveMouseMotionAction.hpp"
#include "Plane.hpp"
#include "Portal.hpp"
#include "SlowSpell.hpp"
#include "SpellCaster.hpp"
#include "Stats.hpp"
#include "StrongVirus.hpp"
#include "Timer.hpp"
#include "Virus.hpp"
#include "Window.hpp"
#include <GL/glut.h>
#include <vector>
namespace vd {

// Game klasa sadrzi sve objete koji se koriste u igri
class Game {
public:
  Game();
  void init();

  void update();
  void draw();

  Timer &timer() { return m_timer; }
  Window &window() { return m_window; }
  KeyboardAction &keyboard() { return m_keyboard_action; }
  PassiveMouseMotionAction &passive_mouse() {
    return m_passive_mouse_motion_action;
  }
  MouseAction &mouse_action() { return m_mouse_action; }
  bool not_over() { return GameVariables::PORTAL_HP > 0; }

private:
  GridController m_grid_controller;
  Window &m_window{GameVariables::window};
  Camera m_camera;
  SpellCaster m_spell_caster;
  KeyboardAction m_keyboard_action;
  Cursor m_cursor;
  Timer m_timer{20, 1};
  PassiveMouseMotionAction m_passive_mouse_motion_action;
  MouseAction m_mouse_action;
  Stats stats;
  Light m_main_light{GL_LIGHT0};
  Plane m_plane;
};
} // namespace vd

#endif // GAME_HPP
