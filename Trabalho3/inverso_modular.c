#include <math.h>
#include <stdio.h>
#include <stdbool.h>

double sqrt(double num)
{
    if (num < 0)
    {
        return -1;
    }
    if (num == 0 || num == 1)
    {
        return num;
    }

    double guess = num;     // Chute inicial
    double epsilon = 0.1;   // Precisão desejada
    int maxIterations = 10; // Máximo de iterações
    int i = 0;

    while (i < maxIterations)
    {
        double newGuess = (guess + num / guess) / 2.0;
        if (fabs(newGuess * newGuess - num) < epsilon)
        {
            break;
        }
        guess = newGuess;
        i++;
    }

    return guess;
}

bool isPrime(int num)
{
    if (num <= 1)
    {
        return 0;
    }
    else if (num <= 3)
    {
        return 1;
    }
    else if (num % 2 == 0 || num % 3 == 0)
    {
        return 0;
    }
    // Verificar divisibilidade de 5 até a raiz quadrada do número
    for (int i = 5; i <= sqrt(num); i += 6)
    {
        if (num % i == 0 || num % (i + 2) == 0)
        {
            return 0;
        }
    }
    return 1;
}
int main()
{
    int p, a;

    scanf("%d", &p);
    scanf("%d", &a);
    if (a % p == 0 || a <= 1 || p <= 1)
    {
        printf("Entradas invalidas\n");
        return 0;
    }
    else if (!isPrime(p))
    {
        printf("O modulo nao eh primo\n");
        return 0;
    }

    for (int i = 0; i < p; i++)
    {
        if ((a * i) % p == 1)
        {
            printf("inverso = %d\n", i);
            break;
        }
    }

    return 0;
}