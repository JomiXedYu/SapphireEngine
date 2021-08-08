
#message("root: ${PROJECT_SOURCE_DIR}")

#include_directories("${PROJECT_SOURCE_DIR}")
#link_directories("${PROJECT_SOURCE_DIR}/ThirdParty/glfw/libvc2019")
file(GLOB_RECURSE SAPPHIREENGINE_SRC "*.cpp")
add_library(SapphireEngine ${SAPPHIREENGINE_SRC})