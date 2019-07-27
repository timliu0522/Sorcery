#include "Deck.h"
#include "all_cards.h"
#include <fstream>

Deck::Deck() {
    cards_left = 0;
}

void Deck::load_deck(std::string filename, int num) {
    std::string cardname;
    std::ifstream ifs(filename);
    while(getline(ifs, cardname)) {
        if (cardname == "Air Elemental")
            push_card(num, new Air_Elemental());
        if (cardname == "Earth Elemental")
            push_card(num, new Earth_Elemental());
        if (cardname == "Bone Golem")
            push_card(num, new Bone_Golem());
        if (cardname == "Apprentice Summoner")
            push_card(num, new Apprentice_Summoner());
        if (cardname == "Fire Elemental")
            push_card(num, new Fire_Elemental());
        if (cardname == "Master Summoner")
            push_card(num, new Master_Summoner());
        if (cardname == "Novice Pyromancer")
            push_card(num, new Novice_Pyromancer());
        if (cardname == "Potion Seller")
            push_card(num, new Potion_Seller());
        if (cardname == "Silence")
            push_card(num, new Silence(nullptr));
        if (cardname == "Giant Strength")
            push_card(num, new Giant_Strength(nullptr));
        if (cardname == "Magic Fatigue")
            push_card(num, new Magic_Fatigue(nullptr));
        if (cardname == "Haste")
            push_card(num, new Haste(nullptr));
        if (cardname == "Enrage")
            push_card(num, new Enrage(nullptr));
        if (cardname == "Dark Ritual")
            push_card(num, new Dark_Ritual());
        if (cardname == "Aura of Power")
            push_card(num, new Aura_of_Power());
        if (cardname == "Standstill")
            push_card(num, new Standstill());
        if (cardname == "Raise Dead")
            push_card(num, new Raise_Dead());
        if (cardname == "Recharge")
            push_card(num, new Recharge());
        if (cardname == "Banish")
            push_card(num, new Banish());
        if (cardname == "Blizzard")
            push_card(num, new Blizzard());
        if (cardname == "Disenchant")
            push_card(num, new Disenchant());
        if (cardname == "Unsummon")
            push_card(num, new Unsummon());
    }
}

void Deck::push_card(int player, Card *in) {
    cardlist[player - 1].emplace_back(in);
    cards_left ++;
}

Card* Deck::pop_card(int player) {
    Card* temp = cardlist[player - 1].back();
    cardlist[player - 1].pop_back();
    return temp;
}
