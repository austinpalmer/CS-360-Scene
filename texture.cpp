#include "texture.h"
#include <stb_image.h>
#include <iostream>

Texture::Texture(std::string fileName) {
	// Load a texture
	stbi_set_flip_vertically_on_load(true);
	int width, height, numChannels;
	unsigned char* data = stbi_load(fileName.c_str(), &width, &height, &numChannels, 0);

	// Generate texture/s
	glGenTextures(1, &textureID);
	// Bind texture/s
	glBindTexture(GL_TEXTURE_2D, textureID);

	if (data) {
		if (numChannels == 3) {
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB8, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
		}
		else if (numChannels == 4) {
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
		}
		else {
			std::cout << "Unable to handle this file type";
		}
		// Generate mipmap
		glGenerateMipmap(GL_TEXTURE_2D);
	}
	else {
		std::cerr << "Failed to load texture" << std::endl;
	}

	stbi_image_free(data);
}

void Texture::Bind() {
	glBindTexture(GL_TEXTURE_2D, textureID);
}
