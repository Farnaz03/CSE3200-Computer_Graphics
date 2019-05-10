///////////////////////////////////////////////////////////////////////////////
// A-Team Project --- UG Innovation Center
// University of Guyana
// Department of Computer Science
///////////////////////////////////////////////////////////////////////////////

#include <stdlib.h>
#include <float.h>
#include <time.h>	
#include <stdio.h>
#include <GL/glut.h>
#include <math.h>
#include <gl\gl.h>
#include <gl\glu.h>
#include <stdarg.h>

//#include "innovbuilding.c"
#include "buildings.c"
//#include "robotgallery.c"

#include "braavabot.c"
#include "karenbot.c"
#include "mega.c"
#include "robonaut.c"

GLuint texture[5];

static int x_rotation = 0, y_rotation = 0,  z_rotation = 0;

// vertex coords array
static GLfloat theta[] = {0.0,0.0,0.0};
static GLint axis = 1;


struct Image {
    unsigned long sizeX;
    unsigned long sizeY;
    char *data;
};

typedef struct Image Image;
#define checkImageWidth 64
#define checkImageHeight 64

GLubyte checkImage[checkImageWidth][checkImageHeight][3];


//Keyboard Variable
float angle=0.0;
float r=1.0,g=0.0,bl=0.0,a=0,b=0;
float x=0.0f,y=1.75f,z=5.0f; //camera viewpoint
float lx=0.0f,ly=0.0f,lz=-1.0f;
float ratio=1.0;

GLfloat vertices[] = {1,1,1,  -1,1,1,  -1,-1,1,  1,-1,1,        // v0-v1-v2-v3
                      1,1,1,  1,-1,1,  1,-1,-1,  1,1,-1,        // v0-v3-v4-v5
                      1,1,1,  1,1,-1,  -1,1,-1,  -1,1,1,        // v0-v5-v6-v1
                      -1,1,1,  -1,1,-1,  -1,-1,-1,  -1,-1,1,    // v1-v6-v7-v2
                      -1,-1,-1,  1,-1,-1,  1,-1,1,  -1,-1,1,    // v7-v4-v3-v2
                      1,-1,-1,  -1,-1,-1,  -1,1,-1,  1,1,-1};   // v4-v7-v6-v5

GLfloat colors[] = {1,1,1,  1,1,1,  1,1,1,  1,1,1,              // v0-v1-v2-v3
                    1,1,0,  1,1,0,  1,1,0,  1,1,0,              // v0-v3-v4-v5
                    1,0,1,  1,0,1,  1,0,1,  1,0,1,              // v0-v5-v6-v1
                    0,1,0,  0,1,0,  0,1,0,  0,1,0,              // v1-v6-v7-v2
                    0,1,1,  0,1,1,  0,1,1,  0,1,1,              // v7-v4-v3-v2
                    0,0,1,  0,0,1,  0,0,1,  0,0,1};             // v4-v7-v6-v5
	
              
void drawCube(){
 glEnableClientState(GL_VERTEX_ARRAY);
 glColorPointer(3, GL_FLOAT, 0, colors);
 glVertexPointer(3, GL_FLOAT, 0, vertices);
 glDrawArrays(GL_QUADS, 0, 24);
}

void drawLines(){
	
	//x-line
	glColor3f(1.0,0.0,0.0);
	glBegin(GL_LINES);
	glVertex3f(20.0,0.0,0.0);
	glVertex3f(-20.0,0.0,0.0);
	glEnd();
		
	//y-line
	glColor3f(0.0,1.0,0.0);
	glBegin(GL_LINES);
	glVertex3f(0.0,20.0,0.0);
	glVertex3f(0.0,-20.0,0.0);
	glEnd();
		
	//z-line
	glColor3f(0.0,0.0,1.0);
	glBegin(GL_LINES);
	glVertex3f(0.0,0.0,20.0);
	glVertex3f(0.0,0.0,-20.0);
	glEnd();
}
	

