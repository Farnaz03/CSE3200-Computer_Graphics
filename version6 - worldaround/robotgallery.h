void room() {

 glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
 //Floor
 glPushMatrix();
 glRotatef(90,1.0,0.0,0.0);
 glTranslatef(0.0,0.0,5.0);
 glScalef(15.0,10.0,0.0);
 glColor3f(0.5,0.5,0.5);
 myquad();
 glPopMatrix();
 
 //Left Side Wall
 glPushMatrix();
 glRotatef(90,0.0,1.0,0.0);
 glTranslatef(0.0,4.0,-15.0);
 glColor3f(0.7,0.9,0.8);
 glScalef(10.0,9.0,0.0);
 myquad();
 glPopMatrix();
 
 //Back wall
 glPushMatrix();
 glTranslatef(0.0,4.0,-8.0);
 glColor3f(0.7,0.9,1.0);
 glScalef(15.0,9.0,0.0);
 myquad();
 glPopMatrix();
 
 //Right Side Wall
 glPushMatrix();
 glRotatef(90,0.0,1.0,0.0);
 glTranslatef(0.0,4.0,15.0);
 glColor3f(0.7,0.9,0.8);
 glScalef(10.0,9.0,0.0);
 myquad();
 glPopMatrix(); 
 
 glutSwapBuffers();  
}
