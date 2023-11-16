#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
#include <random>
#include "features.hpp"
#include "algorithms.hpp"
#include "display.hpp"
#include "Matrix.hpp"

using namespace std;

int main() {
    int num_beds, num_half_baths, num_full_baths, num_closets, a_width, a_height;
    // Print out statements in terminal and ask user for input
    cout << "Welcome to apartment layout builder v1!" << endl;
    cout << "For every layout, a master bedroom, kitchen, pantry, hallway";
    cout << ", and dining room have all been added." << endl;
    cout << "Enter the max width of your apartment: ";
    cin >> a_width;
    cout << "Enter the max height of your apartment: ";
    cin >> a_height;
    cout << "Please include any addition rooms you want below!" << endl;
    cout << "Enter the number of bedrooms: ";
    cin >> num_beds;
    cout << "Enter the number of half bathrooms: ";
    cin >> num_half_baths;
    cout << "Enter the number of full bathrooms: ";
    cin >> num_full_baths;
    cout << "Enter the number of closets: ";
    cin >> num_closets;

    // Create a vector that stores all of the rooms
    vector<apartment::Entity> user_entities;

    // Add in master bedroom to vector
    apartment::MasterBed master(20, 18);
    user_entities.push_back(master);

    // Add in number of bedrooms depending on what the user specifies
    if (num_beds == 0) {
        apartment::LivingRoom living(15, 12);
        user_entities.push_back(living);
    }
    else if (num_beds == 1) {
        apartment::Bedroom bedroom(15, 12);
        user_entities.push_back(bedroom);
        // Add a hallway if there is one bedroom
        apartment::Hallway hallway(4, 10);
        user_entities.push_back(hallway);
        apartment::LivingRoom living(15, 12);
        user_entities.push_back(living);
    }
    else {
        for (int i = 0; i < num_beds; i++) {
            apartment::Bedroom bedroom(15, 12);
            user_entities.push_back(bedroom);
        }
        // Add a hallway if there is more than 1 bedroom
        apartment::Hallway hallway(4, 10);
        user_entities.push_back(hallway);
        apartment::LivingRoom living(15, 12);
        user_entities.push_back(living);
    }

    // Add half baths into the vector
    for (int i = 0; i < num_half_baths; i++) {
        apartment::HalfBath halfbath(5, 3);
        user_entities.push_back(halfbath);
    }

    // Add full baths into the vector
    for (int i = 0; i < num_full_baths; i++) {
        apartment::FullBath fullbath(7, 5);
        user_entities.push_back(fullbath);
    }

    // Add closets into the vector
    for (int i = 0; i < num_closets; i++) {
        apartment::Closet closet(4, 3);
        user_entities.push_back(closet);
    }
    
    // Add kitchen, pantry, and dining room into the vector
    apartment::Kitchen kitchen1(10, 8);
    apartment::Pantry pantry1(4, 4);
    apartment::DiningRoom dining1(10, 10);
    user_entities.push_back(kitchen1);
    user_entities.push_back(pantry1);
    user_entities.push_back(dining1);

    // Create variable to see if a layout is good and to hold the final layout
    bool good_layout = false;
    int try_count = 0;
    auto final_apartment_fit = can_fit(user_entities, a_width , a_height);

    while ((good_layout == false) && (try_count < 20000)) {
        // Create a random number generator
        std::random_device rd;
        std::mt19937 g(rd());

        // Shuffle the vector using std::shuffle
        std::shuffle(user_entities.begin(), user_entities.end(), g);

        // Create a layout for the apartment 
        auto apartment_fit = can_fit(user_entities, a_width , a_height);

        // Get a map of which rooms are connected to other rooms
        auto neighbor_map = neighbors(apartment_fit, a_width, a_height);
        
        // Declare a vector to store the keys with non-empty sets as values
        vector<char> all_rooms;

        // Iterate over the map and add the keys with non-empty sets to the result vector
        for (const auto& pair : neighbor_map) {
            if (!pair.second.empty()) {
                all_rooms.push_back(pair.first);
            }
        }

        good_layout = true;

        for (std::vector<char>::iterator it = all_rooms.begin(); it != all_rooms.end(); ++it) {
            // check if bedroom rules are followed
            if (*it == 'B') {
                apartment::Bedroom room = apartment::Bedroom(1,1);
                bool follows_rules = room.follows_rules(neighbor_map['B'], all_rooms);
                if (follows_rules == false) {
                    good_layout = false;
                }
            // check if master bedroom rules are followed
            } else if (*it == 'M') {
                apartment::MasterBed room = apartment::MasterBed(1,1);
                bool follows_rules = room.follows_rules(neighbor_map['M'], all_rooms);
                if (follows_rules == false) {
                    good_layout = false;
                }
            // check if half bathroom rules are followed
            } else if (*it == 'H') {
                apartment::HalfBath room = apartment::HalfBath(1,1);
                bool follows_rules = room.follows_rules(neighbor_map['H'], all_rooms);
                if (follows_rules == false) {
                    good_layout = false;
                }
            // check if full bathroom rules are followed
            } else if (*it == 'F') {
                apartment::FullBath room = apartment::FullBath(1,1);
                bool follows_rules = room.follows_rules(neighbor_map['F'], all_rooms);
                if (follows_rules == false) {
                    good_layout = false;
                }
            // check if kitchen rules are followed
            } else if (*it == 'K') {
                apartment::Kitchen room = apartment::Kitchen(1,1);
                bool follows_rules = room.follows_rules(neighbor_map['K'], all_rooms);
                if (follows_rules == false) {
                    good_layout = false;
                }
            // check if pantry rules are followed
            } else if (*it == 'P') {
                apartment::Pantry room = apartment::Pantry(1,1);
                bool follows_rules = room.follows_rules(neighbor_map['P'], all_rooms);
                if (follows_rules == false) {
                    good_layout = false;
                }
            // check if closet rules are followed
            } else if (*it == 'C') {
                apartment::Closet room = apartment::Closet(1,1);
                bool follows_rules = room.follows_rules(neighbor_map['C'], all_rooms);
                if (follows_rules == false) {
                    good_layout = false;
                }
            // check if hallway rules are followed
            } else if (*it == 'W') {
                apartment::Hallway room = apartment::Hallway(1,1);
                bool follows_rules = room.follows_rules(neighbor_map['W'], all_rooms);
                if (follows_rules == false) {
                    good_layout = false;
                }
            // check if dining room rules are followed
            } else if (*it == 'D') {
                apartment::DiningRoom room = apartment::DiningRoom(1,1);
                bool follows_rules = room.follows_rules(neighbor_map['D'], all_rooms);
                if (follows_rules == false) {
                    good_layout = false;
                }
            // check if living rules are followed
            } else if (*it == 'L') {
                apartment::LivingRoom room = apartment::LivingRoom(1,1);
                bool follows_rules = room.follows_rules(neighbor_map['L'], all_rooms);
                if (follows_rules == false) {
                    good_layout = false;
                }
            } 
            
        }
        if (good_layout == true) {
            final_apartment_fit = can_fit(user_entities, a_width , a_height);
        }
        try_count = try_count + 1;
    }
    
    // If there is no good layout given the user specifications, it won't produce a layout
    if (good_layout == false) {
        cout << "No apartment layouts worked given the desired rooms" << endl;
    } else if (final_apartment_fit.at(0,0) == 'X') {
        cout << "No apartment layouts worked given the desired apartment size" << endl;
    // If there is a good layout, it will produce the layout and print out the legend
    } else {
        cout << "Here is a sample layout!" << endl;
        cout << " " << endl;
        cout << "Key for Rooms:" << endl;
        cout << "Bedroom: Red" << endl;
        cout << "Master Bedroom: Dark Red" << endl;
        cout << "Half Bathroom: Light Green" << endl;
        cout << "Full Bathroom: Dark Green" << endl;
        cout << "Kitchen: Light Blue" << endl;
        cout << "Pantry: Dark Blue" << endl;
        cout << "Closet: Purple" << endl;
        cout << "Hallway: Yellow" << endl;
        cout << "Dining Room: Magenta" << endl;
        cout << "Living Room: Orange" << endl;
        cout << "Door: Brown" << endl;
        display_placement(final_apartment_fit, a_width, a_height);
    }
    return 0;
}