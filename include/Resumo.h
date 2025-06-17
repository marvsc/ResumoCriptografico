/*
 * Resumo.h
 *
 *  Created on: 11/06/2025
 *      Author: marcus
 */

#ifndef INCLUDE_RESUMO_H_
#define INCLUDE_RESUMO_H_

#include<string>

class Resumo {
public:
    Resumo() : Resumo("") {}
    virtual ~Resumo() {}
    Resumo(const std::string& file) : file_(file) {}
    void set_file(const std::string& file) {
        file_ = file;
    }
    void write_sha512_in_file(const std::string& output_file) const;
private:
    std::string file_;
};

#endif /* INCLUDE_RESUMO_H_ */
