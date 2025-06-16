cmake_minimum_required(VERSION 3.15)
project(resumo CXX)

find_package(Poco REQUIRED)

add_executable(resumo src/Resumo.cpp src/main.cpp)

target_link_libraries(resumo Poco::Crypto)

install(TARGETS resumo DESTINATION "."
        RUNTIME DESTINATION bin
        ARCHIVE DESTINATION lib
        LIBRARY DESTINATION lib
        )
