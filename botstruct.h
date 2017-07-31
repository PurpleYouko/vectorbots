#pragma once

#include "vec3f.h"
#include <vector>
#include <stdlib.h>
#include <iostream>
#include <string>






struct Fart
{
	uint Loudness;
	uint Stench;
	float volume;
};



struct Bcolor
{
	float R;
	float B;
	float G;
	float O;
};


struct Components
{
	uint ComponentType;		//What kind of component is it?
	uint efficiency;		//what efficiency value?


};

struct Cargo
{
	uint CargoType;			// What type of cargo is held in this bay
	uint quantity;			// how many tons of it;
};

struct Sensor
{
    float position;         //The angle of the Sensor with respect to the facing direction
    float arc;              //The arc angle that this Sensor can perceive. Wider arcs cost more energy to process.
    bool active;            //Is this Sensor currently active and being monitored. Turn off from codules to save energy
	uint range;				//How far can this sensor see?
	uint sensorType;		//What kind of thing are we scanning for? Visible light, Infrared, 


    //readbacks
	uint ObjectType;		//what kind of thing are we looking at? star ship? Space station? Planet? Asteroid?
    Bcolor Targetcolor;     //what color is the closest visible target in this sensor?
    uint Targetsize;        //How big is it?
    float TargetDirection;  //what angle is the target from the center of this eye?
    float TargetAngle;      //What angle is it facing
	std::string TargetRace;	//The race of the target object. Returns unknown on first contact. Returns none for scenery objects

};


class VecBot
{
    public:

    // Basic information
    bool Exist;				// does the bot exist
	std::string Race;		// the race identifier
    float X;				// X coordinate
    float Y;				// Y coordinate
    uint GridX;				// Position in the environment grid
    uint GridY;				// Position in the environment grid
    uint Energy;			// Available energy

	
	
    
	uint SlotCount;			// the number of expansion slots in the build
    uint CoduleCount;		// the number of genes in the bot's DNA
    Bcolor BotColor;		// color of the bot in RGB as GLfloats
    double angle;			// The angle that the bot is facing
    double speed;			// the speed at which the bot is moving
							// might need to use speedX and speedY if using trig is too slow
	double Vel;				// Velocity. Much more useful than speed
	double VelAngle;		// Velocity is a vector so it needs a direction
	double speedX;			// current speed in the X direction
	double speedY;			// current speed in the Y direction
	double acc;				// Acceleration factor in the direction of facing

	//calculated values based on components. Calculated once each time a change takes place
	double accFactor;		// Acceleration factor based on the number and power of drives
	uint EnergyProduction;	// Amount of energy produced per cycle. Based on number and type of generators
	uint CondPerCodule;		// Number of conditions that can be evaluated in each codule. Get a more powerful computer to increase this
	uint ActionPerCodule;	// Number of actions that can be performed per codule
	std::vector<Cargo*>Bays;// Allows a number of bays to be dynamically created to hold more than one item type up to maximum capacity
	uint Mass;				// the mass of the bot. Stuff that makes up the bot have finite mass. Also stuff in cargo
	uint MaxCargo;			// Maximum cargo allowed based on the number of cargo bays in the build

	
    std::vector<Codule*> AIP; // the robot's operational code
	sf::Sprite sprite;		// The bot's actual sprite background texture
	sf::Sprite OutLine;		// The outline of the bot
	sf::Sprite Overlay1;	// Custom overlay. Maybe use for showing when a bot is accelerating


    //bot internal structure. senses and stuff
    uint mem[1000];					//Memory array. Raed and write important data here
	std::vector<Sensor*> Sensors;	//Sensor array
	std::vector<Components*> Slot;

    VecBot()    //constructor
    {

    };
    ~VecBot()   //destructor
    {
        X = 0;
        Y = 0;
    };
};


