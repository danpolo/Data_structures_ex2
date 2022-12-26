#include "Team.h"

Team::Team(int teamID) : teamID(teamID), m_points(0), m_strength(0),
                                m_games_played(0), m_number_of_players(0), m_goalKeeper_exist(0),
                                first_player(nullptr), last_player(nullptr){}


Team::~Team() {
    m_dict_of_players_in_team_by_key.destroyNodes();
    m_dict_of_players_in_team.destroyNodes();
}

int Team::valueOfTeam() const {
    return m_strength + m_points;
}

int Team::getGamesPlayed() const {
    return m_games_played;
}

bool Team::isValidTeam() const {
    return ((numberOfPlayers() >= 11) && (isGoalKeeperExists()));
}

void Team::addGamesPlayed(int added) {
    m_games_played += added;
}

int Team::getPoints() const {
    return m_points;
}

int Team::getStrength() const {
    return m_strength;
}

void Team::addPoints(int points) {
    m_points += points;
}

void Team::move_all_players(Team *team2) {
    Player** moving_players_begin = team2->m_dict_of_players_in_team.inorderNodesByValue();
    Player** moving_players = moving_players_begin;
    int number_of_players_to_move = team2->numberOfPlayers();
    int i = 0;
    while (i < number_of_players_to_move){
        (*moving_players)->addGamesPlayed(team2->m_games_played);
        add_player_in_team((*moving_players)->getPlayerId(), *moving_players);
        (*moving_players)->setTeamID(getID());
        team2->remove_player_in_team((*moving_players)->getPlayerId(), *moving_players);
        i++;
        moving_players++;
    }
    delete[] moving_players_begin;
}

bool Team::operator>(const Team &other) const {
    return (valueOfTeam()) > (other.valueOfTeam());
}

bool Team::operator==(const Team &other) const {
    return (valueOfTeam()) == (other.valueOfTeam());
}

int Team::numberOfPlayers() const {
    return m_number_of_players;
}

void Team::addStrength(int strength) {
    m_strength += strength;
}

int Team::getID() const {
    return teamID;
}

bool Team::isGoalKeeperExists() const {
    if (m_goalKeeper_exist > 0){
        return true;
    }
    return false;
}
bool operator!=(const Team& v1, const Team& v2){
    return !(v1 == v2);
}
bool operator<(const Team& v1, const Team& v2){
    return v2 > v1;
}

Team operator-(const Team& v1, const Team& v2){
    return Team(v1) -= v2;
}
Team &Team::operator-=(const Team &other) {
    return *this;
}

bool  Team::operator/(const Team &other) const {
    return true;
}

