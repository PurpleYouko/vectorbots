#pragma once

#include "vec3f.h"
#include <vector>



#include <stdlib.h>
#include <iostream>

struct cell     //a single cell in the environment grid
{
    
	uint8_t scent[100];		//each element of this array contains a unique scent as an intensity 0 - 255
							//A bot has access to 9 of these at any given time
};

struct sector   // a sector contains 100 cells. useful for tracking where the bots are located and other things.
{
    std::vector<VecBot*> BotsHere;   //a vector that tells us which bots are currently located in this sector
    cell cells[10][10];

};

class EnvGrid  //the entire environment grid consisting of a bunch of sectors
{
    public:
    sector* sectors[20][20]; //that's a lot of cells. Hope we don't experience a lot of slowdown when parsing these babies

    EnvGrid() //constructor. Set all cell variables to zero
    {

    };
    ~EnvGrid()  //destructor. Does the same thing as constructor
    {

    };
};

EnvGrid MyGrid;         //initialize the environment grid




