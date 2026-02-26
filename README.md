# 🔏 ResumoCriptografico

> Biblioteca para gerar resumo criptográfico de arquivo.

## 📋 Tabela de Conteúdos
- [Sobre](#-sobre)
- [Funcionalidades](#-funcionalidades)
- [Pré-requisitos gerais](#%EF%B8%8F-pr%C3%A9-requisitos-gerais)
- [Instalação](#-instalação)
    - [Pacote](#-Pacote)
    - [CMake](#-cmake)
    - [Conan](#-conan)
        - [Pré-requisitos](#%EF%B8%8F-pr%C3%A9-requisitos)
        - [Passos para a compilação](#-passos-para-a-compilação)
- [Pipeline](#-pipeline)
- [Como Usar](#-como-usar)

## 📖 Sobre

Gera resumo criptográfico SHA-512 de arquivo em disco.

## ✨ Funcionalidades

- [x] Gera resumo criptográfico SHA-512 de arquivo em disco.

## 🛠️ Pré-requisitos gerais

* C++17 ou superior.

## 🚀 Instalação

### 📦 Pacote
1. Baixar o pacote:

    ```bash
    wget https://github.com/marvsc/ResumoCriptografico/releases/download/v<versão>/libresumo-v<versão>.tgz
    ```

2. Descompactar:

    ```bash
    tar zxvf libresumo-v<versão>.tgz -C <diretório a descompactar>
    ```

### 🛆 CMake

1. Clonar o projeto:

    ```bash
    git clone git@github.com:marvsc/ResumoCriptografico.git
    ```

2. Criar o diretório build:

    ```bash
    mkdir build
    ```

3. Instalar os geradores:

    ```bash
    conan install . --build=missing
    ```

4. Gerar Makefile:

    ```bash
    cmake -DCMAKE_TOOLCHAIN_FILE=build/Release/generators/conan_toolchain.cmake -S . -B build
    ```

5. Compilar projeto:

    ```bash
    make -C build/
    ```

> [!NOTE]
> O comando acima irá compilar o projeto e gerar o artefato build/libresumo.a

### 💪🏻 Conan

#### 🛠️ Pré-requisitos

* Conan na versão 2.25.2

#### 👣 Passos para a compilação

1. Clonar o projeto:

    ```bash
    git clone git@github.com:marvsc/ResumoCriptografico.git
    ```

2. Criar o projeto utilizando conan:

    ```bash
    conan create . --build=missing
    ```

> [!NOTE]
> O comando acima vai baixar e compilar todas as dependencias, compilar o projeto e executar os testes que são compostos de 2 executáveis. Um faz os testes unitários e o outro Obtém o resumo criptografico do arquivo /test_package/resources/arquivos/doc.txt e escreve no arquivo /test_package/resources/arquivos/resultado.txt. O resumo criptográfico é gerado utilizando algoritmo SHA-512.

## Pipeline
Ao criar uma tag, duas pipelines são disparadas via github para gerar a release automaticamente e para publicar o pacote no repositório do conan (cloudsmith).

## ✅ Como usar

Adicionar a lib ao programa durante a compilação com o comando -lresumo.
