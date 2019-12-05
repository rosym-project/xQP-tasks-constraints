add_library(CartesianVelocity SHARED
            CartesianVelocity.hpp
            CartesianVelocity.cpp)

target_include_directories(CartesianVelocity PRIVATE ${CMAKE_SOURCE_DIR}/include)

target_link_libraries(CartesianVelocity BaseTask) # add model interface as well

install(FILES CartesianVelocity.hpp DESTINATION include/${PROJECT_NAME})
install(TARGETS CartesianVelocity DESTINATION lib)
