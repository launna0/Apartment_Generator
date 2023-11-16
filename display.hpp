#ifndef DISPLAY_HPP
#define DISPLAY_HPP

#include <SFML/Graphics.hpp>
#include <vector>
#include <unordered_map>
#include "features.hpp"
#include "Matrix.hpp"

// Uses SFML to display an apartment and the different rooms inside of it. 
void display_placement(Matrix placement, int width, int height);

#endif // DISPLAY_HPP
