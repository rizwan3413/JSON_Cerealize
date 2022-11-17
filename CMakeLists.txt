#############################################
# JSON_PARSER_WITH_SERIALIZE_DESERIALIZE_DATA
###########################################
cmake_minimum_required(VERSION 3.10)

add_definitions("-std=c++17")

add_executable(test1 cereal_lohman_jsonExample.cpp)

add_library(cereal INTERFACE)
add_library(cereal::cereal ALIAS cereal)

target_include_directories(cereal INTERFACE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)

include_directories("/home/rizwan3413/cereal/include")

find_package(nlohmann_json 3.2.0 REQUIRED)

target_link_libraries(test1 PRIVATE nlohmann_json::nlohmann_json)