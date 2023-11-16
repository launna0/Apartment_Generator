#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include "features.hpp"



using namespace std;


namespace apartment {
    bool Bedroom::follows_rules(std::set<char> neighbors, std::vector<char> all_rooms) const {
        (void) neighbors;
        (void) all_rooms;
        return true;
    }
    bool MasterBed::follows_rules(std::set<char> neighbors, std::vector<char> all_rooms) const {
        // RULE: master bedroom must connect to a full bathroom if one exists 
        if ((std::find(all_rooms.begin(), all_rooms.end(), 'F') != all_rooms.end()) 
            && (neighbors.find('F') == neighbors.end())) {
            return false;
        }
        // RULE: if there is at least one closet there must be a 
        // closet connecting to the master bedroom 
        if ((std::find(all_rooms.begin(), all_rooms.end(), 'C') != all_rooms.end()) 
            && (neighbors.find('C') == neighbors.end())) {
            return false;
        }
        return true;
    }
    bool HalfBath::follows_rules(std::set<char> neighbors, std::vector<char> all_rooms) const {
        (void) all_rooms;
        // RULE: two bathrooms should not be connected to each other
        if (neighbors.find('H') != neighbors.end()) {
            return false;
        }
        // RULE: a bathroom cannot connect to a pantry 
        if (neighbors.find('P') != neighbors.end()) {
            return false;
        }
        return true;
    }
    bool FullBath::follows_rules(std::set<char> neighbors, std::vector<char> all_rooms) const {
        (void) all_rooms;
        // RULE: two bathrooms should not be connected to each other
        if (neighbors.find('F') != neighbors.end()) {
            return false;
        }
        // RULE: a bathroom cannot connect to a pantry 
        if (neighbors.find('P') != neighbors.end()) {
            return false;
        }
        return true;
    }
    bool Kitchen::follows_rules(std::set<char> neighbors, std::vector<char> all_rooms) const {
        // RULE: a dining room must be connected to a kitchen if both rooms are in the apartment
        if ((std::find(all_rooms.begin(), all_rooms.end(), 'D') != all_rooms.end()) 
            && (neighbors.find('D') == neighbors.end())) {
            return false;
        }
        return true;
    }
    bool Pantry::follows_rules(std::set<char> neighbors, std::vector<char> all_rooms) const {
        // RULE: a pantry should always connect to a kitchen
        if ((std::find(all_rooms.begin(), all_rooms.end(), 'K') != all_rooms.end()) 
            && (neighbors.find('K') == neighbors.end())) {
            return false;
        }
        // RULE: a closet cannot connect to a pantry
        if (neighbors.find('C') != neighbors.end()) {
            return false;
        }
        return true;
    }
    bool Closet::follows_rules(std::set<char> neighbors, std::vector<char> all_rooms) const {
        (void) all_rooms;
        // RULE: two closets cannot be next to each other
        if (neighbors.find('C') != neighbors.end()) {
            return false;
        }
        return true;
    }
    bool Hallway::follows_rules(std::set<char> neighbors, std::vector<char> all_rooms) const {
        // RULE: If there is at least one bedroom in the apartment, a hallway will be 
        // drawn to connect the bedrooms and the master bedroom.
        (void) all_rooms;
        if (neighbors.find('M') == neighbors.end() || neighbors.find('B') == neighbors.end()) {
            return false;
        }
        return true;
    }
    bool DiningRoom::follows_rules(std::set<char> neighbors, std::vector<char> all_rooms) const {
            (void) neighbors;
            (void) all_rooms;
            return true;
        }
    bool LivingRoom::follows_rules(std::set<char> neighbors, std::vector<char> all_rooms) const {
            (void) neighbors;
            (void) all_rooms;
            return true;
        }
}