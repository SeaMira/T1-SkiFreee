cmake_minimum_required(VERSION 3.20)

project(skifree_project CXX)

option(NOTHOFAGUS_INSTALL "Disabling installation of Nothofagus" OFF)
option(RUSTY_AUDIO_INSTALL "Disabling installation of RustyAudio" OFF)
add_subdirectory("third_party/nothofagus")
add_subdirectory("third_party/rusty_audio")
add_subdirectory(source)

# file(GLOB_RECURSE HEADERS "source/*.h" "include/*.h")
set(INCLUDES "include")

add_executable(skifree
    "skifree.cpp"
)
set_property(TARGET skifree PROPERTY CXX_STANDARD 20)
target_link_libraries(skifree PRIVATE nothofagus rusty_audio skifree_dependencies)
target_include_directories(skifree PRIVATE ${NOTHOFAGUS_INCLUDE} ${RUSTY_AUDIO_INCLUDE} ${INCLUDES})