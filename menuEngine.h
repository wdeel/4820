#include <vector>
#include <SDL.h>
#include "buyMenuEngine.h"
#include "player.h"

class MenuEngine
{
  private:
    Clock& clock;
    SDL_Renderer * const renderer;
    Menu menu;
    BuyMenuEngine buyMenuEngine;
    int optionChoice;
    int result;

    void draw(int) const;
    void update(Uint32);

  public:
    MenuEngine();
    ~MenuEngine();
    MenuEngine(const MenuEngine&) = delete;
    MenuEngine& operator=(const MenuEngine&) = delete;
    int play(int, Player*);
    int getOptionChoice() const { return optionChoice; }
    bool starsOptionChosen();
    void resetResult() { result = 0; }
};
