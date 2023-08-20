#pragma once
#include <glm/glm.hpp>

/*
	Structure of vertices
*/
struct Vertex {
	glm::vec3 Position{ 0.0f, 0.0f, 0.0f };
	glm::vec3 Color{ 1.0f, 1.0f, 1.0f };
	glm::vec2 UV{ 1.0f, 1.0f };
	glm::vec3 Normal{ 0.0f, 0.0f, 0.0f };
};

/*
	Structure of Phone Object
*/
struct PhoneObject {
	static inline std::vector<Vertex> phoneVertices{
	// Front face (bottom of phone)
		// bottom left point
		{
			.Position = {-0.25f, 0.0f, 0.5f},
			.Color = {1.0f, 0.0f, 0.0f}
		},
		// bottom right point
		{
			.Position = {0.25f, 0.0f, 0.5f},
			.Color = {1.0f, 0.0f, 0.0f}
		},
		// top right point
		{
			.Position = {0.25f, 0.10f, 0.5f},
			.Color = {1.0f, 0.0f, 0.0f}
		},
		// top left point
		{
			.Position = {-0.25f, 0.10f, 0.5f},
			.Color = {1.0f, 0.0f, 0.0f}
		},
	// Right face (right side of phone)
		// bottom left point
		{
			.Position = {0.25f, 0.0f, 0.5f},
			.Color = {1.0f, 0.0f, 0.0f}
		},
		// bottom right point
		{
			.Position = {0.25f, 0.0f, -0.5f},
			.Color = {1.0f, 0.0f, 0.0f}
		},
		// top right point
		{
			.Position = {0.25f, 0.10f, -0.5f},
			.Color = {1.0f, 0.0f, 0.0f}
		},
		// top left point
		{
			.Position = {0.25f, 0.10f, 0.5f},
			.Color = {1.0f, 0.0f, 0.0f}
		},
	// Back face (top of phone)
		// bottom left point
		{
			.Position = {0.25f, 0.0f, -0.5f},
			.Color = {1.0f, 0.0f, 0.0f}
		},
		// bottom right point
		{
			.Position = {-0.25f, 0.0f, -0.5f},
			.Color = {1.0f, 0.0f, 0.0f}
		},
		// top right point
		{
			.Position = {-0.25f, 0.10f, -0.5f},
			.Color = {1.0f, 0.0f, 0.0f}
		},
		// top left point
		{
			.Position = {0.25f, 0.10f, -0.5f},
			.Color = {1.0f, 0.0f, 0.0f}
		},
	// Left face (left side of phone)
		// bottom left point
		{
			.Position = {-0.25f, 0.0f, -0.5f},
			.Color = {1.0f, 0.0f, 0.0f}
		},
		// bottom right point
		{
			.Position = {-0.25f, 0.0f, 0.5f},
			.Color = {1.0f, 0.0f, 0.0f}
		},
		// top right point
		{
			.Position = {-0.25f, 0.10f, 0.5f},
			.Color = {1.0f, 0.0f, 0.0f}
		},
		// top left point
		{
			.Position = {-0.25f, 0.10f, -0.5f},
			.Color = {1.0f, 0.0f, 0.0f}
		},
	// Top face (front of phone)
		// bottom left point
		{
			.Position = {-0.25f, 0.10f, 0.5f},
			.Color = {1.0f, 0.0f, 0.0f}
		},
		// bottom right point
		{
			.Position = {0.25f, 0.10f, 0.5f},
			.Color = {1.0f, 0.0f, 0.0f}
		},
		// top right point
		{
			.Position = {0.25f, 0.10f, -0.5f},
			.Color = {1.0f, 0.0f, 0.0f}
		},
		// top left point
		{
			.Position = {-0.25f, 0.10f, -0.5f},
			.Color = {1.0f, 0.0f, 0.0f}
		},
	// Bottom face (Back of phone)
		// Bottom left point
		{
			.Position = { -0.25f, 0.0f, 0.5f },
			.Color = {1.0f, 0.0f, 0.0f}
		},
		// bottom right point
		{
			.Position = {0.25f, 0.0f, 0.5f},
			.Color = {1.0f, 0.0f, 0.0f}
		},
		// top right point
		{
			.Position = {0.25f, 0.0f, -0.5f},
			.Color = {1.0f, 0.0f, 0.0f}
		},
		// top left point
		{
			.Position = {-0.25f, 0.0f, -0.5f},
			.Color = {1.0f, 0.0f, 0.0f}
		},
	// Screen of phone
		// Bottom left point
		{
			.Position = {-0.2f, 0.13f, 0.35f},
			.Color = {0.0f, 0.0f, 0.0f},
			.UV = {0.0f, 0.0f}
		},
		// bottom right point
		{
			.Position = {0.2f, 0.13f, 0.35f},
			.Color = {0.0f, 0.0f, 0.0f},
			.UV = {1.0f, 0.0f}
		},
		// top right point
		{
			.Position = {0.2f, 0.13f, -0.35f},
			.Color = {0.0f, 0.0f, 0.0f},
			.UV = {1.0f, 1.0f}
		},
		// top left point
		{
			.Position = {-0.2f, 0.13f, -0.35f},
			.Color = {0.0f, 0.0f, 0.0f},
			.UV = {0.0f, 1.0f}
		},
	};

	static inline std::vector<uint32_t> phoneElements {
		0, 1, 3, 1, 2, 3, // Front face
		4, 5, 7, 5, 6, 7, // Right face
		8, 9, 11, 9, 10, 11, // Back face
		12, 13, 15, 13, 14, 15, // Left face
		16, 17, 19, 17, 18, 19, // Top face
		20, 21, 23, 21, 22, 23, // Bottom face
		24, 25, 27, 25, 26, 27	// Screen
	};
};

/*
	Structure of Plane Object
*/
struct PlaneObject {
	static inline std::vector<Vertex> planeVertices{
		// front left point
		{
			.Position = {-10.0f, 0.0f, 5.0f},
			.Color = {0.90f, 0.90f, 0.90f},
			.UV = {0.5f, 0.5f}
		},
		// front right point
		{
			.Position = {10.0f, 0.0f, 5.0f},
			.Color = {0.90f, 0.90f, 0.90f},
			.UV = {0.5f, 0.5f}
		},
		// back right point
		{
			.Position = {10.0f, 0.0f, -5.0f},
			.Color = {0.90f, 0.90f, 0.90f},
			.UV = {0.5f, 0.5f}
		},
		// back left point
		{
			.Position = {-10.0f, 0.0f, -5.0f},
			.Color = {0.90f, 0.90f, 0.90f},
			.UV = {0.5f, 0.5f}
		},
	};

	static inline std::vector<uint32_t> planeElements{
		0, 1, 3, // Bottom triangle
		1, 2, 3, // Top triangle
	};
};

