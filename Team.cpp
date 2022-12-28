#include "Team.h"

Team::Team(int teamID) : teamID(teamID), m_points(0), m_total_ability(0),
                         m_games_played(0), m_number_of_players(0), is_valid(false),
                         m_team_spirit(), first_player(nullptr), last_player(nullptr) {}


Team::~Team() {

}

int Team::getTeamValue() const {
    return m_total_ability + m_points;
}

int Team::getGamesPlayed() const {
    return m_games_played;
}

bool Team::isValidTeam() const {
    return is_valid;
}

void Team::addGamesPlayed(int games_played) {
    m_games_played += games_played;
}

int Team::getPoints() const {
    return m_points;
}

int Team::getTotalAbility() const {
    return m_total_ability;
}

void Team::addPoints(int points) {
    m_points += points;
}

//void Team::move_all_players(Team *team2) {
//    Player** moving_players_begin = team2->m_dict_of_players_in_team.inorderNodesByValue();
//    Player** moving_players = moving_players_begin;
//    int number_of_players_to_move = team2->getNumberOfPlayers();
//    int i = 0;
//    while (i < number_of_players_to_move){
//        (*moving_players)->addGamesPlayed(team2->m_games_played);
//        add_player_in_team((*moving_players)->getPlayerId(), *moving_players);
//        (*moving_players)->setTeamID(getID());
//        team2->remove_player_in_team((*moving_players)->getPlayerId(), *moving_players);
//        i++;
//        moving_players++;
//    }
//    delete[] moving_players_begin;
//}

bool Team::operator>(const Team &other) const {
    if (getTeamValue() > other.getTeamValue()) {
        return true;
    }

    if (getTeamValue() == other.getTeamValue() and getTeamSpiritStrength() > other
            .getTeamSpiritStrength()) {
        return true;
    }

    return false;
}

bool operator==(const Team &v1, const Team &v2) {
    return !(v1 > v2) and !(v1 < v2);
}

int Team::getNumberOfPlayers() const {
    return m_number_of_players;
}

void Team::addTotalAbility(int ability) {
    m_total_ability += ability;
}

int Team::getID() const {
    return teamID;
}

bool operator!=(const Team &v1, const Team &v2) {
    return !(v1 == v2);
}

bool operator<(const Team &v1, const Team &v2) {
    return v2 > v1;
}


void Team::addGoalKeeper() {
    is_valid = true;
}

const permutation_t &Team::getTeamSpirit() const {
    return m_team_spirit;
}

void Team::updateTeamSpirit(const permutation_t &new_spirit) {
    m_team_spirit = m_team_spirit * new_spirit;
}

int Team::getTeamSpiritStrength() const {
    return m_team_spirit.strength();
}

Player *Team::getFirstPlayer() const {
    return first_player;
}

Player *Team::getLastPlayer() const {
    return last_player;
}

void Team::setFirstPlayer(Player *f_ply) {
    first_player = f_ply;
}

void Team::setLastPlayer(Player *l_ply) {
    last_player = l_ply;
}

Team::MatchResult playMatchResult(Team *first_team, Team *second_team) {
    if (first_team->getTeamValue() > second_team->getTeamValue()) {
        return Team::MatchResult::FIRST_TEAM_WON_BY_VALUE;
    }

    if (first_team->getTeamValue() < second_team->getTeamValue()) {
        return Team::MatchResult::SECOND_TEAM_WON_BY_VALUE;
    }

    if (first_team->getTeamSpiritStrength() > second_team->getTeamSpiritStrength()) {
        return Team::MatchResult::FIRST_TEAM_WON_BY_SPIRIT;
    }

    if (first_team->getTeamSpiritStrength() < second_team->getTeamSpiritStrength()) {
        return Team::MatchResult::SECOND_TEAM_WON_BY_SPIRIT;
    }

    return Team::MatchResult::TIE;
}

