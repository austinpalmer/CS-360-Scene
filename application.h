#pragma once

#include <string>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <mesh.h>
#include <shader.h>
#include <camera.h>
#include <texture.h>

class Application {
public:
	Application(std::string WindowTitle, int width, int height);

	void Run();

private:
	// Vars
		// Window vars
	std::string applicationName{};
	int width{}, height{};
	GLFWwindow* window{ nullptr };
	bool running{ false };
	// Input handle vars
	bool firstMouse{ false };
	glm::vec2 lastMousePos{};
	glm::vec2 cameraLookSpeed{};
	float moveSpeed{ 5.0f };
	// Shader vars
	Shader shader;
	std::vector<Mesh> meshes;
	// Camera vars
	Camera camera;
	float lastFrameTime{ -1.0f };
	// Texture vars
	GLuint phoneHomeTexture, tableTexture;
	std::vector<Texture> textures;
	// Lighting vars
	float ambientStrength{ 0.1f };
	glm::vec3 ambientColor{ 1.0f, 1.0f, 1.0f };

// Methods
	bool openWindow(), update(float deltaTime), draw();
	void setupScene(), setupInputs();
	void handleInput(float deltaTime);
	void mousePosCallback(double xPos, double yPos);
};