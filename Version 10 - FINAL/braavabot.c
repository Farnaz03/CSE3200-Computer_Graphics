void braavabot()
{
 //Front base
 glPushMatrix();
 glTranslatef(0.0,0.0,-0.5);
 glScalef(4.0,1.0,2.0);
 //glRotatef(angle,1.0,0.0,0.0);
 glColor3f(0.9,0.9,0.9);
 drawCube();
 glPopMatrix();
 
  //Back base
 glPushMatrix();
 glTranslatef(0.0,0.0,4.0);
 glScalef(4.0,1.0,2.0);
 //glRotatef(angle,1.0,0.0,0.0);
 glColor3f(0.9,0.9,0.9);
 drawCube();
 glPopMatrix();
 
  //Center
 glPushMatrix();
 glTranslatef(0.0, 1.5, 2.0);
 glScalef(2.9,2.9, 2.9);
 glRotatef(90, 1.0, 0.0, 0.0);
 glColor3f(0.9, 0.9, 0.9);
 myquad();
 glPopMatrix();
 
 //Center
 glPushMatrix();
 glTranslatef(0.0, 1.4, 2.0);
 glScalef(3.0,3.0, 3.0);
 glRotatef(90, 1.0, 0.0, 0.0);
 glColor3f(0.5, 0.8, 0.9);
 myquad();
 glPopMatrix();

 //Mop
 glPushMatrix();
 glTranslatef(0.0, -1.1, 4.5);
 glScalef(4.2,1.0,1.9);
 glRotatef(90, 1.0, 0.0, 0.0);
 glColor3f(0.5, 0.8, 0.9);
 myquad();
 glPopMatrix();
 
  //Mop2
 glPushMatrix();
 glTranslatef(0.0, -1.3, 4.5);
 glScalef(4.2,1.0,1.9);
 glRotatef(90, 1.0, 0.0, 0.0);
 glColor3f(0.5, 0.8, 0.9);
 myquad();
 glPopMatrix();
 

 int wheelloop3;
 for(wheelloop3 = 1; wheelloop3 < 7; wheelloop3++){
 float xvalue = 3 + (0.1*wheelloop3);

 glPushMatrix();
 glTranslatef(xvalue,0,0);
 glTranslatef(0,-0.5,0);
 //glTranslatef(0,0,0);
 glRotatef(90,0,1,0);
 wheels();
 glPopMatrix();
}
 int wheelloop2;
 for(wheelloop2 = 1; wheelloop2 < 7; wheelloop2++){
 float xvalue = -3 - (0.1*wheelloop2);

 glPushMatrix();
 glTranslatef(xvalue,0,0);
 glTranslatef(0,-0.5,0);
 //glTranslatef(0,0,0);
 glRotatef(90,0,1,0);
 wheels();
 glPopMatrix();
}
 
}

void braavalabel(){
 
/*  //Label Screen
 glPushMatrix();
 glTranslatef(0.0, 00.0, -10.0);
 glScalef(10.0,10.0,0.0);
 glColor3f(1.0,1.0,1.0);
 myquad();
 glPopMatrix(); 
 */
 
 //Label
 glPushMatrix();
 glColor3f(1, 0, 0);
 glTranslatef(8.0, 0.0, -5.0);  
 //glRotatef(90, 0.0, 0.0, 1.0); 
 show_label(0, 0, "Name: Braava Bot");    
 //show_label(0, 0, "Description: No "); 
 glPopMatrix(); 


 glPushMatrix();
 glColor3f(0, 0, 0);
 glTranslatef(8.0, -0.6, -5.0);  
 show_name(0, 0, "A cleaning robot");  
 glPopMatrix();
 
 glPushMatrix();
 glColor3f(0, 0, 0);
 glTranslatef(8, -1.1, -5.0);
 show_name(0, 0, "It has a mop");   
 glPopMatrix();
 
 glPushMatrix();
 glColor3f(0, 0, 0);
 glTranslatef(8.0, -1.6, -5.0);
 show_name(0, 0, "attached at the bottom");   
 glPopMatrix();
 /*
 /*Name on Robot
 glPushMatrix();
 glColor3f(0, 0, 0);
 glTranslatef(-1.0, 1.6, 2.0);  
 glRotatef(90, -1.0, 0.0, 0.0); 
 show_name(0, 0, "iRobot");    
 glPopMatrix(); */   
}
