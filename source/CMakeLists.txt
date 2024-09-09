file(GLOB_RECURSE SOURCES *.cpp *.h)

add_library(SkiFreeDependencies ${SOURCES})
target_link_libraries(SkiFreeDependencies PUBLIC nothofagus)
target_include_directories(SkiFreeDependencies PUBLIC "${CMAKE_SOURCE_DIR}/include" ${NOTHOFAGUS_INCLUDE})

set_property(TARGET SkiFreeDependencies PROPERTY CXX_STANDARD 20)

# target_include_directories(SkiFreeDependencies PUBLIC "${CMAKE_SOURCE_DIR}/include" "${CMAKE_SOURCE_DIR}/extern/nothofagus/include")
