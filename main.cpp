#include <windows.h>
#ifdef APPLE_CC
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif



double posx = 0, posy = 0, posz = 2.1, eyex = 0, eyey = 0, eyez = 0, upx = 0, upy = 1, upz = 0;

static int  a2 = 0, a3 = 0, tx = 0, ty = 0, tz = 0, sx = 1, sy = 1, sz = 1,rx = 0, ry = 0, rz = 0;
float p = 1.4;
static double a1 = 0.8;

float color1 = 0.5f;
float color2 = 0.0f;
float color3 = 0.0f;

static void idle(void)
{
    glutPostRedisplay();
}

void init() {

  glClearColor (0.4, 0.85, 1.0, 0.0);
  glColor3f(1.0, 1.0, 1.0);

  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluPerspective(50.0, 3.22/3.0, 1, 20);

}



void special(int key, int, int) {
  switch (key) {
    case GLUT_KEY_LEFT: (tx -= 1) %= 500; break;
    case GLUT_KEY_RIGHT: (tx += 1) %= 500; break;

    case GLUT_KEY_UP: (ty += 1) %= 500; break;
    case GLUT_KEY_DOWN: (ty -= 1) %= 500; break;



    case GLUT_KEY_F2: (rx += 5) %= 360; break;
    case GLUT_KEY_F3: (rx -= 5) %= 360; break;
    case GLUT_KEY_PAGE_UP: (ry += 5) %= 360; break;
    case GLUT_KEY_PAGE_DOWN: (ry -= 5) %= 360; break;
    case GLUT_KEY_HOME: (rz += 5) %= 360; break;
    case GLUT_KEY_END: (rz -= 5) %= 360; break;

    case GLUT_KEY_F4: (a1 += 0.1); break;
    case GLUT_KEY_F5: (a1 -= 0.1); break;





    case GLUT_KEY_F6: posx += 0.5; break;
    case GLUT_KEY_F7: posx -= 0.5; break;
    case GLUT_KEY_F8: posy += 0.5; break;
    case GLUT_KEY_F9: posy -= 0.5; break;
    case GLUT_KEY_F10: posz += 0.5; break;
    case GLUT_KEY_F11: posz -= 0.5; break;


    default: return;
  }
  glutPostRedisplay();
}


void boat(int value) {
    p = p - 0.025;
    if(p < -0.8){
        p = p + 2.4;
    }
    glutPostRedisplay();
    glutTimerFunc(50, boat, 1);
}

void timer( int value )
{
    color1 += 0.003f;
    color2 += 0.003f;
    color3 += color2;
    if (color1 > 1.0)
        color1 = 0.5;
    if (color2 > 1.0)
        color2 = 0;
    if (color3 > 1.0)
        color3 = 0;

    glutPostRedisplay();
    glutTimerFunc( 16, timer, 0 );
}


