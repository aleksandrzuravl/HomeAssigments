#include <gtest/gtest.h>
#include "Transformer.h"
#include "Autobot.h"
#include "Decepticon.h"
#include "Dinobot.h"
#include "Ability.h"
#include "Weapon.h"

// Tests for Assignment5

// Test Autobot
TEST(TransformerPolymorphismTest, AutobotVirtualTest)
{
    Autobot autobot;
    Transformer* transformer = &autobot;

    // Check Fire
    testing::internal::CaptureStdout(); // Capture output to check what exactly was printed to the screen as a result of calling the fire() method
    transformer->fire();
    std::string output_1 = testing::internal::GetCapturedStdout(); // The captured output is saved into the string variable output.
    EXPECT_NE(output_1.find("Autobot"), std::string::npos); // This macro checks that the string "Autobot" is present in the output variable.

    // Check ultimate
    testing::internal::CaptureStdout();
    transformer->ultimate();
    std::string output_2 = testing::internal::GetCapturedStdout();
    EXPECT_NE(output_2.find("Autobot"), std::string::npos);

    //Check transform
    testing::internal::CaptureStdout();
    transformer->transform();
    std::string output_3 = testing::internal::GetCapturedStdout();
    EXPECT_NE(output_3.find("Autobot"), std::string::npos);
}

// Test Decepticon
TEST(TransformerPolymorphismTest, DecepticonVirtualTest)
{
    Decepticon decepticon;
    Transformer* transformer = &decepticon;

    // Check Fire
    testing::internal::CaptureStdout(); // Capture output to check what exactly was printed to the screen as a result of calling the fire() method
    transformer->fire();
    std::string output_1 = testing::internal::GetCapturedStdout(); // The captured output is saved into the string variable output.
    EXPECT_NE(output_1.find("Decepticon"), std::string::npos); // This macro checks that the string "Decepticon" is present in the output variable.

    // Check ultimate
    testing::internal::CaptureStdout();
    transformer->ultimate();
    std::string output_2 = testing::internal::GetCapturedStdout();
    EXPECT_NE(output_2.find("Decepticon"), std::string::npos);

    // Check transform
    testing::internal::CaptureStdout();
    transformer->transform();
    std::string output_3 = testing::internal::GetCapturedStdout();
    EXPECT_NE(output_3.find("Decepticon"), std::string::npos);
}



// Test all Transformer types (Autobot, Decepticon)
TEST(TransformerPolymorphismTest, AllVirtualTest)
{
    Autobot a1, a2, a3;
    Decepticon d1, d2, d3;

    // Create a vector of pointers to different Transformer objects
    std::vector<Transformer*> transformers = {&t1, &t2, &t3, &a1, &a2, &a3, &d1, &d2, &d3};

    // Iterate over each Transformer pointer and test virtual methods
    for (Transformer* tr_mer : transformers)
    {
        testing::internal::CaptureStdout();
        tr_mer->transform();
        std::string output_transform = testing::internal::GetCapturedStdout();

        // Check if the output contains the correct class name
        if (dynamic_cast<Autobot*>(tr_mer))
        {
            EXPECT_NE(output_transform.find("Autobot"), std::string::npos); // Check for "Autobot" in the output
        }
        else (dynamic_cast<Decepticon*>(tr_mer))
        {
            EXPECT_NE(output_transform.find("Decepticon"), std::string::npos); // Check for "Decepticon" in the output
        }

        // Capture the output of fire()
        testing::internal::CaptureStdout();
        tr_mer->fire();
        std::string output_fire = testing::internal::GetCapturedStdout();

        // Check if the output contains the correct class name
        if (dynamic_cast<Autobot*>(tr_mer))
        {
            EXPECT_NE(output_fire.find("Autobot"), std::string::npos); // Check for "Autobot" in the output
        }
        else (dynamic_cast<Decepticon*>(tr_mer))
        {
            EXPECT_NE(output_fire.find("Decepticon"), std::string::npos);  // Check for "Decepticon" in the output
        }

        // Capture the output of ultimate()
        testing::internal::CaptureStdout();
        tr_mer->ultimate();
        std::string output_ultimate = testing::internal::GetCapturedStdout();

        // Check if the output contains the correct class name
        if (dynamic_cast<Autobot*>(tr_mer))
        {
            EXPECT_NE(output_ultimate.find("Autobot"), std::string::npos); // Check for "Autobot" in the output
        }
        else (dynamic_cast<Decepticon*>(tr_mer))
        {
            EXPECT_NE(output_ultimate.find("Decepticon"), std::string::npos);  // Check for "Decepticon" in the output
        }
    }
}
