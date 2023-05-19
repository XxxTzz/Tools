#include <stdio.h>
#define MAX_LEN 4000
#define GROUP_LEN 100
#define DIVISION_FLAG ' ' // 分隔符
#define divide_number 2   // 分组数
#define float_form 1      // 小数位数

int main()
{
    // TAG: float版
    // printf("How many groups:\n");
    // int divide_number;
    // scanf("%d", &divide_number);
    char data[MAX_LEN];
    printf("Input data (divide by '%c'):\n", DIVISION_FLAG);
    fgets(data, MAX_LEN, stdin);
    float group1[GROUP_LEN], group2[GROUP_LEN], group3[GROUP_LEN], group4[GROUP_LEN], group5[GROUP_LEN], group6[GROUP_LEN], group7[GROUP_LEN], group8[GROUP_LEN];
    unsigned char group1_num = 0, group2_num = 0, group3_num = 0, group4_num = 0, group5_num = 0, group6_num = 0, group7_num = 0, group8_num = 0;
    _Bool negative_flag = 0;
    _Bool float_flag = 0;
    unsigned char float_num = 0;     // 小数点后位数
    float num = 0;                   // 每个数据
    unsigned short int data_num = 0; // 数据总数
    printf("\n");
    // 将数据依次分组
    for (int i = 0; data[i] != '\0'; i++)
    {
        // 识别有效数据
        if ((data[i] >= '0' && data[i] <= '9') || data[i] == '-' || data[i] == '.')
        {
            if (data[i] == '-')
            {
                negative_flag = 1;
                continue;
            }
            if (data[i] == '.')
            {
                float_flag = 1;
                continue;
            }
            data[i] = data[i];
            num = num * 10 + data[i] - '0';
            if (float_flag)
            {
                float_num++;
            }
        }
        // 一个数据读取完毕,存入对应的分组
        if (i > 0 && (data[i + 1] == DIVISION_FLAG || data[i + 1] == '\0') && (data[i] >= '0' && data[i] <= '9'))
        // if (i > 0 && (data[i] == DIVISION_FLAG || data[i] == '\0') && (data[i - 1] >= '0' && data[i - 1] <= '9'))
        {
            if (negative_flag)
            {
                num = -num;
            }
            if (float_flag)
            {
                num /= (10 * float_num);
            }
            switch (data_num % divide_number)
            {
            case 0:
                group1[group1_num] = num;
                group1_num++;
                break;
            case 1:
                group2[group2_num] = num;
                group2_num++;
                break;
            case 2:
                group3[group3_num] = num;
                group3_num++;
                break;
            case 3:
                group4[group4_num] = num;
                group4_num++;
                break;
            case 4:
                group5[group5_num] = num;
                group5_num++;
                break;
            case 5:
                group6[group6_num] = num;
                group6_num++;
                break;
            case 6:
                group7[group7_num] = num;
                group7_num++;
                break;
            case 7:
                group8[group8_num] = num;
                group8_num++;
                break;
            default:
                break;
            }
            // 清零
            data_num++;
            negative_flag = 0;
            float_flag = 0;
            float_num = 0;
            num = 0;
        }
    }
    // 依次显示分组数据
    for (int i = 0; i < divide_number; i++)
    {
        printf("Group %d:\n", i + 1);
        switch (i)
        {
        case 0:
            for (int j = 0; j < group1_num; j++)
            {
                printf("%.*f", float_form, group1[j]);
                printf("%c ", DIVISION_FLAG);
            }
            break;
        case 1:
            for (int j = 0; j < group2_num; j++)
            {
                printf("%.*f", float_form, group2[j]);
                printf("%c ", DIVISION_FLAG);
            }
            break;
        case 2:
            for (int j = 0; j < group3_num; j++)
            {
                printf("%.*f", float_form, group3[j]);
                printf("%c ", DIVISION_FLAG);
            }
            break;
        case 3:
            for (int j = 0; j < group4_num; j++)
            {
                printf("%.*f", float_form, group4[j]);
                printf("%c ", DIVISION_FLAG);
            }
            break;
        case 4:
            for (int j = 0; j < group5_num; j++)
            {
                printf("%.*f", float_form, group5[j]);
                printf("%c ", DIVISION_FLAG);
            }
            break;
        case 5:
            for (int j = 0; j < group6_num; j++)
            {
                printf("%.*f", float_form, group6[j]);
                printf("%c ", DIVISION_FLAG);
            }
            break;
        case 6:
            for (int j = 0; j < group7_num; j++)
            {
                printf("%.*f", float_form, group7[j]);
                printf("%c ", DIVISION_FLAG);
            }
            break;
        case 7:
            for (int j = 0; j < group8_num; j++)
            {
                printf("%.*f", float_form, group8[j]);
                printf("%c ", DIVISION_FLAG);
            }
            break;
        default:
            break;
        }
        printf("\n\n");
    }

    return 0;
}