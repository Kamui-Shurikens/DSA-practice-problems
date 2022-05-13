#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

vector<int> maximizeArray(int arr1[], int arr2[], int n) {

    vector <int> PQ1, PQ2;
    vector <bool> valid1,valid2;
    unordered_map <int,int> indx1,indx2;

    for(int i{n-1} ; i >= 0 ; i--)
    {
        indx1[arr1[i]] = i;
        indx2[arr2[i]] = i;
        PQ1.push_back(arr1[i]);
        valid1.push_back(false);
        valid2.push_back(false);
        PQ2.push_back(arr2[i]);
    }

    sort(PQ1.begin(),PQ1.end(),greater<int>());
    sort(PQ2.begin(),PQ2.end(),greater<int>());
    PQ1.push_back(INT_MIN);
    PQ2.push_back(INT_MIN);
    PQ1.push_back(INT_MIN);
    PQ2.push_back(INT_MIN);

    int p1{},p2{};

    for(int i{} ; i < n ; i++)
    {
        if(PQ1[p1] != PQ2[p2])
        {
            if(PQ1[p1] > PQ2[p2])
            {
                int index = indx1[PQ1[p1]];
                valid1[index] = true;
                int temp = PQ1[p1];
                while(PQ1[p1] == temp)
                    p1++;
            }
            else
            {
                int index = indx2[PQ2[p2]];
                valid2[index] = true;
                int temp = PQ2[p2];
                while(PQ2[p2] == temp)
                    p2++;
            }
        }
        else
        {
            int index = indx2[PQ2[p2]];
            valid2[index] = true;
            int temp = PQ2[p2];

            while(PQ1[p1] == temp)
                p1++;
            while(PQ2[p2] == temp)
                p2++;
        }
    }

    vector <int> result;

    for(int i{} ; i < n ; i++)
    {
        if(valid2[i])
            result.push_back(arr2[i]);
    }
    for(int i{} ; i < n ; i++)
    {
        if(valid1[i])
            result.push_back(arr1[i]);
    }

    return result;
}

int main()
{
    cout << "hello world" << endl;
    return 0;
}