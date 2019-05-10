void mega(void) {
	
 //base
 glPushMatrix();
 glColor3f(0.5,0.6,0.5);
 glTranslatef(0.0,0.0,0.0);
 glScalef(6,0.4,6);
 //glRotatef(angle,1.0,0.0,0.0);
 drawCube();
 glPopMatrix();
  
 //side bars - left
 glPushMatrix();
 glTranslatef(-6.25,4.0,-2.0);
 glScalef(0.2,4,0.2);
 glColor3f(0.5,0.5,0.6);
 drawCube();
 glPopMatrix();
 
 //side bars - right
  glPushMatrix();
 glTranslatef(6.25,4.0,-2.0);
 glScalef(0.2,4,0.2);
 //glRotatef(angle,1.0,0.0,0.0);
 glColor3f(0.5,0.5,0.6);
 drawCube();
 glPopMatrix();
 
  //side bars - right slanted
  glPushMatrix();
  glRotatef(-45,1.0,0.0,0.0);
 glTranslatef(6.25,1.0,0.0);
 glScalef(0.2,1.5,0.2);
 glColor3f(0.5,0.5,0.6);
 drawCube();
 glPopMatrix();
 
   //side bars - left slanted
  glPushMatrix();
  glRotatef(-45,1.0,0.0,0.0);
 glTranslatef(-6.25,1.0,0.0);
 glScalef(0.2,1.5,0.2);
 glColor3f(0.5,0.5,0.6);
 drawCube();
 glPopMatrix();
 
    //back wall
  glPushMatrix();
  //glRotatef(-45,1.0,0.0,0.0);
 glTranslatef(0.0,1.5,-6.0);
 glScalef(6.0,1.5,0.1);
 glColor3f(0.5,0.5,0.5);
 drawCube();
 glPopMatrix();
 
    //back left wall
  glPushMatrix();
  //glRotatef(-45,1.0,0.0,0.0);
 glTranslatef(-6.0,1.5,-4.0);
 glScalef(0.1,1.5,2);
 glColor3f(0.5,0.5,0.5);
 drawCube();
 glPopMatrix();
 
     //back right wall
  glPushMatrix();
  //glRotatef(-45,1.0,0.0,0.0);
 glTranslatef(6.0,1.5,-4.0);
 glScalef(0.1,1.5,2);
 glColor3f(0.5,0.5,0.5);
 drawCube();
 glPopMatrix();
 
      //back separater wall
  glPushMatrix();
  //glRotatef(-45,1.0,0.0,0.0);
 glTranslatef(0.0,2,-3.9);
 glScalef(0.1,1.5,2);
 glColor3f(0.5,0.5,0.6);
 drawCube();
 glPopMatrix();
 
     //middle wall
  glPushMatrix();
  //glRotatef(-45,1.0,0.0,0.0);
 glTranslatef(0.0,3.0,-1.9);
 glScalef(6.0,3.0,0.1);
 glColor3f(0.5,0.5,0.5);
 drawCube();
 glPopMatrix();
 
  //tubes
    glPushMatrix();
  glRotatef(-60,1.0,0.0,0.0);
 glTranslatef(5.50,1.0,3.8);
 glScalef(0.1,3.0,0.1);
glColor3f(1.0,0.5,0.0);
drawCube();
 glPopMatrix();
 
  glPushMatrix();
  glRotatef(-60,1.0,0.0,0.0);
 glTranslatef(4.0,1.0,3.8);
 glScalef(0.1,3.0,0.1);
 glColor3f(1.0,0.5,0.0);
 drawCube();
 glPopMatrix();
 
 glPushMatrix();
  glRotatef(-60,1.0,0.0,0.0);
 glTranslatef(2.0,1.0,3.8);
 glScalef(0.1,3.0,0.1);
 glColor3f(1.0,0.5,0.0);
 drawCube();
 glPopMatrix();
 
 glPushMatrix();
  glRotatef(-60,1.0,0.0,0.0);
 glTranslatef(0.0,1.0,3.8);
 glScalef(0.1,3.0,0.1);
 glColor3f(1.0,0.5,0.0);
 drawCube();
 glPopMatrix();
 
 glPushMatrix();
  glRotatef(-60,1.0,0.0,0.0);
 glTranslatef(-2.0,1.0,3.8);
 glScalef(0.1,3.0,0.1);
 glColor3f(1.0,0.5,0.0);
 drawCube();
 glPopMatrix();
 
  glPushMatrix();
  glRotatef(-60,1.0,0.0,0.0);
 glTranslatef(-4.0,1.0,3.8);
 glScalef(0.1,3.0,0.1);
 glColor3f(1.0,0.5,0.0);
 drawCube();
 glPopMatrix();
 
   glPushMatrix();
  glRotatef(-60,1.0,0.0,0.0);
 glTranslatef(-5.5,1.0,3.8);
 glScalef(0.1,3.0,0.1);
 glColor3f(1.0,0.5,0.0); 
 drawCube();
 glPopMatrix();
 
 //tube base bar
  glPushMatrix();
  //glRotatef(-45,1.0,0.0,0.0);
 glTranslatef(0.0,2.5,3.5);
 glScalef(6,0.2,0.2);
 glColor3f(0.5,0.5,0.5);
 drawCube();
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


}

void megalabel(){
	 //Label
 glPushMatrix();
 glColor3f(1, 0, 0);
 glTranslatef(-5.0, 11.0, -10.0);
 show_label(0, 0, "Name: Megatherium");    
 //show_label(0, 0, "Description: No "); 
 glPopMatrix();
 
 
 glPushMatrix();
 glColor3f(0, 0, 0);
 glTranslatef(-5.0, 10.0, -10.0);
 show_name(0, 0, "Team Guyana Robotics 2017");   
 glPopMatrix();
 
 glPushMatrix();
 glColor3f(0, 0, 0);
 glTranslatef(-5.0, 9.0, -10.0);
 show_name(0, 0, "FIRST Global Competition Bot");   
 glPopMatrix();
}
