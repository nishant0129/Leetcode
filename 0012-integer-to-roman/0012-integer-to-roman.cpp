class Solution {
public:
	string intToRoman(int num) {
    
    vector<int> integer = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    vector<string> s = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
    
    string roman = "";
    
    for(int i = 0; i < integer.size(); i++){
        
        if(integer[i] <= num){
            roman += s[i];
            num -= integer[i];
            i--;
        }
    }
    return roman;
}
};