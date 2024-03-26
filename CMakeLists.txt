cmake_minimum_required(VERSION 3.27)
project(service)
set(CMAKE_CXX_STANDARD 20)

set(openapi-extension-userver_BUILD_UNIT_TESTS false)
set(openapi-extension-userver_BUILD_TEST_SERVICES false)

add_subdirectory(uopenapi)

add_executable(service main/main.cpp)

target_link_libraries(service PUBLIC openapi-extension-userver_library)

#uservers workarounds
include(uopenapi/userver/cmake/UserverTestsuite.cmake)
SET(USERVER_PYTHON "python3")
userver_testsuite_add_simple()

unset(check_service_exe)