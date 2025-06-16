#include "Resumo.h"

#include<unistd.h>

#include<string>

int main(const int argc, char* const argv[]) {
    int opt;
    std::string input_file("");
    std::string output_file("");
    while ((opt = getopt(argc, argv, "i:o:")) != -1) {
        switch (opt) {
        case 'i':
            input_file = optarg;
            break;
        case 'o':
            output_file = optarg;
            break;
        case '?':
            std::printf("Opção inválida: %c\n", opt);
            break;
        default:
            std::printf("Erro no parser: %c\n", opt);
            break;
        }
    }
    if (optind < argc) {
        for (int i = optind; i < argc; i++) {
            std::printf("Argumento inválido: %s\n", argv[i]);
        }
    }
    if (input_file.empty()) {
        std::printf("Arquivo de entrada inválido\n");
        return EXIT_FAILURE;
    }
    if (output_file.empty()) {
        std::printf("Arquivo de saída inválido\n");
        return EXIT_FAILURE;
    }
    try {
        Resumo resume(input_file);
        resume.write_sha512_in_file(output_file);
    } catch (std::exception& e) {
        std::printf("Erro de execução: %s\n", e.what());
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}
