#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> maximizeArray(int arr1[], int arr2[], int n) {

    priority_queue <int> PQ1, PQ2;

    for(int i{} ; i < n ; i++)
    {
        PQ1.push(arr1[i]);
        PQ2.push(arr2[i]);
    }

    vector <int> v1,v2;

    for(int i{} ; i < n ; i++)
    {
        if(PQ1.top() != PQ2.top())
        {
            if(PQ1.top() > PQ2.top())
            {
                v1.push_back(PQ1.top());
                int temp = PQ1.top();

                while(PQ1.top() == temp)
                    PQ1.pop();
            }
            else
            {
                v2.push_back(PQ2.top());
                int temp = PQ2.top();

                while(PQ2.top() == temp)
                    PQ2.pop();
            }
        }
        else
        {
            int temp = PQ1.top();

            v2.push_back(temp);
            while(PQ1.top() == temp)
                PQ1.pop();
            while(PQ2.top() == temp)
                PQ2.pop();

        }
    }

    for(int i{} ; i < (int)v1.size() ; i++)
    {
        v2.push_back(v1[i]);
    }

    return v1;
}

int main()
{
    cout << "hello world" << endl;
    return 0;
}