CMAKE_MINIMUM_REQUIRED(VERSION 3.14)
project(Codes)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -lX11")

add_executable(sorcery main.cpp Subject.h Subject.cpp Player.h Player.cpp ascii_graphics.cc ascii_graphics.h air_elemental.cpp
        air_elemental.h all_cards.h apprentice_summoner.cpp apprentice_summoner.h aura_of_power.cpp aura_of_power.h
        banish.cpp banish.h blizzard.cpp blizzard.h Board.cpp Board.h bone_golem.cpp bone_golem.h Card.h Card.cpp Collection.cpp Collection.h
        dark_ritual.cpp dark_ritual.h Deck.cpp Deck.h disenchant.cpp disenchant.h earth_elemental.cpp earth_elemental.h Enchantment.cpp Enchantment.h enrage.cpp enrage.h
        fire_elemental.cpp fire_elemental.h game.cpp game.h giant_strength.cpp giant_strength.h Grave.cpp Grave.h Hand.cpp Hand.h haste.cpp haste.h magic_fatigue.cpp magic_fatigue.h master_summoner.cpp master_summoner.h
        Minion.cpp Minion.h novice_pyromancer.cpp novice_pyromancer.h
        Observer.cpp Observer.h potion_seller.cpp potion_seller.h raise_dead.cpp raise_dead.h recharge.cpp recharge.h Ritual.cpp Ritual.h silence.cpp silence.h Spell.cpp Spell.h standstill.cpp standstill.h State.h unsummon.cpp unsummon.h)