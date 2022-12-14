/**
*   This code defines a thread called motivation_message() that takes in a void pointer as an argument and returns a void pointer.
*   The thread function first casts the void pointer to a char* and assigns it to a variable called class_name.
*   It then uses an if-else statement to check if class_name is equal to "Warrior", "Mage", "Assassin", or "Cleric".
*   If class_name matches any of these values, the function will print a motivational message for that class using the print_pink() function.
*   Finally, the function waits for the user to press a key using the getchar() function, and returns NULL.
*   Because this function is intended to be used as a thread, it is probably called in a separate thread of execution,
*   allowing it to run concurrently with other code in the program. This may be useful if the motivational messages are intended to be
*   displayed to the user while other parts of the program are running.
**/

void *motivation_message(void *arg) {

    // Casting the "arg" parameter to the correct data type "char*"
    char* class_name = (char*) arg;

    // Check if the class_name is "Warrior"
    if(strcmp(class_name, "Warrior")) {

        // Print a motivational message for the Warrior class
        print_pink("\n\nThe only way to fail is to give up, so keep fighting until the very end Warrior!!!\n\n")
    }else if(strcmp(class_name, "Mage")) {

        // Print a motivational message for the Mage class
        print_pink("\n\nThough your body may be weak, your mind and spirit are unbreakable. Hold onto those, and you can overcome any obstacle Mage\n\n")
    }else if(strcmp(class_name, "Assassin")) {

        // Print a motivational message for the Assassin class
        print_pink("\n\nYour cunning and stealth may have failed you this time, but they have served you well throughout your life. Hold onto the lessons you have learned, and use them to guide you in your next life Assassin!!!\n\n")
    }else if(strcmp(class_name, "Cleric")) {

        // Print a motivational message for the Cleric class
        print_pink("\n\nYour faith has been your rock, and it will continue to be so even in death. Hold onto it and let it guide you on your journey beyond the veil Cleric!!!\n\n")
    }

    // Wait for the user to press a key before continuing
    getchar();

    return NULL;
}