void myquad(){
	//implement scale function
	glBegin(GL_QUADS);
	glVertex3f(-1.0,1.0,0.0);
	glVertex3f(1.0,1.0,0.0);
	glVertex3f(1.0,-1.0,0.0);
	glVertex3f(-1.0,-1.0,0.0);
	glEnd();
}

void optimizedquad(float x, float y, float z){
	glScalef(x, y, z);
	myquad();
}

void mytexturequad(){
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texture[0]);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0, 0.0);	glVertex3f(-1.0,1.0,0.0);
	glTexCoord2f(1.0, 0.0); glVertex3f(1.0,1.0,0.0);
	glTexCoord2f(1.0, 1.0); glVertex3f(1.0,-1.0,0.0);
	glTexCoord2f(0.0, 1.0); glVertex3f(-1.0,-1.0,0.0);
	//glScalef(x, y, z);
	
	glEnd();
	glDisable(GL_TEXTURE_2D);
}

void myglassquad(){
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texture[3]);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0, 0.0);	glVertex3f(-1.0,1.0,0.0);
	glTexCoord2f(1.0, 0.0); glVertex3f(1.0,1.0,0.0);
	glTexCoord2f(1.0, 1.0); glVertex3f(1.0,-1.0,0.0);
	glTexCoord2f(0.0, 1.0); glVertex3f(-1.0,-1.0,0.0);
	//glScalef(x, y, z);	
	glEnd();
	glDisable(GL_TEXTURE_2D);
} 
/*
void mygrassquad(){
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texture[4]);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0, 0.0);	glVertex3f(-1.0,1.0,0.0);
	glTexCoord2f(1.0, 0.0); glVertex3f(1.0,1.0,0.0);
	glTexCoord2f(1.0, 1.0); glVertex3f(1.0,-1.0,0.0);
	glTexCoord2f(0.0, 1.0); glVertex3f(-1.0,-1.0,0.0);
	//glScalef(x, y, z);	
	glEnd();
	glDisable(GL_TEXTURE_2D);
} */

void makeCheckImage(void){
    int i, j, c;
    for (i = 0; i < checkImageWidth; i++) {
        for (j = 0; j < checkImageHeight; j++) {
            c = ((((i&0x8)==0)^((j&0x8)==0)))*255;
            checkImage[i][j][0] = (GLubyte) c;
            checkImage[i][j][1] = (GLubyte) c;
            checkImage[i][j][2] = (GLubyte) c;
        }
    }
}

int ImageLoad(char *filename, Image *image) {
    FILE *file;
    unsigned long size; // size of the image in bytes.
    unsigned long i; // standard counter.
    unsigned short int planes; // number of planes in image (must be 1)
    unsigned short int bpp; // number of bits per pixel (must be 24)
    char temp; // temporary color storage for bgr-rgb conversion.
    // make sure the file is there.
    if ((file = fopen(filename, "rb"))==NULL){
        printf("File Not Found : %s\n",filename);
        return 0;
    }
    // seek through the bmp header, up to the width/height:
    fseek(file, 18, SEEK_CUR);
    // read the width
    if ((i = fread(&image->sizeX, 4, 1, file)) != 1) {
        printf("Error reading width from %s.\n", filename);
        return 0;
    }
    //printf("Width of %s: %lu\n", filename, image->sizeX);
    // read the height
    if ((i = fread(&image->sizeY, 4, 1, file)) != 1) {
        printf("Error reading height from %s.\n", filename);
        return 0;
    }
    //printf("Height of %s: %lu\n", filename, image->sizeY);
    // calculate the size (assuming 24 bits or 3 bytes per pixel).
    size = image->sizeX * image->sizeY * 3;
    // read the planes
    if ((fread(&planes, 2, 1, file)) != 1) {
        printf("Error reading planes from %s.\n", filename);
        return 0;
    }
    if (planes != 1) {
        printf("Planes from %s is not 1: %u\n", filename, planes);
        return 0;
    }
    // read the bitsperpixel
    if ((i = fread(&bpp, 2, 1, file)) != 1) {
        printf("Error reading bpp from %s.\n", filename);
        return 0;
    }
    if (bpp != 24) {
        printf("Bpp from %s is not 24: %u\n", filename, bpp);
        return 0;
    }
    // seek past the rest of the bitmap header.
    fseek(file, 24, SEEK_CUR);
    // read the data.
    image->data = (char *) malloc(size);
    if (image->data == NULL) {
        printf("Error allocating memory for color-corrected image data");
        return 0;
    }
    if ((i = fread(image->data, size, 1, file)) != 1) {
        printf("Error reading image data from %s.\n", filename);
        return 0;
    }
    for (i=0;i<size;i+=3) { // reverse all of the colors. (bgr -> rgb)
        temp = image->data[i];
        image->data[i] = image->data[i+2];
        image->data[i+2] = temp;
    }
    // we're done.
    return 1;
}

