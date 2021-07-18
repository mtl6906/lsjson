project(lsjson)

cmake_minimum_required(VERSION 3.10)

add_definitions(-D_GLIBCXX_USE_CXX11_ABI=0)

include_directories(include)

link_directories(/usr/local/lib)

aux_source_directory(src/ls/json SRC)

aux_source_directory(sample SAMPLE)

add_library(lsjson SHARED  ${SRC})

add_executable(testcase ${SAMPLE} ${SRC})

target_link_libraries(testcase lsexception lscstring lsitem lscopyableitem lslogger lstime)

install(TARGETS lsjson DESTINATION lib)

install(DIRECTORY include/ls/json DESTINATION include/ls)
