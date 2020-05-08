/*
    Date: 2020/5/8
    Owner: Chun-Yeh, Lin
    
*/

// version 2 
// y=ax+b solution

class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        // y=ax+b
        int num_dot=coordinates.size();
        if(num_dot==2)return true;
   
        double a = ((double)(coordinates[1][1]-coordinates[0][1])/(coordinates[1][0]-coordinates[0][0]));
        double b = ((double)(coordinates[0][1]-a*coordinates[0][0]));
        
        for(int i=2;i<num_dot;i++){
            if(coordinates[i][1]!=coordinates[i][0]*a+b){
                return false;;
            }
        }
        return true;
        
    }
};


// version 1

class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        int dot_num = coordinates.size();
        if(dot_num==2)return true;
        float slope=0;
        if(coordinates[1][0]!=coordinates[0][0]){
            slope = (coordinates[1][1]-coordinates[0][1])/(coordinates[1][0]-coordinates[0][0]);
        }else{
            slope = INT_MAX;
        }
        /* slope = infinite case */
        if(slope==INT_MAX){
            for(int i=2;i<dot_num;i++){
                if(coordinates[i][0]!=coordinates[0][0]){
                    return false;
                }
            }
            return true;
        }
        /* other cases */
        
        //cout << slope << " ";
        for(int i=2;i<dot_num;i++){
            // cout << "current_sloper" << (float(abs(coordinates[i][1]-coordinates[0][1]))/(coordinates[i][0]-coordinates[0][0])) << endl;
        if((float(coordinates[i][1]-coordinates[0][1])/(coordinates[i][0]-coordinates[0][0]))==slope){
                continue;
            }else{
                return false;
            }
        }
               
        return true;

    }
};