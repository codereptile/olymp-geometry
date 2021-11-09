#include <gtest/gtest.h>
#include "../lib/olymp-geometry.h"
#include "../lib/olymp-geometry.cpp"
#include <filesystem>
#include <fstream>

// Demonstrate some basic assertions.
TEST(Vector, VectorLength) {
    // Get all tests:
    std::vector<std::string> tests;
    std::filesystem::directory_iterator directory_iterator("../tests/vector_length/");
    for (const auto& file_entry : directory_iterator) {
        tests.push_back(file_entry.path());
    }
    std::sort(tests.begin(), tests.end());

    // Execute all tests
    for (int i = 0; i < tests.size(); i += 2) {
        std::ifstream test_stream(tests[i]);
        std::ifstream ans_stream(tests[i + 1]);

        olymp_geometry::Vector a, b;
        test_stream >> a >> b;
        olymp_geometry::Vector c = b - a;

        long double ans;
        ans_stream >> ans;

        EXPECT_FLOAT_EQ(c.Length(), ans);
    }
}
