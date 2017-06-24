cmake_minimum_required(VERSION 2.8.8)

macro(use_cxx11)
	if (CMAKE_VERSION VERSION_LESS "3.1")
		if (CMAKE_CXX_COMPILER_IS_GNUCXX)
			set (CMAKE_CXX_FLAGS "-std=c++11 ${CMAKE_CXX_FLAGS}")
		endif()
	else()
		set (CMAKE_CXX_STANDARD 11)
	endif()
endmacro(use_cxx11)
			

set (PROJECT_NAME_STR CmdLineParser)
project (${PROJECT_NAME_STR} C CXX)

find_package(Threads REQUIRED)
if (CMAKE_COMPILER_IS_GNUCXX)
	add_definitions(-Wall -ansi -Wno-deprecated -pthread)
endif()

set (COMMON_INCLUDES ${PROJECT_SOURCE_DIR}/include)
include_directories(${COMMON_INCLUDES})


#Gtest related
enable_testing()
set (PROJECT_TEST_NAME ${PROJECT_NAME_STR}_test)
set (GTEST_LIBS_DIR /usr/lib)

use_cxx11()

file(GLOB TEST_SRC_FILES ${PROJECT_SOURCE_DIR}/test/*.cpp)
file(GLOB SRC_FILES ${PROJECT_SOURCE_DIR}/src/*.cpp)

add_executable(${PROJECT_TEST_NAME} ${TEST_SRC_FILES} ${SRC_FILES})

add_executable(main ${SRC_FILES})

target_link_libraries(${PROJECT_TEST_NAME}
	${GTEST_LIBS_DIR}/libgtest.a
	${GTEST_LIBS_DIR}/libgtest_main.a
	)

target_link_libraries(${PROJECT_TEST_NAME} ${CMAKE_THREAD_LIBS_INIT})
add_test(test1 ${PROJECT_TEST_NAME})
