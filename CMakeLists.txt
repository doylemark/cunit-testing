cmake_minimum_required(VERSION 3.21)

set(PROJECT_NAME testing)
set(CUNIT_PATH /opt/homebrew/Cellar/cunit/2.1-3)

project(${PROJECT_NAME} C)

set(CMAKE_C_STANDARD 99)

# compiler flags
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra -Werror --std=c99 \
    -Wno-unused-local-typedefs -target x86_64-apple-darwin")

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} \
    -DCHECK_RESULT_USED=\"__attribute__ ((warn_unused_result))\"")

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -D_GNU_SOURCE -D_FILE_OFFSET_BITS=64")

set(SRC
    src/avg_and_max.c
    tests.c)

set(HDR
    src/avg_and_max.h)

set(SOURCE_FILES ${SRC} ${HDR})

find_library(CUNIT libcunit.a ${CUNIT_PATH}/lib)
include_directories(${CUNIT_PATH}/include/CUnit .)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})
target_link_libraries(${PROJECT_NAME} PUBLIC ${CUNIT})