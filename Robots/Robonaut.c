#include <stdio.h>
#include <stdarg.h>
#include <gl\glut.h>
#include <GL/glut.h>
#include <math.h>
#include <stdarg.h>

static int x_rotation = 0, y_rotation = 0,  z_rotation = 0;
const float DEG2RAD = 3.14159/180;	

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
void drawCube(){
 glEnableClientState(GL_VERTEX_ARRAY);
 glColorPointer(3, GL_FLOAT, 0, colors);
 glVertexPointer(3, GL_FLOAT, 0, vertices);
 glDrawArrays(GL_QUADS, 0, 24);
}

void drawLines() {
	//x-line
	glColor3f(1.0,0.0,0.0); //red
	glBegin(GL_LINES);
	glVertex3f(10.0, 0.0,0.0);
	glVertex3f(-10.0, 0.0,0.0);
	glEnd();
	
	//y-line
	glColor3f(0.0,1.0,0.0); //green
	glBegin(GL_LINES);
	glVertex3f(0.0,10.0,0.0);
	glVertex3f(0.0,-10.0,0.0);
	glEnd();
	
	//z-line
	glColor3f(0.0,0.0,1.0); //blue
	glBegin(GL_LINES);
	glVertex3f(0.0,0.0,10.0);
	glVertex3f(0.0,0.0,-10.0);
	glEnd();
}

void myquad(){
	//implement scale function
	glBegin(GL_QUADS);
	glVertex3f(-1.0,1.0,0.0);
	glVertex3f(1.0,1.0,0.0);
	glVertex3f(1.0,-1.0,0.0);
	glVertex3f(-1.0,-1.0,0.0);
	glEnd();
}

void optimizedquad(float x, float y, float z){
	glScalef(x, y, z);
	myquad();
}

void init(void)
{
 glClearColor (0.0, 0.0, 0.0, 0.0);
 glShadeModel (GL_FLAT);
 glEnable (GL_DEPTH_TEST); // depth 
}

