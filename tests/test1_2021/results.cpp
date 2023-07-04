#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

double calculatePoints( const pair<double,double>& v){
    double points=0;
    double participants=v.first;
    double difTeamParticipants=v.second;
    points=(participants*participants)/difTeamParticipants;
    return points;
}
bool sortDescending(const pair<pair<double,double>,int>& a, const pair<pair<double,double>,int>& b){
    double p1=a.first.first;
    double p2=b.first.first;
    double br1=a.first.second;
    double br2=b.first.second;
    if(p1==p2){
        return br1>br2;
            
    }
    return p1>p2;
}
int main() {
    int N;
    cin>> N;
    vector<pair<pair<double,double>,int>> result;
    vector<pair<double,double>> v;
    
    for(int i=0;i<N;i++){
        int num1,num2;
        cin>>num1>>num2;
        v.push_back({num1,num2});
    }
    for(int i=0;i<N;i++){
        double points=calculatePoints(v[i]);
        double participants=v[i].first;
        result.push_back({{points,participants},i+1});
    }
    stable_sort(result.begin(),result.end(), sortDescending);
    for(int i=0;i<N;i++){
        cout<<result[i].second<<" ";
    }
    return 0;
}
