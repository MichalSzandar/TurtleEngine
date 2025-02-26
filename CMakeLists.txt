cmake_minimum_required(VERSION 3.16)
project(MyCppApp LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Define source and include directories
set(SRC_DIR ${CMAKE_SOURCE_DIR}/src)
set(INCLUDE_DIR ${CMAKE_SOURCE_DIR}/include)
set(TESTS_DIR ${CMAKE_SOURCE_DIR}/tests)

# Find all .cpp files in src and tests directories
file(GLOB_RECURSE SRC_FILES ${SRC_DIR}/*.cpp)
file(GLOB_RECURSE TEST_FILES ${TESTS_DIR}/*.cpp)

# Include directories
include_directories(${INCLUDE_DIR})

# Find SFML
find_package(SFML 2.5 COMPONENTS graphics window system REQUIRED)

# Add executable for the main application
add_executable(${PROJECT_NAME} ${SRC_FILES})

target_link_libraries(${PROJECT_NAME} 
    imgui 
    imgui-sfml 
    imgui-file-dialog 
    sfml-graphics 
    sfml-window 
    sfml-system 
    GL 
    GLU
)


# ---- Build ImGui, ImGui-SFML, and ImGuiFileDialog ----
# ImGui
file(GLOB IMGUI_SOURCES ${INCLUDE_DIR}/imgui/*.cpp)
add_library(imgui STATIC ${IMGUI_SOURCES})
target_include_directories(imgui PUBLIC ${INCLUDE_DIR}/imgui)

# ImGui-SFML
file(GLOB IMGUI_SFML_SOURCES ${INCLUDE_DIR}/imgui-sfml/*.cpp)
add_library(imgui-sfml STATIC ${IMGUI_SFML_SOURCES})
target_include_directories(imgui-sfml PUBLIC ${INCLUDE_DIR}/imgui-sfml)
target_link_libraries(imgui-sfml PRIVATE sfml-graphics imgui)

# ImGuiFileDialog
file(GLOB IMGUI_FILE_DIALOG_SOURCES ${INCLUDE_DIR}/ImGuiFileDialog-0.6.6.1/*.cpp)
add_library(imgui-file-dialog STATIC ${IMGUI_FILE_DIALOG_SOURCES})
target_include_directories(imgui-file-dialog PUBLIC ${INCLUDE_DIR}/ImGuiFileDialog-0.6.6.1)
target_link_libraries(imgui-file-dialog PRIVATE imgui)

# Link compiled libraries to the main executable
target_link_libraries(${PROJECT_NAME} imgui imgui-sfml imgui-file-dialog)

# ---- Add Catch2-based tests ----
find_package(Catch2 3 REQUIRED)

# Add source files for GameObject, Transform, SpriteRenderer, and BoxCollider
set(TEST_SRC_FILES
    ${SRC_DIR}/GameObject.cpp
    ${SRC_DIR}/components/Transform.cpp
    ${SRC_DIR}/components/SpriteRenderer.cpp
    ${SRC_DIR}/components/BoxCollider.cpp
    ${SRC_DIR}/components/Collider.cpp
    ${SRC_DIR}/components/SphereCollider.cpp
    ${SRC_DIR}/components/Transformable.cpp
    ${SRC_DIR}/scene/Scene.cpp
    ${SRC_DIR}/utils/Maths.cpp
    # Add other necessary source files here
)

add_executable(tests ${TEST_FILES} ${TEST_SRC_FILES})
target_link_libraries(tests PRIVATE Catch2::Catch2WithMain imgui imgui-sfml imgui-file-dialog)
target_include_directories(tests PRIVATE ${INCLUDE_DIR} ${INCLUDE_DIR}/imgui ${INCLUDE_DIR}/imgui-sfml ${INCLUDE_DIR}/ImGuiFileDialog-0.6.6.1)

# Enable CTest if you want to run tests using 'ctest'
enable_testing()
add_test(NAME RunTests COMMAND tests)