/*
	Structure of Pyramid object
*/
struct PyramidObject {
	static inline std::vector<Vertex> pyramidVertices {
	// Front face
		// Bottom left point, front face
		{
			.Position = {-0.5f, 0.0f, 0.5f},
			.Color = {1.0f, 0.4f, 0.8f},
			.UV = {0.0f, 0.0f}
		},
		// Bottom right point, front face
		{
			.Position = {0.5f, 0.0f, 0.5f},
			.Color = {1.0f, 1.0f, 0.2f},
			.UV = {1.0f, 0.0f}
		},
		// Top of pyramid
		{
			.Position = {0.0f, 1.0f, 0.0f},
			.Color = {1.0f, 1.0f, 1.0f},
			.UV = {0.5f, 1.0f}
		},
	// Right face
		// Bottom left point, right face
		{
			.Position = {0.5f, 0.0f, 0.5f},
			.Color = {1.0f, 1.0f, 0.2f},
			.UV = {0.0f, 0.0f}
		},
		// Bottom right point, right face
		{
			.Position = {0.5f, 0.0f, -0.5f},
			.Color = {0.4f, 0.1f, 0.9f},
			.UV = {1.0f, 0.0f}
		},
		// Top of pyramid
		{
			.Position = {0.0f, 1.0f, 0.0f},
			.Color = {1.0f, 1.0f, 1.0f},
			.UV = {0.5f, 1.0f}
		},
	// Back face
		// Bottom left point, back face
		{
			.Position = {0.5f, 0.0f, -0.5f},
			.Color = {0.4f, 0.1f, 0.9f},
			.UV = {0.0f, 0.0f}
		},
		// Bottom right point, back face
		{
			.Position = {-0.5f, 0.0f, -0.5f},
			.Color = {0.5f, 1.0f, 1.0f},
			.UV = {1.0f, 0.0f}
		},
		// Top of pyramid
		{
			.Position = {0.0f, 1.0f, 0.0f},
			.Color = {1.0f, 1.0f, 1.0f},
			.UV = {0.5f, 1.0f}
		},
	// Left face
		// Bottom left point, left face
		{
			.Position = {-0.5f, 0.0f, -0.5f},
			.Color = {0.5f, 1.0f, 1.0f},
			.UV = {0.0f, 0.0f}
		},
		// Bottom right point, left face
		{
			.Position = {-0.5f, 0.0f, 0.5f},
			.Color = {0.5f, 1.0f, 1.0f},
			.UV = {1.0f, 0.0f}
		},
		// Top of pyramid
		{
			.Position = {0.0f, 1.0f, 0.0f},
			.Color = {1.0f, 1.0f, 1.0f},
			.UV = {0.5f, 1.0f}
		},
	// Bottom face
		// Front Left point
		{
			.Position = {-0.5f, 0.0f, 0.5f},
			.Color = {1.0f, 0.4f, 0.8f},
			.UV = {0.0f, 0.0f}
		},
		// Front Right point
		{
			.Position = {0.5f, 0.0f, 0.5f},
			.Color = {1.0f, 1.0f, 0.2f},
			.UV = {1.0f, 0.0f}
		},
		// Back right point 
		{
			.Position = {0.5f, 0.0f, -0.5f},
			.Color = {0.4f, 0.1f, 0.9f},
			.UV = {1.0f, 1.0f}
		},
		// Back Left point
		{
			.Position = {-0.5f, 0.0f, -0.5f},
			.Color = {0.5f, 1.0f, 1.0f},
			.UV = {0.0f, 1.0f}
		},
	};

	static inline std::vector<uint32_t> pyramidElements {
		0, 1, 2, // front face
		3, 4, 5, // right face
		6, 7, 8, // back face
		9, 10, 11, // left face
		12, 13, 15, // bottom face bottom triangle
		13, 14, 15 // bottom face top triangle
	};
};

struct CubeLight {
	static inline std::vector<Vertex> cubeLightVertices {
	// Front face
		// Front face bottom left point
		{
			.Position = {-0.5f, 0.0f, 0.0f},
			.Color = {1.0f, 1.0f, 1.0f},
			.UV = {0.5f, 0.5f}
		},
		// Front face bottom right point
		{
			.Position = {0.0f, 0.0f, 0.0f},
			.Color = {1.0f, 1.0f, 1.0f},
			.UV = {0.5f, 0.5f}
		},
		// Front face top right point
		{
			.Position = {0.0f, 0.5f, 0.0f},
			.Color = {1.0f, 1.0f, 1.0f},
			.UV = {0.5f, 0.5f}
		},
		// Front face top left point
		{
			.Position = {-0.5f, 0.5f, 0.0f},
			.Color = {1.0f, 1.0f, 1.0f},
			.UV = {0.5f, 0.5f}
		},
	// Right face
		// Right face bottom left point
		{
			.Position = {0.0f, 0.0f, 0.0f},
			.Color = {1.0f, 1.0f, 1.0f},
			.UV = {0.5f, 0.5f}
		},
		// Right face bottom right point
		{
			.Position = {0.0f, 0.0f, 0.5f},
			.Color = {1.0f, 1.0f, 1.0f},
			.UV = {0.5f, 0.5f}
		},
		// Right face top right point
		{
			.Position = {0.0f, 0.5f, 0.5f},
			.Color = {1.0f, 1.0f, 1.0f},
			.UV = {0.5f, 0.5f}
		},
		// Right face top left point
		{
			.Position = {0.0f, 0.5f, 0.0f},
			.Color = {1.0f, 1.0f, 1.0f},
			.UV = {0.5f, 0.5f}
		},
	// Back face
		// Back face bottom left point
		{
			.Position = {0.0f, 0.0f, 0.5f},
			.Color = {1.0f, 1.0f, 1.0f},
			.UV = {0.5f, 0.5f}
		},
		// Back face bottom right point
		{
			.Position = {-0.5f, 0.0f, 0.5f},
			.Color = {1.0f, 1.0f, 1.0f},
			.UV = {0.5f, 0.5f}
		},
		// Back face top right point
		{
			.Position = {-0.5f, 0.5f, 0.5f},
			.Color = {1.0f, 1.0f, 1.0f},
			.UV = {0.5f, 0.5f}
		},
		// Back face top left point
		{
			.Position = {0.0f, 0.5f, 0.5f},
			.Color = {1.0f, 1.0f, 1.0f},
			.UV = {0.5f, 0.5f}
		},
	// Left face
		// Left face bottom left point
		{
			.Position = {-0.5f, 0.0f, 0.5f},
			.Color = {1.0f, 1.0f, 1.0f},
			.UV = {0.5f, 0.5f}
		},
		// Left face bottom right point
		{
			.Position = {-0.5f, 0.0f, 0.0f},
			.Color = {1.0f, 1.0f, 1.0f},
			.UV = {0.5f, 0.5f}
		},
		// Left face top right point
		{
			.Position = {-0.5f, 0.5f, 0.0f},
			.Color = {1.0f, 1.0f, 1.0f},
			.UV = {0.5f, 0.5f}
		},
		// Left face top left point
		{
			.Position = {-0.5f, 0.5f, 0.5f},
			.Color = {1.0f, 1.0f, 1.0f},
			.UV = {0.5f, 0.5f}
		},
	// Top face
		// Top face front left point
		{
			.Position = {-0.5f, 0.5f, 0.0f},
			.Color = {1.0f, 1.0f, 1.0f},
			.UV = {0.5f, 0.5f}
		},
		// Top face front right point
		{
			.Position = {0.0f, 0.5f, 0.0f},
			.Color = {1.0f, 1.0f, 1.0f},
			.UV = {0.5f, 0.5f}
		},
		// Top face back right point
		{
			.Position = {0.0f, 0.5f, 0.5f},
			.Color = {1.0f, 1.0f, 1.0f},
			.UV = {0.5f, 0.5f}
		},
		// Top face back left point
		{
			.Position = {-0.5f, 0.5f, 0.5f},
			.Color = {1.0f, 1.0f, 1.0f},
			.UV = {0.5f, 0.5f}
		},
	// Bottom face
		// Bottom face front left point
		{
			.Position = {-0.5f, 0.0f, 0.0f},
			.Color = {1.0f, 1.0f, 1.0f},
			.UV = {0.5f, 0.5f}
		},
		// Bottom face front right point
		{
			.Position = {0.0f, 0.0f, 0.0f},
			.Color = {1.0f, 1.0f, 1.0f},
			.UV = {0.5f, 0.5f}
		},
		// Bottom face back right point
		{
			.Position = {0.0f, 0.0f, 0.5f},
			.Color = {1.0f, 1.0f, 1.0f},
			.UV = {0.5f, 0.5f}
		},
		// Bottom face back left point
		{
			.Position = {-0.5f, 0.0f, 0.5f},
			.Color = {1.0f, 1.0f, 1.0f},
			.UV = {0.5f, 0.5f}
		},
	};
	static inline std::vector<uint32_t> cubeLightElements {
		0, 1, 3, 1, 2, 3, // Front face
		4, 5, 7, 5, 6, 7, // Right face
		8, 9, 11, 9, 10, 11, // Back face
		12, 13, 15, 13, 14, 15, // Left face
		16, 17, 19, 17, 18, 19, // Top face
		20, 21, 23, 21, 22, 23, // Bottom face
	};
};

