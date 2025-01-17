#ifndef PLAYER_H
#define PLAYER_H

#include <list>
#include <cmath>
#include "drawable.h"
#include "projectile.h"
#include "sound.h"

class SmartSprite;
class DumbSprite;

class Player : public Drawable
{
  private:
    enum Face {LEFT, RIGHT, UP, DOWN};
    Face facing;
    std::list<SmartSprite*> observers;
    bool collision;
    bool collided;
    bool colliding;
    Vector2f velocity;
    float slowDownFactor;
    Sprite* explosion;
    float explosionStartTime;
    std::string projectileName;
    std::list<Projectile*> activeProjectiles;
    std::list<Projectile*> freeProjectiles;
    unsigned int numLives;
    unsigned int livesLeft;
    bool godMode;
    float minSpeed;
    float pistolInterval;
    float shotgunInterval;
    float assaultRifleInterval;
    float pistolReloadInterval;
    float shotgunReloadInterval;
    float assaultRifleReloadInterval;
    float timeSinceLastShot;
    float timeSinceLastPistolReload;
    float timeSinceLastShotgunReload;
    float timeSinceLastAssaultRifleReload;
    bool pistol;
    bool shotgun;
    bool assaultRifle;
    int pistolAmmoInClip;
    int pistolAmmoTotal;
    int pistolClip;
    int pistolAmmoCost;
    int pistolAmount;
    int shotgunAmmoInClip;
    int shotgunAmmoTotal;
    int shotgunClip;
    int shotgunCost;
    int shotgunAmmoCost;
    int shotgunAmount;
    int assaultRifleAmmoInClip;
    int assaultRifleAmmoTotal;
    int assaultRifleClip;
    int assaultRifleCost;
    int assaultRifleAmmoCost;
    int assaultRifleAmount;
    bool pistolIsReloading;
    bool shotgunIsReloading;
    bool assaultRifleIsReloading;
    bool shotgunPurchased;
    bool assaultRiflePurchased;
    int money;
    int points;
    Sound sound;

    void advanceFrame(Uint32 ticks);

  public:
    Player(const std::string&);
    Player(const Player&) = delete;
    Player& operator=(const Player&) = delete;
    virtual ~Player() { }

    virtual void draw() const;
    virtual void update (Uint32 ticks);

    void moveRight();
    void moveLeft();
    void moveUp();
    void moveDown();
    void stop();
    void attach(SmartSprite* o);
    void detach(SmartSprite* o);
    void collide();
    void shoot();

    std::list<Projectile*> getActiveProjectiles() const { return activeProjectiles; }
    std::list<Projectile*> getFreeProjectiles() const { return freeProjectiles; }
    unsigned int getLivesLeft() const { return livesLeft; }
    unsigned int getNumLives() const { return numLives; }
    bool hasCollided() const { return collided; }
    bool isColliding() const { return colliding; }
    void setCollided(bool b) { collided = b; }
    void loseLife() { --livesLeft; }
    bool isGodMode() const { return godMode; }
    void toggleGodMode() { godMode = !godMode; }
    void cycleLeft();
    void cycleRight();
    std::string getWeapon();
    void reload();
    void setReload();
    int getAmmoInClip();
    int getAmmoTotal();
    int getMoney() { return money; }
    int getPoints() { return points; }
    bool purchasePistolAmmo();
    int getPistolAmmoInClip() const { return pistolClip; }
    int getPistolAmmoTotal() const { return pistolAmmoTotal; }
    bool purchaseShotgun();
    bool isShotgunPurchased() const { return shotgunPurchased; }
    int getShotgunAmmoInClip() const { return shotgunClip; }
    int getShotgunAmmoTotal() const { return shotgunAmmoTotal; }
    bool purchaseShotgunAmmo();
    bool purchaseAssaultRifle();
    bool isAssaultRiflePurchased() const { return assaultRiflePurchased; }
    int getAssaultRifleAmmoInClip() const { return assaultRifleClip; }
    int getAssaultRifleAmmoTotal() const { return assaultRifleAmmoTotal; }
    bool purchaseAssaultRifleAmmo();
};

#endif
