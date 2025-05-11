cmake_minimum_required(VERSION 3.15)

set(TARGET "OpenUsdFileFormatTemplate")

project(${TARGET} LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Define source files
set(SOURCES     
    src/OpenUsdFileFormatTemplate.cpp)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_CURRENT_SOURCE_DIR}/cmake)

# USD configuration
if(DEFINED Houdini_DIR)
    find_package(HoudiniUSD REQUIRED)
else()
    find_package(pxr REQUIRED)
endif()

find_package(OpenGL REQUIRED)
    
add_library(${TARGET} MODULE ${SOURCES})

target_link_libraries(${TARGET} ${PXR_LIBRARIES})
target_include_directories(${TARGET} PUBLIC ${PXR_INCLUDE_DIRS})

target_compile_definitions(${TARGET} PRIVATE NOMINMAX)

# Configure plugInfo.json and copy it to build directory
configure_file(
    ${CMAKE_SOURCE_DIR}/src/plugInfo.json
    ${CMAKE_BINARY_DIR}/plugInfo.json
    @ONLY
)

# Create resources directory and copy plugInfo.json there
add_custom_command(TARGET ${TARGET} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E make_directory "$<TARGET_FILE_DIR:${TARGET}>/resources"
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
        "${CMAKE_BINARY_DIR}/plugInfo.json"
        "$<TARGET_FILE_DIR:${TARGET}>/resources/plugInfo.json"
)

install(TARGETS ${TARGET}
    DESTINATION "${CMAKE_INSTALL_PREFIX}/${TARGET}"
)

install(
    FILES ${CMAKE_BINARY_DIR}/plugInfo.json
    DESTINATION "${CMAKE_INSTALL_PREFIX}/${TARGET}/resources"
)

include(CPack)

