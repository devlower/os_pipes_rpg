void instructions() {

  print_blue(" ---------------------------------------------------------------------------------\n |");
  print_green("                              Operational System                               ");
  print_blue("|\n +-------------------------------------------------------------------------------+\n"
             " |                                                                               |\n |");
  print_green("                               Game Instructions                               ");
  print_blue("|\n |                                                                               |\n"
             " +-------------------------------------------------------------------------------+\n"
             " |                                                                               |\n"
             " | - You and your opponent will choose your class and race.                      |\n"
             " |                                                                               |\n"
             " | - Each one of you will receive a special deck with 10 power cards related     |\n"
             " |   with the class you choosed.                                                 |\n"
             " |                                                                               |\n"
             " | - Both of players have initial 50 points of Life and 100 points of Power.     |\n"
             " |                                                                               |\n"
             " | - On your turn you will have to choose between 3 randomly cards of your deck  |\n"
             " |   to attack your opponent. Based on how much Power you have.                  |\n"
             " |                                                                               |\n"
             " | - Your opponent will turn a d3 dice. If the result is:                        |\n |");
print_yellow("     1 -> The defender will succesfully avoid your attack, not taking any      ");
print_blue("|\n |");
print_yellow("          damage.                                                              ");
print_blue("|\n |");
print_yellow("     2 -> The defender will partially block your attack, receiving 50\% of      ");
print_blue("|\n |");
print_yellow("          full damage.                                                         ");
print_blue("|\n |");
print_yellow("     3 -> The defender failed to avoid your attack, receiving full damage.     ");
print_blue("|\n"
             " |                                                                               |\n"
             " | - Win who kills the opponent first!                                           |\n"
             " ---------------------------------------------------------------------------------\n");

 print_green("\n\nPress 'Enter' to continue...\n");

  getchar();
}
