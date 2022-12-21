//
// Created by itayi on 21/12/2022.
//

#ifndef WET2_SKIPLISTTEAMS_H
#define WET2_SKIPLISTTEAMS_H

#include "Team.h"

class SkipListTeams {

public:

    SkipListTeams(): root(nullptr){}
    ~SkipListTeams();

    void insert(int teamId, Team* team);
    Team* find(int teamId) const;
    void remove(int teamId);

private:
    class Node {
    public:
        Node(int key, Team* value): key(key), value(value), right(nullptr), down(nullptr){}
        Node(const Node& node) = default;
        Node& operator=(const Node& node) = default;
        ~Node() = default;
        void setRight(Node *rig) {right = rig;}
        void setLeft(Node *dow) {down = dow;}
        void setKey(int other_key){ key = other_key;}
        void setValue(Team* other_value){ value = other_value;}
        int key;
        Team* value;
        Node* right;
        Node* down;
    };

    Node root;
    int genZeroOrOne();

};


#endif //WET2_SKIPLISTTEAMS_H
