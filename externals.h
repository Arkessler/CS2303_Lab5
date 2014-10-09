/* externals.h

Originally coded by Professor Robert Kinicki, modified  by Alexi Kessler

The list of the two globals that are in main but
external to all other components and the global defs.      */

#include "globals.h"
#include "tile.h"
#include "destination.h"

extern Tile Mall[MAX+1][MAX+1][2];
extern Dest Dests[20];
extern int simTime;



