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
    int getImportance(vector<Employee*> employees, int id) {
        unordered_map<int, Employee*> id2employee;
        for(const auto & employee: employees){
            id2employee.emplace( employee->id, employee );
        }
        int tot_import = 0;
        stack<Employee*> stk; stk.emplace( id2employee[id] );
        while( !stk.empty() ){
            auto top = stk.top(); stk.pop();
            tot_import += top->importance;
            for(const auto & sub: top->subordinates){
                stk.emplace( id2employee[sub] );
            }
        }
        return tot_import;
    }
};