//***Texture Image***//
Image * loadTexture(){
    Image *image1;
    // allocate space for texture
    image1 = (Image *) malloc(sizeof(Image));
    if (image1 == NULL) {
        printf("Error allocating space for image");
        exit(0);
    }
    if (!ImageLoad("brownwall.bmp", image1)) {
        exit(1);
    }
    return image1;
}

Image * loadTexture2(){
    Image *image2;
    // allocate space for texture
    image2 = (Image *) malloc(sizeof(Image));
    if (image2 == NULL) {
        printf("Error allocating space for image");
        exit(0);
    }
    if (!ImageLoad("glass.bmp", image2)) {
        exit(1);
    }
    return image2;
}
/*
Image * loadTexture3(){
    Image *image3;
    // allocate space for texture
    image3 = (Image *) malloc(sizeof(Image));
    if (image3 == NULL) {
        printf("Error allocating space for image");
        exit(0);
    }
    if (!ImageLoad("grass.bmp", image3)) {
        exit(1);
    }
    return image3;
} */

//*********************TREEEEEEEEEEEEEEEEEEEEEEEEEEE**************************//
GLuint makeaTree;
//float x,y,z;

void makeCylinder(float height, float base){
GLUquadric *obj = gluNewQuadric();
//gluQuadricDrawStyle(obj, GLU_LINE);
//glColor3f(0.64f, 0.16, 0.16f);
 glColor3f(0.0,0.2,0.0);
 glPushMatrix();
 glRotatef(-90, 1.0,0.0,0.0);
 gluCylinder(obj, base,base-(0.2*base), height, 20,20);
 glPopMatrix();
glutSwapBuffers();
}

void makeTree(float height, float base){
float angle;
 makeCylinder(height, base); glTranslatef(0.0, height, 0.0);
 height -= height*.2; base-= base*0.3;
int a;
for(a= 0; a<3; a++){
	angle = rand()%50+20;
if(angle >48)
	angle = -(rand()%50+20);
if (height >1){
 glPushMatrix();
 glRotatef(angle,1,0.0,1);
 makeTree(height,base);
 glPopMatrix();
}
}
}

void makeTree2(float height, float base){
float angle;
 makeCylinder(height, base); glTranslatef(0.0, height, 0.0);
 height -= height*.2; base-= base*0.3;
int a;
for(a= 0; a<3; a++){
	angle = -rand()%50+20;
if(angle >48)
	angle = (rand()%50+20);
if (height >1){
 glPushMatrix();
 glRotatef(angle,1,0.0,1);
 makeTree(height,base);
 glPopMatrix();
}
}
}
//****************************************************************************//


void wheels(){
	//Wheels
    float x1,y1,x2,y2;
	float angle;
	double radius=1.0;

	x1 = 0,y1=0;
	glColor3f(0.0,0.0,0.0);

	glBegin(GL_TRIANGLE_FAN);
	glVertex2f(x1,y1);
	for (angle=1.0f;angle<360.0f;angle+=0.2)
	{
		x2 = x1+sin(angle)*radius;
		y2 = y1+cos(angle)*radius;
		glVertex2f(x2,y2);
		glRotatef(angle,1.0,0.0,0.0);
	}
	glEnd();
}

