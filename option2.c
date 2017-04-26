#include<GL\glut.h>
#include<stdio.h>
#include<windows.h>
#include<process.h>
#include<math.h>
void init()
{
	glMatrixMode(GL_PROJECTION); 
	glLoadIdentity();
	gluOrtho2D(0,499.0,0,499.0);
	glMatrixMode(GL_MODELVIEW);

}


void Write(char *string)
{
    while(*string)
    {
                   glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *string++);
   }
}

void icon(GLint x,GLint y){
	glColor3f(1.0,1.0,1.0);
	glBegin(GL_POLYGON);
	glVertex2d(x+50,y);
	glVertex2d(x-35,y);
	glVertex2d(x-35,y-30);
	glVertex2d(x+50,y-30);
	glEnd();
}
void print(GLint x,GLint y,int i){
	glColor3f(0.0,0.0,0.0);
    glRasterPos2f(x-32,y-15);
    switch(i){
    	case 0: Write(" EXIT");
    			break;
    	case 1: Write(" IS BIT SET ");
    			break;
    	case 2: Write(" FLIP A BIT");
    			break;
    	case 3: Write(" CLEAR A BIT");
    			break;
    	case 4: Write(" SET A BIT");
    			break;
    	
    }
}

void OnMouseClick(int btn,int state,int x,int y){
	if(btn==GLUT_LEFT_BUTTON&&state==GLUT_DOWN){
	//	printf("\n%d,%d",x,y);
		
		
		if(x>=422&&x<=640&&y>=164&&y<=206){
                                          
		
			spawnl(P_NOWAIT, "code.exe","code.exe", NULL );
			return;
         }
        
		if(x>=422&&x<=640&&y>=226&&y<=269){
                                          
			
			spawnl(P_NOWAIT, "codeclear.exe","codeclear.exe", NULL );
			return;
         }
		 if(x>=422&&x<=640&&y>=290&&y<=330){
                                          
		   
		    spawnl(P_NOWAIT, "codeflip.exe","codeflip.exe", NULL );
			return;
         }  
         if(x>=422&&x<=640&&y>=353&&y<=396){
                                          
		    
			spawnl(P_NOWAIT, "codeisset.exe","codeisset.exe", NULL );
			return;
         }
         if(x>=422&&x<=640&&y>=416&&y<=458){
                                          
		    
			exit(0);
			return;
         }
         
	}
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT); //TO CLEAR THE LAST OUTPUT AND AVOID TRANSPARENCY
    glClearColor(0.0,0.0,0.0,0.0); //TO SET BACKGROUND COLOR
    glColor3f(1.0,0.5,0);
	
	int i;
	GLint x=200,y=214,r=5 ;
	glRasterPos2f(180,475);
	Write("BIT MASKING");
	glRasterPos2f(180,470);
	Write("_____________");
	glColor3f(1.0,1.0,0.0);

	glRasterPos2f(40,440);
	Write("-->   	Mask :  A mask defines which bits you want to keep, and which bits you want to clear. " );
	glRasterPos2f(40,420);
	Write("-->   	Masking is the act of applying a mask to a value .");
	glRasterPos2f(40,400);
	Write("-->   	Applying different bitwise operators to a mask and value different tasks that can be accomplished are as follows -");
	
	for(i=0;i<5;i++){
		icon(x,y);
		print(x,y,i);
		y=y+43;
	}
	glRasterPos2f(60,100);
	Write("Mask ");
	glFlush();

}


int main(int argc,char **argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB|GLUT_DEPTH);
	glutInitWindowSize(1280,730);
	glutInitWindowPosition(0,0);
	glutCreateWindow("BIT MANIPULATION");
	init();
	glutDisplayFunc(display);
    glutMouseFunc(OnMouseClick);
    glutMainLoop();
	return 0;
}
