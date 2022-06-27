// Sapphire.h: 标准系统包含文件的包含文件
// 或项目特定的包含文件。

#pragma once

#include <iostream>

#include <ThirdParty/glad/glad.h>
#include <ThirdParty/glfw/include/GLFW/glfw3.h>

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <format>
#include <functional>
#include <array>

#include <CoreLib/File.h>
#include <CoreLib/DebugTool.hpp>
#include <CoreLib/CommonException.h>
#include <CoreLib.Serializer/JsonSerializer.h>

#include <Sapphire/_include.h>

#include <Sapphire/Private/RenderInterface.h>
#include <Sapphire/Private/InputInterface.h>
#include <Sapphire/Private/SystemInterface.h>
#include <Sapphire/Private/ResourceInterface.h>

#include <Sapphire/Components/MeshRenderer.h>
#include <Sapphire/Components/Camera.h>
#include <Sapphire/Components/FreeCamera.h>
#include <Sapphire/Assets/CubeMap.h>
#include <Sapphire/PBRPipeline/PBRTexture.h>
#include <Sapphire/PBRPipeline/PBRRenderer.h>
#include <Sapphire/Assets/ScriptableAsset.h>
#include <Sapphire/Utility/MeshBuilder.h>

#include <Sapphire/RenderPipelines/ScriptablePipeline.h>
// TODO: 在此处引用程序需要的其他标头。
#include <imgui.h>
#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>