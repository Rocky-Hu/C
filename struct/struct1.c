#include <stdio.h>
#include <string.h>

struct Hero 
{
    int id;
    char name[50];// 英雄的名称
    int level;// 英雄的等级
    int hp;// 英雄的血量
    int mp;// 英雄的魔法值
    char skill[50];// 英雄的技能
};

int main()
{
    // 使用结构体
    struct Hero hero1 = {2, "嫌利息", 10, 1000,  200, "分组"};
    // hero1.id = 1;
    // strcpy(hero1.name, "德玛西亚之力");
    // hero1.level = 5;
    // hero1.hp = 500;
    // hero1.mp = 100;
    // strcpy(hero1.skill, "大保健");
    printf("%d\t%s\t%d\t%d\t%d\t%s\n", hero1.id, hero1.name, hero1.level, hero1.hp, hero1.mp, hero1.skill);
    return 0;
}