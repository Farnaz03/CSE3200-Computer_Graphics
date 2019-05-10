innovbuilding() {

//Lawn
 glPushMatrix();
 glRotatef(90,1.0,0.0,0.0);
 glTranslatef(0.0,0.0,5.0);
 glScalef(160.0,160.0,0.0);
 glColor3f(0.0,0.7,0.0);
 myquad();
 glPopMatrix();
	 
//Bottom front brown wall  	
 glPushMatrix();
 glTranslatef(-9.5,-2.0,8.0);
 glScalef(5.4,3.0,0.0);
 glColor3f(1.0,0.5,0.0);
 myquad();
 glPopMatrix();
 
//Top front brown wall  
 glPushMatrix();
 glTranslatef(-4.9,7.0,8.0);
 glScalef(10.0,6.0,0.0);
 glColor3f(1.0,0.5,0.0);
 myquad();
 glPopMatrix();
	 
//Top front glass wall
 glPushMatrix();
 glTranslatef(10.0,6.0,8.0);
 glScalef(5.0,5.5,10.0);
 glColor3f(1.0,1.0,1.0);
 myquad();
 glPopMatrix(); 
 
//Bottom front glass wall
 glPushMatrix();
 glTranslatef(8.0,-2.0,7.0);
 glColor3f(1.0,1.0,1.0);
 optimizedquad(7.0,3.0,0.0);
 glPopMatrix(); 
 
//Door
 glPushMatrix();
 glTranslatef(-1.7,-2.0,7.0);
 glColor3f(0.6,0.3,0.17);
 optimizedquad(2.7,3.0,0.0);
 glPopMatrix();  
 
//Columns Posts
 glPushMatrix();
 glTranslatef(4.0,-2.0,8.2);
 glColor3f(0.6,0.3,0.17);
 optimizedquad(0.3,3.0,0.0);
 glPopMatrix(); 
 
 glPushMatrix();
 glTranslatef(13.0,-2.3,8.2);
 glColor3f(0.6,0.3,0.17);
 optimizedquad(0.3,2.7,0.0);
 glPopMatrix(); 
 
//Window Lines for front walls
 
//Vertical Bottom glass wall lines
 glPushMatrix();
 glTranslatef(8.0,-2.0,7.1);
 glColor3f(0.2,0.2,0.2);
 optimizedquad(0.1,3.0,0.0);
 glPopMatrix();
 
 glPushMatrix();
 glTranslatef(12.0,-2.0,7.1);
 glColor3f(0.2,0.2,0.2);
 optimizedquad(0.1,3.0,0.0);
 glPopMatrix();
 
//Horizontal Bottom glass wall lines
 glPushMatrix();
 glTranslatef(8.0,-1.0,7.1);
 glColor3f(0.2,0.2,0.2);
 optimizedquad(7.0,0.1,0.0);
 glPopMatrix();
 
 glPushMatrix();
 glTranslatef(8.0,-3.0,7.1);
 glColor3f(0.2,0.2,0.2);
 optimizedquad(7.0,0.1,0.0);
 glPopMatrix();
	 
//Vertical upper glass wall lines
 glPushMatrix();
 glTranslatef(10.0,6.0,8.1);
 glColor3f(0.0,0.0,0.0);
 optimizedquad(0.1,5.5,0.0);
 glPopMatrix();
	 
 glPushMatrix();
 glTranslatef(5.0,6.0,8.1);
 glColor3f(0.0,0.0,0.0);
 optimizedquad(0.1,5.5,0.0);
 glPopMatrix();
	 
 glPushMatrix();
 glTranslatef(14.0,6.0,8.1);
 glColor3f(0.0,0.0,0.0);
 optimizedquad(0.1,5.5,0.0);
 glPopMatrix();
	 
//Horizontal upper glass wall lines
 glPushMatrix();
 glTranslatef(10.0,2.5,8.1);
 glColor3f(0.0,0.0,0.0);
 optimizedquad(5.0,0.1,0.0);
 glPopMatrix();
	 
 glPushMatrix();
 glTranslatef(10.0,5.0,8.1);
 glColor3f(0.0,0.0,0.0);
 optimizedquad(5.0,0.1,0.0);
 glPopMatrix();
	 
 glPushMatrix();
 glTranslatef(10.0,7.5,8.1);
 glColor3f(0.0,0.0,0.0);
 optimizedquad(5.0,0.1,0.0);
 glPopMatrix();
	 
 glPushMatrix();
 glTranslatef(10.0,10.0,8.1);
 glColor3f(0.0,0.0,0.0);
 optimizedquad(5.0,0.1,0.0);
 glPopMatrix();

 
 glPushMatrix();
 glTranslatef(10.0,0.5,8.1);
 glColor3f(0.0,0.0,0.0);
 optimizedquad(5.0,0.1,0.0);
 glPopMatrix();  
 
 /*
 glPushMatrix();
 glTranslatef(10.0,0.5,8.1);
 glScalef(5.0,0.1,0.0);
 glColor3f(0.0,0.0,0.0);
 myquad();
 glPopMatrix(); */
 
//Inner side wall near door
 glPushMatrix();
 glRotatef(90,0.0,1.0,0.0);
 glTranslatef(-7.0,-2.0,-4.3);
 glColor3f(1.0,0.6,0.0);
 optimizedquad(1.0,3.0,0.0);
 glPopMatrix();
 
//Inner ceiling for door and brown front
 glPushMatrix();
 glRotatef(90,1.0,0.0,0.0);
 glTranslatef(0,7.0,-1.0);
 glColor3f(1.0,0.65,0.0);
 optimizedquad(5.0,1.0,0.0);
 glPopMatrix();
 
//Inner ceiling for front glass
 glPushMatrix();
 glRotatef(90,1.0,0.0,0.0);
 glTranslatef(10,7.1,-0.5);
 glColor3f(0.9,0.9,0.9);
//glColor3f(0.9,0.0,0.9);
 optimizedquad(4.92,1.0,0.0);
 glPopMatrix();
	 
//Right Side - Upper Wall 
 glPushMatrix();
 glRotatef(90,0.0,1.0,0.0);
 glTranslatef(0.0,6.0,14.9);
 //glScalef(8.0,5.5,0.0);
 glColor3f(1.0,1.0,1.0);
 optimizedquad(8.0,5.5,0.0);
 glPopMatrix(); 
 
//Window Lines for Right Side - Upper glass wall
//Horizontal lines
 glPushMatrix();
 glRotatef(90,0.0,1.0,0.0);
 glTranslatef(0.0,10.0,15.0);
 glColor3f(0.0,0.0,0.0);
 optimizedquad(8.0,0.1,0.0);
 glPopMatrix();

 glPushMatrix();
 glRotatef(90,0.0,1.0,0.0);
 glTranslatef(0.0,7.5,15.0);
 glColor3f(0.0,0.0,0.0);
 optimizedquad(8.0,0.1,0.0);
 glPopMatrix();
 
 glPushMatrix();
 glRotatef(90,0.0,1.0,0.0);
 glTranslatef(0.0,5.0,15.0);
 glColor3f(0.0,0.0,0.0);
 optimizedquad(8.0,0.1,0.0);
 glPopMatrix(); 
 
 glPushMatrix();
 glRotatef(90,0.0,1.0,0.0);
 glTranslatef(0.0,2.5,15.0);
 glColor3f(0.0,0.0,0.0);
 optimizedquad(8.0,0.1,0.0);
 glPopMatrix(); 
 
 //Vertical windows lines - Right side glass wall
 glPushMatrix();
 glRotatef(90,0.0,1.0,0.0);
 glTranslatef(-7.0,3.2,15.0);
 glColor3f(0.0,0.0,0.0);
 optimizedquad(0.1,8.2,0.0);
 glPopMatrix(); 
 
 glPushMatrix();
 glRotatef(90,0.0,1.0,0.0);
 glTranslatef(-3.0,3.2,15.0);
 glColor3f(0.0,0.0,0.0);
 optimizedquad(0.1,8.2,0.0);
 glPopMatrix();

 glPushMatrix();
 glRotatef(90,0.0,1.0,0.0);
 glTranslatef(2.0,3.2,15.0);
 glColor3f(0.0,0.0,0.0);
 optimizedquad(0.1,8.2,0.0);
 glPopMatrix();
 
 glPushMatrix();
 glRotatef(90,0.0,1.0,0.0);
 glTranslatef(7.0,3.2,15.0);
 glColor3f(0.0,0.0,0.0);
 optimizedquad(0.1,8.2,0.0);
 glPopMatrix();
 
//Right Side - Lower Wall
 glPushMatrix();
 glRotatef(90,0.0,1.0,0.0);
 glTranslatef(0.5,-2.0,14.9);
 glColor3f(1.0,1.0,1.0);
 optimizedquad(7.5,3.0,0.0);
 glPopMatrix(); 
 
 //Window Lines for Right Side - Lower glass wall
//Horizontal lines
 glPushMatrix();
 glRotatef(90,0.0,1.0,0.0);
 glTranslatef(0.5,0.0,15.0);
 glColor3f(0.0,0.0,0.0);
 optimizedquad(7.5,0.1,0.0);
 glPopMatrix();
 
 glPushMatrix();
 glRotatef(90,0.0,1.0,0.0);
 glTranslatef(0.5,-2.5,15.0);
 glColor3f(0.0,0.0,0.0);
 optimizedquad(7.5,0.1,0.0);
 glPopMatrix();
 
 
//Left Side Wall
 glPushMatrix();
 glRotatef(90,0.0,1.0,0.0);
 glTranslatef(0.0,4.0,-14.9);
 glColor3f(1.0,0.5,0.0);
 optimizedquad(8.0,9.0,0.0);
 glPopMatrix(); 
 
//Back brown wall  
 glPushMatrix();
 glTranslatef(-4.9,4.0,-8.0);
 glColor3f(1.0,0.5,0.0);
 optimizedquad(10.0,9.0,0.0);
 glPopMatrix();
 
 //back-door -topboard
 glPushMatrix();
 glRotatef(90,1.0,0.0,0.0);
 glTranslatef(-5.0,-8.0,-1.0);
 glScalef(2.6,1.0,0.0);
 glColor3f(0.5,0.2,0.17);
 myquad();
 glPopMatrix();
 
 //back-door -leftboard
 glPushMatrix();
 glRotatef(90,0.0,1.0,0.0);
 glTranslatef(8.0,-3.0,-2.5);
 glScalef(1.0,4.0,0.0);
 glColor3f(0.5,0.2,0.17);
 myquad();
 glPopMatrix();
 
  //back-door -leftboard
 glPushMatrix();
 glRotatef(90,0.0,1.0,0.0);
 glTranslatef(8.0,-3.0,-7.5);
 glScalef(1.0,4.0,0.0);
 glColor3f(0.5,0.2,0.17);
 myquad();
 glPopMatrix();
 
   //back-door - inner quad
 glPushMatrix();
 glTranslatef(-4.9,-2.0,-8.2);
  glColor3f(0.6,0.3,0.17);
 optimizedquad(2.5,3.0,0.0);
 glPopMatrix();
 
	 
//Back glass wall
 glPushMatrix();
 glTranslatef(10.0,3.2,-8.0);
 glColor3f(1.0,1.0,1.0);
 optimizedquad(5.0,8.2,0.0);
 glPopMatrix();
 
//Window Lines for back glass walls

//Vertical upper glass wall lines
 glPushMatrix();
 glTranslatef(10.0,3.2,-8.1);
 glColor3f(0.0,0.0,0.0);
 optimizedquad(0.1,8.2,0.0);
 glPopMatrix();
 
 glPushMatrix();
 glTranslatef(5.0,3.2,-8.1);
 glColor3f(0.0,0.0,0.0);
 optimizedquad(0.1,8.2,0.0);
 glPopMatrix();
	 
 glPushMatrix();
 glTranslatef(14.0,3.2,-8.1);
 glColor3f(0.0,0.0,0.0);
 optimizedquad(0.1,8.2,0.0);
 glPopMatrix();
 
 
 //Horizontal upper glass wall lines
 glPushMatrix();
 glTranslatef(10.0,-2.5,-8.1);
 glColor3f(0.0,0.0,0.0);
 optimizedquad(5.0,0.1,0.0);
 glPopMatrix();
 
 glPushMatrix();
 glTranslatef(10.0,0.0,-8.1);
 glColor3f(0.0,0.0,0.0);
 optimizedquad(5.0,0.1,0.0);
 glPopMatrix();
 
 //Horizontal upper glass wall lines
 glPushMatrix();
 glTranslatef(10.0,2.5,-8.1);
 glColor3f(0.0,0.0,0.0);
 optimizedquad(5.0,0.1,0.0);
 glPopMatrix();
	 
 glPushMatrix();
 glTranslatef(10.0,5.0,-8.1);
 glColor3f(0.0,0.0,0.0);
 optimizedquad(5.0,0.1,0.0);
 glPopMatrix();
	 
 glPushMatrix();
 glTranslatef(10.0,7.5,-8.1);
 glColor3f(0.0,0.0,0.0);
 optimizedquad(5.0,0.1,0.0);
 glPopMatrix();
	 
 glPushMatrix();
 glTranslatef(10.0,10.0,-8.1);
 glColor3f(0.0,0.0,0.0);
 optimizedquad(5.0,0.1,0.0);
 glPopMatrix();


 //Top glass roof
 glPushMatrix();
 glRotatef(90,1.0,0.0,0.0);
 glTranslatef(10.0,0.0,-11.5);
 glColor3f(1.0,1.0,1.0);
 optimizedquad(5.0,8.0,0.0);
 glPopMatrix();
 
  //Top glass roof - frame lines
 glPushMatrix();
 glRotatef(90,1.0,0.0,0.0);
 glTranslatef(14.9,0.0,-11.6);
 glColor3f(0.0,0.0,0.0);
 optimizedquad(0.2,8.0,0.0);
 glPopMatrix();
 
 glPushMatrix();
 glRotatef(90,1.0,0.0,0.0);
 glTranslatef(5.15,0.0,-11.6);
 glColor3f(0.0,0.0,0.0);
 optimizedquad(0.2,8.0,0.0);
 glPopMatrix();

 glPushMatrix();
 glRotatef(90,1.0,0.0,0.0);
 glTranslatef(10.1,8.0,-11.6);
 glColor3f(0.0,0.0,0.0);
 optimizedquad(5.0,0.2,0.0);
 glPopMatrix();
 
 glPushMatrix();
 glRotatef(90,1.0,0.0,0.0);
 glTranslatef(10.1,-8.0,-11.6);
 glColor3f(0.0,0.0,0.0);
 optimizedquad(5.0,0.2,0.0);
 glPopMatrix();

 //Top Concrete roof
 glPushMatrix();
 glRotatef(90,1.0,0.0,0.0);
 glTranslatef(-5.0,0.0,-11.5);
 glColor3f(0.9,0.5,0.0);
 optimizedquad(9.9,8.0,0.0);
 glPopMatrix();
 
 
 //Label
 glPushMatrix();
 glColor3f(0, 0, 0);
 glTranslatef(-4.9,7.0,8.1);   
 show_label(-5, 0, "UG Innovation Center");    
 glPopMatrix(); 
 
 
}
