cmake_minimum_required(VERSION 2.8)

project(ha2_aufgabe2)

add_library(lib_${PROJECT_NAME} src/mystring.cc)
target_include_directories(lib_${PROJECT_NAME} PUBLIC inc)

add_executable(app_${PROJECT_NAME} src/mystring.cc src/main.cc)
target_link_libraries(app_${PROJECT_NAME} lib_${PROJECT_NAME})
target_include_directories(app_${PROJECT_NAME} PRIVATE inc)
