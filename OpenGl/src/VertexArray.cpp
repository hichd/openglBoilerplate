#include "Renderer.h"

#include "VertexArray.h"
#include "VertexBufferLayout.h"

// vertex arrays tie together vertex array buffer with some kind of layout, vertex buffers do not know how the data is organized (what each byte in the array represents, how big is a single vertex)
// vertex array objects are used to store this state

VertexArray::VertexArray()
{
    GLCall(glGenVertexArrays(1, &m_RendererID));
}

VertexArray::~VertexArray()
{
    GLCall(glDeleteVertexArrays(1, &m_RendererID));
}

void VertexArray::AddBuffer(const VertexBuffer& vb, const VertexBufferLayout& layout)
{
    Bind();
	vb.Bind();// bind vertex buffer
    unsigned int offset = 0;
    const auto& elements = layout.GetElements();

    for (unsigned int i = 0; i < elements.size(); i++)
    {// setup the layout
        const auto& element = elements[i];
        GLCall(glEnableVertexAttribArray(i));// specifies how the layout is
        GLCall(glVertexAttribPointer(
            i, 
            element.count, 
            element.type, 
            element.normalized , 
            layout.GetStride(), 
            (const void*)offset)); // links buffer with vao

        offset += element.count * VertexBufferElement::GetSizeOfType(element.type);
    }
}

void VertexArray::Bind() const
{
    GLCall(glBindVertexArray(m_RendererID));
}

void VertexArray::UnBind() const
{
    GLCall(glBindVertexArray(m_RendererID));
}