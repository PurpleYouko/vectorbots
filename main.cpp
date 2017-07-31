




#include "main.h"

using namespace std;


float rnd(float X) 
{
	return static_cast <float> (rand()) / (static_cast <float> (RAND_MAX/X));
}

static void resize(int width, int height)  //handles resizing of the window
{
    const float ar = (float) width / (float) height;

   
}

static void display(void) //does our drawing for us
{
    

   
}

void LoadBots( )
{
    // populates the botlist array with all the relevent information from files.
    // need to write a loading function here but for now hard code it
    // initialize random seed
    srand (time(NULL));
    string line;
    int mode;
	
    for (int bot_count = 1; bot_count <= 10; bot_count++)
    {
        VecBot* thisbot = new (nothrow) VecBot; //create local instance of a bot
        //sets a random color
        thisbot->BotColor.R = (int) rnd(255) + 1;	//range of 1 to 255
		thisbot->BotColor.B = (int) rnd(255) + 1;
		thisbot->BotColor.G = (int) rnd(255) + 1;
		thisbot->BotColor.O = 100;													//set opacity to 50 so it's semi transparent
		thisbot->sprite.setTexture(BotBack);										//apply global texture. defined in h file and preloaded in main
		thisbot->sprite.setColor(sf::Color(thisbot->BotColor.R, thisbot->BotColor.B, thisbot->BotColor.G, thisbot->BotColor.O));	//Apply colors to the sprite
		thisbot->OutLine.setTexture(BotOutline);
		//thisbot->OutLine.setColor(sf::Color(0, 0, 0, 0));

        //randomizes bot position in the range of 1 to WinX and WinY
        thisbot->X = (int) rnd(WinX) + 1;	// 1 to WinX
        thisbot->Y = (int) rnd(WinY) + 1;	// 1 to WinY
        thisbot->angle = rnd(360); // 0 to 360
		//not moving
		thisbot->speedX = 0;
		thisbot->speedY = 0;
		thisbot->Vel = 0;
		thisbot->VelAngle = 0;
        //thisbot->speed = (float)rand() / ((float)RAND_MAX) / 10; // 0.0 to 0.1
		//cout << "Bot " << bot_count << " x = " << thisbot->X << " y = " << thisbot->Y << endl;

        //add this bot to the environment grid. 20 by 20
        thisbot->GridX = (int)((thisbot->X + 1) * 10);
        thisbot->GridY = (int)((thisbot->Y + 1) * 10);
		//set the center of rotation
		thisbot->sprite.setOrigin(sf::Vector2f(12.5, 12.5));
		thisbot->OutLine.setOrigin(sf::Vector2f(12.5, 12.5));

        //load in bot species files. To be done later
		/*
        ifstream infile;
        infile.open ("testbot.txt");
        while(getline(infile, line)) //reads in a line
        {
            //cout << line << endl;

            if(line.compare("end") == 0)    //resetting mode to zero must happen first or else it tries to process the word "end"
            {
                //cout << "mode reset to zero" << endl;
                mode = 0;
            }
            //tried this with a switch but it kept complaining about crossing initialization of variables
            if(mode == 1)
            {//loading bot shape line by line
                //cout << "start reading in data" << " " << endl;
                Lines* newline = new (nothrow) Lines; //create a local instance of lines

                string start_angle;
                string start_rad;
                string end_angle;
                string end_rad;
                uint i = 0;     // loop counter
                uint ind = 0;   // index pointer
                string tmp[3];  // array of 4 strings (0 - 3).

                for (i=0; i<line.length(); i++) //scans the line one character at a time
                {
                    //cout << i << endl;
                    if (line[i] == 44) // found a comma so this string is done!!
                    {
                        ind++;      // increment the index pointer to move to the next string in the array
                        i++;        // increment the character pointer so it skips the comma
                    }
                    //cout << "no comma, should copy the element now" << endl;
                    tmp[ind].push_back(line[i]);    // append the character to the end of the string
                }

                // set the values into the newline instance
                newline->Start.A = atof(tmp[0].c_str());
                newline->Start.R = atof(tmp[1].c_str());
                newline->End.A = atof(tmp[2].c_str());
                newline->End.R = atof(tmp[3].c_str());


                //cout << newline->Start.A << " " << newline->Start.R << " " << newline->End.A << " " << newline->End.R << endl;
                thisbot->lines.push_back(newline); //add the vector to the local structure

            }
            if(mode == 2)
            {//this is the actual code that describes the way the bot behaves

            }



            //END MODE Selection
            // NOTE setting the mode must be done after the mode selection or else it gets very very confused.
            if(line.compare("shape") == 0)
            {
                //cout << "start reading shape data" << endl;
                mode = 1;
            }
            if(line.compare("program") == 0)
            {
                //cout << "start reading shape data" << endl;
                mode = 2;
            }
        }
        infile.close();
		*/
        BotList.push_back(thisbot); //add the bot to the list
        //delete thisbot;
    }
    cout << "Size of bot list" << BotList.size() << endl;

}


//Handles all keypress events
static void key(unsigned char key, int x, int y)
{

    //cout << "The key pressed is " << key << endl;
    switch (key)
    {
        case 27 :
        case 'q':
            exit(0);
            break;

        case '+':
            Zoom += 0.1f;
            if (Zoom > -2){Zoom = -2;}
            cout << Zoom << endl;

            break;

        case '-':
            Zoom -= 0.1f;
            cout << Zoom << endl;
            break;
        case 'a':
            Angle -= 1;
            break;
        case 's':
            Angle += 1;
            break;
    }

}

