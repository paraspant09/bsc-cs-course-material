parent(pam,bob).
parent(tom,bob).
parent(tom,liz).
parent(bob,ann).
parent(bob,pat).
parent(pat,jim).
female(pam).
female(liz).
female(pat).
female(ann).
male(tom).
male(bob).
male(jim).

grandparent(X,Z):- parent(X,Y),parent(Y,Z).
grandfather(X,Z):- grandparent(X,Z),male(X).
grandmother(X,Z):- grandparent(X,Z),female(X).
mother(X,Y):- parent(X,Y),female(X).
father(X,Y):- parent(X,Y),male(X).
sibling(X,Y):-parent(Z,X),parent(Z,Y),X\=Y.
sister(X,Y):- sibling(X,Y),female(X).
brother(X,Y):- sibling(X,Y),male(X).
child(X,Y):-parent(Y,X).
son(X,Y):-parent(Y,X),male(X).
daughter(X,Y):-parent(Y,X),female(X).



sum(X,Y,S):- S is X+Y.

max(X,Y,M):- X>=Y, M is X,!.
max(_,Y,M):- M is Y.

factorial(0,1):-!.
factorial(N,F):- N>0, N1 is N-1,factorial(N1,F1) , F is N*F1.

generate_fib(0,0):-!.
generate_fib(1,1):-!.
generate_fib(N,F):- N>1,
    N1 is N-1,
    N2 is N-2,
    generate_fib(N1,F1),
    generate_fib(N2,F2),
    F is F1+F2.

gcd(0,B,B):-!.
gcd(A,0,A):-!.
gcd(A,B,R):-A>B,N1 is A-B,gcd(N1,B,R),!.
gcd(A,B,R):-N2 is B-A,gcd(A,N2,R).

power(_,0,1):-!.
power(Num,1,Num):-!.
power(Num,Pow,Ans):-Pow>0,F is Pow-1,power(Num,F,R1),Ans is R1*Num.

multi(_,0,0):-!.
multi(N1,1,N1):-!.
multi(1,N1,N1):-!.
multi(N1,N2,R):-N2>0,F is N2-1,multi(N1,F,R1),R is R1+N1.

/*A is src,B is dest,C is support*/

towerofhanoi(1,A,B,_,1):-write("Disc 1 from "),write(A),write("->"),write_ln(B),!.
towerofhanoi(N,A,B,C,R):-	
	N1 is N-1,R is 2**N-1,
	towerofhanoi(N1,A,C,B,_),
	write("Disc "),write(N),write(" from "),write(A),write("->"),write_ln(B),
	N2 is N-1,
	towerofhanoi(N2,C,B,A,_).

edge(p,q).
edge(r,q).
edge(q,s).
edge(s,t).
edge(q,r).
route(A,B,R):-edge(A,B),write(A),write("->"),write(B),write(","),R is 1,!.
route(A,B,R):-edge(A,X),write(A),write("->"),write(X),write(","),route(X,B,R),!.
route(_,_,R):-R is 0.

memb(X,[X|_]):-!.
memb(X,[_|T]):-memb(X,T).

conc([],L,L):-!.
conc([X|L1],L2,[X|L3]):-conc(L1,L2,L3).

reverse([],[]):-!.
reverse([X|L],R):-reverse(L,R1),conc(R1,[X],R).

palindrome(L):-reverse(L,Rev),Rev=L,write("Is A Palindrome"),!.
palindrome(_):-write("Is Not A Palindrome").

sumlist([],0):-!.
sumlist([X|L],S):-sumlist(L,S1),S is (X+S1).

countlength([],0):-!.
countlength([_|L],S):-countlength(L,S1),S is S1+1.
evenlength(List):-countlength(List,S),modulo(S,2,Res),Res=0,!. /*0 is mod(S,2).*/
oddlength(List):-countlength(List,S),modulo(S,2,Res),Res=1,!. /*1 is mod(S,2).*/

modulo(A,B,Res):-A>=B,A1 is A-B,modulo(A1,B,Res),!.
modulo(A,_,Res):-Res is A.

nth_element(0,[H|_],H):-!.
nth_element(N,[_|L],X):-N>0,N1 is N-1,nth_element(N1,L,X).

find(_,[],0):-!.
find(A,[X|L],R):-A=X -> R is 1; L=[] -> R is 0;find(A,L,R).
remove_dup(L,R):-check_dup(L,_,R1),reverse(R1,R).
check_dup([],_,_):-!.
check_dup([H|L],Tmp,R):-find(H,Tmp,Res),
		(Res=1->check_dup(L,Tmp,R);
		Res=0->conc(Tmp,[H],Tmp2),check_dup(L,Tmp2,R1),conc(R1,[H],R)).

maxlist([M],M):-!.
maxlist([X|L],M):-maxlist(L,M1),(X>M1 -> M is X;M is M1).

insert_nth(I,N,L,R):-N>=0,find_nth(I,N,0,L,R).
find_nth(_,_,_,[],[]):-!.
find_nth(I,N,Pos,[H|L],R):-Pos<N,Pos1 is Pos+1,find_nth(I,N,Pos1,L,R1),conc([H],R1,R),!.
find_nth(I,_,_,L,R):-conc([I],L,R).

gethead([H|_],H).
removehead([_|T],T).
sublist([],_):-!.
sublist(S,[HL|L]):-gethead(S,HS),(HS=HL -> removehead(S,S1),sublist(S1,L);sublist(S,L)).

delete_nth(N,L, R):-N>=0,check_nth(N,0,L,R).
check_nth(_,_,[],[]):-!.
check_nth(N,Pos,[H|L],R):-Pos<N,Pos1 is Pos+1,check_nth(N,Pos1,L,R1),conc([H],R1,R),!.
check_nth(_,_,[_|L],R):-conc([],L,R).

delete_all(_,[], []):-!.
delete_all(X,[H|L],R):-(H=X -> delete_all(X,L,R);delete_all(X,L,R1),conc([H],R1,R)).

merge([],L,L):-!.
merge(L,[],L):-!.
merge(L1,L2,L3):-gethead(L1,H1),gethead(L2,H2),
	(H1<H2 -> removehead(L1,S1),merge(S1,L2,SL3),conc([H1],SL3,L3);
	removehead(L2,S2),merge(L1,S2,SL3),conc([H2],SL3,L3)).

noun([dog|X],X).
noun([cat|X],X).
noun([mouse|X],X).
verb([ate|X],X).
verb([chases|X],X).
adjective([big|X],X).
adjective([brown|X],X).
adjective([lazy|X],X).
determiner([the|X],X):-!.
nounphrase(NP,X):- determiner(NP,R) , noun(R,X) ,!.
nounphrase(NP,X):- determiner(NP,R) , adjective(R,S2) , noun(S2,X) ,!.
verbphrase(VP,X):- verb(VP,R) , nounphrase(R,X) ,!.
sentence(I,O):- nounphrase(I,R) , verbphrase(R,O).

