file(GLOB OBSTACLE_SOURCES "obstacles/*.cpp")

add_library(skifree_dependencies STATIC
    "player.cpp"
    "game.cpp"
    "utils.cpp"
    ${OBSTACLE_SOURCES}
)

# We need to tell this library where to look for the headers referenced in the source files
target_include_directories(skifree_dependencies PRIVATE "${CMAKE_SOURCE_DIR}/include" ${NOTHOFAGUS_INCLUDE})