#include <stdio.h>
#include <string.h>

int main()
{
    char ascii_txt[33], hex_txt[65];

    scanf(" %[^\n]", ascii_txt);
    int j = 0;
    for (int i = 0; ascii_txt[i] != '\0'; i++)
    {
        sprintf(&hex_txt[j], "%02x", (unsigned char)ascii_txt[i]);
        j += 2;
    }
    hex_txt[j] = '\0';

    printf("%s\n", hex_txt);

    return 0;
}