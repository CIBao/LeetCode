/*
// Employee info
class Employee {
public:
    // It's the unique ID of each node.
    // unique id of this employee
    int id;
    // the importance value of this employee
    int importance;
    // the id of direct subordinates
    vector<int> subordinates;
};
*/
class Solution {
public:
    int getImportance(vector<Employee*> es, int id) {    
        int res = 0;
        Employee* tmp=NULL;
        for(auto m: es)
            if(m->id == id){
                tmp = m; break;
            }
        if(tmp==NULL)return res;
        res += tmp->importance;
        for(auto i: tmp->subordinates){
            res += getImportance(es, i);
        }
        return res;
        
    }
};
