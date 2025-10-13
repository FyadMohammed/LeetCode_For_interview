#include <bits/stdc++.h>

using namespace std;
int solution(int a, int b, int x, int y){
    if(a < b && x <= y){
        return (b-a)*x;
    }
    else if(a > b && a % 2 != 0 && a == b + 1){
        return x;
    }
    else if( a == b){
        return x * 2;
    }
    else{
        return -1;
    }
}
int main()
{
    int test_case;
    cin >> test_case;
    int test_a, test_b,test_x,test_y;
    for(int i = 0;i < test_case;i++){
        cin >> test_a >> test_b >> test_x >> test_y;
        cout << solution(test_a,test_b,test_x,test_y) << endl;
    }
}
