// Copyright 2018 Your Name <your_email>

#include <gtest/gtest.h>
#include "header.hpp"

TEST(Example, EmptyTest) {
    std::string ftp_path = "../";
    filer(ftp_path);
    EXPECT_EQ(Brokers.size(), 3);

    Brokers.clear();
    ftp_path = "../results/";
    filer(ftp_path);
    EXPECT_EQ(Brokers.size(), 0);

    int x = 0;
    std::for_each(Brokers.begin(), Brokers.end(), [&x](auto i) {
        std::string name = i.first;
        if (x == 0) {
            EXPECT_EQ(name, "bsc");
        }
        if (x == 1) {
            EXPECT_EQ(name, "ib");
        }
        if (x == 2) {
            EXPECT_EQ(name, "otkritie");
        }
        x++;
    });
}