struct LaptopBottom {
	static inline std::vector<Vertex> laptopVertices {
	// Front face of keyboard
		// Front face bottom left point
		{
			.Position = {-2.0f, 0.0f, 1.0f},
			.Color = {0.45f, 0.45f, 0.45f},
			.UV = {0.5f, 0.5f}
		},
		// Front face bottom right point
		{
			.Position = {2.0f, 0.0f, 1.0f},
			.Color = {0.45f, 0.45f, 0.45f},
			.UV = {0.5f, 0.5f}
		},
		// Front face top right point
		{
			.Position = {2.0f, 0.25f, 1.0f},
			.Color = {0.45f, 0.45f, 0.45f},
			.UV = {0.5f, 0.5f}
		},
		// Front face top left point
		{
			.Position = {-2.0f, 0.25f, 1.0f},
			.Color = {0.45f, 0.45f, 0.45f},
			.UV = {0.5f, 0.5f}
		},
	// Right face
		// Bottom left point
		{
			.Position = {2.0f, 0.0f, 1.0f},
			.Color = {0.45f, 0.45f, 0.45f},
			.UV = {0.5f, 0.5f}
		},
		// Bottom right point
		{
			.Position = {2.0f, 0.0f, -1.0f},
			.Color = {0.45f, 0.45f, 0.45f},
			.UV = {0.5f, 0.5f}
		},
		// Top right point
		{
			.Position = {2.0f, 0.25f, -1.0f},
			.Color = {0.45f, 0.45f, 0.45f},
			.UV = {0.5f, 0.5f}
		},
		// Top left point
		{
			.Position = {2.0f, 0.25f, 1.0f},
			.Color = {0.45f, 0.45f, 0.45f},
			.UV = {0.5f, 0.5f}
		},
	// Back face
		// Bottom left point
		{
			.Position = {2.0f, 0.0f, -1.0f},
			.Color = {0.45f, 0.45f, 0.45f},
			.UV = {0.5f, 0.5f}
		},
		// Bottom right point
		{
			.Position = {-2.0f, 0.0f, -1.0f},
			.Color = {0.45f, 0.45f, 0.45f},
			.UV = {0.5f, 0.5f}
		},
		// Top right point
		{
			.Position = {-2.0f, 0.25f, -1.0f},
			.Color = {0.45f, 0.45f, 0.45f},
			.UV = {0.5f, 0.5f}
		},
		// Top left point
		{
			.Position = {2.0f, 0.25f, -1.0f},
			.Color = {0.45f, 0.45f, 0.45f},
			.UV = {0.5f, 0.5f}
		},
	// Left face
		// Bottom left point
		{
			.Position = {-2.0f, 0.0f, -1.0f},
			.Color = {0.45f, 0.45f, 0.45f},
			.UV = {0.5f, 0.5f}
		},
		// Bottom right point
		{
			.Position = {-2.0f, 0.0f, 1.0f},
			.Color = {0.45f, 0.45f, 0.45f},
			.UV = {0.5f, 0.5f}
		},
		// Top right point
		{
			.Position = {-2.0f, 0.25f, 1.0f},
			.Color = {0.45f, 0.45f, 0.45f},
			.UV = {0.5f, 0.5f}
		},
		// Top left point
		{
			.Position = {-2.0f, 0.25f, -1.0f},
			.Color = {0.45f, 0.45f, 0.45f},
			.UV = {0.5f, 0.5f}
		},
	// Bottom face
		// Bottom left point
		{
			.Position = {-2.0f, 0.0f, 1.0f},
			.Color = {0.45f, 0.45f, 0.45f},
			.UV = {0.5f, 0.5f}
		},
		// Bottom right point
		{
			.Position = {2.0f, 0.0f, 1.0f},
			.Color = {0.45f, 0.45f, 0.45f},
			.UV = {0.5f, 0.5f}
		},
		// Top right point
		{
			.Position = {2.0f, 0.0f, -1.0f},
			.Color = {0.45f, 0.45f, 0.45f},
			.UV = {0.5f, 0.5f}
		},
		// Top left point
		{
			.Position = {-2.0f, 0.0f, -1.0f},
			.Color = {0.45f, 0.45f, 0.45f},
			.UV = {0.5f, 0.5f}
		},
	// Top face
		// Bottom left point
		{
			.Position = {-2.0f, 0.25f, 1.0f},
			.Color = {0.45f, 0.45f, 0.45f},
			.UV = {0.5f, 0.5f}
		},
		// Bottom right point
		{
			.Position = {2.0f, 0.25f, 1.0f},
			.Color = {0.45f, 0.45f, 0.45f},
			.UV = {0.5f, 0.5f}
		},
		// Top right point
		{
			.Position = {2.0f, 0.25f, -1.0f},
			.Color = {0.45f, 0.45f, 0.45f},
			.UV = {0.5f, 0.5f}
		},
		// Top left point
		{
			.Position = {-2.0f, 0.25f, -1.0f},
			.Color = {0.45f, 0.45f, 0.45f},
			.UV = {0.5f, 0.5f}
		},
	};
	static inline std::vector<uint32_t> laptopElements{
		0, 1, 3, 1, 2, 3, // Front face
		4, 5, 7, 5, 6, 7, // Right face
		8, 9, 11, 9, 10, 11, // Back face
		12, 13, 15, 13, 14, 15, // Left face
		16, 17, 19, 17, 18, 19, // Top face
		20, 21, 23, 21, 22, 23, // Bottom face
	};
};

