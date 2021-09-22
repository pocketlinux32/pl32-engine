#include <pl32e-system.h>
#include <SDL.h>

bool plSystemInitialized = false;
unsigned int plFrameMs = 0;
unsigned int plMaxFrameMs = 16;

struct plwindow {
	SDL_Window* window;
	SDL_Renderer* renderer;
}

int plInit(){
	SDL_Log("pl32-engine-sdl2, v0.01");
	if(SDL_Init(SDL_INIT_VIDEO|SDL_INIT_EVENTS) != 0){
		SDL_LogError(SDL_LOG_CATEGORY_SYSTEM, "SDL_Init() failed to initialize: %s", SDL_GetError());
		return -1;
	}
	plSystemInitialized = true;
}



void plExit(){
	if(!plSystemInitialized){
		SDL_Log("pl32-engine-sdl2 hasn't been initialized yet!");
		return;
	}
	SDL_QuitSubSystem(SDL_INIT_VIDEO|SDL_INIT_EVENTS);
	SDL_Quit();
}
