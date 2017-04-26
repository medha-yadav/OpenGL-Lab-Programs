#include<GL\glut.h>
#include<stdio.h>
#include<windows.h>
#include<process.h>
#include<math.h>
int p=0;
int q=0;
int r=0;
int s=0;


int a=0;
int b=0;
int c=0;
int d=0;


int ci=0;
int w=0;
int z=0;
int pos=0;
int ar[4]={0};
void init()
{
	glMatrixMode(GL_PROJECTION); 
	glLoadIdentity();
	gluOrtho2D(0,1000.0,0,1000.0);
	glMatrixMode(GL_MODELVIEW);

}
void writeint(int a)
{
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,a+48);
}
void Write(char *string)
{
    while(*string)
    {
    			   
                   glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *string++);
   }
}
void Write1(char *string)
{
    while(*string)
    {
    			   
                   glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *string++);
   }
}

void show_algo()
{

	glColor3f(0.0,0.0,0.8);
	glRasterPos2f(200,900);
    Write("   SET  A  	BIT  ");
    glRasterPos2f(200,890);
    Write("  ___________ ");
    glColor3f(1.0,0.0,0.0);
    glRasterPos2f(150,800);
    Write1(" set_bit  (   x  ,  position   )");
    glRasterPos2f(150,760);
    Write1("{");
    glRasterPos2f(170,720);
    Write1(" mask  =  1  <<  position ");
    glRasterPos2f(170,680);
    Write1("  return  (  x   |  mask  )");
    glRasterPos2f(150,640);
    Write1("} ; " );
    
   
}

void draw_square(int x,int y)
{
	glColor3f(1.0,0.0,0.2);
	//glColor3f(1.0,1.0,0.0);
	glPointSize(2.0);
	glBegin(GL_POLYGON);
	glVertex2i(x,y);
	glVertex2i(x+40,y);
	glVertex2i(x+40,y+70);
	glVertex2i(x,y+70);
	glEnd();
}

void enter()
{
	//glColor3f(0.4,0.0,0.99);
	glColor3f(0,0,0.7);
	glRasterPos2f(50,420);
	Write("Enter ' x ' 	in 	binary		 : ");
	draw_square(200,400);
	draw_square(250,400);
	draw_square(300,400);
	draw_square(350,400);
}
void draw(int x,int y,int m)
{
	if(m==2)
	glColor3f(0.0,0.5,0.5);
	if(m==1)
	glColor3f(0.5,0.5,0);
	if(m==3)
	glColor3f(1.0,0,0.2);
	glPointSize(2.0);
	glBegin(GL_POLYGON);
	glVertex2i(x,y);
	glVertex2i(x+40,y);
	glVertex2i(x+40,y+70);
	glVertex2i(x,y+70);
	glEnd();
}
int dtob(int n)
{
    int binaryNumber = 0;
    int remainder, i = 1, step = 1;

    while (n!=0)
    {
        remainder = n%2;
        //printf("Step %d: %d/2, Remainder = %d, Quotient = %d\n", step++, n, remainder, n/2);
        n /= 2;
        binaryNumber += remainder*i;
        i *= 10;
    }
    return binaryNumber;
}
void func(int r[],int n)
{
	int i=0;
	while(n!=0)
	{
		r[i++]=n%10;
		n/=10;
	}
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	//line dividing in 2 parts
	glColor3f(0.0,0.0,1.0);
	glBegin(GL_LINES);
	glPointSize(100.0);
	glVertex2i(500,0);
	glVertex2i(500,1000);
	glEnd();
	
	//box for algorithm
	glPointSize(100.0);
	glColor3f(0.0,0.0,0.0);
	glBegin(GL_LINE_LOOP);
	glVertex2i(100,600);
	glVertex2i(400,600);
	glVertex2i(400,950);
	glVertex2i(100,950);
	glEnd();
	
	show_algo();
	
	enter();
	
	glColor3f(1.0,1.0,1.0);
	
	
    
     
	if(p==1){	glRasterPos2f(210,420); Write1("1");	ar[3]=1;									    }
	if(q==1){	glRasterPos2f(260,420); Write1("1");	ar[2]=1;										}
	if(r==1){	glRasterPos2f(310,420); Write1("1");	ar[1]=1;										}
	if(s==1){	glRasterPos2f(360,420); Write1("1");	ar[0]=1;									    }
	if(a==1){	glRasterPos2f(210,420); Write1("0");	ar[3]=0;									    }								
	if(b==1){	glRasterPos2f(260,420); Write1("0");	ar[2]=0;									    }
	if(c==1){	glRasterPos2f(310,420); Write1("0");	ar[1]=0;							            }
	if(d==1){	glRasterPos2f(360,420); Write1("0");	ar[0]=0;									    }
	
  
    if(ci==4)
    {
    
 			int j=0,dec=0;
			for(j=0;j<4;j++)
			{
				dec+=ar[j]*pow(2,j);
			}


			char *s;
			glColor3f(0.0,0.4,0.0);
			glRasterPos2f(50,300);
			Write("Decimal eqivalent = ");
			sprintf(s,"%d",dec);

			
			w=1;
			glRasterPos2f(200,300);
			Write1(s);
			//glColor3f(0.2,0,0.99);
			glColor3f(0,0,0.7);
			glRasterPos2f(50,190);Write("Select position to ");	
			glRasterPos2f(50,150);Write("SET the bit ");
			 
			draw_square(200,150);
			glColor3f(1.0,1.0,1.0);
			glRasterPos2f(210,170); Write1("3");
			draw_square(250,150);
			glColor3f(1.0,1.0,1.0);
			glRasterPos2f(260,170); Write1("2");
			draw_square(300,150);
			glColor3f(1.0,1.0,1.0);
			glRasterPos2f(310,170); Write1("1");
			draw_square(350,150);
			glColor3f(1.0,1.0,1.0);
			glRasterPos2f(360,170); Write1("0");
			if(z==1)
			{
				int test=0;
				glColor3f(0.0,0.0,0.0);
				while(test==0)
				{
				
				if(pos==3){
					test=1;glRasterPos2f(210,170); Write1("3");break;
				}
				if(pos==2){
					test=1;glRasterPos2f(260,170); Write1("2");break;
				}
				if(pos==1){
					test=1;glRasterPos2f(310,170); Write1("1");break;
				}
				if(pos==0){
					test=1;glRasterPos2f(360,170); Write1("0");break;
				}
				
				}
				
				
				
				
				draw(700,700,1);
				draw(750,700,1);
				draw(800,700,1);
				draw(850,700,1);
				
				
				glColor3f(0,0.0,1.0);
				glRasterPos2f(570,720);
				Write("  x ");
				glRasterPos2f(570,570);
				Write("  mask ");
				glRasterPos2f(570,400);
				Write("Result");
				
				
				glColor3f(1,1,1);
				glRasterPos2f(710,720);
				writeint(ar[3]);
				glRasterPos2f(760,720);
				writeint(ar[2]);
				glRasterPos2f(810,720);
				writeint(ar[1]);
				glRasterPos2f(860,720);
				writeint(ar[0]);
				
				glColor3f(1,0,0);
				
				
				glColor3f(0,0.4,0);
				glRasterPos2f(660,570);
				Write("  OR ");
				draw(700,550,2);
				draw(750,550,2);
				draw(800,550,2);
				draw(850,550,2);
				int mask=1<<pos;
				int res=mask|dec;
				res=dtob(res);
				mask=dtob(mask);
				int a1[4]={0};
				int a2[4]={0};
				func(a2,res);
				func(a1,mask);
				int i;
				glColor3f(1,1,1);
				glRasterPos2f(710,570);
				writeint(a1[3]);
				glRasterPos2f(760,570);
				writeint(a1[2]);
				glRasterPos2f(810,570);
				writeint(a1[1]);
				glRasterPos2f(860,570);
				writeint(a1[0]);
			
				glColor3f(0,0,0);
				glRasterPos2f(620,500);
				Write1("___________________________________________");
				
				
				draw(700,380,3);
				draw(750,380,3);
				draw(800,380,3);
				draw(850,380,3);
				glColor3f(1,1,1);
				glRasterPos2f(710,400);
				writeint(a2[3]);
				glRasterPos2f(760,400);
				writeint(a2[2]);
				glRasterPos2f(810,400);
				writeint(a2[1]);
				glRasterPos2f(860,400);
				writeint(a2[0]);
			
				
				glColor3f(0,0,0);
				glRasterPos2f(620,350);
				Write1("___________________________________________");
				
				
				
				
				
			}
			
			
    }
	glFlush();
	
}


