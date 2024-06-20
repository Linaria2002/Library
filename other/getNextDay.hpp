void getNextDay(int &y, int &m, int &d){
    static int days[13] = {0, 31, 28, 31, 30, 31, 30,
                           31, 31, 30, 31, 30, 31};
    if((y % 4 == 0 && y % 100 != 0) || y % 400 == 0){
        days[2] = 29;
    }
    else days[2] = 28;

    d++;
    if(d > days[m]){
        d = 1, m++;
        if(m > 12){
            m = 1, y++;
        }
    }
}