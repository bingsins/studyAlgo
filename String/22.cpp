class Solution {
public:
    vector<string> answer;
    void add(int index,int open ,int close,string text){
        if(open==index&&close==index){
            answer.push_back(text);
            return;
        }
        else{
            if(open<index){
                add(index,open+1,close,text+'(');
            }
            if(close<open){
                add(index,open,close+1,text+')');
            }
        }
    }
    vector<string> generateParenthesis(int n) {
        add(n,0,0,"");
        return answer;
    }
};

// class Solution {
// public:
//     vector<string> answer;

//         void add(int n, int index, string text){
            
//         if(n==index){
//             answer.push_back(text);
//             return;
//         }
//         else{
//             if(index < n){
//                 add(n,index+1,'('+text+')');
//                 add(n,index+1,text+"()");
//             }
//         }
//     }
//     vector<string> generateParenthesis(int n) {
//         // if(n ==0)
//         //     return "";
//         // if(n ==1)
//         //     return ["()"];
//         if(n > 1 )
//         add(n, 1, "()");
//         return answer;
//     }
// };
