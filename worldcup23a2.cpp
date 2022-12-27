#include "worldcup23a2.h"

world_cup_t::world_cup_t() : m_teams_dictionary(SkipListTeams()),
                             m_all_players_dictionary(Uptrees()) {
    std::srand(time(nullptr));
}

world_cup_t::~world_cup_t() {
    // TODO: Your code goes here
}

StatusType world_cup_t::add_team(int teamId) {
    if (teamId <= 0) {
        return StatusType::INVALID_INPUT;
    }

    try {
        Team *new_team = new Team(teamId);

        StatusType insert_status = m_teams_dictionary.insert(teamId, new_team);

        if (insert_status != StatusType::SUCCESS) {
            delete new_team;
        }

        return insert_status;
    }
    catch (std::bad_alloc &) {
        return StatusType::ALLOCATION_ERROR;
    }
}

StatusType world_cup_t::remove_team(int teamId) {
    if (teamId <= 0) {
        return StatusType::INVALID_INPUT;
    }
    Team* removed_team = m_teams_dictionary.find(teamId);

    if (removed_team == nullptr) {
        return StatusType::FAILURE;
    }

    Player* first_player_of_removed_team = removed_team->getFirstPlayer();
    if (first_player_of_removed_team != nullptr) {
        int first_player_id_of_removed_team = first_player_of_removed_team->getPlayerId();
        m_all_players_dictionary.removeTeamFromPlayer(first_player_id_of_removed_team);
    }

    if (not m_teams_dictionary.remove(teamId)) {
        return StatusType::FAILURE;
    }

    return StatusType::SUCCESS;
}

StatusType world_cup_t::add_player(int playerId, int teamId,
                                   const permutation_t &spirit, int gamesPlayed,
                                   int ability, int cards, bool goalKeeper) {

    if (playerId <= 0 or teamId <= 0 or not spirit.isvalid() or gamesPlayed < 0 or cards < 0) {
        return StatusType::INVALID_INPUT;
    }

    if (m_all_players_dictionary.findPlayer(playerId) != nullptr or m_teams_dictionary.find
    (teamId) == nullptr) {
        return StatusType::FAILURE;
    }

    try {
        Player* new_player = new Player(playerId, teamId, spirit, gamesPlayed, ability, cards,
                                        goalKeeper);
        Team* new_player_team = m_teams_dictionary.find(teamId);
        //new_player_team->setLastPlayer(new_player);
        m_all_players_dictionary.insert(new_player, new_player_team);
    }
    catch (std::bad_alloc &) {
        return StatusType::ALLOCATION_ERROR;
    }

    return StatusType::SUCCESS;
}

output_t<int> world_cup_t::play_match(int teamId1, int teamId2) {
    // TODO: Your code goes here
    return StatusType::SUCCESS;
}

output_t<int> world_cup_t::num_played_games_for_player(int playerId) {
    // TODO: Your code goes here
    return 22;
}

StatusType world_cup_t::add_player_cards(int playerId, int cards) {
    // TODO: Your code goes here
    return StatusType::SUCCESS;
}

output_t<int> world_cup_t::get_player_cards(int playerId) {
    // TODO: Your code goes here
    return StatusType::SUCCESS;
}

output_t<int> world_cup_t::get_team_points(int teamId) {
    // TODO: Your code goes here
    return 30003;
}

output_t<int> world_cup_t::get_ith_pointless_ability(int i) {
    // TODO: Your code goes here
    return 12345;
}

output_t<permutation_t> world_cup_t::get_partial_spirit(int playerId) {
    // TODO: Your code goes here
    return permutation_t();
}

StatusType world_cup_t::buy_team(int teamId1, int teamId2) {
    // TODO: Your code goes here
    return StatusType::SUCCESS;
}

int world_cup_t::get_teams_skip_list_height() const {
    return m_teams_dictionary.get_height();
}
