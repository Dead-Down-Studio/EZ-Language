extern "C" int add(int a, int b) {
    return a + b;
}

extern "C" int mult(int a, int b) {
    return a * b;
}

extern "C" int sum9(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9) {
    return a1 + a2 + a3 + a4 + a5 + a6 + a7 + a8 + a9;
}

extern "C" double sum9f(double a1,
                         double a2,
                         double a3,
                         double a4,
                         double a5,
                         double a6,
                         double a7,
                         double a8,
                         double a9) {
    return a1 + a2 + a3 + a4 + a5 + a6 + a7 + a8 + a9;
}
