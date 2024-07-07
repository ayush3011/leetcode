string getEncryptedString(string s, int k) {
        int n = s.size();
        string encryptedString = s; 
        
        for (int i = 0; i < n; ++i) {
            encryptedString[i] = s[(i + k) % n];
        }
        
        return encryptedString;
}
