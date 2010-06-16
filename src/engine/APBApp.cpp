#include "APBApp.h"

const Uint32 FRAMELIMITER_DELAY_MINIMUM = 10;
const Uint32 UPDATE_RATE = 1000 / 30;

APBApp::APBApp() {
    display = NULL;
    running = true;
    paused = false;
    scr_w = 800;
    scr_h = 600;
    scr_bpp = 16;
    title = "APB2D Application";
}

int APBApp::setDisplayProperties(int w, int h, int bpp) {
    if (w > 0 && h > 0 && (bpp == 8 || bpp == 16 || bpp == 24 || bpp == 32)) {
        scr_w = w;
        scr_h = h;
        scr_bpp = bpp;
        return 0;
    }
    fprintf(stderr, "Requested display properties are illegal! Reverting to default settings.");
    return 1;
}

int APBApp::execute() {
    if (init() == false) {
        fprintf(stderr,"Failed to initialize application");
        return -1;
    }

    SDL_Event Event;

    Uint32 lastUpdateTime = SDL_GetTicks();
    Uint32 previousFrameTime = SDL_GetTicks();

    while (running) {
        while (SDL_PollEvent(&Event)) {
            APBApp::event(&Event);
        }

        Uint32 currentTime = SDL_GetTicks();
        Uint32 difference = currentTime  - lastUpdateTime;

        if (!paused) {
            while(difference >= UPDATE_RATE) {
                difference -= UPDATE_RATE;
                loop();
                lastUpdateTime = currentTime;
            }

            render();

            Uint32 currentFrameTime = SDL_GetTicks();
            Uint32 ticks = currentFrameTime - previousFrameTime;
            if(ticks  > FRAMELIMITER_DELAY_MINIMUM) {
                SDL_Delay(ticks - FRAMELIMITER_DELAY_MINIMUM);
            }
            previousFrameTime = currentFrameTime;
        }
    }

    cleanup();

    return 0;
}

void APBApp::cleanup() {
    SDL_FreeSurface(display);
    SDL_Quit();
}

bool APBApp::init() {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        fprintf(stderr,"Failed to initialize SDL");
        return false;
    }

    setTitle(title);

    if ((display = SDL_SetVideoMode(scr_w, scr_h, scr_bpp, SDL_HWSURFACE | SDL_DOUBLEBUF)) == NULL) {
        fprintf(stderr,"Failed to set video mode");
        return false;
    }

    loadData();


    return true;
}

void APBApp::event(SDL_Event* Event) {
    APBEvent::event(Event);
}

void APBApp::onExit() {
    running = false;
}

void APBApp::onKeyDown(SDLKey sym, SDLMod mod, Uint16 unicode) {
    if (paused) {
        if (sym == SDLK_p) {
            togglePause();
        }
        if (sym == SDLK_ESCAPE) {
            running = false;
        }
    } else {
        if (sym == SDLK_ESCAPE) {
            running = false;
        }
        if (sym == SDLK_p) {
            togglePause();
        }
    }
}

void APBApp::togglePause() {
    paused  = paused ? false : true;
}

bool APBApp::loadData() {
    // Pure virtual, do nothing
}

void APBApp::loop() {
    // Pure virtual, do nothing
}

void APBApp::render() {
    // Pure virtual, do nothing
}

void APBApp::setTitle(const char* title) {
    SDL_WM_SetCaption(title, title);
}
