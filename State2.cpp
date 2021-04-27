#include <iostream>
#include <SDL2/SDL.h>
#include "State2.h"
#include "sprite.h"


void youWin (SDL_Renderer* renderer, SDL_Event event, int scale, int wscale, int slength) {

    //
	renderLetter("Game Over", 20, 100, renderer);
	renderLetter("Press Enter to retry", 20, 200, renderer);
	renderLetter((string("Score: ") + to_string(slength * 10)).c_str(), 20, 300, renderer);

	// Show game over screen while space has not been pressed
	while (true) {
		SDL_RenderPresent(renderer);

		if (SDL_PollEvent(&event)) {

			if (event.type == SDL_QUIT) {
				exit(0);
			}

			if (event.key.keysym.scancode == SDL_SCANCODE_RETURN) {
				return;
			}
		}
	}
}