void  click(int btn  , int state ,int x , int y)
{
	//printf("%d & %d \n",x,y);
	
	
	if( btn==GLUT_LEFT_BUTTON && state==GLUT_DOWN && w==1 )
	{
		glColor3f(0,0.7,0);
	   	if(x>=270 && x<=322  && y>=546 && y<=592 ){z=1;  pos=3; glutPostRedisplay(); }
		
		if(x>=337 && x<=389  && y>=546 && y<=592){ z=1;  pos=2; glutPostRedisplay(); }
		
		if(x>=406 && x<=455  && y>=546 && y<=592 ){ z=1; pos=1;  glutPostRedisplay();}
		
		if(x>=473 && x<=524  && y>=546 && y<=592 ){ z=1; pos=0;  glutPostRedisplay();}
	}
	
	if( btn==GLUT_LEFT_BUTTON && state==GLUT_DOWN &&ci<=4 )
	{
	   	if(x>=270 && x<=322  && y>=372 && y<=415 ){ p=1; ci++; glutPostRedisplay(); }
		
		if(x>=337 && x<=389  && y>=372 && y<=415 ){ q=1; ci++;glutPostRedisplay(); }
		
		if(x>=406 && x<=455  && y>=372 && y<=415 ){ r=1; ci++;glutPostRedisplay(); }
		
		if(x>=473 && x<=524  && y>=372 && y<=415 ){ s=1; ci++;glutPostRedisplay(); }
	}
		
	
	if( btn==GLUT_RIGHT_BUTTON && state==GLUT_DOWN && ci<=4)
	{
		
		
	
		if(x>=270 && x<=322  && y>=372 && y<=415 ){ a=1; ci++;glutPostRedisplay();}
		
		if(x>=337 && x<=389  && y>=372 && y<=415 ){ b=1; ci++;glutPostRedisplay();}
		
		if(x>=406 && x<=455  && y>=372 && y<=415 ){ c=1; ci++;glutPostRedisplay();}
		
		if(x>=473 && x<=524  && y>=372 && y<=415 ){ d=1; ci++;glutPostRedisplay();}
	
	}
}
void demo_menu(int id)
{
	if(id==1)
	{
		spawnl(P_OVERLAY, "code.exe","code.exe", NULL );
	}
	else
	{
		exit(0);
	}
	
}

int main(int argc,char **argv)
{

	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowPosition(0,0);
	glutInitWindowSize(1350,700);
	glutCreateWindow("SET A BIT");
	glutDisplayFunc(display);
	glutMouseFunc(click);
	init();
	glClearColor(1.0,1.0,1.0,1.0);
	glutCreateMenu(demo_menu);
	glutAddMenuEntry("Restart",1);
	glutAddMenuEntry("Quit",2);
	glutAttachMenu(GLUT_MIDDLE_BUTTON);
	glutMainLoop();
	return 0;
}