//mouse button press
void mouse(int btn, int state, int x, int y)
{
    if(btn == 0 )
    {
        cout << "button 1 clicked" << endl;
    }
    if(btn == 0 )
    {
        cout << "button 1 released" << endl;
    }


    if(btn == 2 ) // Mouse button 2 selects vertices
    {
        cout << "button 2 clicked" << endl;
    }
    if(btn == 2 )
    {
        cout << "button 2 released" << endl;
    }
}

void mouseWheel(int button, int dir, int x, int y) //much better function than the mouse click wheel simulation
{
    if (dir > 0)
    {
        cout << "wheel up" << endl;
    }
    else
    {
        cout << "wheel down" << endl;
    }
}

//MOUSE MOVEMENTS!!
void mouseMove(int x, int y)
{
    cout << "mouse moved" << endl;
}

static void mainLoop(void)
{
    //main program loop
    // do the calculations for bot positions and stuff
	float MaxVel = 0.1;
	float SpeedX;
	float SpeedY;
	float AddSpeedX;
	float AddSpeedY;
	float TotalSpeedX;
	float TotalSpeedY;
	float NewVel;
	float NewAngle;
	float TestAngle;
	float Hyp;
    for(uint i=0;i<BotList.size();i++)
    {
        // move bots
        VecBot* thisbot = BotList.at(i); //create local label to a specific bot in the list
        //maybe the bot will change direction a little
        if(rnd(100) > 97)
        {
            thisbot->angle += 5;
			if(thisbot->angle > 360) thisbot->angle -= 360;
        } else if(rnd(100) < 3)
        {
            thisbot->angle -= 5;
			if(thisbot->angle < 0) thisbot->angle += 360;
        }

        double RadAngle = thisbot->angle * PI / 180;
        if (i == 0 && botswitch == 0)
        {
            cout << thisbot->X << " " << thisbot->Y << " " << thisbot->speed << endl;
        }
		//randomly make a bot accelerate in the direction it's facing
		if(rnd(100) > 99.5)
        {
			thisbot->acc = rnd(0.1f);
		}
		if ( thisbot->acc > 0 )	//we are accelerating at a specified angle so calculate new velocity vector
		{
			//what are the new x and y vectors to be added?
			AddSpeedX = (thisbot->acc * sin(thisbot->angle * PI / 180));
			AddSpeedY = (thisbot->acc * cos(thisbot->angle * PI / 180));

			Hyp = findHyp(AddSpeedX, AddSpeedY);	//find the magnitude of the added velocity vector. Should be precisely the same as acc
			if (Hyp != thisbot->acc) cout << "Calculated acceleration different to applied acceleration " << Hyp << " " << thisbot->acc << endl;
			
			//add the new acceleration value to the existing speed
			thisbot->speedX += AddSpeedX;
			thisbot->speedY += AddSpeedY;
			//find magnitude of the combined speeds
			NewVel = findHyp(thisbot->speedX, thisbot->speedY);
			//find the angle of the new velocity. 
			NewAngle = findAngle(thisbot->speedX, thisbot->speedY);
			if (NewVel > MaxVel)
			{
				//reduce overall velocity to match max
				NewVel = MaxVel;
				//calculate new X and Y vectors
				thisbot->speedX = (NewVel * sin(NewAngle * PI / 180));
				thisbot->speedY = (NewVel * cos(NewAngle * PI / 180));
			}

			thisbot->VelAngle = NewAngle;	//this is kind of irrelevent
			thisbot->Vel = NewVel;
			
			
			
		}

		//update positions
        thisbot->X += thisbot->speedX;
        thisbot->Y -= thisbot->speedY;		//screen coordinates are upside down
        if (thisbot->X > WinX)
        {
            thisbot->X -= WinX;
        }
        if (thisbot->X < 0 )
        {
            thisbot->X += WinX;
        }
        if (thisbot->Y > WinY)
        {
            thisbot->Y -= WinY;
        }
        if (thisbot->Y < 0)
        {
            thisbot->Y += WinY;
        }
        if (i == 0 && botswitch == 0)
        {
            cout << thisbot->X << " " << thisbot->Y << endl;
            botswitch = 1;
        }
		//reset acceleration
		thisbot->acc = 0;
    }
    //done moving bots now
    //refresh the display
    
}



/* Program entry point */

int main(int argc, char *argv[])
{
    WinX = 1000;
	WinY = 800;
	//load basic bot texture
    if (!BotBack.loadFromFile("../graphics/BotSprite.png"))
	{
		cout << "BotBack not loaded" << endl;
	}
	if (!BotOutline.loadFromFile("../graphics/BotOutLine.png"))
	{
		cout << "BotBack not loaded" << endl;
	}
	LoadBots();             //initial bot loading
	//Create the window
	sf::RenderWindow window(sf::VideoMode(WinX, WinY), "VectorBots");
	int Xsize = window.getSize().x;
	int Ysize = window.getSize().y;
	cout << "window size X is " << Xsize << endl;
	cout << "window size Y is " << Ysize << endl;

	
	
    // run the program as long as the window is open
    while (window.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
        }
		//Calculations here so we need a bot vector loop
		mainLoop();

        // clear the window with background color
        window.clear(sf::Color::White);

        // draw everything here...
        // window.draw(...);
		//draw the GUI

		//draw the bots
		for(uint i=0;i<BotList.size();i++)
		{
			VecBot* thisbot = BotList.at(i); //create local label to access a specific bot from the list
			thisbot->OutLine.setRotation(thisbot->angle);
			thisbot->sprite.setPosition(thisbot->X, thisbot->Y);
			thisbot->OutLine.setPosition(thisbot->X, thisbot->Y);
			window.draw(thisbot->sprite);
			window.draw(thisbot->OutLine);
		}

        // end the current frame
        window.display();
    }
   

    return EXIT_SUCCESS;
}
