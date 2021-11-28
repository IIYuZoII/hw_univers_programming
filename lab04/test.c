int main() {

    float frac; 
    int whole;
    float y;
    float num = 111.555;
    int c = num * 1000; // = 123656
    whole = num; // = 123
    frac = (c % 1000); // = 656
    int m;
    int f;
    float s;
    float l;
    float d;
    
    if(frac == 0) {
        y = 0;
    }
    else {
        y = frac / whole; // = 5.3333333
        m = y * 100.0; // = 533
        f = m / 100.0; // = 5
	s = (m / 10) % 10; // = (53) % 10 = 3
	l = m % 10; // = 3 
	d = ((s * 10) + l) / 100; // = 0.33

    }
    float result = f + d;
    return 0;
}
