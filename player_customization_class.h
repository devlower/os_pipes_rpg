int player_customization_class() {
  int opt, valid_option = 1;

  print_blue(" Choose your class by its number: \n\n");
  print_yellow("  1) Warrior\n");
  print_cyan("  2) Mage\n");
  print_red("  3) Assassin\n");
  print_green("  4) Cleric\n\n");

  while(valid_option) {
    printf(" Your choice: ");
    scanf("%d", &opt);
    switch(opt) {
      case 1: print_yellow("\nYou choose to be a Warrior!\n"); valid_option = 0; break;
      case 2: print_cyan("\nYou choose to be a Mage!\n"); valid_option = 0; break;
      case 3: print_red("\nYou choose to be an Assassin!\n"); valid_option = 0; break;
      case 4: print_green("\nYou choose to be a Cleric!\n"); valid_option = 0; break;
      default: print_red("\nPlease insert a valid option.\n\n"); break;
    }
  }
  getchar();

  return opt;
 }
