//#include "stdafx.h"

#include <gl/glut.h>
#include "iostream"
#include "stdio.h"
#include "Texture.h"
#include "GlEngine.h"
#include "Control.h"
#include "Button.h"
#include "ListBox.h"
#include "Slider.h"
const GLsizei width = 500;
const GLsizei height = 500;
bool navigating=false;
float angleX = 0;
float angleY = 0;
char keys[255];
Texture *tex;
Control  *c=NULL;
GLuint gridList;
float zoom = -5.0f;
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
	   char title[80];
	 if (time > 100) {
		  float fps2= (float)loops /(float)time  *1000.f;
		  fps = (fps + fps2) / 2.f ;
		 // glutSetWindowTitle(title);	
		  lastTime = newTime;
		  loops = 0;
	 }
	   sprintf_s(title, "fps: %.1f" ,fps);
	   GlEngine::getInstance()->drawText(title,0,0);
	 loops++;
}
void drawControl() {
	for (list<Control *>::iterator it = Control::controls.begin(); it != Control::controls.end(); it++) {
		 Control* control= (*it);
		 control->drawControl();
		 if ((controlled != NULL &&controlled != control )||  navigating ) {
		  continue;
		 }
		if (control->updateControl(mouseState)) {
			controlled = control;
		}else{
		  controlled = NULL;
		}
		
	
	}


}
void drawCube() {
	glDisable(GL_BLEND);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, tex->texId);
	glColor3f(1.0f, 1.0f, 1.0f);
	glTranslatef(0, 0, zoom);
	glRotatef(angleX, 1, 0, 0);
	glRotatef(angleY, 0, 1, 0);
	if (gridList == 0) {
		gridList=glGenLists(1);
		glNewList(gridList, GL_COMPILE_AND_EXECUTE);
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
		
		glEndList();
	}
	else {

		glCallList(gridList);
	}
}

void  establishMatrixProjection() {
	glViewport(0, 0, width, height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45, width / height, 1, 200);
}
void setOrtho() {
	glViewport(0, 0, width, height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, width, height, 0);

}
void navigatingByMouse() {
	static  float lastX = 0.0f;
	static  float lastY = 0.0f;
	float changex = lastX - mouseState.x;
	float changey = lastY - mouseState.y;
	lastX = mouseState.x;
	lastY = mouseState.y;
	if (mouseState.leftButtonDown &&controlled==NULL) {
		
		navigating = true;
		angleX -= changey*0.1f;
		angleY -= changex*0.1f;
	
	}else if(mouseState.rightButtonDown &&controlled==NULL){
		navigating = true;
		zoom -=changex *0.1f;
		zoom -= changey*0.1f;
		if (zoom >= 0) {
			zoom = -3;
		}
	}else{
		navigating = false;
	}
}
void draw() {
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	establishMatrixProjection();
	drawCube();
	checkKey();
	
	setOrtho();
	displayFPS();
	drawControl();
	navigatingByMouse();
	glFlush();
	glutSwapBuffers();
}


void initGL() {
	string  str("f:/surface.tga");
	tex = new Texture(str,"surface test");
	glClearColor(0.0f, 0.0f, 0.0f,1.0f);
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);
	glShadeModel(GL_SMOOTH);
	establishMatrixProjection();
	glEnable(GL_TEXTURE_2D);
	GlEngine::getInstance()->initialize();
	GlEngine::getInstance()->buildTexTureFont();
	Button * btn = new Button("hit me", 100, 100, 100, 30);
	
	ListBox *  box=(ListBox *  )Control::addControl(new ListBox(100,150,100,100));
	Control::addControl(btn);
	box->addItem("jack1");
	box->addItem("jack2");
	box->addItem("jack3");
	box->addItem("jack4");	

	Slider *  slider=(Slider *  )Control::addControl(new Slider(string("test"),-5.0f,5.0f,100,150,100,20));
	slider->setValue(3.f);
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

	std::cout << "x:" << x << "y:" << y<<std::endl;
	mouseState.leftButtonDown = (button==GLUT_LEFT_BUTTON &&state==GLUT_DOWN);
    mouseState.rightButtonDown = (button==GLUT_RIGHT_BUTTON &&state==GLUT_DOWN);
	mouseState.middleuttonDown=(button==GLUT_MIDDLE_BUTTON &&state==GLUT_DOWN);
	mouseState.x = x;
	mouseState.y = y;
}
void mouseMotionFunc(int x,int y) {
	mouseState.x = x;
	mouseState.y = y;
}
void mousePassiveMotionFunc(int x, int y) {
	mouseState.x = x;
	mouseState.y = y;
}

int main(int args, char **argv) {

	glutInit(&args, argv);
	glutInitDisplayMode(GLUT_DOUBLE);
	glutInitWindowSize(width, height);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("test1");
	initGL();
	glutTimerFunc(1000,timer,0);
	glutIdleFunc(drawWhenIdle);
	glutMouseFunc(mouseStateFunc);
	glutMotionFunc(mouseMotionFunc);
	glutPassiveMotionFunc(mousePassiveMotionFunc);
	glutKeyboardFunc(keyboardFunc);
	glutKeyboardUpFunc(keyboardUpFunc);
	glutSpecialFunc(keyboardSpecialFunc);
	glutSpecialUpFunc(keyboardSpecialUpFunc);
	
	glutDisplayFunc(draw);
	
	glutMainLoop();
	for (list<Control *>::iterator it = Control::controls.begin(); it != Control::controls.end(); it++) 
		 delete (*it);
	GlEngine::getInstance()->uninitialize();
	return  0;
}



