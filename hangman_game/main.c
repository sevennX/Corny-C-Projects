#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define MAX_WORD_LENGTH 100
#define MAX_HINT_LENGTH 200

struct word_hint
{
    char word[MAX_WORD_LENGTH];
    char hint[MAX_HINT_LENGTH];
};

int main(void)
{
    struct word_hint arr[10] = {
        {"apple", "A fruit that keeps the doctor away."},
        {"banana", "A long yellow fruit."},
        {"cherry", "A small red fruit often used in desserts."},
        {"grape", "A small round fruit that can be made into wine."},
        {"orange", "A citrus fruit that is also a color."},
        {"kiwi", "A small brown fruit with green flesh."},
        {"mango", "A tropical stone fruit with sweet yellow flesh."},
        {"peach", "A soft, fuzzy fruit with a pit."},
        {"pear", "A sweet fruit that is often green or yellow."},
        {"plum", "A small round fruit that can be purple or red."}};

    srand(time(NULL));
    int random_index = rand() % 10;

    struct word_hint selected_word = arr[random_index];

    char user_guess;
    int attempts = strlen(selected_word.word);
    char display_word[strlen(selected_word.word) + 1];
    for (int i = 0; i < strlen(selected_word.word); i++)
    {
        display_word[i] = '_';
    }
    display_word[strlen(selected_word.word)] = '\0';
    while (attempts > 0)
    {

        printf("Hint: %s\n", selected_word.hint);
        printf("========================\n");
        printf("Enter your guess: ");
        scanf(" %c", &user_guess);

        if (strchr(selected_word.word, user_guess) == NULL)
        {
            attempts--;
        }

        for (int i = 0; i < strlen(selected_word.word); i++)
        {
            if (selected_word.word[i] == user_guess && display_word[i] == '_')
            {
                display_word[i] = user_guess;
                break;
            }
        }

        printf("%s\n", display_word);
        if (strcmp(display_word, selected_word.word) == 0)
        {
            printf("Congratulations! You guessed the word: %s\n", selected_word.word);
            break;
        }

        printf("Attempts remaining: %d\n", attempts);
    }

    if (attempts == 0 && strcmp(display_word, selected_word.word) != 0)
    {
        printf("Game over! The word was: %s\n", selected_word.word);
    }

    return 0;
}
