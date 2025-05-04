#include <bits/stdc++.h>

using namespace std;

int main()
{
    string str1 = "anagram", str2 = "nagaram";

    vector<int> vec1(26);
    //vector<int>vec2(26);

    bool flag = 0;
    /*
    for(int i = 0;i < str1.size();i++){
        vec1[str1[i]-97]++;
    }
    for(int i = 0;i < str2.size();i++){
        vec2[str2[i]-97]++;
    }

    for(int i = 0;i < 26;i++){
        if(vec1[i] == vec2[i]){
            flag = 1;
        }
        else
            flag = 0;
    }
    */

    for(int i = 0;i < str1.size();i++){
        vec1[str1[i]-97]++;
    }
    for(int i = 0;i < str2.size();i++){
        vec1[str2[i]-97]--;
    }
    for(int i = 0;i < vec1.size();i++){
        if(vec1[i] != 0){
            flag = 0;
            break;
        }
        else
            flag = 1;
    }

    if (flag)
        cout << "True" << endl;
    else
        cout << "False" << endl;
}
