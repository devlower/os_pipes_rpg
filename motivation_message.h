/**
*   This code is a thread function that prints a motivational message to player 2 if their life status
*   is less than or equal to 12.5. The message printed depends on the player's class. The function takes
*   in a parameter "arg" which is expected to be an integer representing the player's class. The function
*   then prints the corresponding motivational message and waits for the user to press a key before continuing.
**/

void *motivation_message(void *arg) {

    // Casting the "arg" parameter to the correct data type "int"
    int class_id = (int) arg;

    print_pink("\n\n\tHere's a Thread!\n\n");

    // Switch statement to determine which motivational message to print based on player's class
    switch(class_id) {
        // If player is a warrior
        case 1:
            // Print a message in pink text
            print_pink(" The only way to fail is to give up, so keep fighting until the very end Warrior!!!\n\n");
            break;
        // If player is a mage
        case 2:
            // Print a message in pink text
            print_pink("\n\n Though your body may be weak, your mind and spirit are unbreakable. Hold onto those, and you can overcome any obstacle Mage\n\n");
            break;
        // If player is an assassin
        case 3:
            // Print a message in pink text
            print_pink("\n\n Your cunning and stealth may have failed you this time, but they have served you well throughout your life.\nHold onto the lessons you have learned, and use them to guide you in your next life Assassin!!!\n\n");
            break;
        // If player is a cleric
        case 4:
            // Print a message in pink text
            print_pink("\n\n Your faith has been your rock, and it will continue to be so even in death. Hold onto it and let it guide you on your journey beyond the veil Cleric!!!\n\n");
            break;
        // If player's class is not recognized
        default:
            // Do nothing
            break;
    }

    // Wait for the user to press a key before continuing
    getchar();

    return NULL;
}
