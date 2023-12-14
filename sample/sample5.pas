READ(A);
READ(B);
I := 0;
C := 1;
WHILE I < B DO
    C := C * A;
    I := I + 1
ENDWHILE;
WRITE(C).