#include <GL/glu.h>
#include <GL/glut.h>

void init (void)
{
     GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0} ; //parameter cahaya specular
     GLfloat mat_shininess[] = { 100.0 }; //parameter shininess
     GLfloat light_position[] = { 1.0, 0.5, 1.0, 1.0 }; //parameter posisi pencahayaan
     glClearColor (0.9, 0.9, 0.9, 1.0);
     glShadeModel (GL_SMOOTH); //mengaktifkan shade model
     glMaterialfv (GL_FRONT, GL_SPECULAR, mat_specular);
     glMaterialfv (GL_FRONT, GL_SHININESS, mat_shininess);
     glLightfv (GL_LIGHT0, GL_POSITION, light_position);
     glEnable(GL_LIGHTING); //mengaktifkan pencahayaan
     glEnable(GL_LIGHT0); //mengaktifkan sumber cayaha
     glEnable(GL_NORMALIZE);
     glShadeModel(GL_SMOOTH);
     //add positioned light
     GLfloat lightColor0[] = {0.7f, 0.7f, 0.7f, 1.0f};
     GLfloat lightPos0[] = {5.0f, 7.0f, 5.0f, 1.0f};
     glLightfv(GL_LIGHT0, GL_DIFFUSE, lightColor0);
     glLightfv(GL_LIGHT0, GL_POSITION, lightPos0);
     glPopMatrix();
     glEnable(GL_DEPTH_TEST);
}

