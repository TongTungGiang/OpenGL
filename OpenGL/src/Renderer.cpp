#include "Renderer.h"

#include <iostream>
#include <sstream>

#include "VertexArray.h"
#include "IndexBuffer.h"
#include "Shader.h"

#include "Common.h"

void Renderer::Draw(const VertexArray& va, const IndexBuffer& ib, const Shader& shader) const
{
	/* Bind data */
	shader.Bind();
	va.Bind();
	ib.Bind();

	GLCall(glDrawElements(GL_TRIANGLES, ib.GetCount(), GL_UNSIGNED_INT, nullptr));
}

void Renderer::Clear()
{
	GLCall(glClear(GL_COLOR_BUFFER_BIT));
}
