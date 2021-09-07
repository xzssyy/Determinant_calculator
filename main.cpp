#include <iostream>
#include <vector>

using namespace std;


void range(int n, vector<int>& temp, vector<vector<int>>& all_arranged, int inp, vector<int>& judge)//����ȫ�����Լ������
{
    if(temp.size() == n)
    {
        temp.emplace_back(inp);
        all_arranged.emplace_back(temp);
        temp.erase(temp.end()-1);

        return;
    }

    for(int i = 1; i <= n; i++)
    {
        if(judge[i] == 1) continue;

        int k = 0;
        if(!temp.empty())
            for(auto j : temp)
                if(j > i)
                    k++;

        temp.emplace_back(i);
        judge[i] = 1;

        range(n, temp, all_arranged, k + inp, judge);

        temp.erase(temp.end()-1);
        judge[i] = 0;
    }
}

void initial(int n,vector<vector<int>>& all_ranged)
{
    vector<int> temp, judge(n + 1,0);

    range(n, temp, all_ranged,0, judge);
}



int main()
{
    int n;
    vector<vector<int>> all_ranged;//0~n-1 ȫ���У� n ������


    cout<<"���������"<<endl;
    cin>>n;

    vector<vector<int>> data(n, vector<int>(n));

    cout<<"��ʼ��ing"<<endl;
    initial(n,all_ranged);
    cout<<"��ʼ����ɣ�����������ʽ�� "<<endl;

    for(int i = 0 ; i < n; i++)
        for(int j = 0; j < n; j++)
         cin>>data[i][j];

        int result = 0;

        for(auto i : all_ranged)
        {
            int t = 1;

            for(int j = 0; j < n; j++)
            {
                t*=data[j][i[j]-1];
            }

            if(i[n] % 2 == 1)
                t=-t;

            result+=t;
        }


        cout<<"���ǣ� "<<result<<endl;
        system("pause");


        return 0;


}
