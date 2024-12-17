# 🖥️ Trabalho de Algoritmos em C - Labirinto

## 📋 Objetivo
Este projeto tem como objetivo utilizar as estruturas de dados e algoritmos vistos em sala de aula para resolver o problema prático de encontrar a saída de um labirinto. O desafio consiste em implementar um algoritmo que percorra um labirinto 10x10 e encontre o caminho entre a entrada (E) e a saída (S), seguindo as regras estabelecidas.

## 📐 Descrição do Problema
O algoritmo deve:
1. Navegar pelo labirinto, que é uma matriz onde:
   - `E` representa a entrada.
   - `S` representa a saída.
   - `X` denota uma parede.
   - `0` representa u## **Resolvendo Labirintos em C: Uma Abordagem Completa**

### **Introdução**

Este projeto tem como objetivo encontrar o caminho mais curto em um labirinto de tamanho 10x10 utilizando a linguagem de programação C. O programa recebe como entrada uma representação textual do labirinto e retorna as coordenadas de cada passo do caminho encontrado, desde a entrada até a saída.

### **Estrutura de Dados**

Para representar o labirinto, utilizamos uma **matriz bidimensional de caracteres**. Cada célula da matriz representa uma posição no labirinto, podendo ser:

* **'E'**: Entrada
* **'S'**: Saída
* **'X'**: Parede
* **'0'**: Caminho livre

### **Algoritmo**

Implementamos o algoritmo de **Busca em Profundidade (DFS)** para explorar o labirinto. O DFS explora o mais profundo possível em cada ramo da árvore de busca antes de retroceder. Essa abordagem é adequada para encontrar qualquer caminho, mas não necessariamente o mais curto.

**[Observação:** Caso você tenha utilizado outro algoritmo, como BFS ou A*, adapte esta seção de acordo.]

### **Funcionamento**

1. **Leitura do labirinto:** O programa lê a representação textual do labirinto a partir de um arquivo ou da entrada padrão.
2. **Inicialização:** A matriz bidimensional é inicializada com os valores correspondentes aos caracteres do labirinto.
3. **Busca em profundidade:** A partir da célula de entrada, o algoritmo explora recursivamente as células adjacentes, marcando as visitadas e empilhando as não visitadas.
4. **Encontrando o caminho:** Quando a célula de saída é encontrada, o caminho é reconstruído a partir da pilha.
5. **Impressão do resultado:** As coordenadas de cada passo do caminho são impressas na saída padrão.

### **Código**

O código fonte principal está localizado no arquivo `labirinto.c`. Ele contém as funções para:

* Ler o labirinto
* Inicializar a matriz
* Implementar o algoritmo DFS
* Imprimir o resultado

### **Compilação e Execução**

Para compilar o programa, utilize o Makefile fornecido:

```bash
make
