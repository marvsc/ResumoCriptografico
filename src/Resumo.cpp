/*
 * Resumo.cpp
 *
 *  Created on: 11/06/2025
 *      Author: marcus
 */

#include "Resumo.h"

#include <fstream>
#include <iostream>
#include <sstream>
#include <iomanip>

#include <Poco/File.h>
#include <Poco/Path.h>

#include <Poco/Crypto/DigestEngine.h>


void Resumo::write_sha512_in_file(const std::string& output_file) const {
    Poco::File file(file_);
    if (!file.exists() || !file.isFile()) {
        std::runtime_error("Arquivos inválido");
    }
    std::ifstream file_stream(file.path(), std::ios::binary);
    file_stream.exceptions(std::ios::badbit | std::ios::failbit);
    Poco::Crypto::DigestEngine sha512("SHA512");
    std::string file_content((std::istreambuf_iterator<char>(file_stream)), std::istreambuf_iterator<char>());
    file_stream.close();
    sha512.update(file_content);
    const Poco::DigestEngine::Digest& digest = sha512.digest();
    std::ofstream output(output_file);
    output.exceptions(std::ios::badbit | std::ios::failbit);
    std::string digest_hex(Poco::DigestEngine::digestToHex(digest));
    output << OPENSSL_buf2hexstr((const unsigned char*) digest_hex.c_str(), digest_hex.size());
    output.close();
}

