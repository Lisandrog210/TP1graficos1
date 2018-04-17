#include <SDL.h> 

int main(int argc, char ** argv){

	bool quit = false;
	SDL_Event event;

	int x=5;
	int y=5;

	SDL_Init(SDL_INIT_VIDEO);

	SDL_Window * window = SDL_CreateWindow("SDL2 Displaying Image", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480, 0);

	SDL_Renderer * renderer = SDL_CreateRenderer(window, -1, 0);
	SDL_Surface * image = SDL_LoadBMP("imagen.bmp");
	SDL_Texture * texture = SDL_CreateTextureFromSurface(renderer, image);

	while (!quit)
	{
		SDL_WaitEvent(&event);

		/*switch (event.type)
		{			
		case SDL_QUIT:
			quit = true;
			break;
		}*/
		
		switch (event.type)
		{
		case SDL_QUIT:
			quit = true;
			break;

		case SDL_KEYDOWN:
			switch (event.key.keysym.sym)
			{

			case SDLK_LEFT:

				x -= 4;

				break;

			case SDLK_RIGHT:

				x += 4;

				break;

			case SDLK_UP:

				y -= 4;

				break;

			case SDLK_DOWN:

				y += 4;

				break;

			}
			break;		
			
		}
		SDL_Rect dstrect = { x, y, 320, 240 };
		SDL_RenderClear(renderer);
		SDL_RenderCopy(renderer, texture, NULL, &dstrect);
		SDL_RenderPresent(renderer);
		
	}
	SDL_DestroyTexture(texture);
	SDL_FreeSurface(image);
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();

	return 0;

	
}

	


