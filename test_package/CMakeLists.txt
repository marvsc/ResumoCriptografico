cmake_minimum_required(VERSION 3.15)
project(PackageTest CXX)

find_package(resumo CONFIG REQUIRED)
find_package(cppunit CONFIG REQUIRED)

add_executable(example src/example.cpp)
target_link_libraries(example resumo::resumo)

add_executable(teste stc/teste.cpp
                    src/UnitTests/src/ResumoTest.cpp)
target_link_libraries(teste assinaturadigital::assinaturadigital cppunit::cppunit)

configure_file(${CMAKE_CURRENT_SOURCE_DIR}/resources/arquivos/doc.txt
${CMAKE_CURRENT_BINARY_DIR}/doc.txt
COPYONLY)