void display(void)
{
     const double t= glutGet(GLUT_ELAPSED_TIME) /1000.0;
     const double a = t*90.0, b = t/2, c = t/10;

     glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
     glEnable(GL_COLOR_MATERIAL); //mengaktifkan fungsi untuk memberikan warna pada meterial
     glColorMaterial(GL_FRONT, GL_DIFFUSE); //parameter-parameter fungsi warna material

     //bulat (objek1)
     glPushMatrix();
                    glColor3f(0.2, 1.0, 0.7);
                    glTranslatef(-1.8, 1.2, -5.0);
                    glRotatef(a, 1.0, 0.0, 0.0);
                    glutSolidSphere (0.15, 100, 16);
     glPopMatrix();

     //kotak (objek2)
     glPushMatrix();
                    glColor3f(0.5, 1.0, 0.5); //warna
                    //glScalef(1.5, 0.5, 0.0);
                    glTranslatef(-2.3, 1.2, -5.0); //letak
                    glRotatef(-a, 0.0, 1.0, 0); //rotasi
                    glRotatef(a, -0.5, 0.5, 1.2);
                    glRotatef(a, -0.5, 0.5, -1.2);
                    glRotatef(-a, 0.0, 1.0, 2);
                    glScaled(1,1,1); //ukuran (x,y,z)
                    glutSolidCube (0.2); //ukuran default
     glPopMatrix();

     //teko transparant (objek3)
     glPushMatrix();
                    glColor3f(1.0, 1.5, 0.5);
                    glTranslatef(-1.1, 1.2, -1.0);
                    glRotatef(-a, 0.0, 1.0, 0.2);
                    glutWireTeapot (0.2);
     glPopMatrix();

     //teko solid (objek4)
     glPushMatrix();
                    glColor3f(0.8, 0.3, 0.2);
                    glTranslatef(-0.4, 1.2, 0.0);
                    glRotatef(a, 0.0, 1.0, 0.0);
                    glRotatef(a, 0.0, 1.0, 1.0);
                    glRotatef(-a, 0.0, 1.0, 0.5);
                    glRotatef(a, 0.0, 1.0, 3.0);
                    glRotatef(a, 0.0, 1.0, 0.0);
                    glutSolidTeapot (0.2);
     glPopMatrix();

     //donat solid (objek5)
     glPushMatrix();
                    glColor3f(1.2, 0.9, 0.5);
                    glTranslatef(0.3, 1.2, 0.0);
                    glRotatef(a, -0.5, 0.5, 0.2);
                    glScaled(0.5,0.5,0.5);
                    glutSolidTorus (0.1, 0.3, 50, 50);
     glPopMatrix();

     //donat transparant (objek6)
     glPushMatrix();
                    glColor3f(0.5, 1.0, 0.5);
                    glTranslatef(0.9, 1.2, 0.0);
                    glRotatef(-a, 0.5, 0.5, 0.2);
                    glScaled(0.5,0.5,0.5); //ukuran
                    glutWireTorus (0.1, 0.3, 40, 50);
     glPopMatrix();

     //cone solid (objek7)
     glPushMatrix();
                    glColor3f(0.2, 0.8, 1.0);
                    glTranslatef(1.6, 1.1, 0.0);
                    glRotatef(a, -0.5, 0.5, 0.2);
                    glRotatef(a, -0.5, 0.5, 1.2);
                    glRotatef(a, -0.5, 0.5, -1.2);
                    glRotatef(a, -0.5, 0.5, -2.2);
                    glScaled(0.65,0.65,0.65);
                    glutSolidCone (0.2, 0.5, 50, 50);
     glPopMatrix();

     //cone transparant (objek8)
     glPushMatrix();
                    glColor3f(0.5, 0.2, 1.0);
                    glTranslatef(2.2, 1.1, 0.0);
                    glRotatef(-a, -0.5, 0.5, 0.2);
                    glRotatef(-a, -0.5, 0.5, 1.2);
                    glRotatef(a, -0.5, 0.5, 2.2);
                    glRotatef(-a, -0.5, 0.5, 0.2);
                    glScaled(0.65,0.65,0.65);
                    glutWireCone (0.2, 0.5, 50, 50);
     glPopMatrix();

    //kulkas
            glPushMatrix();
                    glColor3f(0.3, 1.0, 1.5); //warna
                    //glScalef(1.5, 0.5, 0.0);
                    glTranslatef(-2.3, 0.5, -5.0); //letak
                    glRotatef(25.0, 0.0, 2.0, 0.0); //rotasi
                    glScaled(1.5,3,1); //ukuran (x,y,z)
                    glutSolidCube (0.2); //ukuran default
            glPopMatrix();
            //garis pemisah
            glPushMatrix();
                           glColor3f(0.0, 0.0, 0.0);
                           glTranslatef(-2.42, 0.55, -5.0);
                           glBegin(GL_LINES);
                           glVertex3f(0.3,0.0,5.13);
                           glVertex3f(0,0,0.0);
                           glEnd();
            glPopMatrix();
            //kotak pintu1
            glPushMatrix();
                           glColor3f(0.0, 0.0, 0.0);
                           glTranslatef(-2.17, 0.65, 0.0);
                           glBegin (GL_POLYGON);
                           glColor3f (1.0f, 0.0f, 0.0f); glVertex2f (-0.015f, -0.015f);
                           glColor3f (0.0f, 1.0f, 0.0f); glVertex2f (-0.015f, 0.06f);
                           glColor3f (0.0f, 2.0f, 0.0f); glVertex2f (0.015f, 0.06f);
                           glColor3f (0.0f, 0.0f, 3.0f); glVertex2f (0.015f, -0.015f);
                           glEnd ();
            glPopMatrix();
            //kotak pintu2
            glPushMatrix();
                           glColor3f(0.0, 0.0, 0.0);
                           glTranslatef(-2.17, 0.42, 0.0);
                           glBegin (GL_POLYGON);
                           glColor3f (1.0f, 0.0f, 0.0f); glVertex2f (-0.015f, -0.015f);
                           glColor3f (0.0f, 1.0f, 0.0f); glVertex2f (-0.015f, 0.06f);
                           glColor3f (0.0f, 2.0f, 0.0f); glVertex2f (0.015f, 0.06f);
                           glColor3f (0.0f, 0.0f, 3.0f); glVertex2f (0.015f, -0.015f);
                           glEnd ();
            glPopMatrix();
    //hexagon 3d = isocahedron
    glPushMatrix();
        glColor3ub(123, 58, 126);
        glTranslated(-1.8, 0.42, 0.0);
        glRotatef(a, 0.5, 0.5, 0.2);
        glScaled(0.3, 0.3, 0.3);
        glutSolidIcosahedron();
    glPopMatrix();

//==========10
    glPushMatrix();
        glColor3ub(123, 58, 126);
        glTranslated(-1.1, 0.42, 0.0);
        glRotatef(-a, 0.5, 0.5, 0.2);
        glScaled(0.3, 0.3, 0.3);
        glutWireIcosahedron();
    glPopMatrix();

//==============11
    glPushMatrix();
        glColor3ub(12, 58, 126);
        glTranslated(-0.4, 0.42, 0.0);
        glRotatef(a, 0.5, 0.5, 0.2);
        glScaled(0.3, 0.3, 0.3);
        glutSolidTetrahedron();
    glPopMatrix();
//==============12
    glPushMatrix();
        glColor3ub(12, 58, 126);
        glTranslated(0.3, 0.42, 0.0);
        glRotatef(-a, 0.5, 0.5, 0.2);
        glScaled(0.3, 0.3, 0.3);
        glutWireTetrahedron();
    glPopMatrix();
//==============13
    glPushMatrix();
        glColor3ub(200, 0, 199);
        glTranslated(0.9, 0.42, 0.0);
        glRotatef(a, 0.5, 0.5, 0.2);
        glScaled(0.3, 0.3, 0.3);
        glutSolidOctahedron();
    glPopMatrix();
    //==============14
    glPushMatrix();
        glColor3ub(200, 0, 199);
        glTranslated(1.5, 0.42, 0.0);
        glRotatef(-a, 0.5, 0.5, 0.2);
        glScaled(0.3, 0.3, 0.3);
        glutWireOctahedron();
    glPopMatrix();
//==============15
    glPushMatrix();
        glColor3ub(12, 240, 16);
        glTranslated(2.2, 0.42, 0.0);
        glRotatef(a, 0.5, 0.5, 0.2);
        glScaled(0.3, 0.3, 0.3);
        glutSolidOctahedron();
        glutSolidTetrahedron();
    glPopMatrix();
    //==============16
    glPushMatrix();
        glColor3ub(12, 20, 16);
        glTranslated(-2.3, -0.48, 0.0);
        glRotatef(-a, 0.5, 0.5, 0.2);
        glScaled(0.3, 0.3, 0.3);
        glutWireTetrahedron();
    glPopMatrix();
    glPushMatrix();
        glColor3ub(120, 201, 106);
        glTranslated(-2.3, -0.48, 0.0);
        glRotatef(a, 0.5, 0.5, 0.2);
        glScaled(0.3, 0.3, 0.3);
        glutSolidOctahedron();
    glPopMatrix();
//-=============17
    glPushMatrix();
        glColor3ub(245, 0, 106);
        glTranslated(-1.8, -0.48, 0.0);
        glRotatef(-a, 0.5, 0.5, 0.2);
        glScaled(0.1, 0.1, 0.1);
        glutSolidDodecahedron();
    glPopMatrix();
//-=============18
    glPushMatrix();
        glColor3ub(245, 0, 109);
        glTranslated(-1.1, -0.48, 0.0);
        glRotatef(a, 0.5, 0.5, 0.2);
        glScaled(0.1, 0.1, 0.1);
        glutWireDodecahedron();
    glPopMatrix();
//-=============19
    glPushMatrix();
        glColor3ub(240, 227, 0);
        glTranslated(-0.4, -0.48, 0.0);
        glRotatef(-a, 0.5, 0.5, 0.2);
        glScaled(0.3, 0.3, 0.3);
        glutSolidTorus(0.5, 0., 5, 50);
    glPopMatrix();
//-=============20
    glPushMatrix();
        glColor3ub(240, 227, 0);
        glTranslated(0.3, -0.48, 0.0);
        glRotatef(a, 0.5, 0.5, 0.2);
        glScaled(0.3, 0.3, 0.3);
        glutWireTorus(0.5, 0., 5, 50);
    glPopMatrix();
//-=============21
    glPushMatrix();
        glColor3ub(120, 201, 106);
        glTranslated(0.3, -0.48, 0.0);
        glRotatef(-a, 0.5, 0.5, 0.2);
        glScaled(0.3, 0.3, 0.3);
        glutWireTorus(0.5, 0., 5, 50);
    glPopMatrix();
//-=============21
    glPushMatrix();
        glColor3ub(10, 201, 255);
        glTranslated(0.9, -0.48, 0.0);
        glRotatef(a, 0.5, 0.5, 0.2);
        glScaled(0.4, 0.5, 0.4);
        glutSolidCone(0.5, 0.2, 5, 50);
        glutSolidCone(0.2, 0.5, 5, 50);
    glPopMatrix();
//-=============22
    glPushMatrix();
        glColor3ub(10, 201, 255);
        glTranslated(1.5, -0.48, 0.0);
        glRotatef(a, 0.5, 0.5, 0.2);
        glScaled(0.5, 0.5, 0.5);
        glutWireCone(0.5, 0.2, 5, 50);
        glutWireCone(0.2, 0.5, 5, 50);
    glPopMatrix();
//-=============23
    glPushMatrix();
        glColor3ub(120, 201, 106);
        glTranslated(2.2, -0.48, 0.0);
        glRotatef(-a, 0.5, 0.5, 0.2);
        glScaled(0.5, 0.5, 0.5);
        glutSolidSphere(0.5, 5, 50);
    glPopMatrix();
//-=============24
    glPushMatrix();
        glColor3ub(120, 201, 106);
        glTranslated(-.9, -1.2, 0.0);
        glRotatef(a, 0.5, 0.5, 0.2);
        glScaled(0.5, 0.5, 0.5);
        glutWireSphere(0.5, 5, 50);
    glPopMatrix();
//-=============25
    glPushMatrix();
        glColor3ub(10, 201, 255);
        glTranslated(.9, -1.2, 0.0);
        glRotatef(-a, 0.5, 0.5, 0.2);
        glScaled(0.3, 0.3, 0.3);
        glutWireCube(0.8);
    glPopMatrix();
    glPushMatrix();
        glColor3ub(10, 201, 255);
        glTranslated(.9, -1.2, 0.0);
        glRotatef(-a, 0.5, 0.5, 0.2);
        glScaled(0.3, 0.3, 0.3);
        glutWireTetrahedron();
    glPopMatrix();
    /////////////////////
     glPopMatrix();
     glDisable(GL_COLOR_MATERIAL); //menonaktifkan fungsi untuk memberikan warna pada material

     glFlush ();
     glutPostRedisplay();
}

void reshape (int w, int h)
{
     glViewport (0, 0, (GLsizei) w, (GLsizei) h);
     glMatrixMode (GL_PROJECTION);
     glLoadIdentity();
     if (w <= h)
        glOrtho (-1.5, 1.5, -1.5*(GLfloat)h/(GLfloat)w,
        1.5*(GLfloat)h/(GLfloat)w, -10.0, 10.0);
     else
         glOrtho (-1.5*(GLfloat)w/(GLfloat)h,
         1.5*(GLfloat)w/(GLfloat)h, -1.5, 1.5, -10.0, 10.0);
         glMatrixMode(GL_MODELVIEW);
         glLoadIdentity();
         gluLookAt (0.0, 0.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize (1280, 768);
    glutInitWindowPosition (10, 10);
    glutCreateWindow ("Program 25 Objek");
    init ();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutMainLoop();
    return 0;
}
