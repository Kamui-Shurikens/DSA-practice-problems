#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

vector<int> maximizeArray(int arr1[], int arr2[], int n) {

    priority_queue <int> PQ1, PQ2;
    vector <bool> valid1,valid2;
    unordered_map <int,int> indx1,indx2;

    for(int i{n-1} ; i >= 0 ; i--)
    {
        indx1[arr1[i]] = i;
        indx2[arr2[i]] = i;
        PQ1.push(arr1[i]);
        valid1.push_back(false);
        valid2.push_back(false);
        PQ2.push(arr2[i]);
    }

    for(int i{} ; i < n ; i++)
    {
        if(PQ1.top() != PQ2.top())
        {
            if(PQ1.top() > PQ2.top())
            {
                int index = indx1[PQ1.top()];
                valid1[index] = true;
                int temp = PQ1.top();

                while(PQ1.top() == temp)
                    PQ1.pop();
            }
            else
            {
                int index = indx2[PQ2.top()];
                valid2[index] = true;
                int temp = PQ2.top();

                while(PQ2.top() == temp)
                    PQ2.pop();
            }
        }
        else
        {
            int temp = PQ2.top();
            int index = indx2[PQ2.top()];
            valid2[index] = true;
            while(PQ1.top() == temp)
                PQ1.pop();
            while(PQ2.top() == temp)
                PQ2.pop();

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