struct LaptopScreen {
	static inline std::vector<Vertex> laptopVertices{
	// Front face of keyboard
		// Front face bottom left point
		{
			.Position = {-2.0f, 0.0f, 0.1f},
			.Color = {1.0f, 1.0f, 1.0f},
			.UV = {0.0f, 0.0f}
		},
		// Front face bottom right point
		{
			.Position = {2.0f, 0.0f, 0.1f},
			.Color = {1.0f, 1.0f, 1.0f},
			.UV = {1.0f, 0.0f}
		},
		// Front face top right point
		{
			.Position = {2.0f, 2.0f, 0.1f},
			.Color = {1.0f, 1.0f, 1.0f},
			.UV = {1.0f, 1.0f}
		},
		// Front face top left point
		{
			.Position = {-2.0f, 2.0f, 0.1f},
			.Color = {1.0f, 1.0f, 1.0f},
			.UV = {0.0f, 1.0f}
		},
	// Right face
		// Bottom left point
		{
			.Position = {2.0f, 0.0f, 0.1f},
			.Color = {0.0f, 0.0f, 0.0f},
			.UV = {0.5f, 0.5f}
		},
		// Bottom right point
		{
			.Position = {2.0f, 0.0f, -0.1f},
			.Color = {0.0f, 0.0f, 0.0f},
			.UV = {0.5f, 0.5f}
		},
		// Top right point
		{
			.Position = {2.0f, 2.0f, -0.1f},
			.Color = {0.0f, 0.0f, 0.0f},
			.UV = {0.5f, 0.5f}
		},
		// Top left point
		{
			.Position = {2.0f, 2.0f, 0.1f},
			.Color = {0.0f, 0.0f, 0.0f},
			.UV = {0.5f, 0.5f}
		},
	// Back face
		// Bottom left point
		{
			.Position = {2.0f, 0.0f, -0.1f},
			.Color = {0.45f, 0.45f, 0.45f},
			.UV = {0.5f, 0.5f}
		},
		// Bottom right point
		{
			.Position = {-2.0f, 0.0f, -0.1f},
			.Color = {0.45f, 0.45f, 0.45f},
			.UV = {0.5f, 0.5f}
		},
		// Top right point
		{
			.Position = {-2.0f, 2.0f, -0.1f},
			.Color = {0.45f, 0.45f, 0.45f},
			.UV = {0.5f, 0.5f}
		},
		// Top left point
		{
			.Position = {2.0f, 2.0f, -0.1f},
			.Color = {0.45f, 0.45f, 0.45f},
			.UV = {0.5f, 0.5f}
		},
	// Left face
		// Bottom left point
		{
			.Position = {-2.0f, 0.0f, -0.1f},
			.Color = {0.0f, 0.0f, 0.0f},
			.UV = {0.5f, 0.5f}
		},
		// Bottom right point
		{
			.Position = {-2.0f, 0.0f, 0.1f},
			.Color = {0.0f, 0.0f, 0.0f},
			.UV = {0.5f, 0.5f}
		},
		// Top right point
		{
			.Position = {-2.0f, 2.0f, 0.1f},
			.Color = {0.0f, 0.0f, 0.0f},
			.UV = {0.5f, 0.5f}
		},
		// Top left point
		{
			.Position = {-2.0f, 2.0f, -0.1f},
			.Color = {0.0f, 0.0f, 0.0f},
			.UV = {0.5f, 0.5f}
		},
	// Bottom face
		// Bottom left point
		{
			.Position = {-2.0f, 0.0f, 0.1f},
			.Color = {0.45f, 0.45f, 0.45f},
			.UV = {0.5f, 0.5f}
		},
		// Bottom right point
		{
			.Position = {2.0f, 0.0f, 0.1f},
			.Color = {0.45f, 0.45f, 0.45f},
			.UV = {0.5f, 0.5f}
		},
		// Top right point
		{
			.Position = {2.0f, 0.0f, -0.1f},
			.Color = {0.45f, 0.45f, 0.45f},
			.UV = {0.5f, 0.5f}
		},
		// Top left point
		{
			.Position = {-2.0f, 0.0f, -0.1f},
			.Color = {0.45f, 0.45f, 0.45f},
			.UV = {0.5f, 0.5f}
		},
	// Top face
		// Bottom left point
		{
			.Position = {-2.0f, 2.0f, 0.1f},
			.Color = {0.0f, 0.0f, 0.0f},
			.UV = {0.5f, 0.5f}
		},
		// Bottom right point
		{
			.Position = {2.0f, 2.0f, 0.1f},
			.Color = {0.0f, 0.0f, 0.0f},
			.UV = {0.5f, 0.5f}
		},
		// Top right point
		{
			.Position = {2.0f, 2.0f, -0.1f},
			.Color = {0.0f, 0.0f, 0.0f},
			.UV = {0.5f, 0.5f}
		},
		// Top left point
		{
			.Position = {-2.0f, 2.0f, -0.1f},
			.Color = {0.0f, 0.0f, 0.0f},
			.UV = {0.5f, 0.5f}
		},
	};
	static inline std::vector<uint32_t> laptopElements{
		0, 1, 3, 1, 2, 3, // Front face
		4, 5, 7, 5, 6, 7, // Right face
		8, 9, 11, 9, 10, 11, // Back face
		12, 13, 15, 13, 14, 15, // Left face
		16, 17, 19, 17, 18, 19, // Top face
		20, 21, 23, 21, 22, 23, // Bottom face
	};
};

