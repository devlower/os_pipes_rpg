/**
*   This code defines a struct for an attack card, which contains the name of the attack, its power, and a description.
*   It also defines a struct for an array of attack cards, and a function for selecting a deck of attack cards based
*   on the player's class. The function has a switch statement that returns a different deck of attack cards for each
*   class (warrior, mage, assassin, cleric). The decks of attack cards are defined in the code as well.
**/

// Define a struct for an attack card
typedef struct attack
  {
    char attack_name[20];   // Attack name
    int attack_pwr;         // Attack power
    char description[200];  // Description of the attack
  } Attack;

// Define a struct for an array of attack cards
typedef struct attack_arr {
Attack attack_cards[10];
} Attack_arr;

// Define a function for selecting a deck of attack cards
Attack_arr selected_deck(int deck_index) {

 int player_class_index = deck_index;

    // Define a deck of attack cards for a Warrior
    Attack_arr warrior_deck;
    warrior_deck.attack_cards[0] = (Attack){.attack_name = "Thundering Strike", .attack_pwr = 10, .description = "A powerful attack that causes the ground to shake and the air to crackle with electricity."};
    warrior_deck.attack_cards[1] = (Attack){.attack_name = "Mighty Blow", .attack_pwr = 13, .description = "An incredibly strong attack that deals massive damage to the enemy."};
    warrior_deck.attack_cards[2] = (Attack){.attack_name = "Shield Bash", .attack_pwr = 9, .description = "The warrior uses their shield to bash the enemy, stunning them and leaving them vulnerable to further attacks."};
    warrior_deck.attack_cards[3] = (Attack){.attack_name = "Whirlwind Attack", .attack_pwr = 3, .description = " A spinning attack that hits all enemies in a wide area around the warrior."};
    warrior_deck.attack_cards[4] = (Attack){.attack_name = "Battle Cry", .attack_pwr = 6, .description = "The warrior lets out a mighty roar, inspiring their allies and demoralizing their enemies."};
    warrior_deck.attack_cards[5] = (Attack){.attack_name = "Hamstring Slash", .attack_pwr = 4, .description = "The warrior targets the enemy's legs, crippling them and slowing them down."};
    warrior_deck.attack_cards[6] = (Attack){.attack_name = "Sundering Strike", .attack_pwr = 7, .description = "A powerful attack that shatters the enemy's armor and weaponry."};
    warrior_deck.attack_cards[7] = (Attack){.attack_name = "Stunning Blow", .attack_pwr = 5, .description = "The warrior lands a powerful strike that stuns the enemy, leaving them unable to defend themselves."};
    warrior_deck.attack_cards[8] = (Attack){.attack_name = "Taunt", .attack_pwr = 8, .description = "The warrior taunts the enemy, drawing their attention and aggression onto themselves."};
    warrior_deck.attack_cards[9] = (Attack){.attack_name = "Shield Wall", .attack_pwr = 15, .description = "The warrior raises their shield, forming a barrier that protects them and their allies from enemy attacks."};

    // Define a deck of attack cards for a Mage
    Attack_arr mage_deck;
    mage_deck.attack_cards[0] = (Attack){.attack_name = "Fireball", .attack_pwr = 10, .description = "The mage summons a ball of flame and hurls it at the enemy, causing burning damage."};
    mage_deck.attack_cards[1] = (Attack){.attack_name = "Frost Bolt", .attack_pwr = 13, .description = "The mage shoots a bolt of ice at the enemy, freezing them in place and dealing frost damage."};
    mage_deck.attack_cards[2] = (Attack){.attack_name = "Lightning Bolt", .attack_pwr = 9, .description = "The mage unleashes a bolt of electricity at the enemy, shocking them and dealing lightning damage."};
    mage_deck.attack_cards[3] = (Attack){.attack_name = "Arcane Blast", .attack_pwr = 3, .description = "The mage unleashes a wave of pure magical energy at the enemy, dealing heavy arcane damage."};
    mage_deck.attack_cards[4] = (Attack){.attack_name = "Chain Lightning", .attack_pwr = 6, .description = "The mage summons a bolt of lightning that bounces from the initial target to nearby enemies, dealing lightning damage to all of them."};
    mage_deck.attack_cards[5] = (Attack){.attack_name = "Cone of Cold", .attack_pwr = 4, .description = "The mage creates a cone of freezing air that damages and slows all enemies in its path."};
    mage_deck.attack_cards[6] = (Attack){.attack_name = "Polymorph", .attack_pwr = 7, .description = "The mage transforms the enemy into a harmless creature, rendering them unable to attack."};
    mage_deck.attack_cards[7] = (Attack){.attack_name = "Blink", .attack_pwr = 5, .description = "The mage teleports a short distance, allowing them to quickly reposition themselves and avoid enemy attacks."};
    mage_deck.attack_cards[8] = (Attack){.attack_name = "Mana Drain", .attack_pwr = 8, .description = "The mage drains the enemy's magical energy, weakening their spells and abilities."};
    mage_deck.attack_cards[9] = (Attack){.attack_name = "Arcane Barrier", .attack_pwr = 15, .description = "The mage creates a barrier of arcane energy that protects them and their allies from incoming attacks."};

    // Define a deck of attack cards for a Assassin
    Attack_arr assassin_deck;
    assassin_deck.attack_cards[0] = (Attack){.attack_name = "Venom Strike", .attack_pwr = 10, .description = "The assassin coats their blade with poison and strikes the enemy, dealing damage over time."};
    assassin_deck.attack_cards[1] = (Attack){.attack_name = "Shadow Step", .attack_pwr = 13, .description = "The assassin disappears into the shadows and reappears behind the enemy, surprising them and allowing the assassin to get in a quick attack."};
    assassin_deck.attack_cards[2] = (Attack){.attack_name = "Backstab", .attack_pwr = 9, .description = "The assassin sneaks up on the enemy and strikes them from behind, dealing extra damage."};
    assassin_deck.attack_cards[3] = (Attack){.attack_name = "Smoke Bomb", .attack_pwr = 3, .description = "The assassin tosses a smoke bomb at the enemy, blinding them and allowing the assassin to escape or set up a surprise attack."};
    assassin_deck.attack_cards[4] = (Attack){.attack_name = "Gouge", .attack_pwr = 6, .description = "The assassin rakes their claws across the enemy's eyes, blinding them and leaving them vulnerable to further attacks."};
    assassin_deck.attack_cards[5] = (Attack){.attack_name = "Sprint", .attack_pwr = 4, .description = "The assassin temporarily increases their speed, allowing them to quickly close the distance with the enemy or escape from danger."};
    assassin_deck.attack_cards[6] = (Attack){.attack_name = "Ambush", .attack_pwr = 7, .description = "The assassin sets up a hidden trap that triggers when the enemy walks over it, dealing damage and stunning them."};
    assassin_deck.attack_cards[7] = (Attack){.attack_name = "Disarm", .attack_pwr = 5, .description = "The assassin uses their skills to disarm the enemy, leaving them unable to attack."};
    assassin_deck.attack_cards[8] = (Attack){.attack_name = "Crippling Blow", .attack_pwr = 8, .description = "The assassin strikes a vital spot on the enemy's body, weakening them and making them easier to defeat."};
    assassin_deck.attack_cards[9] = (Attack){.attack_name = "Assassin's Mark", .attack_pwr = 15, .description = "The assassin marks the enemy, allowing the assassin and their allies to track the enemy and deal extra damage to them."};

    // Define a deck of attack cards for a Cleric
    Attack_arr cleric_deck;
    cleric_deck.attack_cards[0] = (Attack){.attack_name = "Healing Word", .attack_pwr = 10, .description = "The cleric utters a word of divine power that heals the wounds of an ally."};
    cleric_deck.attack_cards[1] = (Attack){.attack_name = "Bless", .attack_pwr = 13, .description = "The cleric blesses an ally, increasing their defenses and making them more resistant to damage."};
    cleric_deck.attack_cards[2] = (Attack){.attack_name = "Smite", .attack_pwr = 9, .description = "The cleric channels divine energy into their weapon, causing it to glow with holy light and deal extra damage to evil enemies."};
    cleric_deck.attack_cards[3] = (Attack){.attack_name = "Divine Shield", .attack_pwr = 3, .description = "The cleric creates a shield of divine energy that protects an ally from incoming attacks."};
    cleric_deck.attack_cards[4] = (Attack){.attack_name = "Purify", .attack_pwr = 6, .description = "The cleric cleanses an ally of any negative effects, such as poison or disease."};
    cleric_deck.attack_cards[5] = (Attack){.attack_name = "Mass Cure", .attack_pwr = 4, .description = "The cleric channels divine energy to heal the wounds of all allies within a certain radius."};
    cleric_deck.attack_cards[6] = (Attack){.attack_name = "Turn Undead", .attack_pwr = 7, .description = "The cleric channels divine energy to repel undead enemies, causing them to flee in fear."};
    cleric_deck.attack_cards[7] = (Attack){.attack_name = "Divine Intervention", .attack_pwr = 5, .description = "The cleric calls upon their deity to intervene on their behalf, granting them a temporary boost to their abilities."};
    cleric_deck.attack_cards[8] = (Attack){.attack_name = "Judgment", .attack_pwr = 8, .description = "The cleric pronounces judgment on the enemy, dealing extra damage to evil enemies and reducing the damage they can deal to the cleric and their allies."};
    cleric_deck.attack_cards[9] = (Attack){.attack_name = "Resurrection", .attack_pwr = 15, .description = "The cleric brings a fallen ally back to life, restoring them to full health and allowing them to continue fighting."};


    switch (player_class_index) {
        case 1:
            return warrior_deck;    // Return the warrior deck if the player's class is warrior
        case 2:
            return mage_deck;       // Return the warrior deck if the player's class is mage
        case 3:
            return assassin_deck;   // Return the warrior deck if the player's class is assassin
        case 4:
            return cleric_deck;     // Return the warrior deck if the player's class is cleric
        default:
            break;
    }
  }

