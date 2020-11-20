/*
Auther : Jirayuwat Boonchan
IG : _p_pp_pp
PB : Jirayuwat Boonchan
Email : Jirayuwat12@gmail.com
*/
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <limits.h>
#include <queue>
#include <utility>
using namespace std;
#define FOR(i,s,n) for(int i =s;i<n;i++)
#define FORR(i,s,n) for(int i =s;i>=n;i--)
typedef long long ll;

struct Node {
    int std;
    struct Node * next;
};

int main( ){
    int nc,ns;
    cin>>nc>>ns;
    map<int,int> stdinfo;
    stdinfo[-1] = 0;
    int c,s;
    while(ns--) {
        cin>>c>>s;
        stdinfo[s] = c;
    }

    struct Node * head = new struct Node;
    head->next = NULL;
    head->std = -1;

    vector<int> ans;
    while(1){
        char inp;
        cin>>inp;
        if(inp == 'E'){
            int std;
            cin>>std;
            struct Node * temp = head;
            bool added = false;
            if(temp->next == NULL){
                struct Node * t = new struct Node;
                t->std = std;
                t->next = NULL;
                temp->next = t;
                added = true;
            }else {
                while(temp->next != NULL){
                if(stdinfo[temp->std]== stdinfo[std] && stdinfo[temp->next->std] != stdinfo[std]){
                    struct Node * t = new struct Node;
                    t->std = std;
                    t->next = temp->next;
                    temp->next = t;
                    added = true;
                    break;
                }
                temp = temp->next;
                }
            }
            if(!added){
                while(temp->next != NULL) temp = temp->next;
                temp->next = new struct Node;
                temp->next->next = NULL;
                temp->next->std = std;
            }
        }else if(inp == 'D'){
            ans.push_back(head->next->std);
            head->next = head->next->next;
        }else {
            for(int i : ans) cout<<i<<'\n';
            cout<<0;
            break;
        }
    }

    return 0;
}
/*

*/