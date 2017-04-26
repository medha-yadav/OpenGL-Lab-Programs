#include<GL/glut.h>
#define false 0
#define true 1
GLdouble xmin=50,ymin=50,xmax=100,ymax=100;
GLdouble xvmin=250,yvmin=250,xvmax=300,yvmax=300;
int cliptest(GLdouble p,GLdouble q,GLdouble *te,GLdouble*tl)
{
GLdouble t=q/p;
if(p<0.0)
{
if(t>*te) *te=t;
if(t>*tl) return(false);
}
if(p>0.0)
{
if(t<*tl) *tl=t;
if(t<*te) return(false);
}
if(p==0.0)
{
if(q<0.0)return(false);
}
return(true);
}
void LBLineClipDraw(GLdouble x0,GLdouble y0,GLdouble
x1,GLdouble y1)
{
GLdouble dx=x1-x0,dy=y1-y0,te=0.0,tl=1.0;
if(cliptest(-dx,x0-xmin,&te,&tl)!=false)
{
if(cliptest(dx,xmax-x0,&te,&tl)!=false)
{
if(cliptest(-dy,y0-ymin,&te,&tl)!=false)
{
if(cliptest(dy,ymax-y0,&te,&tl)!=false)
{
if(tl<1.0)
{
x1=x0+tl*dx;
y1=y0+tl*dy;
}
if(te>0.0)
{
x0=x0+te*dx;
y0=y0+te*dy;
}
}
}
}
}
glColor3f(1.0,0.0,0.0);
glBegin(GL_LINE_LOOP);
glVertex2f(xvmin,yvmin);
glVertex2f(xvmax,yvmin);
glVertex2f(xvmax,yvmax);
glVertex2f(xvmin,yvmax);
glEnd();
GLdouble vx0=x0+200;
GLdouble vy0=y0+200;
GLdouble vx1=x1+200;
GLdouble vy1=y1+200;
glColor3f(0.0,0.0,1.0);
glBegin(GL_LINES);
glVertex2d(vx0,vy0);
glVertex2d(vx1,vy1);
glEnd();
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
LBLineClipDraw(x0,y0,x1,y1);
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
glutCreateWindow("Liang Barsky Line Clipping Algorithm");
init();
glutDisplayFunc(display);
glutMainLoop();
}
