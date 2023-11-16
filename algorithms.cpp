#include <vector>
#include <array>
#include <string>
#include <set>
#include <map>
#include <iostream>
#include <algorithm>
#include <SFML/Graphics.hpp>

#include "features.hpp"
#include "algorithms.hpp"
#include "Matrix.hpp"



Matrix can_fit(std::vector<apartment::Entity> entities, int width, int height) {

    // create a matrix to place rooms
    Matrix placement = Matrix(width, height);

    // create variables to detect the remaining hegiht and width of apartment
    int remaining_width = width;
    int remaining_height = height;

    // loop through all of the rooms that should be placed 
    for (auto entity : entities) {
        bool placed = false;

        // Try to place entity in the box
        for (int i = 0; i <= width - entity.get_width(); i++) {
            for (int j = 0; j <= height - entity.get_height(); j++) {
                bool fits = true;
                for (int x = i; x < i + entity.get_width(); x++) {
                    for (int y = j; y < j + entity.get_height(); y++) {
                        if (placement.at(y, x) != 'E') {
                            fits = false;
                            break;
                        }
                    }
                    // a rooms doesn't fit
                    if (!fits) {
                        break;
                    }
                }
                if (fits) {
                    // Place entity in the box
                    for (int x = i; x < i + entity.get_width(); x++) {
                        for (int y = j; y < j + entity.get_height(); y++) {
                            // deals with the potential of walls on the left and right side 
                            if (x == i || x == i + entity.get_width() - 1) {
                                if ((placement.at(y, x - 1) == 'Z') || 
                                    (placement.at(y, x + 1) == 'Z')) {
                                    placement.at(y, x) = entity.get_label();
                                } else {
                                    placement.at(y, x) = 'Z';
                                }
                            } 
                            // deals with the potential of walls on the top and bottom 
                            else if (y == j || y == j + entity.get_height() - 1) {
                                if (placement.at(y - 1, x) == 'Z' || 
                                    placement.at(y + 1, x) == 'Z') {
                                    placement.at(y, x) = entity.get_label();
                                } else {
                                    placement.at(y, x) = 'Z';
                                }
                            }
                            else {
                                placement.at(y, x) = entity.get_label();
                            }

                            // cleans up the corners of rooms to make sure they 
                            // are producing the right label
                            if ((x == i && y == j) || (x == i && y == j + entity.get_height() - 1)
                                    || (x == i + entity.get_width() - 1 && y == j) || 
                                        (x == i + entity.get_width() - 1 && 
                                            y == j + entity.get_height() - 1)) {
                                    if (((placement.at(y, x - 1) == 'Z') && 
                                        (placement.at(y - 1, x) == 'Z') && (x == i)) || 
                                    ((placement.at(y, x - 1) == 'Z') && 
                                        (placement.at(y + 1, x) == 'Z')  && (x == i))) {
                                        placement.at(y, x) = entity.get_label();
                                    }
                                    else {
                                        placement.at(y, x) = 'Z';
                                    }
                            }
                            
                        }
                    }

                    // adding doors 
                    // making sure there is only one door between rooms
                    bool upper = false;
                    bool lower = false;
                    bool left = false;
                    bool right = false;
                    std::vector<char> rooms = {'B', 'M', 'H', 'F', 'K', 'P', 'C', 'W', 'D', 'L'};

                    
                    for (int x = i; x < i + entity.get_width(); x++) {
                        for (int y = j; y < j + entity.get_height(); y++) {

                        // place a door on the left side of a room 
                        if ((x == i) && (left == false) && (y != j) && 
                            (y != j + entity.get_height() - 1)) {
                            if (placement.at(y, x) == 'Z') {
                                if (std::find(rooms.begin(), rooms.end(),placement.at(y, x - 1)) 
                                    != rooms.end()) {
                                    placement.at(y, x) = 'Q';
                                    left = true;  
                                }
                            } else {
                                if (std::find(rooms.begin(), rooms.end(),placement.at(y, x - 2)) 
                                    != rooms.end()) {
                                    placement.at(y, x - 1) = 'Q';
                                    left = true;  
                                }
                            }
                        }

                        // place a door on the right side of a room 
                        if ((x == i + entity.get_width() - 1) && (right == false) && (y != j) && 
                            (y != j + entity.get_height() - 1)) {
                            if (placement.at(y, x) == 'Z') {
                                if (std::find(rooms.begin(), rooms.end(), 
                                    placement.at(y, x + 1)) != rooms.end()) {
                                    placement.at(y, x) = 'Q';
                                    right = true;  
                                }
                            } else {
                                if (std::find(rooms.begin(), rooms.end(), 
                                    placement.at(y, x + 2)) != rooms.end()) {
                                    placement.at(y, x + 1) = 'Q';
                                    right = true;  
                                }
                            }
                        }

                        // place a door on the top of a room 
                        if ((y == j) && (upper == false) && (x != i) && 
                            (x != i + entity.get_width() - 1) && y != 0) {
                            if (placement.at(y, x) == 'Z') {
                                if (std::find(rooms.begin(), rooms.end(), 
                                    placement.at(y - 1, x)) != rooms.end()) {
                                    placement.at(y, x) = 'Q';
                                    upper = true;  
                                }
                            } else {
                                if (std::find(rooms.begin(), rooms.end(), 
                                    placement.at(y - 2, x)) != rooms.end()) {
                                    placement.at(y - 1, x) = 'Q';
                                    upper = true;  
                                }
                            }
                        }

                        // place a door on the bottom  of a room 
                        if ((y == j + entity.get_height() - 1) && (lower == false) && (x != i) && 
                            (x != i + entity.get_width() - 1)) {
                            if (placement.at(y, x) == 'Z') {
                                if (std::find(rooms.begin(), rooms.end(), 
                                    placement.at(y + 1, x)) != rooms.end()) {
                                    placement.at(y, x) = 'Q';
                                    lower = true;  
                                }
                            } else {
                                if (std::find(rooms.begin(), rooms.end(), 
                                    placement.at(y + 2, x)) != rooms.end()) {
                                    placement.at(y + 1, x) = 'Q';
                                    lower = true;  
                                }
                            }
                        }

                        }
                    }

                    // Update remaining width and height of the box
                    remaining_width = std::min(remaining_width, i + entity.get_width());
                    remaining_height = std::min(remaining_height, j + entity.get_height());

                    placed = true;
                    break;
                }

            }
            if (placed) {
                break;
            }
        }

        // what to print out if the rooms cannot fit in the apartment size
        if (!placed) {
            return Matrix(width, height, 'X');
        }
    }
    // what to do if the rooms can fit in the apartment 
    return placement;
}




