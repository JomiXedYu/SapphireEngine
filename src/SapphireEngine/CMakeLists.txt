
include_directories("${PROJECT_SOURCE_DIR}/include")

link_directories("${PROJECT_SOURCE_DIR}/include")

file(GLOB_RECURSE SAPPHIREENGINE_SRC "*.cpp")

add_library(SapphireEngine ${SAPPHIREENGINE_SRC})