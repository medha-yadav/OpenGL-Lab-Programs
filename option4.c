#include<GL\glut.h>

void init_1()
{
	glMatrixMode(GL_PROJECTION); 
	glLoadIdentity();
	gluOrtho2D(-100,100,-100,100);
	glMatrixMode(GL_MODELVIEW);
}
void Write(char *string)
{
    while(*string)
    {
                   glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *string++);
    }
}
void display_1()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0,0.5,1.0);
	
	glRasterPos2f(-40,93);
	Write("__________________________");
	glRasterPos2f(-35,85);
	Write(" APPLICATIONS ");
	glRasterPos2f(-40,80);
	Write("__________________________");
	glColor3f(0.5,1.0,0.0);
	glRasterPos2f(-95,70);
	Write(" >>  Operations with bits are used in Data compression ");
	glRasterPos2f(-95,60);
	Write("      Data is compressed by converting it from one representation to another, to reduce the space)  ");
	glColor3f(1.0,1.0,1.0);
	glRasterPos2f(-95,53);
	Write("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ");
	glColor3f(1.0,0.0,0.2);
	glRasterPos2f(-95,46);
	Write(" >>  Exclusive-Or Encryption (An algorithm to encrypt the data for safety issues).");
	glRasterPos2f(-95,36);
	Write("     In order to encode, decode or compress files we have to extract the data at bit level." );
	glColor3f(1.0,1.0,1.0);
	glRasterPos2f(-95,29);
	Write("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ");
	glColor3f(1.0,1.0,0.0);
	glRasterPos2f(-95,19);
	Write(">>   Use of bitmasks to pass argument to functions " );
	glRasterPos2f(-95,9);
	Write("In programming languages such as C, bit fields are a useful way to pass a set of named boolean arguments to a function. " );
	glRasterPos2f(-98,-1);
	Write("For eg,in OpenGL,there is a command,glClear() which clears the screen or other buffers. " );
	glRasterPos2f(-98,-11);
	Write("It can clear up to four buffers ( color,   depth,  accumulation and stencil buffers) ");
	glRasterPos2f(-98,-21);
	Write("So the API authors could have taken four arguments....and then a call to it would look like- glClear(1,1,0,0)"); 
	glRasterPos2f(-98,-31);
	Write("This isn't how glClear actually works and would make for unstable code .Instead there are four defined field bits ");
	glRasterPos2f(-98,-41);
	Write("GL_COLOR_BUFFER_BIT, GL_DEPTH_BUFFER_BIT,GL_ACCUM_BUFFER_BIT, and GL_STENCIL_BUFFER_BIT ");
	glRasterPos2f(-98,-51);
	Write("void glClear(GLbitfield bits) and call look like  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);");
	glRasterPos2f(-98,-61);
	Write("Internally,function use binary to extract individual bits.Advantage =function argument overhead is decreased.");
	glRasterPos2f(-98,-81);
	Write("The advantage to this approach is that function argument overhead is decreased. ");



	
	
	
	glEnd();
	glFlush();
}
int main(int argc,char **argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB|GLUT_DEPTH);
	glutInitWindowSize(1000,1000);
	glutInitWindowPosition(250,0);
	glutCreateWindow("BIT MANIPULATIONS");
	init_1();
	glutDisplayFunc(display_1);
	glutMainLoop();
    return 0;
}