struct BookCover {
	static inline std::vector<Vertex> bookCoverVertices{
// Book cover bottom
	// Front face of book cover
		// Front face bottom left point
		{
			.Position = {-0.75f, 0.00f, 0.0f},
			.Color = {0.0f, 0.0f, 0.0f},
			.UV = {0.5f, 0.5f}
		},
		// Front face bottom right point
		{
			.Position = {0.75f, 0.0f, 0.0f},
			.Color = {0.0f, 0.0f, 0.0f},
			.UV = {0.5f, 0.5f}
		},
		// Front face top right point
		{
			.Position = {0.75f, 0.05f, 0.0f},
			.Color = {0.0f, 0.0f, 0.0f},
			.UV = {0.5f, 0.5f}
		},
		// Front face top left point
		{
			.Position = {-0.75f, 0.05f, 0.0f},
			.Color = {0.0f, 0.0f, 0.0f},
			.UV = {0.5f, 0.5f}
		},
	// Right face
		// Bottom left point
		{
			.Position = {0.75f, 0.0f, 0.0f},
			.Color = {0.0f, 0.0f, 0.0f},
			.UV = {0.5f, 0.5f}
		},
		// Bottom right point
		{
			.Position = {0.75f, 0.0f, -1.5f},
			.Color = {0.0f, 0.0f, 0.0f},
			.UV = {0.5f, 0.5f}
		},
		// Top right point
		{
			.Position = {0.75f, 0.05f, -1.5f},
			.Color = {0.0f, 0.0f, 0.0f},
			.UV = {0.5f, 0.5f}
		},
		// Top left point
		{
			.Position = {0.75f, 0.05f, 0.0f},
			.Color = {0.0f, 0.0f, 0.0f},
			.UV = {0.5f, 0.5f}
		},
	// Back face
		// Bottom left point
		{
			.Position = {0.75f, 0.0f, -1.5f},
			.Color = {0.0f, 0.0f, 0.0f},
			.UV = {0.5f, 0.5f}
		},
		// Bottom right point
		{
			.Position = {-0.75f, 0.0f, -1.5f},
			.Color = {0.0f, 0.0f, 0.0f},
			.UV = {0.5f, 0.5f}
		},
		// Top right point
		{
			.Position = {-0.75f, 0.05f, -1.5f},
			.Color = {0.0f, 0.0f, 0.0f},
			.UV = {0.5f, 0.5f}
		},
		// Top left point
		{
			.Position = {0.75f, 0.05f, -1.5f},
			.Color = {0.45f, 0.45f, 0.45f},
			.UV = {0.5f, 0.5f}
		},
	// Left face
		// Bottom left point
		{
			.Position = {-0.75f, 0.0f, -1.5f},
			.Color = {0.0f, 0.0f, 0.0f},
			.UV = {0.5f, 0.5f}
		},
		// Bottom right point
		{
			.Position = {-0.75f, 0.0f, 0.0f},
			.Color = {0.0f, 0.0f, 0.0f},
			.UV = {0.5f, 0.5f}
		},
		// Top right point
		{
			.Position = {-0.75f, 0.05f, 0.0f},
			.Color = {0.0f, 0.0f, 0.0f},
			.UV = {0.5f, 0.5f}
		},
		// Top left point
		{
			.Position = {-0.75f, 0.05f, -1.5f},
			.Color = {0.0f, 0.0f, 0.0f},
			.UV = {0.5f, 0.5f}
		},
	// Bottom face
		// Bottom left point
		{
			.Position = {-0.75f, 0.0f, 0.0f},
			.Color = {0.0f, 0.0f, 0.0f},
			.UV = {0.5f, 0.5f}
		},
		// Bottom right point
		{
			.Position = {0.75f, 0.0f, 0.0f},
			.Color = {0.0f, 0.0f, 0.0f},
			.UV = {0.5f, 0.5f}
		},
		// Top right point
		{
			.Position = {0.75f, 0.0f, -1.5f},
			.Color = {0.0f, 0.0f, 0.0f},
			.UV = {0.5f, 0.5f}
		},
		// Top left point
		{
			.Position = {-0.75f, 0.0f, -1.5f},
			.Color = {0.0f, 0.0f, 0.0f},
			.UV = {0.5f, 0.5f}
		},
	// Top face
		// Bottom left point
		{
			.Position = {-0.75f, 0.05f, 0.0f},
			.Color = {0.0f, 0.0f, 0.0f},
			.UV = {0.5f, 0.5f}
		},
		// Bottom right point
		{
			.Position = {0.75f, 0.05f, 0.0f},
			.Color = {0.0f, 0.0f, 0.0f},
			.UV = {0.5f, 0.5f}
		},
		// Top right point
		{
			.Position = {0.75f, 0.05f, -1.5f},
			.Color = {0.0f, 0.0f, 0.0f},
			.UV = {0.5f, 0.5f}
		},
		// Top left point
		{
			.Position = {-0.75f, 0.05f, -1.5f},
			.Color = {0.0f, 0.0f, 0.0f},
			.UV = {0.5f, 0.5f}
		},
// Book Cover side
	// Front face
		// Bottom left point
		{
			.Position = {-0.8f, 0.00f, 0.0f},
			.Color = {0.0f, 0.0f, 0.0f},
			.UV = {0.5f, 0.5f}
		},
		// Bottom right point
		{
			.Position = {-0.75f, 0.00f, 0.0f},
			.Color = {0.0f, 0.0f, 0.0f},
			.UV = {0.5f, 0.5f}
		},
		// Top right point
		{
			.Position = {-0.75f, 0.5f, 0.0f},
			.Color = {0.0f, 0.0f, 0.0f},
			.UV = {0.5f, 0.5f}
		},
		// Top left point
		{
			.Position = {-0.8f, 0.5f, 0.0f},
			.Color = {0.0f, 0.0f, 0.0f},
			.UV = {0.5f, 0.5f}
		},
	// Right face
		// Bottom left point
		{
			.Position = {-0.75f, 0.00f, 0.0f},
			.Color = {0.0f, 0.0f, 0.0f},
			.UV = {0.5f, 0.5f}
		},
		// Bottom right point
		{
			.Position = {-0.75f, 0.00f, -1.5f},
			.Color = {0.0f, 0.0f, 0.0f},
			.UV = {0.5f, 0.5f}
		},
		// Top right point
		{
			.Position = {-0.75f, 0.5f, -1.5f},
			.Color = {0.0f, 0.0f, 0.0f},
			.UV = {0.5f, 0.5f}
		},
		// Top left point
		{
			.Position = {-0.75f, 0.5f, 0.0f},
			.Color = {0.0f, 0.0f, 0.0f},
			.UV = {0.5f, 0.5f}
		},
	// Back face
		// Bottom left point
		{
			.Position = {-0.75f, 0.00f, -1.5f},
			.Color = {0.0f, 0.0f, 0.0f},
			.UV = {0.5f, 0.5f}
		},
		// Bottom right point
		{
			.Position = {-0.8f, 0.00f, -1.5f},
			.Color = {0.0f, 0.0f, 0.0f},
			.UV = {0.5f, 0.5f}
		},
		// Top right point
		{
			.Position = {-0.8f, 0.5f, -1.5f},
			.Color = {0.0f, 0.0f, 0.0f},
			.UV = {0.5f, 0.5f}
		},
		// Top left point
		{
			.Position = {-0.75f, 0.5f, -1.5f},
			.Color = {0.0f, 0.0f, 0.0f},
			.UV = {0.5f, 0.5f}
		},
	// Right face
		// Bottom left point
		{
			.Position = {-0.8f, 0.0f, -1.5f},
			.Color = {0.0f, 0.0f, 0.0f},
			.UV = {0.5f, 0.5f}
		},
		// Bottom Right point
		{
			.Position = {-0.8f, 0.0f, 0.0f},
			.Color = {0.0f, 0.0f, 0.0f},
			.UV = {0.5f, 0.5f}
		},
		// Top Right point
		{
			.Position = {-0.8f, 0.5f, 0.0f},
			.Color = {0.0f, 0.0f, 0.0f},
			.UV = {0.5f, 0.5f}
		},
		// Top left point
		{
			.Position = {-0.8f, 0.5f, -1.5f},
			.Color = {0.0f, 0.0f, 0.0f},
			.UV = {0.5f, 0.5f}
		},
	// Bottom face
		// Bottom left point
		{
			.Position = {-0.8f, 0.0f, 0.0f},
			.Color = {0.0f, 0.0f, 0.0f},
			.UV = {0.5f, 0.5f}
		},
		// Bottom Right point
		{
			.Position = {-0.75f, 0.0f, 0.0f},
			.Color = {0.0f, 0.0f, 0.0f},
			.UV = {0.5f, 0.5f}
		},
		// Top Right point
		{
			.Position = {-0.75f, 0.0f, -1.5f},
			.Color = {0.0f, 0.0f, 0.0f},
			.UV = {0.5f, 0.5f}
		},
		// Top left point
		{
			.Position = {-0.8f, 0.0f, -1.5f},
			.Color = {0.0f, 0.0f, 0.0f},
			.UV = {0.5f, 0.5f}
		},
	// Top face
		// Bottom left point
		{
			.Position = {-0.8f, 0.5f, 0.0f},
			.Color = {0.0f, 0.0f, 0.0f},
			.UV = {0.5f, 0.5f}
		},
		// Bottom Right point
		{
			.Position = {-0.75f, 0.5f, 0.0f},
			.Color = {0.0f, 0.0f, 0.0f},
			.UV = {0.5f, 0.5f}
		},
		// Top Right point
		{
			.Position = {-0.75f, 0.5f, -1.5f},
			.Color = {0.0f, 0.0f, 0.0f},
			.UV = {0.5f, 0.5f}
		},
		// Top left point
		{
			.Position = {-0.8f, 0.5f, -1.5f},
			.Color = {0.0f, 0.0f, 0.0f},
			.UV = {0.5f, 0.5f}
		},

// Book cover top
	// Front face of book cover
		// Front face bottom left point
		{
			.Position = {-0.75f, 0.5f, 0.0f},
			.Color = {0.0f, 0.0f, 0.0f},
			.UV = {0.5f, 0.5f}
		},
		// Front face bottom right point
		{
			.Position = {0.75f, 0.5f, 0.0f},
			.Color = {0.0f, 0.0f, 0.0f},
			.UV = {0.5f, 0.5f}
		},
		// Front face top right point
		{
			.Position = {0.75f, 0.55f, 0.0f},
			.Color = {0.0f, 0.0f, 0.0f},
			.UV = {0.5f, 0.5f}
		},
		// Front face top left point
		{
			.Position = {-0.75f, 0.55f, 0.0f},
			.Color = {0.0f, 0.0f, 0.0f},
			.UV = {0.5f, 0.5f}
		},
	// Right face
		// Bottom left point
		{
			.Position = {0.75f, 0.5f, 0.0f},
			.Color = {0.0f, 0.0f, 0.0f},
			.UV = {0.5f, 0.5f}
		},
		// Bottom right point
		{
			.Position = {0.75f, 0.5f, -1.5f},
			.Color = {0.0f, 0.0f, 0.0f},
			.UV = {0.5f, 0.5f}
		},
		// Top right point
		{
			.Position = {0.75f, 0.55f, -1.5f},
			.Color = {0.0f, 0.0f, 0.0f},
			.UV = {0.5f, 0.5f}
		},
		// Top left point
		{
			.Position = {0.75f, 0.55f, 0.0f},
			.Color = {0.0f, 0.0f, 0.0f},
			.UV = {0.5f, 0.5f}
		},
	// Back face
		// Bottom left point
		{
			.Position = {0.75f, 0.5f, -1.5f},
			.Color = {0.0f, 0.0f, 0.0f},
			.UV = {0.5f, 0.5f}
		},
		// Bottom right point
		{
			.Position = {-0.75f, 0.5f, -1.5f},
			.Color = {0.0f, 0.0f, 0.0f},
			.UV = {0.5f, 0.5f}
		},
		// Top right point
		{
			.Position = {-0.75f, 0.55f, -1.5f},
			.Color = {0.0f, 0.0f, 0.0f},
			.UV = {0.5f, 0.5f}
		},
		// Top left point
		{
			.Position = {0.75f, 0.55f, -1.5f},
			.Color = {0.0f, 0.0f, 0.0f},
			.UV = {0.5f, 0.5f}
		},
	// Left face
		// Bottom left point
		{
			.Position = {-0.75f, 0.5f, -1.5f},
			.Color = {0.0f, 0.0f, 0.0f},
			.UV = {0.5f, 0.5f}
		},
		// Bottom right point
		{
			.Position = {-0.75f, 0.5f, 0.0f},
			.Color = {0.0f, 0.0f, 0.0f},
			.UV = {0.5f, 0.5f}
		},
		// Top right point
		{
			.Position = {-0.75f, 0.55f, 0.0f},
			.Color = {0.0f, 0.0f, 0.0f},
			.UV = {0.5f, 0.5f}
		},
		// Top left point
		{
			.Position = {-0.75f, 0.55f, -1.5f},
			.Color = {0.0f, 0.0f, 0.0f},
			.UV = {0.5f, 0.5f}
		},
	// Bottom face
		// Bottom left point
		{
			.Position = {-0.75f, 0.5f, 0.0f},
			.Color = {0.0f, 0.0f, 0.0f},
			.UV = {0.5f, 0.5f}
		},
		// Bottom right point
		{
			.Position = {0.75f, 0.5f, 0.0f},
			.Color = {0.0f, 0.0f, 0.0f},
			.UV = {0.5f, 0.5f}
		},
		// Top right point
		{
			.Position = {0.75f, 0.5f, -1.5f},
			.Color = {0.0f, 0.0f, 0.0f},
			.UV = {0.5f, 0.5f}
		},
		// Top left point
		{
			.Position = {-0.75f, 0.5f, -1.5f},
			.Color = {0.0f, 0.0f, 0.0f},
			.UV = {0.5f, 0.5f}
		},
	// Top face
		// Bottom left point
		{
			.Position = {-0.75f, 0.55f, 0.0f},
			.Color = {0.0f, 0.0f, 0.0f},
			.UV = {0.5f, 0.5f}
		},
		// Bottom right point
		{
			.Position = {0.75f, 0.55f, 0.0f},
			.Color = {0.0f, 0.0f, 0.0f},
			.UV = {0.5f, 0.5f}
		},
		// Top right point
		{
			.Position = {0.75f, 0.55f, -1.5f},
			.Color = {0.0f, 0.0f, 0.0f},
			.UV = {0.5f, 0.5f}
		},
		// Top left point
		{
			.Position = {-0.75f, 0.55f, -1.5f},
			.Color = {0.0f, 0.0f, 0.0f},
			.UV = {0.5f, 0.5f}
		},
	};
	static inline std::vector<uint32_t> bookCoverElements{
	// Bottom of book cover
		0, 1, 3, 1, 2, 3, // Front face
		4, 5, 7, 5, 6, 7, // Right face
		8, 9, 11, 9, 10, 11, // Back face
		12, 13, 15, 13, 14, 15, // Left face
		16, 17, 19, 17, 18, 19, // Bottom face
		20, 21, 23, 21, 22, 23, // Top face
	// Side of book cover
		24, 25, 27, 25, 26, 27, // Front face
		28, 29, 31, 29, 30, 31, // Right face
		32, 33, 35, 33, 34, 35, // Back face
		36, 37, 39, 37, 38, 39, // Left face
		40, 41, 43, 41, 42, 43, // Bottom face
		44, 45, 47, 45, 46, 47, // Top face
	// Top of book cover
		48, 49, 51, 49, 50, 51, // Front face
		52, 53, 55, 53, 54, 55, // Right face
		56, 57, 59, 57, 58, 59, // Back face
		60, 61, 63, 61, 62, 63, // Left face
		64, 65, 67, 65, 66, 67, // Bottom face
		68, 69, 71, 69, 70, 71, // Top face
	};
};

