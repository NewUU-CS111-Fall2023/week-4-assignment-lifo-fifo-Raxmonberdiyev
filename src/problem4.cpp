#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<stack<int>> stacks(N+1);
    for(int i=0; i<N; i++) {
        int k;
        cin >> k;
        for(int j=0; j<k; j++) {
            int type;
            cin >> type;
            stacks[i].push(type);
        }
    }

    vector<pair<int, int>> actions;
    for(int round=1; round<=N; round++) {
        for(int i=0; i<N; i++) {
            while(!stacks[i].empty() && stacks[i].top() == round) {
                stacks[round-1].push(round);
                stacks[i].pop();
                actions.push_back({i+1, round});
            }
        }
        int pos = -1;
        for(int i=0; i<N; i++) {
            if(!stacks[i].empty() && stacks[i].top() == round) {
                pos = i;
                break;
            }
        }
        if(pos == -1) {
            cout << 0 << endl;
            return 0;
        }
        while(!stacks[pos].empty() && stacks[pos].top() == round) {
            stacks[round-1].push(round);
            stacks[pos].pop();
            actions.push_back({pos+1, round});
        }
        for(int i=0; i<N; i++) {
            while(!stacks[i].empty() && stacks[i].top() != round) {
                stacks[N].push(stacks[i].top());
                stacks[i].pop();
                actions.push_back({i+1, N+1});
            }
        }
    }
    for(auto action : actions) {
        cout << action.first << " " << action.second << endl;
    }
    return 0;
}
