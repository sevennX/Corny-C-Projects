#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int main(void)
{

    srand(time(NULL));
    int play_again = 1;

    char user_input[10];

    while (play_again)
    {
        printf("Enter your choice (rock, paper, scissor): ");
        scanf("%s", user_input);

        int random_value = rand() % 100; // Generate a random value between 0 and 99

        printf("You entered: %s\n", user_input);

        if (strcmp(user_input, "rock") != 0 && strcmp(user_input, "paper") != 0 && strcmp(user_input, "scissor") != 0)
        {
            printf("Invalid input. Please enter rock, paper, or scissor.\n");
            continue; // Prompt the user again without exiting
        }

        char computer_choice[10];
        if (random_value < 33)
        {
            snprintf(computer_choice, sizeof(computer_choice), "rock");
        }
        else if (random_value < 66)
        {
            snprintf(computer_choice, sizeof(computer_choice), "paper");
        }
        else
        {
            snprintf(computer_choice, sizeof(computer_choice), "scissor");
        };
        printf("Computer chose: %s\n", computer_choice);

        if (strcmp(user_input, computer_choice) == 0)
        {
            printf("It's a tie!\n");
        }
        else if ((strcmp(user_input, "rock") == 0 && strcmp(computer_choice, "scissor") == 0) ||
                 (strcmp(user_input, "paper") == 0 && strcmp(computer_choice, "rock") == 0) ||
                 (strcmp(user_input, "scissor") == 0 && strcmp(computer_choice, "paper") == 0))
        {
            printf("You win!\n");
        }
        else
        {
            printf("Computer wins!\n");
        }

        printf("Do you want to play again? (1 for yes, 0 for no): ");
        scanf("%d", &play_again);
    }

    return 0;
}