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
#include <algorithm>
using namespace std;

int main(int argc, char* argv[]){
    freopen("input3.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int N,K;
    cin >>N;
    cin >>K;
    vector<int> vec;
    long long int in;
    for(int i=0;i<N;i++) {
        cin >>in;
        vec.push_back(in);
    }
    sort(vec.begin(),vec.end());
    int total=2-1;
    vector<pair<long long int,long long int>> store;
    pair<long long int,long long int> pairTmp=make_pair(0,0);
    for(int i=0;i<K;i++) {
        store.push_back(pairTmp);
    }
    long long int result=0;
    while(total<=N) {
        if(total>K)
            result-=vec[total-K-1];

        result+=vec[total-1];


        int place=(total%K-1+K)%K;
        long long int toAdd=store[place].second;
        long long int prev=store[place].first;
        store[place].first=prev+toAdd+result;
        store[place].second=result+toAdd;
        cout << store[place].first << " ";
        total++;

    }
    return 0;
}








