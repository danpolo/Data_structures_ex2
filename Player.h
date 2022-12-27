#ifndef EX1_PLAYER_H
#define EX1_PLAYER_H

#include <string>


#include "wet2util.h"

class Player {
public:
    Player(int player_id,int team_id, const permutation_t & spirit , int games_played, int
        ability, int cards, bool is_GK);
    ~Player() = default;
    Player(const Player& v1) = default;
    Player& operator=(const Player& other) = default;
    int getPlayerId() const;

    int getCards() const;
    void addCards(int addCards);

    int getGamesPlayed() const;
    void addGamesPlayed(int added);

    bool isGk() const;

    void setTeamID(int teamID);
    int getTeamID() const;

    bool operator>(const Player& other) const;
    bool operator<(const Player& other) const;
    bool operator/(const Player& other) const;   //left is smaller in all parameters than the right
    Player& operator-=(const Player& other);
    Player* getClosestLeft() const;
    Player* getClosestRight() const;
    void setClosestLeft(Player* other);
    void setClosestRight(Player* other);



private:
    int player_id;
    int team_id;
    const permutation_t & spirit;
    int games_played;
    int ability;
    int cards;
    bool is_GK;
    //int sub;
    //Player* closest_left;
    //Player* closest_right;

};
bool operator!=(const Player& v1, const Player& v2);
bool operator==(const Player& v1, const Player& v2);
Player operator-(const Player& v1, const Player& v2);


#endif //EX1_PLAYER_H
