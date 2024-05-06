#include <GL/glut.h>
#include<math.h>

void circle(GLfloat rx, GLfloat ry, GLfloat cx, GLfloat cy)
{
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(cx, cy);
    for (int i = 0; i <= 360; i++)
    {
        float angle = i * 3.1416 / 180;
        float x = rx * cos(angle);
        float y = ry * sin(angle);
        glVertex2f((x + cx), (y + cy));
    }
    glEnd();
}

void init(void)
{
    glClearColor(0, 0, 0.502, 0.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0.0, 500, 0.0, 500);
}

float xLeftToRight = 1;
float xRightToLeft = 1;

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);

    // ground
    glColor3f(0.133, 0.545, 0.133);
    glBegin(GL_POLYGON);
    glVertex2d(0, 0);
    glVertex2d(500, 0);
    glVertex2d(500, 240);
    glVertex2d(0, 240);
    glEnd();

    // Tree Stem

    glColor3f(0.4, 0.2, 0.1);
    glBegin(GL_POLYGON);
    glVertex2d(400, 265);
    glVertex2d(400, 240);
    glVertex2d(420, 240);
    glVertex2d(420, 265);
    glEnd();

    glColor3f(0.4, 0.2, 0.1);
    glBegin(GL_POLYGON);
    glVertex2d(100, 265);
    glVertex2d(100, 240);
    glVertex2d(120, 240);
    glVertex2d(120, 265);
    glEnd();

    // Tree 
    glColor3f(0.1, 0.5, 0.1);
    glBegin(GL_TRIANGLES);
    glVertex2d(410, 400);
    glVertex2d(390, 265);
    glVertex2d(430, 265);
    glEnd();

    glColor3f(0.1, 0.5, 0.1);
    glBegin(GL_TRIANGLES);
    glVertex2d(110, 400);
    glVertex2d(90, 265);
    glVertex2d(130, 265);
    glEnd();

    // road lower
    glColor3f(0.5, 0.5, 0.5);
    glBegin(GL_POLYGON);
    glVertex2d(0, 180);
    glVertex2d(500, 180);
    glVertex2d(500, 215);
    glVertex2d(0, 215);
    glEnd();

    // road upper
    glColor3f(0.5, 0.5, 0.5);
    glBegin(GL_POLYGON);
    glVertex2d(0, 80);
    glVertex2d(500, 80);
    glVertex2d(500, 115);
    glVertex2d(0, 115);
    glEnd();

    // **************************************** Right to left moving car **************************************** 
    glPushMatrix();
    glTranslatef(xRightToLeft, 0, 0);

    // Car
    glColor3f(0.804, 0.125, 0.165);
    // glColor3f(0.1, 0.1, 0.1);
    glBegin(GL_POLYGON);
    glVertex2d(500, 200);
    glVertex2d(590, 200);
    glVertex2d(590, 230);
    glVertex2d(580, 240);
    glVertex2d(570, 260);
    glVertex2d(520, 260);
    glVertex2d(510, 240);
    glVertex2d(500, 230);
    glEnd();

    // car window
    glColor3f(0.827, 0.827, 0.827);
    glBegin(GL_POLYGON);
    glVertex2d(525, 230);
    glVertex2d(540, 230);
    glVertex2d(540, 250);
    glVertex2d(525, 250);
    glEnd();

    // car window
    glColor3f(0.827, 0.827, 0.827);
    glBegin(GL_POLYGON);
    glVertex2d(550, 230);
    glVertex2d(565, 230);
    glVertex2d(565, 250);
    glVertex2d(550, 250);
    glEnd();

    // car wheel
    glColor3f(0.15, 0.15, 0.15);
    circle(10, 15, 525, 200);
    circle(10, 15, 565, 200);

    glPopMatrix();
    xRightToLeft = xRightToLeft - 0.1;
    if (xRightToLeft < -600) {
        xRightToLeft = 0;
    }

    // **************************************** Left to Right going car ******************************************
    glPushMatrix();
    glTranslatef(xLeftToRight, 0, 0);

    // Car
    glColor3f(0.255, 0.412, 0.882);
    glBegin(GL_POLYGON);
    glVertex2d(520, 160);   // top left
    glVertex2d(520, 100);   // bottom left
    glVertex2d(590, 100);   // bottom right
    glVertex2d(590, 130);   // bumper right corner
    glVertex2d(580, 140);   // wind shield
    glVertex2d(570, 160);   // top right
    glEnd();

    // car window
    glColor3f(0.827, 0.827, 0.827);
    glBegin(GL_POLYGON);
    glVertex2d(530, 130);
    glVertex2d(545, 130);
    glVertex2d(545, 150);
    glVertex2d(530, 150);
    glEnd();

    // car window
    glColor3f(0.827, 0.827, 0.827);
    glBegin(GL_POLYGON);
    glVertex2d(550, 130);
    glVertex2d(565, 130);
    glVertex2d(565, 150);
    glVertex2d(550, 150);
    glEnd();

    // car wheel
    glColor3f(0.15, 0.15, 0.15);
    circle(10, 15, 535, 100);
    circle(10, 15, 565, 100);

    glPopMatrix();
    xLeftToRight = xLeftToRight + 0.1;
    if (xLeftToRight > 0) {
        xLeftToRight = -600;
    }

    glutPostRedisplay();
    glFlush();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
    glutInitWindowSize(1000, 600);
    glutInitWindowPosition(300, 50);
    glutCreateWindow("Racing Cars");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
