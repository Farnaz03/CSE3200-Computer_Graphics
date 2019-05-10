buildingOne() {
 
 //Short Building
 glPushMatrix();
 glTranslatef(-40.0,-4.0,45.0);
 glScalef(5,7,4);
 glColor3f(0.0,0.0,0.0);
 drawCube();
 glPopMatrix();
 
 
 //long building
  glPushMatrix();
 glTranslatef(-35.0,-4.0,45.0);
  glScalef(5,7,9);
 //glRotatef(angle,1.0,0.0,0.0);
 glColor3f(0.0,0.0,0.0);
 drawCube();
 glPopMatrix();
 
 
 //shadow
  glPushMatrix();
 glTranslatef(-40.0,-4.0,25.0);
 glScalef(5,0.1,5);
 //glRotatef(angle,1.0,0.0,0.0);
 glColor3f(0.3,0.6,0.1);
 drawCube();
 glPopMatrix();
 
 
  glPushMatrix();
  glTranslatef(-35.0,-4.0,25.0);
  glScalef(6,0.1,10);
 //glRotatef(angle,1.0,0.0,0.0);
 glColor3f(0.3,0.6,0.2);
 drawCube();
 glPopMatrix();
 
}

building2() {
		
 glPushMatrix();
 glTranslatef(-10.0,-4.0,45.0);
 glScalef(5,7,4);
 //glRotatef(angle,1.0,0.0,0.0);
 glColor3f(0.0,0.0,0.0);
 drawCube();
 glPopMatrix();
 
 
 //long building
  glPushMatrix();
 glTranslatef(0.0,-4.0,45.0);
 glScalef(9,7,6);
 //glRotatef(angle,1.0,0.0,0.0);
 glColor3f(0.0,0.0,0.0);
 drawCube();
 glPopMatrix();
 
  //shadow
  glPushMatrix();
 glTranslatef(-10.0,-4.0,32.0);
 glScalef(5,0.1,4);
 //glRotatef(angle,1.0,0.0,0.0);
 glColor3f(0.3,0.6,0.2);
 drawCube();
 glPopMatrix();
 
 
  glPushMatrix();
 glTranslatef(0.0,-4.0,32.0);
  glScalef(9,0.1,6);
 //glRotatef(angle,1.0,0.0,0.0);
 glColor3f(0.3,0.6,0.2);
 drawCube();
 glPopMatrix();
 
}

building3() {
		
 glPushMatrix();
 glTranslatef(-45.0,0.0,0.0);
 glScalef(4,7,7);
 //glRotatef(angle,1.0,0.0,0.0);
 glColor3f(0.0,0.0,0.0);
 drawCube();
 glPopMatrix();
 
 
 //long building
  glPushMatrix();
 glTranslatef(-40.0,0.0,0.0);
 glScalef(12,7,5);
 //glRotatef(angle,1.0,0.0,0.0);
 glColor3f(0.0,0.0,0.0);
 drawCube();
 glPopMatrix();
 
 //shadow
 glPushMatrix();
 glTranslatef(-42.0,-4.0,-16.9);
 glScalef(4,0.1,7);
 //glRotatef(angle,1.0,0.0,0.0);
 glColor3f(0.3,0.6,0.2);
 drawCube();
 glPopMatrix();
 
 
 //long building
  glPushMatrix();
 glTranslatef(-37.0,-4.0,-16.9);
 glScalef(12,0.1,5);
 //glRotatef(angle,1.0,0.0,0.0);
 glColor3f(0.3,0.6,0.2);
 drawCube();
 glPopMatrix();
 

}
