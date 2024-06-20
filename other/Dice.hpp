// 面と変数の対応付けは Dice Stamp (https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2703) における
// (l, r, f, b, d, u) から (xn, xp, yn, yp, zn, zp) に置き換えたものとする。（右手座標系）
// 面の値（Label）のみを保持。一致判定などにおいて向きは非考慮。
// Verified problem1: Dice Stamp (https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2703)
// Verified problem2: Biased Dice (https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1181)

struct Dice{
    static constexpr int arr[7][7] = {
        {0,0,0,0,0,0,0},
        {0,0,4,2,5,3,0},
        {0,3,0,6,1,0,4},
        {0,5,1,0,0,6,2},
        {0,2,6,0,0,1,5},
        {0,4,0,1,6,0,3},
        {0,0,3,5,2,4,0}
    };
    int xnL, xpL, ynL, ypL, znL, zpL; // labels
    int xco, yco, zco; // x, y, z coordinate (for rolling the dice)

    Dice() : xnL(2), xpL(5), ynL(3), ypL(4), znL(6), zpL(1), xco(0), yco(0), zco(0) {}
    
    Dice(int xn, int xp, int yn, int yp, int zn, int zp, int xco = 0, int yco = 0, int zco = 0) :
    xnL(xn), xpL(xp), ynL(yn), ypL(yp), znL(zn), zpL(zp), xco(xco), yco(yco), zco(zco) {}

    // after initialization, make normal dice (set -1 to unknown label)
    // 右手座標系
    void makeNormalDice(int xn, int xp, int yn, int yp, int zn, int zp){
        if(xn == -1 && xp != -1){ xn = 7 - xp; }
        if(xp == -1 && xn != -1){ xp = 7 - xn; }
        if(yn == -1 && yp != -1){ yn = 7 - yp; }
        if(yp == -1 && yn != -1){ yp = 7 - yn; }
        if(zn == -1 && zp != -1){ zn = 7 - zp; }
        if(zp == -1 && zn != -1){ zp = 7 - zn; }
        if(xn == -1){
            assert(xp == -1 && yn != -1 && zn != -1);
            xp = arr[zp][yp];
            xn = 7 - xp;
        }
        if(yn == -1){
            assert(yp == -1 && xn != -1 && zn != -1);
            yp = arr[xp][zp];
            yn = 7 - yp;
        }
        if(zn == -1){
            assert(zp == -1 && xn != -1 && yn != -1);
            zp = arr[yp][xp];
            zn = 7 - zp;
        }
        xnL = xn, xpL = xp;
        ynL = yn, ypL = yp;
        znL = zn, zpL = zp;
    }

    // shift 4 params to left.
    // (a, b, c, d) -> (b, c, d, a)
    void shift(int& a, int& b, int& c, int& d){
        int tmp = a;
        a = b, b = c, c = d, d = tmp;
    }

    void rotXY(bool clockwise = false){
        if(clockwise) shift(xpL, ypL, xnL, ynL);
        else shift(xpL, ynL, xnL, ypL);
    }
    void rotYZ(bool clockwise = false){
        if(clockwise) shift(ypL, zpL, ynL, znL);
        else shift(ypL, znL, ynL, zpL);
    }
    void rotXZ(bool clockwise = false){
        if(clockwise) shift(xpL, zpL, xnL, znL);
        else shift(xpL, znL, xnL, zpL);
    }

    // roll dice
    // x, y の値が変わるので注意
    void rotXp(){ rotXZ(true);  xco++; }
    void rotXn(){ rotXZ(false); xco--; }
    void rotYp(){ rotYZ(true);  yco++; }
    void rotYn(){ rotYZ(false); yco--; }

    // d と書かれた面の方向を返す。存在しない場合 -1 を返す。
    // roll が true の場合、面の方向に回せるなら回す。
    int faceDir(int d, bool roll = false){
        if(xnL == d){
            if(roll) rotXn();
            return 0;
        }
        if(xpL == d){
            if(roll) rotXp();
            return 1;
        }
        if(ynL == d){
            if(roll) rotYn();
            return 2;
        }
        if(ypL == d){
            if(roll) rotYp();
            return 3;
        }
        if(znL == d) return 4;
        if(zpL == d) return 5;
        return -1;
    }

    // デバッグ用
    friend ostream& operator<<(ostream& os, const Dice& dice){
        os << "(xnL, xpL, ynL, ypL, znL, zpL) = (";
        os << dice.xnL << ", " << dice.xpL << ", ";
        os << dice.ynL << ", " << dice.ypL << ", ";
        os << dice.znL << ", " << dice.zpL << "), "; 
        os << "(x, y, z) = (" << dice.xco << ", " << dice.yco << ", " << dice.zco << ")"; 
        return os;
    }
};