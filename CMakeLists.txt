cmake_minimum_required(VERSION 3.14)
project(RayTracing VERSION 1.0)

add_executable(
    App
    ./src/source/App.cpp
    ./src/source/Ray.cpp
    ./src/source/Boundary.cpp
    ./src/source/Particle.cpp
)

target_link_libraries(
    App
    -lengine
)