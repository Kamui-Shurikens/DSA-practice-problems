#include <iostream>
using namespace std;

long long maxSubarraySum(int arr[], int n){
    if(n == 1)
        return arr[0];
    int result{arr[0]};
    int sum{};
    int i{};
    while( i < n )
    {
        sum += arr[i];
        if(sum < 0)
        {
            i++;
            result = max(result,sum);
            sum  = 0;
        }
        else
        {
            result = max(result,sum);
            i++;
        }
    }

    return result;
}

int main()
{
    cout << "hello world" << endl;
    return 0;
}