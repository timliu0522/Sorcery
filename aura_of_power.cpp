#include "aura_of_power.h"
#include "State.h"

Aura_of_Power::Aura_of_Power() {
    name = "Aura of Power";
    description = "Whenever a minion enters play under your control, it gains +1/+1";
    type = "Ritual";
    cost = 1;
    effect = EffectType::MEC;
    charge = 4;
    act_cost = 1;
}
