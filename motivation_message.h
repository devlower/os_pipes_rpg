void *motivation_message(void *arg) {

    // Casting the "arg" parameter to the correct data type "char*"
    char* class_name = (char*) arg;

    //
    if(strcmp(class_name, "Warrior")) {

        print_pink("\n\nThe only way to fail is to give up, so keep fighting until the very end Warrior!!!\n\n")
    }else if(strcmp(class_name, "Mage")) {

        print_pink("\n\nThough your body may be weak, your mind and spirit are unbreakable. Hold onto those, and you can overcome any obstacle Mage\n\n")
    }else if(strcmp(class_name, "Assassin")) {

        print_pink("\n\nYour cunning and stealth may have failed you this time, but they have served you well throughout your life. Hold onto the lessons you have learned, and use them to guide you in your next life Assassin!!!\n\n")
    }else if(strcmp(class_name, "Cleric")) {

        print_pink("\n\nYour faith has been your rock, and it will continue to be so even in death. Hold onto it and let it guide you on your journey beyond the veil Cleric!!!\n\n")
    }

    getchar();

    return NULL;
}

