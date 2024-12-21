#include <gtest/gtest.h>
#include "Transformer.h"
#include "Autobot.h"
#include "Decepticon.h"
#include "Item.h"

// Tests for class Transformer
TEST(TransformerTest, InitialValues) {
    Transformer transformer;
    // Check inital values
    EXPECT_EQ(transformer.getLevel(), 15);
    EXPECT_EQ(transformer.getAmmo(), 5);
    EXPECT_EQ(transformer.getFuel(), 20);
}

TEST(TransformerTest, FireWeapon) {
    Transformer transformer;
    transformer.fire();
    EXPECT_EQ(transformer.getAmmo(), 5);
}

}

// Test for class item
TEST(ItemTest, ITEM)
{
    Item item(false, true, false);
    item.setisgun(!item.getisgun()); //
    EXPECT_EQ(item.getisgun(), true);
}

// Test for class Autobot
TEST(AutobotTest, AutobotCreation) {
    Autobot autobot;
    EXPECT_EQ(autobot.getLevel(), 15); // check init level
    EXPECT_EQ(autobot.getAmmo(), 5); // check init ammo
    EXPECT_EQ(autobot.getFuel(), 20); // check init fuel
}

// Test for class Decepticon
TEST(DecepticonTest, DecepticonCreation) {
    Decepticon decepticon;
    EXPECT_EQ(decepticon.getLevel(), 15); // check init level
    EXPECT_EQ(decepticon.getAmmo(), 5); // check init ammo
    EXPECT_EQ(decepticon.getFuel(), 20); // check init fuel
}




int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
