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
        NodeTeam* team_as_a_node = new NodeTeam(team->getID(), team);
        player_gets_in->setFatherTeam(team_as_a_node);
    }
}

int Uptrees::hashID(int i) {  //needs a better hash to prevent collisions
    return (i % size_of_array);
}