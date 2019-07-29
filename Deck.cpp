#include "Deck.h"
#include "all_cards.h"
#include <fstream>

Deck::Deck() {
    cards_left = 0;
}

Deck::~Deck() {
    for (int i = 0; i < 2; i++) {
        while (!cardlist[i].empty()) {
            delete cardlist[i].back();
            cardlist[i].pop_back();
        }
    }
}

void Deck::load_deck(std::string filename, int num) {
    std::string cardname;
    std::ifstream ifs(filename);
    while(getline(ifs, cardname)) {
        if (cardname == "Air Elemental")
            push_card(num, new Air_Elemental(num));
        if (cardname == "Earth Elemental")
            push_card(num, new Earth_Elemental(num));
        if (cardname == "Bone Golem")
            push_card(num, new Bone_Golem(num));
        if (cardname == "Apprentice Summoner")
            push_card(num, new Apprentice_Summoner(num));
        if (cardname == "Fire Elemental")
            push_card(num, new Fire_Elemental(num));
        if (cardname == "Master Summoner")
            push_card(num, new Master_Summoner(num));
        if (cardname == "Novice Pyromancer")
            push_card(num, new Novice_Pyromancer(num));
        if (cardname == "Potion Seller")
            push_card(num, new Potion_Seller(num));
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
            push_card(num, new Dark_Ritual(num));
        if (cardname == "Aura of Power")
            push_card(num, new Aura_of_Power(num));
        if (cardname == "Standstill")
            push_card(num, new Standstill(num));
        if (cardname == "Raise Dead")
            push_card(num, new Raise_Dead(num));
        if (cardname == "Recharge")
            push_card(num, new Recharge(num));
        if (cardname == "Banish")
            push_card(num, new Banish(num));
        if (cardname == "Blizzard")
            push_card(num, new Blizzard(num));
        if (cardname == "Disenchant")
            push_card(num, new Disenchant(num));
        if (cardname == "Unsummon")
            push_card(num, new Unsummon(num));
    }
}

void Deck::push_card(int player, std::shared_ptr<Card> in) {
    cardlist[player].emplace_back(in);
    cards_left ++;
}

void Deck::pop_card(int player, std::shared_ptr<Card> out) {
    cardlist[player].pop_back();
}

void Deck::pop_top(int player) {
    setState(Effect(EffectType::MOV, player, 0, CollectionType::HAND));
    setInfo(cardlist[player].back());
    notifyObservers();
    cardlist[player].pop_back();
}