struct BookPages {
	static inline std::vector<Vertex> bookPageVertices{
	// Front face of book pages
		// Front face bottom left point
		{
			.Position = {-0.6f, 0.06f, -0.1f},
			.Color = {0.87f, 0.78f, 0.65f},
			.UV = {0.5f, 0.5f}
		},
		// Front face bottom right point
		{
			.Position = {0.6f, 0.06f, -0.1f},
			.Color = {0.87f, 0.78f, 0.65f},
			.UV = {0.5f, 0.5f}
		},
		// Front face top right point
		{
			.Position = {0.6f, 0.49f, -0.1f},
			.Color = {0.87f, 0.78f, 0.65f},
			.UV = {0.5f, 0.5f}
		},
		// Front face top left point
		{
			.Position = {-0.6f, 0.49f, -0.1f},
			.Color = {0.87f, 0.78f, 0.65f},
			.UV = {0.5f, 0.5f}
		},
	// Right face
		// Bottom left point
		{
			.Position = {0.6f, 0.06f, -0.1f},
			.Color = {0.87f, 0.78f, 0.65f},
			.UV = {0.5f, 0.5f}
		},
		// Bottom right point
		{
			.Position = {0.6f, 0.06f, -1.4f},
			.Color = {0.87f, 0.78f, 0.65f},
			.UV = {0.5f, 0.5f}
		},
		// Top right point
		{
			.Position = {0.6f, 0.49f, -1.4f},
			.Color = {0.87f, 0.78f, 0.65f},
			.UV = {0.5f, 0.5f}
		},
		// Top left point
		{
			.Position = {0.6f, 0.49f, -0.1f},
			.Color = {0.87f, 0.78f, 0.65f},
			.UV = {0.5f, 0.5f}
		},
	// Back face
		// Bottom left point
		{
			.Position = {0.6f, 0.06f, -1.4f},
			.Color = {0.87f, 0.78f, 0.65f},
			.UV = {0.5f, 0.5f}
		},
		// Bottom right point
		{
			.Position = {-0.6f, 0.06f, -1.4f},
			.Color = {0.87f, 0.78f, 0.65f},
			.UV = {0.5f, 0.5f}
		},
		// Top right point
		{
			.Position = {-0.6f, 0.49f, -1.4f},
			.Color = {0.87f, 0.78f, 0.65f},
			.UV = {0.5f, 0.5f}
		},
		// Top left point
		{
			.Position = {0.6f, 0.49f, -1.4f},
			.Color = {0.87f, 0.78f, 0.65f},
			.UV = {0.5f, 0.5f}
		},
	// Left face
		// Bottom left point
		{
			.Position = {-0.6f, 0.06f, -1.4f},
			.Color = {0.87f, 0.78f, 0.65f},
			.UV = {0.5f, 0.5f}
		},
		// Bottom right point
		{
			.Position = {-0.6f, 0.06f, -0.1f},
			.Color = {0.87f, 0.78f, 0.65f},
			.UV = {0.5f, 0.5f}
		},
		// Top right point
		{
			.Position = {-0.6f, 0.49f, -0.1f},
			.Color = {0.87f, 0.78f, 0.65f},
			.UV = {0.5f, 0.5f}
		},
		// Top left point
		{
			.Position = {-0.6f, 0.49f, -1.4f},
			.Color = {0.87f, 0.78f, 0.65f},
			.UV = {0.5f, 0.5f}
		},
	// Bottom face
		// Bottom left point
		{
			.Position = {-0.6f, 0.06f, -0.1f},
			.Color = {0.87f, 0.78f, 0.65f},
			.UV = {0.5f, 0.5f}
		},
		// Bottom right point
		{
			.Position = {0.6f, 0.06f, -0.1f},
			.Color = {0.87f, 0.78f, 0.65f},
			.UV = {0.5f, 0.5f}
		},
		// Top right point
		{
			.Position = {0.6f, 0.06f, -1.4f},
			.Color = {0.87f, 0.78f, 0.65f},
			.UV = {0.5f, 0.5f}
		},
		// Top left point
		{
			.Position = {-0.6f, 0.06f, -1.4f},
			.Color = {0.87f, 0.78f, 0.65f},
			.UV = {0.5f, 0.5f}
		},
	// Top face
		// Bottom left point
		{
			.Position = {-0.6f, 0.49f, -0.1f},
			.Color = {0.87f, 0.78f, 0.65f},
			.UV = {0.5f, 0.5f}
		},
		// Bottom right point
		{
			.Position = {0.6f, 0.49f, -0.1f},
			.Color = {0.87f, 0.78f, 0.65f},
			.UV = {0.5f, 0.5f}
		},
		// Top right point
		{
			.Position = {0.6f, 0.49f, -1.4f},
			.Color = {0.87f, 0.78f, 0.65f},
			.UV = {0.5f, 0.5f}
		},
		// Top left point
		{
			.Position = {-0.6f, 0.49f, -1.4f},
			.Color = {0.87f, 0.78f, 0.65f},
			.UV = {0.5f, 0.5f}
		},
	};
	static inline std::vector<uint32_t> bookPagesElements{
		0, 1, 3, 1, 2, 3, // Front face
		4, 5, 7, 5, 6, 7, // Right face
		8, 9, 11, 9, 10, 11, // Back face
		12, 13, 15, 13, 14, 15, // Left face
		16, 17, 19, 17, 18, 19, // Bottom face
		20, 21, 23, 21, 22, 23, // Top face
	};
};

