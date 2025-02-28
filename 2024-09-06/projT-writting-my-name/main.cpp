/*
 * Escrevendo meu nome
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

    glMatrixMode(GL_PROJECTION); // Define a matriz de transformação da camera para receber um valor.

    glLoadIdentity(); // Seta a matriz identidade para a matriz de trasformação da câmera.

    gluOrtho2D(0, 85, 0, 18); // Espaço de enquadramento da aplicacao (Esquerda, Direita, Base, Topo)

    glMatrixMode(GL_MODELVIEW); // Define a matriz de trasformação dos modelos que compõe a cena.

    glLoadIdentity(); // Seta a matriz identidade para a matriz de trasformação da câmera.

    // glTranslatef(0.0f, -10.0f, 0.0f); //Nesse caso, posso usar essa linha para mudar a posição dos elementos do meu nome que foi escrito na tela.


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
int main(int argc, char* argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode( GLUT_SINGLE | GLUT_RGB );
    glutInitWindowSize(800,600);
    glutCreateWindow("Escrevendo meu nome");
    glutDisplayFunc(desenha);
    glClearColor( 0, 0, 1, 0);
    glutMainLoop();
    return 0;
}

