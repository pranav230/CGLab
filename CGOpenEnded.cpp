#include <bits/stdc++.h>
#include <GL/glut.h>
#include <unistd.h>

using namespace std;

int j = 0;
int inc=0;
int slide=0;

void drawBox(int x,int y){
	glColor3f(1.0,0.0,0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, 2500, 0, 2500);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glPushMatrix();
	glLoadIdentity();
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();  
	glTranslatef(600,1800,0); 

	glBegin(GL_POLYGON);
	glVertex2f(-400,-200);
	glVertex2f(-400,200);
	glVertex2f(400,200);
	glVertex2f(400,-200);
	glEnd();
	glPopMatrix();
	glutSwapBuffers();
}

void drawLock(){
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, 2500, 0, 2500);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glPushMatrix();
	glLoadIdentity();
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();  
	glColor3f(1.0,1.0,0.0);
	glTranslatef(1200,1800,0); 

	glBegin(GL_POLYGON);
	glVertex2f(-400,-400);
	glVertex2f(-400,400);
	glVertex2f(400,400);
	glVertex2f(400,-400);
	glEnd();//here here
	glPopMatrix();

	glutSwapBuffers();
}

void drawHole(){
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, 2500, 0, 2500);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glPushMatrix();
	glLoadIdentity();
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();  
	glTranslatef(1200,1650,0); 
	glColor3f(0.0,0.0,0.0);
	glBegin(GL_POLYGON);
	glVertex2f(-40,-40);
	glVertex2f(-40,40);
	glVertex2f(40,40);
	glVertex2f(40,-40);
	glEnd();//here here
	glPopMatrix();
	glColor3f(1.0,0.0,0.0);
	glutSwapBuffers();
}

void extendHole(){
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, 2500, 0, 2500);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glPushMatrix();
	glLoadIdentity();
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();  
	glTranslatef(1200,1600,0); 
	glColor3f(0.0,0.0,0.0);
	glBegin(GL_POLYGON);
	glVertex2f(-20,-20);
	glVertex2f(-20,20);
	glVertex2f(20,20);
	glVertex2f(20,-20);
	glEnd();//here here
	glPopMatrix();
	glColor3f(1.0,0.0,0.0);
	glutSwapBuffers();
}

void handle(){
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, 2500, 0, 2500);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glPushMatrix();
	glLoadIdentity();
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();  
	glTranslatef(1200,2200,0); 
	glColor3f(0.0,0.0,1.0);
	glLineWidth(5.0);
	glBegin(GL_LINE_STRIP);
	glVertex2f(-200,0);
	glVertex2f(-200,200);
	glVertex2f(200,200);
	glVertex2f(200,0);
	glEnd();//here here
	glPopMatrix();
	glColor3f(1.0,0.0,0.0);
	glutSwapBuffers();
	}

void drawText2(const char *text,int x,int y,float r,float g,float b){
	glLineWidth(2.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, 2500, 0, 2500);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glPushMatrix();
	glLoadIdentity();
	glRasterPos2i(0,0);

	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glTranslatef(x,y,0); 
	glColor3f(r,g,b);
	glLineWidth(4.0);
	
	for (int i = 0; i < strlen(text); i++)
		glutStrokeCharacter(GLUT_STROKE_ROMAN, text[i]);

	glPopMatrix();
	glutSwapBuffers();
}

void rowDisplay(int i, int k) {
	glPushMatrix();
	glColor3f(1, 0, 0);
	glTranslated(-0.9+(i*0.2), 1-(k*0.1), 0);
	glScalef(2,2,2);
	glutSolidSphere(0.05,70,70);
	glPopMatrix();
}

void curtainMove(){
	glFlush();
	glClear(GL_COLOR_BUFFER_BIT);
	int i;
	for(int k=0; k<j; k++) {
    	for(int i=0; i<10; i++) {
     		rowDisplay(i, k);
    	}
  	}
	glFlush();
}

