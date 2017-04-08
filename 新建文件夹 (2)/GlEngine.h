#pragma once
#include <gl/glut.h>

class GlEngine
{
public:
	GlEngine();
	static GlEngine* getInstance();
	void initialize();
	void uninitialize();
	~GlEngine();
};

