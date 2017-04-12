#include "Mesh.h"



Mesh::Mesh() :Node() {

}
Mesh::~Mesh() {

}
bool    Mesh::drawMesh(bool drawChildren , Mesh *drawSelected ) {
	

	return true;
}
Transform& Mesh::getTransform() {

	return transform;
}

void	Mesh::drawFace(Face *face) {
		
	glBegin(GL_TRIANGLES);
	for (int i = 0; i < 3; i++) {	
		Vector3 *normal=face->normals[i];
		Vector3 *vertices=face->vertices[i];
		Vector3 *UVs=face->UVs[i];
		glTexCoord2f(UVs[i].x, UVs[i].y);
		glNormal3d(normal[i].x,normal[i].y, normal[i].z);
		glVertex3d(vertices[i].x, vertices[i].y,vertices[i].z);
	}
	glEnd();

}
int		Mesh::addVertex(float x, float y, float z) {
	vertices.push_back(new Vector3(x, y, z));
	return  vertices.size() - 1;
}
int		Mesh::addNormal(float x, float y, float z) {
	normals.push_back(new Vector3(x, y, z));
	return  normals.size() - 1;
}
int		Mesh::addTexCoord(float s, float t) {
	UVs.push_back(new Vector3(s, t, 0));
	return  UVs.size() - 1;
}
void	Mesh::addFace(int v1, int v2, int v3,
					  int  n1, int  n2, int  n3,
					  int  uv1, int  uv2, int  uv3) {
	faces.push_back(new Face(vertices[v1], vertices[v2], vertices[v3],
							 normals[n1], normals[n2], normals[n3],
							 UVs[uv1], UVs[uv2], UVs[uv3]
	));

}