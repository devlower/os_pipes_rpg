typedef struct pipe_variables {
    int damage;
    int end_game;
} Pipe_variables;

typedef struct player_attr
  {
    char player_class[10];
    char race[8];
    float live_status;
  } Player_attr;

char classes_opt[4][10] = {"Warrior", "Mage", "Assassin", "Cleric"};
char races_opt[3][8] = {"Human", "Elf", "Dwarf"};

int player_1(int readfd, int writefd) {

    int end_game = 0;
    Pipe_variables var_pipes = {0, 0, 0};

    Attack_arr deck;

    system("clear");

    print_green("\n Process 1: Player 1 - Customization - Race\n\n");

    int player_race_index = player_customization_race();
    getchar();

    system("clear");
    print_green("\n Process 1: Player 1 - Customization - Class\n\n");

    int player_class_index = player_customization_class();
    getchar();

    var_pipes.temp = 1;

    write(writefd, &var_pipes, sizeof(var_pipes));

    read(readfd, &var_pipes, sizeof(var_pipes));

    int damage;

    Player_attr player_1;
    strcpy(player_1.race, races_opt[player_race_index - 1]);
    strcpy(player_1.player_class, classes_opt[player_class_index - 1]);
    player_1.live_status = 50;

    system("clear");

    while(player_1.live_status > 0 || end_game == 1) {

    system("clear");

    deck = selected_deck(player_class_index);

    print_green("\n Process 1: Player 1 - Attack time!\n\n");

    printf("\n\n Player 1 Attributes:\n\n\tRace: %s\n\tClass: %s\n\tLife Status: %.2f", player_1.race, player_1.player_class, player_1.live_status);

    damage = attack_move(deck);

    var_pipes.damage = damage;

    write(writefd, &var_pipes, sizeof(var_pipes));

    read(readfd, &var_pipes, sizeof(var_pipes));

    end_game = var_pipes.end_game;
    damage = var_pipes.damage;

    if(end_game == 1) {
        break;
      }

      print_green("\n Process 1: Player 1 - Defense time!\n\n");

      float damage_took;

      printf("Player 1 Attributs:\n\n\tRace: %s\n\tClass: %s\n\tLife Status: %.2f\n\n", player_1.race, player_1.player_class, player_1.live_status);

      damage_took = defense_move(damage);

      printf("\n\n Player 1 took %.2f of damage", damage_took);

      player_1.live_status -= damage_took;

      printf("\n\n Life bar: %.2f", player_1.live_status);

      getchar();

      if (player_1.live_status < 0){
        var_pipes.end_game = 1;
        var_pipes.damage = 0;
        write(writefd, &var_pipes, sizeof(var_pipes));
        break;
      }
    }

    system("clear");

    if(player_1.live_status > 0) {
      print_green("\n\n ***************** PLAYER 1 WIN ***************** ");
    }

    print_green("\n\n ...fim do Processo 1\n\n");

    return(0);
  }
