
cmake_minimum_required (VERSION 3.8)

project ("SapphireTest")
set(CMAKE_CXX_STANDARD 23)

if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "MSVC")
	add_compile_options("/utf-8")
endif()

include_directories(".")
include_directories("./ThirdParty")

link_directories("ThirdParty")
link_directories("ThirdParty/glfw")

add_subdirectory("./CoreLib")
add_subdirectory("./CoreLib.Serializer")
add_subdirectory("./ThirdParty")
add_subdirectory("./Sapphire")

aux_source_directory(./ DIR_SRCS)

add_executable (${PROJECT_NAME} ${DIR_SRCS})

target_link_libraries(${PROJECT_NAME} JxCode.CoreLib)
target_link_libraries(${PROJECT_NAME} JxCode.CoreLib.Serializer)
target_link_libraries(${PROJECT_NAME} Sapphire)
target_link_libraries(${PROJECT_NAME} glad)
target_link_libraries(${PROJECT_NAME} glfw3_mt)
target_link_libraries(${PROJECT_NAME} imgui)
target_link_libraries(${PROJECT_NAME} assimp-vc143-mt)


#target_link_directories(${PROJECT_NAME} PUBLIC "include")