void display(void)
{
 glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
 glRotatef((GLfloat) x_rotation, 1, 0 ,0);
 glRotatef((GLfloat) y_rotation, 0, 1 ,0);
 glRotatef((GLfloat) z_rotation, 0, 0 ,1);
 
 drawLines();
 
  //Lawn
 glPushMatrix();
 glRotatef(90,1.0,0.0,0.0);
 glTranslatef(0.0,0.0,7.0);
 glScalef(20.0,20.0,0.0);
 glColor3f(0.0,0.7,0.0);
 myquad();
 glPopMatrix();
 
  //Left foot
 glPushMatrix();
 glTranslatef(0.0,0.0,-0.5);
 glScalef(1.0,1.0,2.0);
 //glRotatef(angle,1.0,0.0,0.0);
 glColor3f(0.0,0.0,0.0);
 drawCube();
 glPopMatrix();
 
 //Right foot
 glPushMatrix();
 glTranslatef(5.0,0.0,-0.5);
 glScalef(1.0,1.0,2.0);
 glColor3f(0.0,0.0,0.0);
 drawCube();
 glPopMatrix();
 
 //Left Leg
 glPushMatrix();
 glTranslatef(0.0,3.0,-1.3);
 glScalef(1.0,2.0,1.0);
 glColor3f(0.5,0.5,0.5);
 drawCube();
 glPopMatrix();
 
  //Right Leg
 glPushMatrix();
 glTranslatef(5.0,3.0,-1.3);
 glScalef(1.0,2.0,1.0);
 glColor3f(0.5,0.5,0.5);
 drawCube();
 glPopMatrix();
 
  //Gray Base
 glPushMatrix();
 glTranslatef(2.5,5.5,-1.3);
 glScalef(3.5,0.7,1.0);
 glColor3f(0.5,0.5,0.5);
 drawCube();
 glPopMatrix();
 
 //Black Base
 glPushMatrix();
 glTranslatef(2.5,6.9,-1.3);
 glScalef(3.5,0.7,1.0);
 glColor3f(0.0,0.0,0.0);
 drawCube();
 glPopMatrix();
 
  //Body
 glPushMatrix();
 glTranslatef(2.5,10.5,-1.3);
 glScalef(3.5,2.5,2.0);
 glColor3f(1.9,0.9,0.9);
 drawCube();
 glPopMatrix();
 
 //Body Center
 glPushMatrix();
 glTranslatef(2.5,11.3,1.0);
 glScalef(2.0,1.5,1.0);
 glColor3f(0.5,0.5,0.5);
 drawCube();
 glPopMatrix();
 
 //Outline
 glPushMatrix();
 glTranslatef(1.2,7.9,1.3);
 glScalef(0.5,2.0,0.5);
 glColor3f(0.8,0.8,0.8);
 drawCube();
 glPopMatrix();
 
 glPushMatrix();
 glTranslatef(3.8,7.9,1.3);
 glScalef(0.5,2.0,0.5);
 glColor3f(0.8,0.8,0.8);
 drawCube();
 glPopMatrix();
 
 glPushMatrix();
 glTranslatef(-0.3,5.5,1.3);
 glScalef(2.0,0.5,0.5);
 glColor3f(0.8,0.8,0.8);
 drawCube();
 glPopMatrix();
 
 glPushMatrix();
 glTranslatef(5.3,5.5,1.3);
 glScalef(2.0,0.5,0.5);
 glColor3f(0.8,0.8,0.8);
 drawCube();
 glPopMatrix();
 
 glPushMatrix();
 glTranslatef(7.0,5.5,-0.2);
 glScalef(0.5,0.5,2.0);
 glColor3f(0.8,0.8,0.8);
 drawCube();
 glPopMatrix();
 
 glPushMatrix();
 glTranslatef(-2.0,5.5,-0.2);
 glScalef(0.5,0.5,2.0);
 glColor3f(0.8,0.8,0.8);
 drawCube();
 glPopMatrix();
 
 //Right Hand
 glPushMatrix();
 glTranslatef(7.0,12.0,-1.3);
 glScalef(1.0,1.0,1.0);
 glColor3f(1.9,0.9,0.9);
 drawCube();
 glPopMatrix();
 
 glPushMatrix();
 glTranslatef(7.1,9.7,-1.3);
 glScalef(0.9,1.2,0.9);
 glColor3f(0.5,0.5,0.5);
 drawCube();
 glPopMatrix();
 
 glPushMatrix();
 glTranslatef(7.1,7.6,-1.3);
 glScalef(0.9,0.9,0.9);
 glColor3f(0.0,0.0,0.0);
 drawCube();
 glPopMatrix(); 
 
  //Left Hand
 glPushMatrix();
 glTranslatef(-2.0,12.0,-1.3);
 glScalef(1.0,1.0,1.0);
 glColor3f(1.9,0.9,0.9);
 drawCube();
 glPopMatrix();
 
 glPushMatrix();
 glTranslatef(-2.1,9.7,-1.3);
 glScalef(0.9,1.2,0.9);
 glColor3f(0.5,0.5,0.5);
 drawCube();
 glPopMatrix();
 
 glPushMatrix();
 glTranslatef(-2.1,7.6,-1.3);
 glScalef(0.9,0.9,0.9);
 glColor3f(0.0,0.0,0.0);
 drawCube();
 glPopMatrix();
 
 //Head
 glPushMatrix();
 glTranslatef(2.5,15.5,-2.0);
 glScalef(3.5,2.5,0.7);
 glColor3f(1.9,0.9,0.9);
 drawCube();
 glPopMatrix();
 
 glPushMatrix();
 glTranslatef(2.5,15.7,-1.0);
 glScalef(2.1,2.3,0.2);
 glColor3f(0.0,0.0,0.0);
 drawCube();
 glPopMatrix();
 
 //Face
 glPushMatrix();
 glTranslatef(2.5,15.8,-0.8);
 glScalef(2.0,2.0,1.0);
 glColor3f(0.6,0.7,0.7);
 drawCube();
 glPopMatrix();
 
 //Back
 glPushMatrix();
 glTranslatef(2.5,15.0,-3.7);
 glScalef(4.3,3.0,0.7);
 glColor3f(0.5, 0.5, 0.5);
 drawCube();
 glPopMatrix();
 
 //Back
 glPushMatrix();
 glTranslatef(0.0,14.0,-1.0);
 glScalef(0.5, 0.5, 0.5);
 glColor3f(0.5,0.5,0.5);
 drawCube();
 glPopMatrix();
 
 glutSwapBuffers(); // frame butters to be putted out ... not using glFlush 
 
}


void reshape(int w, int h)
{
     glViewport(0,0, (GLsizei)w, (GLsizei)h);
     glMatrixMode(GL_PROJECTION);
     glLoadIdentity();
     gluPerspective (60, (GLfloat)w / (GLfloat)h, 1.0, 200.0);
     glMatrixMode(GL_MODELVIEW);    
     glLoadIdentity(); //clear the main matrix
     gluLookAt(25,25,25,0,0,0,0,1,0); /*control position of camera --- first 3 position is where the position of the camera 
	 --- second three values is where the camera is looking at --- third three values in this case saying the y axis marks up */
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
    y_rotation = 0;
    x_rotation = 0;
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
    glutCreateWindow ("Robonaut");
    init ();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    glutMainLoop();
    return 0;
}
