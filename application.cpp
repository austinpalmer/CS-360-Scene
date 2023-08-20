#include "application.h"
#include "types.h"
#include "vector"
#include <iostream>
#include <string>
#include <glm/gtc/matrix_transform.hpp>
#include <stb_image.h>

// Application constructor
Application::Application(std::string WindowTitle, int width, int height) :
	applicationName{ WindowTitle },
	width{ width },
	height{ height },
	camera{ width, height, {0.0f, 1.0f, 3.0f}, true },
	cameraLookSpeed{ 0.15f, 1.0f } {}

// Run app
void Application::Run() {
	// Open window
	if (!openWindow()) {
		return;
	}

	// Setup inputs
	setupInputs();

	running = true;

	// Setup scene
	setupScene();

	// Run application
	while (running) {
		float currentTime = glfwGetTime();

		// Handle delta time to update frames
		if (lastFrameTime == -1.0f) {
			lastFrameTime = currentTime;
		}
		auto deltaTime = currentTime - lastFrameTime;
		lastFrameTime = currentTime;

		if (glfwWindowShouldClose(window)) {
			running = false;
			continue;
		}
		// Update
		update(deltaTime);
		// Draw
		draw();
	}

	glfwTerminate();
}

// Setup and open window
bool Application::openWindow() {
	// Initialize window
	glfwInit();
	// Tell compiler what version of OpenGL is compatiable
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	// Create window
	window = glfwCreateWindow(800, 600, "Austin Palmer", nullptr, nullptr);

	// If no window is created
	if (!window) {
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
	}

	gladLoadGL();
	glfwMakeContextCurrent(window);
	// Grab aspect ratio of window
	glfwSetWindowUserPointer(window, (void*)this);
	// Window resizing callback
	glfwSetFramebufferSizeCallback(window, [](GLFWwindow* window, int width, int height) {
		std::cout << "Resizing window" << std::endl;
		glViewport(0, 0, width, height);

		auto app = reinterpret_cast<Application*>(glfwGetWindowUserPointer(window));
		app->width = width;
		app->height = height;

		app->camera.SetSize(width, height);
	});

	// Display error if GLAD fails
	if (!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress)) {
		std::cerr << "Failed to initialize GLAD" << std::endl;
		glfwTerminate();
	}

	// Enable depth
	glEnable(GL_DEPTH_TEST);

	// Cull faces to observe triangle faces for lighting
	glFrontFace(GL_CCW);
	glCullFace(GL_BACK);
	glEnable(GL_CULL_FACE);

	return true;
}

