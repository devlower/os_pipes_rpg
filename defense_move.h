/** 
*   This function returns the amount of damage that the player receives from an attack.
*   It takes in the initial amount of damage as input.
**/ 

float defense_move(int damage_input) {

    // Initialize variables for the lower and upper bounds of the random number
    // generation, the defense dice roll, and the final amount of damage.
    int lower = 1, upper = 3, d3_dice, damage;

    // Set the final amount of damage to the initial input amount.
    damage = damage_input;

    // Print the possible results of the defense dice roll to the user.
    print_blue(" Press 'Enter' to roll your defense d3 dice:\n\n");
    print_green(" 1) You avoid the attack\n");
    print_yellow(" 2) You receive 50\% of the damage\n");
    print_red(" 3) You receive full damage\n");

    // Wait for the user to press the 'Enter' key.
    getchar();

    // Seed the random number generator with the current time.
    srand(time(0));

    // Roll the defense dice.
    d3_dice = (rand() % (upper - lower + 1)) + lower;
    printf("\n\n Dice result: %d\n", d3_dice);

    // Return the appropriate amount of damage based on the dice roll.
    switch (d3_dice) {
      case 1:
        return 0;
      case 2:
        return damage * 0.5;
      case 3:
        return damage;
      default:
        break;
    }

    getchar();
 }