void display() {
glClear(GL_COLOR_BUFFER_BIT);
//glLoadIdentity();
//glScalef(a1,a1,a1);


glPushMatrix();
glBegin(GL_POLYGON);
    glColor3f(0.0,1.0,0.0);
    glVertex3f(1.0,1.0,0.0);
    glVertex3f(1.0,-1.0,0.0);
    glVertex3f(-1.0,-1.0,0.0);
    glVertex3f(-1.0,1.0,0.0);


glEnd();
glPopMatrix();

glPushMatrix();
    glColor3f(0.0,0.5,1.0);
    glBegin(GL_POLYGON);

        glVertex3f(0.0,-0.12,0.0);
        glVertex3f(0.1, -0.10,0.0);
        glVertex3f(0.2,-0.12,0.0);
        glVertex3f(0.3, -0.10,0.0);
        glVertex3f(0.4,-0.12,0.0);
        glVertex3f(0.5, -0.10,0.0);
        glVertex3f(0.6,-0.12,0.0);
        glVertex3f(0.7, -0.10,0.0);
        glVertex3f(0.8,-0.12,0.0);
        glVertex3f(0.9, -0.10,0.0);
        glVertex3f(1.0,-0.13,0.0);

        glVertex3f(1.0,-0.62,0.0);
        glVertex3f(0.9, -0.60,0.0);   // NODI
        glVertex3f(0.8,-0.62,0.0);
        glVertex3f(0.7, -0.60,0.0);
        glVertex3f(0.6,-0.62,0.0);
        glVertex3f(0.5, -0.60,0.0);
        glVertex3f(0.4,-0.62,0.0);
        glVertex3f(0.3, -0.60,0.0);
        glVertex3f(0.2,-0.62,0.0);
        glVertex3f(0.1,-0.60,0.0);
        glVertex3f(0.0,-0.62,0.0);

        glVertex3f(-0.1,-0.6,0.0);
        glVertex3f(-0.2, -0.62,0.0);
        glVertex3f(-0.3,-0.6,0.0);
        glVertex3f(-0.4, -0.62,0.0);
        glVertex3f(-0.5,-0.6,0.0);
        glVertex3f(-0.6, -0.62,0.0);
        glVertex3f(-0.7,-0.6,0.0);
        glVertex3f(-0.8, -0.62,0.0);
        glVertex3f(-0.9,-0.6,0.0);
        glVertex3f(-1.0, -0.62,0.0);

        glVertex3f(-1.0,-0.11,0.0);
        glVertex3f(-0.9,-0.12,0.0);
        glVertex3f(-0.8,-0.10,0.0);
        glVertex3f(-0.7,-0.12,0.0);
        glVertex3f(-0.6,-0.10,0.0);
        glVertex3f(-0.5,-0.12,0.0);
        glVertex3f(-0.4,-0.10,0.0);
        glVertex3f(-0.3,-0.12,0.0);
        glVertex3f(-0.2,-0.10,0.0);
        glVertex3f(-0.1,-0.12,0.0);
        glVertex3f(-0.0,-0.10,0.0);

glEnd();
glPopMatrix();

glPushMatrix();
    glTranslatef(p,0.0,0.0);
    //glScalef(0.5,1.0,0.5);
    glBegin(GL_POLYGON);

        glColor3f(0.3,0.2,0.14);
        glVertex3f(-0.3,-0.38,0.0);
        glVertex3f(-0.3,-0.32,0.0);     //Boat-bottom
        glVertex3f(-0.55,-0.32,0.0);
        glVertex3f(-0.55,-0.38,0.0);

    glEnd();
    glBegin(GL_POLYGON);
        glColor3f(0.3,0.2,0.14);
        glVertex3f(-0.55,-0.38,0.0);
        glVertex3f(-0.55,-0.32,0.0);
        glVertex3f(-0.60,-0.335,0.02);     //Boat-Left
        glVertex3f(-0.65,-0.35,0.05);
        glVertex3f(-0.60,-0.365,0.02);
        glVertex3f(-0.55,-0.38,0.0);


    glEnd();
    glBegin(GL_POLYGON);
        glColor3f(0.3,0.2,0.14);
        glVertex3f(-0.3,-0.38,0.0);
        glVertex3f(-0.3,-0.32,0.0);
        glVertex3f(-0.25,-0.335,0.02);     //Boat-Right
        glVertex3f(-0.20,-0.35,0.05);
        glVertex3f(-0.25,-0.365,0.02);
        glVertex3f(-0.3,-0.38,0.0);


    glEnd();

    glBegin(GL_POLYGON);
        glColor3f(0.3,0.2,0.14);
        glVertex3f(-0.65,-0.35,0.05);
        glVertex3f(-0.60,-0.365,0.05);
        glVertex3f(-0.55,-0.38,0.05);
        glVertex3f(-0.3,-0.38,0.05);       //Boat-Front
        glVertex3f(-0.25,-0.365,0.05);
        glVertex3f(-0.20,-0.35,0.05);
        glVertex3f(-0.25,-0.365,0.02);
        glVertex3f(-0.3,-0.38,0.0);
        glVertex3f(-0.55,-0.38,0.0);
        glVertex3f(-0.60,-0.365,0.02);
        glVertex3f(-0.65,-0.35,0.05);


    glEnd();

    glBegin(GL_POLYGON);
        glColor3f(0.3,0.2,0.14);
        glVertex3f(-0.65,-0.35,0.05);
        glVertex3f(-0.60,-0.335,0.05);
        glVertex3f(-0.55,-0.32,0.05);
        glVertex3f(-0.3,-0.32,0.05);       //Boat-Back
        glVertex3f(-0.25,-0.335,0.05);
        glVertex3f(-0.20,-0.35,0.05);
        glVertex3f(-0.25,-0.335,0.02);
        glVertex3f(-0.3,-0.32,0.0);
        glVertex3f(-0.55,-0.32,0.0);
        glVertex3f(-0.60,-0.335,0.02);
        glVertex3f(-0.65,-0.35,0.05);


    glEnd();
    glLineWidth(3.0);
    glColor3f(1.0,color1,color2);
    glBegin(GL_LINES);
        glVertex3f(-0.30,-0.35,0.20);   //Boat-handle
        glVertex3f(-0.2,-0.37,0.03);

    glEnd();
    glBegin(GL_TRIANGLES);
        glVertex3f(-0.205,-0.37,0.03);
        glVertex3f(-0.18,-0.37,0.032);   //Boat-handle
        glVertex3f(-0.20,-0.37,0.00);


    glEnd();
    glLineWidth(4.0);
    glColor3f(0.5,0.5,0.5);
    glBegin(GL_LINES);
        glVertex3f(-0.55,-0.35,0.0);    //Flag-stand
        glVertex3f(-0.55,-0.35,0.3);

    glEnd();

    glBegin(GL_POLYGON);
        glColor3f(0.0,0.5,0.0);
        glVertex3f(-0.55,-0.35,0.3);   //Flag-rectangle
        glVertex3f(-0.45,-0.35,0.3);
        glVertex3f(-0.45,-0.35,0.22);
        glVertex3f(-0.55,-0.35,0.22);

    glEnd();
    glColor3f(1.0,0.0,0.0);
    glTranslatef(-0.5,-0.35,0.26);         //Flag-red-circle
    glRotatef(45,1.0,0.0,0.0);
    glutSolidSphere(0.02,36,2);



glPopMatrix();





glPushMatrix();
    glColor3f(0.5,0.5,1.0);
    glBegin(GL_POLYGON);
        glVertex3f(0.3,0.28,0.0);
        glVertex3f(0.35,0.4,0.0);
        glVertex3f(0.4,0.4,0.0);
        glVertex3f(0.3,0.25,0.0);                  // Rasta
        glVertex3f(0.1,0.1,0.0);
        glVertex3f(-0.1,-0.11,0.0);
        glVertex3f(-0.15,-0.11,0.0);
glEnd();
glPopMatrix();


glPushMatrix();
    glColor3f(0.3,0.2,0.14);

    glBegin(GL_POLYGON);
        glVertex3f(0.3,0.4,0.0);
        glVertex3f(0.5, 0.4,0.0);
        glVertex3f(0.5, 0.65,0.0);  // Bottom    // GHOR
        glVertex3f(0.3,0.65,0.0);


        glVertex3f(0.3,0.65,0.0);
        glVertex3f(0.5, 0.65,0.0);    //back
        glVertex3f(0.5, 0.65,0.3);
        glVertex3f(0.3,0.65,0.3);

        glColor3f(0.3,0.2,0.5);
        glVertex3f(0.3,0.4,0.0);
        glVertex3f(0.3,0.65,0.0);
        glVertex3f(0.3,0.65,0.3);      //left
        glVertex3f(0.3,0.4,0.3);


        glColor3f(0.3,0.2,0.14);
        glVertex3f(0.3,0.4,0.0);
        glVertex3f(0.5,0.4,0.0);
        glVertex3f(0.5,0.4,0.3);   //front
        glVertex3f(0.3,0.4,0.3);

        //glColor3f(1.0,0.0,1.0);
        glVertex3f(0.5,0.4,0.0);
        glVertex3f(0.5,0.65,0.0);
        glVertex3f(0.5, 0.65,0.3);    //right
        glVertex3f(0.5, 0.4,0.3);


glEnd();

glColor3f(0.3,0.1,0.14);
    glBegin(GL_POLYGON);


    glVertex3f(0.28,0.38,0.30);
    glVertex3f(0.52, 0.38,0.30);
    glVertex3f(0.52, 0.67,0.30);                       // top
    glVertex3f(0.28,0.67,0.30);

glEnd();

glBegin(GL_POLYGON);
    glColor3f(0.0,0.5,1.0);
    glVertex3f(0.32,0.4,0.13);
    glVertex3f(0.35,0.4,0.13);
    glVertex3f(0.35,0.4,0.17);    // Janala 1
    glVertex3f(0.32,0.4,0.17);

glEnd();
glBegin(GL_POLYGON);
    glColor3f(0.0,0.5,1.0);
    glVertex3f(0.45,0.4,0.13);
    glVertex3f(0.48,0.4,0.13);
    glVertex3f(0.48,0.4,0.17);    // Janala 2
    glVertex3f(0.45,0.4,0.17);


glEnd();
glPopMatrix();

glPushMatrix();
    glColor3f(0.3,0.2,0.14);
    glBegin(GL_POLYGON);

    glVertex3f(-0.74,-0.05,0.0);
    glVertex3f(-0.7,-0.05,0.0);
    glVertex3f(-0.7,-0.00,0.0);    // Tree
    glVertex3f(-0.74,0.00,0.0);

    glVertex3f(-0.74,0.00,0.0);
    glVertex3f(-0.74,-0.05,0.0);
    glVertex3f(-0.74,-0.05,0.4);   //Tree-left
    glVertex3f(-0.74,0.00,0.4);
    glVertex3f(-0.74,0.00,0.0);

    glVertex3f(-0.74,-0.05,0.0);
    glVertex3f(-0.7,-0.05,0.0);
    glVertex3f(-0.7,-0.05,0.4);    //Tree-front
    glVertex3f(-0.74,-0.05,0.4);
    glVertex3f(-0.74,-0.05,0.0);

    glVertex3f(-0.7,-0.05,0.0);
    glVertex3f(-0.7,-0.00,0.0);
    glVertex3f(-0.7,-0.00,0.4);   //Tree-right
    glVertex3f(-0.7,-0.05,0.4);
    glVertex3f(-0.7,-0.05,0.0);

    glVertex3f(-0.74,0.00,0.0);
    glVertex3f(-0.7,0.00,0.0);
    glVertex3f(-0.7,0.00,0.4);    //Tree-back
    glVertex3f(-0.74,0.00,0.4);
    glVertex3f(-0.74,0.00,0.0);


    glEnd();
glPopMatrix();

glPushMatrix();

    glColor3f(0.0,0.5,0.0);
    glTranslatef(-0.74,-0.025,0.4);     //tree-leaf
    glutSolidSphere(0.13,36,2);

glPopMatrix();
glPushMatrix();

    glColor3f(0.0,0.5,0.0);
    glTranslatef(-0.7,-0.025,0.4);
    glutSolidSphere(0.13,36,2);       //tree-leaf

glPopMatrix();

glPushMatrix();

    glColor3f(0.0,0.5,0.0);
    glTranslatef(-0.72,-0.05,0.4);
    glutSolidSphere(0.13,36,2);        //tree-leaf

glPopMatrix();
glPushMatrix();

    glColor3f(0.0,0.5,0.0);
    glTranslatef(-0.72,-0.0,0.4);
    glutSolidSphere(0.13,36,2);        //tree-leaf

glPopMatrix();



glPushMatrix();
    glColor3f(color1,color2,0.0);
    glTranslatef(0.8,0.8,0.6);         //Sun
    glRotatef(45,1.0,0.0,0.0);
    glutSolidSphere(0.08,36,2);

glPopMatrix();
glPushMatrix();
    glLineWidth(1.0);
    glColor3f(1.0,color1,color2);
    glTranslatef(-0.1,0.2,-0.1);
    glRotatef(45,1.0,0.0,0.0);
    glBegin(GL_LINES);
        glVertex3f(0.82,0.82,0.0);      //Line
        glVertex3f(0.7,0.65,0.0);

        glVertex3f(0.86,0.81,0.0);
        glVertex3f(0.82,0.65,0.0);

        glVertex3f(0.91,0.81,0.0);
        glVertex3f(0.95,0.62,0.0);

        glVertex3f(0.81,0.90,0.0);
        glVertex3f(0.7,0.85,0.0);

    glEnd();
glPopMatrix();


glPushMatrix();

    float kx = float(tx) * 0.03;
    float ky = float(ty) * 0.03;
    glTranslatef(kx,ky,0.0);
    glRotatef(rx,1.0,0.0,0.0);
    glRotatef(ry,0.0,1.0,0.0);
    glRotatef(rz,0.0,0.0,1.0);
    glColor3f(0.5,0.5,0.5);
    glScalef(a1,a1,a1);

    glBegin(GL_POLYGON);


    glVertex3f(0.01,-0.52,0.0);
    glVertex3f(0.03,-0.50,0.0);
    glVertex3f(0.05,-0.48,0.0);    // Fish
    glVertex3f(0.10,-0.49,0.0);
    glVertex3f(0.14,-0.52,0.0);
    glVertex3f(0.10,-0.54,0.0);
    glVertex3f(0.05,-0.55,0.0);
    glVertex3f(0.03,-0.53,0.0);
    glVertex3f(0.01,-0.52,0.0);

glEnd();
glBegin(GL_POLYGON);

    glVertex3f(0.135,-0.52,0.0);
    glVertex3f(0.16,-0.50,0.0);       // Fish-lej
    glVertex3f(0.16,-0.54,0.0);

glEnd();

    glColor3f(color1,color2,0.0);
    glTranslatef(0.028,-0.52,0.0);         //Fish-Eye
    glutSolidSphere(0.004,36,2);
glLineWidth(2.0);
glColor3f(1.0,0.5,1.0);
glBegin(GL_LINES);

    glVertex3f(0.02, 0.03,0.0);      //Fish-Line
    glVertex3f(0.02,-0.03,0.0);

glEnd();


glPopMatrix();

  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  gluLookAt(posx, posy, posz, eyex, eyey, eyez, upx, upy, upz);

  glRotatef(300,1.0,0.0,0.0);

glFlush();
}

// Initializes GLUT, the display mode, and main window; registers callbacks;
// enters the main event loop.
int main(int argc, char** argv) {

  // Use a single buffered window in RGB mode (as opposed to a double-buffered
  // window or color-index mode).
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

  // Position window at (80,80)-(480,380) and give it a title.
  glutInitWindowPosition(80, 80);
  glutInitWindowSize(600, 500);
  glutCreateWindow("Lake");
  glutTimerFunc(100, boat, 0);
  glutTimerFunc( 16, timer, 0 );
  glutDisplayFunc(display);

  glutSpecialFunc(special);

  init();
  glutMainLoop();
}
