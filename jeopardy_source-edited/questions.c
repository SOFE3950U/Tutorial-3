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
#include "questions.h"

// Initializes the array of questions for the game
void initialize_game(void)
{
    // initialize each question struct and assign it to the questions array
    for(int i = 0; i < 12; i++){
        strcpy(questions[i].category, categories[i%3]);
        questions[i].answered = false;
        strcpy(questions[i].question, "Question");
        strcpy(questions[i].answer, "Answer");
    }

    questions[0].value = 100;
    questions[1].value = 100;
    questions[2].value = 100;

    questions[3].value = 200;
    questions[4].value = 200;
    questions[5].value = 200;

    questions[6].value = 300;
    questions[7].value = 300;
    questions[8].value = 300;

    questions[9].value = 500;
    questions[10].value = 500;
    questions[11].value = 500;
}

// Displays each of the remaining categories and question dollar values that have not been answered
void display_categories(void)
{
    // print categories and dollar values for each unanswered question in questions array

    int width = 15;
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("Enter the number in brackets to select the questions.\n");
    printf("\n\"---\"\t\t - question is already answered.\n");
    printf("\"(#) val\"\t - question can be selected by Entering the number specified by #.\n");
    printf("\nEnter -1 to exit.\n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");

    for(int i = 0; i < 3; i++){
        printf("%-15s\t", categories[i]);
    }
    printf("\n");
    printf("-------------------------------------------\n");

    //1st Ques for each Category
    for(int i = 0; i < 3; i++){
        if(questions[i].answered){
            printf("%-15s\t", "---");
        }else{
            printf("(%d) ", i);
            printf("%-10d\t", questions[i].value);
        }
    }
    printf("\n");

    //2nd Ques for each Category
    printf("\n");
    for(int i = 3; i < 6; i++){
        if(questions[i].answered){
            printf("%-15s\t", "---");
        }else{
            printf("(%d) ", i);
            printf("%-10d\t", questions[i].value);
        }
    }
    printf("\n");

    //3rd Ques for each Category
    printf("\n");
    for(int i = 6; i < 9; i++){
        if(questions[i].answered){
            printf("%-15s\t", "---");
        }else{
            printf("(%d) ", i);
            printf("%-10d\t", questions[i].value);
        }
    }
    printf("\n");

    //4th Ques for each Category
    printf("\n");
    for(int i = 9; i < 12; i++){
        if(questions[i].answered){
            printf("%-15s\t", "---");
        }else{
            printf("(%d) ", i);
            printf("%-10d\t", questions[i].value);
        }
    }
    printf("\n");

    
}

// Displays the question for the category and dollar value
//void display_question(char *category, int value)
void display_question(int qNum)
{
    printf("%s\n", questions[qNum].question);
}

// Returns true if the answer is correct for the question for that category and dollar value
//bool valid_answer(char *category, int value, char *answer)
bool valid_answer(int qNum, char *answer)
{
    // Look into string comparison functions
    if(strcasecmp(answer, questions[qNum].answer) == 0){
        return true;
    }

    return false;
}

// Returns true if the question has already been answered
//bool already_answered(char *category, int value)
bool already_answered(int qNum)
{
    // lookup the question and see if it's already been marked as answered
    if(!questions[qNum].answered){
        return false;
    }

    return true;
}
