#include<cstdlib>
#include <GL/glut.h>

#include "Game.hpp"

static void on_keyboard(unsigned char key, int x, int y);
static void on_reshape(int width, int height);
static void on_display(void);
static void on_timer(int value);
static void on_passive_mouse_motion(int x, int y);
static void on_keyboard_up(unsigned char key, int x, int y);

vd::Game game;


int main(int argc, char **argv)
{
    
    game.window().set_width(1024);
    game.window().set_height(1024);

    // Initialize glut
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH | GLUT_DOUBLE);

    // Initialize window
    glutInitWindowSize(game.window().get_width(), game.window().get_height());
    glutInitWindowPosition(100, 100);
    glutCreateWindow(argv[0]);

    // Initialize callback functions
    glutKeyboardFunc(on_keyboard);
    glutReshapeFunc(on_reshape);
    glutDisplayFunc(on_display);
    glutTimerFunc(game.get_msec_timer_update(), on_timer, game.get_timer_id());
    glutPassiveMotionFunc(on_passive_mouse_motion);
    
    glutSetKeyRepeat(GLUT_KEY_REPEAT_OFF);
    glutKeyboardUpFunc(on_keyboard_up);
    glEnable(GL_DEPTH_TEST);

    glClearColor(0, 0, 0, 0);

    game.init();

    glutMainLoop();

    return 0;
}


static void on_keyboard_up(unsigned char key, int x, int y)
{
    y = game.window().get_height() - y;
    game.keyboard().key_up(key, x, y);
}
static void on_timer(int value)
{
    game.update();
    glutPostRedisplay();
    glutTimerFunc(game.get_msec_timer_update(), on_timer, game.get_timer_id());
    
}

static void on_keyboard(unsigned char key, int x, int y)
{
    switch (key) {
    case 27:
        exit(0);
        break;
    default:
        y = game.window().get_height() - y;
        game.keyboard().key_down(key, x, y);
    }
}

static void on_passive_mouse_motion(int x, int y)
{
    y = game.window().get_height() - y;
    game.passive_mouse().on_move(x,y);
}

static void on_reshape(int width, int height)
{
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(30, (float) width / height, 1, 100);
    game.window().set_height(height);
    game.window().set_width(width);
}

static void on_display(void)
{
    game.draw();
}
