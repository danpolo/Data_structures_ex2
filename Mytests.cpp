//
// Created by itayi on 21/11/2022.
//
#include <windows.h>
#include <vector>
#include <cstdlib>
#include <random>
#include <iostream>

#include "Player.h"
#include "worldcup23a2.h"

#define ASSERT(action, expected) if(action != expected) return false

const int MAX_LINE_LENGTH = 75;

void printFunctionName(std::string str) {
    std::string out;
    out += str[0] - 32;
    for (int i = 1; i < str.length(); i++) {
        if (str[i] >= 'A' && str[i] <= 'Z') {
            str[i] = str[i] + 32;
            if (i != 0) {
                out += " ";
            }
            out += str[i];
        } else {
            out += str[i];
        }
    }
    std::cout << "Running test: " << out << std::string(MAX_LINE_LENGTH - out.length(), ' ');
}


bool runAutomaticTests(const std::vector<bool (*)()> &tests) {
    std::cout << "Running Automatic Tests" << std::endl;
    std::cout << std::string(MAX_LINE_LENGTH + 28, '-') << std::endl;
    bool all_tests_passed = true;
    for (auto test: tests) {
        try {
            if (test()) {
                std::cout << "\033[1;32m - TEST PASSED\033[0m" << std::endl;
            } else {
                all_tests_passed = false;
                std::cout << "\033[1;31m - TEST FAILED\033[0m" << std::endl;
            }
        }
        catch (...) {
            all_tests_passed = false;
            std::cout << "\033[1;31m - TEST FAILED\033[0m" << std::endl;
        }
    }
    return all_tests_passed;
}

bool addRemoveTeam() {
    printFunctionName(__FUNCTION__);
    world_cup_t game = world_cup_t();
    int id = 0;
    for (int i = 1; i <= 1000; i++) {
        ASSERT(game.add_team(id + 1), StatusType::SUCCESS);
        id = (id + 733) % 1000;
    }
    for (int i = 1; i <= 1000; i++) {
        ASSERT(game.add_team(i), StatusType::FAILURE);
    }
    for (int i = 100; i <= 200; i++) {
        ASSERT(game.remove_team(i), StatusType::SUCCESS);
    }
    for (int i = 100; i <= 200; i++) {
        ASSERT(game.add_team(i), StatusType::SUCCESS);
    }
    return true;
}

int main() {
    std::cout << "Ignore this (Its for the colors)-> ";
    system(("chcp " + std::to_string(CP_UTF8)).c_str());
    std::cout << std::string(MAX_LINE_LENGTH + 28, '-') << std::endl;

    std::vector<bool (*)()> automatic_tests = {&addRemoveTeam};

    std::vector<void (*)()> manual_tests = {};

    if (runAutomaticTests(automatic_tests)) {
        std::cout << std::string(MAX_LINE_LENGTH + 28, '-') << std::endl;
        std::cout << "\033[1;32mALL TESTS PASSED!!!\033[0m" << std::endl;
    } else {
        std::cout << std::string(MAX_LINE_LENGTH + 28, '-') << std::endl;
        std::cout << "\033[1;31mSome of the automatic tests failed\033[0m" << std::endl;
    }
    std::cout << std::string(MAX_LINE_LENGTH + 28, '-') << std::endl;
    std::cout << "Running Manual Tests" << std::endl;
    std::cout << std::string(MAX_LINE_LENGTH + 28, '-') << std::endl;

    for (auto test: manual_tests) {
        test();
    }

    return 0;
}