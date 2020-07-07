#pragma once

class VertexBuffer
{
	/* id for every type of object (shader, vertex buffer, vertex array ...)
	we create in opengl*/
private:
	unsigned int m_RendererID;
public:
	VertexBuffer(const void* data, unsigned int size);
	~VertexBuffer();

	void Bind() const;
	void UnBind() const;
};