class Solution {
public:
    bool valid(string &c){
        return (c=="+" || c=="-" || c=="*" || c=="/");
    }
    int solve(int u,int v,string &c){
        if(c=="+")return v+u;
        else if(c=="-")return v-u;
        else if(c=="*")return v*u;
        else return v/u;
    }
    int evalRPN(vector<string>& tokens) {
        stack<int>s;
        for(auto it:tokens){
            if(valid(it)){
                int u=s.top();
                s.pop();
                int v=s.top();
                s.pop();
                int k=solve(u,v,it);
                s.push(k);
            }
            else{
                s.push(stoi(it));
            }
        }
        return s.top();
    }
};