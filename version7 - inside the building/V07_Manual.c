///////////////////////////////////////////////////////////////////////////////
// A-Team Project --- UG Innovation Center
// University of Guyana
// Department of Computer Science
///////////////////////////////////////////////////////////////////////////////

#include <stdlib.h>
#include <float.h>
#include <time.h>	
#include <stdio.h>
#include <GL/glut.h>
#include <math.h>
#include <stdarg.h>
#include "braavabot.c"
#include "karenbot.c"
#include "mega.c"
#include "outside.c"

static int x_rotation = 0, y_rotation = 0,  z_rotation = 0;
static GLfloat theta[] = {0.0,0.0,0.0};
static GLint axis = 1;

//Keyboard Variable
float angle=0.0;
float r=1.0,g=0.0,bl=0.0,a=0,b=0;
float x=0.0f,y=1.75f,z=5.0f; //camera viewpoint
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

               
void drawCube(){
 glEnableClientState(GL_VERTEX_ARRAY);
 glColorPointer(3, GL_FLOAT, 0, colors);
 glVertexPointer(3, GL_FLOAT, 0, vertices);
 glDrawArrays(GL_QUADS, 0, 24);
}

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

//Text output Method 
void show_name(GLfloat x, GLfloat y, char *format,...)
{
  va_list args;
  char buffer[200], *p;

  va_start(args, format);
  vsprintf(buffer, format, args);
  va_end(args);
  glPushMatrix();
  glTranslatef(x, y, 0);
  glScalef(0.004, 0.0041, 0.004);
  for (p = buffer; *p; p++)
    glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN, *p);
  glPopMatrix();
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
  glScalef(0.009, 0.0091, 0.009);
  for (p = buffer; *p; p++)
    glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN, *p);
  glPopMatrix();
}

void wheels(){
	//Wheels
    float x1,y1,x2,y2;
	float angle;
	double radius=1.0;

	x1 = 0,y1=0;
	glColor3f(0.0,0.0,0.0);

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

void display(void)
{
 glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
 glRotatef((GLfloat) x_rotation, 1, 0 ,0);
 glRotatef((GLfloat) y_rotation, 0, 1 ,0);
 glRotatef((GLfloat) z_rotation, 0, 0 ,1); 
 	
drawLines(); 

//Floor
 glPushMatrix();
 glRotatef(90,1.0,0.0,0.0);
 glTranslatef(0.0,0.0,5.0);
 glScalef(50.0,30.0,0.0);
 glColor3f(0.3,0.1,0.1);
 myquad();
 glPopMatrix();
 
 //Left Side Wall
 glPushMatrix();
 glRotatef(90,0.0,1.0,0.0);
 glTranslatef(0.0,10.0,-50.0);
 glColor3f(0.7,0.9,0.8);
 glScalef(30.0,15.0,0.0);
 myquad();
 glPopMatrix();
 
 //Back wall
 glPushMatrix();
 glTranslatef(0.0,10.0,-30.0);
 glColor3f(0.7,0.9,1.0);
 glScalef(50.0,15.0,0.0);
 myquad();
 glPopMatrix();

 //Right Side Wall
 glPushMatrix();
 glRotatef(90,0.0,1.0,0.0);
 glTranslatef(0.0,10.0,50.0);
 glColor3f(0.7,0.9,0.8);
 glScalef(30.0,15.0,0.0);
 myquad();
 glPopMatrix(); 

/* 
 //Label
 glPushMatrix();
 glColor3f(0, 0, 0);
 glTranslatef(-4.9,7.0,8.1);   
 show_label(-5, 0, "UG Innovation Center");    
 glPopMatrix(); 
*/
//Braava Bot
 glPushMatrix();
 glTranslatef(0.0, -2.0, -15.0);
 braavabot();
 glPopMatrix(); 
 
 //Karen Bot
 glPushMatrix();
 glTranslatef(-20.0, 1.0, -15.0);
 karenbot();
 glPopMatrix();
 
 //Mega Bot
 glPushMatrix();
 glTranslatef(20.0, -4.0, -15.0);
 mega();
 glPopMatrix();
 
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


//Movement Function 1
void orientMe(float ang) {
	lx = sin(ang);
	lz = -cos(ang);
	glLoadIdentity();
	gluLookAt(x, y, z, 
		      x + lx,y + ly,z + lz,
			  0.0f,1.0f,0.0f);
}
/*
//Movement Function 2
void moveMeFlat(int i) {
	x = x + i*(lx)*0.1;
	z = z + i*(lz)*0.1;
	glLoadIdentity();
	gluLookAt(x, y, z, 
		      x + lx,y + ly,z + lz,
			  0.0f,1.0f,0.0f);
}
*/
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
    
    /*
	case 'u':
	moveMeFlat(10);
    glutPostRedisplay();
    break;
    case 'd':
	moveMeFlat(10);
    glutPostRedisplay();
    break;
    */	case 'o': //in
	moveside(-5);
    glutPostRedisplay();
    break;
    	case 'i': //out
	moveside(5);
    glutPostRedisplay();
    break;
    
    case 'r':
    angle += 0.025;
    orientMe(angle);
    glutPostRedisplay();
    break;
    
    case 'l':
    angle -= 0.025;
    orientMe(angle);
    glutPostRedisplay();
    break;
    
    case 'e':
    outside();
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
    //glutIdleFunc(spinObj);
    glutMainLoop();
    return 0;
}

