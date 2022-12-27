//
// Created by itayi on 21/12/2022.
//
#include <math.h>
#include "Uptrees.h"

const int REMOVED_TEAM = -1;

#define GOLD_FOR_HASH ((sqrt(5) - 1)/2)

void Uptrees::insert(Player *player, Team* team) {
    if (size_of_array/2 < (num_of_players+1)){
        allocateBiggerArray();
    }
    int index = hashID(player->getPlayerId(), false);
    NodePlayer* player_gets_in = new NodePlayer(player->getPlayerId(), player);
    array_of_players[index] = player_gets_in;
    if (team->getLastPlayer() == nullptr){
        NodeTeam* team_node = new NodeTeam(team->getID(), team);
        player_gets_in->setFatherTeam(team_node);
        team_node->addNumOfSonsInSubTree(1);
    }
    else {
        int last_player_id = team->getLastPlayer()->getPlayerId();
        player_gets_in->setFatherPlayer(array_of_players[hashID(last_player_id, true)]);
        NodePlayer* player_node = player_gets_in;
        while (player_node->father_team == nullptr) {
            player_node = player_node->father_player;
        }
        player_node->father_team->addNumOfSonsInSubTree(1);
        player_node->father_team->value->setLastPlayer(player_node->value);
    }
}

int Uptrees::hashID(int i, bool is_find) const {  //constant hash function
    double before_frac = (i * GOLD_FOR_HASH);
    double after_frac = before_frac - long(before_frac);
    int ans = floor(size_of_array * after_frac);
    if (!is_find) {
        while (array_of_players[ans] != nullptr) {
            if (array_of_players[ans]->value->getPlayerId() == i){
                return -1;   //player already exist
            }
            ans++;
        }
        return ans;
    }
    while (array_of_players[ans] != nullptr){
        if (array_of_players[ans]->value->getPlayerId() == i){
            return ans;
        }
        ans++;
    }
    return -1;  //player not found
}

Player *Uptrees::findPlayer(int player_id) const {
    int index = hashID(player_id, true);
    if (index == -1) {
        return nullptr;
    }
    return array_of_players[index]->value;
}


void Uptrees::allocateBiggerArray() {

}

Team *Uptrees::findTeam(int player_id) {
    int index = hashID(player_id, true);
    if (index == -1){
        return nullptr;
    }
    NodePlayer* player_node = array_of_players[index];
    NodePlayer* found_player = player_node;

    while (player_node->father_team == nullptr) {
        player_node = player_node->father_player;
    }

    NodeTeam* root = player_node->father_team;
    player_node = found_player;
    while (player_node->father_team == nullptr) {
        player_node->setFatherTeam(root);
        player_node = player_node->father_player;
    }

    return root->value;
}

void Uptrees::upTreeUnion(Team *bigger_team, Team *smaller_team) {
    int first_player_of_smaller_team = smaller_team->getFirstPlayer()->getPlayerId();
    int last_player_of_bigger_team = bigger_team->getLastPlayer()->getPlayerId();

    NodePlayer* first_player_of_smaller_team_node = array_of_players[hashID
                                                                     (first_player_of_smaller_team, true)];
    NodePlayer* last_player_of_bigger_team_node = array_of_players[hashID
                                                                   (last_player_of_bigger_team, true)];
    first_player_of_smaller_team_node->setFatherPlayer(last_player_of_bigger_team_node);

    int first_player_of_bigger_team = bigger_team->getFirstPlayer()->getPlayerId();
    NodePlayer* first_player_of_bigger_team_node = array_of_players[hashID
                                                                    (first_player_of_bigger_team, true)];
    NodeTeam* new_root = first_player_of_bigger_team_node->father_team;
    new_root->addNumOfSonsInSubTree
    (first_player_of_smaller_team_node->father_team->num_of_sons_in_subtree);
    delete first_player_of_smaller_team_node->father_team;
    first_player_of_smaller_team_node->setFatherTeam(new_root);
}

void Uptrees::removeTeamFromPlayer(int player_id) {
    int index = hashID(player_id, true);
    array_of_players[index]->father_team->key = REMOVED_TEAM;
    array_of_players[index]->father_team->value = nullptr;
}

Uptrees::~Uptrees() {

}
