#---------------------------------------------Indices---------------------------------------------------------
set N := {1..3}; #Numero de produtos;
set K := {1..3}; #Numero de padrão de corte;
set T := {0..3}; #Numero de Periodos;
set S{T};#Numero de subperiodos por periodo;
set Ft{T}; #Primeiro subpriodo de cada periodo ;
set Lt{T}; #Ultimo subpriodo de cada periodo ;


#--------------------------------------------Parametros-----------------------------------------------------

#Inventorio inicial do produto i
param I{i in N}, >=0;

#Demanda do produto i no periodo t
param dit{i in N, t in T}, >=0;

#Unidade do produto i obtida pelo padrão de corte j por hora
param pij{i in N, j in K}, >= 0;

#Cacidade de horas disponíveis no periodo t
param capt{t in T}, >=0;

#tempo necessário para realizar a troca do padrão j para o padrão k;
param stjk{j in K, k in K}, >=0;

#custo referente a troca do padrão j para o padrão k;
param cjk{j in K, k in K}, >= 0;

#Custo de estocagem por unidade do produto i por periodo
param hi{i in N}, >=0;

#Custo de backloggin por unidade do produto i por periodo
param bi{i in N}, >=0;



#--------------------------------------------Variaveis--------------------------------------------------------
#Tempo gasto pelo padrão de corte j no subperiodo s
var Xjs{t in T, j in K, s in S[t]}, >=0, integer;

#Quantidade do produto i no inventório ao final do periodo t
var Iit{i in N, t in T}, >=0, integer;

#Backlock do produto i ao final do periodo t
var Bit{i in N, t in T}, >=0, integer;

#1 se a maquina está preparada para o padrão de corte j no subperiodo s, 0 caso contrario
var Yjs{t in T, j in K, s in S[t]}, binary;

#1 se houver uma troca do padrão de corte j para o padrão de corte k no subperiodo s, 0 caso contrario
var Zjks{t in T, j in K, k in K, s in S[t]}, binary;


#---------------------------------------Função Objetivo-----------------------------------------------------
minimize custo: (sum{i in N, t in T} ((hi[i]*Iit[i,t])+(bi[i]+Bit[i,t]))) + (sum{t in T, j in K, k in K, s in S[t]} ((cjk[j,k] * Zjks[t,j,k,s])));

#------------------------------------------Restrições--------------------------------------------------------

restricao_02{i in N, t in T : t > 1}: (Iit[i,(t-1)] - Bit[i, t-1]) + (sum{j in K, s in S[t]} (pij[i,j] * Xjs[t,j,s])) = dit[i,t] + Iit[i,t] - Bit[i,t];

restricao_03{t in T : t > 0}: ((sum{j in K, s in S[t]} Xjs[t,j,s]) + (sum{j in K,k in K, s in S[t]} stjk[j,k] * Zjks[t, j,k,s])) <= capt[t];

restricao_04{j in K, t in T, s in S[t]}: Xjs[t,j,s] <= (capt[t] * Yjs[t,j,s]);

restricao_05{t in T, s in S[t]}: sum{j in K} Yjs[t, j,s] = 1;

restricao_06{j in K, t in T, t1 in Lt[t], f1 in Ft[t]: t > 1}: Yjs[t, j,t1] = sum{k in K} Zjks[t,j,k,f1];

resticao_07{j in K, t in T, s in S[t]}: Yjs[t,j,s] = sum{k in K} Zjks[t,j,k,s];

restricao_08{k in K, t in T, s in S[t]}: Yjs[t,k,s] = sum{j in K} Zjks[t,j,k,s];

restricao_esqtoque_inicial{i in N}: Iit[i,1] = I[i];


#####
solve;

data;

set S[0] := 1	2;
set S[1] := 1	2;
set S[2] := 1 	2;
set S[3] := 1	2;

set Ft[0] := 1;
set Ft[1] := 1;
set Ft[2] := 1;
set Ft[3] := 1;

set Lt[0] := 2;
set Lt[1] := 2;
set Lt[2] := 2;
set Lt[3] := 2;

param I :=
	1 2
	2 3
	3 1;
	

param dit :
		1	2	3:=
	1	5	2	4
	2	2	3	1
	3	1	1	5;
	
param pij :
	1	2	3:=
1	2	3	1
2	2	1	1
3	1	2	3;
param capt :=
	0 4
	1 5
	2 3
	3 4;
	
param stjk :
	1	2	3:=
1	0	1	1
2	1	0	2
3	1	2	0;

param cjk :
	1	2	3 :=
1	1	100	300
2	200	0	400
3	300	400	0;
	
param hi :=
	1	20
	2	25
	3	30;
	
param bi :=
	1	40
	2	45
	3	50;


end;
