#pragma once
#include <string>
#include <GL\glew.h>
#include "Transform.h"


class Shader
{
public:
	Shader(const std::string& filename);

	void Bind();
	void Update(const Transform& transform, const Camera& camera);

	std::string LoadShader(const std::string& filename);
	void CheckShaderError(GLuint shader, GLuint flag, bool isProgram, const std::string& errorMessage);
	GLuint CreateShader(const std::string& text, unsigned int type);

	~Shader();
protected:
private:
	static const int NUM_SHADERS = 2;
	Shader(const Shader& other) {}
	void operator= (const Shader& other) {}

	enum
	{
		TRANSFORM_U,

		NUM_UNIFORMS
	};	

	GLuint m_Program;
	GLuint m_Shaders[NUM_SHADERS];
	GLuint unforms[NUM_UNIFORMS];
};

