# Competição de Ordenação — O Desafio dos Milissegundos

**Autor:** Vitor Emanoel Espíndola Alves

## 1. Objetivo

Implementar um algoritmo de ordenação em C capaz de organizar uma grande quantidade de números inteiros.

## 2. Algoritmo utilizado

Foi escolhido o **Merge Sort**, que utiliza a estratégia de divisão e conquista:

- Divide o vetor em partes menores.
- Ordena essas partes individualmente.
- Intercala as partes até formar um único vetor ordenado.

A complexidade de tempo é O(N log N), e o espaço auxiliar utilizado é O(N).

## 3. Medição de desempenho

A medição usa a função `clock()` da biblioteca `time.h`. A leitura do arquivo e a alocação de memória acontecem antes da contagem; o tempo registrado corresponde somente à execução do Merge Sort.

## 4. Resultados obtidos

- Quantidade de números: 10.000.000
- Menor número: 1
- Maior número: 2.500.000
- Algoritmo: Merge Sort
- Ordenação correta: SIM
- Preservação dos elementos: SIM
- Preservação da soma: SIM
- Tempo registrado: 0,211 segundo

## 5. Verificação dos resultados

Após a ordenação, foram feitas estas verificações:

1. Conferência da ordem crescente dos números.
2. Comparação dos elementos ordenados com uma cópia da lista original, também ordenada.
3. Comparação da soma dos elementos antes e depois da ordenação.

## 6. Como compilar

É necessário ter o GCC instalado. No terminal, dentro da pasta que contém `main.c`, execute:

```bash
gcc -O2 -Wall -Wextra main.c -o ordenacao.exe
```

## 7. Como executar

No Windows, execute:

```powershell
.\ordenacao.exe
```

## 8. Arquivos do projeto

```text
Pasta de trabalho/
├── listaOdenada.txt
└── desafio-ordenacao/
    ├── README.MD
    └── main.c
```

O programa procura `listaOdenada.txt` na pasta imediatamente acima daquela que contém `main.c`. Esse arquivo contém 10 milhões de números e não foi incluído no repositório por ser um conjunto de dados grande. O executável `ordenacao.exe` é gerado ao compilar e também não faz parte do repositório.
