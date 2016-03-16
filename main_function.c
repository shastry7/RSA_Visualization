
#include<GL/glut.h>
#include<stdio.h>
#include<stdlib.h>
#include<GL/gl.h>
#include<string.h>

#define		mainmenu		100

int flag=0;

char E[1000];


GLfloat x[25];
GLfloat y[20];
GLint i,j,k;
int w,h,a,b,c,e,d,l;




void *currentfont;

void setFont(void *font)
{
	currentfont=font;
}


void drawstring(float x,float y,float z,char *string) //to display text messages
{
	    char *c;
	glRasterPos3f(x,y,z);

	for(c=string;*c!='\0';c++)
	{	glColor3f(0.0,0.0,0.0);
		glutBitmapCharacter(currentfont,*c);
	}
}





void title()												// to draw the starting screen
{

	 setFont(GLUT_BITMAP_HELVETICA_18);
		  glBegin(GL_POLYGON);
          glColor3f(0.0,0.1,0.2);
		         glVertex2i(0,500);
			    glColor3f(0.0,0.0,0.0);
		        glVertex2i(0,0);
		      glColor3f(0.0,0.0,0.0);
		        glVertex2i(500,0);
          glColor3f(0.0,0.1,0.2);
		        glVertex2i(500,500);
	    glEnd();

	glColor3f(1.0,0.0,1.0);
	drawstring(20.0,435.0,1.0,"Topic name");/* Make color changes here*/

	glColor3f(1.0,1.0,1.0);
	drawstring(210.0,365.0,1.0,"submitted by");

	glColor3f(0.0,1.0,1.0);
	drawstring(180.0,340.0,1.0,"Apoorva ");

	glColor3f(0.0,1.0,1.0);
	drawstring(180.0,320.0,1.0,"Dara Sravya");


	glColor3f(1.0,1.0,1.0);
	drawstring(400.0,100.0,1.0," Press M -> continue");

	glFlush();
}

void draw(int c) // TO DRAW POLYGON FOR DISPLAY MENUS
{
/*Color Change here*/
    glBegin(GL_POLYGON);
		glColor3f(0.0f,0.0f,0.0f);
		glVertex2i(0,425-c);
		glColor3f(0.6076,0.0,1.6076);
		glVertex2i(100,395-c);
		glColor3f(0.0f,0.0f,0.0f);
		glVertex2i(425,395-c);
		glColor3f(0.0f,0.0f,0.0f);
		glVertex2i(425,425-c);
		glEnd();
	glFlush();
}
void drawop(int d,int e) // TO DRAW POLYGON FOR selection a,b,c,detcMENUS
{
/*Color change here*/
    glBegin(GL_POLYGON);
			glColor3f(0.2f,0.2f,0.7f);
			glVertex2i(d+57.5,320-e);
			glColor3f(0.0f,0.0f,0.0f);
			glVertex2i(d+147.5,320-e);
			glColor3f(0.0f,0.0f,0.0f);
			glVertex2i(d+147.5,300-e);
			glColor3f(0.2f,0.2f,0.7f);
			glVertex2i(d+57.5,300-e);
		glEnd();
		glFlush();
}

void text(void)											// to draw the text in menu screen
{

	glClear(GL_COLOR_BUFFER_BIT);
	draw(0);
	draw(55);
	draw(110);
	draw(165);
	draw(220);
/*Color change here*/
	setFont(GLUT_BITMAP_HELVETICA_18);
	glColor3f(0.4932,0.9996,0.0);
	drawstring(152.0,455.0,1.0,"RSA ALGORITHM");

	glColor3f(1.0,1.0,1.0);
	drawstring(185.0,405.0,1.0,"Press K: Key generation");

	glColor3f(1.0,1.0,1.0);
	drawstring(185.0,350.0,1.0,"Press E: Encryption");

	glColor3f(1.0,1.0,1.0);
	drawstring(185.0,295.0,1.0,"Press M: Message transmission");

	glColor3f(1.0,1.0,1.0);
	drawstring(185.0,240.0,1.0,"Press D :Decryption");

	glColor3f(1.0,1.0,1.0);
	drawstring(185.0,185.0,1.0,"Press X: EXIT");
	glFlush();
}




void menuSelect(int value)
{
  switch (value)
  {
	  case mainmenu:
      text();
	  break;

  }


}


void mykeyboard(unsigned char key,int x,int y)
{

	switch(key)
	{
		case 'x':
		case 'X':exit(0);break;
		case 'e':
		case 'E':
		case 's':
		case 'S':
	  case 'a':
		case 'A':
		case 'b':
		case 'B':
		case 'c':
		case 'C':
		case 'd':
		case 'D':
		case 'f':
		case 'F':
		case 'g':
		case 'G':
		case 'h':
		case 'H':
		case 'i':
		case 'I':
		case 'j':
		case 'J':
		case 'k':
		case 'K':
		case 'w':
		case 'W':
		case 'r':
		case 'R':
		case 'p':
		case 'P':
		case 't':
		case 'T':
		case 'y':
		case 'Y':
		case 'n':
		case 'N':exit(0);
		case 'm':
		case 'M':flag=1;glutPostRedisplay();break;
		default:return;
	}

	//glutPostRedisplay();
}


void myInit()
{
    	glClearColor(0.0,0.0,0.0,0.0);
			glColor3f(0.0f,0.0f,0.0f);
			glPointSize(5.0);
			gluOrtho2D(0.0,500.0,0.0,500.0);
			glMatrixMode(GL_PROJECTION);
			glLoadIdentity();
}
void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	if(flag==0)
	{
		title();
	}

	if(flag==1) {text();}

}

int main(int argc, char ** argv)
{
	   int fillmenu = 0;
     printf("\n Enter a message less than ten characters\n");
     gets(E);
		if(strlen(E)>10)
	   {
		      printf("Message length exceeded \n");
		      return -1;
	     }


       glutInit(&argc,argv);
       glutInitDisplayMode(GLUT_SINGLE|GLUT_RGBA);
       glutInitWindowPosition(0,0);
       glutInitWindowSize(1000,1000);
       glutCreateWindow("RSA ");
       glutKeyboardFunc(mykeyboard);
       glutDisplayFunc(display);
       myInit();

       glutAttachMenu(GLUT_RIGHT_BUTTON);
       glutMainLoop();

}