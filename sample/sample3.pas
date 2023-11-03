READ(N);
A := 0;
B := 1;
WHILE A < N DO
    A := A + B;
    B := B + 1
ENDWHILE;
WRITE(A).