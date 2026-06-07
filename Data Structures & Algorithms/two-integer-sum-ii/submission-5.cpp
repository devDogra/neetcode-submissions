class Solution {
public:
/*
EXPLN 2:
when we move from r= R, say, to r = R-1, why do we not reset left back to 
the starting pt?  say l = L, r = R was too big
so we try r = R-1, why do we keep l = L? what if an l from [0, L] is the correct one?
well, we moved l to L, L+R was too big 
but L-1, R was too small 
therefore L-1 is not enough to reach the target with R
so if its not enough to reach the target with R, 
it wont be enough to reach the target with R-1 either, since the sum with R-1
is gonna be smaller 

but L R overshot, so L might be enough to reach the target, so let stry 
L R-1

******************************
so in brief: assume r correct. start checking from left. if u overshoot, it means
r was not correct, so try r-1. dont reset l=L to 0, cuz any vals below L 
were not enough to reach the target with r, so they wont be with r-1 either
******************************
*
/

/* EXPLN 1
   0 1  2 3 4   5    6
[ 1  4 5 5  8 10 13 ]
assume r = 6 is part of 
the correct pair 
target = 13
lets find the other part of the pair 
[1], [13] => 14, gr8r than tgt 
our sum is greater than 13
since [13] was assumed to be correct, but
all psbl pairs with [13] will be greater than 
[1], [13], our assumption was false
and 13 is not a correct value. so lets ignore
it forever now and consider [10], with 
its companion being [1]. sum = 11, lower than 13
since [10] is correct, and sum is lower than 13, lets try 
increasing l, see if it matches. [4], [10] again greater than 13
since we assumed [10] to be correct, but we eliminated [1][10] 
and [4][10] and every psbl value with [10] will be greater than 
[4][10], we can safely say that [10] is not part of the right pair
so lets ignore it and try [8]. [1][8] => 9. try[4][8] => 12.
try[5][8] => BINGO


*/
    vector<int> twoSum(vector<int>& numbers, int target) {
        const int n = numbers.size();
        int l = 0; 
        int r = n-1;

        while(l < r) {
            int sum = numbers[l] + numbers[r];
            if (target == sum) {
                return vector<int>{l+1, r+1};
            } else if (target > sum) {
                l++;
            } else {
                r--;
            }
        }

        return vector<int>{-1,-1};
    }
};
