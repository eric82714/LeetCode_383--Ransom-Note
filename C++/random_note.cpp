class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        if(magazine.size() < ransomNote.size()) return false;
        
        if(magazine.size() == ransomNote.size()) {
            if(ransomNote != magazine) return false;
            else return true;
        }
        
        map<char, int> hashmap;
        
        for(auto w : ransomNote) {
            if(magazine.find(w) == magazine.npos) return false;
            if(magazine.find(w) != magazine.npos && hashmap.find(w) == hashmap.end()) {
                hashmap[w] = count(magazine.begin(), magazine.end(), w) - 1;
                continue;
            }
            if(magazine.find(w) != magazine.npos && hashmap.find(w) != hashmap.end() && hashmap[w] != 0) {
                hashmap[w] --;
                continue;
            }
            if(magazine.find(w) != magazine.npos && hashmap.find(w) != hashmap.end() && hashmap[w] == 0)
                return false;
        }
        
        return true;
    }
};
