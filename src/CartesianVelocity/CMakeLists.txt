add_library(CartesianVelocity SHARED
            CartesianVelocity.hpp
            CartesianVelocity.cpp)

target_link_libraries(CartesianVelocity BaseTask) # add model interface as well
