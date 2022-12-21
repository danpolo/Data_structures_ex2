//
// Created by itayi on 21/12/2022.
//

#include "Uptrees.h"

void Uptrees::insert(Player *player, Team* team) {
    if (size_of_array/2 < (num_of_players+1)){
        allocateBiggerArray();
    }
    int index = hashID(player->getPlayerId());
    NodePlayer* player_gets_in = new NodePlayer(player->getPlayerId(), player);
    array_of_players[index] = player_gets_in;
    if (team->getLastPlayer() == nullptr){
        NodeTeam* team_node = new NodeTeam(team->getID(), team);
        player_gets_in->setFatherTeam(team_node);
        team_node->addNumOfSonsInSubTree(1);
    }
    else {
        int last_player_id = team->getLastPlayer()->getPlayerId();
        player_gets_in->setFatherPlayer(array_of_players[hashID(last_player_id)]);
        NodePlayer* player_node = player_gets_in;
        while (player_node->father_team == nullptr) {
            player_node = player_node->father_player;
        }
        player_node->father_team->addNumOfSonsInSubTree(1);
    }
}

int Uptrees::hashID(int i) const {  //needs a better hash to prevent collisions
    return (i % size_of_array);
}

Player *Uptrees::findPlayer(int player_id) const {
    int index = hashID(player_id);
    if (array_of_players[index] == nullptr) {
        return nullptr;
    }
    Player* temp_player = array_of_players[index]->value;
    if (temp_player->getPlayerId() == player_id) {
        return temp_player;
    }
    return nullptr;
}


void Uptrees::allocateBiggerArray() {

}

Team *Uptrees::findTeam(int player_id) {
    int index = hashID(player_id);
    NodePlayer* player_node = array_of_players[index];
    NodePlayer* found_player = player_node;

    if (player_node == nullptr) {
        return nullptr;
    }

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
                                                                     (first_player_of_smaller_team)];
    NodePlayer* last_player_of_bigger_team_node = array_of_players[hashID
                                                                   (last_player_of_bigger_team)];
    first_player_of_smaller_team_node->setFatherPlayer(last_player_of_bigger_team_node);

    int first_player_of_bigger_team = bigger_team->getFirstPlayer()->getPlayerId();
    NodePlayer* first_player_of_bigger_team_node = array_of_players[hashID
                                                                    (first_player_of_bigger_team)];
    NodeTeam* new_root = first_player_of_bigger_team_node->father_team;
    new_root->addNumOfSonsInSubTree
    (first_player_of_smaller_team_node->father_team->num_of_sons_in_subtree);
    delete first_player_of_smaller_team_node->father_team;
    first_player_of_smaller_team_node->setFatherTeam(new_root);
}
