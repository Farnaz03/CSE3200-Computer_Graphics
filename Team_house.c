///////////////////////////////////////////////////////////////////////////////
// A-Team House
// University of Guyana
// Department of Computer Science
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
// glutWireCube(3);
 drawLines();
 
 
 //Front
 glPushMatrix();
 glTranslatef(0,0,4.5);
 glScalef(2.5,2.5,0);
  glColor3f(1.0,0.4,0.2);
 glEnableClientState(GL_VERTEX_ARRAY);
 glVertexPointer(3, GL_FLOAT, 0, vertices);
 glDrawArrays(GL_QUADS, 0, 24);
 glPopMatrix();

 //Back
 glPushMatrix();
 glTranslatef(0,0,-4.5);
 glScalef(2.5,2.5,0);
 glColor3f(1.0,0.4,0.2);
 glEnableClientState(GL_VERTEX_ARRAY);
 glVertexPointer(3, GL_FLOAT, 0, vertices);
 glDrawArrays(GL_QUADS, 0, 24);
 glPopMatrix();
  
 //Right wall
 glPushMatrix();
 glTranslatef(-2.5,0,0);
 glScalef(0,2.5,4.5);
 glColor3f(1.0,0.4,0.2);
 glEnableClientState(GL_VERTEX_ARRAY);
 glVertexPointer(3, GL_FLOAT, 0, vertices);
 glDrawArrays(GL_QUADS, 0, 24);
 glPopMatrix();
 
  
 //Left wall
 glPushMatrix();
 glTranslatef(2.5,0,0);
 glScalef(0,2.5,4.5);
 glColor3f(1.0,0.4,0.2);
 glEnableClientState(GL_VERTEX_ARRAY);
 glVertexPointer(3, GL_FLOAT, 0, vertices);
 glDrawArrays(GL_QUADS, 0, 24);
 glPopMatrix();

 //Lawn
 glPushMatrix();
 glTranslatef(0,-2.5,0);
 glScalef(6,0,6);
 glColor3f(0.0,0.55,0.0);
 glEnableClientState(GL_VERTEX_ARRAY);
 glVertexPointer(3, GL_FLOAT, 0, vertices);
 glDrawArrays(GL_QUADS, 0, 24);
 glPopMatrix();
 
 
 //Ceiling
 glPushMatrix();
 glTranslatef(0,2.5,0);
 glScalef(2.5,0,4.5);
 glColor3f(0.9,0.4,0.2);
 glEnableClientState(GL_VERTEX_ARRAY);
 glVertexPointer(3, GL_FLOAT, 0, vertices);
 glDrawArrays(GL_QUADS, 0, 24);
 glPopMatrix();
   
 //Left roof
 glPushMatrix();
 glRotatef(30,0.0,0.0,1.0);
 glTranslatef(3.5,3.2,0);
 glScalef(0.1,3,4.5); 
 glColor3f(0.0,0.5,0.5);
 glEnableClientState(GL_VERTEX_ARRAY);
 glVertexPointer(3, GL_FLOAT, 0, vertices);
 glDrawArrays(GL_QUADS, 0, 24);
 glPopMatrix();
 
 
 //Right roof
 glPushMatrix();
 glRotatef(-30,0.0,0.0,1.0);
 glTranslatef(-3.5,3.2,0);
 glScalef(0.1,3,4.5);
 glColor3f(0.0,0.5,0.5);
 glEnableClientState(GL_VERTEX_ARRAY);
 glVertexPointer(3, GL_FLOAT, 0, vertices);
 glDrawArrays(GL_QUADS, 0, 24);
 glPopMatrix();
 
 //Front door
 glPushMatrix();
 glTranslatef(0,-0.7,4.6);
 glScalef(1.2,1.6,0);
 glColor3f(0.1,0.7,0.7);
 glEnableClientState(GL_VERTEX_ARRAY);
 glVertexPointer(3, GL_FLOAT, 0, vertices);
 glDrawArrays(GL_QUADS, 0, 24);
 glPopMatrix();
 
 //Back door
 glPushMatrix();
 glTranslatef(0,-0.7,-4.6);
 glScalef(1.2,1.6,0);
 glColor3f(0.1,0.7,0.7);
 glEnableClientState(GL_VERTEX_ARRAY);
 glVertexPointer(3, GL_FLOAT, 0, vertices);
 glDrawArrays(GL_QUADS, 0, 24);
 glPopMatrix();
 
 
 //Right window1
 glPushMatrix();
 glTranslatef(-2.5,0,-1.5);
 glScalef(0.2,1.2,1.2);
 glColor3f(0.1,0.7,0.7);
 glEnableClientState(GL_VERTEX_ARRAY);
 glVertexPointer(3, GL_FLOAT, 0, vertices);
 glDrawArrays(GL_QUADS, 0, 24);
 glPopMatrix();
 
 //Right window2
 glPushMatrix();
 glTranslatef(-2.5,0,1.5);
 glScalef(0.2,1.2,1.2);
 glColor3f(0.1,0.7,0.7);
 glEnableClientState(GL_VERTEX_ARRAY);
 glVertexPointer(3, GL_FLOAT, 0, vertices);
 glDrawArrays(GL_QUADS, 0, 24);
 glPopMatrix();
 
 //Right window1
 glPushMatrix();
 glTranslatef(2.5,0,-1.5);
 glScalef(0.2,1.2,1.2);
 glColor3f(0.1,0.7,0.7);
 glEnableClientState(GL_VERTEX_ARRAY);
 glVertexPointer(3, GL_FLOAT, 0, vertices);
 glDrawArrays(GL_QUADS, 0, 24);
 glPopMatrix();
 
 //Right window2
 glPushMatrix();
 glTranslatef(2.5,0,1.5);
 glScalef(0.2,1.2,1.2);
 glColor3f(0.1,0.7,0.7);
 glEnableClientState(GL_VERTEX_ARRAY);
 glVertexPointer(3, GL_FLOAT, 0, vertices);
 glDrawArrays(GL_QUADS, 0, 24);
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
     gluLookAt(15,15,15,0,0,0,0,1,0); //controls the position of camera, the 1st 3 values defines the position,
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
    glutInitWindowSize (500, 500);
    glutInitWindowPosition (100, 100);
    glutCreateWindow ("A-Team House");
    init ();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    glutMainLoop();
    return 0;
}
