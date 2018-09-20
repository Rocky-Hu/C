//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//
//void unitTest();
//
//int main()
//{
//    unitTest();
//    return 0;
//}
//
//void unitTest()
//{
//    union Data
//    {
//        int i;
//        float f;
//        char str[20];
//    };
//
//    union Data data;
//    data.i = 10;
//    printf("data.i=%d\n", data.i);
//
//    data.f = 226.6;
//    printf("data.f=%f\n", data.f);
//
//    strcpy(data.str, "tanksu");
//    printf("data.str=%s\n", data.str);
//
//    //如果直接全部赋值，那么里面的值就有损坏
//    //如下代码
//    /**
//     * data.i = 10;
//     *  data.f = 220.5;
//     * strcpy( data.str, "C Programming");
//     *
//     * 输出：
//     * data.i : 1917853763
//     * data.f : 4122360580327794860452759994368.000000
//     * data.str : C Programming
//     */
//}
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
