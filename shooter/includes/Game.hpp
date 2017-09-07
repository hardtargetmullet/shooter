#ifndef GAME_H
# define GAME_H

#include <string>
#include <ncurses.h>
#include <sys/time.h>
#include "AGameEntity.hpp"
#include "Missle.hpp"
#include "PlayerShip.hpp"
#include "EnemyShip.hpp"

class Game {
    public:
        Game(std::string playerName="Player1");
        ~Game();
        Game(const Game& toCopy);
        Game operator=(const Game& rhs);

        void        takeUserInput();
        void        updateWorld();
        void        renderChanges();
        bool        beingPlayed();

        void        resetAmmo();
        void        resetEnemies();
        void        spawnEnemies();
        void        playerFire();
        void        enemyFire();
        int         getTicks();
        int         getTime();
        int         getScore();
        std::string getName();
        void        setPlayerName(std::string name);
        void        showHUD();

    private:
        bool        _playing;
        int         _ticks;
        time_t      _startTime;
        double      _elapsedTime;
        Missle*     _playerMissles;
        Missle*     _enemyMissles;
        EnemyShip*  _enemies;
        PlayerShip  _player;
        std::string _playerName;
        int         _life;
        int         _score;
        int         _activeEnemies;
        int         _maxEnemies;
        int         _activeEMissles;
        int         _activePMissles;
        int         _maxMissles;

        int         _winH;
        int         _winW;
        WINDOW*     _scene;
};
#endif
