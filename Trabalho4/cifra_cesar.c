#include <stdio.h>

int main()
{
    int key;
    char cesar[33];
    char alphabet[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
    char uppercase[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};

    scanf("%d", &key);
    scanf(" %[^\n]", cesar);

    key = key % 26;

    for (int i = 0;; i++)
    {
        if (cesar[i] == '\0')
            break;
        int k;
        int upper = 0;
        for (k = 0; k < 27; k++)
        {
            if (cesar[i] == alphabet[k])
            {
                break;
            }
            else if (cesar[i] == uppercase[k])
            {
                upper = 1;
                break;
            }
        }
        int new_index = (k + key) % 26;
        if (new_index < 0)
            new_index = 26 + new_index;

        if (k == 27)
        {
            continue;
        }
        else if (!upper)
        {
            cesar[i] = alphabet[new_index];
        }
        else
        {
            cesar[i] = uppercase[new_index];
        }
    }

    printf("%s\n", cesar);

    return 0;
}