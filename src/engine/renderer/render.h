// Where the render functions in other parts of the code will be used.
#ifndef RENDER_H
#define RENDER_H

#include <SDL2/SDL.h>
#include <linmath.h>

#include "../types.h"

typedef struct render_state {
  SDL_Window *window;
  f32 width;
  f32 height;
} Render_State;

void render_init(void);
void render_begin(void);
void render_end(void);
void render_quad(vec2 position, vec2 size, vec4 color);

#endif
