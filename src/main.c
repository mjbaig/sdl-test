#include <SDL2/SDL.h>
#include <stdbool.h>

SDL_Window *sdlWindow = NULL;

SDL_Surface *graphicsScreenSurface = NULL;

SDL_Surface *helloWorldSurface = NULL;

int SCREEN_WIDTH = 800;

int SCREEN_HEIGHT = 600;

int main(void) {
  SDL_Window *window = NULL;

  SDL_Surface *screenSurface = NULL;

  if (SDL_Init(SDL_INIT_VIDEO) < 0) {
    fprintf(stderr, "Error initializaing video %s\n", SDL_GetError());
    return 1;
  }

  window = SDL_CreateWindow("sdl-test", SDL_WINDOWPOS_UNDEFINED,
                            SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH,
                            SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

  if (window == NULL) {
    fprintf(stderr, "count not create window: %s\n", SDL_GetError());
    return 1;
  }

  screenSurface = SDL_GetWindowSurface(window);
  SDL_FillRect(screenSurface, NULL,
               SDL_MapRGB(screenSurface->format, 0xFF, 0xFF, 0xFF));
  SDL_UpdateWindowSurface(window);
  SDL_Delay(2000);
  SDL_DestroyWindow(window);
  SDL_Quit();
  return 0;
}
