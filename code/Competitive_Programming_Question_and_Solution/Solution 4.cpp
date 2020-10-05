
#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long int t;
    cin >> t;
    for(long long int i = 0; i < t; i++){
        long long int n;
        cin >> n;
        vector<long long int> input;
        for(long long int j = 0; j < n; j++){
            long long int k;
            cin >>k;
            input.push_back(k);
        }
        int flag = 0;
        for(long long int j = 0; j < n; j++){
            if(((j+1) % input[j] ) == 0){
                continue;
            }else{
                flag = 1;
                cout << "NO" << endl;
                break;
            }
        }
        if(flag != 1){
            cout << "YES" << endl;
        }
    }

    return 0;
}