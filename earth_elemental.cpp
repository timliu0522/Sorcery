#include "earth_elemental.h"

Earth_Elemental::Earth_Elemental(int player) : Minion(player) {
    name = "Earth Elemental";
    description = "";
    type = "Minion";
    cost = 3;
    attack = 4;
    defence = 4;
    action_number = 1;
    action_performed = 0;
    has_active = false;
    activated_cost = 0;
}
