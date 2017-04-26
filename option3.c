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
	glRasterPos2f(-35,90);
	Write("BIT TRICKS ... BIT OF FUN WITH BITS :)");
	glRasterPos2f(-40,85);
	Write("_________________________________________");
	glColor3f(0.0,0.5,1.0);
	glRasterPos2f(-90,70);
	Write(" Bitwise operations are faster and closer to the system and sometimes optimize program at good level  .");
	glRasterPos2f(-90,60);
	Write(" Few Simple and Handy Tricks are listed as follows  - ");
	glColor3f(1.0,1.0,0.0);
	glRasterPos2f(-80,50);
	Write(" 1 . CHECK ODD OR EVEN :   (x&1) : returns  0 if EVEN , non - zero if ODD" );
	glRasterPos2f(-70,43);
	Write(" All even numbers have rightmost ( Least Signifiacnt Bit ) as 0 " );
	glRasterPos2f(-70,36);
	Write(" All odd numbers have rightmost ( Least Signifiacnt Bit ) as 1 " );
	glRasterPos2f(-70,29);
	Write(" Hence x & 1 returns 0 for even and non zero for odd . " );
	
	glColor3f(1.0,0.5,0.0);
	glRasterPos2f(-80,19);
	Write(" 2. CHECK IF NUMBER IS POWER OF 2 ");
	glRasterPos2f(-70,12);
	Write("if( (n!=0) && ( n & ( n-1 )== 0 ) return TRUE , else FALSE " );
	glRasterPos2f(-70,5);
	Write(" All numbers which are power of 2 have unique property that in binary format exactly one bit is set" );
	glRasterPos2f(-70,-2);
	Write("  1 - [0001] , 2 - [0010] , 4 - [0100] , 8 - [1000] , hence n & n-1 == 0 seems sufficient " );
	glRasterPos2f(-70,-9);
	Write("  But it evaluates to 1 for 0 also which is not true ... So ( n!=0 && (n & (n-1) == 0) ");
    
	glColor3f(1.0,1.0,0.0);
	glRasterPos2f(-80,-19);
	Write("3 . CHECK IF TWO NUMBERS x,y ARE EQUAL");
	glRasterPos2f(-70,-26);
	Write(" if  ( ( x ^ y ) == 0 )  EQUAL  ,    else NOT EQUAL ");
	glColor3f(1.0,0.0,0.0);
	glRasterPos2f(-80,-36);
	Write("4 . FINDING ALL SUBSETS OF GIVEN SET " );
	glRasterPos2f(-80,-43);
	Write("Lets say, Set has n elements. We will use the bits of numbers to show the presence of element in set.");
	glRasterPos2f(-80,-50);
	Write(" That is  - If xth bit in number is SET i.e. 1, then xth element in given set is present in current subset. ");
	glRasterPos2f(-80,-57);
	Write("Loop from 0 to (2 raised to n)-1 & for each num,check the SET bits in it &take corresponding elements.");
	glRasterPos2f(-80,-64);
	Write("In each iteration, we will have one subset . At the end we will have all 2^n subsets of set.");
	
	
	
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
