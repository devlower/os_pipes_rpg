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
#include <string.h>
#include <time.h>

// VERIFICA O SISTEMA OPERACIONAL PARA SUBSTITUIR FUNÇÕES DE LIMPEZA DE TELA, BUFFER E SLEEP
#if defined(__MINGW32__) || defined(_MSC_VER)
#define clean_input() fflush(stdin)
#define clear_screen() system("cls")
#define sleep() system("timeout 1")
#else
#include <stdio_ext.h>
#define clean_input() __fpurge(stdin)
#define clear_screen() system("clear")
#define sleep() system("sleep 1")
#endif

#define MAXBUFF 1024	  // número de caract. do buffer
#define MAX_PWD_SIZE 1024 // tamanho máximo de nomenclatura de entrada

// funções de controle de cor para visualização do usuário
void print_pink(char *s);
void print_yellow(char *s);
void print_blue(char *s);
void print_green(char *s);
void print_green(char *s);
void print_red(char *s);
void print_white(char *s);
void print_cyan(char *s);

typedef struct attack
  {
    char attack_name[20];
    char description[200];
    int attack_pwr;
  } Attack;

int main()
{

  //system("clear");

  void instructions();
  int player_customization_race();
  int player_customization_class();
  int player_customization_player_1(int readfd, int writefd);
  int player_customization_player_2(int readfd, int writefd);


  int descriptor, // usado para criar o processo filho pelo fork
      pipe1[2],  // comunicação, pai -> filho jogador1
      pipe2[2];  // comunicação, filho -> pai  jodagor2

  typedef struct player_attr
  {
    char class[10];
    char race[8];
    float live_status;
    // int power_bar;
  } Player_attr;

  int attack_move(Attack player_attack[10]);
  float defense_move(int damage);

  // populating data

  char classes_opt[4][10] = {"Warrior", "Mage", "Assassin", "Cleric"};
  char races_opt[3][8] = {"Human", "Elf", "Dwarf"};

  

Attack warrior_deck[10];
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

  // for(i = 0; i < 10; i++){
  //   printf("%s\n%d\n%s\n\n", warrior_deck[i].attack_name, warrior_deck[i].attack_pwr, warrior_deck[i].description);
  // }

  Attack mage_deck[10];
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

  Attack assassin_deck[10];
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

  Attack cleric_deck[10];
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

  

  getchar();

  
  instructions();

  /*
  if (pipe(pipe1) < 0 || pipe(pipe2) < 0)
	{
		print_red("\nrpg.c: Erro na chamada do pipe");
		printf("\nerror: pipe1 = %d pipe2 = %d", pipe(pipe1), pipe(pipe2));
		exit(0);
	}

  if((descriptor = fork()) < 0) {

    print_red("Error: Call FORK()");
    exit(0);

  } else if(descriptor > 0) { // Processo PAI

    close(pipe1[0]);          // Fecha leitura no pipe1
    close(pipe2[1]);          // Fecha escrita no pipe2

    player_customization_player_1(pipe2[0], pipe1[1]);
    printf("fim processo 1 de novo");

    close(pipe1[1]); // fecha escrita pipe1
		close(pipe2[0]); // fecha leitura pipe2

  } else {

    close(pipe1[1]); // fecha escrita no pipe1
		close(pipe2[0]); // fecha leitura no pipe2

    player_customization_player_2(pipe1[0], pipe2[1]); //
    printf("fim processo 2 de novo");

		close(pipe1[0]); // fecha leitura no pipe1
		close(pipe2[1]);


    fflush(stdout);
    printf("Teve bom!");

  } */

  // TESTES EM WINDOWS:

  int player_race_index = player_customization_race();
  int player_class_index = player_customization_class();
  int damage;

  Player_attr player_1;
  strcpy(player_1.race, races_opt[player_race_index - 1]);
  strcpy(player_1.class, classes_opt[player_class_index - 1]);
  player_1.live_status = 100;

printf("race: %s\nclass: %s\nlife: %.2f", player_1.race, player_1.class, player_1.live_status);

while(player_1.live_status > 0) {
  switch (player_class_index)
{
case 1:
  damage = attack_move(warrior_deck);
  break;
case 2:
  damage = attack_move(mage_deck);
  break;
case 3:
  damage = attack_move(assassin_deck);
  break;
case 4:
  damage = attack_move(cleric_deck);
  break;
default:
  break;
}

printf("\n\nDamage: %d", damage);

 float damage_took;

 damage_took = defense_move(damage);

 printf("You took %.2f of damage", damage_took);

player_1.live_status -= damage_took;

printf("Your life bar: %.2f", player_1.live_status);
}

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

 print_green("\n\nPress any key to continue...\n");

  getchar();
  fflush(stdout);
}

