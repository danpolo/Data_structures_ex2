#ifndef EX1_TEAM_H
#define EX1_TEAM_H

#include "Player.h"

class Team
{
public:
    Team(int teamID);
    Team(const Team& other) = default;
    ~Team();

    void move_all_players(Team* team2);
    int valueOfTeam() const;   //points + strength
    int getPoints() const;
    int getStrength() const;
    int getID() const;
    int getGamesPlayed() const;
    int getTopScorerInTeam() const;
    void addPoints(int points);
    void addStrength(int strength);
    void addGamesPlayed(int added);
    int numberOfPlayers() const;
    bool isGoalKeeperExists() const;
    bool isValidTeam() const;
    bool operator>(const Team& other) const;
    bool operator==(const Team& other) const;
    Team& operator-=(const Team& other);
    bool operator/(const Team& other) const;
    Player* getFirstPlayer() const;
    Player* getLastPlayer() const;
    void setFirstPlayer(Player* f_ply){
        first_player = f_ply;
    }
    void setLastPlayer(Player* l_ply){
        last_player = l_ply;
    }

private:
    int teamID;
    int m_points;
    int m_strength;
    int m_games_played;
    int m_number_of_players;
    int m_goalKeeper_exist;
    Player* first_player;
    Player* last_player;
};
bool operator!=(const Team& v1, const Team& v2);
bool operator<(const Team& v1, const Team& v2);
Team operator-(const Team& v1, const Team& v2);

#endif //EX1_TEAM_H
