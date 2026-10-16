#include <stdio.h>
#include <string.h>

#define MAX_WORD_LENGTH 100
#define MAX_HINT_LENGTH 200

struct word_hint
{
    char word[MAX_WORD_LENGTH];
    char hint[MAX_HINT_LENGTH];
};

void initialize(struct word_hint arr[], size_t size)
{
    for (size_t i = 0; i < size; i++)
    {
        arr[i].word[0] = '\0';
        arr[i].hint[0] = '\0';
    }
};

int main(void)
{
    struct word_hint arr[10];
    initialize(arr, 10);

    return 0;
}