#include <Sapphire/RenderPipelines/ScriptablePipeline.h>


namespace Sapphire::RenderPipelines
{
	void ScriptablePipeline::SetCommonUniform()
	{

	}
	void ScriptablePipeline::SetMVP(ShaderProgram* program, const Matrix& P, const Matrix& V, const Matrix& M)
	{
		program->SetUniformMatrix4fv("PROJECTION", P);
		program->SetUniformMatrix4fv("VIEW", V);
		program->SetUniformMatrix4fv("MODEL", M);
	}
}