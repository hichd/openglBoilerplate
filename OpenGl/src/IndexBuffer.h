#pragma once

class IndexBuffer
{
	/* id for every type of object (shader, vertex buffer, vertex array ...)
	we create in opengl*/
private:
	unsigned int m_RendererID;
	unsigned int m_Count;
public:
	// how many indices
	IndexBuffer(const unsigned int* data, unsigned int count);
	~IndexBuffer();

	void Bind() const;
	void UnBind() const;

	inline unsigned int GetCount() const { return m_Count;  }
};
