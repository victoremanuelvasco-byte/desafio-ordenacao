# Competição de Ordenação — O Desafio dos Milissegundos

## Autor

Vitor Emanoel Espíndola Alves
Lucas Eduardo da Silva Nascimento

## 1. Objetivo

O objetivo deste projeto é implementar um algoritmo de ordenação em linguagem C, capaz de organizar uma grande quantidade de números inteiros no menor tempo possível.

Para o benchmark da atividade, deve ser utilizado o arquivo oficial `ListahAhSerOrdenada.txt` (60 MB), disponibilizado no enunciado. O arquivo não é incluído neste repositório.

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

## 4. Resultados da competição

Execução com o arquivo oficial `ListahAhSerOrdenada.txt`:

- Quantidade de números: 10.000.000
- Ordenação correta: SIM
- Preservação dos elementos: SIM
- Preservação da soma: SIM
- Tempo de CPU do Merge Sort: 0,202 segundo (202 ms)

A leitura do arquivo e as verificações acontecem fora do intervalo cronometrado.
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

## 8. Arquivos do projeto

```text
Pasta de trabalho/
├── ListahAhSerOrdenada.txt   # arquivo oficial de 60 MB; não enviado ao GitHub
└── pasta-do-repositorio/
    ├── README.MD
    └── main.c
```

Execute os comandos dentro da pasta do repositório. O código procura `../ListahAhSerOrdenada.txt`, portanto o arquivo oficial deve ficar na pasta imediatamente acima daquela que contém `main.c`.

O executável `ordenacao.exe` é gerado ao compilar e não faz parte do repositório.
