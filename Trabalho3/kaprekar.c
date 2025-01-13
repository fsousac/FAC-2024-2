#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int compare_desc(const void *a, const void *b)
{
    return *(char *)b - *(char *)a;
}

int compare_asc(const void *a, const void *b)
{
    return *(char *)a - *(char *)b;
}

const char *kaprekar_steps(int n)
{
    // Verifica se a entrada é válida: número natural de 4 dígitos e sem todos os dígitos iguais
    char digits[5];
    sprintf(digits, "%04d", n);
    char first = digits[0];
    bool valid = false;

    for (int i = 0; i < 4; i++)
    {
        if (digits[i] != first)
        {
            valid = true;
            break;
        }
    }

    if (n < 1000 || n > 9999 || !valid)
    {
        return "entrada invalida.";
    }

    const int KAPREKAR_CONSTANT = 6174;
    int steps = 0;

    while (n != KAPREKAR_CONSTANT)
    {
        // Converte o número para string e manipula os dígitos
        sprintf(digits, "%04d", n);

        // Ordena os dígitos em ordem decrescente
        qsort(digits, 4, sizeof(char), compare_desc);
        int desc = atoi(digits);

        // Ordena os dígitos em ordem crescente
        qsort(digits, 4, sizeof(char), compare_asc);
        int asc = atoi(digits);

        // Calcula a diferença
        n = desc - asc;
        steps++;
    }

    // Formata o resultado
    static char result[20];
    sprintf(result, "%d", steps);
    return result;
}

int main()
{
    int entrada;
    if (scanf("%d", &entrada) != 1)
    {
        printf("entrada invalida.\n");
        return 0;
    }

    const char *resultado = kaprekar_steps(entrada);
    printf("%s\n", resultado);

    return 0;
}
