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

//#include "innovbuilding.c"
#include "buildings.c"
//#include "robotgallery.c"

#include "braavabot.c"
#include "karenbot.c"
#include "mega.c"
//#include "outside.c"

static int x_rotation = 0, y_rotation = 0,  z_rotation = 0;
// vertex coords array
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
/*
GLuint makeaTree;
//float x,y,z;

void makeCylinder(float height, float base){
GLUquadric *obj = gluNewQuadric();
//gluQuadricDrawStyle(obj, GLU_LINE);
//glColor3f(0.64f, 0.16, 0.16f);
glColor3f(0.0,0.2,0.0);
glPushMatrix();
glRotatef(-90, 1.0,0.0,0.0);
gluCylinder(obj, base,base-(0.2*base), height, 20,20);
glPopMatrix();
glutSwapBuffers();
}

void makeTree(float height, float base){

float angle;
makeCylinder(height, base); glTranslatef(0.0, height, 0.0);
height -= height*.2; base-= base*0.3;
int a;
for(a= 0; a<3; a++){
angle = rand()%50+20;
if(angle >48)
angle = -(rand()%50+20);
if (height >1){
glPushMatrix();
glRotatef(angle,1,0.0,1);
makeTree(height,base);
glPopMatrix();

}
 //else glColor3f(0.0,1.0/a,0.0);glutSolidSphere(.2,10,10); add like fruits...
}
}

void makeTree2(float height, float base){

float angle;
makeCylinder(height, base); glTranslatef(0.0, height, 0.0);
height -= height*.2; base-= base*0.3;
int a;
for(a= 0; a<3; a++){
angle = -rand()%50+20;
if(angle >48)
angle = (rand()%50+20);
if (height >1){
glPushMatrix();
glRotatef(angle,1,0.0,1);
makeTree(height,base);
glPopMatrix();

}
 //else glColor3f(0.0,1.0/a,0.0);glutSolidSphere(.2,10,10); add like fruits...
}
}
*/

