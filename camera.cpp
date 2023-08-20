#include "camera.h"
#include <glm/gtc/matrix_transform.hpp>
#include <algorithm>

// Create the camera for the scene and intialize perspecitve and look positions
Camera::Camera(int width, int height, glm::vec3 initialPos, bool isPerspective) :
	width{ width },
	height{ height },
	isPerspective{ isPerspective },
	position{ initialPos },
	lookDirection{ 0.0f, 0.0f, 1.0f } {
	
	recalculateVectors();
}

// Set the camera where to look and rotate objects in camera space
glm::mat4 Camera::GetViewMatrix() {
	return glm::lookAt(position, position + lookDirection, upDirection);
}

// Transform all vertex data from view matrix to clip space
glm::mat4 Camera::GetProjectionMatrix() {
	auto aspectRatio = (float)width / float(height);
	// If true, return perspective matrix
	if (isPerspective) {
		return glm::perspective(glm::radians(fieldOfView), aspectRatio, nearClip, farClip);
	}
	// Else, return orthographic matrix
	return glm::ortho(-aspectRatio, aspectRatio, -1.0f, 1.0f, nearClip, farClip);
}

// Move camera around using camera positions and cross vectors
void Camera::MoveCamera(MoveDirection direction, float moveAmount) {
	glm::vec3 moveDirection{};
	// Handle direction
	switch (direction) {
		case MoveDirection::Forward:
			moveDirection = lookDirection;
			break;
		case MoveDirection::Backward:
			moveDirection = -lookDirection;
			break;
		case MoveDirection::Left:
			// Use cross product of up direction and look direction
			moveDirection = -glm::normalize(glm::cross(lookDirection, upDirection));
			break;
		case MoveDirection::Right:
			// Use cross product of up direction and look direction
			moveDirection = glm::normalize(glm::cross(lookDirection, upDirection));
			break;
		case MoveDirection::Up:
			moveDirection = upDirection;
			break;
		case MoveDirection::Down:
			moveDirection = -upDirection;
	}
	// Pick direction and amount to move for camera (vector math)
	position += moveDirection * moveAmount;
}

// Rotate camera around using mouse movements
void Camera::RotateBy(float yaw, float pitch) {
	this->yaw += yaw;
	this->pitch += pitch;

	// If below/above constraints, defaults it to min/max (from algorithm lib)
	this->pitch = std::clamp(pitch, -180.0f, 180.0f);
	
	// Recalculate vectors after rotation
	recalculateVectors();
}

void Camera::IncrementZoom(float amount) {
	fieldOfView -= amount;

	fieldOfView = std::clamp(fieldOfView, 1.0f, 75.0f);
}

// Recalculate vectors using vector trig (the new angle after rotation)
void Camera::recalculateVectors() {
	lookDirection = glm::normalize(glm::vec3{
		std::cos(glm::radians(yaw)) * std::cos(glm::radians(pitch)),
		std::sin(glm::radians(pitch)),
		std::sin(glm::radians(yaw)) * std::cos(glm::radians(pitch))
	});
	// Get right vector from cross product of lookDirection and worldUp
	glm::vec3 rightDirection = glm::normalize(glm::cross(lookDirection, glm::vec3(0.0f, 1.0f, 0.0f)));
	// Calculate new up direction from perpendicular rightdirection and new lookDirection
	upDirection = glm::normalize(glm::cross(rightDirection, lookDirection));
}
