#pragma once


struct Conditions
{
    uint MemLoc;
    uint OpCode;
    uint Val;
    bool Or_Bit;
    bool And_Bit;
};

struct Actions
{
    uint MemLoc;
    uint OpCode;
    uint Val;
};

struct Codule
{
    int fucks_given;
	std::vector<Conditions*> Cond;
    std::vector<Actions*> Act;
	std::vector<Actions*> ElseAct;
    bool Active;
};
