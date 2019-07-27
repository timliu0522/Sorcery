#include "aura_of_power.h"
#include "State.h"

Aura_of_Power::Aura_of_Power(int player) : Ritual(player) {
    name = "Aura of Power";
    description = "Whenever a minion enters play under your control, it gains +1/+1";
    type = "Ritual";
    cost = 1;
    charge = 4;
    act_cost = 1;
    effect = Effect(EffectType::MEC, get_player(), 0, CollectionType::BOARD, 1, 1);
}
