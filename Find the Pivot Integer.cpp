//****************Solve this question by using 5 approaches****************
//Approach 1
class Solution {
public:
    int pivotInteger(int n) {
        
        for(int pivot = 1; pivot<=n; pivot++){

            int leftSum = 0;
            int rightSum = 0;

            for(int i = 1 ; i<=pivot ; i++){
                leftSum += i;
            }
             for(int i = pivot ; i<=n ; i++){
                rightSum += i;
            }

            if(leftSum == rightSum){
                return pivot;
            }
        }
        return -1;
    }
};

//Approach 2
class Solution {
public:
    int pivotInteger(int n) {
        int totalSum = n*(n+1)/2;

        for(int pivot = 1 ; pivot<=n; pivot++){
            int leftSum = pivot*(pivot+1)/2;

            int rightSum = totalSum - leftSum + pivot;

                if(leftSum==rightSum){
                    return pivot;
                }

        }
        return -1;
    }
};

//approach 3
class Solution {
public:
    int pivotInteger(int n) {
        int i = 1; 
        int j = n;

        int leftSum = 1;
       int  rightSum = n;

        while(i<j){
            if(leftSum<rightSum){
                i++;
                leftSum += i;
            }else{
                j--;
                rightSum += j;
            }
           
        }
         if(leftSum == rightSum){
                return i;
            }
            
        return -1;
    }
};

//Approach 4
class Solution {
public:
    int pivotInteger(int n) {

        int totalSum = n*(n+1)/2;
        int pivot = sqrt(totalSum);

        if(pivot*pivot == totalSum){
            return pivot;
        }
        
        return -1;
    }
};

//Approach 5
class Solution {
public:
    int pivotInteger(int n) {
        int totalSum = n*(n+1)/2;

        int left = 1;
        int right = n;

            while(left<=right){
                int mid_pivot = left + (right - left ) / 2;

                if(mid_pivot * mid_pivot == totalSum ){
                    return mid_pivot;
                } else if(mid_pivot * mid_pivot < totalSum){
                    left = mid_pivot + 1;
                }else{
                    right = mid_pivot - 1;
                }

            }

            return - 1;

    }
};
