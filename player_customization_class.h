/**
*   This code is a function for player customization in a game. It allows the player to choose their
*   class from a list of options, and then returns the player's chosen class as an integer value.
*   The function also prints messages to the player to inform them of their choice.
**/

int player_customization_class() {

    // Declare an integer variable for the player's class choice
    // and a variable for keeping track of whether the player's choice is valid
    int opt, valid_option = 1;

    // Print instructions for the player
    print_blue(" Choose your class by its number: \n\n");
    print_yellow(" 1) Warrior\n");
    print_cyan(" 2) Mage\n");
    print_red(" 3) Assassin\n");
    print_green(" 4) Cleric\n\n");

    // Keep asking the player to enter a valid class until they do so
    while(valid_option) {
        printf(" Your choice: ");
        scanf("%d", &opt);
        switch(opt) {
            case 1:

                // The player chose to be a Warrior
                print_yellow("\nYou choose to be a Warrior!\n");
                // Set the valid_option variable to 0 to exit the loop
                valid_option = 0;
                break;
            case 2:

                // The player chose to be a Mage
                print_cyan("\nYou choose to be a Mage!\n");
                // Set the valid_option variable to 0 to exit the loop
                valid_option = 0;
                break;
            case 3:

                // The player chose to be an Assassin
                print_red("\nYou choose to be an Assassin!\n");
                // Set the valid_option variable to 0 to exit the loop
                valid_option = 0;
                break;
            case 4:

                // The player chose to be a Cleric
                print_green("\nYou choose to be a Cleric!\n");
                // Set the valid_option variable to 0 to exit the loop
                valid_option = 0;
                break;
            default:

                // The player entered an invalid option
                print_red("\nPlease insert a valid option.\n\n");
                break;
        }
    }

    // Consume the newline character left in the input buffer after
    // the player enters their choice
    getchar();

    // Return the player's chosen class
    return opt;
}