struct PenTip {
	static inline std::vector<Vertex> penTipVertices {
	// Front face
		// Bottom left point, front face
		{
			.Position = {-0.1f, 0.0f, 0.1f},
			.Color = {0.75f, 0.75f, 0.75f},
			.UV = {0.5f, 0.5f}
		},
		// Bottom right point, front face
		{
			.Position = {0.1f, 0.0f, 0.1f},
			.Color = {0.75f, 0.75f, 0.75f},
			.UV = {0.5f, 0.5f}
		},
		// Top of pyramid
		{
			.Position = {0.0f, 0.2f, 0.0f},
			.Color = {0.75f, 0.75f, 0.75f},
			.UV = {0.5f, 0.5f}
		},
	// Right face
		// Bottom left point, right face
		{
			.Position = {0.1f, 0.0f, 0.1f},
			.Color = {0.75f, 0.75f, 0.75f},
			.UV = {0.5f, 0.5f}
		},
		// Bottom right point, right face
		{
			.Position = {0.1f, 0.0f, -0.1f},
			.Color = {0.75f, 0.75f, 0.75f},
			.UV = {0.5f, 0.5f}
		},
		// Top of pyramid
		{
			.Position = {0.0f, 0.2f, 0.0f},
			.Color = {0.75f, 0.75f, 0.75f},
			.UV = {0.5f, 0.5f}
		},
	// Back face
		// Bottom left point, back face
		{
			.Position = {0.1f, 0.0f, -0.1f},
			.Color = {0.75f, 0.75f, 0.75f},
			.UV = {0.5f, 0.5f}
		},
		// Bottom right point, back face
		{
			.Position = {-0.1f, 0.0f, -0.1f},
			.Color = {0.75f, 0.75f, 0.75f},
			.UV = {0.5f, 0.5f}
		},
		// Top of pyramid
		{
			.Position = {0.0f, 0.2f, 0.0f},
			.Color = {0.75f, 0.75f, 0.75f},
			.UV = {0.5f, 0.5f}
		},
	// Left face
		// Bottom left point, left face
		{
			.Position = {-0.1f, 0.0f, -0.1f},
			.Color = {0.75f, 0.75f, 0.75f},
			.UV = {0.5f, 0.5f}
		},
		// Bottom right point, left face
		{
			.Position = {-0.1f, 0.0f, 0.1f},
			.Color = {0.75f, 0.75f, 0.75f},
			.UV = {0.5f, 0.5f}
		},
		// Top of pyramid
		{
			.Position = {0.0f, 0.2f, 0.0f},
			.Color = {0.75f, 0.75f, 0.75f},
			.UV = {0.5f, 0.5f}
		},
	// Bottom face
		// Front Left point
		{
			.Position = {-0.1f, 0.0f, 0.1f},
			.Color = {0.75f, 0.75f, 0.75f},
			.UV = {0.5f, 0.5f}
		},
		// Front Right point
		{
			.Position = {0.1f, 0.0f, 0.1f},
			.Color = {0.75f, 0.75f, 0.75f},
			.UV = {0.5f, 0.5f}
		},
		// Back right point 
		{
			.Position = {0.1f, 0.0f, -0.1f},
			.Color = {0.75f, 0.75f, 0.75f},
			.UV = {0.5f, 0.5f}
		},
		// Back Left point
		{
			.Position = {-0.1f, 0.0f, -0.1f},
			.Color = {0.75f, 0.75f, 0.75f},
			.UV = {0.5f, 0.5f}
		},
	};

