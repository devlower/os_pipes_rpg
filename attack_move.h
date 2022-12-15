/**
*   This function returns the attack power of the chosen attack.
*   It takes in a struct of type Attack_arr as input.
**/

int attack_move(Attack_arr player_attack) {

    // Initialize variables for the lower and upper bounds of the random number
    // generation, the count of attacks to choose from, and the attacks array.
    int lower = 0, upper = 9, count = 3, attacks[3], opt;

    // Seed the random number generator with the current time.
    srand(time(0));

    // Generate three random numbers within the given bounds.
    for(int i = 0; i < count; i++) {
      attacks[i] = (rand() % (upper - lower + 1)) + lower;
    }

    // Choose the three attacks corresponding to the random indices.
    Attack attack1 = player_attack.attack_cards[attacks[0]];
    Attack attack2 = player_attack.attack_cards[attacks[1]];
    Attack attack3 = player_attack.attack_cards[attacks[2]];

    // Print the available attacks to the user and prompt them to choose one.
    print_blue(" \n\nChoose your move by its number:\n\n");
        printf(" 1) %s - Damage points: %d\n\tDescription: %s\n\n"
               " 2) %s - Damage points: %d\n\tDescription: %s\n\n"
               " 3) %s - Damage points: %d\n\tDescription: %s\n\n", attack1.attack_name, attack1.attack_pwr, attack1.description, attack2.attack_name, attack2.attack_pwr, attack2.description, attack3.attack_name, attack3.attack_pwr, attack3.description);

    // Loop until the user selects a valid attack.
    while(1) {
      // Read the user's chosen attack.
      scanf("%d", &opt);

      // Return the attack power of the chosen attack.
      switch (opt) {
            case 1:
              return attack1.attack_pwr;
            case 2:
              return attack2.attack_pwr;
            case 3:
              return attack3.attack_pwr;

            // If the user didn't choose a valid attack,
            // print an error message and prompt them to try again.
            default:
              print_red("Please insert a valid attack...\n\n");
              break;
      }
    }
 }
