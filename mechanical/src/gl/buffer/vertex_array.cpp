#include "mechanical/gl/buffer/vertex_array.hpp"
#include "mechanical/gl/OpenGLDefs.hpp"

namespace me {

VertexArray::VertexArray() { glGenVertexArrays(1, &arrayID); }

VertexArray::~VertexArray() {
    vbos.clear();
    glDeleteVertexArrays(1, &arrayID);
}

void VertexArray::bind() const { glBindVertexArray(arrayID); }

void VertexArray::unbind() { glBindVertexArray(0); }

} // namespace me
