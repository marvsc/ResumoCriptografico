
#include "Resumo.h"

#include <fstream>
#include <iostream>
#include <sstream>
#include <iomanip>

#include <Poco/File.h>
#include <Poco/Path.h>

#include <Poco/Crypto/DigestEngine.h>

// Algoritmo a ser usado para obter o resumo criptográfico.
#define MESSAGE_DIGEST_ALGORITHM "SHA512"
#define BUFFER_SIZE 8192

void Resumo::write_sha512_in_file(const std::string& output_file) const {
    // Verifica se o arquivo existe e abre em modo binário
    Poco::File file(file_);
    if (!file.exists() || !file.isFile()) {
        throw std::runtime_error("Arquivo inválido");
    }
    std::ifstream file_stream(file.path(), std::ios::binary);
    if (!file_stream.is_open()) {
        throw std::runtime_error("Erro ao abrir o arquivo");
    }

    // Define exceções para arquivo corrompido e falha na leitura
    file_stream.exceptions(std::ios::badbit);

    // Define o algoritmo a ser utilizado
    Poco::Crypto::DigestEngine sha512(MESSAGE_DIGEST_ALGORITHM);

    // Atualiza o algoritmo com o conteúdo do arquivo lendo em blocos
    // para evitar carregar arquivos grandes inteiros em memória.
    std::vector<char> buffer(BUFFER_SIZE);
    std::streamsize read_bytes;
    while (file_stream.read(buffer.data(), static_cast<std::streamsize>(BUFFER_SIZE)) ||
            (read_bytes = file_stream.gcount()) > 0) {
        if (read_bytes > 0) {

            // Atualiza o algoritmo com os bytes lidos
            sha512.update(buffer.data(), static_cast<std::size_t>(read_bytes));
        }
    }
    file_stream.close();
    const Poco::DigestEngine::Digest& digest = sha512.digest();

    // Converte o digest para uma string hexadecimal
    std::string digest_hex(Poco::DigestEngine::digestToHex(digest));
    std::ofstream output(output_file, std::ios::binary | std::ios::trunc);
    if (!output.is_open()) {
        throw std::runtime_error("Erro ao abrir o arquivo de saída");
    }

    // Escrever exatamente os bytes da string hexadecimal
    output.write(digest_hex.data(), static_cast<std::streamsize>(digest_hex.size()));
    output.close();
}

