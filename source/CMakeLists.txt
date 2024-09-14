file(GLOB OBSTACLE_SOURCES "obstacles/*.cpp")
file(GLOB_RECURSE HEADERS "${CMAKE_SOURCE_DIR}/include/*.h")

add_library(skifree_dependencies STATIC
    "player.cpp"
    "game.cpp"
    "utils.cpp"
    "audio.cpp"
    ${OBSTACLE_SOURCES}
)

set_property(TARGET skifree_dependencies PROPERTY CXX_STANDARD 20)
# We need to tell this library where to look for the headers referenced in the source files
target_include_directories(skifree_dependencies PRIVATE "${CMAKE_SOURCE_DIR}/include" ${NOTHOFAGUS_INCLUDE} ${RUSTY_AUDIO_INCLUDE})