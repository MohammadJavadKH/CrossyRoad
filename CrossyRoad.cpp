#include "Genio.h"
#include "stdlib.h"
#include <ctime>

struct object {
	G_Rect pos;
	G_Texture* texture;
};
enum GameState { START, PLAY, EXITE };

int score;		// the counter keep the number of box that should be appear
int FPS = 300;
int startLoop, endLoop;
int delay = 1000 / FPS;
int i = 0;
int t;
bool lose = false;
int a[1000];
int speed;
int sp;
bool woods = false;
int up;
int lef;
int select;
int cameraspeed = 1;
int camera = 1;
int starttime;
int eagl = 0;
char b[15];
bool righttree = false;
bool lefttree = false;
bool uptree = false;
bool downtree = false;
bool eagles = false;


object play_btn;
object road;
object tree;
object water;
object way;
object grass;
object car1;
object car2;
object car3;
object car4;
object train;
object wood;
object animal;
object animal1;
object animal2;
object animal3;
object animal4;
object red;
object green;
object startp;
object over;
object eagle;




SDL_RendererFlip flip = SDL_FLIP_HORIZONTAL;
G_Texture* play_bt;
G_Texture* T_road;
G_Texture* T_grass;
G_Texture* T_water;
G_Texture* T_way;
G_Texture* T_tree;
G_Texture* T_car1;
G_Texture* T_car2;
G_Texture* T_car3;
G_Texture* T_car4;
G_Texture* T_train;
G_Texture* T_wood;
G_Texture* T_animal;
G_Texture* T_animal1;
G_Texture* T_animal2;
G_Texture* T_animal3;
G_Texture* T_animal4;
G_Texture* T_green;
G_Texture* T_red;
G_Texture* T_startp;
G_Texture* T_over;
G_Texture* T_eagle;
G_Sound* trainalarm;
G_Sound* carsquish;
G_Sound* river;
G_Sound* trainpass;
G_Sound* carpass;
G_Sound* eagle1;

G_Rect windowPos;

void initialize();
void start();
void play();
void draw();
void load();
void destroy();

GameState gameState = START;

int main(int argc, char* args[])
{
	G_InitSDL();
	windowPos.x = SDL_WINDOWPOS_UNDEFINED;
	windowPos.y = SDL_WINDOWPOS_UNDEFINED;
	windowPos.w = 800;
	windowPos.h = 500;
	G_CreateWindow("Crossy Road", windowPos, 255, 255, 255);
	load();
	while (gameState != EXITE){
		startLoop = G_GetTicks();
		//Clear screen
		G_Update();
		switch (gameState){
		case START:    start();		break;
		case PLAY:     play();			break;
		case EXITE:		break;
		}
	}
	destroy();
	return 0;
}

void load()
{
	play_bt = G_LoadImage("crossyroad/play_btn.png");
	T_way = G_LoadImage("crossyroad/way.jpg");
	T_tree = G_LoadImage("crossyroad/tree.jpg", 1, 149, 37);
	T_grass = G_LoadImage("crossyroad/grass.jpg", 255, 255, 255);
	T_road = G_LoadImage("crossyroad/road.jpg");
	T_water = G_LoadImage("crossyroad/water.jpg", 255, 255, 255);
	T_wood = G_LoadImage("crossyroad/wood.jpg", 255, 255, 255);
	T_car1 = G_LoadImage("crossyroad/car1.jpg", 19, 19, 19);
	T_car2 = G_LoadImage("crossyroad/car2.jpg", 19, 19, 19);
	T_car3 = G_LoadImage("crossyroad/car3.jpg", 255, 255, 255);
	T_car4 = G_LoadImage("crossyroad/car4.jpg",255,255,255);
	T_train = G_LoadImage("crossyroad/train.jpg", 255, 255, 255);
	T_animal1 = G_LoadImage("crossyroad/animal1.jpg", 255, 255, 255);
	T_animal2 = G_LoadImage("crossyroad/animal2.jpg", 255, 255, 255);
	T_animal3 = G_LoadImage("crossyroad/animal3.jpg", 255, 255, 255);
	T_animal4 = G_LoadImage("crossyroad/animal4.jpg", 255, 255, 255);
	T_green = G_LoadImage("crossyroad/green.jpg", 255, 255, 255);
	T_red = G_LoadImage("crossyroad/red.jpg", 255, 255, 255);
	T_eagle = G_LoadImage("crossyroad/eagle.jpg", 0, 0, 0);
	T_startp = G_LoadImage("crossyroad/startp.jpg");
	T_over = G_LoadImage("crossyroad/over.jpg");
	trainalarm = G_LoadSound("crossyroad/trainalarm.wav");
	carsquish = G_LoadSound("crossyroad/carsquish.wav");
	carpass = G_LoadSound("crossyroad/carpass.wav");
	river = G_LoadSound("crossyroad/river.wav");
	trainpass = G_LoadSound("crossyroad/trainpass.wav");
	eagle1 = G_LoadSound("crossyroad/eagle1.mp3");
	G_Font* font = G_OpenFont("crossyroad/arial.ttf", 60);
}

