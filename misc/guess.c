#include <stdio.h>
#include <stdlib.h>

int check_win(int pl_choice, int pc_choice); // returns 0 if win, 1 if too high, -1 if too low
int handle_result(int result); // returns 1 if game must continue or 0 if game is won
void end_message(int guess_coint, int recent_choice, int pc_choice); // Shows a message based on end result

int main(void)
{
    while (1) 
    {
        printf("-----------------------\n");
        printf("Welcome to the game.\n");
        int guess_count = 3;
        int pc_choice = (rand() % (10 - 0 + 1) + 0);
        int recent_choice;
        while (guess_count > 0)
        {
            printf("You have %i guesses left.\n", guess_count);
            printf("Pick a number btwn 0-10: ");
            scanf("%i", &recent_choice);
            if (handle_result(check_win(recent_choice, pc_choice)) > 0) 
            {
                guess_count--;
            }
            else
            {
                break;
            }
            
        }
        end_message(guess_count, recent_choice, pc_choice);
    }
}

int check_win(int pl_choice, int pc_choice)
{
    if (pl_choice > pc_choice)
    {
        return 1;
    }
    else if (pl_choice < pc_choice)
    {
        return -1;
    }
    else
    {
        return 0;
    }
}

int handle_result(int result)
{
    if (result == 1)
    {   
        printf("Too High.\n");
        return 1;
    }
    else if (result == -1)
    {
        printf("Too Low.\n");
        return 1;
    }
    else
    {
        return 0;
    }
    
}

void end_message(int guess_count, int recent_choice, int pc_choice)
{
    if (guess_count > 0)
    {
        printf("Congrats, You win!!\n");
    }
    else
    {
        printf("You lose. Computer chose %i | You chose %i\n", pc_choice, recent_choice);
    }
}

