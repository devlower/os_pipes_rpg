/**
*   This code is a function for player customization in a game. It allows the player to choose their
*   race from a list of options, and then returns the player's chosen race as an integer value.
*   The function also prints messages to the player to inform them of their choice and to handle invalid input.
**/

int player_customization_race() {
    // Initialize variable for user's choice of race
    int opt, valid_option = 1;

    // Display options for race selection
    print_blue(" Choose your race by its number:\n\n"
               " 1) Human\n"
               " 2) Elf\n"
               " 3) Dwarf\n\n");

    // Loop until user selects a valid option
    while(valid_option) {

    // Prompt user to enter their choice of race
    printf(" Your choice: ");

    // Read user's choice of race
    scanf("%d", &opt);

    // Clear input buffer
    getchar();

    // Switch case to handle user's choice of race
    switch(opt) {
        case 1:     // User chose Human
            // Display message to confirm user's choice of race
            print_blue("\n You choose to be a Human!\n");
            // Set flag to exit loop
            valid_option = 0;
            break;
    case 2:     // User chose Elf
        // Display message to confirm user's choice of race
        print_blue("\n You choose to be an Elf!\n");
        // Set flag to exit loop
        valid_option = 0;
        break;
    case 3:     // User chose Dwarf
        // Display message to confirm user's choice of race
        print_blue("\n You choose to be a Dwarf!\n");
        // Set flag to exit loop
        valid_option = 0;
        break;
    default:    // User entered an invalid option
        // Display error message
        print_red("\n\n Please insert a valid option.\n\n");
        break;
    }
}

    // Return user's choice of race
    return opt;
}
