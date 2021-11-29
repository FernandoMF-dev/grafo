cmake_minimum_required(VERSION 3.20)
project(grafo C)

set(CMAKE_C_STANDARD 99)

add_executable(grafo main.c ControleArquivoGrafo.c headers/ControleArquivoGrafo.h Cidade.c headers/Cidade.h StringUtils.c headers/StringUtils.h ArrayUtils.c headers/ArrayUtils.h RandomUtils.c headers/RandomUtils.h Grafo.c headers/Grafo.h)

target_link_libraries(grafo m)