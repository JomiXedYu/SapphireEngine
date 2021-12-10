
cmake_minimum_required (VERSION 3.8)

project ("SapphireEngineTest")
set(CMAKE_CXX_STANDARD 20)

if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "MSVC")
	add_compile_options("/utf-8")
endif()

include_directories(".")
include_directories("./ThirdParty")

link_directories("ThirdParty/glfw/libvc2019")
link_directories("ThirdParty")

add_subdirectory("./CoreLib")
add_subdirectory("./CoreLib.Serializer")
add_subdirectory("./ThirdParty")
add_subdirectory("./SapphireEngine")

aux_source_directory(./ DIR_SRCS)

add_executable (${PROJECT_NAME} ${DIR_SRCS})
#add_executable (${PROJECT_NAME} "dd.cpp")

target_link_libraries(${PROJECT_NAME} JxCode.CoreLib)
target_link_libraries(${PROJECT_NAME} JxCode.CoreLib.Serializer)
target_link_libraries(${PROJECT_NAME} SapphireEngine)
target_link_libraries(${PROJECT_NAME} glad)
target_link_libraries(${PROJECT_NAME} glfw3)
target_link_libraries(${PROJECT_NAME} assimp-vc142-mt)


#target_link_directories(${PROJECT_NAME} PUBLIC "include")