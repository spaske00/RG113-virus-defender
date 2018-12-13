

#if !defined(MouseAction_HPP)
#define MouseAction_HPP

#include "Cursor.hpp"
namespace vd {
class MouseAction {
    public:
        MouseAction(Cursor& cursor) : m_cursor(cursor) {}
        void on_left_click_down();
        void on_right_click_down();
    private:
        Cursor& m_cursor;
};
}

#endif // MouseAction_HPP