void init(void)
{
 glClearColor (0.0, 0.0, 0.0, 0.0);
 glShadeModel (GL_FLAT);
 glEnable (GL_DEPTH_TEST);  //turn on depth(z-axis) buffer
/*  makeaTree=glGenLists(1);
 glNewList(makeaTree, GL_COMPILE);
 makeTree2(3,0.2);
 glEndList(); */
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


/****************OUTSIDE THE INNOVATION BUILDING**********************/
void innovbuilding() {

//Lawn
 glPushMatrix();
 glRotatef(90,1.0,0.0,0.0);
 glTranslatef(0.0,0.0,5.0);
 glScalef(160.0,160.0,0.0);
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
 glColor3f(0.2,0.2,0.2);
 optimizedquad(0.1,3.0,0.0);
 glPopMatrix();
 
 glPushMatrix();
 glTranslatef(12.0,-2.0,7.1);
 glColor3f(0.2,0.2,0.2);
 optimizedquad(0.1,3.0,0.0);
 glPopMatrix();
 
//Horizontal Bottom glass wall lines
 glPushMatrix();
 glTranslatef(8.0,-1.0,7.1);
 glColor3f(0.2,0.2,0.2);
 optimizedquad(7.0,0.1,0.0);
 glPopMatrix();
 
 glPushMatrix();
 glTranslatef(8.0,-3.0,7.1);
 glColor3f(0.2,0.2,0.2);
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
//glColor3f(0.9,0.0,0.9);
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
 
 //back-door -topboard
 glPushMatrix();
 glRotatef(90,1.0,0.0,0.0);
 glTranslatef(-5.0,-8.0,-1.0);
 glScalef(2.6,1.0,0.0);
 glColor3f(0.5,0.2,0.17);
 myquad();
 glPopMatrix();
 
 //back-door -leftboard
 glPushMatrix();
 glRotatef(90,0.0,1.0,0.0);
 glTranslatef(8.0,-3.0,-2.5);
 glScalef(1.0,4.0,0.0);
 glColor3f(0.5,0.2,0.17);
 myquad();
 glPopMatrix();
 
  //back-door -leftboard
 glPushMatrix();
 glRotatef(90,0.0,1.0,0.0);
 glTranslatef(8.0,-3.0,-7.5);
 glScalef(1.0,4.0,0.0);
 glColor3f(0.5,0.2,0.17);
 myquad();
 glPopMatrix();
 
   //back-door - inner quad
 glPushMatrix();
 glTranslatef(-4.9,-2.0,-8.2);
  glColor3f(0.6,0.3,0.17);
 optimizedquad(2.5,3.0,0.0);
 glPopMatrix();
 
	 
//Back glass wall
 glPushMatrix();
 glTranslatef(10.0,3.2,-8.0);
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
 
  //Top glass roof - frame lines
 glPushMatrix();
 glRotatef(90,1.0,0.0,0.0);
 glTranslatef(14.9,0.0,-11.6);
 glColor3f(0.0,0.0,0.0);
 optimizedquad(0.2,8.0,0.0);
 glPopMatrix();
 
 glPushMatrix();
 glRotatef(90,1.0,0.0,0.0);
 glTranslatef(5.15,0.0,-11.6);
 glColor3f(0.0,0.0,0.0);
 optimizedquad(0.2,8.0,0.0);
 glPopMatrix();

 glPushMatrix();
 glRotatef(90,1.0,0.0,0.0);
 glTranslatef(10.1,8.0,-11.6);
 glColor3f(0.0,0.0,0.0);
 optimizedquad(5.0,0.2,0.0);
 glPopMatrix();
 
 glPushMatrix();
 glRotatef(90,1.0,0.0,0.0);
 glTranslatef(10.1,-8.0,-11.6);
 glColor3f(0.0,0.0,0.0);
 optimizedquad(5.0,0.2,0.0);
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
 
}
/****************INSIDE THE BUILDING - ROBOT GALLERY ROOM**********************/
void room() {

//Floor
 glPushMatrix();
 glRotatef(90,1.0,0.0,0.0);
 glTranslatef(0.0,0.0,4.9);
 glScalef(10.0,3.0,0.0);
 glColor3f(0.3,0.1,0.1);
 myquad();
 glPopMatrix();
 
 //Left Side Wall
 glPushMatrix();
 glRotatef(90,0.0,1.0,0.0);
 //glTranslatef(0.0,10.0,-50.0);
 glColor3f(0.7,0.9,0.8);
 //glScalef(30.0,15.0,0.0);
 myquad();
 glPopMatrix();
 
 //Back wall
 glPushMatrix();
 //glTranslatef(0.0,10.0,-30.0);
 glColor3f(0.7,0.9,1.0);
 //glScalef(50.0,15.0,0.0);
 myquad();
 glPopMatrix();

 //Right Side Wall
 glPushMatrix();
 glRotatef(90,0.0,1.0,0.0);
 //glTranslatef(0.0,10.0,50.0);
 glColor3f(0.7,0.9,0.8);
 //glScalef(30.0,15.0,0.0);
 myquad();
 glPopMatrix(); 

}

void display(void)
{
 glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
 glRotatef((GLfloat) x_rotation, 1, 0 ,0);
 glRotatef((GLfloat) y_rotation, 0, 1 ,0);
 glRotatef((GLfloat) z_rotation, 0, 0 ,1); 	

 drawLines(); 
 
/* //trees
glPushMatrix();
glTranslatef(18.0,-5.0,7.0); 
glScalef(1.5,1.5,1.5);
glCallList(makeaTree);
glPopMatrix();

glPushMatrix();
glTranslatef(-22.0,-5.0,7.0); 
glScalef(1.5,1.5,1.5);
glCallList(makeaTree);
glPopMatrix();

glPushMatrix();
glTranslatef(-22.0,-8.0,7.0); 
glScalef(1.0,1.0,1.0);
glCallList(makeaTree);
glPopMatrix();

glPushMatrix();
glTranslatef(-22.0,-8.0,7.0); 
glScalef(1.7,1.3,1.7);
glCallList(makeaTree);
glPopMatrix();

glPushMatrix();
glTranslatef(-14.0,-8.0,15.0); 
glScalef(1.7,1.3,1.7);
glCallList(makeaTree);
glPopMatrix();

glPushMatrix();
glTranslatef(-14.0,-8.0,25.0); 
glScalef(1.7,1.3,1.7);
glCallList(makeaTree);
glPopMatrix();

glPushMatrix();
glTranslatef(-20.0,-8.0,30.0); 
glScalef(1.7,1.3,1.7);
glCallList(makeaTree);
glPopMatrix();

//fake shadow
 glPushMatrix();
 glRotatef(90,1.0,0.0,0.0);
 glTranslatef(0.0,-22.0,4.9);
 glScalef(15.5,10.0,0.0);
 glColor3f(0.3,0.6,0.2);
 myquad();
 glPopMatrix();
	  
*/
 //Main Building
 glPushMatrix();
// glScalef(50.0, 50.0, 50.0);
  innovbuilding();
  room();
 glPopMatrix();
 
/* //Inside - Room
 glPushMatrix();
 glTranslatef(0.0,0.0,0.0);
 glScalef(5.0,5.0,5.0);
 room();
 glPopMatrix();
*/
// buildingOne();
 
// building2();
 
// building3();
 
 
 
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
     gluPerspective (60, (GLfloat)w / (GLfloat)h, 1.0, 200.0);
     glMatrixMode(GL_MODELVIEW);    
     glLoadIdentity(); //clear the main matrix
     gluLookAt(45,25,45,0,0,0,0,1,0); //controls the position of camera, the 1st 3 values defines the position,
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

//Movement Function 2
void moveside(int i) {
	x = x + i*(lx)*0.2;
	z = z + i*(lz)*0.2;
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
    
	case 'o': //in
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