void init(void)
{
 glClearColor (0.53, 0.81, 0.92, 0.0);
 glShadeModel (GL_FLAT);
 glEnable (GL_DEPTH_TEST);  //turn on depth(z-axis) buffer
 
 //glEnable( GL_TEXTURE_2D );
    glDepthFunc(GL_LESS);
//	Image *image2 = loadTexture2();
    Image *image1 = loadTexture();
    Image *image2 = loadTexture2();
    //Image *image3 = loadTexture3();
    if(image1 == NULL){
        printf("Image was not returned from loadTexture\n");
        exit(0);
    }
    makeCheckImage();
    glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
    // Create Texture
    glGenTextures(5, texture);
    
    glBindTexture(GL_TEXTURE_2D, texture[0]);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR); //scale linearly when image bigger than texture
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR); //scale linearly when image smalled than texture
    glTexImage2D(GL_TEXTURE_2D, 0, 3, image1->sizeX, image1->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, image1->data);
    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);

   glBindTexture(GL_TEXTURE_2D, texture[3]);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR); //scale linearly when image bigger than texture
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR); //scale linearly when image smalled than texture
    glTexImage2D(GL_TEXTURE_2D, 0, 3, image2->sizeX, image2->sizeY, 0,
    GL_RGB, GL_UNSIGNED_BYTE, image2->data);
    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL); 
/*    
     glBindTexture(GL_TEXTURE_2D, texture[4]);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR); //scale linearly when image bigger than texture
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR); //scale linearly when image smalled than texture
    glTexImage2D(GL_TEXTURE_2D, 0, 3, image3->sizeX, image3->sizeY, 0,
    GL_RGB, GL_UNSIGNED_BYTE, image3->data);
    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL); 
*/	
	glBindTexture(GL_TEXTURE_2D, texture[1]);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);
    glTexImage2D(GL_TEXTURE_2D, 0, 3, checkImageWidth,

    checkImageHeight, 0, GL_RGB, GL_UNSIGNED_BYTE,&checkImage[0][0][0]);

    glEnable(GL_TEXTURE_2D);
    glShadeModel(GL_FLAT);

 //*********************************************************//
 makeaTree=glGenLists(1);
 glNewList(makeaTree, GL_COMPILE);
 makeTree2(3,0.2);
 glEndList();
}

//Text output Method 
void show_label(GLfloat x, GLfloat y, char *format,...)
{
  va_list args;
  char buffer[200], *p;

  va_start(args, format);
  vsprintf(buffer, format, args);
  va_end(args);
  glPushMatrix();
  glTranslatef(x, y, 0);
  glScalef(0.006, 0.006, 0.006);
  for (p = buffer; *p; p++)
    glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN, *p);
  glPopMatrix();
}


//Text output 2 Method 
void show_name(GLfloat x, GLfloat y, char *format,...)
{
  va_list args;
  char buffer[200], *p;

  va_start(args, format);
  vsprintf(buffer, format, args);
  va_end(args);
  glPushMatrix();
  glTranslatef(x, y, 0);
  glScalef(0.004, 0.0041, 0.004);
  for (p = buffer; *p; p++)
    glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN, *p);
  glPopMatrix();
}

