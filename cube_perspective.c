#include<stdio.h>
#include<GL/glut.h>

static GLfloat theta[] = {0.0,0.0,0.0};
static GLint axis = 2;
GLdouble viewer[]={0.0,0.0,5.0}; 
//GLfloat ver[][3] = { {-1.0,-1.0,1.0},{-1.0,1.0,1.0},{1.0,1.0,1.0},{1.0,-1.0,1.0},
//					{-1.0,-1.0,1.0},{-1.0,1.0,1.0},{1.0,1.0,1.0},{1.0,-1.0,1.0}};
GLfloat ver[][3] = {{-1.0,-1.0,1.0},{-1.0,1.0,1.0},{1.0,1.0,1.0},{1.0,-1.0,1.0} , {-1.0,-1.0,-1.0},{-1.0,1.0,-1.0},{1.0,1.0,-1.0}, {1.0,-1.0,-1.0}}; 
			
//GLfloat col[][3] = {{1.0,1.0,1.0,0.0},{1.0,0.0,0.0,0.0}, {0.0,1.0,0.27,0.0}, {0.0,0.68,1.0,0.0}, {1.0,0.33,0.0,0.0},{0.45,0.0,-0.9,0.0},{0.0,1.0,1.0,0.0},{0.2,1.0,0.7} };
GLfloat col[][4] =  {{0.0,0.0,0.0},{1.0,0.0,0.0,0.0},{0.0,1.0,0.0,0.0},{0.0,0.0,1.0,0.0},{1.0,1.0,0.0,0.0},{0.0,1.0,1.0,0.0},{1.0,0.0,1.0,0.0},{0.5,0.5,0.5,0.0}};

void polygon(int a , int b ,int  c ,int d)
{
	glBegin(GL_POLYGON);
	
		glColor3fv(col[a]);
		glVertex3fv(ver[a]);
		
		glColor3fv(col[b]);
		glVertex3fv(ver[b]);
		
	    glColor3fv(col[c]);
		glVertex3fv(ver[c]);
		
		glColor3fv(col[d]);
		glVertex3fv(ver[d]);
		
	glEnd();
}

void  colorcube()
{
	/* map vertices to faces */ 
//	polygon(0,3,2,1);  polygon(2,3,7,6);  polygon(0,4,7,3);  polygon(1,2,6,5);  polygon(4,5,6,7);  polygon(0,1,5,4); 
	 polygon(0,3,2,1);
	 polygon(2,3,7,6);
	 polygon(0,4,7,3); 
	 polygon(1,2,6,5); 
     polygon(4,5,6,7);
     polygon(0,1,5,4);
}

void display() { 
/* display callback, clear frame buffer and z buffer,    rotate cube and draw, swap buffers */  
glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);  
glLoadIdentity(); 
 gluLookAt(viewer[0],viewer[1],viewer[2],0.0,0.0,0.0,0.0,1.0,0.0); 
 glRotatef(theta[0], 1.0, 0.0, 0.0);
 glRotatef(theta[1], 0.0, 1.0, 0.0);
 glRotatef(theta[2], 0.0, 0.0, 1.0);
 colorcube(); 
 glFlush();
 glutSwapBuffers(); 
 }
 
 void spinCube()
  { 
  /* idle callback, spin cube 2 degrees about selected axis */ 
   theta[axis] += 0.02;
   if( theta[axis] > 360.0 ) 
   theta[axis] -= 360.0;  
   glutPostRedisplay(); 
}

void mouse(int btn, int state, int x, int y) 
{
 /* mouse callback, selects an axis about which to rotate */  
if(btn==GLUT_LEFT_BUTTON && state == GLUT_DOWN) axis = 0;  
if(btn==GLUT_MIDDLE_BUTTON && state == GLUT_DOWN) axis = 1; 
 if(btn==GLUT_RIGHT_BUTTON && state == GLUT_DOWN) axis = 2;
 theta[axis]+=2.0;  
 if(theta[axis]>360.0) 
 theta[axis]-=360.0;  
 display(); 
} 
 void keys(unsigned char key,int x,int y) {   
 if(key=='X') 
 viewer[0]-=1.0;   
 if(key=='x') 
 viewer[0]+=1.0;   
 if(key=='Y') 
 viewer[1]-=1.0;   
 if(key=='y') 
 viewer[1]+=1.0;   
 if(key=='Z') 
 viewer[2]-=1.0;   
 if(key=='z') 
 viewer[2]+=1.0;   
 display();
}
 void myReshape(int w, int h)
  { 
      glViewport(0, 0, w, h);     
	  glMatrixMode(GL_PROJECTION);   
	  glLoadIdentity();   
		  if (w <= h) 
		          glOrtho(-2.0, 2.0, -2.0 * (GLfloat) h / (GLfloat) w, 2.0 * (GLfloat) h / (GLfloat) w, -10.0, 10.0); 
	     else      
		           glOrtho(-2.0 * (GLfloat) w / (GLfloat) h, 2.0 * (GLfloat) w / (GLfloat) h, -2.0, 2.0, -10.0, 10.0);
				   
	
	  gluPerspective(50.0,w/h,1.0,10.0); 
      glMatrixMode(GL_MODELVIEW);
}
int main(int argc, char **argv) { 
glutInit(&argc, argv);  /* need both double buffering and z buffer */   
glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);  
glutInitWindowPosition(350,50);
glutInitWindowSize(500, 500);   
glutCreateWindow("CUBE ");    
glutReshapeFunc(myReshape);
glutDisplayFunc(display);   
glutIdleFunc(spinCube);   
glutMouseFunc(mouse); 
glutKeyboardFunc(keys);    
glEnable(GL_DEPTH_TEST); /* Enable hidden-surface removal */    
glutMainLoop();
return 0; 

} 
