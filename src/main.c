#include <stdbool.h>
#include <stdint.h>

#include <SDL2/SDL.h>

#include "common.h"

int main(int argc, char **argv) {
  UNUSED(argc);
  UNUSED(argv);

  uint16_t opcode;

  uint8_t memory[4096];
  uint8_t V[16];

  uint16_t I;
  uint16_t PC;

  uint8_t gfx[64 * 32];

  uint8_t delay_timer;
  uint8_t sound_timer;

  uint8_t stack[48];
  uint16_t SP;

  uint8_t keyboard[16];

  int sdl_status = SDL_Init(SDL_INIT_VIDEO);
  if (sdl_status != 0) {
    printf("Unable to init SDL: %s\n", SDL_GetError());
    return 1;
  }

  SDL_Window *window = SDL_CreateWindow("CHIP-8", SDL_WINDOWPOS_CENTERED,
      SDL_WINDOWPOS_CENTERED, 640, 320, 0);
  if (window == NULL) {
    printf("Unable to create a window: %s\n", SDL_GetError());
    return 1;
  }

  SDL_Renderer *renderer = SDL_CreateRenderer(window, -1,
      SDL_RENDERER_ACCELERATED);
  if (renderer == NULL) {
    printf("Unable to create a renderer: %s\n", SDL_GetError());
    return 1;
  }

  int pending_event = 0;
  SDL_Event event;

  bool running = true;
  while (running) {
    do {
      pending_event = SDL_PollEvent(&event);
      switch (event.type) {
        case SDL_QUIT:
          running = false;
          break;

        default:
          break;
      }
    } while(pending_event);

    // TODO: emulation cycle

    SDL_RenderClear(renderer);

    SDL_RenderPresent(renderer);
  }

  SDL_Quit();

  return 0;
}
