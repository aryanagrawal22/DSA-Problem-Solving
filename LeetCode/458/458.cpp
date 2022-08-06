class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        int y = (minutesToTest/minutesToDie) + 1;
        int z = y;
        int count = 1;
        if(buckets==1){
            return 0;
        }

        while(y<buckets){

            y = y * z;
            count++;

        }
        return count;
    }
};