	static inline std::vector<uint32_t> penTipElements{
		0, 1, 2, // front face
		3, 4, 5, // right face
		6, 7, 8, // back face
		9, 10, 11, // left face
		12, 13, 15, // bottom face bottom triangle
		13, 14, 15 // bottom face top triangle
	};
};

struct PenBase {
	static inline std::vector<Vertex> penBaseVertices{
	// Front face
		// Bottom left point, front face
		{
			.Position = {-0.1f, 0.0f, 0.1f},
			.Color = {0.0f, 0.0f, 0.0f},
			.UV = {0.5f, 0.5f}
		},
		// Bottom right point, front face
		{
			.Position = {0.1f, 0.0f, 0.1f},
			.Color = {0.0f, 0.0f, 0.0f},
			.UV = {0.5f, 0.5f}
		},
		// Top right point
		{
			.Position = {0.1f, 2.0f, 0.1f},
			.Color = {0.0f, 0.0f, 0.0f},
			.UV = {0.5f, 0.5f}
		},
		// Top left point
		{
			.Position = {-0.1f, 2.0f, 0.1f},
			.Color = {0.0f, 0.0f, 0.0f},
			.UV = {0.5f, 0.5f}
		},
	// Right face
		// Bottom left point
		{
			.Position = {0.1f, 0.0f, 0.1f},
			.Color = {0.0f, 0.0f, 0.0f},
			.UV = {0.5f, 0.5f}
		},
		// Bottom right point
		{
			.Position = {0.1f, 0.0f, -0.1f},
			.Color = {0.0f, 0.0f, 0.0f},
			.UV = {0.5f, 0.5f}
		},
		// Top right point
		{
			.Position = {0.1f, 2.0f, -0.1f},
			.Color = {0.0f, 0.0f, 0.0f},
			.UV = {0.5f, 0.5f}
		},
		// Top left point
		{
			.Position = {0.1f, 2.0f, 0.1f},
			.Color = {0.0f, 0.0f, 0.0f},
			.UV = {0.5f, 0.5f}
		},
	// Back face
		// Bottom left point, back face
		{
			.Position = {0.1f, 0.0f, -0.1f},
			.Color = {0.0f, 0.0f, 0.0f},
			.UV = {0.5f, 0.5f}
		},
		// Bottom right point, back face
		{
			.Position = {-0.1f, 0.0f, -0.1f},
			.Color = {0.0f, 0.0f, 0.0f},
			.UV = {0.5f, 0.5f}
		},
		// Top right point
		{
			.Position = {-0.1f, 2.0f, -0.1f},
			.Color = {0.0f, 0.0f, 0.0f},
			.UV = {0.5f, 0.5f}
		},
		// Top left point
		{
			.Position = {0.1f, 2.0f, -0.1f},
			.Color = {0.0f, 0.0f, 0.0f},
			.UV = {0.5f, 0.5f}
		},
	// Left face
		// Bottom left point, left face
		{
			.Position = {-0.1f, 0.0f, -0.1f},
			.Color = {0.0f, 0.0f, 0.0f},
			.UV = {0.5f, 0.5f}
		},
		// Bottom right point, left face
		{
			.Position = {-0.1f, 0.0f, 0.1f},
			.Color = {0.0f, 0.0f, 0.0f},
			.UV = {0.5f, 0.5f}
		},
		// Top right point
		{
			.Position = {-0.1f, 2.0f, 0.1f},
			.Color = {0.0f, 0.0f, 0.0f},
			.UV = {0.5f, 0.5f}
		},
		// Top left point
		{
			.Position = {-0.1f, 2.0f, -0.1f},
			.Color = {0.0f, 0.0f, 0.0f},
			.UV = {0.5f, 0.5f}
		},
	// Bottom face
		// Front Left point
		{
			.Position = {-0.1f, 0.0f, 0.1f},
			.Color = {0.75f, 0.75f, 0.75f},
			.UV = {0.5f, 0.5f}
		},
		// Front Right point
		{
			.Position = {0.1f, 0.0f, 0.1f},
			.Color = {0.75f, 0.75f, 0.75f},
			.UV = {0.5f, 0.5f}
		},
		// Back right point 
		{
			.Position = {0.1f, 0.0f, -0.1f},
			.Color = {0.75f, 0.75f, 0.75f},
			.UV = {0.5f, 0.5f}
		},
		// Back Left point
		{
			.Position = {-0.1f, 0.0f, -0.1f},
			.Color = {0.75f, 0.75f, 0.75f},
			.UV = {0.5f, 0.5f}
		},
	// Top face
		// Front Left point
		{
			.Position = {-0.1f, 2.0f, 0.1f},
			.Color = {0.75f, 0.75f, 0.75f},
			.UV = {0.5f, 0.5f}
		},
		// Front Right point
		{
			.Position = {0.1f, 2.0f, 0.1f},
			.Color = {0.75f, 0.75f, 0.75f},
			.UV = {0.5f, 0.5f}
		},
		// Back right point 
		{
			.Position = {0.1f, 2.0f, -0.1f},
			.Color = {0.75f, 0.75f, 0.75f},
			.UV = {0.5f, 0.5f}
		},
		// Back Left point
		{
			.Position = {-0.1f, 2.0f, -0.1f},
			.Color = {0.75f, 0.75f, 0.75f},
			.UV = {0.5f, 0.5f}
		},
	};
	static inline std::vector<uint32_t> penBaseElements{
		0, 1, 3, 1, 2, 3, // Front face
		4, 5, 7, 5, 6, 7, // Right face
		8, 9, 11, 9, 10, 11, // Back face
		12, 13, 15, 13, 14, 15, // Left face
		16, 17, 19, 17, 18, 19, // Bottom face
		20, 21, 23, 21, 22, 23, // Top face
	};
};