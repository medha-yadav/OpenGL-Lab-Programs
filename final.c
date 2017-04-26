#include<stdio.h>
#include<process.h>
#include<GL/glut.h>
#include<math.h>
#include<windows.h>

void myinit(void)
{
	
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0,1000.0,0.0,1000.0);
}

void Write(char *string)
{
    while(*string)
    {
                   glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *string++);
    }
}
void Write1(char *string)
{
    while(*string)
    {
                   glutBitmapCharacter(GLUT_BITMAP_HELVETICA_10, *string++);
    }
}
void Write2(char *string)
{
    while(*string)
    {
                   glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *string++);
    }
}
void draw_square(int x,int y)
{
	glBegin(GL_POLYGON);
	glVertex2i(x,y);
	glVertex2i(x+200,y);
	glVertex2i(x+200,y-100);
	glVertex2i(x,y-100);
	glEnd();
	
}


void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.5,1.0,0.0);
	glBegin(GL_POLYGON);
	glVertex2i(50,700);
	glVertex2i(950,700);
	glVertex2i(950,950);
	glVertex2i(50,950);
	glEnd();
	glColor3f(0.0,0.0,0.0);
	glRasterPos2f(150,940);
	Write("_______________________________________________________");
	glColor3f(0.4,0.0,0.0);
	glRasterPos2f(150,900);
	Write("   COMPUTER   GRAPHICS  MINI   PROJECT   WITH   OPENGL ");
	glColor3f(0.0,0.0,0.0);
	glRasterPos2f(150,890);
	Write("________________________________________________________");
	glColor3f(0.0,0.15,0.2);
	glRasterPos2f(300,840);
	Write2(" UNDER THE GUIDANCE OF VIMALA MADAM    ");
	glRasterPos2f(500,800);
	Write2(" 					 -   BY  MEDHA YADAV   ");
	glRasterPos2f(520,760);
	Write2("   						14GAEC9024    ");
	glRasterPos2f(520,720);
	Write2("   						Vth SEM CSE ,2016-17   ");
	glColor3f(1.0,0.0,0.2);
	
	draw_square(50,650);
	glColor3f(1.0,1.0,1.0);
	glRasterPos2f(60,600);
	Write2(" 1.TETRAHEDRON");
	
	glColor3f(1.0,0.0,0.2);
	draw_square(50,500);
	glColor3f(1.0,1.0,1.0);
	glRasterPos2f(60,450);
	Write2("2.LIANG-BARSKY");
	
	glColor3f(1.0,0.0,0.2);
	draw_square(50,350);
	glColor3f(1.0,1.0,1.0);
	glRasterPos2f(60,300);
	Write2("3.CUBE-SPIN");
	
	glColor3f(1.0,0.0,0.2);
	draw_square(300,650);
	glColor3f(1.0,1.0,1.0);
	glRasterPos2f(310,600);
	Write2("4.HOUSE");
	
	glColor3f(1.0,0.0,0.2);
	draw_square(300,500);
	glColor3f(1.0,1.0,1.0);
	glRasterPos2f(310,450);
	Write2("5.COHEN");
	glRasterPos2f(320,422);
	Write2("SUTHERLAND");
	
	glColor3f(1.0,0.0,0.2);
	draw_square(300,350);
	glColor3f(1.0,1.0,1.0);
	glRasterPos2f(310,300);
	Write2("6.CYLINDER");
	
	glColor3f(1.0,0.0,0.2);
	draw_square(550,650);
	glColor3f(1.0,1.0,1.0);
	glRasterPos2f(560,600);
	Write2("7.TEAPOT");
	
	glColor3f(1.0,0.0,0.2);
	draw_square(550,500);
	glColor3f(1.0,1.0,1.0);
	glRasterPos2f(552,450);
	Write2("8.CUBE PERSPECTIVE ");
	glRasterPos2f(580,415);
	Write2(" VIEW");
	
	glColor3f(1.0,0.0,0.2);
	draw_square(550,350);
	glColor3f(1.0,1.0,1.0);
	glRasterPos2f(560,300);
	Write2("9.SCAN LINE ");
	glRasterPos2f(570,275);
	Write2("ALGORITHM");
	
	glColor3f(1.0,0.0,0.2);
	draw_square(780,650);
	glColor3f(1.0,1.0,1.0);
	glRasterPos2f(790,600);
	Write2("10.RECTANGULAR ");
	glRasterPos2f(815,572);
	Write2("MESH");
	
	
	glColor3f(1.0,1.0,0.0);
	glBegin(GL_POLYGON);
	glVertex2i(780,500);
	glVertex2i(980,500);
	glVertex2i(980,340);
	glVertex2i(780,340);
	glEnd();
	glColor3f(1.0,1.0,1.0);
	glBegin(GL_POLYGON);
	glVertex2i(780,300);
	glVertex2i(980,300);
	glVertex2i(980,240);
	glVertex2i(780,240);
	glEnd();
	
	glColor3f(0.0,0.0,0.0);
	glRasterPos2f(790,450);
	Write2("11.BIT ");
	glRasterPos2f(815,422);
	Write2("MANIPULATION");
	glRasterPos2f(825,375);
	Write2(" - I know C a bit");
	glColor3f(1.0,0.0,0.0);
	glRasterPos2f(840,268);
	Write2("EXIT");
	
	glFlush();
}


