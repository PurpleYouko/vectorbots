#pragma once


struct Conditions
{
    uint MemLoc;		//Memory Location
    uint OpCode;		//Numerical code to control which conditions are checked
    uint Val;
    bool Or_Bit;		//Used to seperate conditions.
    bool And_Bit;		//Used to seperate conditions. And operations take precidence
};

struct Actions
{
    uint MemLoc;		//Memory Location
    uint OpCode;		//Numerical code to control which actionss are performed
    uint Val;
};

// a codule is one module that consists of a list of conditions and a list of actions.
// If all conditions are met according to predefined rules (And_Bit, Or_Bit) then returns TRUE. ALL actions are performed.
// If conditions are NOT met, returns FALSE. ALL present ElseActions are performed.
struct Codule						
{
	int fucks_given;				//yeah.... probably don't need this. It's there to debug something. ^_^
	std::vector<Conditions*> Cond;	//Conditions list
    std::vector<Actions*> Act;		//Actions list
	std::vector<Actions*> ElseAct;	//Else Actions list
    bool Active;					//Is this codule active. only perform the codule if active. otherwise ignore it entirely. This bit can be set from any codule
};
