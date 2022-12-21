//
// Created by itayi on 21/12/2022.
//

#ifndef WET2_UPTREES_H
#define WET2_UPTREES_H

#include "Player.h"
#include "NodeUpTree.h"
#include "Team.h"

class Uptrees {

public:
    Uptrees(): array_of_players(new NodeUpTree<Player*>*[2]), num_of_players(0), size_of_array(2){}
    ~Uptrees();

    Player* find(int i) const;
    void upTreeUnion(int i, int j);
    void insert(Player* player, Team* team);


private:
    class NodeTeam {
    public:
        NodeTeam(int key, Team* value): key(key), value(value), num_of_sons_in_subtree(1){}
        NodeTeam(const NodeTeam& node) = default;
        NodeTeam& operator=(const NodeTeam& node) = default;
        ~NodeTeam() = default;
        void setKey(int other_key){ key = other_key;}
        void setValue(Team* other_value){ value = other_value;}

        int key;
        Team* value;
        int num_of_sons_in_subtree;
    };
    class NodePlayer {
    public:
        NodePlayer(int key, Player* value): key(key), value(value), father_player(nullptr), father_team(nullptr),
                                            num_of_sons_in_subtree(1){}
        NodePlayer(const NodePlayer& node) = default;
        NodePlayer& operator=(const NodePlayer& node) = default;
        ~NodePlayer() = default;
        void setFatherPlayer(NodePlayer *fat) { father_player = fat;}
        void setFatherTeam(NodeTeam* fat) { father_team = fat;}
        void setKey(int other_key){ key = other_key;}
        void setValue(Player* other_value){ value = other_value;}

        int key;
        Player* value;
        NodePlayer* father_player;
        NodeTeam* father_team;
        bool is_root;
        int num_of_sons_in_subtree;
    };

    NodePlayer** array_of_players;
    int num_of_players;
    int size_of_array;

    int hashID(int i);
    void allocateBiggerArray();
};


#endif //WET2_UPTREES_H
