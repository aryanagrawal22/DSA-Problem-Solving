class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        
        //Sort the array with respect to units i.e 1st index
        sort(boxTypes.begin(), boxTypes.end(), [](auto const &a, auto const &b) { return a[1] > b[1]; });
        int curBoxes = 0;
        int curUnits = 0;
        for(int i = 0; i<boxTypes.size(); i++){
            
            // If Total Boxes till now + boxes at next array ele > truckSize then make boxes at next ele = left space for boxes to fit
            if(curBoxes + boxTypes[i][0] > truckSize)boxTypes[i][0] =  truckSize - curBoxes;
            
            //Update the currBoxes and currUnits after adding
            curUnits += boxTypes[i][0] * boxTypes[i][1];
            curBoxes += boxTypes[i][0];
            
            //Break loop when curBoxes equals to truckSize and retrun currUnits
            if(curBoxes == truckSize) break;
        }
        return curUnits;
    }
};