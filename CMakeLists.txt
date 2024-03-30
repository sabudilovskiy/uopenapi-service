cmake_minimum_required(VERSION 3.27)
project(service)
set(CMAKE_CXX_STANDARD 20)

set(openapi-extension-userver_BUILD_UNIT_TESTS false)
set(openapi-extension-userver_BUILD_TEST_SERVICES false)

add_subdirectory(uopenapi)

include(uopenapi/CMake/CreatePart.cmake)

CreateTrivialPart(
        name "src"
        path "/src"
)

target_link_libraries(${src_module} PUBLIC openapi-extension-userver_library)
target_link_libraries(${src_module} PUBLIC userver-postgresql)

add_executable(service service/main.cpp)

target_link_libraries(service PUBLIC ${src_module})

include(uopenapi/userver/cmake/UserverTestsuite.cmake)
SET(USERVER_PYTHON "python3")
userver_testsuite_add_simple()
