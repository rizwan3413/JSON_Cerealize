#############################################
# JSON_PARSER_WITH_SERIALIZE_DESERIALIZE_DATA
###########################################
add_definitions("-std=c++17")

add_executable(test test.cpp)

find_package(nlohmann_json 3.2.0 REQUIRED)

target_link_libraries(test PRIVATE nlohmann_json::nlohmann_json)