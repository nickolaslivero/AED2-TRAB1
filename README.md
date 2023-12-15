<h1 align= "center"> Trabalho para composição da 1ª NOTA </h1>


## 1) Introdução

Este trabalho visa comparar o desempenho de algoritmos de ordenação, incluindo BubbleSort, SelectSort, InsertSort, ShellSort, QuickSort, HeapSort e MergeSort. A implementação e análise dos algoritmos serão conduzidas em vetores de tamanhos variados, com foco na contagem de comparações, movimentações e tempo de execução. Os testes abrangerão cenários com vetores aleatórios e ordenados. O programa gerará saídas detalhadas, incluindo método de ordenação, tipo e tamanho do vetor, tempo de execução, e número de comparações e movimentações. A capacidade de imprimir os vetores antes e depois da execução será incorporada. Este estudo não apenas apresenta um código funcional, mas também oferece insights críticos sobre a escolha de algoritmos de ordenação em diferentes contextos. Os tópicos a seguir abordarão a implementação detalhada, conclusões e desafios enfrentados.

## 2) Implementação

Este trabalho envolve a criação de um programa em C++ que gera um arquivo CSV contendo informações sobre a execução de sete algoritmos de ordenação em listas de diferentes tamanhos. O código, além de produzir o CSV, inclui uma seção comentada que imprime as listas antes e depois da ordenação. Em seguida, um script em Python é utilizado para ler o CSV gerado, extrair dados relevantes e criar gráficos.

O programa em C++ realiza iterações para quatro tamanhos de lista, gerando listas aleatórias e ordenadas. Dentro de cada iteração, os sete algoritmos de ordenação (BubbleSort, SelectSort, InsertSort, ShellSort, QuickSort, HeapSort e MergeSort) são aplicados, e o tempo gasto por cada algoritmo é medido. Ao término de cada iteração, o tempo é acumulado em uma variável para posterior análise.

Em resumo, o processo compreende a geração de dados por meio do programa em C++, seguido pela leitura e análise desses dados com o script em Python, proporcionando insights valiosos sobre o desempenho relativo dos algoritmos de ordenação em diferentes contextos.

Os gráficos gerados foram:

### a)
<img src="https://live.staticflickr.com/65535/53400337649_a31bd2fb27_z.jpg"/>

### b)
<img src="https://live.staticflickr.com/65535/53400015991_d7c09a5d32_z.jpg"/>

### c)
<img src="https://live.staticflickr.com/65535/53400016001_9a00d93872_z.jpg"/>

### d)
<img src="https://live.staticflickr.com/65535/53400447610_a8916f67f7_z.jpg"/>

### e)
<img src="https://live.staticflickr.com/65535/53400016011_55013524c1_z.jpg"/>

### f)
<img src="https://live.staticflickr.com/65535/53399085687_876cb8a64d_z.jpg"/>

## 3) Conclusão
A análise dos gráficos revela insights significativos sobre o desempenho dos algoritmos de ordenação. Notavelmente:

a) O Bubble Sort demonstrou eficácia ao lidar com arrays de todos os tamanhos, entretanto, seus custos temporais foram os mais elevados em comparação com os demais algoritmos.

b) Para os três primeiros tamanhos de arrays, destacaram-se os algoritmos Insertion Sort e Heap Sort como os mais eficazes, proporcionando resultados notáveis em termos de tempo de execução.

c) Intrigantemente, ao enfrentar arrays no maior tamanho (100000), os algoritmos Insertion, Heap e Merge não foram capazes de concluir os testes. Em contrapartida, os algoritmos Bubble, Selection e Quick demonstraram sucesso ao completar todos os quatro testes, revelando sua robustez em lidar com conjuntos de dados mais extensos.

Essas observações ressaltam a importância de considerar não apenas a eficácia, mas também a eficiência temporal dos algoritmos de ordenação, especialmente em cenários de grandes conjuntos de dados. Este insight tem implicações cruciais na escolha apropriada de algoritmos para otimização de desempenho em contextos específicos.

## 👩🏽🧔🏻‍♀️) Dupla
| [<img src="https://avatars.githubusercontent.com/u/93674466?v=4" width=115><br><sub>Manuela Bastos</sub>](https://github.com/manupbastos) | [<img src="https://avatars.githubusercontent.com/u/90870510?v=4" width=115><br><sub>Nickolas Livero</sub>](https://github.com/nickolaslivero)| 
| :---: |  :---:|
