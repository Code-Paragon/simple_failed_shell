#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    char *str = "youare;here;arent;you";
    char *token[1000];
    char *str_copy, *token_str;
    int c = ';', i = 0;
    char *delim = ";";

    str_copy = strdup(str);  // Create a copy of the input string

    if (str_copy != NULL)
    {
        if (strchr(str_copy, c) != NULL)
        {
            token_str = strtok(str_copy, delim);
            while (token_str != NULL)
            {
                token[i] = token_str;
                printf("%s\n", token[i]);

                token_str = strtok(NULL, delim); // Get the next token
                i++;
            }
        }
        else
        {
            printf("Delimiter not found, no tokenization performed.\n");
        }

        free(str_copy);  // Free the copied string after use
    }

    return 0;
}
