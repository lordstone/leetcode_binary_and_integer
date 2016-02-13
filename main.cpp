class intAndBin{
public:

    intAndBin(){
        hasNeg = false;
    }

    string intToBin(string& s){
        if(s.length() == 0) return "";
        int sign = 1;
        if(s[0] == '-') {
            s = s.substr(1);
            sign = -1;
        }
        int tmp = 0;
        for(auto &i : s){
            tmp *= 10;
            int intTmp = (int)(i - '0');
            tmp += intTmp;
        }
        if(tmp == 0) return "0";
        string mys = "";
        while(tmp != 0){
            mys = (char)(tmp % 2 + '0') + mys;
            tmp /= 2;
        }
        return mys;
    }//int to bin

    string binToInt(string& s){
        if(s.length() == 0) return "";
        if(s[0] == '0') return "0";
        int tmp = 0;
        int cur = 1;
        while(s.length() != 0){
            if(s[s.length() - 1] == '1'){
                tmp += cur;
            }
            cur = cur << 1;
            s = s.substr(0,s.length() - 1);
        }
        string strTmp = "";
        while(tmp != 0){
            strTmp = (char)('0' + (tmp % 10)) + strTmp;
            tmp /= 10;
        }
        return strTmp;
    }
private:
    bool hasNeg;
};
