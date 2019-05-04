#include <GL/glut.h>

buildingOne() {

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
	
	
//glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	 //short building
 glPushMatrix();
 glTranslatef(-40.0,-4.0,45.0);
 glScalef(5,7,4);
 //glRotatef(angle,1.0,0.0,0.0);
 glColor3f(0.0,0.0,0.0);
 glEnableClientState(GL_VERTEX_ARRAY);
 glColorPointer(3, GL_FLOAT, 0, colors);
 glVertexPointer(3, GL_FLOAT, 0, vertices);
 glDrawArrays(GL_QUADS, 0, 24);
 glPopMatrix();
 
 
 //long building
  glPushMatrix();
 glTranslatef(-35.0,-4.0,45.0);
  glScalef(5,7,9);
 //glRotatef(angle,1.0,0.0,0.0);
 glColor3f(0.0,0.0,0.0);
 glEnableClientState(GL_VERTEX_ARRAY);
 glColorPointer(3, GL_FLOAT, 0, colors);
 glVertexPointer(3, GL_FLOAT, 0, vertices);
 glDrawArrays(GL_QUADS, 0, 24);
 glPopMatrix();
 
 
 //shadow
  glPushMatrix();
 glTranslatef(-40.0,-4.0,25.0);
 glScalef(5,0.1,5);
 //glRotatef(angle,1.0,0.0,0.0);
 glColor3f(0.3,0.6,0.2);
 glEnableClientState(GL_VERTEX_ARRAY);
 glColorPointer(3, GL_FLOAT, 0, colors);
 glVertexPointer(3, GL_FLOAT, 0, vertices);
 glDrawArrays(GL_QUADS, 0, 24);
 glPopMatrix();
 
 
  glPushMatrix();
 glTranslatef(-35.0,-4.0,25.0);
  glScalef(6,0.1,10);
 //glRotatef(angle,1.0,0.0,0.0);
 glColor3f(0.3,0.6,0.2);
 glEnableClientState(GL_VERTEX_ARRAY);
 glColorPointer(3, GL_FLOAT, 0, colors);
 glVertexPointer(3, GL_FLOAT, 0, vertices);
 glDrawArrays(GL_QUADS, 0, 24);
 glPopMatrix();
 
 // glutSwapBuffers();  
}

building2(){
	
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
	
	
 glPushMatrix();
 glTranslatef(-10.0,-4.0,45.0);
 glScalef(5,7,4);
 //glRotatef(angle,1.0,0.0,0.0);
 glColor3f(0.0,0.0,0.0);
 glEnableClientState(GL_VERTEX_ARRAY);
 glColorPointer(3, GL_FLOAT, 0, colors);
 glVertexPointer(3, GL_FLOAT, 0, vertices);
 glDrawArrays(GL_QUADS, 0, 24);
 glPopMatrix();
 
 
 //long building
  glPushMatrix();
 glTranslatef(0.0,-4.0,45.0);
 glScalef(9,7,6);
 //glRotatef(angle,1.0,0.0,0.0);
 glColor3f(0.0,0.0,0.0);
 glEnableClientState(GL_VERTEX_ARRAY);
 glColorPointer(3, GL_FLOAT, 0, colors);
 glVertexPointer(3, GL_FLOAT, 0, vertices);
 glDrawArrays(GL_QUADS, 0, 24);
 glPopMatrix();
 
  //shadow
  glPushMatrix();
 glTranslatef(-10.0,-4.0,32.0);
 glScalef(5,0.1,4);
 //glRotatef(angle,1.0,0.0,0.0);
 glColor3f(0.3,0.6,0.2);
 glEnableClientState(GL_VERTEX_ARRAY);
 glColorPointer(3, GL_FLOAT, 0, colors);
 glVertexPointer(3, GL_FLOAT, 0, vertices);
 glDrawArrays(GL_QUADS, 0, 24);
 glPopMatrix();
 
 
  glPushMatrix();
 glTranslatef(0.0,-4.0,32.0);
  glScalef(9,0.1,6);
 //glRotatef(angle,1.0,0.0,0.0);
 glColor3f(0.3,0.6,0.2);
 glEnableClientState(GL_VERTEX_ARRAY);
 glColorPointer(3, GL_FLOAT, 0, colors);
 glVertexPointer(3, GL_FLOAT, 0, vertices);
 glDrawArrays(GL_QUADS, 0, 24);
 glPopMatrix();
 
 
}

void building3(){
	
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
	
 glPushMatrix();
 glTranslatef(-45.0,0.0,0.0);
 glScalef(4,7,7);
 //glRotatef(angle,1.0,0.0,0.0);
 glColor3f(0.0,0.0,0.0);
 glEnableClientState(GL_VERTEX_ARRAY);
 glColorPointer(3, GL_FLOAT, 0, colors);
 glVertexPointer(3, GL_FLOAT, 0, vertices);
 glDrawArrays(GL_QUADS, 0, 24);
 glPopMatrix();
 
 
 //long building
  glPushMatrix();
 glTranslatef(-40.0,0.0,0.0);
 glScalef(12,7,5);
 //glRotatef(angle,1.0,0.0,0.0);
 glColor3f(0.0,0.0,0.0);
 glEnableClientState(GL_VERTEX_ARRAY);
 glColorPointer(3, GL_FLOAT, 0, colors);
 glVertexPointer(3, GL_FLOAT, 0, vertices);
 glDrawArrays(GL_QUADS, 0, 24);
 glPopMatrix();
 
 //shadow
 glPushMatrix();
 glTranslatef(-45.0,-4.0,-16.9);
 glScalef(4,0.1,7);
 //glRotatef(angle,1.0,0.0,0.0);
 glColor3f(0.3,0.6,0.2);
 glEnableClientState(GL_VERTEX_ARRAY);
 glColorPointer(3, GL_FLOAT, 0, colors);
 glVertexPointer(3, GL_FLOAT, 0, vertices);
 glDrawArrays(GL_QUADS, 0, 24);
 glPopMatrix();
 
 
 //long building
  glPushMatrix();
 glTranslatef(-40.0,-4.0,-16.9);
 glScalef(12,0.1,5);
 //glRotatef(angle,1.0,0.0,0.0);
 glColor3f(0.3,0.6,0.2);
 glEnableClientState(GL_VERTEX_ARRAY);
 glColorPointer(3, GL_FLOAT, 0, colors);
 glVertexPointer(3, GL_FLOAT, 0, vertices);
 glDrawArrays(GL_QUADS, 0, 24);
 glPopMatrix();
 
 
	
}
