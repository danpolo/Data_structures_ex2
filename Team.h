#ifndef EX1_TEAM_H
#define EX1_TEAM_H

#include "Player.h"

class Team
{
public:
    Team(int teamID);
    Team(const Team& other) = default;
    ~Team();

    int getPoints() const;
    int getTotalAbility() const;
    int getID() const;
    int getGamesPlayed() const;
    const permutation_t &getTeamSpirit() const;
    int getNumberOfPlayers() const;
    bool isValidTeam() const;
    Player* getFirstPlayer() const;
    Player* getLastPlayer() const;

    void addPoints(int points);
    void addTotalAbility(int ability);
    void addGamesPlayed(int games_played);
    void addGoalKeeper();
    void updateTeamSpirit(const permutation_t &new_spirit);
    void setFirstPlayer(Player* f_ply);
    void setLastPlayer(Player* l_ply);

    bool operator>(const Team& other) const;

    enum struct MatchResult {
        TIE                       = 0,
        FIRST_TEAM_WON_BY_VALUE   = 1,
        FIRST_TEAM_WON_BY_SPIRIT  = 2,
        SECOND_TEAM_WON_BY_VALUE  = 3,
        SECOND_TEAM_WON_BY_SPIRIT = 4,
    };

    friend MatchResult playMatchResult(Team* first_team, Team* second_team);

private:
    int teamID;
    int m_points;
    int m_total_ability;
    int m_games_played;
    int m_number_of_players;
    bool is_valid;
    permutation_t m_team_spirit;
    Player* first_player;
    Player* last_player;

    int getTeamValue() const;   //points + strength
    int getTeamSpiritStrength() const;
};

bool operator==(const Team& v1, const Team& v2);
bool operator!=(const Team& v1, const Team& v2);
bool operator<(const Team& v1, const Team& v2);

Team::MatchResult playMatchResult(Team* first_team, Team* second_team);

#endif //EX1_TEAM_H
