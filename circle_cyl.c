#include<GL/glut.h>
void draw_pixel(GLint m,GLint n)
{
glColor3f(1.0,1.0,0.0);
glBegin(GL_POINTS);
glVertex2i(m,n);
glEnd();
}
void plotpixels(GLint h,GLint k,GLint x,GLint y)
{
draw_pixel(x+h,y+k);
draw_pixel(-x+h,y+k);
draw_pixel(x+h,-y+k);
draw_pixel(-x+h,-y+k);
draw_pixel(y+h,x+k);
draw_pixel(-y+h,x+k);
draw_pixel(y+h,-x+k);
draw_pixel(-y+h,-x+k);
}
void circle_draw(GLint h,GLint k,GLint r)
{
GLint d=1-r,x=0,y=r;
plotpixels(h,k,x,y);
while(y>x)
{
if(d<0)
{
d+=2*x+3;
}
else
{
d+=2*(x-y)+5;
--y;
}
++x;
plotpixels(h,k,x,y);
}
}
void cylinder_draw()
{
GLint h=100,k=100,r=50;
GLint i,n=50;
for(i=0;i<n;i+=3)
{
circle_draw(h,k+i,r);
}
}

void rectangle_draw(GLint x1,GLint x2,GLint y1,GLint y2)
{
glColor3f(0.6,0.0,1.0);
glBegin(GL_LINE_LOOP);
glVertex2i(x1,y1);
glVertex2i(x2,y1);
glVertex2i(x2,y2);
glVertex2i(x1,y2);
glEnd();
}
void parallelopiped_draw()
{
GLint x1=200,x2=300,y1=100,y2=175;
GLint i,n=40;
for(i=0;i<n;i+=2)
{
rectangle_draw(x1+i,x2+i,y1+i,y2+i);
}
}
void init()
{
glMatrixMode(GL_PROJECTION);
gluOrtho2D(0.0,400.0,0.0,300.0);
}
void display()
{
glClear(GL_COLOR_BUFFER_BIT); //TO CLEAR THE LAST OUTPUT AND AVOID TRANSPARENCY
glClearColor(1.0,1.0,1.0,0.0); //TO SET BACKGROUND COLOR
cylinder_draw();
parallelopiped_draw();
glFlush();
}
void main(int argc,char**argv)
{
glutInit(&argc,argv);
glutInitWindowPosition(350,100);
glutInitWindowSize(500,400);
glutCreateWindow("Cylinder and Parallelopiped");
init();
glutDisplayFunc(display);
glutMainLoop();
}












