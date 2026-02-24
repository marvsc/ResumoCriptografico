/*
 * @file ResumoTest.h
 * @brief Declaração da classe ResumoTest
 * @author Marcus Chaves
 */

#ifndef TEST_PACKAGE_SRC_UNITTESTS_SRC_RESUMOTEST_H_
#define TEST_PACKAGE_SRC_UNITTESTS_SRC_RESUMOTEST_H_

#include <cppunit/TestFixture.h>

#include <cppunit/extensions/HelperMacros.h>

/*
 * @class ResumoTest
 * @brief Classe de testes unitários para o Resumo
 */
class ResumoTest : public CppUnit::TestFixture {
    // Declaração do suite de testes
    CPPUNIT_TEST_SUITE(ResumoTest);
    // Adicionando steps
    CPPUNIT_TEST(teste_construtor_basico);
    CPPUNIT_TEST(teste_construtor_com_path);
    CPPUNIT_TEST_SUITE_END();

public:

    /*
     * @brief Teste instanciando o Resumo com contrutor sem parâmetros.
     */
    void teste_construtor_basico();

    /*
     * @brief Teste instanciando o Resumo com o path completo para o arquivo
     *          a se obter o resumo criptográfico
     */
    void teste_construtor_com_path();
};

#endif /* TEST_PACKAGE_SRC_UNITTESTS_SRC_RESUMOTEST_H_ */
