#include <stdio.h>

int main()
{
    int c;
    float f = 0;
    printf("Digite os dois ultimos digitos da sua matricula:\n");
    scanf("%d", &c);
    f = ((9.0 * c) / 5.0) + 32.0;
    printf("O valor de %d em Fahrenheit eh: %f\n", c, f);
    return 0;
}