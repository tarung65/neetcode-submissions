class Solution {
public:
    constexpr static int total_minutes =24*60;
    constexpr static int max_difference = total_minutes/2;
    int convertStringToMin(string& s){
        int hours = std::stoi(s.substr(0, 2));
        int minutes = std::stoi(s.substr(3, 2));
        return hours * 60 + minutes;
    }
    
    int diffenceab(int a,int b){
        int difference = abs(a-b);
        if(difference > max_difference){
            difference = total_minutes-difference;
        }
        return difference;
    }
    int findMinDifference(vector<string>& timePoints) {
        std::vector<int>minutes;
        for(auto s : timePoints)
            minutes.push_back(convertStringToMin(s));
        int min = max_difference;
        for(int i = 0;i<minutes.size()-1;i++){
            for(int j = i+1;j<minutes.size();j++){
                min = std::min(min,diffenceab(minutes[i],minutes[j]));
            }
        }
        return min;
    }
};