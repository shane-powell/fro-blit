#include "rib-blit.hpp"
#include "assets.hpp"
using namespace blit;

int32_t maxX = 320;
int32_t minX = 0;
int32_t maxY = 230;
int32_t minY = 0;

int32_t rowHeight = 40;

class Actor {
public:
	virtual ~Actor() = default;
	//Point loc = Point(16, 16);
	Size size;
	Rect spriteLocation;
	float x = 0.0f;
	float y = 0.0f;

	Actor() = default;

	Actor(float xIn, float yIn)
	{
		this->x = xIn;
		this->y = yIn;
	}

	/*virtual Size GetSize()
	{
		return this->size;
	}

	virtual Rect GetSpriteLocation()
	{
		return this->spriteLocation;
	}

	Point GetLocation()
	{
		return this->loc;
	}*/
};

class Eagle : public Actor
{
	void Update()
	{
		this->y += 12;
	}	
};

enum PlayerState
{
	Alive,
	Splat,
	Splash,
	Eagle
};

enum GameState {
	Menu,
	Play,
	GameOver
};

GameState state = Menu;
SpriteSheet* backGroundSurface;
SpriteSheet* menu0ss;
SpriteSheet* menu1ss;
SpriteSheet* gameOver;

class Game
{
public:

	int8_t aiOffset = 0;

	int8_t vibrationTimer = 0;

	Game()
	{

	}

	Game(int8_t noPlayers)
	{

	}

	void Update()
	{
		if(vibrationTimer > 0)
		{
			blit::vibration = 1;
			vibrationTimer--;
		}
		else
		{
			blit::vibration = 0;
		}
	}


};

Game game;

const uint32_t tilemap_width = 32;

const uint32_t tilemap_height = 16;



TileMap world(const_cast<uint8_t*>(map1), nullptr, Size(tilemap_width, tilemap_height), nullptr);

///////////////////////////////////////////////////////////////////////////
//
// init()
//
// setup your game here
//
void init() {
	//set_screen_mode(ScreenMode::hires);

	if (screen.sprites != nullptr)
	{
		screen.sprites->data = nullptr;
		screen.sprites = nullptr;
	}
	
	//screen.sprites = SpriteSheet::load(sprites_data);

	world.sprites = SpriteSheet::load(tile_sheet_1);
	state = Play;

}

void DrawMenu()
{
	
}

void DrawWorld()
{
	Vec2 wo(64, 40);

	/*world.transform =
		Mat3::identity() *
		Mat3::translation(wo) *
		Mat3::scale(Vec2(0.5, 0.5)) *
		Mat3::translation(Vec2(-128, -80));*/

	world.draw(&screen, Rect(0, 0, 320, 240), nullptr);

}

void DrawGame()
{
	DrawWorld();
}

void DrawGameOver()
{
}

///////////////////////////////////////////////////////////////////////////
//
// render(time)
//
// This function is called to perform rendering of the game. time is the 
// amount if milliseconds elapsed since the start of your game
//
void render(uint32_t time) {
	screen.pen = Pen(0, 0, 0, 255);
	//screen.mask = nullptr;
	
	// clear the screen -- screen is a reference to the frame buffer and can be used to draw all things with the 32blit
	screen.clear();
	

	switch (state)
	{
	case Menu:
		DrawMenu();
		break;
	case Play:
		DrawGame();
		break;
	case GameOver:
		DrawGameOver();
		break;
	}
}



///////////////////////////////////////////////////////////////////////////
//
// update(time)
//
// This is called to update your game state. time is the 
// amount if milliseconds elapsed since the start of your game
//
void update(uint32_t time) {

	static uint16_t lastButtons = 0;
	uint16_t changed = blit::buttons ^ lastButtons;
	uint16_t pressed = changed & blit::buttons;
	uint16_t released = changed & ~blit::buttons;

	switch (state)
	{
	case Menu:
		
		break;
	case Play:
	
		break;
	case GameOver:
		
		break;
	}

	lastButtons = blit::buttons;
}