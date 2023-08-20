#include "shader.h"
#include <iostream>
#include <glm/gtc/type_ptr.hpp>

// Default shader load
Shader::Shader(const std::string& vertexSource, const std::string& fragmentSource) {
	load(vertexSource, fragmentSource);
}

/* Load shader from file path
Shader::Shader(Path vertexPath, Path fragmentPath) {
	// File sources
	std::string vertexSource, fragmentSource;

	// Load shader
	load(vertexSource, fragmentSource);
}
*/

void Shader::Bind() {
	// Bind shader program
	glUseProgram(shaderProgram);
}

void Shader::load(const std::string& vertexSource, const std::string& fragmentSource){
	const char* vShaderCode = vertexSource.c_str();
	const char* fShaderCode = fragmentSource.c_str();
	// Create vertex shader
	auto vertexShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexShader, 1, &vShaderCode, nullptr);
	// Compile vertex shader
	glCompileShader(vertexShader);

	// Check if vertex shader compilation was successful
	int success;
	char infoLog[512];
	glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);

	if (!success) {
		glGetShaderInfoLog(vertexShader, 512, nullptr, infoLog);
		std::cerr << "Failed to compile vertex shader\n" << infoLog << std::endl;
	}

	// Create fragment shader
	auto fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShader, 1, &fShaderCode, nullptr);
	// Compile fragment shader
	glCompileShader(fragmentShader);

	// Check if fragment shader compilation was successful
	glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);

	if (!success) {
		glGetShaderInfoLog(fragmentShader, 512, nullptr, infoLog);
		std::cerr << "Failed to compile fragment shader\n" << infoLog << std::endl;
	}

	// Create shader program
	shaderProgram = glCreateProgram();
	// Attach shaders to program
	glAttachShader(shaderProgram, vertexShader);
	glAttachShader(shaderProgram, fragmentShader);
	glLinkProgram(shaderProgram);

	// Check if linking the shader program was successful
	glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);

	if (!success) {
		glGetShaderInfoLog(shaderProgram, 512, nullptr, infoLog);
		std::cerr << "Failed to link shader porgram\n" << infoLog << std::endl;
	}

	// Delete shaders after attached to free up memory
	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);
}

GLuint Shader::getUniformLocation(const std::string& uniformName){
	return glGetUniformLocation(shaderProgram, uniformName.c_str());
}

// Set uniform for view/projection/model matrices
void Shader::SetMat4(const std::string& uniformName, const glm::mat4& mat4) {
	// Set uniform location
	auto uniformLocation = getUniformLocation(uniformName);

	// If no error getting uniform location
	if (uniformLocation != -1) {
		// Check program still active
		glUniformMatrix4fv(uniformLocation, 1, GL_FALSE, glm::value_ptr(mat4));
	}
}

// Set texture location
void Shader::SetInt(const std::string& uniformName, int value) {
	// Set uniform location
	auto uniformLocation = getUniformLocation(uniformName);

	// If no error getting uniform location
	if (uniformLocation != -1) {
		// Check program still active
		glUniform1i(uniformLocation, value);
	}
}
