///////////////////////////////////////////////////////////////////////////////
// A-Team Project --- UG Innovation Center
// University of Guyana
// Department of Computer Science
// 
///////////////////////////////////////////////////////////////////////////////

#include <GL/glut.h>
static int x_rotation = 0, y_rotation = 0,  z_rotation = 0;
// vertex coords array
GLfloat vertices[] = {1,1,1,  -1,1,1,  -1,-1,1,  1,-1,1,        // v0-v1-v2-v3
                      1,1,1,  1,-1,1,  1,-1,-1,  1,1,-1,        // v0-v3-v4-v5
                      1,1,1,  1,1,-1,  -1,1,-1,  -1,1,1,        // v0-v5-v6-v1
                      -1,1,1,  -1,1,-1,  -1,-1,-1,  -1,-1,1,    // v1-v6-v7-v2
                      -1,-1,-1,  1,-1,-1,  1,-1,1,  -1,-1,1,    // v7-v4-v3-v2
                      1,-1,-1,  -1,-1,-1,  -1,1,-1,  1,1,-1};   // v4-v7-v6-v5

GLfloat colors[] = {1,1,1,  1,1,1,  1,1,1,  1,1,1,              // v0-v1-v2-v3
                    1,1,0,  1,1,0,  1,1,0,  1,1,0,              // v0-v3-v4-v5
                    1,0,1,  1,0,1,  1,0,1,  1,0,1,              // v0-v5-v6-v1
                    0,1,0,  0,1,0,  0,1,0,  0,1,0,              // v1-v6-v7-v2
                    0,1,1,  0,1,1,  0,1,1,  0,1,1,              // v7-v4-v3-v2
                    0,0,1,  0,0,1,  0,0,1,  0,0,1};             // v4-v7-v6-v5

void drawLines(){
	
	//x-line
	glColor3f(1.0,0.0,0.0);
	glBegin(GL_LINES);
	glVertex3f(20.0,0.0,0.0);
	glVertex3f(-20.0,0.0,0.0);
	glEnd();
	
	//y-line
	glColor3f(0.0,1.0,0.0);
	glBegin(GL_LINES);
	glVertex3f(0.0,20.0,0.0);
	glVertex3f(0.0,-20.0,0.0);
	glEnd();
	
	//z-line
	glColor3f(0.0,0.0,1.0);
	glBegin(GL_LINES);
	glVertex3f(0.0,0.0,20.0);
	glVertex3f(0.0,0.0,-20.0);
	glEnd();
}

void myquad(){
	
	glBegin(GL_QUADS);
	glVertex3f(-1.0,1.0,0);
	glVertex3f(1.0,1.0,0);
	glVertex3f(1.0,-1.0,0);
	glVertex3f(-1.0,-1.0,0);
	glEnd();
}

void init(void)
{
 glClearColor (0.0, 0.0, 0.0, 0.0);
 glShadeModel (GL_FLAT);
 glEnable (GL_DEPTH_TEST);  //turn on depth(z-axis) buffer
}

