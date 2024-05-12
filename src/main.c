#include <SDL2/SDL.h>
#include <stdbool.h>

SDL_Window *sdlWindow = NULL;

SDL_Surface *graphicsScreenSurface = NULL;

SDL_Surface *helloWorldSurface = NULL;

int SCREEN_WIDTH = 800;

int SCREEN_HEIGHT = 600;

bool init(void) {
  bool isSuccess = true;

  if (SDL_Init(SDL_INIT_VIDEO) < 0) {
    printf("SDL could not initialize: %s\n", SDL_GetError());
    isSuccess = false;
  } else {
    sdlWindow = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED,
                                 SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH,
                                 SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
  }

  if (sdlWindow == NULL) {
    printf("SDL Window Could Not Be Created: %s\n", SDL_GetError());
    isSuccess = false;
  } else {
    graphicsScreenSurface = SDL_GetWindowSurface(sdlWindow);
  }

  return isSuccess;
}

bool localMedia(void) {
  bool isSuccess = true;

  helloWorldSurface = SDL_LoadBMP("");

  if (helloWorldSurface == NULL) {
    printf("Error making hello world surface: %s\n", SDL_GetError());
  }

  return isSuccess;
}

void close(void) {
  SDL_FreeSurface(helloWorldSurface);
  helloWorldSurface = NULL;

  SDL_FreeSurface(graphicsScreenSurface);
  graphicsScreenSurface = NULL;

  SDL_DestroyWindow(sdlWindow);
  sdlWindow = NULL;

  SDL_Quit();
}

int main(void) {
  init();
  localMedia();
  close();

  if (init()) {
    if (localMedia()) {
      SDL_BlitSurface(helloWorldSurface, NULL, graphicsScreenSurface, NULL);
    }
  }

  return 0;
}
