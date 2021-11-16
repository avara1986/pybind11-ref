cmake_minimum_required(VERSION 3.20)
project(cpp_examples)

add_subdirectory(pybind11)

#find_package(pybind11 REQUIRED)
find_package(PythonLibs REQUIRED)
#include_directories(${PYTHON_INCLUDE_DIRS})
#add_compile_options(-std=c++11 -fPIC -fms-extensions)
#add_compile_options(-DBIT64 -DPAL_STDCPP_COMPAT -DPLATFORM_UNIX -DUNICODE -DLINUX)
#add_link_options(-ldl)
# EXAMPLE_VERSION_INFO is defined by setup.py and passed into the C++ code as a
# define (VERSION_INFO) here.
#target_compile_definitions(cpp_examples
#        PRIVATE VERSION_INFO=${EXAMPLE_VERSION_INFO})
#pybind11_add_module(cpp_examples ${SOURCES}
#        src/main.cpp
#        )
add_executable(cpp_examples src/main.cpp)
target_link_libraries(cpp_examples PRIVATE pybind11::embed)

