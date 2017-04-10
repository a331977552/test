
#include "GlEngine.h"


GlEngine::GlEngine()
{

}
GlEngine* GlEngine::getInstance() {
static GlEngine *gl= new GlEngine();
return gl;
}
GLuint GlEngine::getTextLength(const string &text) {

	return getTextLength(text.data());
}
GLuint  GlEngine::getTextLength(const char  *text) {
		return strlen(text)*fontspace;
}
void        GlEngine::drawText(const string &text,int x,int y) {
	drawText(text.data(), x, y);
}
void         GlEngine::drawText(const char  *text,int x,int y) {
	glEnable(GL_TEXTURE_2D);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA,GL_ONE);
	glBindTexture(GL_TEXTURE_2D, fontTexture->texId);
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glLoadIdentity();
	glTranslated(x, y, 0);
	glListBase(fontlist -48);
	glCallLists(strlen(text), GL_BYTE, text);
	glMatrixMode(GL_MODELVIEW);
	glPopMatrix();

}
GLuint GlEngine::getTextHeight(const string &text) {
		return getTextHeight(text.data());
}
GLuint  GlEngine::getTextHeight(const char  *text) {
		return fontspace;
}
GLvoid GlEngine::buildTexTureFont(void) {
	glEnable(GL_TEXTURE_2D);
	string str("f:\\font.tga");
	fontTexture = new Texture(str,"font");
	glBindTexture(GL_TEXTURE_2D, fontTexture->texId);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE);
	fontlist=glGenLists(256);
	for (int i = 0; i< 256; i++) {
			float cx = (float) (i % 16) / 16.0f;
			float cy = (float) (i / 16) / 16.0f;
		glNewList(fontlist+i,GL_COMPILE);
		glBegin(GL_QUADS);
			glTexCoord2d(cx,      1 - cy );						glVertex2i(0, fontSize);
			glTexCoord2d(cx+0.0625f,1 - cy);					glVertex2i(fontSize, fontSize);
			glTexCoord2d(cx+0.0625f,1 - cy - 0.0625f );         glVertex2i(fontSize, 0);
			glTexCoord2d(cx,         1 - cy - 0.0625f );        glVertex2i(0,0 );
		glEnd();
		glTranslated(fontspace, 0, 0);
		glEndList();
	}
}
void GlEngine::initialize() {
	
	
}
void GlEngine::uninitialize() {

}

GlEngine::~GlEngine()
{
}
