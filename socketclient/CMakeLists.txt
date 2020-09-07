cmake_minimum_required(VERSION 3.1)
project(socketclient)

add_executable(socketclient src/main.cpp)

message( ${CMAKE_CURRENT_SOURCE_DIR} )
message( "Fooo0000000000000--------------" )
#[[
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY /build)

set_target_properties(socket PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY_DEBUG "${CMAKE_RUNTIME_OUTPUT_DIRECTORY} /build"
    RUNTIME_OUTPUT_DIRECTORY_RELEASE "${CMAKE_RUNTIME_OUTPUT_DIRECTORY} /build"

)
]]
target_include_directories (${PROJECT_NAME} PRIVATE
                            ${PROJECT_SOURCE_DIR}/src)
install(TARGETS ${PROJECT_NAME}
        RUNTIME DESTINATION ${CMAKE_BINARY_DIR}/..)
