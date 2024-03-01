#include "../foundationallib.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// The function to be tested
char *format_string(const char *format, ...);

// Test for basic functionality
void test_basic_formatting()
{
    char *result = format_string("{}", "test");
    assert(strcmp(result, "test") == 0);
    free(result);
}

// Test for multiple curly braces
void test_multiple_curly_braces()
{
    char *result = format_string("{0} {} {1}", "test1", "test2");
    assert(strcmp(result, "test1 test2") == 0);
    free(result);
}

// Test for empty format string
void test_empty_format_string()
{
    char *result = format_string("", "test");
    assert(strcmp(result, "") == 0);
    free(result);
}

// Test for invalid format string
void test_invalid_format_string()
{
    char *result = format_string("{1} {", "test");
    assert(result == NULL);
}

// Test for large number of arguments
void test_large_number_of_arguments()
{
    char *result = format_string("{0} {1} {2} {3} {4} {5} {6} {7} {8} {9} {10} {11} {12} {13} {14} {15} {16} {17} {18} {19} {20} {21} {22} {23} {24} {25} {26} {27} {28} {29} {30} {31} {32} {33} {34} {35} {36} {37} {38} {39} {40} {41} {42} {43} {44} {45} {46} {47} {48} {49} {50} {51} {52} {53} {54} {55} {56} {57} {58} {59} {60} {61} {62} {63} {64} {65} {66} {67} {68} {69} {70} {71} {72} {73} {74} {75} {76} {77} {78} {79} {80} {81} {82} {83} {84} {85} {86} {87} {88} {89} {90} {91} {92} {93} {94} "
                                 "{95} {96} {97} {98} {99} {100} {101} {102} {103} {104} {105} {106} {107} {108} {109} {110} {111} {112} {113} {114} {115} {116} {117} {118} {119} {120} {121} {122} {123} {124} {125} {126} {127} {128} {129} {130} {131} {132} {133} {134} {135} {136} {137} {138} {139} {140} {141} {142} {143} {144} {145} {146} {147} {148} {149} {150} {151} {152} {153} {154} {155} {156} {157} {158} {159} {160} {161} {162} {163} {164} {165} {166} {167} {168} {169} {170} {171} {172} "
                                 "{173} {174} {175} {176} {177} {178} {179} {180} {181} {182} {183} {184} {185} {186} {187} {188} {189} {190} {191} {192} {193} {194} {195} {196} {197} {198} {199} {200}",
                                 "test0", "test1", "test2", "test3", "test4", "test5", "test6", "test7", "test8", "test9", "test10", "test11", "test12", "test13", "test14", "test15", "test16", "test17", "test18", "test19", "test20", "test21", "test22", "test23", "test24", "test25", "test26", "test27", "test28", "test29", "test30", "test31", "test32", "test33", "test34", "test35", "test36", "test37", "test38", "test39", "test40", "test41", "test42", "test43", "test44", "test45", "test46",
                                 "test47", "test48", "test49", "test50", "test51", "test52", "test53", "test54", "test55", "test56", "test57", "test58", "test59", "test60", "test61", "test62", "test63", "test64", "test65", "test66", "test67", "test68", "test69", "test70", "test71", "test72", "test73", "test74", "test75", "test76", "test77", "test78", "test79", "test80", "test81", "test82", "test83", "test84", "test85", "test86", "test87", "test88", "test89", "test90", "test91", "test92",
                                 "test93", "test94", "test95", "test96", "test97", "test98", "test99", "test100", "test101", "test102", "test103", "test104", "test105", "test106", "test107", "test108", "test109", "test110", "test111", "test112", "test113", "test114", "test115", "test116", "test117", "test118", "test119", "test120", "test121", "test122", "test123", "test124", "test125", "test126", "test127", "test128", "test129", "test130", "test131", "test132", "test133", "test134", "test135",
                                 "test136", "test137", "test138", "test139", "test140", "test141", "test142", "test143", "test144", "test145", "test146", "test147", "test148", "test149", "test150", "test151", "test152", "test153", "test154", "test155", "test156", "test157", "test158", "test159", "test160", "test161", "test162", "test163", "test164", "test165", "test166", "test167", "test168", "test169", "test170", "test171", "test172", "test173", "test174", "test175", "test176", "test177",
                                 "test178", "test179", "test180", "test181", "test182", "test183", "test184", "test185", "test186", "test187", "test188", "test189", "test190", "test191", "test192", "test193", "test194", "test195", "test196", "test197", "test198", "test199", "test200");
    assert(strcmp(result, "test0 test1 test2 test3 test4 test5 test6 test7 test8 test9 test10 test11 test12 test13 test14 test15 test16 test17 test18 test19 test20 test21 test22 test23 test24 test25 test26 test27 test28 test29 test30 test31 test32 test33 test34 test35 test36 test37 test38 test39 test40 test41 test42 test43 test44 test45 test46 test47 test48 test49 test50 test51 test52 test53 test54 test55 test56 test57 test58 test59 test60 test61 test62 test63 test64 test65 test66 test67 "
                          "test68 test69 test70 test71 test72 test73 test74 test75 test76 test77 test78 test79 test80 test81 test82 test83 test84 test85 test86 test87 test88 test89 test90 test91 test92 test93 test94 test95 test96 test97 test98 test99 test100 test101 test102 test103 test104 test105 test106 test107 test108 test109 test110 test111 test112 test113 test114 test115 test116 test117 test118 test119 test120 test121 test122 test123 test124 test125 test126 test127 test128 test129 test130 "
                          "test131 test132 test133 test134 test135 test136 test137 test138 test139 test140 test141 test142 test143 test144 test145 test146 test147 test148 test149 test150 test151 test152 test153 test154 test155 test156 test157 test158 test159 test160 test161 test162 test163 test164 test165 test166 test167 test168 test169 test170 test171 test172 test173 test174 test175 test176 test177 test178 test179 test180 test181 test182 test183 test184 test185 test186 test187 test188 test189 "
                          "test190 test191 test192 test193 test194 test195 test196 test197 test198 test199 test200") == 0);
    free(result);
}

int main()
{
    test_basic_formatting();
    test_multiple_curly_braces();
    test_empty_format_string();
    test_invalid_format_string();
    test_large_number_of_arguments();
    printf("All tests passed!\n");
    return 0;
}
