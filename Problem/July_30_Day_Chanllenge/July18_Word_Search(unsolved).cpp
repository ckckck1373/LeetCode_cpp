/*
    Date: 2020/7/20
    Owner: Chun-Yeh, Lin
    Note: case 41/44 passed
    
*/

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        bool* first_point = new bool [numCourses];
        bool* end_point = new bool [numCourses];
        bool* in_ans = new bool [numCourses];
        int * priority_list = new int [numCourses];
        bool flag = false;
        bool insert_flag=false;
        
        int n = prerequisites.size();
        vector<int>ans;
        vector<vector<int>>course_vec(numCourses+1);
        
        
        // initialize (**)
        for(int i=0;i<numCourses;i++){
            first_point[i] = true;
            end_point[i] = true;
            in_ans[i] = false;
            priority_list[i] = 0;
        }
        
    
        // find first & end node
        for(int i=0;i<n;i++){
            // start point condtition (no inward pointer)
            if(first_point[prerequisites[i][0]]==true){
                // not found
                first_point[prerequisites[i][0]]=false;
            }
            
            // end point condition (no outward pointer)
            if(end_point[prerequisites[i][1]]==true){
                // not found
                end_point[prerequisites[i][1]]=false;
            }
            
            //
            priority_list[prerequisites[i][1]]++;
            //
        }
        
        
        for(int i=0;i<n;i++){
            for(int j=0;j<course_vec[prerequisites[i][1]].size();j++){
                if(priority_list[course_vec[prerequisites[i][1]][j]] >= priority_list[prerequisites[i][0]]){
                    course_vec[prerequisites[i][1]].insert(course_vec[prerequisites[i][1]].begin()+j, prerequisites[i][0]); 
                    insert_flag = true;
                    break;
                }
                  
            }
            if(insert_flag==false){
                 course_vec[prerequisites[i][1]].push_back(prerequisites[i][0]);
            }
            insert_flag=true;
            
        }
        
        
        // first point condition
        for(int i=0;i<numCourses;i++){
            if(first_point[i]==true){
                //cout << i << endl;
                course_vec[numCourses].push_back(i);
            }
            
        }
        
        // reuse first_point vector
        first_point = new bool [numCourses];
        
        // initialize (**)
        for(int i=0;i<numCourses;i++){
            first_point[i] = false;
        }
        
        queue<int> q;
        
        
        // deal with first point first
        for(int i=0;i<course_vec[numCourses].size();i++){
            if(first_point[course_vec[numCourses][i]]==false){
                // not found
                q.push(course_vec[numCourses][i]);
                first_point[course_vec[numCourses][i]]=true;
            }
            // else do nothing
        }
        
        // BFS strategy
        while(!q.empty()){
            if(in_ans[q.front()]==true){
                flag=true;
                break;
            }else{
                ans.push_back(q.front());
                in_ans[q.front()]=true;
            }
            
            
            
            for(int i=0;i<course_vec[q.front()].size();i++){
                if(in_ans[course_vec[q.front()][i]]==true){
                    flag = true;
                    break;
                }
                
                if(first_point[course_vec[q.front()][i]]==false){
                    
                    // not found
                    if(end_point[course_vec[q.front()][i]]==false){
                        
                        q.push(course_vec[q.front()][i]);
                        first_point[course_vec[q.front()][i]]=true;
                       
                    }
                }

            }
            q.pop();
        }
        
        for(int i=0;i<numCourses;i++){
            if(end_point[i]==true && first_point[i]==false){
                ans.push_back(i);
            }
        }
        
//         cout << "ans: "; 
        
//         for(int i=0;i<ans.size();i++){
//             cout << ans[i] << " " ;
//         } 
//         cout << "flag = " << flag << endl;
        
        if(flag==true || ans.size()!=numCourses) ans.clear();
        return ans;
    }
};