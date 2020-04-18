/*
    Date: 4/18/2020 
    state: run time error
    thought: image as maze question, if( : go down ; if ) : go right ; if * add branch to three node
*/

class Solution {
public:
    struct direction{
        int x_d=0;
        int y_d=0;
    };
    
    bool checkValidString(string s) {
        // int x=0;
        // int y=0;
        int current_depth=0;
        direction** node_keep = new direction*[100];
        direction* root;
        &node_keep[0][0] = root;    
        root->x_d=0;
        root->y_d=0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='('){
                cout << node_keep[current_depth][0].x_d;
               // maze(0, 1, node_keep, current_depth, 0);
            }else if(s[i]==')'){
                //maze(1, 0, node_keep, current_depth, 0);
            }else{
                // star case
                current_depth++;
                direction* node_exten = new direction[pow(3,current_depth)];
                node_keep[current_depth] = node_exten;
                for(int i=0;i<pow(3, current_depth-1);i++){
                    for(int j=0;j<3;j++){
                        int temp = pow(3, current_depth-1);
                        node_exten[temp+j] = node_keep[current_depth-1][i];
                    }
                    
                }
                    
                // maze(1, 0, node_keep, current_depth, 1);
                // maze(0, 1, node_keep, current_depth, 2);
                // maze(0, 0, node_keep, current_depth, 3);
            }
        }
        // for(int i=0;i<pow(3, current_depth);i++){
        //     if(node_keep[current_depth][i].x_d>0  && node_keep[current_depth][i].x_d==node_keep[current_depth][i].y_d)return true;
        // }
        return false;
    }
    
//     void maze(int x, int y, direction** node_keep, int current_depth, int request){
//         if(request==0){
//             for(int i=0; i< pow(3, current_depth);i++){
//                 if(node_keep[current_depth][i].x_d<0 || node_keep[current_depth][i].y_d<0){
//                     continue;
//                 }else if( node_keep[current_depth][i].x_d+x >node_keep[current_depth][i].y_d+y){
//                     node_keep[current_depth][i].x_d=-1;
//                     node_keep[current_depth][i].y_d=-1;
//                     continue;
//                 }
//                 node_keep[current_depth][i].x_d+=x;
//                 node_keep[current_depth][i].y_d+=y;

//             }
//         }else{
//             for(int i=request; i<pow(3, current_depth);i=i+3){
//                 if(node_keep[current_depth][i].x_d<0 || node_keep[current_depth][i].y_d<0){
//                     continue;
//                 }else if( node_keep[current_depth][i].x_d+x >node_keep[current_depth][i].y_d+y){
//                     node_keep[current_depth][i].x_d=-1;
//                     node_keep[current_depth][i].y_d=-1;
//                     continue;
//                 }
//                 node_keep[current_depth][i].x_d+=x;
//                 node_keep[current_depth][i].y_d+=y;
//             }
//         }
//     }
};