// [0, 2pi)
template<class T>
bool arg_cmp(const complex<T> &p, const complex<T> &q){
    bool p_area = imag(p) > 0 ? 0 : (imag(p) == 0 && real(p) >= 0 ? 0 : 1);
    bool q_area = imag(q) > 0 ? 0 : (imag(q) == 0 && real(q) >= 0 ? 0 : 1);
    if(p_area != q_area) return p_area < q_area;
    else if(real(p) == 0 && imag(p) == 0) return real(q) != 0 || imag(q) != 0;
    else return cross(p, q) > 0;
}