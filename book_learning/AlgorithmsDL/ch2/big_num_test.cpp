#include <gtest/gtest.h>
#include "big_num_add.cpp"

string big_num_add(string num1, string num2);
// 测试用例  

GTEST_API_ int main(int argc, char **argv) {
    std::cout << "Running main() from gtest_main.cc\n";
    
    testing::InitGoogleTest(&argc, argv);//解析命令行中的GoogleTest参数，它允许用户通过多样的命令行参数来控制测试程序的行为（即定制命令行参数的行为）
    return RUN_ALL_TESTS();//将会搜索不同的Test Case和不同的源文件中所有已经存在测试案例，然后运行它们，所有Test都成功时返回1，否则返回0。
}

TEST(BigNumAddTest, SimpleAddition) {  
    EXPECT_EQ(big_num_add("123", "456"), "579");  
    EXPECT_EQ(big_num_add("0", "0"), "0");  
    EXPECT_EQ(big_num_add("123456789", "987654321"), "1111111110");  
}  

TEST(BigNumAddTest, AdditionWithCarry) {  
    EXPECT_EQ(big_num_add("999", "1"), "1000");  
    EXPECT_EQ(big_num_add("9999", "9999"), "19998");  
    EXPECT_EQ(big_num_add("123", "999"), "1122");  
}  

TEST(BigNumAddTest, LargeNumbers) {  
    EXPECT_EQ(big_num_add("12345678901234567890", "98765432109876543210"),   
                "111111111011111111100");  
    EXPECT_EQ(big_num_add("1000000000000", "9000000000000"), "10000000000000");  
}  

TEST(BigNumAddTest, EdgeCases) {  
    EXPECT_EQ(big_num_add("123456789", "0"), "123456789");  
    EXPECT_EQ(big_num_add("0", "987654321"), "987654321");  
    EXPECT_EQ(big_num_add("1", "9"), "10");  
}  

int main(int argc, char **argv) {  
    ::testing::InitGoogleTest(&argc, argv);  
    return RUN_ALL_TESTS();  
}