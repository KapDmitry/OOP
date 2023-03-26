# CMakeList.txt: проект CMake для OOP_8; включите исходный код и определения,
# укажите здесь логику для конкретного проекта.
#
cmake_minimum_required (VERSION 3.8)

project ("OOP_8")

# Добавьте источник в исполняемый файл этого проекта.
add_executable (OOP_8 "OOP_8.cpp" "OOP_8.h" "document.hpp" "factory.hpp" "octagon.hpp" "point.hpp" "processor.hpp" "square.hpp" "subscriber.hpp" "triangle.hpp")

# TODO: Добавьте тесты и целевые объекты, если это необходимо.
