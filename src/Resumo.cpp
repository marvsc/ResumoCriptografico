
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

void Resumo::write_sha512_in_file(const std::string& output_file) const {
    // Verifica se o arquivo existe e abre em modo binário
    Poco::File file(file_);
    if (!file.exists() || !file.isFile()) {
        std::runtime_error("Arquivos inválido");
    }
    std::ifstream file_stream(file.path(), std::ios::binary);

    // Define exceções para arquivo corrompido e falha na leitura
    file_stream.exceptions(std::ios::badbit | std::ios::failbit);

    // Define o algoritmo a ser utilizado
    Poco::Crypto::DigestEngine sha512(MESSAGE_DIGEST_ALGORITHM);

    // Carrega o conteúdo do arquivo para memória e fecha o arquivo
    std::string file_content((std::istreambuf_iterator<char>(file_stream)), std::istreambuf_iterator<char>());
    file_stream.close();

    // Atualiza o algoritmo com o conteúdo do arquivo e gera o resumo em memória
    sha512.update(file_content);
    const Poco::DigestEngine::Digest& digest = sha512.digest();
    std::ofstream output(output_file);
    output.exceptions(std::ios::badbit | std::ios::failbit);

    // Converte o resumo para hexadecimal e escreve em disco
    std::string digest_hex(Poco::DigestEngine::digestToHex(digest));
    output << OPENSSL_buf2hexstr(reinterpret_cast<const unsigned char*>(digest_hex.c_str()), digest_hex.size());
    output.close();
}

