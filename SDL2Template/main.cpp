#include <SDL.h>

int main(int argc, char* argv[]) {
	// SDLの初期化
	int sdl_result = SDL_Init(SDL_INIT_EVERYTHING);
	if (sdl_result != 0) {
		SDL_Log("SDLの初期化に失敗: %s", SDL_GetError());
		return -1;
	}
	// ウインドウの作成
	SDL_Window* window = SDL_CreateWindow(
		"SDL2 Template Window", // 名前
		SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
		1024, 768,
		0
	);
	if (!window) {
		SDL_Log("ウインドウの作成に失敗: %s", SDL_GetError());
		return -1;
	}

	SDL_Delay(3000);

	SDL_DestroyWindow(window);

	SDL_Quit();

	return 0;
}
