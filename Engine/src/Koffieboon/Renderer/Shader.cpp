#include "kbpch.h"
#include "Shader.h"

#include <glad/glad.h>

namespace Koffieboon
{
	Shader::Shader(const std::string& vertexShaderSource, const std::string& fragmentShaderSource)
	{
		// Create an empty vertex shader handle
        unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);

		// Send the vertex shader source code to GL
		const GLchar* sourceCStr = vertexShaderSource.c_str();
        glShaderSource(vertexShader, 1, &sourceCStr, 0);
		// Compile the vertex shader
        glCompileShader(vertexShader);

        // check for shader compile errors
        GLint isCompiled = 0;
        glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &isCompiled);
        if (isCompiled == GL_FALSE)
        {
            GLint maxLength = 0;
            glGetShaderiv(vertexShader, GL_INFO_LOG_LENGTH, &maxLength);

            // The maxLength includes the NULL character
            std::vector<GLchar> infoLog(maxLength);
            glGetShaderInfoLog(vertexShader, maxLength, &maxLength, &infoLog[0]);

            // We don't need the shader anymore.
            glDeleteShader(vertexShader);

            KB_CORE_ERROR("{0}", infoLog.data());
            KASSERT_MSG(false, "Vertex shader compilation failure!");
            return;
        }

		// Create an empty fragment shader handle
        unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);

		// Send the fragment shader source code to GL
		sourceCStr = fragmentShaderSource.c_str();
        glShaderSource(fragmentShader, 1, &sourceCStr, NULL);
		// Compile the fragment shader
        glCompileShader(fragmentShader);

        // check for shader compile errors
        glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &isCompiled);
        if (isCompiled == GL_FALSE)
        {
            GLint maxLength = 0;
            glGetShaderiv(fragmentShader, GL_INFO_LOG_LENGTH, &maxLength);

            // The maxLength includes the NULL character
            std::vector<GLchar> infoLog(maxLength);
            glGetShaderInfoLog(fragmentShader, maxLength, &maxLength, &infoLog[0]);

            // We don't need the shader anymore.
            glDeleteShader(fragmentShader);
            // Either of them. Don't leak shaders.
            glDeleteShader(vertexShader);

            KB_CORE_ERROR("{0}", infoLog.data());
            KASSERT(false, "Fragment shader compilation failure!");
            return;
        }

		// Vertex and fragment shaders are successfully compiled.
		// Link the vertex and fragment shader into a shader program

		// Create an empty shader program handle
        m_ShaderRendererID = glCreateProgram();
		GLuint shaderProgram = m_ShaderRendererID;

		// Attach the vertex and fragment shaders to the shader program
        glAttachShader(shaderProgram, vertexShader);
        glAttachShader(shaderProgram, fragmentShader);

		// Link the shader program
        glLinkProgram(shaderProgram);

        // check for linking errors
		GLint isLinked = 0;
        glGetProgramiv(shaderProgram, GL_LINK_STATUS, (int*)&isLinked);
        if (isLinked == GL_FALSE) {
            GLint maxLength = 0;
            glGetProgramiv(shaderProgram, GL_INFO_LOG_LENGTH, &maxLength);

            // The maxLength includes the NULL character
            std::vector<GLchar> infoLog(maxLength);
            glGetProgramInfoLog(shaderProgram, maxLength, &maxLength, &infoLog[0]);

            // We don't need the program anymore.
            glDeleteProgram(shaderProgram);
            // Don't leak shaders either.
            glDeleteShader(vertexShader);
            glDeleteShader(fragmentShader);

            KB_CORE_ERROR("{0}", infoLog.data());
            KASSERT(false, "Shader link failure!");
            return;
        }

        // delete the shaders as they're linked into our program now and no longer necessary
        glDetachShader(shaderProgram, vertexShader);
        glDetachShader(shaderProgram, fragmentShader);
	}

	Shader::~Shader()
	{
		glDeleteProgram(m_ShaderRendererID);
	}

	void Shader::Bind() const
	{
		glUseProgram(m_ShaderRendererID);
	}

	void Shader::Unbind() const
	{
		glUseProgram(0);
	}
} // namespace Koffieboon