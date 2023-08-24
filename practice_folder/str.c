#include <stdio.h>

int main() {
    char input[] = "Hello,World:Custom;Tokenizer";
    char *token_start = input;  // Initialize token_start to the beginning of the input

    // Loop through the input string to find and print tokens
    while (*token_start != '\0') {
        printf("Token Start: %c\n", *token_start);

        // Move token_start to the next non-delimiter character
        while (*token_start != '\0' && (*token_start == ',' || *token_start == ';' || *token_start == ':')) {
            token_start++;
        }

        // Move token_start to the next delimiter character
        while (*token_start != '\0' && *token_start != ',' && *token_start != ';' && *token_start != ':') {
            token_start++;
        }
    }

    return 0;
}

