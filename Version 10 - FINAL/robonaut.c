void robonaut()
{  

 //Left foot
 glPushMatrix();
 glTranslatef(0.0,0.0,-0.5);
 glScalef(1.0,1.0,2.0);
 //glRotatef(angle,1.0,0.0,0.0);
 glColor3f(0.0,0.0,0.0);
 drawCube();
 glPopMatrix();
 
 //Right foot
 glPushMatrix();
 glTranslatef(5.0,0.0,-0.5);
 glScalef(1.0,1.0,2.0);
 glColor3f(0.0,0.0,0.0);
 drawCube();
 glPopMatrix();
 
 //Left Leg
 glPushMatrix();
 glTranslatef(0.0,3.0,-1.3);
 glScalef(1.0,2.0,1.0);
 glColor3f(0.5,0.5,0.5);
 drawCube();
 glPopMatrix();
 
  //Right Leg
 glPushMatrix();
 glTranslatef(5.0,3.0,-1.3);
 glScalef(1.0,2.0,1.0);
 glColor3f(0.5,0.5,0.5);
 drawCube();
 glPopMatrix();
 
  //Gray Base
 glPushMatrix();
 glTranslatef(2.5,5.5,-1.3);
 glScalef(3.5,0.7,1.0);
 glColor3f(0.5,0.5,0.5);
 drawCube();
 glPopMatrix();
 
 //Black Base
 glPushMatrix();
 glTranslatef(2.5,6.9,-1.3);
 glScalef(3.5,0.7,1.0);
 glColor3f(0.0,0.0,0.0);
 drawCube();
 glPopMatrix();
 
  //Body
 glPushMatrix();
 glTranslatef(2.5,10.5,-1.3);
 glScalef(3.5,2.5,2.0);
 glColor3f(1.9,0.9,0.9);
 drawCube();
 glPopMatrix();
 
 //Body Center
 glPushMatrix();
 glTranslatef(2.5,11.3,1.0);
 glScalef(2.0,1.5,1.0);
 glColor3f(0.5,0.5,0.5);
 drawCube();
 glPopMatrix();
 
 //Outline
 glPushMatrix();
 glTranslatef(1.2,7.9,1.3);
 glScalef(0.5,2.0,0.5);
 glColor3f(0.8,0.8,0.8);
 drawCube();
 glPopMatrix();
 
 glPushMatrix();
 glTranslatef(3.8,7.9,1.3);
 glScalef(0.5,2.0,0.5);
 glColor3f(0.8,0.8,0.8);
 drawCube();
 glPopMatrix();
 
 glPushMatrix();
 glTranslatef(-0.3,5.5,1.3);
 glScalef(2.0,0.5,0.5);
 glColor3f(0.8,0.8,0.8);
 drawCube();
 glPopMatrix();
 
 glPushMatrix();
 glTranslatef(5.3,5.5,1.3);
 glScalef(2.0,0.5,0.5);
 glColor3f(0.8,0.8,0.8);
 drawCube();
 glPopMatrix();
 
 glPushMatrix();
 glTranslatef(7.0,5.5,-0.2);
 glScalef(0.5,0.5,2.0);
 glColor3f(0.8,0.8,0.8);
 drawCube();
 glPopMatrix();
 
 glPushMatrix();
 glTranslatef(-2.0,5.5,-0.2);
 glScalef(0.5,0.5,2.0);
 glColor3f(0.8,0.8,0.8);
 drawCube();
 glPopMatrix();
 
 //Right Hand
 glPushMatrix();
 glTranslatef(7.0,12.0,-1.3);
 glScalef(1.0,1.0,1.0);
 glColor3f(1.9,0.9,0.9);
 drawCube();
 glPopMatrix();
 
 glPushMatrix();
 glTranslatef(7.1,9.7,-1.3);
 glScalef(0.9,1.2,0.9);
 glColor3f(0.5,0.5,0.5);
 drawCube();
 glPopMatrix();
 
 glPushMatrix();
 glTranslatef(7.1,7.6,-1.3);
 glScalef(0.9,0.9,0.9);
 glColor3f(0.0,0.0,0.0);
 drawCube();
 glPopMatrix(); 
 
  //Left Hand
 glPushMatrix();
 glTranslatef(-2.0,12.0,-1.3);
 glScalef(1.0,1.0,1.0);
 glColor3f(1.9,0.9,0.9);
 drawCube();
 glPopMatrix();
 
 glPushMatrix();
 glTranslatef(-2.1,9.7,-1.3);
 glScalef(0.9,1.2,0.9);
 glColor3f(0.5,0.5,0.5);
 drawCube();
 glPopMatrix();
 
 glPushMatrix();
 glTranslatef(-2.1,7.6,-1.3);
 glScalef(0.9,0.9,0.9);
 glColor3f(0.0,0.0,0.0);
 drawCube();
 glPopMatrix();
 
 //Head
 glPushMatrix();
 glTranslatef(2.5,15.5,-2.0);
 glScalef(3.5,2.5,0.7);
 glColor3f(1.9,0.9,0.9);
 drawCube();
 glPopMatrix();
 
 glPushMatrix();
 glTranslatef(2.5,15.7,-1.0);
 glScalef(2.1,2.3,0.2);
 glColor3f(0.0,0.0,0.0);
 drawCube();
 glPopMatrix();
 
 //Face
 glPushMatrix();
 glTranslatef(2.5,15.8,-0.8);
 glScalef(2.0,2.0,1.0);
 glColor3f(0.6,0.7,0.7);
 drawCube();
 glPopMatrix();
 
 //Back
 glPushMatrix();
 glTranslatef(2.5,15.0,-3.7);
 glScalef(4.3,3.0,0.7);
 glColor3f(0.5, 0.5, 0.5);
 drawCube();
 glPopMatrix();
 
 //Back
 glPushMatrix();
 glTranslatef(0.0,14.0,-1.0);
 glScalef(0.5, 0.5, 0.5);
 glColor3f(0.5,0.5,0.5);
 drawCube();
 glPopMatrix();
 
}

