#include <mesh.h>
#include <iostream>
#include <string>

Mesh::Mesh(std::vector<Vertex>& vertices, std::vector<uint32_t>& elements) {
	initialize(vertices, elements);

}

Mesh::Mesh(std::vector<Vertex>& vertices, std::vector<uint32_t>& elements, const glm::vec3& color) {
	for (auto& vertex : vertices) {
		vertex.Color = color;
	}

	initialize(vertices, elements);
}

void Mesh::Draw() {
	// Bind VAO
	glBindVertexArray(VAO);

	// Draw triangles
	glDrawElements(GL_TRIANGLES, elementCount, GL_UNSIGNED_INT, nullptr);
}

void Mesh::initialize(std::vector<Vertex>& vertices, std::vector<uint32_t>& elements) {
	// Generate VAO for triangle
	glGenVertexArrays(1, &VAO);
	// Generate VBO for triangle
	glGenBuffers(1, &VBO);
	// Generate EBO for triangle
	glGenBuffers(1, &EBO);
	// Bind VAO
	glBindVertexArray(VAO);

	// Bind VBO and send data to GPU,
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, static_cast<GLsizeiptr>(vertices.size() * sizeof(Vertex)), vertices.data(), GL_STATIC_DRAW);

	// Bind EBO and send data to GPU
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, static_cast<GLsizeiptr>(elements.size() * sizeof(uint32_t)), elements.data(), GL_STATIC_DRAW);

	// Define vertex attributes
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, Position));
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, Color));
	glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, UV));
	glVertexAttribPointer(3, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, Normal));
	// Enable vertex pointers
	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);
	glEnableVertexAttribArray(2);
	glEnableVertexAttribArray(3);

	elementCount = elements.size();
}
