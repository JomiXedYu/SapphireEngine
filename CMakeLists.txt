
cmake_minimum_required (VERSION 3.8)

project ("SapphireEngineTest")
set(CMAKE_CXX_STANDARD 20)

add_subdirectory("./include")
add_subdirectory("./src")

include_directories("./include")
include_directories("./src")

aux_source_directory(./ DIR_SRCS)

add_executable (${PROJECT_NAME} ${DIR_SRCS})

target_link_libraries(${PROJECT_NAME} Include_Src)
target_link_libraries(${PROJECT_NAME} SapphireEngine)
target_link_libraries(${PROJECT_NAME} GLAD)
target_link_directories(${PROJECT_NAME} PUBLIC src)