/****************OUTSIDE THE INNOVATION BUILDING**********************/
void innovbuilding() {

//Lawn
 glPushMatrix();
 glRotatef(90,1.0,0.0,0.0);
 glTranslatef(0.0,0.0,5.0);
 glScalef(160.0,160.0,0.0);
 glColor3f(0.0,0.7,0.0);
 myquad();
// mygrassquad();
 glPopMatrix();
	 
//Bottom front brown wall  	
 glPushMatrix();
 glTranslatef(-9.5,-2.0,8.0);
 glScalef(5.4,3.0,0.0);
 glColor3f(1.0,0.5,0.0);
 //myquad();
 mytexturequad();
 glPopMatrix();
 
//Top front brown wall  
 glPushMatrix();
 glTranslatef(-4.9,7.0,8.0);
 glScalef(10.0,6.0,0.0);
 glColor3f(1.0,0.5,0.0);
 mytexturequad();
 glPopMatrix();
	 
//Top front glass wall
 glPushMatrix();
 glTranslatef(10.0,6.0,8.0);
 glScalef(5.0,5.5,10.0);
 glColor3f(1.0,1.0,1.0);
 myglassquad();
 glPopMatrix(); 
 
//Bottom front glass wall
 glPushMatrix();
 glTranslatef(8.0,-2.0,7.0);
 glColor3f(1.0,1.0,1.0);
 //optimizedquad(7.0,3.0,0.0);
 glScalef(7.0,3.0,0.0);
 myglassquad();
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
 glColor3f(0.0,0.0,0.0);
 optimizedquad(0.1,3.0,0.0);
 glPopMatrix();
 
 glPushMatrix();
 glTranslatef(12.0,-2.0,7.1);
 glColor3f(0.0,0.0,0.0);
 optimizedquad(0.1,3.0,0.0);
 glPopMatrix();
 
//Horizontal Bottom glass wall lines
 glPushMatrix();
 glTranslatef(8.0,-1.0,7.1);
 glColor3f(0.0,0.0,0.0);
 optimizedquad(7.0,0.1,0.0);
 glPopMatrix();
 
 glPushMatrix();
 glTranslatef(8.0,-3.0,7.1);
 glColor3f(0.0,0.0,0.0);
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
 //glColor3f(1.0,0.6,0.0);
 glColor3f(0.5,0.2,0.17);
 optimizedquad(1.0,3.0,0.0);
 glPopMatrix();
 
//Inner ceiling for door and brown front
 glPushMatrix();
 glRotatef(90,1.0,0.0,0.0);
 glTranslatef(0,7.0,-1.0);
 //glColor3f(1.0,0.65,0.0);
 glColor3f(0.5,0.2,0.17);
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
 glScalef(8.0,5.5,0.0);
 myglassquad();
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
 glScalef(7.5,3.0,0.0);
 myglassquad();
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
 glScalef(8.0,9.0,0.0);
 mytexturequad();
 glPopMatrix(); 
 
//Back brown wall  
 glPushMatrix();
 glTranslatef(-4.9,4.0,-8.0);
 glColor3f(1.0,0.5,0.0);
 glScalef(10.0,9.0,0.0);
 mytexturequad();
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
 glTranslatef(8.0,-2.0,-2.5);
 glScalef(1.0,3.0,0.0);
 glColor3f(0.5,0.2,0.17);
 myquad();
 glPopMatrix();
 
  //back-door -leftboard
 glPushMatrix();
 glRotatef(90,0.0,1.0,0.0);
 glTranslatef(8.0,-2.0,-7.5);
 glScalef(1.0,3.0,0.0);
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
 glScalef(5.0,8.2,0.0);
 myglassquad();
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
 glScalef(5.0,8.0,0.0);
 myglassquad();
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
 //glColor3f(0.9,0.5,0.0);
 glColor3f(0.5,0.2,0.17);
 optimizedquad(9.9,8.0,0.0);
 glPopMatrix();
 
 
 //Label
 glPushMatrix();
 glColor3f(0, 0, 0);
 glTranslatef(-4.9,7.0,8.1);   
 show_label(-5, 0, "UG Innovation Center");    
 glPopMatrix(); 
 
}
/****************INSIDE THE BUILDING - ROBOT GALLERY ROOM**********************/
void room() {

//Floor
 glPushMatrix();
 glRotatef(90,1.0,0.0,0.0);
 glTranslatef(0.0,0.0,1.0);
 glScalef(14.5,6.0,0.0);
 glColor3f(0.3,0.2,0.1);
 myquad();
 glPopMatrix();
 
 //Left Side Wall
 glPushMatrix();
 glRotatef(90,0.0,1.0,0.0);
 glTranslatef(0.0,3.0,-14.0);
 glColor3f(0.98,0.98,0.98);
 glScalef(8.0,8.0,0.0);
 myquad();
 glPopMatrix(); 
 
 //Back wall
 glPushMatrix();
 glTranslatef(0.0,3.0,-7.0);
 glColor3f(0.95,0.95,0.95);
 glScalef(14.0,8.0,0.0);
 myquad();
 glPopMatrix();
 
 //Front wall
 glPushMatrix();
 glTranslatef(0.0,3.0,6.0);
 glColor3f(1.0,1.0,1.0);
 glScalef(14.0,8.0,0.0);
 myquad();
 glPopMatrix();

 //Right Side Wall
 glPushMatrix();
 glRotatef(90,0.0,1.0,0.0);
 glTranslatef(0.0,3.0,14.0);
 glColor3f(0.98,0.98,0.98);
 glScalef(7.0,8.0,0.0);
 myquad();
 glPopMatrix(); 
 
 
 //Braava Shelf
 int st; //shelf thickness
 for (st = 0; st < 15; st++){
 float stval = (2.0 + (st*0.01));
 glPushMatrix();
 glColor3f(0.6,0.6,0.6);
 glTranslatef(8.0,stval,0.0);
 glTranslatef(0.0,0.0,-5.0);
 glRotatef(-90,1.0,0.0,0.0);
 glScalef(1.5,1.0,0.0);
 myquad();
 glPopMatrix();
}

}

