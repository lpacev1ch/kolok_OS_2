#include <gtest/gtest.h>
#include "Singleton.h"

TEST(SingletonTest, InstanceConsistency) {
    Singleton& instance1 = Singleton::getInstance();
    Singleton& instance2 = Singleton::getInstance();
    ASSERT_EQ(&instance1, &instance2);
}

TEST(SingletonTest, ThreadSafety) {
    Singleton* instance1 = nullptr;
    Singleton* instance2 = nullptr;

    std::thread t1([&instance1]() {
        instance1 = &Singleton::getInstance();
    });
    std::thread t2([&instance2]() {
        instance2 = &Singleton::getInstance();
    });

    t1.join();
    t2.join();

    ASSERT_EQ(instance1, instance2);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
