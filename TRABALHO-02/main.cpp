/*
 * SEGUNDO TRABALHO PRÁTICO DE MODELAGEM 3D
 * PROFESSOR WILL MACHADO
 * ESCRITO POR: Gustavo Vilas Boas Pereira
 */

#ifdef __APPLE__
#include <GLUT/freeglut.h>
#else
#include <GL/glut.h>
#endif

#include <stdlib.h>
#include <stdio.h>
#include <cmath>

float alpha = 55;
float beta = 0;
float delta = 1.35;

float bolaX = 0;
float bolaZ = 0.4;
float rodaBola = 0;
float goleiroX = 0;
float direcaoGoleiro = 1;
float velocidadeGoleiro = 0.015;

int contadorMensagemGol = 0;
int contadorMensagemErro = 0;
int contadorMensagemFora = 0;
int contadorMensagemDefesa = 0;

int acertou = 0;
int errou = 0;

int visualisarAntigo = 0;
GLfloat escala = 1, rodandoHorario = 0, rodandoAntiHorario = 0, MoveX = 0, MoveY = 0;

void init() {
    glClearColor(0, 0, 0, 0);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-4.7, 4.7, -4.7, 4.7, -4.7, 4.7);
}

void colocaGol()
{
    glColor3f(1, 1, 1);
    glPushMatrix();
    glTranslatef(0, 13, -0.4); //travessao
    glScalef(0.5, 1.5, 0.05f);
    glutSolidCube(1.0f);
    glPopMatrix();

    glColor4f(0, 0, 1, 0);
    glPushMatrix();
    glTranslatef(0, 6.36, -0.6); //marcador de gol
    glScalef(0.47, 11.6, 0.05f);
    glutSolidCube(1.0f);
    glPopMatrix();

    glColor3f(1, 1, 1);
    glPushMatrix();
    glTranslatef(-0.25, 7.05, -0.4); //trave esq
    glScalef(0.03f, 13.23, 0.05f);
    glutSolidCube(1.0f);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.25, 7.05, -0.4);
    glScalef(0.03f, 13.23, 0.05f);  //trave dir
    glutSolidCube(1.0f);
    glPopMatrix();
}

void desenhaGoleiro()
{
    float alturaGoleiro = 10;
    float larguraGoleiro = 0.1;

    glColor3f(0, 0, 0);
    glPushMatrix();
    glTranslatef(goleiroX, 8, -0.3);
    glScalef(larguraGoleiro, alturaGoleiro - 5, 0.05);
    glutSolidCube(1.0f);
    glPopMatrix();

    glColor3f(0.988, 0.854, 0.607);
    float bracoLargura = 0.05;
    glPushMatrix();
    glTranslatef(goleiroX, 5, -0.3);
    glTranslatef(larguraGoleiro / 2 + bracoLargura / 2, 0, 0);
    glScalef(bracoLargura, 0.5 * alturaGoleiro, 0.05);
    glutSolidCube(1.0f);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(goleiroX, 5, -0.3);
    glTranslatef(-larguraGoleiro / 2 - bracoLargura / 2, 0, 0);
    glScalef(bracoLargura, 0.5 * alturaGoleiro, 0.05);
    glutSolidCube(1.0f);
    glPopMatrix();

    glColor3f(1, 0, 0);
    float larguraPerna = 0.07;
    glPushMatrix();
    glTranslatef(goleiroX, 3, -0.3);
    glTranslatef(larguraGoleiro / 2 - larguraPerna / 2, 0, 0);
    glScalef(larguraPerna, 0.5 * alturaGoleiro, 0.05);
    glutSolidCube(1.0f);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(goleiroX, 3, -0.3);
    glTranslatef(-larguraGoleiro / 2 + larguraPerna / 2, 0, 0);
    glScalef(larguraPerna, 0.5 * alturaGoleiro, 0.05);
    glutSolidCube(1.0f);
    glPopMatrix();
}

void desenhaBola()
{
    glTranslatef(bolaX, 3.5, bolaZ);
    glScalef(1, 60, 1);
    glRotatef(rodaBola, 1, 0, 0);
    glColor3f(1, 1, 1);
    glutWireSphere(0.05f, 10, 5);
}

void atualizaGoleiro()
{
    goleiroX += direcaoGoleiro * velocidadeGoleiro;

    float goleiroLimiteEsquerdo = -0.30;
    float goleiroLimiteDireito = 0.30;

    if (goleiroX > goleiroLimiteDireito || goleiroX < goleiroLimiteEsquerdo)
        direcaoGoleiro = -direcaoGoleiro;
}

