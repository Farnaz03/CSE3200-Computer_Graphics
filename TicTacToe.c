#include <gl/glut.h>
void doInit() {
	glClearColor(0.0,0.0,0.0,0.0);

	/* Select the projection matrix and reset it */
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	
	/* setup drawing canvas / 2D coodinate*/
	//height & width x & y//
	gluOrtho2D(0,15,0,15);
}

void doDisplay() {

	/* Clear the screen with the clearcolor */
	glClear(GL_COLOR_BUFFER_BIT);
    
    //Set state to Red for Horizintal Lines
    glColor3f(1.0,0.0,0.0);
    
    //Setting the line parameters... 
    //horizontal lines
	glBegin(GL_LINES);          
		glVertex3f(3,6,0);
		glVertex3f(12,6,0);
	glEnd();
	
	glBegin(GL_LINES);          
		glVertex3f(3,9,0);
		glVertex3f(12,9,0);
	glEnd();

    //Set state to yellow for vertical Line
    glColor3f(1.0,1.0,0.0);
    
	//vertical lines
	glBegin(GL_LINES);          
		glVertex3f(6,3,0);
		glVertex3f(6,12,0);
	glEnd();
	
	glBegin(GL_LINES);          
		glVertex3f(9,3,0);
		glVertex3f(9,12,0);
	glEnd();

	glFlush();
}

int main(int argc, char *argv[]) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(480,480);
	glutInitWindowPosition(300,100);
	glutCreateWindow("CSE3200: Simple Line : Farnaz Baksh)");
	doInit();
	glutDisplayFunc(doDisplay);
	glutMainLoop();
	return 0;
}

