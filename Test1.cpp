//#include "stdafx.h"

#include <gl/glut.h>
#include "iostream"
#include "stdio.h"
#include "Texture.h"
const GLsizei width = 400;
const GLsizei height = 400;
float angleX = 45;
float angleY = 45;
char keys[255];
Texture *tex;
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
	
	glVertex3f(1.f, 1.f, 1.f);
	glVertex3f(-1.f, 1.f, 1.f);
	glVertex3f(-1.f, 1.f, -1.f);
	glVertex3f(1.f, 1.f, -1.f);
	
	glVertex3f(1.f, -1.f, 1.f);
	glVertex3f(-1.f, -1.f, 1.f);
	glVertex3f(-1.f, -1.f, -1.f);
	glVertex3f(1.f, -1.f, -1.f);
	
	
	glVertex3f(1.f, 1.f, 1.f);
	glVertex3f(1.f, -1.f, 1.f);
	glVertex3f(-1.f, -1.f, 1.f);
	glVertex3f(-1.f, 1.f, 1.f);

	
	glVertex3f(1.f, 1.f, -1.f);
	glVertex3f(1.f, -1.f, -1.f);
	glVertex3f(-1.f, -1.f, -1.f);
	glVertex3f(-1.f, 1.f, -1.f);
	
	
	glVertex3f(-1.f, 1.f, 1.f);
	glVertex3f(-1.f, -1.f, 1.f);
	glVertex3f(-1.f, -1.f, -1.f);
	glVertex3f(-1.f, 1.f, -1.f);


	glVertex3f(1.f, 1.f, 1.f);
	glVertex3f(1.f, -1.f, 1.f);
	glVertex3f(1.f, -1.f, -1.f);
	glVertex3f(1.f, 1.f, -1.f);

	glEnd();
	glFlush();
	glutSwapBuffers();
	checkKey();
	displayFPS();
}

void initGL() {
	string  str("f:\test.tga");
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
int main(int args, char **argv) {

	glutInit(&args, argv);
	glutInitDisplayMode(GLUT_DOUBLE);
	glutCreateWindow("test1");
	glutDisplayFunc(draw);
	glutTimerFunc(1000,timer,0);
	glutInitWindowSize(width, height);
	glutIdleFunc(drawWhenIdle);
	glutKeyboardFunc(keyboardFunc);
	glutKeyboardUpFunc(keyboardUpFunc);
	glutSpecialFunc(keyboardSpecialFunc);
	glutSpecialUpFunc(keyboardSpecialUpFunc);

	initGL();
	glutMainLoop();

	return  0;
}



