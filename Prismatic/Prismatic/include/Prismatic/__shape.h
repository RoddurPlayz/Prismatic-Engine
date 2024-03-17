#pragma once


#include <source_location>

#define GLEW_STATIC
#include "../GL/glew.h"

#include "__error.h"
#include "__shader.h"


class PrismSurface
{
private:
	unsigned int m_VAO;
	unsigned int m_VBO;
	unsigned int m_IBO;

	float m_Vertices[8] = {
		-0.5f, -0.5f, // 0
		 0.5f, -0.5f, // 1
		 0.5f,  0.5f, // 2
		-0.5f,  0.5f  // 3
	};

	unsigned int m_Indices[6] = {
		0, 1, 2,
		2, 3, 0
	};
public:
	PrismSurface(int width, int height, std::source_location location = std::source_location::current());

	void Draw(const PrismShader& shader = PrismShader(), std::source_location location = std::source_location::current());
};
