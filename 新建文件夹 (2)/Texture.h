#pragma once
#include <gl/glut.h>
#include "iostream"
#include <stdio.h>
#include "vector"
#include <stdlib.h>
#include <string>
using std::string;
using std::vector;
class Texture {
	struct TgaHeader {
		GLubyte  length;
		GLubyte  ColorMaptype;
		GLubyte  ImageType;
		GLubyte  colorMapSpecification[5];
		GLushort  originX;
		GLushort  originY;
		GLushort  width;
		GLushort  heigh;
		GLubyte   pixelDepth;
		GLubyte   info;
	};
public :
	Texture(string &filename, const string &name = "");

	~Texture();

public :
	string name;
	string *filename;
	GLushort  width;
	GLushort  height;
	GLubyte *imageData;
	//RGB or RGBA
	GLuint imageType;
	GLuint texId;
	static vector<Texture *> vec;
private :
	
	bool loadTga(const char * name);
		

	bool createTexture();

};
