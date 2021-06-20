
include_directories("${PROJECT_SOURCE_DIR}/include")
include_directories("${PROJECT_SOURCE_DIR}/src")

link_directories("${PROJECT_SOURCE_DIR}/src")

file(GLOB_RECURSE SAPPHIREENGINE_SRC "*.cpp")

add_library(SapphireEngine ${SAPPHIREENGINE_SRC})