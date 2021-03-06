
#if !defined(STATS_HPP)
#define STATS_HPP
#include <string>

namespace vd {
/*
  Konvertuje u string i ispisuje na ekranu
  trenutno stanje PLASMA, PORTAL_HP, i MANA
  promenljivih
*/
class Stats {

public:
  void update();
  void draw();

private:
  std::string m_plasma_string{10};
  std::string m_mana_string{20};
  std::string m_portal_hp_string{10};
};
} // namespace vd

#endif // STATS_HPP