void OnMouseClick(int btn,int state,int x,int y){
	if(btn==GLUT_LEFT_BUTTON&&state==GLUT_DOWN){
	//	printf("\n%d,%d",x,y);
		if(x>=50&&x<=250&&y>=287&&y<=365){
                    
		spawnl(P_NOWAIT, "Gasket_Random.exe","Gasket_Random.exe", NULL );
			return;
      }
		
		if(x>=50&&x<=250&&y>=411&&y<=490){
                                         
		
			spawnl(P_NOWAIT, "liang.exe","liang.exe", NULL );
			return;
        }
		
		if(x>=50&&x<=250&&y>=536&&y<=615){
                                          
		
			spawnl(P_NOWAIT, "3.CUBE-SPIN.exe","3.CUBE-SPIN.exe", NULL );
			return;
      }
	if(x>=300&&x<=500&&y>=287&&y<=370){
                                          
		
		spawnl(P_NOWAIT, "house.exe","house.exe", NULL );
			return;
        }
			
		if(x>=300&&x<=450&&y>=411&&y<=490){
                                          
		
		spawnl(P_NOWAIT, "cohen.exe","cohen.exe", NULL );
			return;
        }
		if(x>=300&&x<=500&&y>=535&&y<=614){
                                          
		
		spawnl(P_NOWAIT, "circle_cyl.exe","circle_cyl.exe", NULL );
		return;
        }
			
		if(x>=550&&x<=750&&y>=410&&y<=492){
                                          
		
		spawnl(P_NOWAIT, "cube_perspective.exe","cube_perspective.exe", NULL );
			return;
        }
			
		if(x>=550&&x<=750&&y>=292&&y<=411){
                                          
		
		spawnl(P_NOWAIT, "teapot.exe","teapot.exe", NULL );
			return;
        }
			
		if(x>=550&&x<=750&&y>=535&&y<=615){
                                          
		
			spawnl(P_NOWAIT, "scan_line.exe","scan_line.exe", NULL );
			return;
        }
		if(x>=780&&x<=980&&y>=285&&y<=370){
		
		spawnl(P_NOWAIT, "rectangular-mesh.exe","rectangular-mesh.exe", NULL );
			return;
		
        }
        if(x>=780&&x<=980&&y>=411&&y<=542){
			
		
			spawnl(P_NOWAIT,"head.exe","head.exe", NULL );	
		}
        if(x>=780&&x<=980&&y>=575&&y<=624){
			//Exit();
				spawnl(P_OVERLAY,"ex.exe","ex.exe", NULL );		
		}
        
	}
}






int main(int argc,char **argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowPosition(200,20);
	glutInitWindowSize(1000,1000);
	glutCreateWindow("CG MINI PROJECT");
	glutDisplayFunc(display);
//	glutAddMenuEntry("Quit",1);
//	glutAttachMenu(GLUT_MIDDLE_BUTTON);
	glutMouseFunc(OnMouseClick);
	myinit();
	glutMainLoop();
	return 0;
}
