/*
 * @file Resumo.h
 * @brief Declaração da classe Resumo
 * @author Marcus Chaves
 * @date 2026-01-27
 */

#ifndef INCLUDE_RESUMO_H_
#define INCLUDE_RESUMO_H_

#include<string>

/*
 * @class Resumo
 * @brief Escreve em disco o resumo criptográfico de arquivo usando algoritmo SHA-512
 */
class Resumo {
public:

    /*
     * @brief Constrói a classe de forma básica
     */
    Resumo() : Resumo("") {}

    /*
     * @brief Destrói a classe.
     */
    virtual ~Resumo() {}

    /*
     * @brief Constrói a class a partir de um path para o arquivo a se obter o resumo
     *          criptográfico.
     *
     * @param[in] file Path completo para o arquivo a ser obtido o resumo criptográfico.
     */
    Resumo(const std::string& file) : file_(file) {}

    /*
     * @brief Define o path para o arquivo a se obter o resumo criptográfico.
     *
     * @param[in] file Path completo para o arquivo a se obter o resumo criptográfico.
     */
    void set_file(const std::string& file) {
        file_ = file;
    }

    /*
     * @brief Obtém o resumo criptográfico do arquivo usando o algoritmo SHA-512 e
     *          escreve em arquivo.
     *
     * @param[in] output_file Path completo para o arquivo a ser criado com o resumo
     *                          criptográfico.
     */
    void write_sha512_in_file(const std::string& output_file) const;
private:
    std::string file_; ///< @brief Path completo para o arquivo a ser obtido o resumo criptográfico.
};

#endif /* INCLUDE_RESUMO_H_ */
