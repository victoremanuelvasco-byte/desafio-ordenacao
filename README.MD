# Competição de Ordenação — O Desafio dos Milissegundos

## 1. Objetivo

O objetivo deste projeto é implementar um algoritmo de ordenação em linguagem C, capaz de organizar uma grande quantidade de números inteiros no menor tempo possível.

Para os testes, foi utilizado o arquivo `listaOdenada.txt`, contendo 10 milhões de números.

## 2. Algoritmo utilizado

Foi escolhido o algoritmo **Merge Sort**, que utiliza a estratégia de divisão e conquista.

Seu funcionamento acontece em três etapas:
- Divide o vetor em partes menores.
- Ordena essas partes individualmente.
- Intercala as partes até formar um único vetor ordenado.

A complexidade de tempo do algoritmo é O(N log N), e sua complexidade de espaço auxiliar é O(N).

## 3. Medição de desempenho

A medição foi realizada utilizando a função `clock()` da biblioteca `time.h`.

A leitura do arquivo e a alocação de memória acontecem antes do início da contagem. Dessa forma, o tempo registrado corresponde somente à execução do algoritmo de ordenação.

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

Após a ordenação, foram realizadas três verificações:

1. Conferência da ordem crescente dos números.
2. Comparação dos elementos ordenados com uma cópia da lista original, também ordenada.
3. Comparação da soma dos elementos antes e depois da ordenação.

## 6. Como compilar

É necessário possuir um compilador GCC instalado.

No terminal, execute:

```bash
gcc -O2 -Wall -Wextra main.c -o ordenacao.exe
```

## 7. Como executar

No Windows, execute:

```powershell
.\ordenacao.exe
```

## 8. Estrutura do projeto

```text
desafio/
├── main.c
├── README.md
└── ordenacao.exe
```

O arquivo de entrada `listaOdenada.txt` deve permanecer na pasta imediatamente acima de `desafio`, conforme o caminho utilizado no código.