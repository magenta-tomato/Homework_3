cmake_minimum_required(VERSION 3.10)

# библиотека

# проект
project( 
	library 
	VERSION 
	${PROJECT_VERSION}
)

# библиотека и исходники
add_library( lib STATIC customVector.cpp customVector.h allocators.cpp allocators.h  )

# исходники используют файл version.h
target_include_directories(
    lib 
    PRIVATE
    ${CMAKE_CURRENT_BINARY_DIR}
)

# поддержка стандарта языка
set_target_properties(
    lib PROPERTIES
    CXX_STANDARD 14
    CXX_STANDARD_REQUIRED ON
)