void display(void)
{
 glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
 glRotatef((GLfloat) x_rotation, 1, 0 ,0);
 glRotatef((GLfloat) y_rotation, 0, 1 ,0);
 glRotatef((GLfloat) z_rotation, 0, 0 ,1);
    // enble and specify pointers to vertex arrays
    glEnableClientState(GL_COLOR_ARRAY);
    glEnableClientState(GL_VERTEX_ARRAY);
    glColorPointer(3, GL_FLOAT, 0, colors);
    glVertexPointer(3, GL_FLOAT, 0, vertices);
    glDrawArrays(GL_QUADS, 0, 24);
    glDisableClientState(GL_VERTEX_ARRAY);  // disable vertex arrays
    glDisableClientState(GL_COLOR_ARRAY);
 //-------------------------------------
 glutWireCube(3);
 drawLines();
 
 //Lawn
 glPushMatrix();
 glRotatef(90,1.0,0.0,0.0);
 glTranslatef(0.0,0.0,5.0);
 glScalef(15.0,10.0,0.0);
 glColor3f(0.0,0.7,0.0);
 myquad();
 glPopMatrix();
 
 //Bottom front brown wall  	
 glPushMatrix();
 glTranslatef(-9.5,-2.0,8.0);
 glScalef(5.4,3.0,0.0);
 glColor3f(1.0,0.5,0.0);
 myquad();
 glPopMatrix();
 
 //Top front brown wall  
 glPushMatrix();
 glTranslatef(-4.9,7.0,8.0);
 glScalef(10.0,6.0,0.0);
 glColor3f(1.0,0.5,0.0);
 myquad();
 glPopMatrix();
 
 //Top front glass wall
 glPushMatrix();
 glTranslatef(10.0,6.0,8.0);
 glScalef(5.0,5.5,0.0);
 glColor3f(1.0,1.0,1.0);
 myquad();
 glPopMatrix(); 
 
 //Bottom front glass wall
 glPushMatrix();
 glTranslatef(8.0,-2.0,7.0);
 glScalef(7.0,3.0,0.0);
 glColor3f(1.0,1.0,1.0);
 myquad();
 glPopMatrix();
 
 //Door
 glPushMatrix();
 glTranslatef(-1.5,-2.0,7.0);
 glScalef(2.5,3.0,0.0);
 glColor3f(1.0,0.0,0.0);
 myquad();
 glPopMatrix();
 
 //Columns Posts
 glPushMatrix();
 glTranslatef(4.0,-2.0,8.2);
 glScalef(0.3,3.0,0.0);
 glColor3f(1.5,7.5,0.0);
 myquad();
 glPopMatrix();
 
 glPushMatrix();
 glTranslatef(13.0,-2.0,8.2);
 glScalef(0.3,3.0,0.0);
 glColor3f(1.5,7.5,0.0);
 myquad();
 glPopMatrix();
 
 //Window Lines
 
 //Vertical Bottom glass wall lines
 glPushMatrix();
 glTranslatef(7.0,-2.0,7.1);
 glScalef(0.1,3.0,0.0);
 glColor3f(0.0,0.0,0.0);
 myquad();
 glPopMatrix();
 
 glPushMatrix();
 glTranslatef(11.0,-2.0,7.1);
 glScalef(0.1,3.0,0.0);
 glColor3f(0.0,0.0,0.0);
 myquad();
 glPopMatrix();
 
 //Horizontal Bottom glass wall lines
 glPushMatrix();
 glTranslatef(8.0,-1.0,7.1);
 glScalef(7.0,0.1,0.0);
 glColor3f(0.0,0.0,0.0);
 myquad();
 glPopMatrix();
 
 glPushMatrix();
 glTranslatef(8.0,-3.0,7.1);
 glScalef(7.0,0.1,0.0);
 glColor3f(0.0,0.0,0.0);
 myquad();
 glPopMatrix();
 
 //Vertical upper glass wall lines
 glPushMatrix();
 glTranslatef(10.0,6.0,8.1);
 glScalef(0.1,5.5,0.0);
 glColor3f(0.0,0.0,0.0);
 myquad();
 glPopMatrix();
 
 glPushMatrix();
 glTranslatef(5.0,6.0,8.1);
 glScalef(0.1,5.5,0.0);
 glColor3f(0.0,0.0,0.0);
 myquad();
 glPopMatrix();
 
 glPushMatrix();
 glTranslatef(15.0,6.0,8.1);
 glScalef(0.1,5.5,0.0);
 glColor3f(0.0,0.0,0.0);
 myquad();
 glPopMatrix();
 
 //Horizontal upper glass wall lines
 glPushMatrix();
 glTranslatef(10.0,2.5,8.1);
 glScalef(5.0,0.1,0.0);
 glColor3f(0.0,0.0,0.0);
 myquad();
 glPopMatrix();
 
  glPushMatrix();
 glTranslatef(10.0,5.0,8.1);
 glScalef(5.0,0.1,0.0);
 glColor3f(0.0,0.0,0.0);
 myquad();
 glPopMatrix();
 
  glPushMatrix();
 glTranslatef(10.0,7.5,8.1);
 glScalef(5.0,0.1,0.0);
 glColor3f(0.0,0.0,0.0);
 myquad();
 glPopMatrix();
 
  glPushMatrix();
 glTranslatef(10.0,10.0,8.1);
 glScalef(5.0,0.1,0.0);
 glColor3f(0.0,0.0,0.0);
 myquad();
 glPopMatrix();
 /*
  glPushMatrix();
 glTranslatef(10.0,0.5,8.1);
 glScalef(5.0,0.1,0.0);
 glColor3f(0.0,0.0,0.0);
 myquad();
 glPopMatrix(); */
 
 //Inner side wall near door
 glPushMatrix();
 glRotatef(90,0.0,1.0,0.0);
 glTranslatef(-7.0,-2.0,-4.3);
 glScalef(1.0,3.0,0.0);
 glColor3f(1.0,0.5,0.0);
 myquad();
 glPopMatrix();
 
 //Inner ceiling for door and front glass
 glPushMatrix();
 glRotatef(90,1.0,0.0,0.0);
 glTranslatef(5.8,7.0,-1.0);
 glScalef(9.0,1.0,0.0);
 glColor3f(0.0,0.0, 0.0);
 myquad();
 glPopMatrix();
 
 glutSwapBuffers();    //instead of using GLflush you're swapping buffers
}

void reshape(int w, int h)
{
     glViewport(0,0, (GLsizei)w, (GLsizei)h);
     glMatrixMode(GL_PROJECTION);
     glLoadIdentity();
     gluPerspective (60, (GLfloat)w / (GLfloat)h, 1.0, 200.0);
     glMatrixMode(GL_MODELVIEW);    
     glLoadIdentity(); //clear the main matrix
     gluLookAt(20,20,15,0,0,0,0,1,0); //controls the position of camera, the 1st 3 values defines the position,
                                      //second 3 values is where the camera is looking at
                                      //marks where up is, in this case y is where up is, usually the y.
 }
 
void keyboard (unsigned char key, int x, int y)
{
    switch (key) 
     {
    case 'x':
    x_rotation = 15;
    y_rotation = 0;
    z_rotation = 0;
    glutPostRedisplay();
    break;
    case 'y':
    y_rotation = 15;
    x_rotation = 0;
    z_rotation = 0;
    glutPostRedisplay();
    break;
    case 'z':
    z_rotation = 15;	
    x_rotation = 0;
    y_rotation = 0;
    glutPostRedisplay();
    break;
    default:
    break;
    }
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize (1000, 600);
    glutInitWindowPosition (100, 100);
    glutCreateWindow ("A-Team --- UG Innovation Centre");
    init ();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    glutMainLoop();
    return 0;
}