// create the function to get which rooms are neighbors to other rooms in a given layout
std::map<char, std::set<char>> neighbors(Matrix placement, int width, int height) {

    // create a map to hold neighbor values and a list of all possible rooms
    std::map<char, std::set<char>> neighbor_map;
    std::vector<char> rooms = {'B', 'M', 'H', 'F', 'K', 'P', 'C', 'W', 'D', 'L'};

    // create a key for each possible room 
    for (char room : rooms) {
        neighbor_map.insert({room, {}});
    }

    // loop through all blocks and look specifically for doors
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {

            char current = placement.at(i, j);

            if (current == 'Q') {

                std::vector<char> neighbors;

                // look in all directions to see what two rooms the door is connecting 
                if (std::find(rooms.begin(), rooms.end(), placement.at(i, j - 1)) != rooms.end()) {
                    neighbors.push_back(placement.at(i, j - 1));
                }
                if (std::find(rooms.begin(), rooms.end(), placement.at(i, j + 1)) != rooms.end()) {
                    neighbors.push_back(placement.at(i, j + 1));
                }
                if (std::find(rooms.begin(), rooms.end(), placement.at(i - 1, j)) != rooms.end()) {
                    neighbors.push_back(placement.at(i - 1, j));
                }
                if (std::find(rooms.begin(), rooms.end(), placement.at(i + 1, j)) != rooms.end()) {
                    neighbors.push_back(placement.at(i + 1, j));
                }

                // make sure that a set of rooms has been found
                if (!neighbors.empty()) {
                    // add the second room to the neighbor set of the first room 
                    auto r1 = neighbor_map.find(neighbors.front());
                        std::set<char>& n_set1 = r1->second;
                        if (n_set1.find(neighbors.back()) == n_set1.end()) {
                            n_set1.insert(neighbors.back());
                        }

                    // add the first room to the neighbor set of the second room 
                    auto r2 = neighbor_map.find(neighbors.back());
                        std::set<char>& n_set2 = r2->second;
                        if (n_set2.find(neighbors.front()) == n_set2.end()) {
                            n_set2.insert(neighbors.front());
                        }
                }
            }
        }
    }  
    // return the map of neighbors
    return neighbor_map;
}






