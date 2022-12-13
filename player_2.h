int player_2(int readfd, int writefd) {

    int end_game = 0;
    Pipe_variables var_pipes_2 = {0, 0, 0};
    Attack_arr deck;

    read(readfd, &var_pipes_2, sizeof(var_pipes_2));

    int damage;

    system("clear");

    print_green("\n Process 2: Player 2 Customization - Race\n\n");

    int player_race_index = player_customization_race();
    getchar();

    system("clear");
    print_green("\n Process 2: Player 2 Customization - Class\n\n");
    int player_class_index = player_customization_class();
    getchar();

    Player_attr player_2;
    strcpy(player_2.race, races_opt[player_race_index - 1]);
    strcpy(player_2.player_class, classes_opt[player_class_index - 1]);
    player_2.live_status = 50;

    write(writefd, &var_pipes_2, sizeof(var_pipes_2));

    while(player_2.live_status > 0 || end_game == 1){

      read(readfd, &var_pipes_2, sizeof(var_pipes_2));

      deck = selected_deck(player_class_index);

      damage = var_pipes_2.damage;
      end_game = var_pipes_2.end_game;

      if(end_game == 1) {
        break;
      }

      printf("\n\n Damage: %d\n\n", damage);
      getchar();

      print_green("\n Process 2: Player 2 - Defense time!\n\n");

      float damage_took;

      printf("\n\n Player 2 Attributs:\n\n\tRace: %s\n\tClass: %s\n\tLife Status: %.2f\n\n", player_2.race, player_2.player_class, player_2.live_status);

      damage_took = defense_move(damage);

      printf(" You took %.2f of damage", damage_took);

      player_2.live_status -= damage_took;

      printf("\n\n Player 2 life bar: %.2f", player_2.live_status);

      getchar();

      if (player_2.live_status < 0){
        var_pipes_2.end_game = 1;
        var_pipes_2.damage = 0;
        write(writefd, &var_pipes_2, sizeof(var_pipes_2));
        break;
      }

      system("clear");

      print_green("\n Process 2: Player 2 - Attack time!\n\n");

      printf("\n\n Player 2 Attributes:\n\n\tRace: %s\n\tClass: %s\n\tLife Status: %.2f", player_2.race, player_2.player_class, player_2.live_status);

      damage = attack_move(deck);

      printf("\n\n Damage: %d\n\n", damage);
      getchar();

      var_pipes_2.damage = damage;

      write(writefd, &var_pipes_2, sizeof(var_pipes_2));
    }

    system("clear");

    if(player_2.live_status > 0) {
        print_green("\n\n *****************  PLAYER 2 WIN! ***************** \n\n");
    }

    print_green("\n\n ...fim do Processo 2.\n\n");

    return (0);
 }
