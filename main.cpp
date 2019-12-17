/*
Student Name:
Student Number:
Project Number: 5
Compile Status: [SUCCESS/FAIL]
Running Status: [SUCCESS/FAIL]
Notes: Anything you want to say about your code that will be helpful in the grading process.
*/

#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char* argv[]){
    int N;
    int K;
    cin >>N;
    cin >>K;
    vector<int> vec;
    long long int in;
    for(int i=0;i<N;i++) {
        cin >>in;
        vec.push_back(in);
    }
    sort(vec.begin(),vec.end());

    int total=1;

    vector<pair<int,int>> store;
    while(total<=N) {
        long long int result=0;
        if (total <= K) {
            for (int i = 0; i < total; i++) {
                result += vec[i];
            }
            cout << result << endl;
            pair<int,int> temp=make_pair(result,result);
            store.push_back(temp);
            total++;
            continue;
        }
        else {
            for(int i=1;i<=K;i++) {
                result+=vec[total-i];
            }
            int place=(total%K-1+K)%K;
            long long int toAdd=store[place].second;
            long long int prev=store[place].first;
            store[place].first=prev+toAdd+result;
            store[place].second=result+toAdd;
            cout << store[place].first <<endl;
            total++;
            continue;

        }


    }
    return 0;
}








