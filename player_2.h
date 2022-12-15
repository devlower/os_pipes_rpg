/**
*   This code is a function that handles the actions of player 2 in a game. It allows player 2 to customize their
*   race and class, and then engage in a battle against player 1. The function uses pipes to communicate with
*   player 1 and exchange information about the game. The function repeatedly loops through defense and attack
*   phases, where player 2 can defend against player 1's attacks and deal damage to player 1. The loop continues
*   until either player 2 or player 1's life status reaches 0, at which point the game ends and a winner is declared.
**/

// function to handle player 2's actions
int player_2(int readfd, int writefd) {

    // variables
    int end_game = 0, // variable to track if the game has ended
    damage, // variable to store the amount of damage
    player_race_index, // variable to store the selected race index
    player_class_index; // variable to store the selected class index

    Pipe_variables var_pipes_2 = {0, 0}; // create a Pipe_variables object to store variables for pipe communication
    Attack_arr deck; // create an Attack_arr object to store attack deck

    // read from the pipe the variables stored in var_pipes_2
    read(readfd, &var_pipes_2, sizeof(var_pipes_2));

    // clear the terminal screen
    system("clear");

    // print a message in green text
    print_green("\n Process 2: Player 2 Customization - Race\n\n");

    // call the player_customization_race function to let player 2 choose their race
    player_race_index = player_customization_race();
    // wait for user to press enter
    getchar();

    // clear the terminal screen
    system("clear");

    // print a message in green text
    print_green("\n Process 2: Player 2 Customization - Class\n\n");

    // call the player_customization_class function to let player 2 choose their class
    player_class_index = player_customization_class();

    // wait for user to press enter
    getchar();

    // create a Player_attr object to store player 2's attributes
    Player_attr player_2;

    // store player 2's selected race in the race attribute
    strcpy(player_2.race, races_opt[player_race_index - 1]);

    // store player 2's selected class in the player_class attribute
    strcpy(player_2.player_class, classes_opt[player_class_index - 1]);

    // initialize player 2's life status to 50
    player_2.live_status = 50;

    // write the variables in var_pipes_2 to the pipe
    write(writefd, &var_pipes_2, sizeof(var_pipes_2));

    // keep executing the loop while player 2's life status is greater than 0 and the game has not ended
    while(player_2.live_status > 0 || end_game == 1){

        // read from the pipe the variables stored in var_pipes_2
        read(readfd, &var_pipes_2, sizeof(var_pipes_2));

        // call the selected_deck function to get the selected attack deck
        deck = selected_deck(player_class_index);

        // store the damage received from player 1
        damage = var_pipes_2.damage;
        // store the value of end_game
        end_game = var_pipes_2.end_game;

        // if the game has ended, break the loop
        if(end_game == 1) {
        break;
        }

        // print the amount of damage received
        printf("\n\n Damage: %d\n\n", damage);

        // wait for user to press enter
        getchar();

        // print a message in green text
        print_green("\n Process 2: Player 2 - Defense time!\n\n");

        // declare a variable to store the amount of damage taken
        float damage_took;

        // print player 2's attributes
        printf("\n\n Player 2 Attributs:\n\n\tRace: %s\n\tClass: %s\n\tLife Status: %.2f\n\n", player_2.race, player_2.player_class, player_2.live_status);

        // call the defense_move function to calculate the amount of damage taken
        damage_took = defense_move(damage);

        // print the amount of damage taken
        printf(" You took %.2f of damage", damage_took);

        // subtract the damage taken from player 2's life status
        player_2.live_status -= damage_took;

        // if player 2's life status is less than or equal to 12.5, print a motivational message
        if(player_2.live_status <= 12.5 && player_2.live_status > 0) {
        // create a pthread object to handle the motivational message
        pthread_t thread;

        // create the thread
        pthread_create(&thread, NULL, motivation_message, (void*)player_class_index);

        // wait for the thread to finish
        pthread_join(thread, NULL);

        }

    // print player 2's life status
    printf("\n\n Player 2 life bar: %.2f", player_2.live_status);

    // wait for user to press enter
    getchar();

    // if player 2's life status is less than or equal to 0, end the game
    if (player_2.live_status <= 0){

        // set the end_game variable to 1
        var_pipes_2.end_game = 1;

        // set the damage variable to 0
        var_pipes_2.damage = 0;

        // write the variables in var_pipes_2 to the pipe
        write(writefd, &var_pipes_2, sizeof(var_pipes_2));

        // break the loop
        break;
        }

    // clear the terminal screen
    system("clear");

    // print a message in green text
    print_green("\n Process 2: Player 2 - Attack time!\n\n");

    // print player 2's attributes
    printf("\n\n Player 2 Attributes:\n\n\tRace: %s\n\tClass: %s\n\tLife Status: %.2f", player_2.race, player_2.player_class, player_2.live_status);

    // call the attack_move function to calculate the amount of damage to be dealt
    damage = attack_move(deck);

    // print the amount of damage dealt
    printf("\n\n Damage: %d\n\n", damage);
    // wait for user to press enter
    getchar();

    // store the damage dealt in the damage variable of var_pipes_2
    var_pipes_2.damage = damage;

    // write the variables in var_pipes_2 to the pipe
    write(writefd, &var_pipes_2, sizeof(var_pipes_2));
    }

    // clear the terminal screen
    system("clear");

    // if player 2's life status is greater than 0, print a message that player 2 has won the game
    if(player_2.live_status > 0) {
        // print a message in green text
        print_green("\n\n ***************** PLAYER 2 WIN! ***************** \n\n");
    }

    // print a message in green text
    print_green("\n\n ...end of process 2.\n\n");

    // return 0
    return (0);
}
