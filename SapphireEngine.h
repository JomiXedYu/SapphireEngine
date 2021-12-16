// SapphireEngine.h: 标准系统包含文件的包含文件
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

#include <SapphireEngine/_include.h>

#include <SapphireEngine/Private/RenderInterface.h>
#include <SapphireEngine/Private/InputInterface.h>
#include <SapphireEngine/Private/SystemInterface.h>
#include <SapphireEngine/Private/ResourceInterface.h>

#include <SapphireEngine/Components/MeshRenderer.h>
#include <SapphireEngine/Components/Camera.h>
#include <SapphireEngine/Components/FreeCamera.h>
#include <SapphireEngine/Assets/CubeMap.h>
#include <SapphireEngine/PBRPipeline/PBRTexture.h>
#include <SapphireEngine/PBRPipeline/PBRRenderer.h>
#include <SapphireEngine/Assets/ScriptableAsset.h>
#include <SapphireEngine/Utility/MeshBuilder.h>

#include <SapphireEngine/RenderPipelines/ScriptablePipeline.h>
// TODO: 在此处引用程序需要的其他标头。
