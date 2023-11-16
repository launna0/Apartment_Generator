#include <iostream>
#include <sstream>
#include "unit_test_framework.h"
#include "algorithms.hpp"
#include "features.hpp"

using namespace std;

// placing one room that can fit 
TEST(test_can_fit_one)
{
  vector<apartment::Entity> entities;
  apartment::Bedroom sample_room(3, 3);
  entities.push_back(sample_room);

  Matrix actual = can_fit(entities, 3, 3);

  
  ASSERT_EQUAL(actual.at(1,1), 'B');
}

// making sure that walls are properly placed with one room 
TEST(test_can_fit_two)
{
  vector<apartment::Entity> entities;
  apartment::Bedroom sample_room(3, 3);
  entities.push_back(sample_room);

  Matrix actual = can_fit(entities, 3, 3);

  
  ASSERT_EQUAL(actual.at(0,0), 'Z');
  ASSERT_EQUAL(actual.at(2,2), 'Z');
}

// testing a small room that cannot fit
TEST(test_can_fit_three)
{
  vector<apartment::Entity> entities;
  apartment::Bedroom sample_room(4, 4);
  entities.push_back(sample_room);

  Matrix actual = can_fit(entities, 3, 3);

  
  ASSERT_EQUAL(actual.at(1,1), 'X');
}

// testing a small room that cannot fit
TEST(test_can_fit_four)
{
  vector<apartment::Entity> entities;
  apartment::Bedroom sample_room(4, 3);
  entities.push_back(sample_room);

  Matrix actual = can_fit(entities, 3, 3);

  
  ASSERT_EQUAL(actual.at(0,0), 'X');
}

// testing two rooms connected, door is placed 
TEST(test_can_fit_five)
{
  vector<apartment::Entity> entities;
  apartment::Bedroom sample_room(3, 3);
  entities.push_back(sample_room);
  entities.push_back(sample_room);

  Matrix actual = can_fit(entities, 6, 6);

  
  ASSERT_EQUAL(actual.at(2,1), 'Q');
  ASSERT_EQUAL(actual.at(3,1), 'B');
}

// testing two rooms connected, only one wall in between rooms
TEST(test_can_fit_six)
{
  vector<apartment::Entity> entities;
  apartment::Bedroom sample_room(3, 3);
  entities.push_back(sample_room);
  entities.push_back(sample_room);

  Matrix actual = can_fit(entities, 6, 6);

  
  ASSERT_EQUAL(actual.at(3,1), 'B');
}

// testing two rooms, cannot fit
TEST(test_can_fit_seven)
{
  vector<apartment::Entity> entities;
  apartment::Bedroom sample_room(3, 3);
  entities.push_back(sample_room);
  entities.push_back(sample_room);

  Matrix actual = can_fit(entities, 5, 5);

  ASSERT_EQUAL(actual.at(0, 0), 'X');
  ASSERT_EQUAL(actual.at(2, 2), 'X');
  ASSERT_EQUAL(actual.at(4, 4), 'X');
}

// testing three rooms, rooms are placed 
TEST(test_can_fit_eight)
{
  vector<apartment::Entity> entities;
  apartment::Bedroom sample_room(3, 3);
  apartment::FullBath sample_room_two(6, 3);
  entities.push_back(sample_room_two);
  entities.push_back(sample_room);
  entities.push_back(sample_room);

  Matrix actual = can_fit(entities, 6, 6);

  ASSERT_EQUAL(actual.at(1, 1), 'F');
  ASSERT_EQUAL(actual.at(4, 4), 'B');
  ASSERT_EQUAL(actual.at(4, 1), 'B');
}

// testing three rooms, doors between
TEST(test_can_fit_nine)
{
  vector<apartment::Entity> entities;
  apartment::Bedroom sample_room(3, 3);
  apartment::FullBath sample_room_two(6, 3);
  entities.push_back(sample_room_two);
  entities.push_back(sample_room);
  entities.push_back(sample_room);

  Matrix actual = can_fit(entities, 6, 6);

  ASSERT_EQUAL(actual.at(2, 1), 'Q');
  ASSERT_EQUAL(actual.at(2, 4), 'Q');
}

// testing three rooms, one wall between
TEST(test_can_fit_ten)
{
  vector<apartment::Entity> entities;
  apartment::Bedroom sample_room(3, 3);
  apartment::FullBath sample_room_two(6, 3);
  entities.push_back(sample_room_two);
  entities.push_back(sample_room);
  entities.push_back(sample_room);

  Matrix actual = can_fit(entities, 6, 6);

  ASSERT_EQUAL(actual.at(1, 1), 'F');
  ASSERT_EQUAL(actual.at(2, 1), 'Q');
  ASSERT_EQUAL(actual.at(3, 1), 'B');
}


// test no neighbors 
TEST(test_neighbor_one)
{
Matrix test_layout = Matrix(3, 1, 'B');
std::map<char, std::set<char>> actual = neighbors(test_layout, 3, 3);
bool actual_bool = actual['B'].empty();

ASSERT_EQUAL(actual_bool, true);
}

// testing a room having itself as a neighbor 
TEST(test_neighbor_two)
{
  vector<apartment::Entity> entities;
  apartment::Bedroom sample_room(3, 3);
  entities.push_back(sample_room);
  entities.push_back(sample_room);
  Matrix actual = can_fit(entities, 6, 6);

std::map<char, std::set<char>> actual_map = neighbors(actual, 6, 6);
char actual_char = *actual_map['B'].begin();

ASSERT_EQUAL(actual_char, 'B');
}

// testing a room having another room as its neighbor 
TEST(test_neighbor_three)
{
  vector<apartment::Entity> entities;
  apartment::Bedroom sample_room(3, 3);
  apartment::FullBath sample_room_two(3, 3);
  entities.push_back(sample_room);
  entities.push_back(sample_room_two);
  Matrix actual = can_fit(entities, 6, 6);

std::map<char, std::set<char>> actual_map = neighbors(actual, 6, 6);
char actual_char = *actual_map['B'].begin();

ASSERT_EQUAL(actual_char, 'F');
}

// multiple neighbors 
TEST(test_neighbor_four)
{
  vector<apartment::Entity> entities;
  apartment::Bedroom sample_room(3, 3);
  apartment::FullBath sample_room_two(3, 3);
  entities.push_back(sample_room);
  entities.push_back(sample_room_two);
  entities.push_back(sample_room_two);
  Matrix actual = can_fit(entities, 9, 9);

std::map<char, std::set<char>> actual_map = neighbors(actual, 9, 9);
char actual_char_first = *actual_map['F'].begin();
char actual_char_last = *next(actual_map['F'].begin(), 1);

ASSERT_EQUAL(actual_char_first, 'B');
ASSERT_EQUAL(actual_char_last, 'F');
}

TEST_MAIN()


