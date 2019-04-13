class Solution {
public:
    double Power(double base, int exponent) {
        if(exponent==0)
        {
            return 1.0;
        }
        if(exponent==1)
        {
            return base;
        }
        int _exponent=abs(exponent);
        double result=1.0;
        while(_exponent)
        {
            if(_exponent&1==1)
            {
                result*=base;
            }
            base*=base;
            _exponent>>=1;
        }
        if(exponent<0)
        {
            return 1/result;
        }
        return result;
    }
};