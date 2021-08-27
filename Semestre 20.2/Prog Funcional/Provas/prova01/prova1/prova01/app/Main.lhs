Avaliação 1 de Programação Funcional
========================

ATENÇÃO
-------

* A interpretação dos enunciados faz parte
da avaliação.

* A avaliação deve ser resolvida INDIVIDUALMENTE.
Se você discutir soluções com outros alunos da
disciplina, deverá mencionar esse fato como
parte dos comentários de sua solução.

* Se você utilizar recursos disponíveis na internet
e que não fazem parte da bibliografia, você deverá
explicitamente citar a fonte apresentando o link
pertinente como um comentário em seu código.

* Todo código produzido por você deve ser acompanhado
por um texto explicando a estratégia usada para a
solução. Lembre-se: meramente parafrasear o código
não é considerado uma explicação!

* Não é permitido modificar a seção Setup inicial
do código, seja por incluir bibliotecas ou por
eliminar a diretiva de compilação -Wall.

* Seu código deve ser compilado sem erros e warnings
de compilação. A presença de erros acarretará em
uma penalidade de 20% para cada erro de compilação e
de 10% para cada warning. Esses valores serão descontados
sobre a nota final obtida pelo aluno.

* Todo o código a ser produzido por você está marcado
usando a função "undefined". Sua solução deverá
substituir a chamada a undefined por uma implementação
apropriada.

* Todas as questões desta avaliação possuem casos de
teste para ajudar no entendimento do resultado
esperado. Para execução dos casos de teste, basta
executar os seguintes comandos:

```
$> stack build
$> stack exec prova1-exe
```

* Sobre a entrega da solução:

1. A entrega da solução da avaliação deve ser feita
como um único arquivo .zip contendo todo o projeto
stack usado.

2. O arquivo .zip a ser entregue deve usar a seguinte
convenção de nome: MATRÍCULA.zip, em que matrícula é
a sua matrícula. Exemplo: Se sua matrícula for
20.1.2020 então o arquivo entregue deve ser
2012020.zip. A não observância ao critério de nome e
formato da solução receberá uma penalidade de 20%
sobre a nota obtida na avaliação.

3. O arquivo de solução deverá ser entregue usando a
atividade "Entrega da Avaliação 1" no Moodle dentro do
prazo estabelecido.

4. É de responsabilidade do aluno a entrega da solução
dentro deste prazo.

5. Sob NENHUMA hipótese serão aceitas soluções fora do
prazo ou entregues usando outra ferramenta que
não a plataforma Moodle.


Setup inicial
-------------

