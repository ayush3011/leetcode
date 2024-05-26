class Solution
{
public:
    bool checkRecord(string s)
    {
        // int absentCount=0, lateCount=0, consecutiveLateFlag=0;
        // for(int i=0; i<s.size(); i++){
        //     if(s[i]=='A'){
        //         absentCount++;
        //         lateCount=0;
        //     }
        //     else if(s[i]=='L'){
        //         lateCount++;
        //         if(lateCount==3)
        //             consecutiveLateFlag=1;
        //     }
        //     else{
        //         lateCount=0;
        //     }
        // }
        // if(absentCount<2 && consecutiveLateFlag==0)
        //     return true;
        // return false;

        int absentCount = 0;
        for (int i = 0; i < s.size(); ++i)
        {
            if (s[i] == 'A')
            {
                absentCount++;
                if (absentCount >= 2)
                {
                    return false;
                }
            }
            if (i > 1 && s[i] == 'L' && s[i - 1] == 'L' && s[i - 2] == 'L')
            {
                return false;
            }
        }
        return true;
    }
};