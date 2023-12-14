READ(N);

IF N = 0 THEN
    L := 0
ENDIF;

IF N = 1 THEN
    L := 1
ENDIF;

IF N > 1 THEN
    I := 1;
    A := 0;
    B := 1;
    WHILE I < N + 1 DO
        T := B;
        B := A + B;
        A := T;
        I := I + 1
    ENDWHILE;
    L := B
ENDIF;

WRITE(L).