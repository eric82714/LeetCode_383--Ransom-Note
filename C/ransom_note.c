bool canConstruct(char * ransomNote, char * magazine){
    if(strlen(ransomNote) > strlen(magazine)) return false;
    
    int char_count[26] = {0};
    
    for(int i = 0; i < strlen(magazine); i++) {
        char_count[magazine[i] - 'a'] ++;
    }

    for(int i = 0; i < strlen(ransomNote); i++) {
        if(char_count[ransomNote[i]-'a'] <= 0) return false;
        else char_count[ransomNote[i]-'a'] --;
    }

    return true;
}
