cmake_minimum_required(VERSION 3.0)


project(test)

add_executable(test main.cpp
D:/Programozas/small_prog/C++/Lib_resources/imgui/imgui.cpp
D:/Programozas/small_prog/C++/Lib_resources/imgui/imgui_demo.cpp
D:/Programozas/small_prog/C++/Lib_resources/imgui/imgui_draw.cpp
D:/Programozas/small_prog/C++/Lib_resources/imgui/imgui_tables.cpp
D:/Programozas/small_prog/C++/Lib_resources/imgui/imgui_widgets.cpp
D:/Programozas/small_prog/C++/Lib_resources/imgui/backends/imgui_impl_glfw.cpp
D:/Programozas/small_prog/C++/Lib_resources/imgui/backends/imgui_impl_opengl3.cpp
)
target_include_directories(test PUBLIC
D:/Programozas/small_prog/C++/Lib_resources/imgui
D:/Programozas/small_prog/C++/Lib_resources/imgui/backends
D:/Programozas/small_prog/C++/Lib_resources/glfw-3.3.6.bin.WIN64/include
D:/Programozas/small_prog/C++/Lib_resources/glew-2.1.0/include
)


target_link_libraries(test PUBLIC
glew32.lib
glfw3.lib
opengl32.lib
)

target_link_directories(test PUBLIC
D:/Programozas/small_prog/C++/Lib_resources/glew-2.1.0/lib/Release/x64
D:/Programozas/small_prog/C++/Lib_resources/glfw-3.3.6.bin.WIN64/lib-vc2022
)