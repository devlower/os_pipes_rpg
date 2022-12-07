#include <stdio.h>

//$ gcc -Wall rpg.c -o rpg; ./rpg


int main() {

  struct player_attr {
   char class[10];
   char race[8];
   int live_status = 100;
   int power_bar = 100;
   };

   struct move {
    char description[60];
    char attack_name[20];
    int attack_pwr;
   }

  char classes_opt[4][10] = {"Warrior", "Mage", "Assassin", "Cleric"};
  char races_opt[3][8] = {"Human", "Elf", "Dwarf"};



  char nome[10] = "Guerreiro";

  printf("%s", nome);
  printf("\nhello rpg");

  return 0;
}