class Solution {
public:
    int characterReplacement(string s, int k) {
        if(0==s.length()) {return 0;}

        vector<int> count(26,0);
        int count_diff=0, slide=0, _max=1;

        for(int i=0; i<s.length(); i++)
        {
            count[s[i]-'A'] ++;
            count_diff = max(count_diff, count[s[i]-'A']);

            while((i-slide+1) - count_diff > k)
            {
                count[s[slide]-'A']--;
                slide++;
            }

            _max = max(_max, i-slide+1);
        }

        return _max;
    }
};