/**
 * Description:
 *      The following program takes the conception of pipes to communicate between 2
 *      process and also calls a thread during execution time.
 *
 *      Project developed for the Operational Systems for the Computer Science degree.
 *
 * Autors:
 *      Tuanne Assenço - tuanne.assenco@gmail.com
 *      Gabriel Garcia - gabrielhgarcia7@gmail.com
 *
 * Compiled as follows:
 *      $ gcc -Wall rpg.c -o rpg; ./rpg
 **/

// Inclusion of libraries necessary for the operation of the program
#include <stdio.h>                      // For standard input/output functions
#include <stdlib.h>                     // For standard library functions
#include <string.h>                     // For string manipulation functions
#include <time.h>                       // For time-related functions
#include <unistd.h>                     // For POSIX-standard functions
#include <pthread.h>                    // For thread-related functions
#include "instructions.h"               // For instructions-related functions
#include "player_customization_race.h"  // For player customization race-related functions
#include "player_customization_class.h" // For player customization class-related functions
#include "decks.h"                      // For deck-related functions
#include "attack_move.h"                // For attack move-related functions
#include "defense_move.h"               // For defense move-related functions
#include "player_1.h"                   // For player 1-related functions
#include "player_2.h"                   // For player 2-related functions
#include "print_colors.h"               // For print color-related functions
#include "motivation_message.h"         // For motivation message-related functions

// This code defines macros for cleaning the input buffer, clearing the screen, and sleeping for 1 second,
// depending on the compiler being used.
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
// Declarations of functions
void instructions();
int player_customization_race();
int player_customization_class();
Attack_arr selected_deck(int deck_index);

// Variables
int descriptor,
    pipe1[2], // array of size 2 to store 2 file descriptors for pipe 1
    pipe2[2]; // array of size 2 to store 2 file descriptors for pipe 2

// Print blue text and prompt user to press enter to enter the game
print_blue("Press 'Enter' to entry the game...\n");
getchar();

// Clear the terminal screen
system("clear");

// Call the instructions function
instructions();

// Create two pipes for communication between player 1 and player 2
if (pipe(pipe1) < 0 || pipe(pipe2) < 0) {

    // Print error message if pipe call fails
    print_red("\nrpg.c: Pipe call error");
    printf("\nerror: pipe1 = %d pipe2 = %d", pipe(pipe1), pipe(pipe2));

    // Exit the program
    exit(0);
}

// Create a child process
if((descriptor = fork()) < 0) {

    // Print error message if fork call fails
    print_red("Error: Call FORK()");

    // Exit the program
    exit(0);
}

// If the descriptor is greater than 0, it is the parent process
else if(descriptor > 0) {

    // Close the reading end of pipe1 and the writing end of pipe2
    close(pipe1[0]);
    close(pipe2[1]);

    // Call player_1 function with the reading end of pipe2 and the writing end of pipe1
    player_1(pipe2[0], pipe1[1]);

    // Close the writing end of pipe1 and the reading end of pipe2
    close(pipe1[1]);
    close(pipe2[0]);
}

// If the descriptor is 0, it is the child process
else {

    // Close the writing end of pipe1 and the reading end of pipe2
    close(pipe1[1]);
    close(pipe2[0]);

    // Call player_2 function with the reading end of pipe1 and the writing end of pipe2
    player_2(pipe1[0], pipe2[1]);

    // Close the reading end of pipe1 and the writing end of pipe2
    close(pipe1[0]);
    close(pipe2[1]);
}

// Flush the stdout buffer
fflush(stdout);

// Prompt user to press enter to end the program
getchar();

return 0;
}
