cmake_minimum_required(VERSION 3.15)
project(resumo CXX)


find_package(Poco REQUIRED)

add_library(resumo src/Resumo.cpp)
target_include_directories(resumo PUBLIC include)
target_link_libraries(resumo Poco::Crypto)


set_target_properties(resumo PROPERTIES PUBLIC_HEADER "include/Resumo.h")
install(TARGETS resumo)
