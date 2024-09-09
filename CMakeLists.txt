cmake_minimum_required(VERSION 3.20)
set(CMAKE_LEGACY_CYGWIN_WIN32 OFF)

project(SkiFree CXX)

option(NOTHOFAGUS_INSTALL "Disabling installation of Nothofagus" OFF)

add_subdirectory("third_party/nothofagus")
# add_subdirectory(third_party)
add_subdirectory(source)


add_executable(SkiFree "main.cpp")
set_property(TARGET SkiFree PROPERTY CXX_STANDARD 20)
target_include_directories(SkiFree PRIVATE ${NOTHOFAGUS_INCLUDE} include)
# Here we bind the library and its headers
target_link_libraries(${PROJECT_NAME} SkiFreeDependencies nothofagus)
