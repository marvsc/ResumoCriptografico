/*
 * ResumoTest.cpp
 *
 *  Created on: 24 de fev. de 2026
 *      Author: marcus.chaves
 */

#include "../include/ResumoTest.h"

#include "Resumo.h"

#include "../include/ResumoMacros.h"

#include <filesystem>

// Registra o suite de testes
CPPUNIT_TEST_SUITE_REGISTRATION(ResumoTest);

void ResumoTest::teste_construtor_basico() {
    Resumo resumo;
    resumo.set_file(INPUT_FILE);

    // Escreve o resumo criptográfico SHA-512 do arquivo em disco
    resumo.write_sha512_in_file(OUTPUT_FILE);
    std::string message("O arquivo ");

    // Verifica se o arquivo com o resumo criptográfico foi gerado
    CPPUNIT_ASSERT_MESSAGE(message.append(OUTPUT_FILE).append(" deveria existir").c_str(),
            std::filesystem::exists(OUTPUT_FILE));
}

void ResumoTest::teste_construtor_com_path() {
    Resumo resumo(INPUT_FILE);

    // Escreve o resumo criptográfico SHA-512 do arquivo em disco
    resumo.write_sha512_in_file(OUTPUT_FILE);
    std::string message("O arquivo ");

    // Verifica se o arquivo com o resumo criptográfico foi gerado
    CPPUNIT_ASSERT_MESSAGE(message.append(OUTPUT_FILE).append(" deveria existir").c_str(),
            std::filesystem::exists(OUTPUT_FILE));
}
