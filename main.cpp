class intAndBin{
public:

    intAndBin(){
        isSigned = false;
    }
    intAndBin(bool mySign){
        isSigned = mySign;
    }
    //use 32-bit
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
        if(isSigned && (tmp < INT_MIN || tmp > INT_MAX)) return "OVERFLOW";
        if(tmp == 0) return "0";

        string mys = "";
        if(!isSigned){
            while(tmp != 0){
                mys = (char)(tmp % 2 + '0') + mys;
                tmp /= 2;
            }
        }else{
            if(sign == -1) tmp = ~tmp + 1;
            for(int i = 0; i < 32; i ++){
                mys = (char)((tmp & 1) + '0') + mys;
                tmp = tmp >> 1;
            }
        }
        return mys;
    }//int to bin

    string binToInt(string& s){
        if(s.length() == 0) return "";
        if(isSigned && s.length() != 32) return "LENGTH WRONG";
        if(!isSigned && s[0] == '0') return "0";

        int tmp = 0;
        int cur = 1;
        int ptr = s.length() - 1;
        while(ptr >= 0){
            if(s[ptr] == '1'){
                tmp += cur;
            }
            cur = cur << 1;
            ptr --;
        }
        string strTmp = "";
        if(!isSigned || s[0] == '0'){
            while(tmp != 0){
                strTmp = (char)('0' + (tmp % 10)) + strTmp;
                tmp /= 10;
            }
        }else{
            tmp = ~tmp + 1;
            while(tmp != 0){
                strTmp = (char)('0' + (tmp % 10)) + strTmp;
                tmp /= 10;
            }
            strTmp = '-' + strTmp;
        }
        return strTmp;
    }

private:
    bool isSigned;
};


int main()
{
    vector<string> testCases;
    testCases.push_back("1");
    testCases.push_back("-1");
    testCases.push_back("123");
    testCases.push_back("323213");
    testCases.push_back("-24222");
    testCases.push_back("7546");
    testCases.push_back("-8372");
    testCases.push_back("8372");

    intAndBin myClass (true);

    for(auto &i : testCases){
        cout << endl;
        cout << i << ":" ;
        string tmp = myClass.intToBin(i);
        cout << tmp << ":" ;
        cout << myClass.binToInt(tmp) << endl;
    }
    return 0;

}
