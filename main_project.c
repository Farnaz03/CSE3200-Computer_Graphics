///////////////////////////////////////////////////////////////////////////////
// A-Team Project --- UG Innovation Center
// University of Guyana
// Department of Computer Science
///////////////////////////////////////////////////////////////////////////////
	
#include <stdio.h>
#include <stdarg.h>
#include <gl\glut.h>
#include <GL/glut.h>
#include <math.h>
#include <stdarg.h>
#include "robotgallery.h"

static int x_rotation = 0, y_rotation = 0,  z_rotation = 0;
// vertex coords array
static GLfloat theta[] = {0.0,0.0,0.0};
static GLint axis = 1;

//Keyboard Variable
float angle=0.0;
float r=1.0,g=0.0,bl=0.0,a=0,b=0;
float x=0.0f,y=1.75f,z=5.0f;
float lx=0.0f,ly=0.0f,lz=-1.0f;
float ratio=1.0;

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
 glEnable (GL_DEPTH_TEST);  //turn on depth(z-axis) buffer
}

//Movement Function
void moveMeFlat(int i) {
	x = x + i*(lx)*0.1;
	z = z + i*(lz)*0.1;
	glLoadIdentity();
	gluLookAt(x, y, z, 
		      x + lx,y + ly,z + lz,
			  0.0f,1.0f,0.0f);
}
void moveside(int i) {
	x = x + i*(lx)*0.5;
	z = z + i*(lz)*0.5;
	glLoadIdentity();
	gluLookAt(x, y, z, 
		      x + lx,y + ly,z + lz,
			  0.0f,1.0f,0.0f);
}
//Keyboard Function
void keyboard (unsigned char key, int x, int y)
{
    switch (key) 
     {
    case 'x':
    axis =0;
    glutPostRedisplay();
    break;
    case 'y':
    axis = 1;
    glutPostRedisplay();
    break;
    case 'z':
    axis = 2;
    glutPostRedisplay();
    break;
    
    case 'o': //in
	moveside(-10);
    glutPostRedisplay();
    break;
    case 'i': //out
	moveside(10);
    glutPostRedisplay();
    break;
    
    case 'e':
    room();
    glutPostRedisplay();
    break;
    
    default:
    break;
    }
}

//Animation or Rotation
void spinObj() {
	theta[axis] +=0.05;
	if(theta[axis] > 360.0) theta[axis] -= 360.0;
	glutPostRedisplay();
}

//Text output Method 
void show_label(GLfloat x, GLfloat y, char *format,...)
{
  va_list args;
  char buffer[200], *p;

  va_start(args, format);
  vsprintf(buffer, format, args);
  va_end(args);
  glPushMatrix();
  glTranslatef(x, y, 0);
  glScalef(0.006, 0.006, 0.006);
  for (p = buffer; *p; p++)
    glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN, *p);
  glPopMatrix();
}

