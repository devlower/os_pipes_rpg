int player_customization_race() {
  int opt, valid_option = 1;

  print_blue(" Choose your race by its number:\n\n"
             " 1) Human\n"
             " 2) Elf\n"
             " 3) Dwarf\n\n");

  while(valid_option) {
    printf(" Your choice: ");
    scanf("%d", &opt);
    getchar();
    switch(opt) {
      case 1: print_blue("\n You choose to be a Human!\n"); valid_option = 0; break;
      case 2: print_blue("\n You choose to be an Elf!\n"); valid_option = 0; break;
      case 3: print_blue("\n You choose to be a Dwarf!\n"); valid_option = 0; break;
      default: print_red("\n\n Please insert a valid option.\n\n"); break;
    }
  }

    return opt;
}
