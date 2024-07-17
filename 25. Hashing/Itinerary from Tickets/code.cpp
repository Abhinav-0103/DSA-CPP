#include<iostream>
#include<unordered_map>
#include<unordered_set>
#include<vector>
using namespace std;

void itinerary(unordered_map<string,string> tickets) {
    unordered_set<string> s;
    string start = "";

    for(pair<string,string> p: tickets) {
        s.insert(p.second);
    }

    for(pair<string,string> p: tickets) {
        if(s.find(p.first) == s.end()) {
            start = p.first;
            break;
        }
    }

    while(tickets.count(start) != 0) {
        cout << start << " -> ";
        start = tickets[start];
    }

    cout << start << endl;
}

int main() {
    unordered_map<string, string> tickets;
    tickets["Chennai"] = "Bengaluru";
    tickets["Mumbai"] = "Delhi";
    tickets["Goa"] = "Chennai";
    tickets["Delhi"] = "Goa";

    itinerary(tickets);
}