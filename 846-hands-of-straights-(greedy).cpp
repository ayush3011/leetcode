bool isNStraightHand(vector<int>& hand, int groupSize) {
        if(hand.size()%groupSize!=0) return false;

        sort(hand.begin(), hand.end());

        map<int,int> m;
        for(int i=0; i<hand.size(); i++)
            m[hand[i]]++;

        for(int card:hand){
            if(m[card]==0) continue;

            for(int i=0; i<groupSize; i++){
                int currentCard=card+i;
                if(m[currentCard]==0) return false;
                m[currentCard]--;
            }
        }
        return true;
}
