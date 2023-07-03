#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct Ticket{
    int number;
    int id;
    
    bool operator<(const Ticket& other) {
        if (number != other.number) {
            return number < other.number;
        }
        return id < other.id;
    }
};
int main() {
    long N;
    cin>>N;
    Ticket tickets[N];
    Ticket sortedTickets[N];
    
    
    for(int i=0;i<N;i++){
       
        cin>>tickets[i].number;
        tickets[i].id=i;
      
    }
    //stable_sort(tickets,tickets+N);  
    sort(tickets,tickets+N);
    vector<long> result;
    for(int i=0;i<N;i++){
       sortedTickets[tickets[i].id].id=i;
    }
    for(int i=0;i<N;i++){
        cout<<sortedTickets[i].id<<" ";
    }
    return 0;
}