void display(void)
{
 glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
 glRotatef((GLfloat) x_rotation, 1, 0 ,0);
 glRotatef((GLfloat) y_rotation, 0, 1 ,0);
 glRotatef((GLfloat) z_rotation, 0, 0 ,1); 	

// drawLines(); 
 
 //trees
glPushMatrix();
glTranslatef(18.0,-5.0,7.0); 
glScalef(1.5,1.5,1.5);
glCallList(makeaTree);
glPopMatrix();

glPushMatrix();
glTranslatef(-22.0,-5.0,7.0); 
glScalef(1.5,1.5,1.5);
glCallList(makeaTree);
glPopMatrix();

glPushMatrix();
glTranslatef(-22.0,-8.0,7.0); 
glScalef(1.0,1.0,1.0);
glCallList(makeaTree);
glPopMatrix();

glPushMatrix();
glTranslatef(-22.0,-8.0,7.0); 
glScalef(1.7,1.3,1.7);
glCallList(makeaTree);
glPopMatrix();

glPushMatrix();
glTranslatef(-14.0,-8.0,15.0); 
glScalef(1.7,1.3,1.7);
glCallList(makeaTree);
glPopMatrix();

glPushMatrix();
glTranslatef(-14.0,-8.0,25.0); 
glScalef(1.7,1.3,1.7);
glCallList(makeaTree);
glPopMatrix();

glPushMatrix();
glTranslatef(-20.0,-8.0,30.0); 
glScalef(1.7,1.3,1.7);
glCallList(makeaTree);
glPopMatrix();

//fake shadow
 glPushMatrix();
 glRotatef(90,1.0,0.0,0.0);
 glTranslatef(0.0,-19.5,4.9);
 glScalef(15.5,10.0,0.0);
 glColor3f(0.3,0.6,0.2);
 myquad();
 glPopMatrix();
	  

 //Main Building
 glPushMatrix();
// glScalef(50.0, 50.0, 50.0);
  innovbuilding();
  room();
 glPopMatrix();
 
/* //Inside - Room
 glPushMatrix();
 glTranslatef(0.0,0.0,0.0);
 glScalef(5.0,5.0,5.0);
 room();
 glPopMatrix();
*/
 buildingOne();
 
 building2();
 
 building3(); 
 
 
 //Braava Bot
 glPushMatrix();
 glTranslatef(8.0,2.5,-5.0);
 glScalef(0.2,0.2,0.2);
 braavabot();
 glPopMatrix(); 
 
 glPushMatrix();
 glTranslatef(4.0,1.5,-6.0);
 glScalef(0.3,0.3,0.0);
 braavalabel();
 glPopMatrix();
 
 //Karen Bot
 glPushMatrix();
 glTranslatef(-8.0, 0.4, -4.0);
 glScalef(0.25,0.25,0.25);
 karenbot();
 glPopMatrix();
 
 glPushMatrix();
 glTranslatef(-10.0,-1.4,-6.0);
 glScalef(0.3,0.3,0.0);
 karenlabel();
 glPopMatrix();
 
 //Robonaut bot
 glPushMatrix();
 glRotatef(270,0.0,1.0,0.0);
 glTranslatef(0.0, 0.0, -8.0);
 glScalef(0.16,0.2,0.1);
 robonaut();
 glPopMatrix();
 
 glPushMatrix();
 glRotatef(270,0.0,1.0,0.0);
 glTranslatef(1.6,2.0,-9.5);
 glScalef(0.2,0.2,0.0);
 robonautlabel();
 glPopMatrix(); 
 
 
 
 //Megatherium bot
 glPushMatrix();
 glTranslatef(0.0, -0.8, -4.0);
 glScalef(0.2,0.2,0.2);
 mega();
 glPopMatrix();
 
 glPushMatrix();
 glTranslatef(0.0,-1.4,-6.0);
 glScalef(0.3,0.3,0.0);
 megalabel();
 glPopMatrix();
 
  glPushMatrix();
  glRotatef(90,0.0,1.0,0.0);
  glTranslatef(-3.0,4.0,-9.0);
  glScalef(0.5,0.5,0.0);
  roomart();
  glPopMatrix();
 
 glutSwapBuffers();    //instead of using GLflush you're swapping buffers
}
	
