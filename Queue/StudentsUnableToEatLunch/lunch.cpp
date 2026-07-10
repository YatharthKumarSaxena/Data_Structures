#include <vector>
#include <stack>
#include <queue>
using namespace std;

class Solution {
public:
    int countStudents(vector<int>& st, vector<int>& sa) {
        // Finding the number of students who like square and circular sandwich
        int noc = 0; // Circular Sandwich
        int nos = 0; // Square Sandwich
        queue<int>q;
        stack<int>s;
        for(int i=0;i<st.size();i++){
            if(st[i]==0)noc++;
            else nos++;
            //Making Queue of students and stacks of student 
            q.push(st[i]);
            s.push(sa[sa.size()-1-i]);
        }
        while(s.size()){
            if(q.front()==s.top()){
                if(s.top()==0)noc--;
                else nos--;
                q.pop();
                s.pop();
            }
            else{
                if(s.top()==0){
                    if(noc==0)break;
                    else{
                        int x = q.front();
                        q.pop();
                        q.push(x);
                    }
                }
                else{
                    if(nos==0)break;
                    else{
                        int x = q.front();
                        q.pop();
                        q.push(x);
                    }
                }
            }
        }
        return q.size();
    }
};