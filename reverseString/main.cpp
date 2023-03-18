/**

example 1:
input：["h","e","l","l","o"]
output：["o","l","l","e","h"]

example2 2：

input：["H","a","n","n","a","h"]
output：["h","a","n","n","a","H"]

**/

void reverseString(char* s, int sSize){
    for (int i = 0, j = sSize - 1; i < j; ++i, --j) {
        char c = s[i];
        s[i] = s[j];
        s[j] = c;
    }    
}
// time complexity：O(n)
// space complexity ：O(1)