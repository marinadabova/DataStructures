#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
double calculatePoints(const pair<double,double>& a){
    double points=0;
    double br1=a.first;
    double br2=a.second;
    points=(br1*br1)/br2;
    return points;
}
bool sortDescending(const pair<pair<double,double>,int>&a,const pair<pair<double,double>,int>&b){
    double points1=a.first.first;
    double points2=b.first.first;
    double br11=a.first.second;
    double br12=b.first.second;
    if(points1==points2){
        return br11>br12;
    }
    return points1>points2;
}
int main() {
    int N;
    cin>>N;
    vector<pair<double,double>> vec;
    for(int i=0;i<N;i++){
        double br1,br2;
        cin>>br1>>br2;
        vec.push_back(make_pair(br1,br2));
    }
    vector<pair<pair<double,double>,int>> result;
    for(int i=0;i<N;i++){
        double points=calculatePoints(vec[i]);
        double br1=vec[i].first;
        result.push_back(make_pair(make_pair(points,br1),i+1));
    }
    stable_sort(result.begin(),result.end(),sortDescending);
    for(int i=0;i<N;i++){
        cout<<result[i].second<<" ";
    }
    return 0;
}
