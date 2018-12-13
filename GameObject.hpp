

#if !defined(GAMEOBJECT_HPP)
#define GAMEOBJECT_HPP
#include<iostream>
#include<GL/glut.h>
namespace vd {
class GameObject {
    public:
        GameObject() = default;
        GameObject(GLfloat x, GLfloat y, GLfloat z) : m_xyz{x,y,z} {};
        virtual void update() = 0;
        virtual void draw() = 0;
        virtual ~GameObject() = default;
        virtual void activate() { m_active = true;}
        bool is_active() { return m_active; }
        virtual void deactivate() { m_active = false; }
        GLfloat get_x() const { return m_xyz[0]; }
        GLfloat get_y() const { return m_xyz[1]; }
        GLfloat get_z() const { return m_xyz[2]; }

    protected:
        GLfloat m_xyz[3];
        
    private:
        bool m_active = false;
};

}

#endif // GAMEOBJECT_HPP
