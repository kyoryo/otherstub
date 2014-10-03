#include <windows.h>
#include <GL/glut.h>
#include <cmath>

/* draw circle*/
void Torus2d( float inner, float outer, unsigned int pts )
{
    glBegin( GL_QUAD_STRIP );
    for( unsigned int i = 0; i <= pts; ++i )
    {
        float angle = ( i / (float)pts ) * 3.14159f * 2.0f;
        glVertex2f( inner * cos( angle ), inner * sin( angle ) );
        glVertex2f( outer * cos( angle ), outer * sin( angle ) );
    }
    glEnd();
}
/*get value*/
void display()
{
    glClear( GL_COLOR_BUFFER_BIT );

    glMatrixMode( GL_PROJECTION );
    glLoadIdentity();
    double w = glutGet( GLUT_WINDOW_WIDTH );
    double h = glutGet( GLUT_WINDOW_HEIGHT );
    double ar = w / h;
    glOrtho( -4 * ar, 4 * ar, -4, 4, -1, 1);

    glMatrixMode( GL_MODELVIEW );
    glLoadIdentity();

    /*getcolor*/
    glColor3ub( 192, 203, 195 );

    /* draw */
    Torus2d( 2, 3, 80 );

    glutSwapBuffers();
}

int main( int argc, char **argv )
{
    glutInit( &argc, argv );
    glutInitDisplayMode( GLUT_RGBA | GLUT_DOUBLE );
    glutInitWindowSize( 640, 480 );
    glutCreateWindow( "Circle" );
    glutDisplayFunc( display );
    glutMainLoop();
    return 0;
}
