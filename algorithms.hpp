#ifndef APARTMENT_PLACEMENT_HPP
#define APARTMENT_PLACEMENT_HPP

#include <vector>
#include <set>
#include <array>
#include <algorithm>
#include <map>

#include "features.hpp"
#include "Matrix.hpp"



// Checks to see if a vector of rooms can be placed in an apartment based 
// on size alone. If they can be it creates a layout that fits all of the 
// different rooms with doors in between them. 
Matrix can_fit(std::vector<apartment::Entity> entities, int width, int height);

// find the neighbors of a specific room. 
std::map<char, std::set<char>> neighbors(Matrix placement, int width, int height);


#endif // APARTMENT_PLACEMENT_HPP









    




