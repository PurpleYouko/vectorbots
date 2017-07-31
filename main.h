#pragma once

#include <stdlib.h>
#include <iostream>
#include <cstdint>
#include <iostream>
#include <string>
#include <cstdio>
#include <fstream>
#include <vector>
#include <SFML/Graphics.hpp>



#include <math.h>
#include <time.h>

#include "trig.h"
#include "vec3f.h"
#include "datatypes.h"

#include "AI.h"
#include "botstruct.h"
#include "environment.h"




// This stuff should all be loaded from a file at some point
class ConfigSetup
{
    public:

    float Zoom;
    double Angle;
    double MAX_X;
    double MAX_Y;
    double MIN_X;
    double MIN_Y;

    ConfigSetup()   //constuctor
    {
        Zoom = -3.0f;
        Angle = 0.0f;
        MAX_X = 2.0f;
        MAX_Y = 2.0f;
        MIN_Y = -2.0f;
        MIN_X = -2.0f;
    };
    ~ConfigSetup()  //destructor
    {

    };
};

ConfigSetup Config;     //global config

float Zoom = -3.0f;
double Angle = 0.0f;
double MAX_X = 2.0f;
double MAX_Y = 2.0f;
double MIN_X = -2.0f;
double MIN_Y = -2.0f;

int botswitch = 0;

//window size
int WinX;
int WinY;

const float light_ambient[]  = { 0.0f, 0.0f, 0.0f, 1.0f };
const float light_diffuse[]  = { 1.0f, 1.0f, 1.0f, 1.0f };
const float light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
const float light_position[] = { 2.0f, 5.0f, 5.0f, 0.0f };

const float mat_ambient[]    = { 0.7f, 0.7f, 0.7f, 1.0f };
const float mat_diffuse[]    = { 0.8f, 0.8f, 0.8f, 1.0f };
const float mat_specular[]   = { 1.0f, 1.0f, 1.0f, 1.0f };
const float high_shininess[] = { 100.0f };



//Base texture
sf::Texture BotBack;
sf::Texture BotOutline;
sf::Texture BotAccelerate;

//lists and vectors    
std::vector <VecBot*> BotList;  //create the list to hold all the bots. 


//prototypes
int main(int argc, char *argv[]);
static void resize(int width, int height);
static void display(void);
static void key(unsigned char key, int x, int y);
void mouse(int btn, int state, int x, int y);
void mouseWheel(int button, int dir, int x, int y);
void mouseMove(int x, int y);
static void mainLoop(void);
void LoadBots();
void AddBot();

//randum function
float rnd(float X);