// Set up shaders and object placement in scene
void Application::setupScene() {
	// Link textures
	//textures.emplace_back("phoneScreen.jpg");
	textures.emplace_back("LaptopScreen.jpg");

	// Phone mesh
	auto& mesh1 = meshes.emplace_back(PhoneObject::phoneVertices, PhoneObject::phoneElements);
	// Place phone above plane
	mesh1.Transform = glm::translate(mesh1.Transform, glm::vec3(-1.5f, 0.28f, 0.5f));
	// Plane mesh
	auto& mesh2 = meshes.emplace_back(PlaneObject::planeVertices, PlaneObject::planeElements);
	mesh2.Transform = glm::scale(mesh2.Transform, glm::vec3(0.5f, 0.5f, 0.5f));
	// Light mesh
	auto& mesh3 = meshes.emplace_back(CubeLight::cubeLightVertices, CubeLight::cubeLightElements);
	mesh3.Transform = glm::translate(mesh3.Transform, glm::vec3(0.0f, 2.0f, 4.5f));
	mesh3.Transform = glm::scale(mesh3.Transform, glm::vec3(0.5f, 0.5f, 0.5f));
	// Laptop mesh
	auto& mesh4 = meshes.emplace_back(LaptopBottom::laptopVertices, LaptopBottom::laptopElements);
	auto& mesh5 = meshes.emplace_back(LaptopScreen::laptopVertices, LaptopScreen::laptopElements);
	mesh4.Transform = glm::translate(mesh4.Transform, glm::vec3(0.0f, 0.05f, 0.0f));
	mesh5.Transform = glm::translate(mesh4.Transform, glm::vec3(0.0f, 0.20f, -1.0f));
	// Book mesh
	auto& mesh6 = meshes.emplace_back(BookCover::bookCoverVertices, BookCover::bookCoverElements);
	mesh6.Transform = glm::translate(mesh6.Transform, glm::vec3(-3.5f, 0.05f, 1.5f));
	auto& mesh7 = meshes.emplace_back(BookPages::bookPageVertices, BookPages::bookPagesElements);
	mesh7.Transform = glm::translate(mesh7.Transform, glm::vec3(-3.5f, 0.05f, 1.5f));
	// Pen mesh
	auto& mesh8 = meshes.emplace_back(PenTip::penTipVertices, PenTip::penTipElements);
	mesh8.Transform = glm::rotate(mesh8.Transform, 1.5708f, glm::vec3(1.0f, 0.0f, 0.0f));
	mesh8.Transform = glm::translate(mesh8.Transform, glm::vec3(4.0f, 1.0f, -0.1f));
	mesh8.Transform = glm::scale(mesh8.Transform, glm::vec3(0.5f, 0.5f, 0.5f));
	auto& mesh9 = meshes.emplace_back(PenBase::penBaseVertices, PenBase::penBaseElements);
	mesh9.Transform = glm::rotate(mesh9.Transform, 1.5708f, glm::vec3(1.0f, 0.0f, 0.0f));
	mesh9.Transform = glm::translate(mesh9.Transform, glm::vec3(4.0f, 0.0f, -0.1f));
	mesh9.Transform = glm::scale(mesh9.Transform, glm::vec3(0.5f, 0.5f, 0.5f));

	// Vertex shader Main
	std::string vertexShaderSource = R"(#version 330 core
	layout (location = 0) in vec3 position;
	layout (location = 1) in vec3 color;
	layout (location = 2) in vec2 uv;
	layout (location = 3) in vec3 normal;
	
	out vec4 vertexColor;
	out vec2 texCoord;
	uniform mat4 view;
	uniform mat4 projection;
	uniform mat4 model;

	void main() {
		gl_Position = projection * view * model * vec4(position, 1);
		vertexColor = vec4(color, 1.0f);
		texCoord = uv;
	}
	)";

	// Fragment shader Main
	std::string fragmentShaderSource = R"(#version 330 core
	out vec4 FragColor;
	in vec4 vertexColor;
	in vec2 texCoord;

	uniform sampler2D tex0; // GL_TEXTURE0
	uniform sampler2D tex1; // GL_TEXTURE1

	void main() {
		float ambientStrength = 0.9;
		vec3 ambientColor = vec3(1.0f, 1.0f, 1.0f);
		vec3 ambient = ambientStrength * ambientColor;
		vec2 constTest = vec2(0.5f, 0.5f);

		vec3 objectColor = vertexColor.xyz;
		vec3 finalColor = objectColor * ambient;

		if (texCoord == constTest) {
			FragColor = vec4(finalColor, 1.0);
		}
		else {
			FragColor = texture(tex0, texCoord) * vec4(finalColor, 1.0);
		}
	}
	)";

	// Light vertex shader
	std::string lightVertexShader = R"(#version 330 core
	layout (location = 0) in vec3 position;
	layout (location = 1) in vec3 color;
	layout (location = 2) in vec2 uv;
	layout (location = 3) in vec3 normal;
	
	out vec4 vertexColor;
	out vec2 texCoord;
	uniform mat4 view;
	uniform mat4 projection;
	uniform mat4 model;

	void main() {
		gl_Position = projection * view * model * vec4(position, 1);
		vertexColor = vec4(color, 1.0f);
		texCoord = uv;
	}
	)";

	// Light fragment shader
	std::string lightFragmentShader = R"(#version 330 core
	out vec4 FragColor;
	in vec4 vertexColor;
	in vec2 texCoord;

	uniform sampler2D tex0; // GL_TEXTURE0
	uniform sampler2D tex1; // GL_TEXTURE1

	void main() {
		float ambientStrength = 1.0;
		vec3 ambientColor = vec3(1.0f, 1.0f, 1.0f);
		vec3 ambient = ambientStrength * ambientColor;

		vec3 objectColor = vertexColor.xyz;
		vec3 finalColor = objectColor * ambient;

		FragColor = texture(tex0, texCoord) * vec4(finalColor, 1.0);
	}
	)";


	shader = Shader(vertexShaderSource, fragmentShaderSource);

}

