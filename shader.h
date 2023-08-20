#pragma once
#include <filesystem>
#include <string>
#include <glad/glad.h>
#include <glm/glm.hpp>

using Path = std::filesystem::path;

class Shader {
public:
	Shader() = default;
	Shader(const std::string& vertexSource, const std::string& fragmentSource);

	void Bind();
	void SetMat4(const std::string& uniformName, const glm::mat4& mat4);
	void SetInt(const std::string& uniformName, int value);

private:
	// Vars
	GLuint shaderProgram;
	// Methods
	void load(const std::string& vertexSource, const std::string& fragmentSource);
	GLuint getUniformLocation(const std::string& uniformName);


};