void display()
{
	glFlush();
	glClearColor(1,1,1,1 );
	glClear(GL_COLOR_BUFFER_BIT);
	if(slide==0){
		for(j=0;j<=20;j++)
			curtainMove();

		curtainMove();

		for(j=20;j>=0;j--)
			curtainMove();

		slide=1;
	}
	else if(slide==1){
		drawText2("INTERNET AWARENESS",300,2200,1.0,0.0,1.0);
		drawText2("AMONG CHILDREN",300,2000,1.0,0.0,1.0);
		drawText2("CG OPEN ENDED MADE BY",300,1600,0.0,0.0,1.0);
		drawText2("PRANAV AND NIKHIL",300,1400,1.0,0.0,0.0);
		drawText2("FACULTY:",300,900,1.0,1.0,0.0);
		drawText2("SHWETA MA'AM",300,700,0.0,1.0,0.0);
		drawText2("RAGHAVENDRA SIR",300,500,1.0,0.0,0.0);
		glColor3f(1.0,0.0,0.0);

		if(inc > 0){
			inc=-1;
			slide++;
		}
	}
	else if(slide==2){
		glClear(GL_COLOR_BUFFER_BIT);
		glClearColor(1.0,1.0,1.0,1.0);
		drawBox(200,200);
		
		if(inc>=1)
			drawText2("INTERNET",300,1400,1.0,0.0,1.0);

		if(inc>=2)
			drawText2("_________",1000,1800,0.0,0.0,1.0);

		if(inc>=3)
			drawText2("STREAM",1300,1850,0.0,0.0,1.0);

		if(inc>=4){
			drawText2("MIND",2000,1740,0.701428,0.0,1.0);
			drawText2("___",2000,1735,0.701428,0.0,1.0);
			glColor3f(1.0,0.0,0.0);
		}
		if(inc>=5){
			drawText2(">The stream of information entering",30,1200,1.0,0.0,0.0);
			drawText2(" the mind of a kid must be ",30,1050,1.0,0.0,0.0);
			drawText2(" controlled.",30,900,1.0,0.0,0.0);
		}
		if(inc>=6){
			drawText2(">Avoiding pop-ups and disturbing ads",30,700,0.0,1.0,0.0);
			drawText2(" which may be irrelevant.",30,550,0.0,1.0,0.0);
			glColor3f(1.0,0.0,0.0);
		}
		if(inc>6){
			inc=-1;
			slide++;
		}
	}
	else if(slide==3){
		drawLock();
		drawHole();
		extendHole();
		handle();
		if(inc>=1){
			drawText2(">Avoid Fraud Links and don't share",30,700,0.0,1.0,0.0);
			drawText2(" your passwords online.",30,550,0.0,1.0,0.0);
			glColor3f(1.0,0.0,0.0);
		}
		if(inc>=2){
			drawText2(">Don't download files from untrusted",30,400,1.0,0.0,0.0);
			drawText2(" sources and run them",30,250,1.0,0.0,0.0);
		}
		if(inc>2){
			inc=-1;
			slide++;
		}
	}
	else if(slide==4){
		drawText2("STAY SAFE!",800,1400,1.0,0.0,0.0);
		drawText2("STAY VIGILANT!",800,1200,1.0,0.0,0.0);
		drawText2("THANK YOU! :)",800,1000,1.0,0.0,0.0);
	}
}

void mykeys(unsigned char key,int x, int y)
{
	if(key=='1'){
		slide=1;
		inc=0;
		glutPostRedisplay();
	}
	else if(key=='2'){
		slide=2;
		inc=0;
		glutPostRedisplay();
	}
	else if(key=='3'){
		inc=0;
		slide=3;
		glutPostRedisplay();
	}
	else if(key=='4'){
		inc=0;
		slide=4;
		glutPostRedisplay();
	}
	else if(key=='n'){
		inc++;
		glutPostRedisplay();
	}
}

// void subMenu(int id){
// 	slide=id;
// 	glutPostRedisplay();
// }

void mainmenu(int id){
	switch(id){
		case 1:
			slide++;
			glutPostRedisplay();
			break;
		case 3:
			exit(0);
	}
}

int main(int argc,char **argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_RGB|GLUT_SINGLE);
	glutInitWindowSize(700, 700);
	glutCreateWindow("Curtains");
	glutDisplayFunc(display);
	glutKeyboardFunc(mykeys);
	// int id=glutCreateMenu(subMenu);
	glutAddMenuEntry("Name Display",1);
	glutAddMenuEntry("Slide 1:Info Stream",2);
	glutAddMenuEntry("Slide 2:Privacy",3);
	glutAddMenuEntry("Slide 3:End",4);
	glutCreateMenu(mainmenu);
	// glutAddMenuEntry("Next slide",1);
	// glutAddSubMenu("Jump to slide",id);
	// glutAddMenuEntry("exit",3);
	// glutAttachMenu(GLUT_RIGHT_BUTTON);
	glutMainLoop();
	return 0;
}
