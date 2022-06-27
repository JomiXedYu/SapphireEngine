
#message("root: ${PROJECT_SOURCE_DIR}")

#include_directories("${PROJECT_SOURCE_DIR}")
#link_directories("${PROJECT_SOURCE_DIR}/ThirdParty/glfw/libvc2019")

file(GLOB_RECURSE Sapphire_SRC "*.cpp")
add_library(Sapphire ${Sapphire_SRC})