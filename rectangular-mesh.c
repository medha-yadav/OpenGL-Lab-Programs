/* Lab Program 10: Program to display a set of values { fij } as a rectangular mesh. */ /* Edited by Mr. Vishwa Kiran, Assistant Professor CITech, Bangalore */ 
#include <stdlib.h> 
#include<stdlib.h> 
#include<GL/glut.h> 
#define maxx 10 
#define maxy 15 
#define dx 15 
#define dy 10  
GLfloat x[maxx]={0.0},y[maxy]={0.0}; 
GLfloat x0=200,y0=200; 
GLint i,j;  
void init() 
{  
glClearColor(0.0,0.0,.0,0.0);  
glColor3f(1.0,0.0,0.0);  
glPointSize(5.0);  
glMatrixMode(GL_PROJECTION);  
glLoadIdentity();  
gluOrtho2D(0.0,499.0,0.0,499.0);  
glutPostRedisplay(); 
}
void display(void) 
{  
glClear(GL_COLOR_BUFFER_BIT);  
glColor3f(1.0,0.0,0.0);  
for(i=0;i<maxx;i++)  
x[i]=x0+i*dx;  
for(j=0;j<maxy;j++)  
y[j]=y0+j*dy;  
 glColor3f(1.0,0.0,0.0);  
 for(i=0;i<maxx-1;i++)  
 for(j=0;j<maxy-1;j++)  
 {   glColor3f(1.0,0.0,0.0);   
 glBegin(GL_LINE_LOOP);   
 glVertex2f(x[i],y[j]);   
 glVertex2f(x[i],y[j+1]);   
 glVertex2f(x[i+1],y[j+1]);   
 glVertex2f(x[i+1],y[j]);   
 glEnd();   
 glFlush(); 
 } 
 } 
 int main(int argc,char **argv) {  
 glutInit(&argc,argv);  
 glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);  
 glutInitWindowSize(500,500);  
 glutInitWindowPosition(350,50);  
 glutCreateWindow("Rectangular Mesh");  
 glutDisplayFunc(display);  
 init();  
 glutMainLoop(); 
 } 
