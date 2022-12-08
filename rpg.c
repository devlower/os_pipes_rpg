/**
 * Descrição:
 *      Projeto de implementação de pipes em um programa que contém mais de 1 processo
 *      para a disciplina de Sistemas Operacionais
 *
 * Autoria:
 *      Tuanne Assenço - tuanne.assenco@gmail.com
 *      Gabriel Garcia
 *
 * Compilado da seguinte forma:
 *      $ gcc -Wall rpg.c -o rpg; ./rpg
 **/

#include <stdio.h>
#include <stdlib.h>

// funções de controle de cor para visualização do usuário
char print_pink(char *s);
char print_yellow(char *s);
char print_blue(char *s);
char print_green(char *s);
char print_green(char *s);
char print_red(char *s);
char print_white(char *s);
char print_cyan(char *s);

// variáveis globais para leitura e escrita para os pipes
int readfd, writefd;

int main()
{

  system("cls");

  void instructions();
  void player_customization();

  char option, valid_option;
  int counter = 0,
      descriptor, // usado para criar o processo filho pelo fork
      pipe1[2],  // comunicação, pai -> filho jogador1
      pipe2[2];  // comunicação, filho -> pai  jodagor2

  // defining variables declaration

  typedef struct player_attr
  {
    char class[10];
    char race[8];
    int live_status;
    // int power_bar;
  } Player_attr;

  typedef struct attack
  {
    char attack_name[20];
    char description[200];
    int attack_pwr;
  } Attack;

  // populating data

  char classes_opt[4][10] = {"Warrior", "Mage", "Assassin", "Cleric"};
  char races_opt[3][8] = {"Human", "Elf", "Dwarf"};

  Attack warrior_deck[9];
  warrior_deck[0] = (Attack){.attack_name = "Blade of Revenge", .attack_pwr = 10, .description = "Blade of Revenge will cut your opponent with bitter power."};
  warrior_deck[1] = (Attack){.attack_name = "Ancient Sharp Fury", .attack_pwr = 13, .description = "Ancient Sharp Fury will use power of your ancestors to cut your enemy."};
  warrior_deck[2] = (Attack){.attack_name = "Indulgent Sword", .attack_pwr = 9, .description = "Indulgent Sword will graciously hit your enemy."};
  warrior_deck[3] = (Attack){.attack_name = "Balanced Swing", .attack_pwr = 3, .description = "Balanced Swing will "};
  warrior_deck[4] = (Attack){.attack_name = "Loyal Stab", .attack_pwr = 6, .description = "Eu magna anim id ea."};
  warrior_deck[5] = (Attack){.attack_name = "Light Saber", .attack_pwr = 4, .description = "Ad deserunt minim anim irure sint enim esse elit culpa velit amet ipsum."};
  warrior_deck[6] = (Attack){.attack_name = "Blood Thirst", .attack_pwr = 7, .description = "Quis et adipisicing aliqua ex anim non pariatur."};
  warrior_deck[7] = (Attack){.attack_name = "Honorable Laceration", .attack_pwr = 5, .description = "Cillum ut dolor incididunt enim."};
  warrior_deck[8] = (Attack){.attack_name = "Undefeated Gash", .attack_pwr = 8, .description = "Dolor duis adipisicing elit aute pariatur laboris et ex magna reprehenderit tempor fugiat officia."};
  warrior_deck[9] = (Attack){.attack_name = "Gut Penetration", .attack_pwr = 15, .description = "Proident sint in sit velit sit ad ea eiusmod eu exercitation qui."};

  // int i;

  // for(i = 0; i < 9; i++){
  //   printf("%s\n%d\n%s\n\n", warrior_deck[i].attack_name, warrior_deck[i].attack_pwr, warrior_deck[i].description);
  // }

  Attack mage_deck[9];
  mage_deck[0] = (Attack){.attack_name = "Fire Ball", .attack_pwr = 10, .description = "Esse ea excepteur exercitation qui Lorem culpa est irure fugiat fugiat non quis sunt."};
  mage_deck[1] = (Attack){.attack_name = "Ignite Flames", .attack_pwr = 13, .description = "Culpa anim ad minim sit pariatur dolor."};
  mage_deck[2] = (Attack){.attack_name = "Ice Blast", .attack_pwr = 9, .description = "Est ad aute consequat nostrud."};
  mage_deck[3] = (Attack){.attack_name = "Earth Quack", .attack_pwr = 3, .description = "Fugiat magna adipisicing dolore veniam eiusmod quis aute velit fugiat."};
  mage_deck[4] = (Attack){.attack_name = "Air Frost", .attack_pwr = 6, .description = "Eu magna anim id ea."};
  mage_deck[5] = (Attack){.attack_name = "Sharp Wind", .attack_pwr = 4, .description = "Ad deserunt minim anim irure sint enim esse elit culpa velit amet ipsum."};
  mage_deck[6] = (Attack){.attack_name = "Water Ball", .attack_pwr = 7, .description = "Quis et adipisicing aliqua ex anim non pariatur."};
  mage_deck[7] = (Attack){.attack_name = "Steamy Air", .attack_pwr = 5, .description = "Cillum ut dolor incididunt enim."};
  mage_deck[8] = (Attack){.attack_name = "Flying Rocks", .attack_pwr = 8, .description = "Dolor duis adipisicing elit aute pariatur laboris et ex magna reprehenderit tempor fugiat officia."};
  mage_deck[9] = (Attack){.attack_name = "Wizard's Power", .attack_pwr = 15, .description = "Proident sint in sit velit sit ad ea eiusmod eu exercitation qui."};

  Attack assassin_deck[9];
  assassin_deck[0] = (Attack){.attack_name = "Fire Ball", .attack_pwr = 10, .description = "Esse ea excepteur exercitation qui Lorem culpa est irure fugiat fugiat non quis sunt."};
  assassin_deck[1] = (Attack){.attack_name = "Ignite Flames", .attack_pwr = 13, .description = "Culpa anim ad minim sit pariatur dolor."};
  assassin_deck[2] = (Attack){.attack_name = "Ice Blast", .attack_pwr = 9, .description = "Est ad aute consequat nostrud."};
  assassin_deck[3] = (Attack){.attack_name = "Earth Quack", .attack_pwr = 3, .description = "Fugiat magna adipisicing dolore veniam eiusmod quis aute velit fugiat."};
  assassin_deck[4] = (Attack){.attack_name = "Air Frost", .attack_pwr = 6, .description = "Eu magna anim id ea."};
  assassin_deck[5] = (Attack){.attack_name = "Sharp Wind", .attack_pwr = 4, .description = "Ad deserunt minim anim irure sint enim esse elit culpa velit amet ipsum."};
  assassin_deck[6] = (Attack){.attack_name = "Water Ball", .attack_pwr = 7, .description = "Quis et adipisicing aliqua ex anim non pariatur."};
  assassin_deck[7] = (Attack){.attack_name = "Steamy Air", .attack_pwr = 5, .description = "Cillum ut dolor incididunt enim."};
  assassin_deck[8] = (Attack){.attack_name = "Flying Rocks", .attack_pwr = 8, .description = "Dolor duis adipisicing elit aute pariatur laboris et ex magna reprehenderit tempor fugiat officia."};
  assassin_deck[9] = (Attack){.attack_name = "Wizard's Power", .attack_pwr = 15, .description = "Proident sint in sit velit sit ad ea eiusmod eu exercitation qui."};

  Attack cleric_deck[9];
  cleric_deck[0] = (Attack){.attack_name = "Fire Ball", .attack_pwr = 10, .description = "Esse ea excepteur exercitation qui Lorem culpa est irure fugiat fugiat non quis sunt."};
  cleric_deck[1] = (Attack){.attack_name = "Ignite Flames", .attack_pwr = 13, .description = "Culpa anim ad minim sit pariatur dolor."};
  cleric_deck[2] = (Attack){.attack_name = "Ice Blast", .attack_pwr = 9, .description = "Est ad aute consequat nostrud."};
  cleric_deck[3] = (Attack){.attack_name = "Earth Quack", .attack_pwr = 3, .description = "Fugiat magna adipisicing dolore veniam eiusmod quis aute velit fugiat."};
  cleric_deck[4] = (Attack){.attack_name = "Air Frost", .attack_pwr = 6, .description = "Eu magna anim id ea."};
  cleric_deck[5] = (Attack){.attack_name = "Sharp Wind", .attack_pwr = 4, .description = "Ad deserunt minim anim irure sint enim esse elit culpa velit amet ipsum."};
  cleric_deck[6] = (Attack){.attack_name = "Water Ball", .attack_pwr = 7, .description = "Quis et adipisicing aliqua ex anim non pariatur."};
  cleric_deck[7] = (Attack){.attack_name = "Steamy Air", .attack_pwr = 5, .description = "Cillum ut dolor incididunt enim."};
  cleric_deck[8] = (Attack){.attack_name = "Flying Rocks", .attack_pwr = 8, .description = "Dolor duis adipisicing elit aute pariatur laboris et ex magna reprehenderit tempor fugiat officia."};
  cleric_deck[9] = (Attack){.attack_name = "Wizard's Power", .attack_pwr = 15, .description = "Proident sint in sit velit sit ad ea eiusmod eu exercitation qui."};

  //   printf("                                    .\n"
  // "                               ::. :. :      \n"
  // "                            .-:..==-==       \n"
  // "                      .:.  -:  ===*=         \n"
  // "                     .=-= =:.  -+*+ -:-      \n"
  // "                  :+++*+ .-= .++*+.=-.       \n"
  // "                 .*+++:.=+-:=*+-..:.         \n"
  // "         :--=-==++++**+**+**+------          \n"
  // "        --+*++++==++++++++****+=-:           \n"
  // "        +*+++==-=-======++++=..::            \n"
  // "       +*++==-----=---=+++**                 \n"
  // "     ==*+==--::::-:::==++**+ :-              \n"
  // "     ***+==-::::::::-==++*=  ::              \n"
  // "     *+++=-:::::::::-=++**+**=               \n"
  // "     -*++==-:::::::-=+++++=-::               \n"
  // "      -*++==------==++*+:  .                 \n"
  // "       .=*++++====+++**=                     \n"
  // "         .-+*****+**+-                       \n"
  // "             ..::..                          \n");

  instructions();
  player_customization();

  // if (pipe(pipe1) < 0 || pipe(pipe2) < 0)
	// {
	// 	print_red("\nrpg.c: Erro na chamada do pipe");
	// 	printf("\nerror: pipe1 = %d pipe2 = %d", pipe(pipe1), pipe(pipe2));
	// 	exit(0);
	// }

  return 0;
}

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
             " | - Both of players have initial 100 points of Life and 100 points of Power.    |\n"
             " |                                                                               |\n"
             " | - On your turn you will have to choose between 3 randomly cards of your deck  |\n"
             " |   to attack your opponent. Based on how much Power you have.                  |\n"
             " |                                                                               |\n"
             " | - Your opponent will turn a d3 dice. If the result is:                        |\n |");
