# CMakeList.txt: проект CMake для oop_6; включите исходный код и определения,
# укажите здесь логику для конкретного проекта.
#
cmake_minimum_required (VERSION 3.8)

project ("oop_6")

# Добавьте источник в исполняемый файл этого проекта.
add_executable (oop_6 "oop_6.cpp" "oop_6.h"   "allocator.h" "containers/queue.h" "containers/stack.h")

# TODO: Добавьте тесты и целевые объекты, если это необходимо.
