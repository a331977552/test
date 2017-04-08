//#include "stdafx.h"

#include <gl/glut.h>
#include "iostream"
#include "stdio.h"
#include "Texture.h"
#include "GlEngine.h"
#include "Control.h"
const GLsizei width = 400;
const GLsizei height = 400;
float angleX = 45;
float angleY = 45;
char keys[255];
Texture *tex;
Control  *c=NULL;
Control::mouseState mouseState;
Control * controlled=NULL;
void checkKey() {
	const static float speed = .01f;
	if (keys[GLUT_KEY_F1]) {
		exit(0);
	}
	if (keys[GLUT_KEY_UP]) {
		angleX += speed;
	}
	if (keys[GLUT_KEY_DOWN]) {
		angleX -= speed;
	}
	if (keys[GLUT_KEY_LEFT]) {
		angleY-= speed;
	}
	if (keys[GLUT_KEY_RIGHT]) {
		angleY+= speed;
	}

}
void displayFPS() {
	static long  lastTime = glutGet(GLUT_ELAPSED_TIME);
	 static long loops = 0;
	 static  float fps = 0;
	  long  newTime = glutGet(GLUT_ELAPSED_TIME);
	 long time=newTime - lastTime;
	 if (time > 100) {
		  float fps2= (float)loops /(float)time  *1000.f;
		  fps = (fps + fps2) / 2.f ;
		  char title[80];
		  sprintf_s(title, "current fps:%.1f" ,fps);
		  glutSetWindowTitle(title);
		  lastTime = newTime;
		  loops = 0;
	 }
	 loops++;
}
void drawControl() {
	for (list<Control *>::iterator it = Control::controls.begin(); it != Control::controls.end(); it++) {
		 Control* control= (*it);
		 control->drawControl();
		 if (controlled != NULL &&controlled != control)
			 continue;
		if (control->updateControl(mouseState)) {
			controlled = control;
		}else if(controlled == control){
			controlled = NULL;
		}else{
		  
		}
	
	}


}
void draw() {
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glBindTexture(GL_TEXTURE_2D, tex->texId);
	glColor3f(1.0f, 1.0f, 1.0f);
	glTranslatef(0, 0, -5.0f);
	glRotatef(angleX, 1, 0, 0);
	glRotatef(angleY, 0, 1, 0);
	glBegin(GL_QUADS);
	
	glTexCoord2f(1.0f, 1.0f); glVertex3f(1.f, 1.f, -1.f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.f, 1.f, -1.f);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.f, 1.f, 1.f);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(1.f, 1.f, 1.f);
	
	glTexCoord2f(1.0f, 1.0f); glVertex3f(1.f, -1.f, 1.f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.f, -1.f, 1.f);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.f, -1.f, -1.f);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(1.f, -1.f, -1.f);
	
	
	glTexCoord2f(1.0f, 1.0f); glVertex3f(1.f, 1.f, 1.f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(1.f, -1.f, 1.f);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.f, -1.f, 1.f);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.f, 1.f, 1.f);

	
	glTexCoord2f(1.0f, 1.0f); glVertex3f(1.f, 1.f, -1.f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(1.f, -1.f, -1.f);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.f, -1.f, -1.f);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.f, 1.f, -1.f);
	
	
	glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.f, 1.f, 1.f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.f, -1.f, 1.f);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.f, -1.f, -1.f);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.f, 1.f, -1.f);


	glTexCoord2f(1.0f, 1.0f); glVertex3f(1.f, 1.f, 1.f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(1.f, -1.f, 1.f);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(1.f, -1.f, -1.f);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(1.f, 1.f, -1.f);

	glEnd();
	glFlush();
	glutSwapBuffers();
	checkKey();
	glMatrixMode(GL_MODELVIEW);
	gluOrtho2D(0,width,0,height);
	displayFPS();
	glLoadIdentity();
	drawControl();
}

void initGL() {
	string  str("f:\\font.tga");
	tex = new Texture(str,"surface test");
	glViewport(0, 0, width, height);
	glClearColor(0.0f, 0.0f, 0.0f,1.0f);
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);
	glShadeModel(GL_SMOOTH);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45, width / height, 1, 200);
	glEnable(GL_TEXTURE_2D);
	GlEngine::getInstance()->initialize();
}
void timer(int value) {
	
	glutTimerFunc(1000,timer,0);
}
void drawWhenIdle() {
	
	draw();

}
GLvoid keyboardFunc(unsigned char key,int x,int y) {
	keys[key] = true;
}
GLvoid keyboardUpFunc(unsigned char key,int x,int y) {
	keys[key] = false;
}
GLvoid keyboardSpecialFunc(int key,int x,int y) {
	keys[key] = true;
}
GLvoid keyboardSpecialUpFunc(int key,int x,int y) {
	keys[key] = false;
}
void mouseStateFunc(int button,int state,int x,int y) {	
						
	mouseState.leftButtonDown = (button==GLUT_LEFT_BUTTON &&state==GLUT_DOWN);
    mouseState.rightButtonDown = (button==GLUT_RIGHT_BUTTON &&state==GLUT_DOWN);
	mouseState.middleuttonDown=(button==GLUT_MIDDLE_BUTTON &&state==GLUT_DOWN);
	mouseState.x = x;
	mouseState.y = y;
}

int main(int args, char **argv) {

	glutInit(&args, argv);
	glutInitDisplayMode(GLUT_DOUBLE);
	glutCreateWindow("test1");
	glutDisplayFunc(draw);
	glutTimerFunc(1000,timer,0);
	glutInitWindowSize(width, height);
	glutIdleFunc(drawWhenIdle);
	glutMouseFunc(mouseStateFunc);
	glutKeyboardFunc(keyboardFunc);
	glutKeyboardUpFunc(keyboardUpFunc);
	glutSpecialFunc(keyboardSpecialFunc);
	glutSpecialUpFunc(keyboardSpecialUpFunc);

	initGL();
	glutMainLoop();
	for (list<Control *>::iterator it = Control::controls.begin(); it != Control::controls.end(); it++) 
		 delete (*it);
	GlEngine::getInstance()->uninitialize();
	return  0;
}



