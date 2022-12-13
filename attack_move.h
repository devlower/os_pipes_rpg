 int attack_move(Attack_arr player_attack) {

    //system("clear");
    int lower = 0, upper = 9, count = 3, attacks[3], opt;

    srand(time(0));

    for(int i = 0; i < count; i++) {
      attacks[i] = (rand() % (upper - lower + 1)) + lower;
    }

    Attack attack1 = player_attack.attack_cards[0];
    Attack attack2 = player_attack.attack_cards[1];
    Attack attack3 = player_attack.attack_cards[2];

    print_blue(" Choose your move by its number:\n\n");
        printf(" 1) %s - Damage points: %d\n\tDescription: %s\n\n"
               " 2) %s - Damage points: %d\n\tDescription: %s\n\n"
               " 3) %s - Damage points: %d\n\tDescription: %s\n\n", attack1.attack_name, attack1.attack_pwr, attack1.description, attack2.attack_name, attack2.attack_pwr, attack2.description, attack3.attack_name, attack3.attack_pwr, attack3.description);

    while(1) {
      scanf("%d", &opt);
      switch (opt) {
            case 1:
              return attack1.attack_pwr;
            case 2:
              return attack2.attack_pwr;
            case 3:
              return attack3.attack_pwr;
            default:
              print_red("Please insert a valid attack...\n\n");
              break;
      }
    }
 }
