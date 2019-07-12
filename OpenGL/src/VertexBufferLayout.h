#pragma once

#include <vector>
#include <GL/glew.h>
#include "Common.h"

struct VertexBufferElement
{
	unsigned int type;
	unsigned int count;
	bool normalized;

	static unsigned int GetSizeOfType(unsigned int type)
	{
		switch (type)
		{
		case GL_FLOAT: return 4;
		case GL_UNSIGNED_INT: return 4;
		case GL_UNSIGNED_BYTE: return 1;
		}

		ASSERT(false);
		return 0;
	}
};

class VertexBufferLayout
{
public:
	VertexBufferLayout() : m_Stride(0) {}

	template <typename T>
	void Push(unsigned int count)
	{
		static_assert(false);
	}

	inline std::vector<VertexBufferElement> GetElements() const { return m_Elements; }
	inline unsigned int GetStride() const { return m_Stride; }

private:

	std::vector<VertexBufferElement> m_Elements;
	unsigned int m_Stride;
};


/***
 * Template function specializations
 */
template<>
void VertexBufferLayout::Push<float>(unsigned int count);

template<>
void VertexBufferLayout::Push<unsigned int>(unsigned int count);

template<>
void VertexBufferLayout::Push<unsigned char>(unsigned int count);
