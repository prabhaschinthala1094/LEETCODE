class Solution {
public:
    int isValid(int x) {
        int sum =0;
        int n = x;
        while(x){
            sum+=x%10;
            x/=10;
        }
        return (n%sum == 0)?sum:-1;
    }
    int sumOfTheDigitsOfHarshadNumber(int x) {
        return isValid(x);
    }
};