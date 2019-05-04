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

void wheels(){
	//Wheels
    float x1,y1,x2,y2;
	float angle;
	double radius=1.5;

	x1 = 0,y1=0;
	glColor3f(0.6,0.6,0.6);

	glBegin(GL_TRIANGLE_FAN);
	glVertex2f(x1,y1);
	for (angle=1.0f;angle<360.0f;angle+=0.2)
	{
		x2 = x1+sin(angle)*radius;
		y2 = y1+cos(angle)*radius;
		glVertex2f(x2,y2);
		glRotatef(angle,1.0,0.0,0.0);
	}
	glEnd();
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
 
  //Head
 glPushMatrix();
 glTranslatef(0.0,10.0,0.0);
 glScalef(4,3,2);
 //glRotatef(angle,1.0,0.0,0.0);
 glColor3f(1.0,0.0,0.0);
 glEnableClientState(GL_VERTEX_ARRAY);
 glColorPointer(3, GL_FLOAT, 0, colors);
 glVertexPointer(3, GL_FLOAT, 0, vertices);
 glDrawArrays(GL_QUADS, 0, 24);
 //myquad();
 glDisableClientState(GL_VERTEX_ARRAY); 
 glDisableClientState(GL_COLOR_ARRAY);
 glPopMatrix();
 
  //Screen
 glPushMatrix();
// glRotatef(90,1.0,0.0,0.0);
 glTranslatef(0.0,10.0,2.1);
 glScalef(3.0,2.0,0.5);
 glColor3f(1.0,1.0,1.0);
 myquad();
 glPopMatrix();
 
 //Neck
 glPushMatrix();
 glTranslatef(0.0,2.0,0.0);
 glScalef(0.5,5.0,0.5);
 //glRotatef(angle,1.0,0.0,0.0);
 glColor3f(1.0,0.0,0.0);
 glEnableClientState(GL_VERTEX_ARRAY);
 glColorPointer(3, GL_FLOAT, 0, colors);
 glVertexPointer(3, GL_FLOAT, 0, vertices);
 glDrawArrays(GL_QUADS, 0, 24);
 glDisableClientState(GL_VERTEX_ARRAY);  
 glDisableClientState(GL_COLOR_ARRAY);
 
 glPopMatrix();
 
  //Base
 glPushMatrix();
 glTranslatef(0.0,-4.0,0.0);
 glScalef(5.0,1.0,5.0);
 //glRotatef(angle,1.0,0.0,0.0);
 glColor3f(1.0,1.0,0.0);
 glEnableClientState(GL_VERTEX_ARRAY);
 glColorPointer(3, GL_FLOAT, 0, colors);
 glVertexPointer(3, GL_FLOAT, 0, vertices);
 glDrawArrays(GL_QUADS, 0, 24);
 glDisableClientState(GL_VERTEX_ARRAY);
 glDisableClientState(GL_COLOR_ARRAY);
 glPopMatrix();
 
 int wheelloop;
 for(wheelloop = 1; wheelloop < 7; wheelloop++){
 float xvalue = 5 + (0.1*wheelloop);
 //Right-side Front wheel
 glPushMatrix();
 glTranslatef(xvalue,0,0);
 glTranslatef(0,-5,0);
 glTranslatef(0,0,3.5);
 glRotatef(90,0,1,0);
 wheels();
 glPopMatrix();
 
 //Right-side Back wheel
 glPushMatrix();
 glTranslatef(xvalue,0,0);
 glTranslatef(0,-5,-7);
 glTranslatef(0,0,3.5);
 glRotatef(90,0,1,0);
 wheels();
 glPopMatrix();
 
 //Left-side Back wheel
 glPushMatrix();
 glTranslatef(xvalue,0,0);
 glTranslatef(-10.5,-5,-7);
 glTranslatef(0,0,3.5);
 glRotatef(90,0,1,0);
 wheels();
 glPopMatrix();
 
 //Left-side Front wheel
 glPushMatrix();
 glTranslatef(xvalue,0,0);
 glTranslatef(-10.5,-5,0);
 glTranslatef(0,0,3.5);
 glRotatef(90,0,1,0);
 wheels();
 glPopMatrix();
}
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
     gluLookAt(20,20,20,0,0,0,0,1,0); /*control position of camera --- first 3 position is where the position of the camera 
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
    glutCreateWindow ("Karen Robot");
    init ();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    glutMainLoop();
    return 0;
}
