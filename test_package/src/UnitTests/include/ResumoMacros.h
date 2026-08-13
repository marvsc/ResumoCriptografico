/*
 * @file ResumoMacros.h
 * @brief Macros necessárias para execução dos testes
 * @author Marcus Chaves
 * @date 2026-01-27
 */

#ifndef TEST_PACKAGE_SRC_UNITTESTS_INCLUDE_RESUMOMACROS_H_
#define TEST_PACKAGE_SRC_UNITTESTS_INCLUDE_RESUMOMACROS_H_

#define INPUT_FILE "doc.txt"
#define OUTPUT_FILE "resultado_teste_unitario.txt"
#define BUFFER_SIZE 256
#define INVALID_FILE "arquivo_inexistente.txt"
#define INVALID_FILE_EXCEPTION_MESSAGE "Arquivo inválido"

// Macro para criação de mensagens de erro
#define CPPUNIT_PRINTF_MESSAGE(format, ...) \
    ([&]() { \
            char buffer[BUFFER_SIZE]; \
            std::snprintf(buffer, BUFFER_SIZE, format, ##__VA_ARGS__); \
            return std::string(buffer); \
    }())


#endif /* TEST_PACKAGE_SRC_UNITTESTS_INCLUDE_RESUMOMACROS_H_ */
