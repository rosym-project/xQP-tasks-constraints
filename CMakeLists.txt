cmake_minimum_required(VERSION 3.0)

# TODO double check if this policy is fine
# if(POLICY CMP0053)
#     cmake_policy(SET CMP0053 OLD)
# endif()

set(xQP_VERSION_MAJOR 0)
set(xQP_VERSION_MINOR 1)

project(xQP VERSION "${xQP_VERSION_MAJOR}.${xQP_VERSION_MINOR}")

configure_file(${PROJECT_SOURCE_DIR}/config/version.h.in version.h)

find_package (Eigen3 3.3 REQUIRED)
if (EIGEN3_FOUND)
  include_directories(${EIGEN3_INCLUDE_DIRS})
else ()
  message (FATAL_ERROR "Eigen3 not found. Check the following for the fix:\n \
                        https://eigen.tuxfamily.org/dox/TopicCMakeGuide.html")
endif ()

# target_link_libraries (xxx Eigen3::Eigen)
