#include <gl/glut.h>
#include<math.h>

int mywidth = 228, myheight = 114;

void doInit() {
	glClearColor(0.0,0.0,0.0,0.0);

	/* Select the projection matrix and reset it */
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	
	/* setup drawing canvas / 2D coodinate*/
	//height & width x & y//
	gluOrtho2D(0,mywidth,0,myheight);
}

void doDisplay() {

	/* Clear the screen with the clearcolor */
	glClear(GL_COLOR_BUFFER_BIT);
    
    //Set state to Green
    glColor3f(0.,0.4,0.0);
    
		GLfloat p1[3] = {0,34,0}; 
		GLfloat p2[3] = {228,34,0}; 
		GLfloat p3[3] = {228,0,0}; 
		GLfloat p4[3] = {0,0,0};
	glBegin(GL_POLYGON); 
		glVertex3fv(p1); 
		glVertex3fv(p2); 
		glVertex3fv(p3); 
		glVertex3fv(p4); 
	glEnd();
	
	//Set state to white line
    glColor3f(1.0,1.0,1.0);
    
		GLfloat p5[3] = {0,40,0}; 
		GLfloat p6[3] = {228,40,0}; 
		GLfloat p7[3] = {228,34,0}; 
		GLfloat p8[3] = {0,34,0};
	glBegin(GL_POLYGON); 
		glVertex3fv(p5); 
		glVertex3fv(p6); 
		glVertex3fv(p7); 
		glVertex3fv(p8); 
	glEnd();
	
	//Set state to Red
    glColor3f(1.0,0.0,0.0);
    
		GLfloat p9[3] = {0,74,0}; 
		GLfloat p10[3] = {228,74,0}; 
		GLfloat p11[3] = {228,40,0}; 
		GLfloat p12[3] = {0,40,0};
	glBegin(GL_POLYGON); 
		glVertex3fv(p9); 
		glVertex3fv(p10); 
		glVertex3fv(p11); 
		glVertex3fv(p12); 
	glEnd();
	
	//Set state to white line
    glColor3f(1.0,1.0,1.0);
    
		GLfloat p13[3] = {0,80,0}; 
		GLfloat p14[3] = {228,80,0}; 
		GLfloat p15[3] = {228,74,0}; 
		GLfloat p16[3] = {0,74,0};
	glBegin(GL_POLYGON); 
		glVertex3fv(p13); 
		glVertex3fv(p14); 
		glVertex3fv(p15); 
		glVertex3fv(p16); 
	glEnd();
	
	//Set state to black
    glColor3f(0.0,0.0,0.0);
    
		GLfloat p17[3] = {0,114,0}; 
		GLfloat p18[3] = {228,114,0}; 
		GLfloat p19[3] = {228,80,0}; 
		GLfloat p20[3] = {0,80,0};
	glBegin(GL_POLYGON); 
		glVertex3fv(p17); 
		glVertex3fv(p18); 
		glVertex3fv(p19); 
		glVertex3fv(p20); 
	glEnd();
	
	glBegin(GL_POLYGON); 
	
	float triangleheight = sqrt((myheight*myheight) - ((myheight/2)*(myheight/2)));
	
		glColor3f(0.0, 0.0, 1.0);   // blue 
		glVertex3f(0.0, myheight, 0.0); 
		glVertex3f(triangleheight, myheight/2, 0.0); 
		glVertex3f(0.0, 0.0, 0.0); 
	glEnd();

	glFlush();
}

int main(int argc, char *argv[]) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(mywidth*2,myheight*2);
	glutInitWindowPosition(300,100);
	glutCreateWindow("CSE3200: Simple Line : Farnaz Baksh)");
	doInit();
	glutDisplayFunc(doDisplay);
	glutMainLoop();
	return 0;
}

