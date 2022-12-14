 float defense_move(int damage_input) {

    //system("clear");

    int lower = 1, upper = 3, d3_dice, damage;

    damage = damage_input;

    print_blue(" Press 'Enter' to roll your defense d3 dice:\n\n");
    print_green(" 1) You avoid the attack\n");
    print_yellow(" 2) You receive 50\% of the damage\n");
    print_red(" 3) You receive full damage\n");

    getchar();

    srand(time(0));

    d3_dice = (rand() % (upper - lower + 1)) + lower;
    printf("\n\n Dice result: %d\n", d3_dice);

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
