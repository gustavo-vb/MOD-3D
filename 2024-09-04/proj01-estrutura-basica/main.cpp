/*
 * Estrutura basica freeglut
 * Written by Gustavo Vilas Boas Pereira
 */

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <stdlib.h>

void desenha(void)
{
    glClear ( GL_COLOR_BUFFER_BIT);
    glFlush();
}
int main(int argc, char* argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode( GLUT_SINGLE | GLUT_RGB );
    glutInitWindowSize(800,600);
    glutCreateWindow("Ola Glut");
    glutDisplayFunc(desenha);
    glClearColor( 0, 0, 1, 0);
    glutMainLoop();
    return 0;
}

