cmake_minimum_required(VERSION 3.0)

# TODO double check if this policy is fine
# if(POLICY CMP0053)
#     cmake_policy(SET CMP0053 OLD)
# endif()

set(xQP_VERSION_MAJOR 0)
set(xQP_VERSION_MINOR 1)

project(xQP VERSION "${xQP_VERSION_MAJOR}.${xQP_VERSION_MINOR}")

configure_file(${PROJECT_SOURCE_DIR}/config/version.h.in version.h)