void robonautlabel(){
 
/*  //Label Screen
 glPushMatrix();
 glTranslatef(0.0, 00.0, -10.0);
 glScalef(10.0,10.0,0.0);
 glColor3f(1.0,1.0,1.0);
 myquad();
 glPopMatrix(); */
 
 
 //Label
 glPushMatrix();
 glColor3f(1, 0, 0);
 glTranslatef(0.0, 0.0, -5.0);  
 //glRotatef(90, 0.0, 0.0, 1.0); 
 show_label(0, 0, "Name: Robonaut");    
 //show_label(0, 0, "Description: No "); 
 glPopMatrix(); 


 glPushMatrix();
 glColor3f(0, 0, 0);
 glTranslatef(0.0, -0.6, -5.0);  
 show_name(0, 0, "This is a useless");  
 glPopMatrix();
 
 glPushMatrix();
 glColor3f(0, 0, 0);
 glTranslatef(0, -1.1, -5.0);
 show_name(0, 0, "robot built for ");   
 glPopMatrix();
 
 glPushMatrix();
 glColor3f(0, 0, 0);
 glTranslatef(0.0, -1.6, -5.0);
 show_name(0, 0, "showcase");   
 glPopMatrix();
 
 /*Name on Robot
 glPushMatrix();
 glColor3f(0, 0, 0);
 glTranslatef(-1.0, 1.6, 2.0);  
 glRotatef(90, -1.0, 0.0, 0.0); 
 show_name(0, 0, "iRobot");    
 glPopMatrix(); 
 } */
}

void roomart(){
	
 glPushMatrix();
 glColor3f(1, 0, 0);
 glTranslatef(0.0, 0.0, -5.0);  
 //glRotatef(90, 0.0, 0.0, 1.0); 
 show_label(0, 0, "ROBOTICS");    
 //show_label(0, 0, "Description: No "); 
 glPopMatrix(); 


 glPushMatrix();
 glColor3f(1, 1, 0);
 glTranslatef(0.0, -0.6, -5.0);  
 show_label(0, 0, "IS");  
 glPopMatrix();
 
 glPushMatrix();
 glColor3f(0.5, 1, 0);
 glTranslatef(0, -1.1, -5.0);
 show_label(0, 0, "AWESOME");  
 glPopMatrix();

}
