#include <stdio.h>
#include <ctype.h> // Para as funções isalpha, isupper e islower

int main()
{
    int key;
    char cesar[33];

    // Leitura da chave e da string
    scanf("%d", &key);
    scanf(" %[^\n]", cesar);

    // Ajusta a chave para o intervalo de 0 a 25
    key = key % 26;

    for (int i = 0; cesar[i] != '\0'; i++)
    {
        // Verifica se o caractere é uma letra
        if (isalpha(cesar[i]))
        {
            // Define o limite ASCII (A ou a)
            char base = isupper(cesar[i]) ? 'A' : 'a';
            // Aplica a fórmula da Cifra de César
            cesar[i] = base + (cesar[i] - base + key + 26) % 26;
        }
        // Outros caracteres permanecem inalterados
    }

    // Imprime a string cifrada
    printf("%s\n", cesar);

    return 0;
}
