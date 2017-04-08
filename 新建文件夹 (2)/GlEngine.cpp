#include "stdafx.h"
#include "GlEngine.h"


GlEngine::GlEngine()
{

}
GlEngine* GlEngine::getInstance() {
static GlEngine *gl= new GlEngine();
return gl;
}
void GlEngine::initialize() {

}
void GlEngine::uninitialize() {

}

GlEngine::~GlEngine()
{
}