> {-# OPTIONS_GHC -Wall #-}

> module Main where

> import Test.Tasty
> import Test.Tasty.HUnit

> main :: IO ()
> main = defaultMain tests

> tests :: TestTree
> tests
>   = testGroup "Unit tests"
>         [
>           question1Tests
>         , question2Tests
>         , question3Tests
>         , question4Tests
>         , question5Tests
>         , question6Tests
>         , question7Tests
>         , question8Tests
>         , question9Tests
>         , question10Tests
>         ]

Uma ferramenta para ensino remoto
=================================

Devido a recente pandemia de COVID-19, toda a rede de ensino
no Brasil e no mundo teve que se adaptar rapidamente à
realidade de aulas remotas.

O objetivo dessa avaliação é a criação de parte de uma ferramenta
para elaboração e correção de questionários. Para isso, esta avaliação
será dividida em duas partes: a primeira lidará com a modelagem de
questionários e a segunda com a sua correção e respectiva elaboração de
relatório de notas.

Parte 1. Validando um questionário
----------------------------------

Nesta primeira parte da avaliação, vamos construir tipos de dados
e funções para criação de questionários. O tipo central para questionários
é o tipo Question:


> data Question
>  = Question [Subject]
>             Statement
>             [Choice]
>             Value
>             deriving Show

O tipo Question é composto por um único construtor, Question, que recebe uma
lista de tópicos abordados pela questão (tipo Subject), o enunciado da questão
(tipo Statement) e uma lista das possíveis respostas para a questão (tipo Choice).

Os tipos Subject e Statement são sinônimos para strings.

> type Subject = String
> type Statement = String

O tipo Choice representa um possível item para um questionário e é composto pelo
texto da resposta, uma string, e um booleano que indica se este item é a resposta
correta para a questão.

> data Choice
>   = Choice String Bool
>     deriving Show

O tipo Value denota o total de pontos para a questão considerada e é representado
como um sinônimo para Int.

> type Value = Int

Representamos um questionário por seu nome (tipo String),
o total de pontos distribuídos (tipo Value) e as questões que o compõe.

> data Questionary
>   = Questionary String Value [Question]
>     deriving Show

As respostas para um determinado estudante são representadas pelo tipo AnswerSet que
é composto por um valor de tipo Student, que representa o nome do estudante e uma
lista das respostas do aluno. O tipo Answer representa uma resposta para uma questão
e consiste de um inteiro indicando a alternativa escolhida (construtor TheAnswer) ou
um indicativo que a questão está em branco (construtor Blank).

> data AnswerSet
>   = AnswerSet Student [Answer]
>     deriving Show

> type Student = String

> data Answer
>     = TheAnswer Int
>     | Blank
>     deriving Show

Com base no apresentado, faça o que se pede.

*Questão 1.* Dizemos que uma questão é bem formada se essa possui uma e
apenas uma resposta (campo booleano do tipo Choice igual a verdadeiro)
e uma pontuação não negativa e nem nula. Implemente a função:

-- Estratégia: 
        --Criei duas funcções auxiliares para usar na questão 1 que eu resolvi da seguinte maneira:
        --A ideia foi pegar a questão e verificar primeiro se a pontuação está de acordo
        --depois, com o auxilio das funções auxiliares, verificar se a quantidade de "True" no vetor Choice da questao
        --é igual a 1;

> getBool :: Choice -> Bool
> getBool (Choice _ v) = v

> qtdTrue :: [Choice] -> Int
> qtdTrue [] = 0
> qtdTrue (x : xs) = if getBool x then 1 + qtdTrue xs else qtdTrue xs

> wfQuestion :: Question -> Bool
> wfQuestion (Question _ _ xs v)
>       | v <= 0 = False
>       | (qtdTrue xs)  == 1 = True
>       | otherwise = False           



que determina se uma questão é ou não bem formada de acordo com o critério
apresentado no enunciado desta questão.

Sua implementação deve satisfazer os seguintes casos de teste.

> question1Tests :: TestTree
> question1Tests
>       = testGroup "Question 1"
>               [
>                  testCase "Test question 1 (success):" $
>                               wfQuestion question1 @?= True
>               ,  testCase "Test question 1 (failure):" $
>                               wfQuestion questionf1 @?= False
>               ,  testCase "Test question 1 (failure):" $
>                               wfQuestion questionf2 @?= False
>               ,  testCase "Test question 1 (failure):" $
>                               wfQuestion questionf3 @?= False
>               ]

> question1 :: Question
> question1 = Question ["História"] stmt choices 1
>    where
>      stmt = "Qual a cor do cavalo branco de Napoleão?"
>      choices = [ch1, ch2, ch3]
>      ch1 = Choice "Azul" False
>      ch2 = Choice "Preto" False
>      ch3 = Choice "Branco" True


> questionf1 :: Question
> questionf1 = Question ["História"] stmt choices 1
>    where
>      stmt = "Qual a cor do cavalo branco de Napoleão?"
>      choices = [ch1, ch2, ch3]
>      ch1 = Choice "Azul" False
>      ch2 = Choice "Preto" True
>      ch3 = Choice "Branco" True

> questionf2 :: Question
> questionf2 = Question ["História"] stmt choices 0
>    where
>      stmt = "Qual a cor do cavalo branco de Napoleão?"
>      choices = [ch1, ch2, ch3]
>      ch1 = Choice "Azul" False
>      ch2 = Choice "Preto" False
>      ch3 = Choice "Branco" True


> questionf3 :: Question
> questionf3 = Question ["História"] stmt choices (-2)
>    where
>      stmt = "Qual a cor do cavalo branco de Napoleão?"
>      choices = [ch1, ch2, ch3]
>      ch1 = Choice "Azul" False
>      ch2 = Choice "Preto" False
>      ch3 = Choice "Branco" True


*Questão 2.* Um questionário é bem formado se todas as suas questões são bem
formadas e se o valor total do questionário coincide com a soma das questões
que o compõe. Desenvolva a função

--Estratégia:
        --Similar à questão 1, eu primeiro verifico se o valor do questionario é igual a soma dos valores das questões,
        --aproveitando e verificando se cada uma das questões é bem formada;
        --Caso não seja, eu retorno um número negativo para fazê-lo diferente ao valor do questionario, ou senão retorno a
        --dos valores das questões.

> somaValorQuestoes :: [Question] -> Int
> somaValorQuestoes [] = 0
> somaValorQuestoes (x : xs) = if wfQuestion x then valorQuestao x + somaValorQuestoes xs else -1000
>       where
>               valorQuestao :: Question -> Int
>               valorQuestao (Question _ _ _ v) = v
        

> wfQuestionary :: Questionary -> Bool
> wfQuestionary (Questionary _ v xs)
>       | v /= somaValorQuestoes xs = False
>       | otherwise = True

que determina se um questionário é bem formado ou não.

Sua implementação deve satisfazer os seguintes casos de teste.

> question2Tests :: TestTree
> question2Tests
>    = testGroup "Question 2"
>          [
>             testCase "Test question 2 (success):" $
>                       wfQuestionary question2 @?= True
>          ,  testCase "Test question 2 (failure):" $
>                       wfQuestionary question2a @?= False
>          ,  testCase "Test question 2 (failure):" $
>                       wfQuestionary question2b @?= False
>          ]

> question2 :: Questionary
> question2
>    = Questionary
>         "Teste de história"
>         6
>         [question11, question1]


> question2a :: Questionary
> question2a
>    = Questionary
>         "Teste de história"
>         6
>         [question11, questionf1]


> question2b :: Questionary
> question2b
>    = Questionary
>         "Teste de história"
>         6
>         [question11]

> question11 :: Question
> question11 = Question ["História"] stmt choices 5
>    where
>      stmt = "Qual a cor do cavalo branco de Napoleão?"
>      choices = [ch1, ch2, ch3]
>      ch1 = Choice "Azul" False
>      ch2 = Choice "Preto" False
>      ch3 = Choice "Branco" True


*Questão 3.* Dizemos que as respostas para um estudante são bem formadas se
sua solução possui um valor do tipo Answer para cada valor do tipo Question
presente em um questionário (tipo Questionary). Implemente a função:

--Estratégia:
        --A estratégia que usei foi de comparar a quantidade de respostas do aluno com a quantidade
        --de questõess que o questionario possui

> wfAnswerSet :: Questionary -> AnswerSet -> Bool
> wfAnswerSet (Questionary _ _ qs) (AnswerSet _ as) = 
>       if length qs == length as then True else False 

que determina se as respostas de um estudante (valor de tipo AnswerSet) são
bem formadas.

Sua implementação deve satisfazer os seguintes casos de teste.

> question3Tests :: TestTree
> question3Tests
>       = testGroup "Question 3"
>               [
>                 testCase "Test question 3 (success):" $
>                    wfAnswerSet question2 answer11 @?= True
>               , testCase "Test question 3 (failure):" $
>                    wfAnswerSet question2 answer12 @?= False
>               ]

> answer11 :: AnswerSet
> answer11 = AnswerSet "João da Silva" [TheAnswer 2, TheAnswer 2]

> answer12 :: AnswerSet
> answer12 = AnswerSet "João da Silva" [TheAnswer 2]


*Questão 4.* Uma medida da dificuldade de um teste é a quantidade de
respostas em branco presentes em uma avaliação. Desenvolva a função:

--Estratégia:
        --Para essa questão no array de respostas do aluno eu verifico quantos BLANKS tem e faço o somatorio e retorno o 
        --resultado; Para a solução desta questão, consultei a colega Enya dos Santos, principalmente quanto a utilização
        --dos construtores;

> countBlanks :: AnswerSet -> Int
> countBlanks (AnswerSet _ xs) = qtdBlanks xs
>       where
>               qtdBlanks :: [Answer] -> Int
>               qtdBlanks [] = 0
>               qtdBlanks (x : ys) = if isBlank x then 1 + qtdBlanks ys else qtdBlanks ys
>
>               isBlank :: Answer -> Bool
>               isBlank Blank = True
>               isBlank (TheAnswer _) = False


que conta o número de respostas deixadas em branco em uma avaliação
entregue por um aluno. Sua implementação deve satisfazer os seguintes
casos de teste.

> question4Tests :: TestTree
> question4Tests
>       = testGroup "Question 4"
>               [
>                 testCase "Test question 4 (1)" $ countBlanks answer13 @?= 1
>               , testCase "Test question 4 (0)" $ countBlanks answer11 @?= 0
>               ]

> answer13 :: AnswerSet
> answer13 = AnswerSet "João da Silva" [TheAnswer 2, Blank]


*Questão 5.* Em bancos de questões, uma funcionalidade importante é
a de selecionar questões de um determinado tópico. O banco de questões
é representado pelo tipo QuestionDB:

> type QuestionDB = [Question]

--Estratégia:
        --A estratégia foi verificar para todos os subjects da questão se algum era igual ao subject que queria filtrar
        --e então retorna uma lista com todas as questões do subject desejado

Implemente a função

> selectBySubject :: Subject -> QuestionDB -> [Question]
> selectBySubject sub
>     = foldr step base
>       where
>         step x ac = if compSubject x sub then x : ac else ac
>         base = []
>         compSubject :: Question -> Subject -> Bool
>         compSubject (Question x _ _ _) sub' = verificarSubjects x sub'
>         verificarSubjects :: [Subject] -> Subject -> Bool 
>         verificarSubjects [] _ = False
>         verificarSubjects (y : ys) sub'' = if y == sub'' then True else verificarSubjects ys sub'' 

que seleciona todas as questões de um tópico fornecido como
entrada. Sua implementação deve ser feita obrigatoriamente usando
o template acima, usando foldr. Caso julgue necessário inclua uma
variável para representar o primeiro parâmetro de entrada para a
função selectBySubject.

Sua implementação deve satisfazer os seguintes casos de teste.

> questionDB :: QuestionDB
> questionDB = [ question1
>              , question5]


> question5 :: Question
> question5 = Question ["Math"] stmt choices 5
>    where
>      stmt = "Quanto é 2 + 2?"
>      choices = [ch1, ch2, ch3]
>      ch1 = Choice "0" False
>      ch2 = Choice "22" False
>      ch3 = Choice "4" True



> question5Tests :: TestTree
> question5Tests
>       = testGroup "Question 5"
>                   [
>                      testCase "Question 5 (non-empty):" $
>                         length (selectBySubject "Math" questionDB) @?= 1
>                   ,  testCase "Question 5 (empty) $ " $
>                         length (selectBySubject "Geo" questionDB) @?= 0
>                   ]

Parte 2. Relatórios
-------------------

A segunda parte desta avaliação consiste em construir um conjunto de funções
para calcular o resultado obtido por alunos e também a impressão de um
relatório contendo as notas obtidas no teste.

*Questão 6.* Uma tarefa fundamental de uma aplicação para formular testes é
a sua correção. Desenvolva a função

--Estratégia:
        --A estratégia que usei foi verificar cada resposta com sua respectiva questão, e dentro da questão eu percorrir
        --o array de choices para saber se a escolha dele era True ou False de acordo com a posição que ele informou;
        --Caso a resposta fosse True faz o somatorio das notas;
        --Parti do princípio de que todos os questionarios e respostas são bem formados;

> grade :: Questionary -> AnswerSet -> Int
> grade (Questionary _ _ qs) (AnswerSet _ as) = calcularNota qs as
>       where
>         calcularNota :: [Question] -> [Answer] -> Int
>         calcularNota [] _ = 0
>         calcularNota _ [] = 0
>         calcularNota (q : qs') (a : as') = verificaQuestao q a + calcularNota qs' as'
>
>         verificaQuestao :: Question -> Answer -> Int
>         verificaQuestao _ Blank = 0
>         verificaQuestao (Question _ _ cs v) (TheAnswer i) = verificaResposta cs v i
>
>         verificaResposta :: [Choice] -> Int -> Int -> Int
>         verificaResposta [] _ _ = 0
>         verificaResposta (c : cs') v' i'
>               |i' == 0 = if getBool c then v' else 0
>               |otherwise = verificaResposta cs' v' (i'-1)

que calcula a nota obtida por um aluno ao realizar um teste. A nota é calculada
pela soma da pontuação das respostas corretas do aluno.

Sua implementação deve satisfazer os seguintes casos de teste:

> question6Tests :: TestTree
> question6Tests
>       = testGroup "Question 6"
>               [
>                  testCase "Question 6 (success):" $
>                       grade question2 answer11 @?= 6
>               ,  testCase "Question 6 (blank):" $
>                       grade question2 answer12 @?= 5
>               ]


O seguinte tipo de dados representa os testes resolvidos por uma
classe de alunos.

> data Class
>   = Class Questionary [AnswerSet]
>     deriving Show

Uma importante tarefa deste sistema de elaboração de provas é construir um
relatório de notas, que deve conter o nome e a respectiva nota de cada aluno.
As próximas questões envolverão a tarefa de construir uma string que representa
esse relatório de notas de uma turma.

*Questão 7.* Para construir o relatório de notas, um primeiro passo é calcular
as notas de uma turma. Representaremos as notas de uma turma usando o tipo
a seguir:

--Estratégia:
        --Usei a função do exercicio anterior para pegar a nota e criei uma nova funcao para pegar o nome do estudante
        --e criei a tupla e coloquei numa lista de retorno

> type Report = [(Student, Int)]

O tipo Report consiste de uma lista de pares formados pelo nome de um estudante
e de sua respectiva nota em um teste. Desenvolva a função

--Funcao auxiliar

> getStudent :: AnswerSet -> Student
> getStudent (AnswerSet nome _) = nome

> createReport :: Class -> Report
> createReport (Class q as) = listaAlunos q as
>       where
>         listaAlunos :: Questionary -> [AnswerSet] -> [(Student, Int)]
>         listaAlunos _ [] = []
>         listaAlunos q' (a : as') = (getStudent a, grade q' a) : listaAlunos q' as'




que constrói um valor de tipo Report a partir dos resultados da aplicação de um
questionário (representado pelo tipo Class).

Sua implementação deve satisfazer os seguintes casos de teste.


> exampleClass :: Class
> exampleClass = Class questionary answers

> questionary :: Questionary
> questionary = Questionary "Math" 10
>                       [
>                         questiona
>                       , questionb
>                       ]

> questiona :: Question
> questiona =  Question ["Math"] stmt choices 5
>    where
>      stmt = "Quanto é 2 + 2?"
>      choices = [ch1, ch2, ch3]
>      ch1 = Choice "0" False
>      ch2 = Choice "22" False
>      ch3 = Choice "4" True


> questionb :: Question
> questionb =  Question ["Math"] stmt choices 5
>    where
>      stmt = "Quanto é 1 + 1?"
>      choices = [ch1, ch2, ch3]
>      ch1 = Choice "0" False
>      ch2 = Choice "11" False
>      ch3 = Choice "2" True


> answerj :: AnswerSet
> answerj = AnswerSet "João da Silva" [TheAnswer 1, Blank]

> answerm :: AnswerSet
> answerm = AnswerSet "Ana Maria" [TheAnswer 2, TheAnswer 2]

> answers :: [AnswerSet]
> answers = [answerj, answerm]

> question7Tests :: TestTree
> question7Tests
>       = testGroup "Question 7"
>               [
>                  testCase "Question 7 result" $
>                       createReport exampleClass @?= [("João da Silva", 0),
>                                                      ("Ana Maria" , 10)]
>               ]

As próximas questões envolvem a criação de uma string que representa o relatório
de notas de uma turma. Um exemplo de tal relatório é apresentado a seguir.

````
+------------+------+
| Nome       | Nota |
+------------+------+
| João Silva | 0    |
+------------+------+
| Ana Maria  | 10   |
+------------+------+
````

*Questão 8.* Observe que para construir esse relatório é necessário calcular o
tamanho das colunas referentes ao nome do aluno e sua respectiva nota.
Desenvolva a função

--Estratégia:
        --Verifiquei com auxilio de uma variavel auxiliar qual a maior String Students de cada uma das tuplas
        --da lista do Report; Para o segundo valor, como no exemplo abaixo, deixei 4 "NOTA"


> type ColumnSize = (Int, Int)

> columnsSize :: Report -> ColumnSize
> columnsSize [] = (0, 0)
> columnsSize xs = (maiorNomeTam xs 0, 4)
>       where
>         maiorNomeTam :: Report -> Int -> Int
>         maiorNomeTam [] tam = tam
>         maiorNomeTam (x : xs') tam = if (length (fst x )) > tam then maiorNomeTam xs' (length  (fst x)) else maiorNomeTam xs' tam


que retorna um par correspondente ao tamanho das duas colunas da tabela de notas.

A sua implementação deve satisfazer o seguinte caso de teste:

> rep :: Report
> rep = [("João da Silva", 0), ("Ana Maria" , 10)]

> question8Tests :: TestTree
> question8Tests
>       = testGroup "Question 8"
>               [
>                  testCase "Question 8 result:" $
>                       columnsSize rep @?= (13, 4)
>               ]

*Questão 9.* De posse do tamanho das colunas e da informação de nota de um aluno,
podemos gerar a string correspondente a uma linha do relatório. Desenvolva a
função

--Estratégia:
        --Consultei esse site para ver como exibir um número Int como String/[char]
        --"https://programming-idioms.org/idiom/55/convert-integer-to-string/955/haskell"
        --A estratégia foi escrever o nome do aluno e preencher com espaços o restante de carcteres que faltam
        --para o total de carcteres possiveis da coluna que também é informado. o mesmo faço para a nota;

> lineReport :: (Student, Int) -> ColumnSize -> String
> lineReport (nome, nota) (e , _) = gerarLinha 
>       where
>         gerarLinha :: String
>         gerarLinha = "| " ++ gerarLinhaNome ++ " | " ++ gerarLinhaNota ++ " |"
>
>         espNome = e - length nome 
>         gerarLinhaNome :: String
>         gerarLinhaNome = nome ++ gerarEspaço espNome
>
>         espNota = if nota < 10 then 3 else if nota < 100 then 2 else 1
>         gerarLinhaNota ::  String
>         gerarLinhaNota
>                |nota == -111 = "Nota"
>                |otherwise =  show nota ++ gerarEspaço espNota
>
>         gerarEspaço :: Int -> String
>         gerarEspaço esp = if esp <= 0 then "" else " " ++ gerarEspaço (esp - 1)

que irá produzir a string correspondente a uma linha da tabela de notas.

A sua implementação deve satisfazer o seguinte caso de teste:

> question9Tests :: TestTree
> question9Tests
>       = testGroup "Question 9"
>               [
>                 testCase "Question 9 result:" $
>                   lineReport ("João da Silva", 0) (13, 4) @?= lineRep
>               ]

> lineRep :: String
> lineRep = "| João da Silva | 0    |"

*Questão 10.* Utilizando as funções anteriores, desenvolva a função

--Estratégia:
        --Utilizando as funções dos exercicios anteriores, imprimi, no formato apresentado no fim do arquivo, cada aluno
        --e sua respectiva nota

> printReport :: Class -> String
> printReport classe = criarTabela
>       where
>         criarTabela :: String
>         criarTabela = cabecario ++ dadoAlunos 
>
>         cabecario :: String
>         cabecario = "+" ++ gerarEntreLinhasNome (tam + 2) ++ gerarEntreLinhasNota 6 ++ lineReport ("Nome  ", -111) tamanhoColuna ++ "\n+" ++ gerarEntreLinhasNome (tam + 2) ++ gerarEntreLinhasNota 6 
>
>         tam = fst tamanhoColuna
>
>         gerarEntreLinhasNome :: Int -> String
>         gerarEntreLinhasNome 0 =  "+" 
>         gerarEntreLinhasNome tracos = "-" ++ gerarEntreLinhasNome (tracos - 1)
>
>         gerarEntreLinhasNota :: Int -> String
>         gerarEntreLinhasNota 0 =  "+\n" 
>         gerarEntreLinhasNota tracos = "-" ++ gerarEntreLinhasNota (tracos - 1)
>
>         tamanhoColuna = columnsSize (createReport classe)
>
>         dadoAlunos :: String
>         dadoAlunos = gerarReport
>
>         gerarReport :: String 
>         gerarReport = imprimirReport  (createReport classe)
>
>
>         imprimirReport :: Report -> String
>         imprimirReport [] = ""
>         imprimirReport (x : xs) =  lineReport x tamanhoColuna ++ "\n+" ++ gerarEntreLinhasNome (tam + 2) ++ gerarEntreLinhasNota 6 ++ imprimirReport xs


que produz a string correspondente ao relatório de notas das avaliações de uma
turma representada por um valor de tipo Class.

Sua implementação deve satisfazer o seguinte caso de teste:

> question10Tests :: TestTree
> question10Tests
>       = testGroup "Question 10"
>               [
>                 testCase "Question 10 result:" $
>                    printReport exampleClass @?= tableRep
>               ]


> tableRep :: String
> tableRep
>  = concat ["+---------------+------+\n"
>           ,"| Nome          | Nota |\n"
>           ,"+---------------+------+\n"
>           ,"| João da Silva | 0    |\n"
>           ,"+---------------+------+\n"
>           ,"| Ana Maria     | 10   |\n"
>           ,"+---------------+------+\n"]
