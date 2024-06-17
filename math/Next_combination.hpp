long long next_combination(long long sub){
    if(!sub) return (long long)1e18;
    long long x = sub & -sub, y = sub + x;
    return (((sub & ~y) / x) >> 1) | y;
}
