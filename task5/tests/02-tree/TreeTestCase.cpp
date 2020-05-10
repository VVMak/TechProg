//
// Created by akhtyamovpavel on 5/1/20.
//


#include "TreeTestCase.h"
#include "Tree.h"
#include <boost/filesystem.hpp>
#include <string>

TEST(TreeTestCase, PathNotExist) {
    try {
        GetTree("/..*?абвгде", false);
    } catch (const std::invalid_argument& e) {
        ASSERT_STREQ(e.what(), "Path not exist");
    } catch (...) {
        ASSERT_TRUE(false);
    }
}

TEST(TreeTestCase, PathIsNotDirectory) {
    std::string file = boost::filesystem::temp_directory_path().string() + "/testTreeNotDirectory.txt";
    freopen(file.c_str(), "w", stdout);
    std::cout << "Hello, world!\n";
    try {
        GetTree(file, false);
    } catch (const std::invalid_argument& e) {
        ASSERT_STREQ(e.what(), "Path is not directory");
    } catch (...) {
        ASSERT_TRUE(false);
    }
    boost::filesystem::remove(file);
}

TEST(TreeTestCase, MainCase) {
    std::string tmp = boost::filesystem::temp_directory_path().string();
    boost::filesystem::create_directory(tmp + "/TestFolder");
    freopen((tmp + "/TestFolder/first.txt").c_str(), "w", stdout);
    std::cout << "First\n";
    boost::filesystem::create_directory(tmp + "/TestFolder/SubFolder");
    freopen((tmp + "/TestFolder/SubFolder/second.txt").c_str(), "w", stdout);
    std::cout << "Second\n";
    ASSERT_FALSE(GetTree(tmp + "/TestFolder", true) == GetTree(tmp + "/TestFolder", false));
    boost::filesystem::remove_all(tmp + "/TestFolder");
}