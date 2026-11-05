
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
// Funcao que intercala duas partes ordenadas
void intercalar(int vetor[], int auxiliar[],
                size_t inicio, size_t meio, size_t fim)
{

    size_t i = inicio;
    size_t j = meio;
    size_t k = inicio;

    while (i < meio && j < fim)
    {
        if (vetor[i] <= vetor[j])
        {
            auxiliar[k++] = vetor[i++];
        }
        else
        {
            auxiliar[k++] = vetor[j++];
        }
    }

    while (i < meio)
    {
        auxiliar[k++] = vetor[i++];
    }

    while (j < fim)
    {
        auxiliar[k++] = vetor[j++];
    }

    for (k = inicio; k < fim; k++)
    {
        vetor[k] = auxiliar[k];
    }
}

// Algoritmo Merge Sort
void mergeSort(int vetor[], int auxiliar[],
               size_t inicio, size_t fim)
{

    if (fim - inicio <= 1)
    {
        return;
    }

    size_t meio = inicio + (fim - inicio) / 2;

    mergeSort(vetor, auxiliar, inicio, meio);
    mergeSort(vetor, auxiliar, meio, fim);

    intercalar(vetor, auxiliar, inicio, meio, fim);
}
int comparar(const void *a, const void *b)
{
    int x = *(const int *)a;
    int y = *(const int *)b;

    return (x > y) - (x < y);
}
int main()
{

    FILE *arquivo;
    int numero;
    size_t quantidade = 0;

    // Abre o arquivo de entrada
    arquivo = fopen("../listaOdenada.txt", "r");

    if (arquivo == NULL)
    {
        printf("Erro ao abrir o arquivo!\n");
        return 1;
    }

    // Primeira leitura: conta os numeros
    while (fscanf(arquivo, "%d", &numero) == 1)
    {
        quantidade++;
    }

    if (!feof(arquivo))
    {
        printf("Erro na leitura dos dados!\n");
        fclose(arquivo);
        return 1;
    }

    if (quantidade == 0)
    {
        printf("Arquivo vazio!\n");
        fclose(arquivo);
        return 1;
    }

    rewind(arquivo);

    // Reserva memoria para os vetores
    int *vetor = malloc(quantidade * sizeof(int));
    int *auxiliar = malloc(quantidade * sizeof(int));
    int *original = malloc(quantidade * sizeof(int));

    if (vetor == NULL || auxiliar == NULL || original == NULL)
    {
        printf("Erro ao alocar memoria!\n");
        free(vetor);
        free(auxiliar);
        fclose(arquivo);
        return 1;
    }

    // Segunda leitura: carrega os numeros
    long long somaAntes = 0;

    for (size_t i = 0; i < quantidade; i++)
    {

        if (fscanf(arquivo, "%d", &vetor[i]) != 1)
        {
            printf("Erro ao carregar os dados!\n");
            free(vetor);
            free(auxiliar);
            fclose(arquivo);
            return 1;
        }

        somaAntes += vetor[i];
    }
    memcpy(original, vetor, quantidade * sizeof(int));

    fclose(arquivo);

    // MEDICAO: somente o algoritmo sera cronometrado
    clock_t inicio = clock();

    mergeSort(vetor, auxiliar, 0, quantidade);

    clock_t fim = clock();

    double tempo = (double)(fim - inicio) / CLOCKS_PER_SEC;

    // Verificacao da ordenacao
    int ordenado = 1;

    for (size_t i = 1; i < quantidade; i++)
    {
        if (vetor[i - 1] > vetor[i])
        {
            ordenado = 0;
            break;
        }
    }
    // Ordena a copia original para comparar os elementos
qsort(original, quantidade, sizeof(int), comparar);

// Compara os elementos das duas listas
int preservacao = 1;

for (size_t i = 0; i < quantidade; i++)
{
    if (original[i] != vetor[i])
    {
        preservacao = 0;
        break;
    }
}

    // Verificacao adicional da soma dos elementos
    long long somaDepois = 0;

    for (size_t i = 0; i < quantidade; i++)
    {
        somaDepois += vetor[i];
    }

    printf("\n===== RESULTADO DA ORDENACAO =====\n");
    printf("Quantidade de numeros: %zu\n", quantidade);
    printf("Ordenacao correta: %s\n",
           ordenado ? "SIM" : "NAO");
    printf("Preservacao dos elementos: %s\n",
       preservacao ? "SIM" : "NAO");

printf("Preservacao da soma: %s\n",
       somaAntes == somaDepois ? "SIM" : "NAO");
    printf("Tempo de ordenacao: %.6f segundos\n", tempo);

    free(vetor);
    free(auxiliar);

    free(original);

return ordenado && preservacao &&
       somaAntes == somaDepois ? 0 : 1;

}
