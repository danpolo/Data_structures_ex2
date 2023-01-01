#include "Player.h"


Player::Player(int player_id, int team_id, const permutation_t &spirit, int games_played,
               int ability, int cards, bool is_GK) :  player_id(player_id), team_id(team_id), spirit
               (spirit), games_played(games_played), ability(ability), cards(cards), is_GK(is_GK){
}

void Player::setTeamID(int teamID) {
    team_id = teamID;
}

int Player::getTeamID() const{
    return team_id;
}

permutation_t Player::getSpirit() const {
    return spirit;
}

void Player::addCards(int addCards) {
    cards += addCards;
}

void Player::addGamesPlayed(int added) {
    games_played += added;
}


int Player::getPlayerId() const {
    return player_id;
}


int Player::getCards() const {
    return cards;
}

int Player::getGamesPlayed() const {
    return games_played;
}

bool Player::isGk() const {
    return is_GK;
}
