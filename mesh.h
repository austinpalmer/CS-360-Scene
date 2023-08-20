#pragma once
#include <vector>
#include <types.h>
#include <glad/glad.h>

class Mesh {
public:
	Mesh(std::vector<Vertex>& vertices, std::vector<uint32_t>& elements);
	Mesh(std::vector<Vertex>& vertices, std::vector<uint32_t>& elements, const glm::vec3& color);
	void Draw();
	glm::mat4 Transform{ 1.0f };

private:
	// Vars
	GLuint VBO{}, VAO{}, EBO{}, shaderProgram{};
	uint32_t elementCount{ 0 };
	// Methods
	void initialize(std::vector <Vertex>& vertices, std::vector<uint32_t>& elements);
};