// Setup and poll for input devices
void Application::setupInputs() {
	// Keyboard callback
	glfwSetKeyCallback(window, [](GLFWwindow* window, int key, int scancode, int action, int mods) {
		// Get reference to app
		auto* app = reinterpret_cast<Application*>(glfwGetWindowUserPointer(window));
		// Handle key input
		switch (key) {
			case GLFW_KEY_ESCAPE:
				if (action == GLFW_PRESS) {
					app->running = false;
				}
			case GLFW_KEY_P:
				if (action == GLFW_PRESS) {
					app->camera.SetIsPerspective(!app->camera.IsPerspective());
				}
				break;

			default: {}
		}
	});

	// Mouse cursor callback
	glfwSetCursorPosCallback(window, [](GLFWwindow* window, double xPos, double yPos) {
		auto* app = reinterpret_cast<Application*>(glfwGetWindowUserPointer(window));

		app->mousePosCallback(xPos, yPos);
	});
	

	// Scroll callback
	glfwSetScrollCallback(window, [](GLFWwindow* window, double xOffset, double yOffset) {
		auto* app = reinterpret_cast<Application*>(glfwGetWindowUserPointer(window));

		app->camera.IncrementZoom(yOffset * 2);
	});

	// Button callback
	glfwSetMouseButtonCallback(window, [](GLFWwindow* window, int button, int action, int mods) {
		switch (button) {
			case GLFW_MOUSE_BUTTON_LEFT:
				if (action == GLFW_PRESS) {

				}
				break;
			case GLFW_MOUSE_BUTTON_MIDDLE:
				if (action == GLFW_PRESS) {

				}
				break;
			case GLFW_MOUSE_BUTTON_RIGHT:
				if (action == GLFW_PRESS) {

				}
				break;
			default:
				std::cout << "Unhandled mouse button" << std::endl;
		}
	});
}

// Move camera based on input
void Application::handleInput(float deltaTime) {
	// Regulate move speed
	auto moveAmount = moveSpeed * deltaTime;
	// Move forward
	if (glfwGetKey(window, GLFW_KEY_W)) {
		camera.MoveCamera(Camera::MoveDirection::Forward, moveAmount);
	}
	// Move backward
	if (glfwGetKey(window, GLFW_KEY_S)) {
		camera.MoveCamera(Camera::MoveDirection::Backward, moveAmount);
	}
	// Move left
	if (glfwGetKey(window, GLFW_KEY_A)) {
		camera.MoveCamera(Camera::MoveDirection::Left, moveAmount);
	}
	// Move Right
	if (glfwGetKey(window, GLFW_KEY_D)) {
		camera.MoveCamera(Camera::MoveDirection::Right, moveAmount);
	}
	// Move up
	if (glfwGetKey(window, GLFW_KEY_Q)) {
		camera.MoveCamera(Camera::MoveDirection::Up, moveAmount);
	}
	if (glfwGetKey(window, GLFW_KEY_E)) {
		camera.MoveCamera(Camera::MoveDirection::Down, moveAmount);
	}
}

// Rotate position upon mouse movement
void Application::mousePosCallback(double xPos, double yPos) {
	if (!firstMouse) {
		lastMousePos.x = static_cast<float>(xPos);
		lastMousePos.y = static_cast<float>(yPos);
		firstMouse = true;
	}

	// Calculate mouse offset
	glm::vec2 moveAmount{
		xPos - lastMousePos.x,
		lastMousePos.y - yPos,
	};

	lastMousePos.x = static_cast<float>(xPos);
	lastMousePos.y = static_cast<float>(yPos);

	// Rotate camera
	camera.RotateBy(moveAmount.x * cameraLookSpeed.x, moveAmount.y * cameraLookSpeed.y);
}

// Update scene and poll inptus
bool Application::update(float deltaTime) {
	// Poll keyboard, mouse, window events
	glfwPollEvents();

	handleInput(deltaTime);

	return false;
}

// Generate matrices and draw scene
bool Application::draw() {
	// Clear screen of color
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// Camera
	// View matrix	
	glm::mat4 view = camera.GetViewMatrix();
	// Projection matrix					
	glm::mat4 projection = camera.GetProjectionMatrix();

	// Bind shader
	shader.Bind();
	// Set matrices
	shader.SetMat4("projection", projection);
	shader.SetMat4("view", view);
	// Set texture locations
	shader.SetInt("tex0", 0);
	shader.SetInt("tex1", 1);

	// Bind texture
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, tableTexture);

	for (auto i = 0; i < textures.size(); i++) {
		glActiveTexture(GL_TEXTURE0 + i);
		textures[i].Bind();
	}

	// Find all meshes and draw
	for (auto mesh : meshes) {
		shader.SetMat4("model", mesh.Transform);
		mesh.Draw();
	}

	// Take back buffer with objects
	glfwSwapBuffers(window);

	return false;
}

