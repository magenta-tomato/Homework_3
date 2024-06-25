cmake_minimum_required(VERSION 3.10)

# тесты к библиотеке

# проект
project( 
	tests_lib 
	VERSION 
	${PROJECT_VERSION}
)

# исполняемый файл и исходники
add_executable( 
	tests_lib 
	tests_lib.cpp 
)

# исполняемый файл использует библиотеку lib
target_link_libraries( 
	tests_lib 
	lib 
)

# исходники используют заголовок библиотеки lib
target_include_directories(
	tests_lib
    PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/../lib
)

# директория бинарника библиотеки 
target_include_directories(
	tests_lib
	PRIVATE
	${CMAKE_CURRENT_BINARY_DIR}
)

# исполняемый файл использует библиотеку BOOST
find_package( 
	Boost 
	COMPONENTS 
	unit_test_framework 
	REQUIRED
)
target_link_libraries( 
	tests_lib 
	${Boost_LIBRARIES} 
)

# исходники используют заголовки библиотеки BOOST
target_include_directories(
    tests_lib
    PRIVATE
    ${Boost_INCLUDE_DIR}
)
set_target_properties(
	tests_lib PROPERTIES
    COMPILE_DEFINITIONS BOOST_TEST_DYN_LINK
)

# поддержка станадарта языка
set_target_properties(
    tests_lib PROPERTIES
    CXX_STANDARD 14
    CXX_STANDARD_REQUIRED ON
)

add_test( 
	tests_lib 
	tests_lib
)
