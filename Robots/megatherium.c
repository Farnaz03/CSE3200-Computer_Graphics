///////////////////////////////////////////////////////////////////////////////
// draw cube with glDrawArrays
// University of Guyana
// Department of Computer Science
// CSI 322 Micro-computer Graphics
// 3D Orientation Exercise - 2009/2010
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

void wheels(double radius){
	//Wheels
    float x1,y1,x2,y2;
	float angle;
	

	x1 = 0,y1=0;
	//glColor3f(0.6,0.6,0.6);

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

void drawLines(){
	
	//x-line
	glColor3f(1.0,0.0,1.0);
	glBegin(GL_LINES);
	glVertex3f(10.0,0.0,0.0);
	glVertex3f(-10.0,0.0,0.0);
	glEnd();
	
	//y-line
	glColor3f(1.0,1.0,0.0);
	glBegin(GL_LINES);
	glVertex3f(0.0,10.0,0.0);
	glVertex3f(0.0,-10.0,0.0);
	glEnd();
	
	//z-line
	glColor3f(0.0,1.0,0.0);
	glBegin(GL_LINES);
	glVertex3f(0.0,0.0,10.0);
	glVertex3f(0.0,0.0,-10.0);
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



 //-------------------------------------
 glColor3f(1,1,1);
// glutWireCube(5);
 drawLines();
 //--------------------------------------
 
 //base
 glPushMatrix();
 glTranslatef(0.0,0.0,0.0);
 glScalef(6,0.4,6);
 //glRotatef(angle,1.0,0.0,0.0);
 glColor3f(0.5,0.6,0.5);
 glEnableClientState(GL_VERTEX_ARRAY);
 glColorPointer(3, GL_FLOAT, 0, colors);
 glVertexPointer(3, GL_FLOAT, 0, vertices);
 glDrawArrays(GL_QUADS, 0, 24);
 glPopMatrix();
 
 
 //side bars - left
  glPushMatrix();
 glTranslatef(-6.25,4.0,-2.0);
 glScalef(0.2,4,0.2);
 //glRotatef(angle,1.0,0.0,0.0);
 glColor3f(0.5,0.5,0.6);
 glEnableClientState(GL_VERTEX_ARRAY);
 glColorPointer(3, GL_FLOAT, 0, colors);
 glVertexPointer(3, GL_FLOAT, 0, vertices);
 glDrawArrays(GL_QUADS, 0, 24);
 glPopMatrix();
 
 //side bars - right
  glPushMatrix();
 glTranslatef(6.25,4.0,-2.0);
 glScalef(0.2,4,0.2);
 //glRotatef(angle,1.0,0.0,0.0);
 glColor3f(0.5,0.5,0.6);
 glEnableClientState(GL_VERTEX_ARRAY);
 glColorPointer(3, GL_FLOAT, 0, colors);
 glVertexPointer(3, GL_FLOAT, 0, vertices);
 glDrawArrays(GL_QUADS, 0, 24);
 glPopMatrix();
 
  //side bars - right slanted
  glPushMatrix();
  glRotatef(-45,1.0,0.0,0.0);
 glTranslatef(6.25,1.0,0.0);
 glScalef(0.2,1.5,0.2);
 glColor3f(0.5,0.5,0.6);
 glEnableClientState(GL_VERTEX_ARRAY);
 glColorPointer(3, GL_FLOAT, 0, colors);
 glVertexPointer(3, GL_FLOAT, 0, vertices);
 glDrawArrays(GL_QUADS, 0, 24);
 glPopMatrix();
 
   //side bars - left slanted
  glPushMatrix();
  glRotatef(-45,1.0,0.0,0.0);
 glTranslatef(-6.25,1.0,0.0);
 glScalef(0.2,1.5,0.2);
 glColor3f(0.5,0.5,0.6);
 glEnableClientState(GL_VERTEX_ARRAY);
 glColorPointer(3, GL_FLOAT, 0, colors);
 glVertexPointer(3, GL_FLOAT, 0, vertices);
 glDrawArrays(GL_QUADS, 0, 24);
 glPopMatrix();
 
    //back wall
  glPushMatrix();
  //glRotatef(-45,1.0,0.0,0.0);
 glTranslatef(0.0,1.5,-6.0);
 glScalef(6.0,1.5,0.1);
 glColor3f(0.5,0.5,0.5);
 glEnableClientState(GL_VERTEX_ARRAY);
 glColorPointer(3, GL_FLOAT, 0, colors);
 glVertexPointer(3, GL_FLOAT, 0, vertices);
 glDrawArrays(GL_QUADS, 0, 24);
 glPopMatrix();
 
    //back left wall
  glPushMatrix();
  //glRotatef(-45,1.0,0.0,0.0);
 glTranslatef(-6.0,1.5,-4.0);
 glScalef(0.1,1.5,2);
 glColor3f(0.5,0.5,0.5);
 glEnableClientState(GL_VERTEX_ARRAY);
 glColorPointer(3, GL_FLOAT, 0, colors);
 glVertexPointer(3, GL_FLOAT, 0, vertices);
 glDrawArrays(GL_QUADS, 0, 24);
 glPopMatrix();
 
     //back right wall
  glPushMatrix();
  //glRotatef(-45,1.0,0.0,0.0);
 glTranslatef(6.0,1.5,-4.0);
 glScalef(0.1,1.5,2);
 glColor3f(0.5,0.5,0.5);
 glEnableClientState(GL_VERTEX_ARRAY);
 glColorPointer(3, GL_FLOAT, 0, colors);
 glVertexPointer(3, GL_FLOAT, 0, vertices);
 glDrawArrays(GL_QUADS, 0, 24);
 glPopMatrix();
 
      //back separater wall
  glPushMatrix();
  //glRotatef(-45,1.0,0.0,0.0);
 glTranslatef(0.0,2,-3.9);
 glScalef(0.1,1.5,2);
 glColor3f(0.5,0.5,0.6);
 glEnableClientState(GL_VERTEX_ARRAY);
 glColorPointer(3, GL_FLOAT, 0, colors);
 glVertexPointer(3, GL_FLOAT, 0, vertices);
 glDrawArrays(GL_QUADS, 0, 24);
 glPopMatrix();
 
     //middle wall
  glPushMatrix();
  //glRotatef(-45,1.0,0.0,0.0);
 glTranslatef(0.0,3.0,-1.9);
 glScalef(6.0,3.0,0.1);
 glColor3f(0.5,0.5,0.5);
 glEnableClientState(GL_VERTEX_ARRAY);
 glColorPointer(3, GL_FLOAT, 0, colors);
 glVertexPointer(3, GL_FLOAT, 0, vertices);
 glDrawArrays(GL_QUADS, 0, 24);
 glPopMatrix();
 
  //tubes
    glPushMatrix();
  glRotatef(-60,1.0,0.0,0.0);
 glTranslatef(5.50,1.0,3.8);
 glScalef(0.1,3.0,0.1);
glColor3f(1.0,0.5,0.0);
 glEnableClientState(GL_VERTEX_ARRAY);
 glColorPointer(3, GL_FLOAT, 0, colors);
 glVertexPointer(3, GL_FLOAT, 0, vertices);
 glDrawArrays(GL_QUADS, 0, 24);
 glPopMatrix();
 
  glPushMatrix();
  glRotatef(-60,1.0,0.0,0.0);
 glTranslatef(4.0,1.0,3.8);
 glScalef(0.1,3.0,0.1);
 glColor3f(1.0,0.5,0.0);
 glEnableClientState(GL_VERTEX_ARRAY);
 glColorPointer(3, GL_FLOAT, 0, colors);
 glVertexPointer(3, GL_FLOAT, 0, vertices);
 glDrawArrays(GL_QUADS, 0, 24);
 glPopMatrix();
 
 glPushMatrix();
  glRotatef(-60,1.0,0.0,0.0);
 glTranslatef(2.0,1.0,3.8);
 glScalef(0.1,3.0,0.1);
 glColor3f(1.0,0.5,0.0);
 glEnableClientState(GL_VERTEX_ARRAY);
 glColorPointer(3, GL_FLOAT, 0, colors);
 glVertexPointer(3, GL_FLOAT, 0, vertices);
 glDrawArrays(GL_QUADS, 0, 24);
 glPopMatrix();
 
 glPushMatrix();
  glRotatef(-60,1.0,0.0,0.0);
 glTranslatef(0.0,1.0,3.8);
 glScalef(0.1,3.0,0.1);
 glColor3f(1.0,0.5,0.0);
 glEnableClientState(GL_VERTEX_ARRAY);
 glColorPointer(3, GL_FLOAT, 0, colors);
 glVertexPointer(3, GL_FLOAT, 0, vertices);
 glDrawArrays(GL_QUADS, 0, 24);
 glPopMatrix();
 
 glPushMatrix();
  glRotatef(-60,1.0,0.0,0.0);
 glTranslatef(-2.0,1.0,3.8);
 glScalef(0.1,3.0,0.1);
 glColor3f(1.0,0.5,0.0);
 glEnableClientState(GL_VERTEX_ARRAY);
 glColorPointer(3, GL_FLOAT, 0, colors);
 glVertexPointer(3, GL_FLOAT, 0, vertices);
 glDrawArrays(GL_QUADS, 0, 24);
 glPopMatrix();
 
  glPushMatrix();
  glRotatef(-60,1.0,0.0,0.0);
 glTranslatef(-4.0,1.0,3.8);
 glScalef(0.1,3.0,0.1);
 glColor3f(1.0,0.5,0.0);
 glEnableClientState(GL_VERTEX_ARRAY);
 glColorPointer(3, GL_FLOAT, 0, colors);
 glVertexPointer(3, GL_FLOAT, 0, vertices);
 glDrawArrays(GL_QUADS, 0, 24);
 glPopMatrix();
 
   glPushMatrix();
  glRotatef(-60,1.0,0.0,0.0);
 glTranslatef(-5.5,1.0,3.8);
 glScalef(0.1,3.0,0.1);
 glColor3f(1.0,0.5,0.0); 
 glEnableClientState(GL_VERTEX_ARRAY);
 glColorPointer(3, GL_FLOAT, 0, colors);
 glVertexPointer(3, GL_FLOAT, 0, vertices);
 glDrawArrays(GL_QUADS, 0, 24);
 glPopMatrix();
 
 //tube base bar
  glPushMatrix();
  //glRotatef(-45,1.0,0.0,0.0);
 glTranslatef(0.0,2.5,3.5);
 glScalef(6,0.2,0.2);
 glColor3f(0.5,0.5,0.5);
 glEnableClientState(GL_VERTEX_ARRAY);
 glColorPointer(3, GL_FLOAT, 0, colors);
 glVertexPointer(3, GL_FLOAT, 0, vertices);
 glDrawArrays(GL_QUADS, 0, 24);
 glPopMatrix();
 
  //Right-side Back wheel
  
//large conveyor wheels
int n;
for(n = 1; n < 7; n++ ){
 glPushMatrix();
 glTranslatef(-12.0 + (2*n), 0.0,0.0);

 int wheelloop1;
 for(wheelloop1 = 1; wheelloop1 < 50; wheelloop1++){
 float xvalue = 4.8 + (0.01*wheelloop1);
 glPushMatrix();
 glTranslatef(xvalue,0,0);
 glTranslatef(0,1.5,0);
 glTranslatef(0,0,6.2);
 glRotatef(90,0,1,0);
  glColor3f(0.7,0.7,0.7);
 wheels(1.0);
 glPopMatrix();
}
glPopMatrix();
}

//small conveyor wheels
int n1;
for(n1 = 1; n1 < 6; n1++ ){
 glPushMatrix();
 glTranslatef(-12.0 + (2*n1), 0.0,0.0);

 int wheelloop1;
 for(wheelloop1 = 1; wheelloop1 < 50; wheelloop1++){
 float xvalue = 5.7 + (0.01*wheelloop1);
 glPushMatrix();
 glTranslatef(xvalue,0,0);
 glTranslatef(0,2.5,0);
 glTranslatef(0,0,4.5);
 //glScalef(0.5,0.,0.0);
 glRotatef(90,0,1,0);
  glColor3f(0.8,0.8,0.8);
 wheels(0.8);
 glPopMatrix();
}
glPopMatrix();
}

 int dw;
 for(dw = 1; dw < 40; dw++){
 float xvalue = 6.0 + (0.01*dw);
 glPushMatrix();
 glTranslatef(xvalue,0,0);
 glTranslatef(0,0.0,0);
 glTranslatef(0,0,2.5);
 //glScalef(0.5,0.,0.0);
 glRotatef(90,0,1,0);
  glColor3f(1.0,1.0,1.0);
 wheels(1);
 glPopMatrix();
}

 for(dw = 1; dw < 40; dw++){
 float xvalue = 6.0 + (0.01*dw);
 glPushMatrix();
 glTranslatef(xvalue,0,0);
 glTranslatef(0,0.0,0);
 glTranslatef(0,0,-3.5);
 //glScalef(0.5,0.,0.0);
 glRotatef(90,0,1,0);
 glColor3f(1.0,1.0,1.0);
 wheels(1);
 glPopMatrix();
}

 for(dw = 1; dw < 40; dw++){
 float xvalue = -6.0 - (0.01*dw);
 glPushMatrix();
 glTranslatef(xvalue,0,0);
 glTranslatef(0,0.0,0);
 glTranslatef(0,0,2.5);
 //glScalef(0.5,0.,0.0);
 glRotatef(90,0,1,0);
  glColor3f(1.0,1.0,1.0);
 wheels(1);
 glPopMatrix();
}


 for(dw = 1; dw < 40; dw++){
 float xvalue = -6.0 - (0.01*dw);
 glPushMatrix();
 glTranslatef(xvalue,0,0);
 glTranslatef(0,0.0,0);
 glTranslatef(0,0,-3.5);
 //glScalef(0.5,0.,0.0);
 glRotatef(90,0,1,0);
  glColor3f(1.0,1.0,1.0);
 wheels(1);
 glPopMatrix();
}


 float xvalue = 6.0 + (0.01*dw);{
 glPushMatrix();
 glTranslatef(xvalue,0,0);
 glTranslatef(0,0.0,0);
 glTranslatef(0,0,-3.5);
 //glScalef(0.5,0.,0.0);
 glRotatef(90,0,1,0);
  glColor3f(1.0,1.0,1.0);
 wheels(1);
 glPopMatrix();
}



 /*long building
  glPushMatrix();  
 glTranslatef(5.0,0.0,0.0);
 glScalef(13,7,6);
 //glRotatef(angle,1.0,0.0,0.0);
 glColor3f(1.0,0.0,0.0);
 glEnableClientState(GL_VERTEX_ARRAY);
 glColorPointer(3, GL_FLOAT, 0, colors);
 glVertexPointer(3, GL_FLOAT, 0, vertices);
 glDrawArrays(GL_QUADS, 0, 24);
 glPopMatrix();*/
 

 
 
 
 
 
 
 
 
 //----------------
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
     gluLookAt(20,20,20,0,0,0,0,1,0); //controls the position of camera, the 1st 3 values defines the position,
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
    glutInitWindowSize (1200, 1000);
    glutInitWindowPosition (200, 0.0);
    glutCreateWindow ("Cubeee 2.0 |Depth Test Enabled!!!");
    init ();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    glutMainLoop();
    return 0;
}
