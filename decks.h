typedef struct attack
  {
    char attack_name[20];
    char description[200];
    int attack_pwr;
  } Attack;

  typedef struct attack_arr {
    Attack attack_cards[10];
  } Attack_arr;

 Attack_arr selected_deck(int deck_index) {

 int player_class_index = deck_index;

    Attack_arr warrior_deck;
    warrior_deck.attack_cards[0] = (Attack){.attack_name = "Blade of Revenge", .attack_pwr = 10, .description = "Blade of Revenge will cut your opponent with bitter power."};
    warrior_deck.attack_cards[1] = (Attack){.attack_name = "Ancient Sharp Fury", .attack_pwr = 13, .description = "Ancient Sharp Fury will use power of your ancestors to cut your enemy."};
    warrior_deck.attack_cards[2] = (Attack){.attack_name = "Indulgent Sword", .attack_pwr = 9, .description = "Indulgent Sword will graciously hit your enemy."};
    warrior_deck.attack_cards[3] = (Attack){.attack_name = "Balanced Swing", .attack_pwr = 3, .description = "Balanced Swing will "};
    warrior_deck.attack_cards[4] = (Attack){.attack_name = "Loyal Stab", .attack_pwr = 6, .description = "Eu magna anim id ea."};
    warrior_deck.attack_cards[5] = (Attack){.attack_name = "Light Saber", .attack_pwr = 4, .description = "Ad deserunt minim anim irure sint enim esse elit culpa velit amet ipsum."};
    warrior_deck.attack_cards[6] = (Attack){.attack_name = "Blood Thirst", .attack_pwr = 7, .description = "Quis et adipisicing aliqua ex anim non pariatur."};
    warrior_deck.attack_cards[7] = (Attack){.attack_name = "Honorable Laceration", .attack_pwr = 5, .description = "Cillum ut dolor incididunt enim."};
    warrior_deck.attack_cards[8] = (Attack){.attack_name = "Undefeated Gash", .attack_pwr = 8, .description = "Dolor duis adipisicing elit aute pariatur laboris et ex magna reprehenderit tempor fugiat officia."};
    warrior_deck.attack_cards[9] = (Attack){.attack_name = "Gut Penetration", .attack_pwr = 15, .description = "Proident sint in sit velit sit ad ea eiusmod eu exercitation qui."};

    Attack_arr mage_deck;
    mage_deck.attack_cards[0] = (Attack){.attack_name = "Fire Ball", .attack_pwr = 10, .description = "Esse ea excepteur exercitation qui Lorem culpa est irure fugiat fugiat non quis sunt."};
    mage_deck.attack_cards[1] = (Attack){.attack_name = "Ignite Flames", .attack_pwr = 13, .description = "Culpa anim ad minim sit pariatur dolor."};
    mage_deck.attack_cards[2] = (Attack){.attack_name = "Ice Blast", .attack_pwr = 9, .description = "Est ad aute consequat nostrud."};
    mage_deck.attack_cards[3] = (Attack){.attack_name = "Earth Quack", .attack_pwr = 3, .description = "Fugiat magna adipisicing dolore veniam eiusmod quis aute velit fugiat."};
    mage_deck.attack_cards[4] = (Attack){.attack_name = "Air Frost", .attack_pwr = 6, .description = "Eu magna anim id ea."};
    mage_deck.attack_cards[5] = (Attack){.attack_name = "Sharp Wind", .attack_pwr = 4, .description = "Ad deserunt minim anim irure sint enim esse elit culpa velit amet ipsum."};
    mage_deck.attack_cards[6] = (Attack){.attack_name = "Water Ball", .attack_pwr = 7, .description = "Quis et adipisicing aliqua ex anim non pariatur."};
    mage_deck.attack_cards[7] = (Attack){.attack_name = "Steamy Air", .attack_pwr = 5, .description = "Cillum ut dolor incididunt enim."};
    mage_deck.attack_cards[8] = (Attack){.attack_name = "Flying Rocks", .attack_pwr = 8, .description = "Dolor duis adipisicing elit aute pariatur laboris et ex magna reprehenderit tempor fugiat officia."};
    mage_deck.attack_cards[9] = (Attack){.attack_name = "Wizard's Power", .attack_pwr = 15, .description = "Proident sint in sit velit sit ad ea eiusmod eu exercitation qui."};

    Attack_arr assassin_deck;
    assassin_deck.attack_cards[0] = (Attack){.attack_name = "Fire Ball", .attack_pwr = 10, .description = "Esse ea excepteur exercitation qui Lorem culpa est irure fugiat fugiat non quis sunt."};
    assassin_deck.attack_cards[1] = (Attack){.attack_name = "Ignite Flames", .attack_pwr = 13, .description = "Culpa anim ad minim sit pariatur dolor."};
    assassin_deck.attack_cards[2] = (Attack){.attack_name = "Ice Blast", .attack_pwr = 9, .description = "Est ad aute consequat nostrud."};
    assassin_deck.attack_cards[3] = (Attack){.attack_name = "Earth Quack", .attack_pwr = 3, .description = "Fugiat magna adipisicing dolore veniam eiusmod quis aute velit fugiat."};
    assassin_deck.attack_cards[4] = (Attack){.attack_name = "Air Frost", .attack_pwr = 6, .description = "Eu magna anim id ea."};
    assassin_deck.attack_cards[5] = (Attack){.attack_name = "Sharp Wind", .attack_pwr = 4, .description = "Ad deserunt minim anim irure sint enim esse elit culpa velit amet ipsum."};
    assassin_deck.attack_cards[6] = (Attack){.attack_name = "Water Ball", .attack_pwr = 7, .description = "Quis et adipisicing aliqua ex anim non pariatur."};
    assassin_deck.attack_cards[7] = (Attack){.attack_name = "Steamy Air", .attack_pwr = 5, .description = "Cillum ut dolor incididunt enim."};
    assassin_deck.attack_cards[8] = (Attack){.attack_name = "Flying Rocks", .attack_pwr = 8, .description = "Dolor duis adipisicing elit aute pariatur laboris et ex magna reprehenderit tempor fugiat officia."};
    assassin_deck.attack_cards[9] = (Attack){.attack_name = "Wizard's Power", .attack_pwr = 15, .description = "Proident sint in sit velit sit ad ea eiusmod eu exercitation qui."};

    Attack_arr cleric_deck;
    cleric_deck.attack_cards[0] = (Attack){.attack_name = "Fire Ball", .attack_pwr = 10, .description = "Esse ea excepteur exercitation qui Lorem culpa est irure fugiat fugiat non quis sunt."};
    cleric_deck.attack_cards[1] = (Attack){.attack_name = "Ignite Flames", .attack_pwr = 13, .description = "Culpa anim ad minim sit pariatur dolor."};
    cleric_deck.attack_cards[2] = (Attack){.attack_name = "Ice Blast", .attack_pwr = 9, .description = "Est ad aute consequat nostrud."};
    cleric_deck.attack_cards[3] = (Attack){.attack_name = "Earth Quack", .attack_pwr = 3, .description = "Fugiat magna adipisicing dolore veniam eiusmod quis aute velit fugiat."};
    cleric_deck.attack_cards[4] = (Attack){.attack_name = "Air Frost", .attack_pwr = 6, .description = "Eu magna anim id ea."};
    cleric_deck.attack_cards[5] = (Attack){.attack_name = "Sharp Wind", .attack_pwr = 4, .description = "Ad deserunt minim anim irure sint enim esse elit culpa velit amet ipsum."};
    cleric_deck.attack_cards[6] = (Attack){.attack_name = "Water Ball", .attack_pwr = 7, .description = "Quis et adipisicing aliqua ex anim non pariatur."};
    cleric_deck.attack_cards[7] = (Attack){.attack_name = "Steamy Air", .attack_pwr = 5, .description = "Cillum ut dolor incididunt enim."};
    cleric_deck.attack_cards[8] = (Attack){.attack_name = "Flying Rocks", .attack_pwr = 8, .description = "Dolor duis adipisicing elit aute pariatur laboris et ex magna reprehenderit tempor fugiat officia."};
    cleric_deck.attack_cards[9] = (Attack){.attack_name = "Wizard's Power", .attack_pwr = 15, .description = "Proident sint in sit velit sit ad ea eiusmod eu exercitation qui."};

    switch (player_class_index)
    {
    case 1:
      return warrior_deck;
      break;
    case 2:
      return mage_deck;
      break;
    case 3:
      return assassin_deck;
      break;
    case 4:
      return cleric_deck;
      break;
    default:
      break;
    }
  }

