#include <pl32e-system.h>
#include <SDL.h>

struct plwindow {
	SDL_Window* window;
	SDL_Renderer* renderer;
}

plwindow_t* plInit(){
	plwindow_t* returnWindow = safe_malloc(sizeof(plwindow_t))

	if(SDL_Init(SDL_INIT_VIDEO|SDL_INIT_EVENTS) != 0){
		SDL_Log("SDL_Init() failed to initialize: %s", SDL_GetError());
		SDL_Log("Shutting down pl32-engine...\n");
		safe_free(returnWindow);
		return -1;
	}else if(SDL_CreateWindowAndRenderer(640, 480, SDL_WINDOW_RESIZABLE, &returnWindow->window, &returnWindow->renderer) != 0){
		SDL_Log("SDL_CreateWindowAndRenderer() failed to create a window and a renderer: %s", SDL_GetError());
		SDL_Log("Shutting down pl32-engine...\n");
		safe_free(returnWindow);
		return -2;
	}

	return returnWindow;
}

int main(int argc, const char* argv[]){
	printf("Starting pl32-engine...");

}
