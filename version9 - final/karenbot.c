void karenbot() {

  //Head
 glPushMatrix();
 glTranslatef(0.0,10.0,0.0);
 glScalef(4,3,2);
 glColor3f(1.0,0.0,0.0);
 drawCube();
 glPopMatrix();
 
 //Screen
 glPushMatrix();
 glTranslatef(0.0,10.0,2.1);
 glScalef(3.0,2.0,0.5);
 glColor3f(1.0,1.0,1.0);
 myquad();
 glPopMatrix();
 
 
 //eyes
 glPushMatrix();
 glTranslatef(0.0,10.0,2.3);
 int i;
 float r = 0.2;
 glColor3f(0.0, 0.0, 0.0);
 glPointSize(8.0);
 glBegin(GL_POINTS);
 for(i = 0; i < 1000; i++)
 {
 	//x and y defines the radius
 	glVertex3f( 1.5 - ( r * cos(2*3.14159 * i/1000.0)), 0.8 + (r * sin(2*3.14159 * i/1000.0)), -0.2);
 	glVertex3f( -1.5 - ( r * cos(2*3.14159 * i/1000.0)), 0.8 + (r * sin(2*3.14159 * i/1000.0)), -0.2);
 }
 glEnd();
 glPopMatrix();
 
 //mouth
 glPushMatrix();
 glTranslatef(0.0,8.5,2.5);
 glColor3f(0.0, 0.0, 0.0);
 glBegin(GL_POLYGON);
 glVertex3f(0.0, 0.55, -0.21);
 glVertex3f(1.5, 0.9, -0.21);
 glVertex3f(-1.5, 0.9, -0.21);
 glEnd(); 
 glPopMatrix();
 
  //Neck
 glPushMatrix();
 glTranslatef(0.0,2.0,0.0);
 glScalef(0.5,5.0,0.5);
 //glRotatef(angle,1.0,0.0,0.0);
 glColor3f(1.0,0.0,0.0);
 drawCube(); 
 glPopMatrix();
 
 //Base
 glPushMatrix();
 glTranslatef(0.0,-4.0,0.0);
 glScalef(5.0,1.0,5.0);
 //glRotatef(angle,1.0,0.0,0.0);
 glColor3f(1.0,1.0,0.0);
 drawCube();
 glPopMatrix();
 
 
  //Label Screen
 glPushMatrix();
 glTranslatef(0.0, 10.0, -10.0);
 glScalef(10.0,10.0,0.0);
 glColor3f(1.0,1.0,1.0);
 //myquad();
 glPopMatrix(); 

 
 int wheelloop1;
 for(wheelloop1 = 1; wheelloop1 < 7; wheelloop1++){
 float xvalue = 5 + (0.1*wheelloop1);
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
  
}

void karenlabel(){
	 
  //Label
 glPushMatrix();
 glColor3f(1, 0, 0);
 glTranslatef(7.0, 10.0, 0.0);  
 show_label(0, 0, "Name: Project NOW");    
 //show_label(0, 0, "Description: No "); 
 glPopMatrix(); 
 
  glPushMatrix();
 glColor3f(0, 0, 0);
 glTranslatef(7.0, 8.0, 0.0);  
 show_label(0, 0, "Project Now was");    
 //show_label(0, 0, "Description: No "); 
 glPopMatrix(); 
 
/* 
 glPushMatrix();
 glColor3f(0, 0, 0);
 glTranslatef(-5.0, 15.0, 0.0);
 show_name(0, 0, "UG Robotics Club Build");   
 glPopMatrix(); */
}
