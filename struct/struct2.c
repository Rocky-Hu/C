#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Hero 
{
    int id;
    char * name;// 英雄的名称
    int level;// 英雄的等级
    int hp;// 英雄的血量
    int mp;// 英雄的魔法值
    char skill[50];// 英雄的技能
};

int main()
{
    // 使用结构体
    struct Hero hero1 = {2, "嫌利息", 10, 1000,  200, "分组"};
    printf("请输入英雄的名称：");
    hero1.name = (char*) malloc(50);
    scanf("%s", hero1.name);
    printf("%d\t%s\t%d\t%d\t%d\t%s\n", hero1.id, hero1.name, hero1.level, hero1.hp, hero1.mp, hero1.skill);
    return 0;
}