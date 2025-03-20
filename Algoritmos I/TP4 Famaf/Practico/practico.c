/*
Ayuda:
https://apuntes-famaf-lcc.vercel.app/algoritmos1/programas_imperativos
1)
 { P } S { Q }

    a)
        Pre             Pos
    { P = x = X ∧ y = Y } S { Q = x v y }

    Var x, y, res: Int;
    { x = X ∧ y = Y }
      if 
        x <= y ->  
            res := x;
        x > y ->  
            res := y;
      fi ; 
    { res = min.x.y }

    Derivacion:

        wp.s.q
    ={Defincion de wp}
        wp.(if..fi).(res = min.x.y)
    ={Por digesto de condicional}
        (x <= y ^ x > y) ^
        (x <= y -> wp.(res := x).(res = min.x.y) ^
        (x > y -> wp.(res := y).(res = min.x.y))
    ={Logica, abs. Def de secuenciacion}
        (x <= y -> (res = min.x.y) (x <- res) ^
        (x > y -> (res = min.x.y) (y <- res)
    ={Asignacion}
        (x <= y -> (x = min.x.y) ^          1)
        (x > y -> (y = min.x.y)             2)
    ={Supongamos que vale 1)}
        (x = min.x.y) ^ ( x > y -> ( y = min.x.y))
    ={Como es una suposicion de x <= y, entonces min.x.y = x. Vale una o la otra}
        True ^ ( y = min.x.y)
    ={Por suposicion de x >y, entonces min.x.y = y}
        True ^ True
    ={Logica}
        True 

    b)      
    Var x: Int;
    { x = X }
        if
            x >= 0 -> 
                skip;
            x < 0 -> 
                x := -x;
        fi;
    { x = |X|}

    Derivacion:

        wp.s.q
    ={Definicon por asignacion}
        wp.(if..fi).(x = |X|)
    ={Por digesto de if}
        (x >= 0 ^ x < 0) ^
        (x >= 0 -> wp.skip.(x = |X|) ^
        (x < 0 -> wp.(x := -x).(x = |X|)
    ={Logica}
        (True) ^
        (x >= 0 -> x = |X|) ^
        (x < 0 -> wp.(x := -x).(x = |X|)
    ={Def de digesto de asignacion. Abs de true}
        (x >= 0 -> x = |X|) ^
        (x < 0 -> (x = |X|).(x <- -x)
    ={Asignacion}
        (x >= 0 -> x = |X|) ^
        (x < 0 -> -x = |X|)
    ={Supongo x >= 0 }
        (x = |X|) ^
        (x < 0 -> -x = |X|)
    ={Por suposicion y aritmetica}
        True ^ (x < 0 -> -x = |X|)
    ={Supongo ewl antescedente y demuestro el consecuente}
        True ^ (-x = |X|)
    ={Por suposicion como x < 0 ^ x = X }
        True ^ True
    ={Logica}
        True
        
2)

    Sol apunte del profe luque:

    Ejemplo: Factorial de un número N: Dado N ≥ 0 quiero calcular el factorial de N.

    Const N : Int;
    Var res : Int;
    { P: N ≥ 0 }
    S
    { Q:  res = N!  }

    ¿Nos saldrá este programa a ojo? Queremos calcular: 
                                1 * 2 * 3 * 4 * …. * (N-1) * N
    La idea es hacer un ciclo que recorra los números desde 1 hasta el N (en una variable n), e ir multiplicando en res esos números.

    Const N : Int;
    Var res , n : Int;
    { P: N ≥ 0 }
    res , n  :=  1 , 1  ;
    do n ≤ N → 
            res , n := res * n , n + 1
    od
    { Q:  res = N!  }

    La otra forma a ojo, recorriendo al revés:

    Const N : Int;
    Var res , n : Int;
    { P: N ≥ 0 }
    res , n  :=  1 , N  ;
    do n ≥ 1 → 
            res , n := res * n , n - 1
    od
    { Q:  res = N!  }

    Ahora probemos derivando:
    Usando la técnica de reemplazo de constante por variable, creamos una nueva variable n : Int, y proponemos:
        INV ≡  res = n!  ∧  0 ≤ n ≤ N
        B    ≡   n ≠ N     (también andaría n < N)

    Replanteamos el programa:
    Const N : Int;
    Var res : Int;
    { P: N ≥ 0 }
    S1 ;
    { INV }
    do n ≠ N → 
            { INV ∧ B }
            S2
            { INV }
    od
    { Q:  res = N!  }

    Inicialización:
    { P: N ≥ 0 }
    S1 ; 
    { INV: res = n !  ∧  0 ≤ E ≤ N }

    S1 debe ser de la forma: res, n := E , F
    ( F no puede ser 1 porque no puedo saber 1 ≤ N )
    Elijo F = 0, E = 1 y sale todo bien (ejercicio: verificarlo con la wp)

    verifico:
    De ante mano ya se que debería quedar de la manera:
        res, n := 1, 0 ;

        wp.S1.I
    ={Asignacion de wp.}
        (res, n := E, F).(res = n ! ^ 0 <= res <= n )
    ={Asigno e, f}
        (E = F! ^ 0 <= E <= F )
    ={Supongo F = 0}
        (E = 0! ^ 0 <= E <= 0 )
    ={Por Aritmetica}
        E = 1 ^ 0 <= E <= 0
    ={Logica}
        E = 1 )?)
    ={Elijo E = 1}
        True
    
    Entonces, concluyo:
    res, n := 1, 0;

    Cuerpo del ciclo:
            { INV ∧ B:  res = n !  ∧  0 ≤ n ≤ N  ∧  n ≠ N }
            S2
            { INV:  res = n !  ∧  0 ≤ n ≤ N }

    S2 debe ser de la forma:   res, n := E , n + 1.

    Derivemos: Supongamos como hipótesis INV ∧ B, y veamos la wp:

        wp.(res, n := E , n + 1).INV
    ≡ { def. wp para :=  }
        E = (n+1) !  ∧  0 ≤ n+1 ≤ N
    ≡ { algebra (prop !) }
        E = n! * (n + 1)     ∧      0 ≤ n+1 ≤ N
    ≡ { hip. INV }   ← FUNDAMENTAL A LA HORA DE DERIVAR UN CUERPO DE CICLO
        E = res * (n + 1)     ∧      0 ≤ n+1 ≤ N
    ≡ { elijo E = res * (n+1) }
        res * (n + 1) = res * (n + 1)     ∧     0 ≤ n+1 ≤ N
    ≡ { lógica, elim de ambos lados.}
        0 ≤ n+1 ≤ N
    ≡ { 0 ≤ n+1 vale por hip. 0 ≤ n,    n+1 ≤ N vale por hip   n ≤ N  ∧ n ≠ N  } 
        True

    Listo! Resultado final:
    Const N : Int;
    Var res : Int;
    { P: N ≥ 0 }
    res, n := 1, 0 ;
    do n ≠ N → 
            res,  n := res * (n+1) , n + 1
    od
    { Q:  res = N!  }

    Es muy parecido pero no igual al que hicimos a ojo. Ambos andan bien igual.


3)

    Dado N >= 0

    Existe I (inv) tq:

    1) p -> I ^                     (Esto implicará en futuro p => wp.s1.q)
    2) {I ^ B} S { I } ^            (Esto implicará en futuro I ^ B = > wp.s2.q)
    3) I ^ -b => Q
    4) El ciclo termina

    (dsp funciones de cota )

     Var n, sum : Int;
    { P: N >= 0 }
    S
    { Q } 

    Derivacion: Neceisot un ciclo. APlico la tecnica de reemplazo de consante por variable.
    Pienso en un Q que cumpla:

    { P: N >= 0 }
    S
    { Q : res = <Sum i : 0 <= i < pos: i> ^ 0 <= pos <= N} 
    
    A ojo, veo que el programa tiene la forma de:

    En el ciclo, se cumple que:
    B = pos != N 

    Programa (a ojo):

    Var n, sum : Int;
    { P: N >= 0 }
        res, pos := 0, 0;       //s1 Inicializacion
        do (pos != N)
            pos := pos + res;   //s2 Cuerpo
        od 
    { Q: res = <Sum i : 0 <= i < N: i> }
    
    //Quiza sea de esta manera, lo hice a ojo.

    Tendrá la forma de:

    Var n, sum : Int;
    { P }
        S1 ; // Inicializacion
        do (B)
            {INV ^ B} 
            S2              // Cuerpo del ciclo
            {INV}
        od 
    { Q }

    El invariante tendria la forma de:
    res = <Sum i : 0 <= i < pos: i> ^ 0 <= pos <= N

    Hago la inicializacion:             // -> p => wp.S1.I

    Propongo que habrá s1 tq:

    res, pos := E, F;

    Supongo p y veo su wp.

        wp.s1.q
    ={Asignacion de wp}
        (res, pos := E, F;).(res = <Sum i : 0 <= i < pos: i> ^ 0 <= pos <= N)
    ={Asignacion}
        (E = <Sum i : 0 <= i < F: i> ^ 0 <= F <= N)
    ={Supongo F = 0}
        (E = <Sum i : 0 <= i < 0: i> ^ 0 <= 0 <= N)
    ={Rango vacio}
        (E = 0 ^ 0 <= 0 <= N)
    ={Hipotesis de P ( En la terna propuesta, N >= 0)}
        E = 0
    ={Elijo E = 0}
        True

    El programa va obtentiendo la forma de:


    { P : N >= 0 }
    res, pos := 0, 0;    // Inicializacion
        do (pos != N ) ???
            {INV ^ B} 
            S2    ???          // Cuerpo del ciclo
            {INV}
        od 
    { Q : res = <Sum i : 0 <= i < pos: i> ^ 0 <= pos <= N}


    Ahora con el cuerpo del ciclo:

    {I ^ B} s2 {I} == I ^ b => wp.s2.I
    
    Supongo que s2 tiene la forma de:
    
    res, pos := E, pos + 1;

    Entonces:

        wp.s2.q
    ={Asignacion de wp}
        (res, pos := E, pos + 1;).(res = <Sum i : 0 <= i < pos: i> ^ 0 <= pos <= N)
    ={Asignaciones}
        (E = <Sum i : 0 <= i < pos + 1: i> ^ 0 <= pos + 1 <= N)
    ={Por logica}
        (E = <Sum i : i = 0 v 0 <= i < pos + 1: i> ^ 0 <= pos + 1 <= N)
    ={Part de rango}
        (E = <Sum i : 1 <= i < pos + 1: i> + <Sum i : i = 0 : i> ^ 0 <= pos + 1 <= N)
    ={elim de var}
        (E = <Sum i : 1 <= i < pos + 1: i> + 0 ^ 0 <= pos + 1 <= N)
    ={Neutro de sum y Cambio de var, i = i + 1 }
        (E = <Sum i : 1 <= i + 1 < pos + 1: i + 1> ^ 0 <= pos + 1 <= N)
    ={Aritmetica}
        (E = <Sum i : 0 <= i < pos : i + 1> ^ 0 <= pos + 1 <= N)
    ={Escape de constante (+1) ?}
        (E = <Sum i : 0 <= i < pos : i> + 1 ^ 0 <= pos + 1 <= N)
    ={Por P, N >= 0 y aritmetica}
        (E = <Sum i : 0 <= i < pos : i> + 1 ^ N >= pos + 1)
    ={Por hipotesis P, y Q}
        (E = res + 1 ^ pos + 1)

    Finalmente:

    { P : N >= 0 }
    res, pos := 0, 0;    // Inicializacion
        do (pos != N ) 
            res, pos := res + 1, pos + 1;          // Cuerpo del ciclo
        od 
    { Q : res = <Sum i : 0 <= i < pos: i> ^ 0 <= pos <= N}

    Luego, { I ^ -b} S { Q } Trivialmente

            
    4)

    Dado N >= 0

    Existe I (inv) tq:

    1) p -> I ^                     (Esto implicará en futuro p => wp.s1.q)
    2) {I ^ B} S { I } ^            (Esto implicará en futuro I ^ B = > wp.s2.q)
    3) I ^ -b => Q                  (Suele ser trivial)
    4) El ciclo termina

    (dsp funciones de cota )

     Var n, sum : Int;
    { P: N >= 0 }
    S
    { Q } 

    Derivacion: 
        Necesito un ciclo. 
        Aplico la tecnica de reemplazo de consante por variable.
    
    Pienso en un Q que cumpla:

    { P: N >= 0 }
    S
    { Q : res = <sum i : 0 ≤ i < N : A.i >} 

    En el ciclo, se cumple que:
    B = pos != N  (Alternativamente, pos < N)

    Luego, I ^ -b -> Q es trivial. 

    A ojo, veo que el programa tiene la forma de:

    Const N : Int, A : Array[0, N) of Int;
    Var pos, res : Int;
    { P: N >= 0 }
    res, pos := 0, 0 ;
    { R: res = 0 ∧ pos = 0 }
    do pos != N → 
        { hasta acá ya sumé todas las posiciones desde 0 hasta pos no inclusive }
        res, pos := res + A.pos, pos + 1
    od
    { Q: res = <sum i : 0 ≤ i < N : A.i >}

    Pero tendrá la forma tal que:

    { P : N >= 0}
    s1;                         //Inicializacion
    {Inv}
        do (pos != N)
        {Inv ^ b}       
            s2;                 //Cuerpo
        {Inv}
        od
    {Q : <sum i : 0 ≤ i < N : A.i >}

    Invariante:  Recordemos que expresa el “resultado intermedio”:

    INV ≡    { res = <sum i : 0 ≤ i < pos : A.i >  ∧   0 ≤ pos ≤ N }

    //inicializacion

    Tengo que:
    
    p => wp.s1.I

    Y:

    { P : N >= 0}
    S1;
    {Q : <sum i : 0 ≤ i < N : A.i > }

    Entonces:
    Propongo que, res, pos := E, F; + La inv que tengo.

        wp.s1.I
    ={Asignacion de wp}
        wp.(res, pos := E, F;).(res = <sum i : 0 ≤ i < pos : A.i >  ∧   0 ≤ pos ≤ N)
    ={Asignaciones}
        (E = <sum i : 0 ≤ i < F : A.i >  ∧   0 ≤ F ≤ N)
    ={Elijo F = 0}
        (E = <sum i : 0 ≤ i < 0 : A.i >  ∧   0 ≤ 0 ≤ N)
    ={Rango vacio}
        E = 0 ^  0 ≤ 0 ≤ N
    ={Hip de p. ( N >= 0)}
        E = 0
    ={Elijo E = 0}
        True

    //Cuerpo

    Conclui en el anterior. Por mi logica que:

    res, pos := E, pos + 1;

    Tengo que:
    { I ^ B } S2 {I} == I ^ B => wp.s2.I

        wp.S2.I
    ={Asignacion de wp}
        wp.(res, pos := E, pos + 1;).(res = <sum i : 0 ≤ i < pos : A.i >  ∧   0 ≤ pos ≤ N)
    ={Asignacion de digesto.}
        (E = <sum i : 0 ≤ i < pos + 1 : A.i >  ∧   0 ≤ pos + 1 ≤ N)
    ={Logica de manera 2}
        (E = <sum i : i = pos v 1 ≤ i < pos : A.i >  ∧   0 ≤ pos + 1 ≤ N)
    ={Part de rango }
        (E = <sum i : i = pos : A.i > + <sum i : 0 ≤ i < pos : A.i >  ∧   0 ≤ pos + 1 ≤ N)
    ={Asig de var}
        E = A.pos + <sum i : 0 ≤ i < pos : A.i >  ∧   0 ≤ pos + 1 ≤ N
    ={Hip de Q ( lo q vale res) y P ( N >= 0)}
        E = A.Pos + res + 1
    ={Elijo E = A.pos + res}
        true 

    Quedando válido, la ultima parte de I ^ -b => Q  es trivial


    El programa quedo:

    { P : N >= 0}
        res, pos := 0, 0;                                               //Inicializacion
            do (pos != N) 
                res, pos := A.Pos + res + 1, pos + 1;                 //Cuerpo
            od
    {Q : <sum i : 0 ≤ i < N : A.i >}


5)

    a)

    Recorre un arreglo -> Do
    Se fija si los elementos son mayores a 0 (naturales de cierta forma)
    Var a: array[0,N) of Int;      
    { P : N >= 0 }
        S
    { Q : res = <Ai : 0 <= i < N : A.i > 0 > }

    Existe I (inv) tq:

    1) p -> I ^                     (Esto implicará en futuro p => wp.s1.I)
    2) {I ^ B} S { I } ^            (Esto implicará en futuro I ^ B = > wp.s2.I)
    3) I ^ -b => Q                  (Suele ser trivial)
    4) El ciclo termina

    (dsp funciones de cota )

    Derivacion: 
        Necesito un ciclo. 
        Aplico la tecnica de reemplazo de consante por variable.

    En el ciclo, b debería de ser de la forma:

    pos < N

    Entonces, nos va quedando de la manera:

    Var a: array[0,N) of Int;
    { P : N >= 0 }
    S1;
        do (pos < N)
        s2;
        od
    { Q : res = <Ai : 0 <= i < N : A.i >= 0 > }

    con una estructura de:

    Var a: array[0,N) of Int;
    { P : N >= 0 }
    S1;
    {Inv}
        do (pos < N)
        {Inv ^ b}
        s2;
        {Inv}
        od
    { Q : res = <Ai : 0 <= i < N : A.i >= 0 > }

    Var a: array[0,N) of Int;
    { P : N >= 0}
    s1;                         //Inicializacion
    {Inv}
        do (pos != N)
        {Inv ^ b}       
            s2;                 //Cuerpo
        {Inv}
        od
    {Q : res = <A i : 0 ≤ i < N : A.i >= 0>}

    Supongo que mi invariante, será de la forma
    res = <A i : 0 ≤ i < pos : A.i >= 0 > ^ 0 <= pos <= N

    Entonces, veo:

    //Inicializacion:

    Veo si p => wp.s1.I

    {N >= 0}
    S1;
    { Q : res = <A i : 0 ≤ i < pos : A.i >= 0> ^ 0 <= pos <= N}

    Busco algun S1 de la forma res,pos := E, F; Para ellos supongamos la hipotesis (N>= 0) y veamos la wp:
    res,pos := E, F;

        wp.s1.I
    ={Def de wp}
        wp.(res,pos := E, F;).(res = <A i : 0 ≤ i < pos : A.i >= 0> ^ 0 <= pos <= N)
    ={Def wp de asignacion}
        (E = <A i : 0 ≤ i < F : A.i >= 0> ^ 0 <= F <= N)
    ={Supongo F = 0}
        (E = <A i : 0 ≤ i < 0 : A.i >= 0> ^ 0 <= 0 <= N)
    ={Rango vacio, Hipotesis de N>=0}
        (E = true ^ True)
    ={Logica}
        True

        Por ende, tengo que s1 es:
        E = True, F = 0
        Entonces:
        s1 == res, pos := True, 0;

    Finalizo, demostrando I ^ -b => Q. Ya se que B es pos != N

        res = <A i : 0 ≤ i < pos : A.i >= 0> ^ 0 <= pos <= N ^ -(pos != N) => res = <A i : 0 ≤ i < N : A.i >= 0>
    ={Logica}
        res = <A i : 0 ≤ i < pos : A.i >= 0> ^ 0 <= pos <= N ^ pos = N => res = <A i : 0 ≤ i < N : A.i >= 0>
    ={Supongo antecedente y demuestro consecuente (O sea, como se repite en dos lados el res, se elimina)}
        <A i : 0 ≤ i < pos : A.i >= 0 >
    ={Por que pos = N}
        <A i : 0 ≤ i < N : A.i >= 0 >
    ={Por Q}
        True


    Va quedando el programa:

    Var a: array[0,N) of Int;
    { P : N >= 0}
    res, pos := True, 0;                         //Inicializacion
    {Inv}
    do (pos != N)
        {Inv ^ b}       
            s2;                 //Cuerpo
        {Inv}
    od
    {Q : res = <A i : 0 ≤ i < N : A.i >= 0>}

    Ahora veamos:

    {I ^ B } S2 { Q } == (I ^ B = > wp.s2.I)

    Busco una manera de que se siga validando las posiciones en bucle, pienso en un aumento de la mnera que:
    res, pos := E, pos + 1;

    Por s1, se que vale y supongo:
        res = <∀i : 0 ≤i < pos : A.i ≥0 >∧ 0 ≤ pos ≤N ∧ pos != N

        wp.s2.I
    ={Def de wp}
        wp.(res, pos := E, pos + 1;).(res = <∀i : 0 ≤i < pos : A.i ≥0 >∧ 0 ≤ pos ≤N ∧ pos != N)
    ={Asignaciones}
        (E = <∀i : 0 ≤ i < pos + 1 : A.i ≥ 0 >∧ 0 ≤ pos + 1 ≤ N)
    ={Logica}
        (E = <∀i : 0 ≤ i < pos v i = pos : A.i ≥ 0 >∧ 0 ≤ pos + 1 ≤ N)
    ={Particion de rango y rango unitario}
        (E = <∀i : 0 ≤ i < pos : A.i ≥ 0 > a.pos >= 0 ∧ 0 ≤ pos + 1 ≤ N)
    ={Por hipotesis P (N >= 0)}
        (E = <∀i : 0 ≤ i < pos : A.i ≥ 0 > ^ a.pos >= 0)
    ={Por suposicion de Q}
        E = res ^ a.pos >= 0
    ={Elijo E = res ^ a.pos >= 0}
        true


        Quedando  finalmente el programa:

    Var a: array[0,N) of Int;
    { P : N >= 0}
    res, pos := True, 0;                         //Inicializacion
    {Inv}
    do (pos != N)
        {Inv ^ b}       
            res, pos := res ^ a.pos >= 0, pos + 1;                //Cuerpo
        {Inv}
    od
    {Q : res = <A i : 0 ≤ i < N : A.i >= 0>}

    b) //este es el mas acertado de un ciclo

    Especificar y derivar un programa que determine si alg ́un elemento de A es mayor a 0

    Tenemos:

    { P : N >= 0 }
    S
    { Q : res = <E i : 0 <= i < N : A.i > 0 >}

    Derivacion: Neceisto un ciclo.
    Uso tecnica de reemplazo de constantes por variable y obtengo la invariante que seria:

    Inv = res = <E i : 0 <= i < pos : A.i > 0> ^ 0 <= pos < N

    Mi B de do sería:
    res != N

    Entonces, el programa reeplanteado tendría la forma de:

    Var a: array[0,N) of Int;
    { P : N >= 0}
    S1;                         //Inicializacion
    {Inv}
    do (pos != N)
        {Inv ^ b}       
            S2;                 //Cuerpo
        {Inv}
    od
    {Q : res = <E i : 0 <= i < N : A.i > 0 >}               

    Luego 
    P => I es trivial.

    Veamos:

    //inicializacion (Requisito I { P } S1; {Inv})

    Supongo como hipotesis que s1, es de:
    res, pos := E, F;

        wp.s1.I
    ={Def de wp.}
        wp.(res, pos := E, F;).(res = <E i : 0 <= i < pos : A.i > 0> ^ 0 <= pos < N)
    ={Asignaciones}
        (E = <E i : 0 <= i < F : A.i > 0> ^ 0 <= F < N)
    ={Asumo F = 0}
        (E = <E i : 0 <= i < 0 : A.i > 0 > ^ 0 <= 0 < N)
    ={Hipotesis P, Rango vacío}
        E  = False ^ True
    ={Elijo E = False y neutro de ^}
        True

    //cuerpo { Inv ^ B } S2 { I } -> wp.s2.I

    Propongo s2:

    res, pos := E, pos + 1.

    Hago la wp:

        wp.s2.I
    ={Def de wp}
        wp.(res, pos := E, pos + 1.).(res = <E i : 0 <= i < pos : A.i > 0 > ^ 0 <= pos < N)
    ={Asignaciones}
        (E =  <E i : 0 <= i < pos + 1 : A.i > 0 > ^ 0 <= pos + 1< N)
    ={Logica}
        (E =  <E i : 0 <= i < pos v i = pos : A.i > 0 > ^ 0 <= pos + 1< N)
    ={Particion de rango}
        (E =  <E i : 0 <= i < pos : A.i > 0 > v <E i : i = pos : A.i > 0 > ^ 0 <= pos + 1 < N)
    ={Hipotesis, Eliminacion de variable}
        (E =  res v A.pos > 0 ^ 0 <= pos + 1 < N)
    ={Hipotesis P}
        (E =  res v A.pos > 0)
    ={Elijo (E =  res v A.pos > 0) }
        True

    Quedando:

    Var a: array[0,N) of Int;
    { P : N >= 0}
    res, pos := 0, false;                         //Inicializacion
    {Inv}
    do (pos != N)
        {Inv ^ b}       
            res, pos := res v A.pos > 0, pos + 1;                 //Cuerpo
        {Inv}
    od
    {Q : res = <E i : 0 <= i < N : A.i > 0 >}

    // { I ^ -b } S1 => q

        (res = <E i : 0 <= i < pos : A.i > 0> ^ 0 <= pos < N) ^ -(pos != N) => (res = <E i : 0 <= i < N : A.i > 0 >)
    ={Por logica de negacion}
        (res = <E i : 0 <= i < pos : A.i > 0> ^ 0 <= pos < N) ^ pos = N => (res = <E i : 0 <= i < N : A.i > 0 >)
    ={Asignacion}
        (res = <E i : 0 <= i < pos : A.i > 0> ^ 0 <= pos < N) ^ pos = N => (res = <E i : 0 <= i < N : A.i > 0 >)
    ={Asigno el pos}
        (res = <E i : 0 <= i < N : A.i > 0 > ^ 0 <= N < N) => (res = <E i : 0 <= i < N : A.i > 0 >)
    ={Suponemos antecedente y demostramos consecuente, lógica}
        res = <E i : 0 <= i < N : A.i > 0 >
    ={Elijo, res = <E i : 0 <= i < N : A.i > 0 >}
        True

    Var a: array[0,N) of Int;
    {P : N >= 0}
    res, pos := 0, false;                                          //Inicializacion
    do (pos != N)    
            res, pos := res v A.pos > 0, pos + 1;                 //Cuerpo
    od
    {Q : res = <E i : 0 <= i < N : A.i > 0 >}


6)

    {P : N >= 0}
    S1
    {Q: <Sum i : 0 <= i < N : i mod 2 >}

7)

    Const N : Int, A : array[0, N) of Int ;
    Var r : Int ;
    {P : N ≥0}
    S
    {Q : r = ⟨N i, j : 0 ≤ i < j < N : A.i = A.j ⟩}       //es conteo             -> Pag 137

    Derivacion: Necesito un ciclo anidado

    Necesito una invariante, uso la tecnica de reemplazo de constante con variable
    se que el programa / respuesta final queda de la forma:

    I == res = ⟨N i, j : 0 ≤ i < j < pos : A.i = A.j ⟩ ^ 0 <= pos < N
    
    y mi condicion del do queda:
    B == pos < N

    Por estos datos, ya se que me queda la forma:

    { P : N >= 0 }
    S1;                                 //Inicializacion
    {Inv}
    do (pos < N)
        {Inv ^ B}
        S1;                             //Cuerpo
        {Inv}
    od
    {Q : r = ⟨N i, j : 0 ≤ i < j < N : A.i = A.j ⟩ }

    Por tecnica de ciclos anidados, me conviene calcular el Cuerpo primero, y no la inicializacion

    Cuerpo = Supongamos: I ^ B y veamos la wp.

    Sabemos que s2 quedaria:

    s2 = res,pos := E, pos +1;

        wp.s2.I
    ={Asignacion de wp}
        wp.(res,pos := E, pos +1;).(res = ⟨N i, j : 0 ≤ i < j < pos : A.i = A.j ⟩ ^ 0 <= pos < N);
    ={Asignacion}
        (E = ⟨N i, j : 0 ≤ i < j < pos + 1 : A.i = A.j ⟩ ^ 0 <= pos + 1 < N);
    ={Calculo auxilar de el rango de 0 ≤ i < j < pos + 1 }
            

            0 <= i < j < pos +1
            (0 <= i) ^ (i < j) ^ (j < pos + 1)
            (0 <= i) ^ (i < j) ^ (j <= pos)
            (0 <= i) ^(i < j) ^ (j < pos v j = pos)
            (0 <= i) ^(i < j) v (j < pos) v ((0 <= i) ^(i < j) ^ pos)
            0 <= i < j < pos v (0 <= i<j ^ j=pos)
            
            = 0 <= i < j < pos v (0<= i < j ^ j = pos)

        (E = ⟨N i, j : 0 <= i < j < pos v (0<= i < j ^ j = pos) : A.i = A.j ⟩ ^ 0 <= pos + 1 < N);    
    ={ Particion de rango }
        (E = ⟨N i, j : 0 <= i < j < pos : A.i = A.j ⟩ + ⟨N i, j : (0 <= i < j ^ j = pos) : A.i = A.j ⟩ ^ 0 <= pos + 1 < N);   
    ={ Hipotesis de res }
        E = res + ⟨N i, j : (0 <= i < j ^ j = pos) : A.i = A.j ⟩ ^ 0 <= pos + 1 < N);   
    ={logica de P}
        E = res + ⟨N i, j : (0 <= i < j ^ j = pos) : A.i = A.j ⟩ );
    ={Elim de var}   
        E = res + ⟨N i, j : (0 <= i < pos) : A.i = A.pos ⟩);
    
    Me trabo, no puedo fortalecer por que A.pos aparece mencionado, por lo tanto necesito el ciclo anidado mencionado, para tener una
    hipotesis adicional.

    aux = <Ni : 0 <= i < pos : A.i = A.pos >

    Entonces, el programa nos quedaria

    { P }
    S1;
    {I}
    do B ->
        {I ^ B}
            S2'; -> Calculo auxiliar
        {I ^ b ^ aux = <Ni : 0 <= i < pos : A.i = A.pos >}
            S2; -> res, pos := res + aux pos + 1
        {I}
    od
    { Q }


            














    {P : N ≥0}
    res, pos := 0, 0;
    do pos < N ->
        aux, pos2 := 0, 0;
        do pos2 < pos ->
            if A.pos2 = A.pos ->
                aux, pos2 := aux + 1, pos2;
            [] A.pos2 != A.pos ->
                pos2 := pos2 + 1;
            fi
        od;
    od;
    {Q : r = ⟨N i, j : 0 ≤ i < j < N : A.i = A.j ⟩}              -> Pag 137


10) 
    En el apunte del profe luque.





*/