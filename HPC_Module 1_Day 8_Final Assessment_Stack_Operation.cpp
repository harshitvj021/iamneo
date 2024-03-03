#include <iostream>
#include <string>

using namespace std;

int main() {
    int count =0, o_count=0, e_count=0, length=0;
    string inp;
    
    getline(cin,inp);
    
    if(inp[0] == '}') {
        count +=2;
    }
    
    length = inp.length();
    for (int i=0;i<length;i++) {
        if(inp[i] == '{') {
            o_count++;
        } else {
            e_count++;
        }
    }
    
    if((o_count - e_count) > -1) {
        count+=(o_count-e_count)/2;
    } else {
        count += (e_count - o_count) /2;
    }
    
    if(length % 2==0) {
        cout << count <<endl;
    } else {
        cout << -1 << endl;
    }
    
    return 0;
}