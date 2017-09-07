#include "../includes/Game.hpp"

Game::Game(std::string name)
{
    this->_scene = initscr();
    noecho();
    curs_set(FALSE);
    cbreak();
    getmaxyx(_scene, _winH, _winW);
    keypad(this->_scene, true);
    nodelay(_scene, true);
    this->_playing = true;
    this->_playerName = name;
    this->_score = 0;
    this->_ticks = 0;
    time(&this->_startTime);
    this->_elapsedTime = 0.0;
    this->_activeEnemies = 0;
    this->_maxEnemies = 100;
    this->_maxMissles = 100;
    this->_activePMissles = 0;
    this->_activeEMissles = 0;
    this->_life = 4;
    this->_playerMissles = new Missle[this->_maxMissles];
    this->_enemyMissles = new Missle[this->_maxMissles];
    this->_player = PlayerShip(_winH - 10, _winW / 2);
    this->_enemies = new EnemyShip[this->_maxEnemies];
}

Game::~Game(void)
{
    return ;
}

Game::Game(const Game& toCopy)
{
    *this = toCopy;
}

Game Game::operator=(const Game& rhs)
{
    this->_playerMissles = rhs._playerMissles;
    this->_enemyMissles = rhs._enemyMissles;
    this->_activePMissles = rhs._activePMissles;
    this->_enemies = rhs._enemies;
    this->_player = rhs._player;
    this->_playerName = rhs._playerName;
    return *this;
}

std::string Game::getName()
{
    return this->_playerName;
}

int Game::getScore()
{
    return _score + _elapsedTime / 2;
}
void    Game::takeUserInput()
{
    int key = wgetch(this->_scene);
    if (key == KEY_UP && _player.getY() > 0)
        _player.setY(_player.getY() - 1);
    else if (key == KEY_DOWN && _player.getY() < _winH)
        _player.setY(_player.getY() + 1);
    else if (key == KEY_LEFT && _player.getX() > 0)
        _player.setX(_player.getX() - 1);
    else if (key == KEY_RIGHT && _player.getX() < _winW)
        _player.setX(_player.getX() + 1);
    else if (key == ' ')
        playerFire();
}

int     Game::getTicks()
{
    return this->_ticks;
}

int     Game::getTime()
{
    return (int)this->_elapsedTime;
}

bool    Game::beingPlayed()
{
    return this->_playing;
}

void    Game::setPlayerName(std::string name)
{
    this->_playerName = name;
}

void    Game::enemyFire()
{
    int enemy = rand() % _activeEnemies;
    if (_activeEMissles < _maxMissles - 1)
    {
        _enemyMissles[_activeEMissles].setX(_enemies[enemy].getX() + 1);
        _enemyMissles[_activeEMissles].setY(_enemies[enemy].getY());
        _enemyMissles[_activeEMissles].setStatus(true);
        _enemyMissles[_activeEMissles].setSpeed(1);
        _enemyMissles[_activeEMissles].setDirection(0);
        _enemyMissles[_activeEMissles].setDesign(".");
        _activeEMissles += 1;
    }
    else
        resetAmmo();
}

void    Game::playerFire()
{
    if (_activePMissles < _maxMissles - 2)
    {
        _playerMissles[_activePMissles + 1].setX(_player.getX() + 6);
        _playerMissles[_activePMissles + 1].setY(_player.getY() - 1);
        _playerMissles[_activePMissles + 1].setStatus(true);
        _playerMissles[_activePMissles + 1].setDirection(1);

        _playerMissles[_activePMissles].setX(_player.getX());
        _playerMissles[_activePMissles].setY(_player.getY() - 1);
        _playerMissles[_activePMissles].setStatus(true);
        _playerMissles[_activePMissles].setDirection(1);
        _activePMissles += 2;
    }
    else
        resetAmmo();
}

void    Game::spawnEnemies()
{
    if (_activeEnemies < _maxEnemies - 1)
    {
        _enemies[_activeEnemies].setX(rand() % (_winW - 5));
        _enemies[_activeEnemies].setY(0);
        _enemies[_activeEnemies].setStatus(true);
        _enemies[_activeEnemies].setDirection(0);
        _activeEnemies += 1;
    }
    else
        resetEnemies();
}

void    Game::resetAmmo()
{
    for (int i = 0; i < _maxMissles; i++)
    {
        _playerMissles[i].setX(0);
        _playerMissles[i].setY(0);
        _playerMissles[i].setStatus(false);
    }
    _activePMissles = 0;
}

void    Game::resetEnemies()
{
    for (int i = 0; i < _maxEnemies; i++)
    {
        _enemies[i].setX(0);
        _enemies[i].setY(0);
        _enemies[i].setStatus(false);
    }
    _activeEnemies = 0;
}

void    Game::updateWorld()
{
    time_t temp;

    time(&temp);
    for (int i = 0; i < this->_maxEnemies; i++)
    {
        if (_enemies[i].getStatus())
        {
            if(_enemies[i].collide(_player.getX(), _player.getY(), (int)_player.getDesign().length())) {
                    _enemies[i].setStatus(false);
                    _life -= 1;
                    if (_life == 0)
                        _playing = false;
            }
            if (_ticks % 300 == 0)
                _enemies[i].update();
        }
    }
    for (int i = 0; i < this->_maxMissles; i++)
    {
        if (_playerMissles[i].getStatus())
        {
            for (int j = 0; j < this->_maxEnemies; j++)
                if(_enemies[j].collide(_playerMissles[i].getX(), _playerMissles[i].getY(), 1)) {
                    _enemies[j].setStatus(false);
                    _playerMissles[i].setStatus(false);
                    this->_score += 10;
                }
            if (_ticks % 50 == 0)
                _playerMissles[i].update();
        }
    }
    for (int i = 0; i < this->_maxMissles; i++)
    {
        if (_enemyMissles[i].getStatus())
        {
            if(_player.collide(_enemyMissles[i].getX(), _enemyMissles[i].getY(), 6)) {
                    _enemies[i].setStatus(false);
                    _life -= 1;
                    if (_life == 0)
                        _playing = false;
            }
            if (_ticks % 100 == 0)
                _enemyMissles[i].update();
        }
    }
    _ticks += 1;
    _elapsedTime = difftime(temp, _startTime);
}

void    Game::renderChanges()
{
    for (int i = 0; i < _winH; i++)
    {
        for (int j = 0; j < _winW; j++)
            mvprintw(i, j, " ");
    }
    this->_player.draw();
    for (int i = 0; i < this->_maxEnemies; i++)
    {
        if (_enemies[i].getStatus())
            _enemies[i].draw();
    }
    for (int i = 0; i < this->_maxMissles; i++)
    {
        if (_playerMissles[i].getStatus())
            _playerMissles[i].draw();
        if (_enemyMissles[i].getStatus())
            _enemyMissles[i].draw();
    }
}

void    Game::showHUD() {

    mvprintw(0, 0, "SCORE %.0f\nTIME %.0f\nLives: %i", (_elapsedTime / 2) + _score, _elapsedTime, this->_life);
}
