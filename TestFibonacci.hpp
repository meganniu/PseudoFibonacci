class TestFibonacci : public CppUnit::TestFixture{
    CPPUNIT_TEST_SUITE(TestFibonacci);
    CPPUNIT_TEST(testPositives);
    CPPUNIT_TEST(testNegatives);
    CPPUNIT_TEST(testMixed);
    CPPUNIT_TEST(testZeroes);
    CPPUNIT_TEST(testLength);
    CPPUNIT_TEST(testIntegers);
    CPPUNIT_TEST(testDisplay);
    CPPUNIT_TEST_SUITE_END();
    
    public:
        static bool equal(std::vector<double> v1, std::vector<double> v2);
    
    protected:
        void testPositives(void);
        void testNegatives(void);
        void testMixed(void);
        void testZeroes(void);
        void testLength(void);
        void testIntegers(void);
        void testDisplay(void);
};
