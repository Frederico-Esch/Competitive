#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void reverse_word(const char* string, char* new_string, size_t begin, size_t end)
{
    for (size_t i = begin; i < end; i++)
    {
        new_string[i] = string[end-(i-begin)-1];
    }
}

char* reverseWords(const char* text)
{
    size_t size = strlen(text);
    char* new_string = malloc(sizeof(char)*size);

    size_t begin = 0;
    size_t end = 0;
    for (size_t i = 0; i < size; i++)
    {
        if (text[i] == ' ')
        {
            end = i;
            printf("begin: %zu\n", begin);
            reverse_word(text, new_string, begin, end);
            begin = end+1;
            new_string[i] = text[i];
        }
    }
    reverse_word(text, new_string, begin, size);
    new_string[size] = '\0';

    return new_string;
}

int main()
{
    {
        const char* string = "Apple and other fruits";
        char* result = reverseWords(string);
        printf("%s\n", result);
    }
    {
        const char* string = "a b c d";
        char* result = reverseWords(string);
        printf("%s\n", result);
    }
}