print_yellow("     1 -> The defendor will succesfuly avoid your attack, not taking any       ");
print_blue("|\n |");
print_yellow("          damage.                                                              ");
print_blue("|\n |");
print_yellow("     2 -> The defendor will partially block your attack, receiving 50\% of      ");
print_blue("|\n |");
print_yellow("          full damage.                                                         ");
print_blue("|\n |");
print_yellow("     3 -> The defendor failed to avoid your attack, receiving full damage.     ");
print_blue("|\n"
             " |                                                                               |\n"
             " | - Win who kills the opponent first!                                           |\n"
             " ---------------------------------------------------------------------------------\n");

 print_green("\n\nPress any key to continue...\n");

  getchar();
  fflush(stdin);
}

void player_customization() {
  int opt;
  int valid_option = 1;

  system("cls");
  print_blue(" Choose your class by its number: \n\n");
  print_yellow("  1) Warrior\n");
  print_cyan("  2) Mage\n");
  print_red("  3) Assassin\n");
  print_green("  4) Cleric\n\n");

  while(valid_option) {
    printf("Your choice: ");
    scanf("%d", &opt);
    switch(opt) {
      case 1: print_yellow("\nYou choose to be a Warrior!"); valid_option = 0; break;
      case 2: print_cyan("\nYou choose to be a Mage!"); valid_option = 0; break;
      case 3: print_red("\nYou choose to be an Assassin!"); valid_option = 0; break;
      case 4: print_green("\nYou choose to be a Cleric!"); valid_option = 0; break;
      default: print_blue("\nPlease insert a valid option. Press 'Enter' to continue.\n\n"); break;
   }
   fflush(stdin);
   getchar();
  }
 }

// Funções de controle de cor para visualização do usuário
// Recebem uma string e formatam sua cor para saída no terminal
char print_pink(char *s)
{
  printf("\033[1;35m%s\033[0m", s);
}

char print_cyan(char *s)
{
  printf("\033[1;36m%s\033[0m", s);
}

char print_yellow(char *s)
{
  printf("\033[1;33m%s\033[0m", s);
}

char print_blue(char *s)
{
  printf("\033[1;34m%s\033[0m", s);
}

char print_green(char *s)
{
  printf("\033[1;32m%s\033[0m", s);
}

char print_red(char *s)
{
  printf("\033[1;31m%s\033[0m", s);
}

char print_white(char *s)
{
  printf("\033[1;29m%s\033[0m", s);
}

char print_reset(char *s)
{
  printf("\033[0m%s\033[0m", s);
}
