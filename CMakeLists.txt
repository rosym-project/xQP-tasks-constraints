# I'm going for version 3 despit the fact that many still prefer 2.8.
# I do this for few reasons: i) V.3 has better support for
# documentation; ii) Standardized support for CXX version; iii) every
# linux distribution in the past half of decade adopts at least V.3.
cmake_minimum_required(VERSION 3.0)

# TODO double check if this policy is fine
# if(POLICY CMP0053)
#     cmake_policy(SET CMP0053 OLD)
# endif()

set(xQP_VERSION_MAJOR 0)
set(xQP_VERSION_MINOR 1)

project(xQP VERSION "${xQP_VERSION_MAJOR}.${xQP_VERSION_MINOR}")



