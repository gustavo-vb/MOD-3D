/*
 * TRABALHO PRÁTICO DE MODELAGEM 3D
 * PROFESSOR WILL MACHADO
 * ESCRITO POR: Gustavo Vilas Boas Pereira
 */

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <stdlib.h>

GLfloat escala = 1, rodandoHorario = 0, rodandoAntiHorario = 0, MoveX = 0, MoveY = 0;

void desenha(void)
{
    glClear ( GL_COLOR_BUFFER_BIT);

    glMatrixMode(GL_PROJECTION);

    glLoadIdentity();

    gluOrtho2D(0, 85, 0, 18);

    glScalef(escala, escala, 0);
    glRotatef(rodandoHorario, 0, 0, 1.0);
    glRotatef(rodandoAntiHorario, 0, 0, 1.0);
    glTranslatef(MoveX, MoveY, 0);

    glMatrixMode(GL_MODELVIEW);

    glLoadIdentity();

    //letra G
    glBegin (GL_LINE_STRIP);
        glVertex2f(15,15);
        glVertex2f(10,15);
        glVertex2f(10,5);
        glVertex2f(15,5);
        glVertex2f(15,10);
        glVertex2f(12,10);
    glEnd();

    //letra U
    glBegin (GL_LINE_STRIP);
        glVertex2f(20,15);
        glVertex2f(20,5);
        glVertex2f(25,5);
        glVertex2f(25,15);
    glEnd();

    //letra S
    glBegin (GL_LINE_STRIP);
        glVertex2f(35,15);
        glVertex2f(30,15);
        glVertex2f(30,10);
        glVertex2f(35,10);
        glVertex2f(35,5);
        glVertex2f(30,5);
    glEnd();

    //letra T
    glBegin (GL_LINE_STRIP);
        glVertex2f(45,15);
        glVertex2f(42.5,15);
        glVertex2f(40,15);
        glVertex2f(42.5,15);
        glVertex2f(42.5,5);
    glEnd();

    //letra A
    glBegin (GL_LINE_STRIP);
        glVertex2f(50,5);
        glVertex2f(50,15);
        glVertex2f(55,15);
        glVertex2f(55,5);
        glVertex2f(55,10);
        glVertex2f(50,10);
    glEnd();

    //letra V
    glBegin (GL_LINE_STRIP);
        glVertex2f(60,15);
        glVertex2f(62.5,5);
        glVertex2f(65,15);
    glEnd();

    //letra O
    glBegin (GL_LINE_LOOP);
        glVertex2f(70,15);
        glVertex2f(70,5);
        glVertex2f(75,5);
        glVertex2f(75,15);
    glEnd();

    glFlush();
}

void ouveTecla(unsigned char tecla, GLint x, GLint y)
{
    switch(tecla)
    {
        case '+': escala += 0.5;
                    break;

        case '-': if(escala <= 0.5)
                    break;

                    escala -= 0.5;
                    break;

        case 'e': rodandoHorario -= 3.0;
                    break;

        case 'q': rodandoAntiHorario += 3.0;
                    break;

        case 'w': MoveY++;
                break;

        case 'a': MoveX--;
                break;

        case 's': MoveY--;
                break;

        case 'd': MoveX++;
                break;
    }

    desenha();
}

int main(int argc, char* argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode( GLUT_SINGLE | GLUT_RGB );
    glutInitWindowPosition(800,600);
    glutCreateWindow("Trabalho Modelagem 3D");
    glutKeyboardFunc(ouveTecla);
    glutDisplayFunc(desenha);
    glClearColor( 0.243, 0.557, 0.741, 0);
    glutMainLoop();
    return 0;
}

