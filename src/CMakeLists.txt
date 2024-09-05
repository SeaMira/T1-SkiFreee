file(GLOB SOURCES *.cpp *.h)

add_library(SkiFreeDependencies ${SOURCES})
target_link_libraries(SkiFreeDependencies PUBLIC nothofagus)
target_include_directories(SkiFreeDependencies PUBLIC "${CMAKE_SOURCE_DIR}/include" ${NOTHOFAGUS_INCLUDE})