void reshape(int w, int h)
{
     glViewport(0,0, (GLsizei)w, (GLsizei)h);
     glMatrixMode(GL_PROJECTION);
     glLoadIdentity();
     gluPerspective (60, (GLfloat)w / (GLfloat)h, 1.0, 200.0);
     glMatrixMode(GL_MODELVIEW);    
     glLoadIdentity(); //clear the main matrix
     gluLookAt(45,25,45,0,0,0,0,1,0); //controls the position of camera, the 1st 3 values defines the position,
                                      //second 3 values is where the camera is looking at
                                      //marks where up is, in this case y is where up is, usually the y.
}
//Movement Function 1
void orientMe(float ang) {
	lx = sin(ang);
	lz = -cos(ang);
	glLoadIdentity();
	gluLookAt(x, y, z, 
		      x + lx,y + ly,z + lz,
			  0.0f,1.0f,0.0f);
}

//Movement Function 2
void moveside(int i) {
	x = x + i*(lx)*0.2;
	z = z + i*(lz)*0.2;
	glLoadIdentity();
	gluLookAt(x, y, z, 
		      x + lx,y + ly,z + lz,
			  0.0f,1.0f,0.0f);
}

//Keyboard Function
void keyboard (unsigned char key, int x, int y)
{
    switch (key) 
     {
    case 'x':
    x_rotation = 15;
    y_rotation = 0;
    z_rotation = 0;
    glutPostRedisplay();
    break;
    case 'y':
    y_rotation = 15;
    x_rotation = 0;
    z_rotation = 0;
    glutPostRedisplay();
    break;
    case 'z':
    z_rotation = 15;
    y_rotation = 0;
    x_rotation = 0;
    glutPostRedisplay();
    break;
    
	case 'o': //in
	moveside(-5);
    glutPostRedisplay();
    break;
    
	case 'i': //out
	moveside(5);
    glutPostRedisplay();
    break;
    
    case 'r':
    angle += 0.025;
    orientMe(angle);
    glutPostRedisplay();
    break;
    
    case 'l':
    angle -= 0.025;
    orientMe(angle);
    glutPostRedisplay();
    break;
    
    default:
    break;
    }
} 

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize (1000, 600);
    glutInitWindowPosition (100, 100);
    glutCreateWindow ("A-Team --- UG Innovation Centre");
    init ();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    //glutIdleFunc(spinObj);
    glutMainLoop();
    return 0;
}
