project(service)
cmake_minimum_required(VERSION 3.27)
set(CMAKE_CXX_STANDARD 20)
set(USERVER_TESTSUITE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/uopenapi/userver/testsuite")
set(USERVER_PYTHON "${CMAKE_BINARY_DIR}/venv-userver-cmake/bin/python")

include(CTest)
enable_testing()

add_subdirectory(uopenapi)
#
CreateTrivialExe(
        name "check_service"
        path "/main"
)


target_link_libraries(${check_service_exe} PUBLIC openapi-extension-userver_library)
userver_testsuite_add_simple()

#include(GNUInstallDirs)
#file(GLOB CONFIGS_FILES ${CMAKE_CURRENT_SOURCE_DIR}/configs/*.yaml ${CMAKE_CURRENT_SOURCE_DIR}/configs/*.json)

#install(TARGETS ${test_service_exe} DESTINATION ${CMAKE_INSTALL_BINDIR} COMPONENT ${test_service_exe})
#install(FILES ${CONFIGS_FILES} DESTINATION ${CMAKE_INSTALL_SYSCONFDIR}/${test_service_exe} COMPONENT ${test_service_exe})

unset(check_service_exe)