#pragma once
#include <gl/glut.h>
#include "iostream"
#include "stdio.h"
#include "vector"
#include <string>
#include <ostream>
#include <fstream>

using std::string;
using std::fstream;
using std::ifstream;
using std::ostream;
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
	
	bool loadTga(string filename);
		

	bool createTexture();

};