//
void initialize()
{
	srand(time(0));
	for (int i = 990; i < 1000; i++)
	{
		a[i] = 10;
	}
	for (int i = 0; i < 990; i++)
	{
		a[i] = rand();
	}
	animal.pos.x = 350;animal.pos.y = 200;
	woods = false;
	righttree = false;
	lefttree = false;
	uptree = false;
	downtree = false;
	score = 0;
	i = 0;
	speed = 0;
	up = 0;
	lef = 0;
}
;void start()
{
	initialize();
	startp.texture = T_startp;
	startp.pos = { 0,0,800,500 };
	G_Draw(T_startp, &startp.pos, false);
	play_btn.texture = play_bt;
	play_btn.pos = { 350,400,100,50 };
	G_Draw(play_bt, &play_btn.pos, false);
	animal1.texture = T_animal1;
	animal1.pos = { 0,0,100,100 };
	G_Draw(T_animal1, &animal1.pos, false);
	animal2.texture = T_animal2;
	animal2.pos = { 250,0,100,100 };
	G_Draw(T_animal2, &animal2.pos, false);
	animal3.texture = T_animal3;
	animal3.pos = { 450,0,100,100 };
	G_Draw(T_animal3, &animal3.pos, false);
	animal4.texture = T_animal4;
	animal4.pos = { 700,0,100,100 };
	G_Draw(T_animal4, &animal4.pos, false);
	switch (G_Event())
	{
	case G_MOUSEBUTTONDOWN:
		switch (G_Mouse)
		{
		case G_BUTTON_LEFT:
			if (G_motion.x > 350 && G_motion.x < 450 && G_motion.y > 400 && G_motion.y < 450)
			{
				initialize();
				starttime = G_GetTicks();
				G_Sound* play = G_LoadSound("sound/play.wav");
				G_PlaySound(play, 0);
				gameState = PLAY;lose = false;
			}
			if (G_motion.x > 0 && G_motion.x < 100 && G_motion.y > 0 && G_motion.y < 100)
				select = 1;
			if (G_motion.x > 250 && G_motion.x < 350 && G_motion.y > 0 && G_motion.y < 100)
				select = 2;
			if (G_motion.x > 450 && G_motion.x < 550 && G_motion.y > 0 && G_motion.y < 100)
				select = 3;
			if (G_motion.x > 700 && G_motion.x < 800 && G_motion.y > 0 && G_motion.y < 100)
				select = 0;
			break;
		}
	}
	//G_Font* font = G_OpenFont("crossyroad/arial.ttf", 50);
	//G_Texture* font_texture0 = G_LoadFont(font, "selected animal : elephant", 0, 0, 0);
	//G_Texture* font_texture1 = G_LoadFont(font, "selected animal : lady-bug", 0, 0, 0);
	//G_Texture* font_texture2 = G_LoadFont(font, "selected animal : rabbit", 0, 0, 0);
	//G_Texture* font_texture3 = G_LoadFont(font, "selected animal : deer", 0, 0, 0);
	//G_Rect font_pos0 = { 300,250,200,50 };
	switch (select) {
	case 0:
		//	G_Draw(font_texture0, &font_pos0, false);
		T_animal = T_animal4;
		;break;
	case 1:
		//	G_Draw(font_texture1, &font_pos0, false);
		T_animal = T_animal1;
		;break;
	case 2:
		//	G_Draw(font_texture2, &font_pos0, false);
		T_animal = T_animal2;
		;break;
	case 3:
		//	G_Draw(font_texture3, &font_pos0, false);
		T_animal = T_animal3;
		;break;
	}
}
// Draw all object in play loop
void draw()
{
	int j = -49500;
	for (int i = 0;i < 1000;i++) {
		switch (a[i] % 6) {
		case 0:
			water.texture = T_water;
			water.pos = { 0,j + speed,800,50 };
			G_Draw(T_water, &water.pos, false);
			if (j + speed + 50 == animal.pos.y && !lose)
				G_PlaySound(river, 0);
			switch (a[i - 2] % 3)
			{
			case 0:
				wood.texture = T_wood;
				wood.pos = { 50,j + speed,100,50 };
				G_Draw(T_wood, &wood.pos, false);
				if (wood.pos.x - animal.pos.x < 50 && wood.pos.x - animal.pos.x > -100 && animal.pos.y <= wood.pos.y + 5 && animal.pos.y >= wood.pos.y - 5) {
					woods = true;
				}
				wood.pos = { 450,j + speed,100,50 };
				G_Draw(T_wood, &wood.pos, false);
				if (wood.pos.x - animal.pos.x < 50 && wood.pos.x - animal.pos.x > -100 && animal.pos.y <= wood.pos.y + 5 && animal.pos.y >= wood.pos.y - 5) {
					woods = true;
				}
				wood.pos = { 650,j + speed,100,50 };
				G_Draw(T_wood, &wood.pos, false);
				if (wood.pos.x - animal.pos.x < 50 && wood.pos.x - animal.pos.x > -100 && animal.pos.y <= wood.pos.y + 5 && animal.pos.y >= wood.pos.y - 5) {
					woods = true;
				}
				if (water.pos.y == animal.pos.y && !woods)
					lose = true;
				break;
			case 1:
				wood.texture = T_wood;
				wood.pos = { 100,j + speed,100,50 };
				G_Draw(T_wood, &wood.pos, false);
				if (wood.pos.x - animal.pos.x < 50 && wood.pos.x - animal.pos.x > -100 && animal.pos.y <= wood.pos.y + 5 && animal.pos.y >= wood.pos.y - 5) {
					woods = true;
				}
				wood.pos = { 300,j + speed,100,50 };
				G_Draw(T_wood, &wood.pos, false);
				if (wood.pos.x - animal.pos.x < 50 && wood.pos.x - animal.pos.x > -100 && animal.pos.y <= wood.pos.y + 5 && animal.pos.y >= wood.pos.y - 5) {
					woods = true;
				}
				wood.pos = { 500,j + speed,100,50 };
				G_Draw(T_wood, &wood.pos, false);
				if (wood.pos.x - animal.pos.x < 50 && wood.pos.x - animal.pos.x > -100 && animal.pos.y <= wood.pos.y + 5 && animal.pos.y >= wood.pos.y - 5) {
					woods = true;
				}
				wood.pos = { 700,j + speed,100,50 };
				G_Draw(T_wood, &wood.pos, false);
				if (wood.pos.x - animal.pos.x < 50 && wood.pos.x - animal.pos.x > -100 && animal.pos.y <= wood.pos.y + 5 && animal.pos.y >= wood.pos.y - 5) {
					woods = true;
				}
				if (water.pos.y == animal.pos.y && !woods)
					lose = true;
				break;
			case 2:
				wood.texture = T_wood;
				wood.pos = { 100,j + speed,100,50 };
				G_Draw(T_wood, &wood.pos, false);
				if (wood.pos.x - animal.pos.x < 50 && wood.pos.x - animal.pos.x > -100 && animal.pos.y <= wood.pos.y + 5 && animal.pos.y >= wood.pos.y - 5) {
					woods = true;
				}
				wood.pos = { 300,j + speed,100,50 };
				G_Draw(T_wood, &wood.pos, false);
				if (wood.pos.x - animal.pos.x < 50 && wood.pos.x - animal.pos.x > -100 && animal.pos.y <= wood.pos.y + 5 && animal.pos.y >= wood.pos.y - 5) {
					woods = true;
				}
				wood.pos = { 700,j + speed,100,50 };
				G_Draw(T_wood, &wood.pos, false);
				if (wood.pos.x - animal.pos.x < 50 && wood.pos.x - animal.pos.x > -100 && animal.pos.y <= wood.pos.y + 5 && animal.pos.y >= wood.pos.y - 5) {
					woods = true;
				}
				if (water.pos.y == animal.pos.y && !woods)
					lose = true;
				break;
			}


			break;
		case 1:
			way.texture = T_way;
			way.pos = { 0,j + speed,800,50 };
			G_Draw(T_way, &way.pos, false);
			switch (a[i-2]%2)
			{
			case 0:
				train.texture = T_train;
				train.pos = { -((sp * 5) % 9000) + 2000 ,j + speed,500,50 };
				G_Draw(T_train, &train.pos, false);
				if (-((sp * 5) % 9000) + 2000 > -400 && -((sp * 10) % 7000) + 2000 < 1500) {
					red.texture = T_red;
					red.pos = { 750,j + speed,50,50 };
					G_Draw(T_red, &red.pos, false);
					G_PlaySound(trainalarm, 0);
				}
				else {
					green.texture = T_red;
					green.pos = { 750,j + speed,50,50 };
					G_Draw(T_green, &green.pos, false);
				}
				break;
			case 1:
				train.texture = T_train;
				train.pos = { ((sp * 5) % 9000) - 2000,j + speed,500,50 };
				G_Draw(T_train, &train.pos, false);
				if (((sp * 5) % 9000) - 2000 < 1200 && ((sp * 10) % 7000) - 2000 > -1500) {
					red.texture = T_red;
					red.pos = { 0,j + speed,50,50 };
					G_Draw(T_red, &red.pos, false);
				}
				else {
					green.texture = T_red;
					green.pos = { 0,j + speed,50,50 };
					G_Draw(T_green, &green.pos, false);
				}
				break;
			}
			break;
		case 2:case 3:
			road.texture = T_road;
			road.pos = { 0,j + speed,800,50 };
			G_Draw(T_road, &road.pos, false);
			if (j + speed + 50 == animal.pos.y && !lose)
			G_PlaySound(carpass, 0);
			switch (a[i - 2] % 5)
			{
			case 0:
				car1.texture = T_car1;
				car1.pos = { -((sp * 2) % 900) + 800,j + speed,100,50 };
				G_Draw(T_car1, &car1.pos, false);
				car3.texture = T_car1;
				car3.pos = { -((sp * 2) % 900) + 1800,j + speed,100,50 };
				G_Draw(T_car3, &car3.pos, false);
				break;
			case 1:
				car3.texture = T_car3;
				car3.pos = { -((sp) % 950) + 800,j + speed,100,50 };
				G_Draw(T_car3, &car3.pos, false);
				break;
			case 2:
				car1.texture = T_car1;
				car1.pos = { -((sp * 2) % 1150) + 800,j + speed,100,50 };
				G_Draw(T_car1, &car1.pos, false);
				break;
			case 3:
				car2.texture = T_car2;
				car2.pos = { -((sp) % 900) + 800,j + speed,100,50 };
				G_Draw(T_car2, &car2.pos, false);
				break;
			case 4:
				car4.texture = T_car4;
				car4.pos = { ((sp * 2) % 1050) - 125,j + speed,100,50 };
				G_Draw(T_car4, &car4.pos, false);
				car3.texture = T_car3;
				car3.pos = { -((sp * 2) % 950) - 225,j + speed,100,50 };
				G_Draw(T_car3, &car3.pos, false);
				break;
			}
			;break;
		case 4:case 5:
			grass.texture = T_grass;
			grass.pos = { 0,j + speed,800,50 };
			G_Draw(T_grass, &grass.pos, false);
			tree.texture = T_tree;
			tree.pos = { 750,j + speed,50,50 };
			G_Draw(T_tree, &tree.pos, false);
			if (animal.pos.y == tree.pos.y && animal.pos.x + 50 == tree.pos.x)
				righttree = true;

			if (animal.pos.y == tree.pos.y && animal.pos.x - 50 == tree.pos.x)
				lefttree = true;

			if (animal.pos.y - 50 == tree.pos.y && animal.pos.x == tree.pos.x)
				uptree = true;

			if (animal.pos.y + 50 == tree.pos.y && animal.pos.x == tree.pos.x)
				downtree = true;

			tree.pos = { 0,j + speed,50,50 };
			G_Draw(T_tree, &tree.pos, false);
			if (animal.pos.y == tree.pos.y && animal.pos.x + 50 == tree.pos.x)
				righttree = true;

			if (animal.pos.y == tree.pos.y && animal.pos.x - 50 == tree.pos.x)
				lefttree = true;

			if (animal.pos.y - 50 == tree.pos.y && animal.pos.x == tree.pos.x)
				uptree = true;

			if (animal.pos.y + 50 == tree.pos.y && animal.pos.x == tree.pos.x)
				downtree = true;
			switch (a[i - 2] % 5) {
			case 0:
				tree.texture = T_tree;
				tree.pos = { 100,j + speed,50,50 };
				G_Draw(T_tree, &tree.pos, false);
				if (animal.pos.y == tree.pos.y && animal.pos.x + 50 == tree.pos.x)
					righttree = true;

				if (animal.pos.y == tree.pos.y && animal.pos.x - 50 == tree.pos.x)
					lefttree = true;

				if (animal.pos.y - 50 == tree.pos.y && animal.pos.x == tree.pos.x)
					uptree = true;

				if (animal.pos.y + 50 == tree.pos.y && animal.pos.x == tree.pos.x)
					downtree = true;
				tree.texture = T_tree;
				tree.pos = { 250,j + speed,50,50 };
				G_Draw(T_tree, &tree.pos, false);
				if (animal.pos.y == tree.pos.y && animal.pos.x + 50 == tree.pos.x)
					righttree = true;

				if (animal.pos.y == tree.pos.y && animal.pos.x - 50 == tree.pos.x)
					lefttree = true;

				if (animal.pos.y - 50 == tree.pos.y && animal.pos.x == tree.pos.x)
					uptree = true;

				if (animal.pos.y + 50 == tree.pos.y && animal.pos.x == tree.pos.x)
					downtree = true;
				tree.texture = T_tree;
				tree.pos = { 450,j + speed,50,50 };
				G_Draw(T_tree, &tree.pos, false);
				if (animal.pos.y == tree.pos.y && animal.pos.x + 50 == tree.pos.x)
					righttree = true;
				if (animal.pos.y == tree.pos.y && animal.pos.x - 50 == tree.pos.x)
					lefttree = true;

				if (animal.pos.y - 50 == tree.pos.y && animal.pos.x == tree.pos.x)
					uptree = true;

				if (animal.pos.y + 50 == tree.pos.y && animal.pos.x == tree.pos.x)
					downtree = true;
			case 1:
				tree.texture = T_tree;
				tree.pos = { 500,j + speed,50,50 };
				G_Draw(T_tree, &tree.pos, false);
				if (animal.pos.y == tree.pos.y && animal.pos.x + 50 == tree.pos.x)
					righttree = true;

				if (animal.pos.y == tree.pos.y && animal.pos.x - 50 == tree.pos.x)
					lefttree = true;

				if (animal.pos.y - 50 == tree.pos.y && animal.pos.x == tree.pos.x)
					uptree = true;

				if (animal.pos.y + 50 == tree.pos.y && animal.pos.x == tree.pos.x)
					downtree = true;

				tree.texture = T_tree;
				tree.pos = { 600,j + speed,50,50 };
				G_Draw(T_tree, &tree.pos, false);
				if (animal.pos.y == tree.pos.y && animal.pos.x + 50 == tree.pos.x)
					righttree = true;

				if (animal.pos.y == tree.pos.y && animal.pos.x - 50 == tree.pos.x)
					lefttree = true;

				if (animal.pos.y - 50 == tree.pos.y && animal.pos.x == tree.pos.x)
					uptree = true;

				if (animal.pos.y + 50 == tree.pos.y && animal.pos.x == tree.pos.x)
					downtree = true;
				;break;
			case 2:
				tree.texture = T_tree;
				tree.pos = { 50,j + speed,50,50 };
				G_Draw(T_tree, &tree.pos, false);
				if (animal.pos.y == tree.pos.y && animal.pos.x + 50 == tree.pos.x)
					righttree = true;

				if (animal.pos.y == tree.pos.y && animal.pos.x - 50 == tree.pos.x)
					lefttree = true;

				if (animal.pos.y - 50 == tree.pos.y && animal.pos.x == tree.pos.x)
					uptree = true;

				if (animal.pos.y + 50 == tree.pos.y && animal.pos.x == tree.pos.x)
					downtree = true;

				tree.texture = T_tree;
				tree.pos = { 200,j + speed,50,50 };
				G_Draw(T_tree, &tree.pos, false);
				if (animal.pos.y == tree.pos.y && animal.pos.x + 50 == tree.pos.x)
					righttree = true;

				if (animal.pos.y == tree.pos.y && animal.pos.x - 50 == tree.pos.x)
					lefttree = true;

				if (animal.pos.y - 50 == tree.pos.y && animal.pos.x == tree.pos.x)
					uptree = true;

				if (animal.pos.y + 50 == tree.pos.y && animal.pos.x == tree.pos.x)
					downtree = true;
				tree.texture = T_tree;
				tree.pos = { 400,j + speed,50,50 };
				G_Draw(T_tree, &tree.pos, false);
				if (animal.pos.y == tree.pos.y && animal.pos.x + 50 == tree.pos.x)
					righttree = true;

				if (animal.pos.y == tree.pos.y && animal.pos.x - 50 == tree.pos.x)
					lefttree = true;

				if (animal.pos.y - 50 == tree.pos.y && animal.pos.x == tree.pos.x)
					uptree = true;

				if (animal.pos.y + 50 == tree.pos.y && animal.pos.x == tree.pos.x)
					downtree = true;
				tree.texture = T_tree;
				tree.pos = { 500,j + speed,50,50 };
				G_Draw(T_tree, &tree.pos, false);
				if (animal.pos.y == tree.pos.y && animal.pos.x + 50 == tree.pos.x)
					righttree = true;

				if (animal.pos.y == tree.pos.y && animal.pos.x - 50 == tree.pos.x)
					lefttree = true;

				if (animal.pos.y - 50 == tree.pos.y && animal.pos.x == tree.pos.x)
					uptree = true;

				if (animal.pos.y + 50 == tree.pos.y && animal.pos.x == tree.pos.x)
					downtree = true;
				;break;
			case 3:
				tree.texture = T_tree;
				tree.pos = { 200,j + speed,50,50 };
				G_Draw(T_tree, &tree.pos, false);
				if (animal.pos.y == tree.pos.y && animal.pos.x + 50 == tree.pos.x)
					righttree = true;

				if (animal.pos.y == tree.pos.y && animal.pos.x - 50 == tree.pos.x)
					lefttree = true;

				if (animal.pos.y - 50 == tree.pos.y && animal.pos.x == tree.pos.x)
					uptree = true;

				if (animal.pos.y + 50 == tree.pos.y && animal.pos.x == tree.pos.x)
					downtree = true;
				;break;
			case 4:
				tree.texture = T_tree;
				tree.pos = { 350,j + speed,50,50 };
				G_Draw(T_tree, &tree.pos, false);
				if (animal.pos.y == tree.pos.y && animal.pos.x + 50 == tree.pos.x)
					righttree = true;

				if (animal.pos.y == tree.pos.y && animal.pos.x - 50 == tree.pos.x)
					lefttree = true;
				if (animal.pos.y - 50 == tree.pos.y && animal.pos.x == tree.pos.x)
					uptree = true;

				if (animal.pos.y + 50 == tree.pos.y && animal.pos.x == tree.pos.x)
					downtree = true;
				tree.texture = T_tree;
				tree.pos = { 650,j + speed,50,50 };
				G_Draw(T_tree, &tree.pos, false);
				if (animal.pos.y == tree.pos.y && animal.pos.x + 50 == tree.pos.x)
					righttree = true;

				if (animal.pos.y == tree.pos.y && animal.pos.x - 50 == tree.pos.x)
					lefttree = true;

				if (animal.pos.y - 50 == tree.pos.y && animal.pos.x == tree.pos.x)
					uptree = true;

				if (animal.pos.y + 50 == tree.pos.y && animal.pos.x == tree.pos.x)
					downtree = true;
				;break;
			}

		}
		j += 50;
		animal.texture = T_animal;
		if (car1.pos.x - animal.pos.x < 50 && car1.pos.x - animal.pos.x > -100 && animal.pos.y <= car1.pos.y + 5 && animal.pos.y >= car1.pos.y - 5) {
			if (!lose)
				G_PlaySound(carsquish, 0);
			lose = true;
		}

		if (car2.pos.x - animal.pos.x < 50 && car2.pos.x - animal.pos.x > -100 && animal.pos.y <= car2.pos.y + 5 && animal.pos.y >= car2.pos.y - 5) {
			if (!lose)
				G_PlaySound(carsquish, 0);
			lose = true;
		}

		if (car3.pos.x - animal.pos.x < 50 && car3.pos.x - animal.pos.x > -100 && animal.pos.y <= car3.pos.y + 5 && animal.pos.y >= car3.pos.y - 5) {
			if (!lose)
				G_PlaySound(carsquish, 0);
			lose = true;
		}

		if (car4.pos.x - animal.pos.x < 50 && car4.pos.x - animal.pos.x > -100 && animal.pos.y <= car4.pos.y + 5 && animal.pos.y >= car4.pos.y - 5) {
			if (!lose)
				G_PlaySound(carsquish, 0);
			lose = true;
		}

		if (train.pos.x - animal.pos.x < 50 && train.pos.x - animal.pos.x > -500 && animal.pos.y <= train.pos.y + 5 && animal.pos.y >= train.pos.y - 5) {
			if (!lose)
				G_PlaySound(carsquish, 0);
			lose = true;
		}
		if (animal.pos.y > 500 && !lose) {
			if (!eagles) {
				eagl = G_GetTicks();
				eagles = true;
			}
			eagle.texture = T_eagle;
			eagle.pos = { 350,(sp * 2) % 600 - 50,100,50 };
			G_Draw(T_eagle, &eagle.pos, false);
			if(!lose)
			G_PlaySound(eagle1, 0);

			if (G_GetTicks() - eagl > 1500)
				lose = true;
		}

		animal.pos = { 350 + lef ,speed + 200 + up,50,50 };
		G_Draw(T_animal, &animal.pos, false);

	}
	if (sp % 4 == 0) {
		speed += camera;
	}
	sp++;



}
void play()
{
	G_Font* font = G_OpenFont("crossyroad/arial.ttf", 50);
	draw();

	//showing score
	/*sprintf(b, "score : %d", score);
	G_Texture* font_texture = G_LoadFont(font, b, 0, 0, 0);
	G_Rect font_pos = { 0,0,90,50 };
	G_Draw(font_texture, &font_pos, false);*/

	if (lose) {
		camera = 0;
		over.texture = T_over;
		over.pos = { 150,50,500,400 };
		G_Draw(T_over, &over.pos, false);
		
		//showing score
		/*sprintf(b, "score : %d", score);
		G_Texture* font_texture = G_LoadFont(font, b, 0, 0, 0);
		G_Rect font_pos = { 355,75,90,50 };
		G_Draw(font_texture, &font_pos, false);*/

		switch (G_Event())
		{
		case G_KEYDOWN:
			switch (G_Keyboard)
			{
			case GK_SPACE:
				gameState = START;
				lose = false;
				cout << "Your Score: " << score;
				break;
			}
		}
	}
	if (animal.pos.y < 200 && !lose)
		camera = 5;
	if (animal.pos.y > 300 && !lose)
		camera = cameraspeed;
	if (animal.pos.x <= car1.pos.x + 100 && animal.pos.x >= car1.pos.x && animal.pos.y <= car1.pos.y + 25 && animal.pos.y >= car1.pos.y - 25)
		lose = true;
	int los = 0;

	switch (G_Event())
	{
	case G_KEYDOWN:
		switch (G_Keyboard)
		{
		case GK_UP:
			if (!uptree) {
				up -= 50;score++;righttree = false;lefttree = false;downtree = false;woods = false;
			}
			break;
		case GK_RIGHT:
			if (!righttree) {
				lef += 50;lefttree = false;uptree = false;downtree = false;woods = false;
			}
			break;
		case GK_LEFT:
			if (!lefttree) {
				lef -= 50;righttree = false;uptree = false;downtree = false;woods = false;
			}
			break;
		case GK_DOWN:
			if (!downtree) {
				up += 50;score--;righttree = false;uptree = false;downtree = false;woods = false;
			}
			break;
		}

	}
	if (animal.pos.x < 0 || animal.pos.x > 750)
		lose = true;
	endLoop = G_GetTicks() - startLoop;
	if (endLoop < delay)
	{
		G_Delay(delay - endLoop);
	}


}

void destroy()
{
	//G_DestroyTexture(box);
	G_QuitSDL();

}