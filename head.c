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
	glColor3f(1.0,1.0,1.0);
	glVertex2d(x-35,y-30);
	glVertex2d(x+50,y-30);
	glEnd();
}
void print(GLint x,GLint y,int i){
	glColor3f(0.0,0.0,0.0);
    glRasterPos2f(x-32,y-15);
    switch(i){
    	case 0: Write("EXIT");
    			break;
    	case 1: Write("APPLICATIONS");
    			break;
    	case 2: Write("BIT TRICKS");
    			break;
    	case 3: Write("BIT MASKING ");
    			break;
    	case 4: Write("BIT WISE OPERATORS");
    			break;
    	
    }
}

void OnMouseClick(int btn,int state,int x,int y){
	if(btn==GLUT_LEFT_BUTTON&&state==GLUT_DOWN){
		printf("\n%d,%d",x,y);
		
		
		if(x>=422&&x<=640&&y>=164&&y<=206){
                                          
			//system("option1.exe");
			spawnl(P_NOWAIT, "option1.exe","option1.exe", NULL );
			
         }
        
		if(x>=422&&x<=640&&y>=227&&y<=268){
                                          
			
			spawnl(P_NOWAIT, "option2.exe","option1.exe", NULL );
			
         }
		 if(x>=422&&x<=640&&y>=290&&y<=329){
                                          
		
			spawnl(P_NOWAIT, "option3.exe","option3.exe", NULL );
			
         }
		  if(x>=422&&x<=640&&y>=354&&y<=392){
                                          
			
			spawnl(P_NOWAIT, "option4.exe","option4.exe", NULL );
			
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
   // glClearColor(0.0,0.0,0.0,0.0); //TO SET BACKGROUND COLOR

	glColor3f(1.0,0.0,1.0);
	int i;
	GLint x=200,y=214,r=5 ;
	glRasterPos2f(180,475);
	Write("BIT MANIPULATION");
	glColor3f(0.0,1.0,0.0);
	glRasterPos2f(40,460);
	Write(" -->  BIT is 0 , 1 . In computer system EVERYTHING  is represented and manipulated as bits .");
	glRasterPos2f(40,445);
	Write(" --> As a programmer , we normally use char, int ,float ,string etc ...and not concerned with operations at bit level .");
	glRasterPos2f(40,430);
	Write(" --> These data types are internally represented as  sequence of bits.");
	glRasterPos2f(40,415);
	Write(" --> We can't access each bit individually (minimum is  1 byte) , since addressing each bit is a difficult task ");
	glRasterPos2f(40,400);
	Write(" --> BitWise Operators allows us to manipulate data at bit level and exploit  for wide ranging applications. ");
	for(i=0;i<5;i++){
		icon(x,y);
		print(x,y,i);
		y=y+43;
	}
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
