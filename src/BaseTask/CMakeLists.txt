add_library(BaseTask INTERFACE)

install(FILES "${CMAKE_CURRENT_SOURCE_DIR}/BaseTask.hpp" DESTINATION include)

target_include_directories(BaseTask INTERFACE "${CMAKE_CURRENT_SOURCE_DIR}")


# this could be needed for some IDE e.g., QTCreator
# target_sources(BaseTask INTERFACE "${CMAKE_CURRENT_SOURCE_DIR}/BaseTask.hpp")
