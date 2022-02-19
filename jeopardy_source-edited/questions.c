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

    //Questions/answers for Games category
    strcpy(questions[0].question, "This winning declaration in a chess game is from the Arabic for \"This king is dead\"");
    strcpy(questions[0].answer, "What is checkmate?");
    strcpy(questions[3].question,"In the \"Simpsons\" edition Monopoly, properties up for sale include Disco Stu's and this convenience store");
    strcpy(questions[3].answer,"What is Kwik-E-Mart");
    strcpy(questions[6].question, "\"Walk-off\" began as a term for a play that ends a game in this sport");
    strcpy(questions[6].answer, "What is baseball?");
    strcpy(questions[9].question,"The bank cannot go broke in this Parker Brothers game, so exhaustion may be the deciding factor");
    strcpy(questions[9].answer,"What is Monopoly?");

    //Questions/answers for Science category
    strcpy(questions[1].question,"As its name suggests, this 1,900-foot-deep lake sits atop an Oregon volcano");
    strcpy(questions[1].answer,"What is Crater?");
    strcpy(questions[4].question, "It's a statement of a relationship such as greater than or less than");
    strcpy(questions[4].answer, "What is inequality?");
    strcpy(questions[7].question, "In calculus this is defined as the instantaneous rate of change of a function");
    strcpy(questions[7].answer, "What is derivative?");
    strcpy(questions[10].question,"A tremor of the thumb can be a sign of this neurological disorder that bears the last name of a British doctor");
    strcpy(questions[10].answer,"What is Parkinson's?");


    //Questions/answer for Arts category
    strcpy(questions[2].question, "Before he was \"The Rock\", he had another nickname--Dewey");
    strcpy(questions[2].answer, "Who is Dwanye Johnson?");
    strcpy(questions[5].question, "This country legends is Miley Cyrus' godmother");
    strcpy(questions[5].answer, "Who is Dolly Parton?");
    strcpy(questions[8].question,"He painted \"Lady With a Fan\" during his Rose Period");
    strcpy(questions[8].answer,"Who is Picasso?");
    strcpy(questions[11].question, "The title of this 1961 novel is shorthand for a no-win situation");
    strcpy(questions[11].answer, "What is Catch-22?");

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
