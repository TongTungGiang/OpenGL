#pragma once

#include <unordered_map>
#include <string>

struct ShaderSource
{
	std::string VertexSource;
	std::string FragmentSource;
};

class Shader
{
public:

	Shader(const std::string& filePath);
	~Shader();

	void Bind() const;
	void Unbind() const;

	void SetUniform4f(const std::string& name, float v0, float v1, float v2, float v3);
	void SetUniform1f(const std::string& name, float v);
	void SetUniform1i(const std::string& name, int v);

private:

	int GetUniformLocation(const std::string& name);

	unsigned int CompileShader(unsigned int type, const std::string& source);
	ShaderSource ParseShader(const std::string& file);
	unsigned int CreateShader(const std::string& vertexShader, const std::string& fragmentShader);

private:

	std::string m_FilePath;
	unsigned int m_RendererID;
	std::unordered_map<std::string, int> m_UniformLocationCache;

};

