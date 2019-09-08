#include <iostream>
using namespace std;
int main(void)
{
    int n; cin >> n; auto arr = new int[n]();
    int total = 0;
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i]; total += arr[i];
    }
    total /= n;
    
    int ret = 0;
    
    for(int i = 0; i < n; i++)
        if(arr[i] > total)
            ret += arr[i] - total;
    cout << ret;
}
