#include<GL\glut.h>
#include<process.h>
#include<math.h>
#include<windows.h>
int i;
void init()
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0,500,0,500);
	glMatrixMode(GL_MODELVIEW);
}

void Write(char *string)
{
    while(*string)
    {
                   glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *string++);
    }
}
void OnMouseClick(int btn,int state,int x,int y){
	if(btn==GLUT_LEFT_BUTTON&&state==GLUT_DOWN){
		//printf("\n%d,%d",x,y);
	}
}
void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0,0,0);
	glBegin(GL_POLYGON);
	glVertex2i(100,100);
	glVertex2i(400,100);
	glVertex2i(400,400);
	glVertex2i(100,400);
	glEnd();
	glPointSize(20.0);
	glColor3f(1,1,1);
	glRasterPos2f(175,250);
	Write("THANK YOU ");
	glRasterPos2f(330,250);
	Write(" :) ");
	glFlush();
	TerminateProcess(PROCESS_TERMINATE,GetExitCodeProcess);
	while(i<1999999999){
		i++;
	}
	exit(0);
}
int main(int argc,char **argv)
{
	glutInit(&argc,argv);
	glutInitWindowSize(500,500);
	glutInitWindowPosition(400,100);
	glutCreateWindow("EXIT");
	glutDisplayFunc(display);
	glutMouseFunc(OnMouseClick);
	init();
	glClearColor(1,1,1,1);
	glutMainLoop();
	return 0;
}

