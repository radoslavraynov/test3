//
// Created by Radoslav Zlatev on 5/24/20.
//

#include <gmp.h>
#include <gtest/gtest.h>
#include <unordered_map>

TEST(Cxx17, Basic)
{
    std::unordered_map<int,int> mp;
    for(int i=0;i<10;++i)
        mp[i] = i*i;
    for(const auto& [k, v]: mp)
        EXPECT_EQ(k*k, v);
}

TEST(GmpTest, Basic)
{
    mpz_t a, b;
    mpz_init(a);
    mpz_init_set_str(a, "12345678901234567890", 10);
    mpz_init(b);
    mpz_pow_ui(b,a,10);
    gmp_fprintf(stderr, "and this is an gmp int %Zd\n", b);

    const char* b_str = mpz_get_str(nullptr, 10, b);
    EXPECT_STREQ("82252625996962883902200053988119600331774131569207631446528559806647083663566037435187912750978162286251755705030444941948763304746218157802392139307392345500269796500763077997366010000000000", b_str);
    EXPECT_EQ(191, strlen(b_str));
}