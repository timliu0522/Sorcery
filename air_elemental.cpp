#include "air_elemental.h"

Air_Elemental::Air_Elemental(int player) : Minion(player) {
    name = "Air Elemental";
    description = "";
    type = "Minion";
    cost = 0;
    attack = 1;
    defence = 1;
    action_number = 1;
    action_performed = 0;
    has_active = false;
    activated_cost = 0;
}
