///////////////////////////////////////////////////////////////////////////////
// draw cube with glDrawArrays
// University of Guyana
// Department of Computer Science
// CSI 322 Micro-computer Graphics
// 3D Orientation Exercise - 2018/2019
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
    // enble and specify pointers to vertex arrays
    glEnableClientState(GL_COLOR_ARRAY);
    glEnableClientState(GL_VERTEX_ARRAY);
    glColorPointer(3, GL_FLOAT, 0, colors);
    glVertexPointer(3, GL_FLOAT, 0, vertices);
    glDrawArrays(GL_QUADS, 0, 24);
    glDisableClientState(GL_VERTEX_ARRAY);  // disable vertex arrays
    glDisableClientState(GL_COLOR_ARRAY);
 //-------------------------------------
 glColor3f(1,1,1);
 glutWireCube(5); // wire cube aorund the object
 drawLines();
 
 //Front wall
 glPushMatrix();
 glColor3f(0.5, 0.5, 0.5);
 glTranslatef(0.0, 0.0, 6.0);
 glScaled(6.0f, 6.0f, 0.0f);
// glRotatef(angle, 0.0, 0.0, 0.0);
	glEnableClientState(GL_VERTEX_ARRAY);
	glVertexPointer(3, GL_FLOAT, 0, vertices);
 	glDrawArrays(GL_QUADS, 0, 24);
 glPopMatrix(); 
 
  //Back wall
 glPushMatrix();
 glColor3f(0.5, 0.5, 0.5);
 glTranslatef(0.0, 0.0, -6.0);
 glScaled(6.0f, 6.0f, 0.0f);
	glEnableClientState(GL_VERTEX_ARRAY);
	glVertexPointer(3, GL_FLOAT, 0, vertices);
 	glDrawArrays(GL_QUADS, 0, 24);
 glPopMatrix(); 
 
   //Right wall
 glPushMatrix();
 glColor3f(0.5, 0.5, 0.5);
 glTranslatef(6.0, 0.0, 0.0);
 glScaled(0.0f, 6.0f, 6.0f);
	glEnableClientState(GL_VERTEX_ARRAY);
	glVertexPointer(3, GL_FLOAT, 0, vertices);
 	glDrawArrays(GL_QUADS, 0, 24);
 glPopMatrix();
 
    //Left wall
 glPushMatrix();
 glColor3f(0.5, 0.5, 0.5);
 glTranslatef(-6.0, 0.0, 0.0);
 glScaled(0.0f, 6.0f, 6.0f);
	glEnableClientState(GL_VERTEX_ARRAY);
	glVertexPointer(3, GL_FLOAT, 0, vertices);
 	glDrawArrays(GL_QUADS, 0, 24);
 glPopMatrix();
 
     //Base
 glPushMatrix();
 glColor3f(0.0, 0.4, 0.0);
 glTranslatef(0.0, -6.0, 0.0);
 glScaled(10.0f, 0.0f, 10.0f);
	glEnableClientState(GL_VERTEX_ARRAY);
	glVertexPointer(3, GL_FLOAT, 0, vertices);
 	glDrawArrays(GL_QUADS, 0, 24);
 glPopMatrix();
 
  //Door
 glPushMatrix();
 glColor3f(1.0, 1.0, 1.0);
 glTranslatef(0.0, 0.0, 6.1);
 glScaled(2.0f, 4.0f, 0.0f);
// glRotatef(angle, 0.0, 0.0, 0.0);
	glEnableClientState(GL_VERTEX_ARRAY);
	glVertexPointer(3, GL_FLOAT, 0, vertices);
 	glDrawArrays(GL_QUADS, 0, 24);
 glPopMatrix(); 
 
     //Left Window
 glPushMatrix();
 glColor3f(1.0, 1.0, 1.0);
 glTranslatef(-6.1, 0.0, 0.0);
 glScaled(0.0f, 2.0f, 2.0f);
	glEnableClientState(GL_VERTEX_ARRAY);
	glVertexPointer(3, GL_FLOAT, 0, vertices);
 	glDrawArrays(GL_QUADS, 0, 24);
 glPopMatrix();
 
     //Right Window
 glPushMatrix();
 glColor3f(1.0, 1.0, 1.0);
 glTranslatef(6.1, 0.0, 0.0);
 glScaled(0.0f, 2.0f, 2.0f);
	glEnableClientState(GL_VERTEX_ARRAY);
	glVertexPointer(3, GL_FLOAT, 0, vertices);
 	glDrawArrays(GL_QUADS, 0, 24);
 glPopMatrix();
 
 /*	//Ceiling
 glPushMatrix();
 glColor3f(0.5, 0.2, 0.0);
 glTranslatef(0.0, 6.0, 0.0);
 glScaled(6.0f, 0.0f, 6.0f);
	glEnableClientState(GL_VERTEX_ARRAY);
	glVertexPointer(3, GL_FLOAT, 0, vertices);
 	glDrawArrays(GL_QUADS, 0, 24);
 glPopMatrix(); */
 
	//left Roof
 glPushMatrix();
 glColor3f(0.5, 0.2, 0.0);
 glRotatef(20, 0.0, 0.0, 1.0);
 glTranslatef(-3.2, 7.7, 0.0);
 glScaled(6.0f, 0.1f, 6.0f);
glEnableClientState(GL_VERTEX_ARRAY);
	glVertexPointer(3, GL_FLOAT, 0, vertices);
 	glDrawArrays(GL_QUADS, 0, 24);
 glPopMatrix(); 
 
	//right Roof
 glPushMatrix();
 glColor3f(0.5, 0.2, 0.0);
 glRotatef(-20, 0.0, 0.0, 1.0);
 glTranslatef(3.2, 7.7, 0.0);
 glScaled(6.0f, 0.1f, 6.0f);
glEnableClientState(GL_VERTEX_ARRAY);
	glVertexPointer(3, GL_FLOAT, 0, vertices);
 	glDrawArrays(GL_QUADS, 0, 24);
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
     gluLookAt(15,15,15,0,0,0,0,1,0); /*control position of camera --- first 3 position is where the position of the camera 
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
    glutInitWindowSize (800, 800);
    glutInitWindowPosition (100, 100);
    glutCreateWindow ("Cubeee House |Farnaz Baksh");
    init ();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    glutMainLoop();
    return 0;
}
