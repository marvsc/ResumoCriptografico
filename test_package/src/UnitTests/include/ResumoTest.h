/**
 * @file ResumoTest.h
 * @brief Declaração da classe ResumoTest
 * @author Marcus Chaves
 */

#ifndef TEST_PACKAGE_SRC_UNITTESTS_INCLUDE_RESUMOTEST_H_
#define TEST_PACKAGE_SRC_UNITTESTS_INCLUDE_RESUMOTEST_H_

#include <cppunit/TestFixture.h>

#include <cppunit/extensions/HelperMacros.h>

/**
 * @class ResumoTest
 * @brief Classe de testes unitários para o Resumo
 */
class ResumoTest : public CppUnit::TestFixture {
    // Declaração do suite de testes
    CPPUNIT_TEST_SUITE(ResumoTest);
    // Adicionando steps
    CPPUNIT_TEST(teste_construtor_basico);
    CPPUNIT_TEST(teste_construtor_com_path);
    CPPUNIT_TEST(teste_set_get_file_path);
    CPPUNIT_TEST(teste_arquivo_inexistente);
    CPPUNIT_TEST(teste_geracao_resumo);
    CPPUNIT_TEST_SUITE_END();

public:

    /**
     * @brief Método de configuração do teste, executado antes de cada teste.
     */
    void setUp() override;

    /**
     * @brief Método de limpeza do teste, executado após cada teste.
     */
    void tearDown() override;

    /**
     * @brief Teste instanciando o Resumo com contrutor sem parâmetros.
     */
    void teste_construtor_basico();

    /**
     * @brief Teste instanciando o Resumo com o path completo para o arquivo
     *          a se obter o resumo criptográfico
     */
    void teste_construtor_com_path();

    /**
     * @brief Teste para conferir se o path completo do arquivo a se obter o
     *          resumo criptográfico foi definido corretamente.
     */
    void teste_set_get_file_path();

    /**
     * @brief Teste para tentar gerar resumo criptografico de arquivo
     *          inexistente, esperando que lance exceção.
     */
    void teste_arquivo_inexistente();

    /**
     * @brief Teste para verificar a mensagem gerada na tentativa de gerar
     *         resumo criptografico de arquivo inexistente.
     */
    void teste_mensagem_arquivo_inexistente();

    /**
     * @brief Teste gerar resumo criptografico de arquivo.
     */
    void teste_geracao_resumo();
};

#endif /* TEST_PACKAGE_SRC_UNITTESTS_INCLUDE_RESUMOTEST_H_ */
