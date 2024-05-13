// Global state for the game
#ifndef GLOBAL_H
#define GLOBAL_H

#include "renderer/render.h"

// Extern struct means its defined here but no memory assigned with it yet
typedef struct global {
  Render_State render;
} Global;

extern Global global;

#endif
