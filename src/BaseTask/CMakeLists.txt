add_library(BaseTask INTERFACE)
target_sources(BaseTask INTERFACE BaseTask.hpp)
#include_directories(${CMAKE_CURRENT_SOURCE_DIR})
install(FILES "${CMAKE_CURRENT_SOURCE_DIR}/BaseTask.hpp" DESTINATION include)




# this is pointless. Only here for QTcreator:
# add_custom_target(BaseTask.headers SOURCES BaseTask.hpp)
