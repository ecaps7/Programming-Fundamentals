/*输入
输入共12∗n+1行，第一行是球队数量(1<n<1000)
接下来是n个球队的信息，每个球队第一行是球队名，接下来11行是球员的名称以及进攻，防守，组织能力的评分值
保证球队名和姓名中只会出现英文字母，保证按现有排序规则结果唯一。

输出
输出共 3 行，分别表示所有球队按照平均进攻评分，平均防守评分和平均战术组织评分降序排序的结果，用球队名来标识整支球队*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
struct Team
{
    string country;
    double attack[12]{};
    double ave_att = 0;
    double defend[12]{};
    double ave_def = 0;
    double ability[12]{};
    double ave_abi = 0;
};

void print_ans(vector<Team> a, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << a[i].country << " ";
    }
    cout << endl;
}

bool compare_att(const Team& a, const Team& b)
{
    return a.ave_att > b.ave_att;
}

bool compare_def(const Team& a, const Team& b)
{
    return a.ave_def > b.ave_def;
}

bool compare_abi(const Team& a, const Team& b)
{
    return a.ave_abi > b.ave_abi;
}

int main()
{
    int n;
    cin >> n;
    vector<Team> countries(n);
    for (int i = 0; i < n; i++)
    {
        cin >> countries[i].country;
        for (int j = 0; j < 11; j++)
        {
            string name;
            cin >> name;
            cin >> countries[i].attack[j];
            countries[i].ave_att += countries[i].attack[j] / 12;
            cin >> countries[i].defend[j];
            countries[i].ave_def += countries[i].defend[j] / 12;
            cin >> countries[i].ability[j];
            countries[i].ave_abi += countries[i].ability[j] / 12;
        }
    }
    sort(countries.begin(), countries.end(), compare_att);
    print_ans(countries, n);
    sort(countries.begin(), countries.end(), compare_def);
    print_ans(countries, n);
    sort(countries.begin(), countries.end(), compare_abi);
    print_ans(countries, n);
    return 0;
}

// int main()
// {
//     int n;
//     cin >> n;
//     vector<string> countries(n);
//     using ArrOf12Int = int[12];
//     ArrOf12Int* attack = new ArrOf12Int[n];
//     ArrOf12Int* defend = new ArrOf12Int[n];
//     ArrOf12Int* ability = new ArrOf12Int[n];
//     for (int i = 0; i < n; i++)
//     {
//         string country;
//         cin >> country;
//         countries.push_back(country);
//         for (int j = 0; j < 12; j++)
//         {
//             cin >> attack[i][j];
//             cin >> defend[i][j];
//             cin >> ability[i][j];
//         }
//     }
//     double* ave_att = new double[n]{};
//     double* ave_def = new double[n]{};
//     double* ave_abi = new double[n]{};
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = 0; j < 12; j++)
//         {
//             ave_att[i] += (double)attack[i][j] / 12.0;
//             ave_def[i] += (double)defend[i][j] / 12.0;
//             ave_def[i] += (double)ability[i][j] / 12.0;
//         }
//     }

// }