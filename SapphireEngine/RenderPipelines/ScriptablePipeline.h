#pragma once
#include <SapphireEngine/MObject.h>
#include <SapphireEngine/ShaderProgram.h>
#include <SapphireEngine/UnitType/Matrix.h>

namespace SapphireEngine::RenderPipelines
{
	class ScriptablePipeline : public MObject
	{
		CORELIB_DEF_TYPE(SapphireEngine::RenderPipelines::ScriptablePipeline, MObject);

	public:
		void SetCommonUniform();

		void SetMVP(ShaderProgram* program, const Matrix& P, const Matrix& V, const Matrix& M);

	};
}