#pragma once

typedef unsigned int uint;

// object types
enum { ship, base, planet, asteroid };
// sensor types
enum { visible, infrared, ultraviolet, radar, subspace };
// component types. This could be actually loaded from a file to allow for easy expansions
enum { drive, generator, computer, armament, shield, armor, powerbattery, repairmodule, miningmodule, cargobay };
// Drive types
enum { ion, impulse, singularity, warp };
// Generator types
enum { treadmill, hydrogen, fission, fusion, conversion };
// computer types
enum { zx81, spectrum, atari, PC, super, quantum };
// armor types 
enum { iron, steel, kevlar, adamantium, indistructium, active, adaptive, proactive };
// shield types
enum { force_field, laser_screen, plasma_screen, phase_shield, absorbtive_screen };
// armament types
enum { basic_rockets, torpedoes, laser, disruptor, wave, beam };



// general all purpose upgrade levels
enum { mkI, mkII, mkIII, mkIV, mkV, mkVI, mkVII, mkVIII, mkIX, mkX };






