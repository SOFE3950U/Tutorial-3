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
    printf("Enter the number of players (1-4): ");
    scanf("%d", &numPlayers);

    player *players = malloc(sizeof (player) * numPlayers);

    system("cls");

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
    
    
    int playerNum = 0%numPlayers;
    int a;

    int counter = 0;

    // Perform an infinite loop getting command input from users until game ends
    while (fgets(buffer, BUFFER_LEN, stdin) != NULL)
    {   

        display_categories();
        printf("\n");

        printf("%s, select question: ", players[playerNum].name);
        scanf("%d", &a);

        if(a < 0){
            break;
        }

        while(already_answered(a) || a >= 12){
            printf("%s, select a valid question: ", players[playerNum].name);
            scanf("%d", &a);
        }

        if(a < 0){
            break;
        }

        system("cls");

        // Call functions from the questions and players source files

        display_question(a);

        printf("\nEnter your answer: ");
        char *ans[MAX_LEN] = {0};
        getchar();
        //scanf("%s", ans);
        fgets((char *) ans, MAX_LEN, stdin);

        questions[a].answered = true;
        counter += 1;

        char *tokenized_ans;
        tokenize((char *) ans, &tokenized_ans);

        if(valid_answer(a, tokenized_ans)){
            printf("\nCongrats, %s!\nThe correct answer is: %s\n", players[playerNum].name, questions[a].answer);
            //players[playerNum].score += questions[a].value;
            update_score(players, numPlayers, players[playerNum].name, questions[a].value);
            playerNum = (playerNum + 1) % numPlayers;
            printf("ENTER any key to continue...\n");
            getch(); //change to getchar() for unix
        }else{
            printf("\nSorry, %s!\nThe correct answer is: %s\n", players[playerNum].name, questions[a].answer);
            playerNum = (playerNum + 1) % numPlayers;
            printf("ENTER any key to continue...\n");
            getch(); //change to getchar() for unix
        }
        
        

        // Execute the game until all questions are answered
        if(counter == 12){
            break;
        }

        // Display the final results and exit
    }

    system("cls");
    show_results(players, numPlayers);
    return EXIT_SUCCESS;
}


void tokenize(char *input, char **tokens){

    char *token;

    token = strtok(input," ");

    if(token != NULL){
        if(strcasecmp(token, "who") != 0 && strcasecmp(token, "what") != 0){
            return;
        }
    }

    token = strtok(NULL, " ");

    if(token != NULL){
        if(strcasecmp(token, "is") != 0){
            return;
        }
    }

    *tokens = strtok(NULL, "\n");
}


void show_results(player *players, int numPlayers){

    for(int i = 0; i < numPlayers-1; i++){
        for(int j = 0; j < numPlayers-i-1; j++){
            if(players[j].score < players[j+1].score){
                player temp;

                temp = players[j];
                players[j] = players[j+1];
                players[j+1] = temp;
            }
        }
    }

    bool tie = false;
    int score = players[0].score;

    for(int i = 1; i < numPlayers; i++){
        if (score == players[i].score)
            tie = true;
            break;
        score = players[i].score;
    }

    if(tie){
        printf("%s: %d\n", players[0].name, players[0].score);
    }else{
        printf("%s: %d - WINNER!!\n", players[0].name, players[0].score);
    }

    for(int i = 1; i < numPlayers; i ++){
        
        printf("%s: %d\n", players[i].name, players[i].score);
    }
}