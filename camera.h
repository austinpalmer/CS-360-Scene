#pragma once

#include <glm/glm.hpp>

class Camera {

public:
	explicit Camera(int width, int height, glm::vec3 initialPos = glm::vec3{ 0, 0, -20.0f }, bool isPerspective = true);

	enum class MoveDirection {
		Forward,
		Backward,
		Left,
		Right,
		Up,
		Down
	};

	glm::mat4 GetViewMatrix();
	glm::mat4 GetProjectionMatrix();

	//void SetAspectRatio(float aspectRatio) { this->aspectRatio = aspectRatio; }
	bool IsPerspective() const { return isPerspective; }
	void SetIsPerspective(bool isPerspective) { this->isPerspective = isPerspective; }
	void SetSize(int width, int height) {
		this->width = width, this->height = height;
	}

	void MoveCamera(MoveDirection direction, float moveAmount);
	void RotateBy(float yaw, float pitch);
	void IncrementZoom(float amount);

private:
	// Set size of view
	int width{ 0 }, height{ 0 };
	// Cursor movement vars
	float yaw{ -90.0f }, pitch{};
	// View matrix vars
	glm::vec3 position{}, lookDirection{}, initialPos{}, upDirection{0.0f, 1.0f, 0.0f};
	// Projection matrix vars
	float fieldOfView{ 75.0f };
	// aspectRatio{ 0.0f };
	// Change perspective type
	bool isPerspective{ true };
	// Clipping vars
	float nearClip{ 0.1f }, farClip{ 100.0f };

	void recalculateVectors();
};