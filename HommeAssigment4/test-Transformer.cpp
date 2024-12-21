#include <gtest/gtest.h>
#include "Transformer.h"
#include "Autobot.h"
#include "Decepticon.h"
#include "Item.h"

// Tests for class Transformer
TEST(TransformerTest, InitialValues)
{
    Transformer transformer;
    // Check inital values
    EXPECT_EQ(transformer.getLevel(), 15);
    EXPECT_EQ(transformer.getAmmo(), 5);
    EXPECT_EQ(transformer.getFuel(), 20);
}

TEST(TransformerTest, FireWeapon)
{
    Transformer transformer;
    transformer.fire();
    EXPECT_EQ(transformer.getAmmo(), 4);
}




// Test for class Item
TEST(ItemTest, ITEM)
{
    Item item(false, true, false);
    item.setisgun(!item.getisgun()); //
    EXPECT_EQ(item.getisgun(), true);
}

// Test for class Autobot
TEST(AutobotTest, AutobotCreation)
{
    Autobot autobot;
    EXPECT_EQ(autobot.getLevel(), 15); // check init level
    EXPECT_EQ(autobot.getAmmo(), 5); // check init ammo
    EXPECT_EQ(autobot.getFuel(), 20); // check init fuel
}

// Test for class Decepticon
TEST(DecepticonTest, DecepticonCreation)
{
    Decepticon decepticon;
    EXPECT_EQ(decepticon.getLevel(), 15); // check init level
    EXPECT_EQ(decepticon.getAmmo(), 5); // check init ammo
    EXPECT_EQ(decepticon.getFuel(), 20); // check init fuel
}



// Test overload operator
TEST(AutobotTest, ComparisonOperators)
{
    Autobot autobot1(100, true);
    Autobot autobot2(150, false);

    // Checking comparison operators
    EXPECT_LT(autobot1, autobot2);
    EXPECT_GT(autobot2, autobot1);
    EXPECT_FALSE(autobot1 == autobot2);

    autobot1.setFirepowerAutobot(150); // Change for check
    EXPECT_EQ(autobot1, autobot2); // Now they equal
}

// Test comparison operators for Decepticon
TEST(DecepticonTest, ComparisonOperators)
{
    Decepticon decepticon1(120, true);
    Decepticon decepticon2(100, false);

    // Checking comparison operators
    EXPECT_GT(decepticon1, decepticon2);
    EXPECT_LT(decepticon2, decepticon1);
    EXPECT_FALSE(decepticon1 == decepticon2);

    decepticon2.setevil(120); // Change for check
    EXPECT_EQ(decepticon1, decepticon2); // Now they equal
}

// Test comparison between Autobot and Decepticon
TEST(TransformerComparisonTest, AutobotVsDecepticon)
{
    Autobot autobot(130, true);
    Decepticon decepticon(140, true);

    // Checking comparison operators
    EXPECT_LT(autobot, decepticon);
    EXPECT_GT(decepticon, autobot);
    EXPECT_FALSE(autobot == decepticon);

    autobot.setFirepowerAutobot(140); // Change for check
    EXPECT_EQ(autobot, decepticon); // Now they equal
}

