A := 10;
I := 1;
WHILE I < A DO
    B := 10;
    J := 1;
    WHILE J < B DO
        C := I * J;
        WRITE(C);
        J := J + 1
    ENDWHILE;
    I := I + 1
ENDWHILE.