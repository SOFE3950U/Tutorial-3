/*
 * Tutorial 3 Jeopardy Project for SOFE 3950U / CSCI 3020U: Operating Systems
 *
 * Copyright (C) 2015, <GROUP MEMBERS>
 * All rights reserved.
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "questions.h"
#include "players.h"
#include "jeopardy.h"

// Put macros or constants here using #define
#define BUFFER_LEN 256
#define NUM_PLAYERS 4

const int numPlayers;

// Put global environment variables here

// Processes the answer from the user containing what is or who is and tokenizes it to retrieve the answer.
void tokenize(char *input, char **tokens);

// Displays the game results for each player, their name and final score, ranked from first to last place
void show_results(player *players, int num_players);


int main(int argc, char *argv[])
{

    int numPlayers;
    printf("Enter the number of playres (1-4): ");
    scanf("%d", &numPlayers);

    player *players = malloc(sizeof (player) * numPlayers);

    system("cls");

    


    for(int i = 0; i < numPlayers; i++){
        printf("%s %d | ", players[i].name, players[i].score);
    }

    printf("\n");
    
    
    // Input buffer and and commands
    char buffer[BUFFER_LEN] = { 0 };

    // Display the game introduction and initialize the questions
    initialize_game();

    // Prompt for players names
    // initialize each of the players in the array
    for(int i = 0; i < numPlayers; i++){
        printf("Enter name for player %d: ", i+1);
        scanf("%s", players[i].name);
        players[i].score = 0;
        system("cls");
    }
    
    

    // Perform an infinite loop getting command input from users until game ends
    while (fgets(buffer, BUFFER_LEN, stdin) != NULL)
    {   
        
        int a;
        char cat;
        int val;

        int playerNum = 0;
        display_categories();
        printf("\n");

        // printf("Player %d, select category: ", playerNum+1);
        // scanf("%c", &cat);
        // printf("Player %d, select value: ", playerNum+1);
        // scanf("%d", &val);

        printf("%s, select question: ", players[playerNum].name);
        scanf("%d", &a);

        if(a == -1){
            break;
        }

        system("cls");

        // Call functions from the questions and players source files
        if(already_answered(a)){
            printf("%s, select a different question: ", players[playerNum].name);
            scanf("%d", &a);
        }else{
            display_question(a);
        }
        

        // Execute the game until all questions are answered

        // Display the final results and exit
    }
    return EXIT_SUCCESS;
}
