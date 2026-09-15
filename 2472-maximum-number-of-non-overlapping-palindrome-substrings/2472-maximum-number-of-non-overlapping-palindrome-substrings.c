int maxPalindromes(char* s, int k) {
    int n = strlen(s);
    int count = 0;

    int end = -1;
    int i = k-1;
    while(i < n){
        int left = i-k+1;
        int right = i;
        int is_pal = 1;

        if(left > end){
            while(left < right){
                if(s[left] != s[right]){
                    is_pal = 0;
                    break;
                }
                left++;
                right--;
            }
        }
        else{
            is_pal = 0;
        }

        if(is_pal){
            count++;
            end = i;
            i += k;
            continue;
        }

        if(i-k >= 0){
            left = i-k;
            right = i;
            is_pal = 1;

            if(left > end){
                while(left < right){
                    if(s[left] != s[right]){
                        is_pal = 0;
                        break;
                    }
                    left++;
                    right--;
                }
            }
            else{
                is_pal = 0;
            }

            if(is_pal){
                count++;
                end = i;
                i += k;
                continue;
            }
        }
        i++;
    }
    return count;
}