/**
*   The code defines two structs for storing the attributes of a player and the values of variables passed through pipes.
*   It also defines two arrays for the available class and race options.
*
*   The player_1() function is the main function for player 1. It asks the player to choose their race
*   and class, and then enters a loop where it allows the player to choose and perform an attack and defense move.
*   The function also checks the player's life points and prints a motivational message if they are low.
**/

// Define a struct for holding the values of variables passed through pipes
typedef struct pipe_variables {
    int damage;
    int end_game;
} Pipe_variables;

// Define a struct for holding the attributes of a player
typedef struct player_attr
  {
    char player_class[10];
    char race[8];
    float life_status;
  } Player_attr;

// Define arrays for the available class and race options
char classes_opt[4][10] = {"Warrior", "Mage", "Assassin", "Cleric"};
char races_opt[3][8] = {"Human", "Elf", "Dwarf"};

// Declare thread function for printing a motivational message
void *motivation_message(void *arg);

// Define the main function for player 1
int player_1(int readfd, int writefd) {

    // Initialize variables for the game
    int end_game = 0, damage;           // Flags for ending the game and storing damage dealt
    Pipe_variables var_pipes = {0, 0};  // Struct for passing values through pipes
    Attack_arr deck;                    // Array for storing the player's attack moves

    // Clear the terminal
    system("clear");

    // Print a message to the player
    print_green("\n Process 1: Player 1 - Customization - Race\n\n");

    // Ask the player to choose their race
    int player_race_index = player_customization_race();

    // Consume the newline character left in the input buffer after
    // the player enters their choice
    getchar();

    system("clear");
    print_green("\n Process 1: Player 1 - Customization - Class\n\n");

    // Ask the player to choose their class
    int player_class_index = player_customization_class();
    getchar();

    // Write the initial values of the pipe variables to the pipe
    write(writefd, &var_pipes, sizeof(var_pipes));

    // Read the values of the pipe variables from the pipe
    read(readfd, &var_pipes, sizeof(var_pipes));

    // Create a struct for storing the attributes of player 1
    Player_attr player_1;

    // Set the player's race and class based on their chosen indexes
    strcpy(player_1.race, races_opt[player_race_index - 1]);
    strcpy(player_1.player_class, classes_opt[player_class_index - 1]);

    // Set the player's initial life points
    player_1.life_status = 50;

    system("clear");

    // Loop until either player's life points reach 0 or the end_game flag is set
    while(player_1.life_status > 0 || end_game == 1) {

    system("clear");

    // Select the player's attack moves based on their chosen class
    deck = selected_deck(player_class_index);

    // Print a message to the player
    print_green("\n Process 1: Player 1 - Attack time!\n\n");

    // Print the player's attributes
    printf("\n\n Player 1 Attributes:\n\n\tRace: %s\n\tClass: %s\n\tLife Status: %.2f", player_1.race, player_1.player_class, player_1.life_status);

    // Allow the player to choose and perform an attack move
    damage = attack_move(deck);

    // Store the amount of damage dealt in the pipe variable struct
    var_pipes.damage = damage;

    // Write the updated values of the pipe variables to the pipe
    write(writefd, &var_pipes, sizeof(var_pipes));

    // Read the updated values of the pipe variables from the pipe
    read(readfd, &var_pipes, sizeof(var_pipes));

    // Store the updated values of the end_game and damage variables
    end_game = var_pipes.end_game;
    damage = var_pipes.damage;

    // If the end_game flag is set, break out of the loop
    if(end_game == 1) {
        break;
      }

      // Print a message to the player
      print_green("\n Process 1: Player 1 - Defense time!\n\n");

      float damage_took;

      // Print the player's attributes
      printf("Player 1 Attributs:\n\n\tRace: %s\n\tClass: %s\n\tLife Status: %.2f\n\n", player_1.race, player_1.player_class, player_1.life_status);

      // Allow the player to choose and perform a defense move
      damage_took = defense_move(damage);

      // Print the amount of damage taken by the player
      printf("\n\n Player 1 took %.2f of damage", damage_took);

      // Reduce the player's life points by the amount of damage taken
      player_1.life_status -= damage_took;

      // If the player's life points are low, print a motivational message
      if(player_1.life_status <= 12.5 && player_1.life_status > 0) {

        // Create a new thread for printing the motivational message
        pthread_t thread;

        // Start the thread and pass the player's class as an argument
        pthread_create(&thread, NULL, motivation_message, (void*)player_class_index);

        // Wait for the thread to finish
        pthread_join(thread, NULL);

      }

      // Print the player's current life points
      printf("\n\n Life bar: %.2f", player_1.life_status);

      // Consume the newline character left in the input buffer
      getchar();

      // If the player's life points have reached 0, set the end_game flag
      // and write the updated values of the pipe variables to the pipe
      if (player_1.life_status <= 0){
        var_pipes.end_game = 1;
        var_pipes.damage = 0;
        write(writefd, &var_pipes, sizeof(var_pipes));
        break;
      }
    }

    system("clear");

    // If player 1's life points are greater than 0, print a win message
    if(player_1.life_status > 0) {
      print_green("\n\n ***************** PLAYER 1 WIN ***************** ");
    }

    // Print a message to the player informing that the Process 1 is finished
    print_green("\n\n ...end of process 1.\n\n");

    // Return 0 to indicate that the function ran successfully
    return(0);
  }
