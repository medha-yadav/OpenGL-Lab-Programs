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
	glColor3f(0.5,1.0,0.0);
	glRasterPos2f(-35,80);
	Write("BIT WISE OPERATORS");
	glColor3f(0.2,0.4,0.6);
	glRasterPos2f(-75,70);
	Write("OPERATOR");
	glRasterPos2f(-55,70);
	Write("              DESCRIPTION");
	glRasterPos2f(0,70);
	Write("              TRUTH TABLE / EXAMPLE");
	glColor3f(1.0,1.0,1.0);
	glRasterPos2f(-75,60);
	Write("&"); 
	glRasterPos2f(-55,60);
	Write("              Binary AND operator");
	glRasterPos2f(0,60);
	Write("              0&0=0 , 0&1=0 , 1&0=0 , 1&1=1 ");
	glRasterPos2f(-75,50);
	Write("|"); 
	glRasterPos2f(-55,50);
	Write("              Binary OR operator");
	glRasterPos2f(0,50);
	Write("               0|0=0 , 0|1=1 , 1|0=1 , 1|1=1 ");
	glRasterPos2f(-75,40);
	Write("^"); 
	glRasterPos2f(-55,40);
	Write("              Binary XOR operator");
	glRasterPos2f(0,40);
	Write("               0^0=0 ,  0^1=1  ,1^0=1 ,  1^1=0");
	glRasterPos2f(-75,30);
	Write("~"); 
	glRasterPos2f(-55,30);
	Write("              Unary NOT operator");
	glRasterPos2f(0,30);
	Write("              ~0=1   ,  ~1=0 ");
	glRasterPos2f(-75,20);
	Write("<<"); 
	glRasterPos2f(-55,20);
	Write("              LEFT SHIFT operator");
	glRasterPos2f(-55,15);
	Write("Left operand value is shifted LEFT ");
	glRasterPos2f(-55,10);
	Write("by the no. of places specified on right ");
	glRasterPos2f(-55,5);
	Write("Each left shift equals MULTIPLY BY 2 ");
	glRasterPos2f(0,20);
	Write("              0100 << 0001 =  1000   in binary");
	glRasterPos2f(0,15);
	Write("              4    <<   1  =   8     in decimal");
	glRasterPos2f(-75,-5);
	Write(">>"); 
	glRasterPos2f(-55,-5);
	Write("              RIGHT SHIFT operator");
	glRasterPos2f(-55,-10);
	Write("Left operand value is shifted RIGHT ");
	glRasterPos2f(-55,-15);
	Write("by the no. of places specified on right ");
	glRasterPos2f(-55,-20);
	Write("Each right shift equals DIVIDE BY 2 ");
	glRasterPos2f(0,-5);
	Write("              0100 >> 0001 =  0010   in binary");
	glRasterPos2f(0,-10);
	Write("              4    >>   1  =   2     in decimal");
	glColor3f(1.0,1.0,1.0);
	glRasterPos2f(-90,-30);
	Write("===========================================================================================");
	glColor3f(1.0,1.0,0.0);
	glRasterPos2f(-85,-35);
	Write("NOTE ...");
	glColor3f(1.0,0.5,0.0);
	glRasterPos2f(-90,-40);
	Write("**  Bitwise operators and Logical operators are not same . Both can't be used interchnagably ");
	glRasterPos2f(-90,-50);
	Write("**  Bitwise operators return integer value  ,  Logical operators return True or False .");
	glColor3f(1.0,1.0,1.0);
	glRasterPos2f(-90,-60);
	Write("=============================================================================================");
	
	
	glEnd();
	glFlush();
}
int main(int argc,char **argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB|GLUT_DEPTH);
	glutInitWindowSize(1000,1000);
	glutInitWindowPosition(250,0);
	glutCreateWindow("BIT WISE OPERATORS");
	init_1();
	glutDisplayFunc(display_1);
	glutMainLoop();
    return 0;
}
