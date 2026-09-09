bool isAnagram(char* s, char* t) {
    if(strlen(s) != strlen(t)) return false;
    int count[26] = {0};

    int k = 0;
    while(s[k] != '\0'){
        count[s[k] - 'a']++;
        count[t[k] - 'a']--;
        k++;
    }

    for(int i = 0; i < 26; i++){
        if(count[i] != 0) return false;
    }
    return true;
}