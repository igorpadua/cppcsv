cmake_minimum_required(VERSION 3.5)

project(cppcsv LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(cppcsv main.cpp)

find_package(fmt)
target_link_libraries(cppcsv PRIVATE fmt::fmt-header-only)

include(GNUInstallDirs)
install(TARGETS cppcsv
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

