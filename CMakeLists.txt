cmake_minimum_required(VERSION 3.15)
project(resumo CXX)


find_package(Poco REQUIRED COMPONENTS Crypto)

add_library(resumo src/Resumo.cpp)
target_include_directories(resumo PUBLIC include)

target_link_libraries(resumo PUBLIC Poco::Crypto)

target_compile_features(resumo PUBLIC cxx_std_17)

set_target_properties(resumo PROPERTIES PUBLIC_HEADER "include/Resumo.h")
install(TARGETS resumo
    EXPORT resumoTargets
    ARCHIVE DESTINATION lib
    LIBRARY DESTINATION lib
    RUNTIME DESTINATION bin
    PUBLIC_HEADER DESTINATION include)

