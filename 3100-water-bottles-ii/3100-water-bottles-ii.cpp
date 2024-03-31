class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int ans = numBottles;
        if(numBottles<numExchange)return numBottles;
        if(numBottles == numExchange) return numBottles+1;
        while(numBottles>0) {
            numBottles-=numExchange;
            numExchange+=1;
            numBottles+=1;
            ans++;
        }
        return ans-1;
        
    }
};