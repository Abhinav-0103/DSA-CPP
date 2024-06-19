#include<iostream>
#include<cstring>
using namespace std;

string removeDup(string str, string ans, bool map[]) {
    if(str.length() == 0) {
        return ans;
    }

    if(!map[str[0] - 'a']) {
        map[str[0] - 'a'] = true;
        return removeDup(str.substr(1), ans + str[0], map);
    }

    return removeDup(str.substr(1),ans,map);
}

int main() {
    string str = "appnnacollege";
    string ans = "";
    bool map[26] = {false};
    int i = 0;
    
    cout << str << " --> " << removeDup(str, ans, map) << endl;

    return 0;
}