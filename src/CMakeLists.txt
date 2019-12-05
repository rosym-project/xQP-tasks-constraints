## The header only interface pure abstract super class (more adjectives!) of all tasks
add_library(BaseTask INTERFACE)
target_include_directories(BaseTask INTERFACE ${CMAKE_SOURCE_DIR}/include/xQP)
# this one is for the IDE
target_sources(BaseTask INTERFACE ${CMAKE_SOURCE_DIR}/include/xQP/BaseTask.hpp)

## add the rest of the tasks
add_subdirectory(CartesianVelocity)
