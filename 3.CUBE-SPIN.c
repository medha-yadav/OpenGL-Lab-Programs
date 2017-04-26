#include<GL\glut.h>

GLfloat ver[8][3] ={{-1.0,-1.0,1.0},{-1.0,1.0,1.0},{1.0,1.0,1.0},{1.0,-1.0,1.0},
			  {-1.0,-1.0,-1.0},{-1.0,1.0,-1.0},{1.0,1.0,-1.0},{1.0,-1.0,-1.0},	
			 };
			 
GLfloat colors[6][3]={{1.0,0.0,0.0},{0.0,1.0,0.0},{0.0,0.0,1.0},{1.0,1.0,0.0},{0.0,1.0,1.0},{1.0,0.0,0.0}};
GLfloat theta[]={0.0,0.0,0.0};
GLint axis=1;
void cube(int a , int b, int c, int d)
{
	glBegin(GL_POLYGON);
		glColor3fv(colors[a]);
		glVertex3fv(ver[a]);
		//glColor3fv(colors[1]);
		glVertex3fv(ver[b]);
	//	glColor3fv(colors[2]);
		glVertex3fv(ver[c]);
	//	glColor3fv(colors[3]);
		glVertex3fv(ver[d]);
	glEnd();	
}

void polygon()
{
	cube(0,3,2,1);
	cube(2,3,7,6);
	cube(1,2,6,5);
	cube(4,0,1,5);
	cube(5,6,7,4);
	cube(3,0,4,7);
}
void display()
{
	glClearColor(1.0,1.0,1.0,1.0);
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	
	glLoadIdentity();
	glRotatef(theta[0],1.0,0.0,0.0);
	glRotatef(theta[1],0.0,1.0,0.0);
	glRotatef(theta[2],0.0,0.0,1.0);
	polygon();
	glFlush();
	glutSwapBuffers();
	
}

void spin()
{
	theta[axis]+=0.1;
	if(theta[axis]>360.0)
	{
		theta[axis]-=360.0;
	}
	glutPostRedisplay();
}

void mouse(int btn,int s,int x,int y)
{
	if(btn==GLUT_LEFT_BUTTON&&s==GLUT_DOWN)
	axis=0;
	if(btn==GLUT_RIGHT_BUTTON&&s==GLUT_DOWN)
	axis=1;
	if(btn==GLUT_MIDDLE_BUTTON&&s==GLUT_DOWN)
	axis=2;
}
void myReshape(int w,int h)
{
	glViewport(0,0,w,h);
	
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	
	if(w<=h)
		glOrtho(-2.0,2.0,-2.0*(GLfloat)w/(GLfloat)h,2.0*(GLfloat)w/(GLfloat)h,-10.0,10.0);
	else	
		glOrtho(-2.0,2.0,-2.0*(GLfloat)h/(GLfloat)w,2.0*(GLfloat)h/(GLfloat)w,-10.0,10.0);
		glMatrixMode(GL_MODELVIEW);
}

int main(int argc,char **argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB);
	glutInitWindowPosition(350,50);
	glutInitWindowSize(500,500);
	glutCreateWindow("CUBE");
	glutDisplayFunc(display);
	glutIdleFunc(spin);
	glutReshapeFunc(myReshape);
	glutMouseFunc(mouse);
	glEnable(GL_DEPTH_TEST);
	glutMainLoop();
	return 0;
}
