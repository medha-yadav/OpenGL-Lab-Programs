#include<GL/glut.h>
//#define outcode int
GLdouble xmin=50,ymin=50,xmax=100,ymax=100;
GLdouble xvmin=250,yvmin=250,xvmax=300,yvmax=300;
const int RIGHT=8;
const int TOP=4;
const int LEFT=2;
const int BOTTOM=1;
int computeoutcode(GLdouble x, GLdouble y)
{
int code=0;
if(y>ymax)
{
code=code|TOP;
}
if(y<ymin)
{
code=code|BOTTOM;
}
if(x>xmax)
{
code=code|RIGHT;
}
if(x<xmin)
{
code=code|LEFT;
}
return code;
}
void CSlineclipdraw(GLdouble x0,GLdouble y0,GLdouble x1,GLdouble y1)
{
int outcode0,outcode1,outcodeout;
bool accept=false;
bool done=false;
outcode0=computeoutcode(x0,y0);
outcode1=computeoutcode(x1,y1);
do
{
if((outcode0|outcode1)==0000)
{
accept=true;
done=true;
}
else if((outcode0 & outcode1)!=0000)
{
accept=false;
done=true;
}
else
{
	GLdouble x,y;
if(outcode0!=0000)
{
outcodeout=outcode0;
}
else
{
outcodeout=outcode1;
}
if(outcodeout & TOP)
{
x=x0+(x1-x0)*(ymax-y0)/(y1-y0);
y=ymax;
}
if(outcodeout & BOTTOM)
{
x=x0+(x1-x0)*(ymin-y0)/(y1-y0);
y=ymin;
}
if(outcodeout & RIGHT)
{
x=xmax;
y=y0+(y1-y0)*(xmax-x0)/(x1-x0);
}
if(outcodeout & LEFT)
{
x=xmin;
y=y0+(y1-y0)*(xmin-x0)/(x1-x0);
}
if(outcodeout==outcode0)
{
x0=x;
y0=y;
outcode0=computeoutcode(x0,y0);
}
if(outcodeout==outcode1)
{
x1=x;
y1=y;
outcode1=computeoutcode(x1,y1);
}
}
}
while(!done);
if(accept=true)
{
glColor3f(1.0,0.0,0.0);
glBegin(GL_LINE_LOOP);
glVertex2f(xvmin,yvmin);
glVertex2f(xvmax,yvmin);
glVertex2f(xvmax,yvmax);
glVertex2f(xvmin,yvmax);
glEnd();
GLdouble vx0=x0+(xvmin-xmin);
GLdouble vy0=y0+(yvmin-ymin);
GLdouble vx1=x1+(xvmin-xmin);
GLdouble vy1=y1+(yvmin-ymin);
glColor3f(0.0,0.0,1.0);
glBegin(GL_LINES);
glVertex2d(vx0,vy0);
glVertex2d(vx1,vy1);
glEnd();
}
}
void display()
{
glClear(GL_COLOR_BUFFER_BIT); //TO CLEAR THE LAST OUTPUT AND AVOID TRANSPARENCY
glClearColor(1.0,1.0,1.0,1.0); //TO SET BACKGROUND COLOR
GLdouble x0=60,y0=20,x1=80,y1=120;
glColor3f(0.0,0.0,1.0);
glBegin(GL_LINE_LOOP);
glVertex2f(xmin,ymin);
glVertex2f(xmax,ymin);
glVertex2f(xmax,ymax);
glVertex2f(xmin,ymax);
glEnd();
glColor3f(1.0,0.0,0.0);
glBegin(GL_LINES);
glVertex2d(x0,y0);
glVertex2d(x1,y1);
glEnd();
CSlineclipdraw(x0,y0,x1,y1);
glFlush();
}
void init()
{
glMatrixMode(GL_PROJECTION);
gluOrtho2D(0.0,500.0,0.0,500.0);
}
void main(int argc,char **argv)
{
glutInit(&argc,argv);
glutInitWindowSize(500,500);
glutInitWindowPosition(350,50);
glutCreateWindow("CohenSutherland Line Clipping Alg");
init();
glutDisplayFunc(display);
glutMainLoop();
}
	
