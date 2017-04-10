#pragma once
#include <gl/glut.h>
#include <string.h>
#include <iostream>
#include "Texture.h"
using std::string;

class GlEngine
{
public:
	GLubyte  fontSize =13;
	GLubyte  fontspace = 14;
	GLuint fontlist;
	Texture * fontTexture;
	GlEngine();
	GLuint getTextLength(const string &text);
	GLuint getTextLength(const char  *text);
	void drawText(const string &text,int x,int y);
	void drawText(const char  *text,int x,int y);
	GLuint getTextHeight(const string &text);
	GLuint getTextHeight(const char  *text);
	GLvoid buildTexTureFont(void);
	static GlEngine* getInstance();
	void initialize();
	void uninitialize();
	~GlEngine();
};

