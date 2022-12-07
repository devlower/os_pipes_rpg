#include <stdio.h>

//$ gcc -Wall rpg.c -o rpg; ./rpg


int main() {

  // defining variables declaration

  typedef struct player_attr {
   char class[10];
   char race[8];
   int live_status;
   int power_bar;
   } Player_attr;

   typedef struct attack {
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

  int i;

  for(i = 0; i < sizeof(warrior_deck); i++){
    printf("%s\n%d\n%s\n\n", warrior_deck[i].attack_name, warrior_deck[i].attack_pwr, warrior_deck[i].description);
  }

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
// getchar();

  return 0;
}