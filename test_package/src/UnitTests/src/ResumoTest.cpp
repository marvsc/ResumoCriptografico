#include "../include/ResumoTest.h"

#include "Resumo.h"

#include "../include/ResumoMacros.h"

#include <filesystem>

// Registra o suite de testes
CPPUNIT_TEST_SUITE_REGISTRATION(ResumoTest);

void ResumoTest::setUp() {
    // Remove o arquivo de resultado do teste anterior, caso exista
    if (std::filesystem::exists(OUTPUT_FILE)) {
        std::filesystem::remove(OUTPUT_FILE);
    }
}

void ResumoTest::tearDown() {
    // Remove o arquivo de resultado do teste, caso exista
    if (std::filesystem::exists(OUTPUT_FILE)) {
        std::filesystem::remove(OUTPUT_FILE);
    }
}

void ResumoTest::teste_construtor_basico() {
    Resumo resumo;
    resumo.set_file_path(INPUT_FILE);

    // Escreve o resumo criptográfico SHA-512 do arquivo em disco
    resumo.write_sha512_in_file(OUTPUT_FILE);

    // Verifica se o arquivo com o resumo criptográfico foi gerado
    CPPUNIT_ASSERT_MESSAGE(CPPUNIT_PRINTF_MESSAGE("O arquivo %s deveria existir",
            OUTPUT_FILE), std::filesystem::exists(OUTPUT_FILE));
}

void ResumoTest::teste_construtor_com_path() {
    Resumo resumo(INPUT_FILE);

    // Escreve o resumo criptográfico SHA-512 do arquivo em disco
    resumo.write_sha512_in_file(OUTPUT_FILE);

    // Verifica se o arquivo com o resumo criptográfico foi gerado
    CPPUNIT_ASSERT_MESSAGE(CPPUNIT_PRINTF_MESSAGE("O arquivo %s deveria existir",
            OUTPUT_FILE), std::filesystem::exists(OUTPUT_FILE));
}

void ResumoTest::teste_set_get_file_path() {
    Resumo resumo;
    resumo.set_file_path(INPUT_FILE);

    // Verifica se o path do arquivo foi definido corretamente
    CPPUNIT_ASSERT_MESSAGE(CPPUNIT_PRINTF_MESSAGE("O path do arquivo deveria ser %s, mas foi %s",
            INPUT_FILE, resumo.get_file_path().c_str()),
            resumo.get_file_path() == INPUT_FILE);
}

void ResumoTest::teste_arquivo_inexistente() {
    Resumo resumo(INVALID_FILE);

    // Verifica se a exceção é lançada ao tentar gerar o resumo criptográfico de um arquivo inexistente
    CPPUNIT_ASSERT_THROW_MESSAGE("Deveria lançar exceção ao tentar gerar resumo de arquivo inexistente",
            resumo.write_sha512_in_file(OUTPUT_FILE), std::runtime_error);
}

void ResumoTest::teste_mensagem_arquivo_inexistente() {
    Resumo resumo(INVALID_FILE);

    try {
        resumo.write_sha512_in_file(OUTPUT_FILE);
        CPPUNIT_FAIL("Deveria lançar exceção ao tentar gerar resumo de arquivo inexistente");
    } catch (const std::runtime_error& e) {
        // Verifica se a mensagem da exceção é a esperada
        CPPUNIT_ASSERT_MESSAGE(CPPUNIT_PRINTF_MESSAGE("A mensagem da exceção deveria ser '%s', mas foi '%s'",
                INVALID_FILE_EXCEPTION_MESSAGE, e.what()),
                std::string(e.what()) == INVALID_FILE_EXCEPTION_MESSAGE);
    }
}

void ResumoTest::teste_geracao_resumo() {
    Resumo resumo(INPUT_FILE);

    // Escreve o resumo criptográfico SHA-512 do arquivo em disco
    resumo.write_sha512_in_file(OUTPUT_FILE);

    // Verifica se o arquivo com o resumo criptográfico foi gerado
    CPPUNIT_ASSERT_MESSAGE(CPPUNIT_PRINTF_MESSAGE("O arquivo %s deveria existir",
            OUTPUT_FILE), std::filesystem::exists(OUTPUT_FILE));
}
