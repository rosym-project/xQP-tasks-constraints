## The header only interface pure abstract super class (more adjectives!) of all tasks
add_library(BaseTask INTERFACE)
target_include_directories(BaseTask INTERFACE ${CMAKE_SOURCE_DIR}/include/xQP)
target_link_libraries(BaseTask INTERFACE ${KDMI_LIBRARIES})
# this one is for the IDE but it might need cmake version 3.1
target_sources(BaseTask INTERFACE ${CMAKE_SOURCE_DIR}/include/xQP/BaseTask.hpp)

## add the rest of the tasks
add_subdirectory(CartesianVelocity)



##----------------TODO-------------
# 1. For all these targets, add export and install them
