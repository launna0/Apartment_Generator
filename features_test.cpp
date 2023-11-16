#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include "features.hpp"
#include "unit_test_framework.h"

using namespace std;

TEST(test_master_one)
{
    vector<char> all_rooms = {'M', 'F'};
    set<char> neighbors = {'F'};
    apartment::MasterBed test_master = apartment::MasterBed(10, 10);
    bool actual = test_master.follows_rules(neighbors, all_rooms);
    ASSERT_EQUAL(actual, true);
}

TEST(test_master_two)
{
    vector<char> all_rooms = {'M', 'F', 'C'};
    set<char> neighbors = {'F', 'C'};
    apartment::MasterBed test_master = apartment::MasterBed(10, 10);
    bool actual = test_master.follows_rules(neighbors, all_rooms);
    ASSERT_EQUAL(actual, true);
}

TEST(test_halfBath_one)
{
    vector<char> all_rooms = {'H', 'H', 'M'};
    set<char> neighbors = {'M'};
    apartment::HalfBath test_master = apartment::HalfBath(10, 10);
    bool actual = test_master.follows_rules(neighbors, all_rooms);
    ASSERT_EQUAL(actual, true);
}

TEST(test_halfBath_two)
{
    vector<char> all_rooms = {'H', 'H', 'M', 'F', 'C'};
    set<char> neighbors = {'H'};
    apartment::HalfBath test_master = apartment::HalfBath(10, 10);
    bool actual = test_master.follows_rules(neighbors, all_rooms);
    ASSERT_EQUAL(actual, false);
}

TEST(test_fullBath_one)
{
    vector<char> all_rooms = {'F', 'M', 'C', 'F'};
    set<char> neighbors = {'F'};
    apartment::FullBath test_master = apartment::FullBath(10, 10);
    bool actual = test_master.follows_rules(neighbors, all_rooms);
    ASSERT_EQUAL(actual, false);
}

TEST(test_fullBath_two)
{
    vector<char> all_rooms = {'B', 'M', 'H', 'F', 'F', 'F', 'K', 'P', 'F', 'C', 'W', 'D', 'L'};
    set<char> neighbors = {'F'};
    apartment::FullBath test_master = apartment::FullBath(10, 10);
    bool actual = test_master.follows_rules(neighbors, all_rooms);
    ASSERT_EQUAL(actual, false);
}

TEST(test_kitchen_one)
{
    vector<char> all_rooms = {'K', 'D'};
    set<char> neighbors = {'D'};
    apartment::Kitchen test_master = apartment::Kitchen(10, 10);
    bool actual = test_master.follows_rules(neighbors, all_rooms);
    ASSERT_EQUAL(actual, true);
}

TEST(test_kitchen_two)
{
    vector<char> all_rooms = {'B', 'M', 'H', 'F', 'K', 'P', 'C', 'W', 'D', 'L'};
    set<char> neighbors = {'D'};
    apartment::Kitchen test_master = apartment::Kitchen(10, 10);
    bool actual = test_master.follows_rules(neighbors, all_rooms);
    ASSERT_EQUAL(actual, true);
}

TEST(test_kitchen_three)
{
    vector<char> all_rooms = {'K', 'C'};
    set<char> neighbors = {'C'};
    apartment::Kitchen test_master = apartment::Kitchen(10, 10);
    bool actual = test_master.follows_rules(neighbors, all_rooms);
    ASSERT_EQUAL(actual, true);
}

TEST(test_pantry_one)
{
    vector<char> all_rooms = {'B', 'M', 'H', 'F', 'K', 'P', 'C', 'W', 'D', 'L'};
    set<char> neighbors = {'K'};
    apartment::Pantry test_master = apartment::Pantry(10, 10);
    bool actual = test_master.follows_rules(neighbors, all_rooms);
    ASSERT_EQUAL(actual, true);
}

TEST(test_pantry_two)
{
    vector<char> all_rooms = {'P', 'L'};
    set<char> neighbors = {'L'};
    apartment::Pantry test_master = apartment::Pantry(10, 10);
    bool actual = test_master.follows_rules(neighbors, all_rooms);
    ASSERT_EQUAL(actual, true);
}

TEST(test_closet_one)
{
    vector<char> all_rooms = {'C', 'C', 'B'};
    set<char> neighbors = {'B'};
    apartment::Closet test_master = apartment::Closet(10, 10);
    bool actual = test_master.follows_rules(neighbors, all_rooms);
    ASSERT_EQUAL(actual, true);
}

TEST(test_closet_two)
{
    vector<char> all_rooms = {'C', 'C', 'C', 'C', 'B', 'L'};
    set<char> neighbors = {'B', 'L'};
    apartment::Closet test_master = apartment::Closet(10, 10);
    bool actual = test_master.follows_rules(neighbors, all_rooms);
    ASSERT_EQUAL(actual, true);
}

TEST(test_closet_three)
{
    vector<char> all_rooms = {'C', 'C', 'B'};
    set<char> neighbors = {'B', 'C'};
    apartment::Closet test_master = apartment::Closet(10, 10);
    bool actual = test_master.follows_rules(neighbors, all_rooms);
    ASSERT_EQUAL(actual, false);
}

TEST(test_hallway_one)
{
    vector<char> all_rooms = {'W', 'B', 'K', 'D', 'M'};
    set<char> neighbors = {'B', 'M'};
    apartment::Hallway test_master = apartment::Hallway(10, 10);
    bool actual = test_master.follows_rules(neighbors, all_rooms);
    ASSERT_EQUAL(actual, true);
}

TEST(test_hallway_two)
{
    vector<char> all_rooms = {'W', 'M', 'B', 'B', 'B'};
    set<char> neighbors = {'B', 'B', 'B', 'M'};
    apartment::Hallway test_master = apartment::Hallway(10, 10);
    bool actual = test_master.follows_rules(neighbors, all_rooms);
    ASSERT_EQUAL(actual, true);
}



TEST_MAIN()
