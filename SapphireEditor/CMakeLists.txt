
project(SapphireEditor)

file(GLOB_RECURSE SapphireEditor_SRC "*.cpp")

add_library(${PROJECT_NAME} STATIC ${SapphireEditor_SRC})