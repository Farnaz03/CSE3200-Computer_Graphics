void room() {

 glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
 //Floor
 glPushMatrix();
 glRotatef(90,1.0,0.0,0.0);
 glTranslatef(0.0,0.0,5.0);
 glScalef(15.0,10.0,0.0);
 glColor3f(0.2,0.2,0.2);
 myquad();
 glPopMatrix();
 
 //Left Side Wall
 glPushMatrix();
 glRotatef(90,0.0,1.0,0.0);
 glTranslatef(0.0,4.0,-15.0);
 glColor3f(0.5,0.5,0.5);
 glScalef(9.0,9.0,0.0);
 myquad();
 glPopMatrix();
 
 //Back wall
 glPushMatrix();
 glTranslatef(0.0,3.3,-8.0);
 glColor3f(0.5,0.5,0.5);
 glScalef(15.0,9.0,0.0);
 myquad();
 glPopMatrix();
 
 //Right Side Wall
 glPushMatrix();
 glRotatef(90,0.0,1.0,0.0);
 glTranslatef(0.5,-2.0,14.9);
 glColor3f(0.5,0.5,0.5);
 glScalef(7.5,3.0,0.0);
 myquad();
 glPopMatrix(); 
 
 glutSwapBuffers();  
}