int player_customization_race() {
  int opt, valid_option = 1;

  //system("clear");
  print_blue(" Choose your race by its number:\n\n"
             " 1) Human\n"
             " 2) Elf\n"
             " 3) Dwarf\n\n");

  while(valid_option) {
    printf(" Your choice: ");
    scanf("%d", &opt);
    switch(opt) {
      case 1: print_blue("\n You choose to be a Human!\n"); valid_option = 0; break;
      case 2: print_blue("\n You choose to be an Elf!\n"); valid_option = 0; break;
      case 3: print_blue("\n You choose to be a Dwarf!\n"); valid_option = 0; break;
      default: print_red("\n\n Please insert a valid option.\n\n"); break;
    }
  }

    fflush(stdout);
    getchar();

    return opt;
}

int player_customization_class() {
  int opt;
  int valid_option = 1;

  //system("clear");
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

  fflush(stdout);
  getchar();

  return opt;
 }

 int player_customization_player_1(readfd, writefd) {

    print_green("\n Process 1: Player 1  Customization...\n\n");

    player_customization_race();
    getchar();
    int a = player_customization_class();
    getchar();

    write(writefd);
    printf(" ...fim do Processo 1\n\n");
    printf("A classe do Jogador 1 e: %d", a);
    return(0);

 }

 int player_customization_player_2(readfd, writefd) {

    read(readfd);

    fflush(stdout);

    print_green("\n Process 2: Player 2 Customization...\n\n");

    player_customization_race();
    getchar();
    int a = player_customization_class();
    getchar();

    printf(" ...fim do Processo 2.\n\n");
    printf("A classe do Jogador 2 e: %d", a);
    return (0);
 }

 int attack_move(Attack player_attack[10]) {
    int lower = 0, upper = 9, count = 3, attacks[3], opt;

    srand(time(0));

    for(int i = 0; i < count; i++) {
      attacks[i] = (rand() % (upper - lower + 1)) + lower;
      printf("\n\n%d\n", attacks[i]);
    }

    Attack attack1 = player_attack[attacks[0]];
    Attack attack2 = player_attack[attacks[1]];
    Attack attack3 = player_attack[attacks[2]];

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

 float defense_move(int damage_input) {

    int lower = 1, upper = 3, d3_dice, damage;

    damage = damage_input;

    print_blue(" Press 'Enter' to roll your defense d3 dice:\n\n");
    print_green(" 1) You avoid the attack\n");
    print_yellow(" 2) You receive 50\% of the damage\n");
    print_red(" 3) You receive full damage");

    getchar();

    srand(time(0));

    d3_dice = (rand() % (upper - lower + 1)) + lower;
    printf("\n\nDice result: %d\n", d3_dice);

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
 }

// Funções de controle de cor para visualização do usuário
// Recebem uma string e formatam sua cor para saída no terminal
void print_pink(char *s)
{
  printf("\033[1;35m%s\033[0m", s);
}

void print_cyan(char *s)
{
  printf("\033[1;36m%s\033[0m", s);
}

void print_yellow(char *s)
{
  printf("\033[1;33m%s\033[0m", s);
}

void print_blue(char *s)
{
  printf("\033[1;34m%s\033[0m", s);
}

void print_green(char *s)
{
  printf("\033[1;32m%s\033[0m", s);
}

void print_red(char *s)
{
  printf("\033[1;31m%s\033[0m", s);
}

void print_white(char *s)
{
  printf("\033[1;29m%s\033[0m", s);
}

void print_reset(char *s)
{
  printf("\033[0m%s\033[0m", s);
}