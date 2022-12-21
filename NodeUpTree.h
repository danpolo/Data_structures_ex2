//
// Created by itayi on 21/12/2022.
//

#ifndef WET2_NODEUPTREE_H
#define WET2_NODEUPTREE_H

#include "Team.h"

template<class VALUE>
class NodeUpTree {
public:
    NodeUpTree(int key, VALUE value): key(key), value(value), father_player(nullptr), is_root(true),
                                      num_of_sons_in_subtree(1){}
    NodeUpTree(const NodeUpTree& node) = default;
    NodeUpTree& operator=(const NodeUpTree& node) = default;
    ~NodeUpTree() = default;
    void setFatherPlayer(NodeUpTree *fat) { father_player = fat;}
    void setFatherTeam(NodeUpTree *fat) { father_team = fat;}
    void setKey(int other_key){ key = other_key;}
    void setValue(VALUE other_value){ value = other_value;}

private:
    int key;
    VALUE value;
    NodeUpTree<Player*>* father_player;
    NodeUpTree<Team*>* father_team;
    bool is_root;
    int num_of_sons_in_subtree;
};


#endif //WET2_NODEUPTREE_H
