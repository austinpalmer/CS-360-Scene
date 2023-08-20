#pragma once
#include <string>
#include <glad/glad.h>

class Texture {
public:
	explicit Texture(std::string fileName);
	void Bind();

private:
	GLuint textureID;
};