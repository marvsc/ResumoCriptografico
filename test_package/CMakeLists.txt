cmake_minimum_required(VERSION 3.15)
project(PackageTest CXX)

find_package(resumo CONFIG REQUIRED)
find_package(cppunit CONFIG REQUIRED)
find_package(Poco CONFIG REQUIRED COMPONENTS Foundation Crypto)

add_executable(example src/example.cpp)
target_link_libraries(example resumo::resumo Poco::Foundation Poco::Crypto)

add_executable(teste src/teste.cpp
                    src/UnitTests/src/ResumoTest.cpp)
target_link_libraries(teste resumo::resumo cppunit::cppunit Poco::Foundation Poco::Crypto)

configure_file(${CMAKE_CURRENT_SOURCE_DIR}/resources/arquivos/doc.txt
${CMAKE_CURRENT_BINARY_DIR}/doc.txt
COPYONLY)