int verificaColisao() {
    if (((int)(bolaX * 100) >= (int)((goleiroX - 0.1) * 100) && (int)(bolaX * 100) <= (int)((goleiroX + 0.1) * 100)) && ((int)(bolaZ * 100) == (int)(-0.3 * 100)))
    {
        errou++;
        bolaZ = 0.4;
        bolaX = 0;
        contadorMensagemDefesa = 100;
        return 1;
    }

    if (((int)(bolaX * 100) == (int)(-0.25 * 100)) && ((int)(bolaZ * 100) == (int)(-0.4 * 100)))
    {
        errou++;
        bolaZ = 0.4;
        bolaX = 0;
        contadorMensagemErro = 100;
        return 1;
    }

    if (((int)(bolaX * 100) == (int)(0.25 * 100)) && ((int)(bolaZ * 100) == (int)(-0.4 * 100)))
    {
        errou++;
        bolaZ = 0.4;
        bolaX = 0;
        contadorMensagemErro = 100;
        return 1;
    }

    if ((((int)(bolaX * 100) >= (int)(-0.2 * 100)) && ((int)(bolaX * 100) <= (int)(0.2 * 100))) && ((int)(bolaZ * 100) == (int)(-0.6 * 100)))
    {
        acertou++;
        bolaZ = 0.4;
        bolaX = 0;
        contadorMensagemGol = 100;
        return 1;
    }

    if ((bolaX < -2.7 || bolaX > 2.7 || bolaZ < -0.6) && bolaZ <= 0.5)
    {
        errou++;
        bolaZ = 0.4;
        bolaX = 0;
        contadorMensagemFora = 100;
        return 1;
    }

    return 0;
}

void moveBola(int /*glut_timer_nao_usa*/)
{
    if (bolaZ > -0.6)
    {
        bolaZ -= 0.02;
        rodaBola += 12.5;

        if (verificaColisao())
            return;

        glutPostRedisplay();
        glutTimerFunc(16, moveBola, 0);
    }
}

void desenhaTexto(const char* texto, float x, float y)
{
    glRasterPos2f(x, y);
    for (const char* c = texto; *c != '\0'; c++)
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *c);
}

void desenhaEstatisticas()
{
    char textoGols[30], textoErros[30];
    sprintf(textoGols, "Gols: %d", acertou);
    sprintf(textoErros, "Erros: %d", errou);

    glPushMatrix();
    glColor3f(0, 1, 0);
    desenhaTexto(textoGols, -0.55, 42);
    glColor3f(1, 0, 0);
    desenhaTexto(textoErros, -0.55, 38);
    glPopMatrix();
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glRotatef(beta, 0, 1, 0);
    glRotatef(alpha, 1, 0, 0);
    glScalef(delta, delta, delta);

    glTranslatef(0, 0, 0);
    glScalef(5, 0.1f, 5);
    glColor3f(0.02745, 0.47059, 0.00392);
    glutSolidCube(1.0f);

    colocaGol();

    glPushMatrix();
    desenhaGoleiro();
    glPopMatrix();

    glPushMatrix();
    desenhaBola();
    glPopMatrix();

    if (contadorMensagemGol > 0)
    {
        float r = (sin(contadorMensagemGol * 0.1) + 1) / 2;
        float g = (cos(contadorMensagemGol * 0.1) + 1) / 2;
        float b = (sin(contadorMensagemGol * 0.1 + 3.14159 / 2) + 1) / 2;

        glColor3f(r, g, b);
        desenhaTexto("GOOOOOL!", -0.08, 1);

        contadorMensagemGol--;
    }

    if (contadorMensagemErro > 0)
    {
        glColor3f(1, 0, 0);
        desenhaTexto("TRAVEEEE!", -0.08, 1);

        contadorMensagemErro--;
    }

    if (contadorMensagemFora > 0)
    {
        glColor3f(1, 1, 0);
        desenhaTexto("Foi fora!", -0.05, 1);

        contadorMensagemFora--;
    }

    if (contadorMensagemDefesa > 0)
    {
        glColor3f(1, 0, 1);
        desenhaTexto("Defesa do goleiro!", -0.1, 1);

        contadorMensagemDefesa--;
    }

        desenhaEstatisticas();

    if(visualisarAntigo == 1)
    {

        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();

        gluOrtho2D(0, 85, 0, 18);

        glClearColor( 0.243, 0.557, 0.741, 0);
        glColor3f(1,1,1);

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

    glutSwapBuffers();
}


void keyboard(unsigned char key, int x, int y)
{
    if (key == ' ')
        glutTimerFunc(0, moveBola, 0);

    if(key == 'r')
    {
        acertou = 0;
        errou = 0;
    }

    if(key == 'c')
        visualisarAntigo = 1;

    if(key == 27)
        exit(0);

    if(visualisarAntigo == 1)
    {
        switch(key)
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

        display();
    }
}

void listeningSpKey(GLint tecla, GLint x, GLint y)
{
    switch (tecla)
    {
        case GLUT_KEY_LEFT:
            if(bolaX <= -0.45)
                break;
            bolaX -= 0.05;
            break;
        case GLUT_KEY_RIGHT:
            if(bolaX >= 0.45)
                break;
            bolaX += 0.05;
            break;
    }
    glutPostRedisplay();
}

void atualizaCena(int /*glut_timer_nao_usa*/)
{
    atualizaGoleiro();
    glutPostRedisplay();
    glutTimerFunc(16, atualizaCena, 0);
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Acerte o Gol!");
    init();
    glutDisplayFunc(display);
    glutSpecialFunc(listeningSpKey);
    glutKeyboardFunc(keyboard);
    glutTimerFunc(0, atualizaCena, 0);

    glutMainLoop();
    return 0;
}
