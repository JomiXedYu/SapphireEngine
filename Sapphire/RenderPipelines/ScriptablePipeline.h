#pragma once
#include <Sapphire/MObject.h>
#include <Sapphire/ShaderProgram.h>
#include <Sapphire/Math/Matrix.h>

namespace Sapphire::RenderPipelines
{
	class ScriptablePipeline : public MObject
	{
		CORELIB_DEF_TYPE(Sapphire::RenderPipelines::ScriptablePipeline, MObject);

	public:
		void SetCommonUniform();

		void SetMVP(ShaderProgram* program, const Matrix& P, const Matrix& V, const Matrix& M);

	};
}