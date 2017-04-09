#include "Texture.h"
 vector<Texture *> Texture::vec;
Texture::Texture(string in_filename, const string &name){
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

	////将全局区域设为操作系统默认区域
	//ifstream file(filename,std::ios::binary);
	//
	//if (!file.is_open())
	//{
	//std::cout << " fail to open  file"<<std::endl;

	//return false;
	//}
	//
	//
	//TgaHeader header;
 // 
	//if (!file.read((char *)&header, sizeof(header))) {
	//	std::cout << " fail to read  header data"<<std::endl;
	//	return false;
	//}
	//
	//if (header.ImageType != 2) {
	//	std::cout << "imageType is unsupportable"<<std::endl;
	//	return false;
	//}
	//if (header.pixelDepth != 24 && header.pixelDepth != 32)
	//{

	//	std::cout << "pixelDepth is unsupportable"<<std::endl;
	//	return false;
	//}
	//	
	//if (header.width == 0 || header.heigh == 0) {
	//std::cout << "width or height is unsupportable"<<std::endl;
	//	return false;
	//}
	// imageType = GL_RGB;
	//if (header.pixelDepth == 32) {
	//	imageType = GL_RGBA;
	//}
	//width = header.width;
	//height = header.heigh;
	//this->filename =new string(filename);
	//GLubyte bitsPerPixel = header.pixelDepth / 8;
	//int imageSize = width*height*bitsPerPixel;
	//   
	//imageData = new GLubyte[imageSize];

	//if (imageData == NULL) {
	//		std::cout << "unable to allocate imageData"<<std::endl;
	//	return false;
	//}

	//
	//if (!file.read((char*)imageData, sizeof(imageData))) {
	//	delete[] imageData;
	//	std::cout << "unable to read imageData from file"<<std::endl;
	//	return false;
	//}
	////swap RGB to BGR
	//for (int i = 0; i < (int)imageSize; i +=bitsPerPixel) {     
	//	GLuint temp = imageData[i];
	//	imageData[i] = imageData[i + 2];
	//	imageData[i + 2] = temp; 
	//}
	GLubyte     TGAheader[12] = { 0,0,2,0,0,0,0,0,0,0,0,0 };    // Uncompressed TGA Header  
	GLubyte     TGAcompare[12];                             // Used To Compare TGA Header  
	GLubyte     header[6];                                  // First 6 Useful Bytes From The Header  
	GLuint      bytesPerPixel;                              // Holds Number Of Bytes Per Pixel Used In The TGA File  
	GLuint      imageSize;                                  // Used To Store The Image Size When Setting Aside Ram  
	GLuint      temp;                                       // Temporary Variable  
	                             // Set The Default GL Mode To RBGA (32 BPP)  
	FILE *file;
	const char * str=filename.data();
	fopen_s(&file,str, "rb");                     // Open The TGA File  
	if (file == NULL ||                                       // Does File Even Exist?  
		fread(TGAcompare, 1, sizeof(TGAcompare), file) != sizeof(TGAcompare) ||  // Are There 12 Bytes To Read?  
		memcmp(TGAheader, TGAcompare, sizeof(TGAheader)) != 0 ||  // Does The Header Match What We Want?  
		fread(header, 1, sizeof(header), file) != sizeof(header))                // If So Read Next 6 Header Bytes  
	{
		if (file == NULL)                                   // Did The File Even Exist? *Added Jim Strong*  
			return false;                                   // Return False  
		else
		{
			fclose(file);                                   // If Anything Failed, Close The File  
			return false;                                   // Return False  
		}
	}

	width = header[1] * 256 + header[0];           // Determine The TGA Width  (highbyte*256+lowbyte)  
	height = header[3] * 256 + header[2];           // Determine The TGA Height (highbyte*256+lowbyte)  

	//OpenGL中纹理只能使用24位或者32位的TGA图像  
	if (width <= 0 ||                              // Is The Width Less Than Or Equal To Zero  
		height <= 0 ||                              // Is The Height Less Than Or Equal To Zero  
		(header[4] != 24 && header[4] != 32))                   // Is The TGA 24 or 32 Bit?  
	{
		fclose(file);                                       // If Anything Failed, Close The File  
		return false;                                       // Return False  
	}

	GLubyte type = header[4];                            // Grab The TGA's Bits Per Pixel (24 or 32)  
	bytesPerPixel = type / 8;                        // Divide By 8 To Get The Bytes Per Pixel  
	imageType = bytesPerPixel == 3 ? GL_RGB : GL_RGBA;
	imageSize = width*height*bytesPerPixel;   // Calculate The Memory Required For The TGA Data  
	imageData = new GLubyte[imageSize];     // Reserve Memory To Hold The TGA Data  
  
    if( imageData==NULL ||                          // Does The Storage Memory Exist?  
        fread(imageData, 1, imageSize, file)!=imageSize)    // Does The Image Size Match The Memory Reserved?  
    {  
		if (imageData != NULL)                     // Was Image Data Loaded  
			delete[]     imageData;                   // If So, Release The Image Data  
        fclose(file);                                       // Close The File  
        return false;                                       // Return False  
    }  
  
    //RGB数据格式转换，便于在OpenGL中使用  
    for(GLuint i=0; i<int(imageSize); i+=bytesPerPixel)      // Loop Through The Image Data  
    {                                                       // Swaps The 1st And 3rd Bytes ('R'ed and 'B'lue)  
        temp=imageData[i];                          // Temporarily Store The Value At Image Data 'i'  
        imageData[i] = imageData[i + 2];    // Set The 1st Byte To The Value Of The 3rd Byte  
        imageData[i + 2] = temp;                    // Set The 3rd Byte To The Value In 'temp' (1st Byte Value)  
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
