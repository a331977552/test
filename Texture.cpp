#include "Texture.h"
 vector<Texture *> Texture::vec;
Texture::Texture(string &in_filename, const string &name){
	   vec.push_back(this);
		this->name = name;
		loadTga(in_filename);
}
Texture::~Texture(){
		vector<Texture *>::iterator or=vec.begin();
		while(or!=vec.end()) {
			if ((*or) == this) {
				vec.erase(or);
				break;
			}
			or++;
		}
		if (!imageData)
			delete []imageData;
	}
bool Texture::loadTga(string filename) {
	
		//将全局区域设为操作系统默认区域
		ifstream file("f:\\test.tga",std::ios_base::binary);
		
		if (!file.is_open())
		{
		std::cout << " fail to open  file"<<std::endl;
	
		return false;
		}
		
		
		TgaHeader header;
		if (!file.read((char *)&header, sizeof(header))) {
			std::cout << " fail to read  header data"<<std::endl;
			return false;
		}
		if (header.ImageType != 2) {
			std::cout << "imageType is unsupportable"<<std::endl;
			return false;
		}
		if (header.colorBit != 24 && header.colorBit != 32)
		{

			std::cout << "colorBit is unsupportable"<<std::endl;
			return false;
		}
			
		if (header.width == 0 || header.heigh == 0) {
		std::cout << "width or height is unsupportable"<<std::endl;
			return false;
		}
			
		if (header.pixelDepth != 24 && header.pixelDepth != 32){
			std::cout << "pixelDepth  is unsupportable"<<std::endl;
			return false;
		}
		 imageType = GL_RGB;
		if (header.pixelDepth == 32) {
			imageType = GL_RGBA;
		}
		width = header.width;
		height = header.heigh;
		this->filename =new string(filename);
		GLubyte bitsPerPixel = header.pixelDepth / 8;
		int imageSize = width*height*bitsPerPixel;
		imageData = new GLubyte[imageSize];
		if (imageData == NULL) {
				std::cout << "unable to allocate imageData"<<std::endl;
			return false;
		}
		if (!file.read((char*)imageData, sizeof(imageData))) {
			delete[] imageData;
			std::cout << "unable to read imageData from file"<<std::endl;
			return false;
		}
		//swap RGB to BGR
		for (int i = 0; i < imageSize; i +=bitsPerPixel) {
			GLubyte temp = imageData[i];
			imageData[i] = imageData[i + 2];
			imageData[i + 2] = temp; 
		}
		createTexture();
		return true;
	}

bool Texture::createTexture() {
	glGenTextures(1, &texId);
	glBindTexture(GL_TEXTURE_2D, texId);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexImage2D(GL_TEXTURE_2D, 0, imageType, width, height, 0, imageType, GL_UNSIGNED_BYTE, imageData);
	return true;
}
