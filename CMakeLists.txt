cmake_minimum_required(VERSION 3.10)
project(SM_BCBRC)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(${CMAKE_SOURCE_DIR}/include)
include_directories(${CMAKE_SOURCE_DIR}/third_party/imgui)
include_directories(${CMAKE_SOURCE_DIR}/include/rlImGui)

link_directories(${CMAKE_SOURCE_DIR}/lib)

add_executable(SM_BCBRC 
    src/main.cpp 
    src/gui.cpp
    ${CMAKE_SOURCE_DIR}/third_party/imgui/imgui.cpp 
    ${CMAKE_SOURCE_DIR}/third_party/imgui/imgui_draw.cpp 
    ${CMAKE_SOURCE_DIR}/third_party/imgui/imgui_demo.cpp 
    ${CMAKE_SOURCE_DIR}/third_party/imgui/imgui_tables.cpp 
    ${CMAKE_SOURCE_DIR}/third_party/imgui/imgui_widgets.cpp 
    ${CMAKE_SOURCE_DIR}/include/rlImGui/rlImGui.cpp
)

file(COPY "${CMAKE_SOURCE_DIR}/resources" DESTINATION "${CMAKE_BINARY_DIR}/$<CONFIG>")

if (WIN32)
    target_link_libraries(SM_BCBRC ${CMAKE_SOURCE_DIR}/lib/raylib.lib opengl32 gdi32 winmm user32)
else()
    target_link_libraries(SM_BCBRC raylib m dl pthread GL)
endif()