void display(void)
{
 glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
 /*glRotatef((GLfloat) x_rotation, 1, 0 ,0);
 glRotatef((GLfloat) y_rotation, 0, 1 ,0);
 glRotatef((GLfloat) z_rotation, 0, 0 ,1); */
 	glLoadIdentity();
 	gluLookAt(20,20,20,0,0,0,0,1,0);
 	
 	glRotatef(theta[0], 1.0, 0.0, 0.0);
 	glRotatef(theta[1], 0.0, 1.0, 0.0);
 	glRotatef(theta[2], 0.0, 0.0, 1.0);
   /* // enble and specify pointers to vertex arrays
    glEnableClientState(GL_COLOR_ARRAY);
    glEnableClientState(GL_VERTEX_ARRAY);
    glColorPointer(3, GL_FLOAT, 0, colors);
    glVertexPointer(3, GL_FLOAT, 0, vertices);
    glDrawArrays(GL_QUADS, 0, 24);
    glDisableClientState(GL_VERTEX_ARRAY);  // disable vertex arrays
    glDisableClientState(GL_COLOR_ARRAY); */
 //-------------------------------------
 //glutWireCube(3);
 drawLines(); 
 
//Lawn
 glPushMatrix();
 glRotatef(90,1.0,0.0,0.0);
 glTranslatef(0.0,0.0,5.0);
 glScalef(18.0,10.0,0.0);
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
 glScalef(5.0,5.5,10.0);
 glColor3f(1.0,1.0,1.0);
 myquad();
 glPopMatrix(); 
 
//Bottom front glass wall
 glPushMatrix();
 glTranslatef(8.0,-2.0,7.0);
 glColor3f(1.0,1.0,1.0);
 optimizedquad(7.0,3.0,0.0);
 glPopMatrix(); 
 
//Door
 glPushMatrix();
 glTranslatef(-1.7,-2.0,7.0);
 glColor3f(0.6,0.3,0.17);
 optimizedquad(2.7,3.0,0.0);
 glPopMatrix();  
 
//Columns Posts
 glPushMatrix();
 glTranslatef(4.0,-2.0,8.2);
 glColor3f(0.6,0.3,0.17);
 optimizedquad(0.3,3.0,0.0);
 glPopMatrix(); 
 
 glPushMatrix();
 glTranslatef(13.0,-2.3,8.2);
 glColor3f(0.6,0.3,0.17);
 optimizedquad(0.3,2.7,0.0);
 glPopMatrix(); 
 
//Window Lines for front walls
//Vertical Bottom glass wall lines
 glPushMatrix();
 glTranslatef(8.0,-2.0,7.1);
 glColor3f(0.0,0.0,0.0);
 optimizedquad(0.1,3.0,0.0);
 glPopMatrix();
 
 glPushMatrix();
 glTranslatef(12.0,-2.0,7.1);
 glColor3f(0.0,0.0,0.0);
 optimizedquad(0.1,3.0,0.0);
 glPopMatrix();
 
//Horizontal Bottom glass wall lines
 glPushMatrix();
 glTranslatef(8.0,-1.0,7.1);
 glColor3f(0.0,0.0,0.0);
 optimizedquad(7.0,0.1,0.0);
 glPopMatrix();
 
 glPushMatrix();
 glTranslatef(8.0,-3.0,7.1);
 glColor3f(0.0,0.0,0.0);
 optimizedquad(7.0,0.1,0.0);
 glPopMatrix();
	 
//Vertical upper glass wall lines
 glPushMatrix();
 glTranslatef(10.0,6.0,8.1);
 glColor3f(0.0,0.0,0.0);
 optimizedquad(0.1,5.5,0.0);
 glPopMatrix();
	 
 glPushMatrix();
 glTranslatef(5.0,6.0,8.1);
 glColor3f(0.0,0.0,0.0);
 optimizedquad(0.1,5.5,0.0);
 glPopMatrix();
	 
 glPushMatrix();
 glTranslatef(14.0,6.0,8.1);
 glColor3f(0.0,0.0,0.0);
 optimizedquad(0.1,5.5,0.0);
 glPopMatrix();
	 
//Horizontal upper glass wall lines
 glPushMatrix();
 glTranslatef(10.0,2.5,8.1);
 glColor3f(0.0,0.0,0.0);
 optimizedquad(5.0,0.1,0.0);
 glPopMatrix();
	 
 glPushMatrix();
 glTranslatef(10.0,5.0,8.1);
 glColor3f(0.0,0.0,0.0);
 optimizedquad(5.0,0.1,0.0);
 glPopMatrix();
	 
 glPushMatrix();
 glTranslatef(10.0,7.5,8.1);
 glColor3f(0.0,0.0,0.0);
 optimizedquad(5.0,0.1,0.0);
 glPopMatrix();
	 
 glPushMatrix();
 glTranslatef(10.0,10.0,8.1);
 glColor3f(0.0,0.0,0.0);
 optimizedquad(5.0,0.1,0.0);
 glPopMatrix();

 
 glPushMatrix();
 glTranslatef(10.0,0.5,8.1);
 glColor3f(0.0,0.0,0.0);
 optimizedquad(5.0,0.1,0.0);
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
 glColor3f(1.0,0.6,0.0);
 optimizedquad(1.0,3.0,0.0);
 glPopMatrix();
 
//Inner ceiling for door and brown front
 glPushMatrix();
 glRotatef(90,1.0,0.0,0.0);
 glTranslatef(0,7.0,-1.0);
 glColor3f(1.0,0.65,0.0);
 optimizedquad(5.0,1.0,0.0);
 glPopMatrix();
 
//Inner ceiling for front glass
 glPushMatrix();
 glRotatef(90,1.0,0.0,0.0);
 glTranslatef(10,7.1,-0.5);
 glColor3f(0.9,0.9,0.9);
 optimizedquad(4.92,1.0,0.0);
 glPopMatrix();
	 
//Right Side - Upper Wall 
 glPushMatrix();
 glRotatef(90,0.0,1.0,0.0);
 glTranslatef(0.0,6.0,14.9);
 //glScalef(8.0,5.5,0.0);
 glColor3f(1.0,1.0,1.0);
 optimizedquad(8.0,5.5,0.0);
 glPopMatrix(); 
 
//Window Lines for Right Side - Upper glass wall
//Horizontal lines
 glPushMatrix();
 glRotatef(90,0.0,1.0,0.0);
 glTranslatef(0.0,10.0,15.0);
 glColor3f(0.0,0.0,0.0);
 optimizedquad(8.0,0.1,0.0);
 glPopMatrix();

 glPushMatrix();
 glRotatef(90,0.0,1.0,0.0);
 glTranslatef(0.0,7.5,15.0);
 glColor3f(0.0,0.0,0.0);
 optimizedquad(8.0,0.1,0.0);
 glPopMatrix();
 
 glPushMatrix();
 glRotatef(90,0.0,1.0,0.0);
 glTranslatef(0.0,5.0,15.0);
 glColor3f(0.0,0.0,0.0);
 optimizedquad(8.0,0.1,0.0);
 glPopMatrix(); 
 
 glPushMatrix();
 glRotatef(90,0.0,1.0,0.0);
 glTranslatef(0.0,2.5,15.0);
 glColor3f(0.0,0.0,0.0);
 optimizedquad(8.0,0.1,0.0);
 glPopMatrix(); 
 
 //Vertical windows lines - Right side glass wall
 glPushMatrix();
 glRotatef(90,0.0,1.0,0.0);
 glTranslatef(-7.0,3.2,15.0);
 glColor3f(0.0,0.0,0.0);
 optimizedquad(0.1,8.2,0.0);
 glPopMatrix(); 
 
 glPushMatrix();
 glRotatef(90,0.0,1.0,0.0);
 glTranslatef(-3.0,3.2,15.0);
 glColor3f(0.0,0.0,0.0);
 optimizedquad(0.1,8.2,0.0);
 glPopMatrix();

 glPushMatrix();
 glRotatef(90,0.0,1.0,0.0);
 glTranslatef(2.0,3.2,15.0);
 glColor3f(0.0,0.0,0.0);
 optimizedquad(0.1,8.2,0.0);
 glPopMatrix();
 
 glPushMatrix();
 glRotatef(90,0.0,1.0,0.0);
 glTranslatef(7.0,3.2,15.0);
 glColor3f(0.0,0.0,0.0);
 optimizedquad(0.1,8.2,0.0);
 glPopMatrix();
 
//Right Side - Lower Wall
 glPushMatrix();
 glRotatef(90,0.0,1.0,0.0);
 glTranslatef(0.5,-2.0,14.9);
 glColor3f(1.0,1.0,1.0);
 optimizedquad(7.5,3.0,0.0);
 glPopMatrix(); 
 
 //Window Lines for Right Side - Lower glass wall
//Horizontal lines
 glPushMatrix();
 glRotatef(90,0.0,1.0,0.0);
 glTranslatef(0.5,0.0,15.0);
 glColor3f(0.0,0.0,0.0);
 optimizedquad(7.5,0.1,0.0);
 glPopMatrix();
 
 glPushMatrix();
 glRotatef(90,0.0,1.0,0.0);
 glTranslatef(0.5,-2.5,15.0);
 glColor3f(0.0,0.0,0.0);
 optimizedquad(7.5,0.1,0.0);
 glPopMatrix();
 
 
//Left Side Wall
 glPushMatrix();
 glRotatef(90,0.0,1.0,0.0);
 glTranslatef(0.0,4.0,-14.9);
 glColor3f(1.0,0.5,0.0);
 optimizedquad(8.0,9.0,0.0);
 glPopMatrix(); 
 
//Back brown wall  
 glPushMatrix();
 glTranslatef(-4.9,4.0,-8.0);
 glColor3f(1.0,0.5,0.0);
 optimizedquad(10.0,9.0,0.0);
 glPopMatrix();
	 
//Back glass wall
 glPushMatrix();
 glTranslatef(10.0,3.3,-8.0);
 glColor3f(1.0,1.0,1.0);
 optimizedquad(5.0,8.2,0.0);
 glPopMatrix();
 
//Window Lines for back glass walls

//Vertical upper glass wall lines
 glPushMatrix();
 glTranslatef(10.0,3.2,-8.1);
 glColor3f(0.0,0.0,0.0);
 optimizedquad(0.1,8.2,0.0);
 glPopMatrix();
 
 glPushMatrix();
 glTranslatef(5.0,3.2,-8.1);
 glColor3f(0.0,0.0,0.0);
 optimizedquad(0.1,8.2,0.0);
 glPopMatrix();
	 
 glPushMatrix();
 glTranslatef(14.0,3.2,-8.1);
 glColor3f(0.0,0.0,0.0);
 optimizedquad(0.1,8.2,0.0);
 glPopMatrix();
 
 
 //Horizontal upper glass wall lines
 glPushMatrix();
 glTranslatef(10.0,-2.5,-8.1);
 glColor3f(0.0,0.0,0.0);
 optimizedquad(5.0,0.1,0.0);
 glPopMatrix();
 
 glPushMatrix();
 glTranslatef(10.0,0.0,-8.1);
 glColor3f(0.0,0.0,0.0);
 optimizedquad(5.0,0.1,0.0);
 glPopMatrix();
 
 //Horizontal upper glass wall lines
 glPushMatrix();
 glTranslatef(10.0,2.5,-8.1);
 glColor3f(0.0,0.0,0.0);
 optimizedquad(5.0,0.1,0.0);
 glPopMatrix();
	 
 glPushMatrix();
 glTranslatef(10.0,5.0,-8.1);
 glColor3f(0.0,0.0,0.0);
 optimizedquad(5.0,0.1,0.0);
 glPopMatrix();
	 
 glPushMatrix();
 glTranslatef(10.0,7.5,-8.1);
 glColor3f(0.0,0.0,0.0);
 optimizedquad(5.0,0.1,0.0);
 glPopMatrix();
	 
 glPushMatrix();
 glTranslatef(10.0,10.0,-8.1);
 glColor3f(0.0,0.0,0.0);
 optimizedquad(5.0,0.1,0.0);
 glPopMatrix();


 //Top glass roof
 glPushMatrix();
 glRotatef(90,1.0,0.0,0.0);
 glTranslatef(10.0,0.0,-11.5);
 glColor3f(1.0,1.0,1.0);
 optimizedquad(5.0,8.0,0.0);
 glPopMatrix();

 //Top Concrete roof
 glPushMatrix();
 glRotatef(90,1.0,0.0,0.0);
 glTranslatef(-5.0,0.0,-11.5);
 glColor3f(0.9,0.5,0.0);
 optimizedquad(9.9,8.0,0.0);
 glPopMatrix();
 
 
 //Label
 glPushMatrix();
 glColor3f(0, 0, 0);
 glTranslatef(-4.9,7.0,8.1);   
 show_label(-5, 0, "UG Innovation Center");    
 glPopMatrix(); 
 
 /*
 glPushMatrix();
 room();
 glPopMatrix();
 */
 glutSwapBuffers();    //instead of using GLflush you're swapping buffers
}
	
void reshape(int w, int h)
{
     glViewport(0,0, (GLsizei)w, (GLsizei)h);
     glMatrixMode(GL_PROJECTION);
     glLoadIdentity();
     gluPerspective (80, (GLfloat)w / (GLfloat)h, 1.0, 200.0);
     glMatrixMode(GL_MODELVIEW);    
     glLoadIdentity(); //clear the main matrix
     gluLookAt(20,20,20,0,0,0,0,1,0); //controls the position of camera, the 1st 3 values defines the position,
                                      //second 3 values is where the camera is looking at
                                      //marks where up is, in this case y is where up is, usually the y.
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
    glutIdleFunc(spinObj);
    glutMainLoop();
    return 0;
}
