/**
 * Description:
 *      The following program takes the conception of pipes to communicate between 2
 *      process and also calls a thread during execution time.
 *      Project developed for the Operational Systems for the Computer Science degree
 *
 * Autors:
 *      Tuanne Assenço - tuanne.assenco@gmail.com
 *      Gabriel Garcia - gabrielhgarcia7@gmail.com
 *
 * Compiled as follows:
 *      $ gcc -Wall rpg.c -o rpg; ./rpg
 **/

// Inclusion of libraries necessary for the operation of the program
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <pthread.h>
#include "instructions.h"
#include "player_cutomization_race.h"
#include "player_customization_class.h"
#include "decks.h"
#include "attack_move.h"
#include "defense_move.h"
#include "player_1.h"
#include "player_2.h"
#include "print_colors.h"
#include "motivation_message.h"

// Verifies the Operational System to override 'Screen Cleaning', 'Buffer' and 'Sleep' functions
#if defined(__MINGW32__) || defined(_MSC_VER)
#define clean_input() fflush(stdin)
#define clear_screen() system("cls")
#define sleep() system("timeout 1")
#else
#include <stdio_ext.h>
#define clean_input() __fpurge(stdin)
#define clear_screen() system("clear")
#define sleep() system("sleep 1")
#endif

// Color control functions for user preview
void print_pink(char *s);
void print_yellow(char *s);
void print_blue(char *s);
void print_green(char *s);
void print_green(char *s);
void print_red(char *s);
void print_white(char *s);
void print_cyan(char *s);

// Global functions declaration of 'attack moves', 'defense', 'player 1' and 'player 2'
int attack_move(Attack_arr player_attack);
float defense_move(int damage);
int player_1(int readfd, int writefd);
int player_2(int readfd, int writefd);

int main() {

    // Local functions declaration of 'game instructions', 'race customization', 'class customization' and 'attack array'
    void instructions();
    int player_customization_race();
    int player_customization_class();
    Attack_arr selected_deck(int deck_index);


    int descriptor,   // Used to create child process by fork
        pipe1[2],     // Communication, parent -> child: Player1
        pipe2[2];     // Communication, child -> parent: Player2

    // Start of the Game
    print_blue("Press 'Enter' to entry the game...\n");
    getchar();
    system("clear");

    // Print out game instructions
    instructions();


    // Checks if an error occur in Pipe call
    if (pipe(pipe1) < 0 || pipe(pipe2) < 0) {

        print_red("\nrpg.c: Pipe call error");
        printf("\nerror: pipe1 = %d pipe2 = %d", pipe(pipe1), pipe(pipe2));

        exit(0);
	}

	// Checks if there was an error in the fork() call
    if((descriptor = fork()) < 0) {

        print_red("Error: Call FORK()");

        exit(0);
    } else if(descriptor > 0) {     // Parent process

        close(pipe1[0]);    // Close reading of pipe1
        close(pipe2[1]);    // Close writing of pipe2

        player_1(pipe2[0], pipe1[1]);

        close(pipe1[1]);    // Close writing of pipe1
        close(pipe2[0]);    // Close reading of pipe2
    } else {

        close(pipe1[1]);    // Close writing of pipe1
        close(pipe2[0]);    // Close reading of pipe2

        player_2(pipe1[0], pipe2[1]);   // Child process

        close(pipe1[0]); // Close reading of pipe1
        close(pipe2[1]); // Close writing of pipe1
  }

    fflush(stdout);     // Clean outputs
    getchar();          // Await for the user press 'Enter' to close program

    return 0;
}
