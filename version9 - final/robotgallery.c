void room() {

//Floor
 glPushMatrix();
 glRotatef(90,1.0,0.0,0.0);
 //glTranslatef(0.0,0.0,5.0);
 //glScalef(50.0,30.0,0.0);
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
