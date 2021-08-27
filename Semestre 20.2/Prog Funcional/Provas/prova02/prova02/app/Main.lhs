Avaliação 2 de Programação Funcional
========================

ATENÇÃO
-------

* A interpretação dos enunciados faz parte
da avaliação.

* A avaliação deve ser resolvida INDIVIDUALMENTE.
Não serão tolerados plágios de nenhum tipo.

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
atividade "Entrega da Avaliação 2" no Moodle dentro do
prazo estabelecido.

4. É de responsabilidade do aluno a entrega da solução
dentro deste prazo.

5. Sob NENHUMA hipótese serão aceitas soluções fora do
prazo ou entregues usando outra ferramenta que
não a plataforma Moodle.

6. Não será aceito o envio de soluções em formato ".hs".
Avaliações enviadas nesse formato não serão consideradas
para correção.


Setup inicial
-------------

> {-# OPTIONS_GHC -Wall #-}

> module Main where

> import Data.Time.Clock
> import Data.Time.Calendar
> import ParseLib
> import System.Environment (getArgs)

Gerenciador de tarefas
======================

Introdução
----------

O objetivo dessa avaliação é a criação de uma ferramenta de linha
de comando para o gerenciamento de tarefas. A ferramenta a ser implementada
lerá um arquivo contendo as tarefas e produzirá um relatório contendo:

1. Tarefas atrasadas.
2. Tarefas que devem ser concluídas no dia atual.
3. Tarefas a serem concluídas até a próxima semana.

Para concluir a implementação dessa ferramenta, desenvolva os exercícios
especificados a seguir.

*Questão 1.* *(Valor 3,0 pontos).* Uma importante tarefa em um software para gestão de tarefas é
a correta manipulação de datas. O tipo `Date` representa datas formadas
por seu dia, mês e ano.

> data Date
>  = Date {
>      day   :: Int
>    , month :: Int
>    , year  :: Int
>    } deriving Eq

a) *(Valor 0,5 ponto)* Implemente uma instância de `Show` para o tipo `Date` de forma que
uma data seja exibida no formato DD/MM/YYYY, em que DD denota o dia,
MM o mês e YYYY o ano.

--Estratégia:
    Concatenar os valores inteiros exibidos como strings com o show com as "/", conforme pede o enunciado

> instance Show Date where
>    show (Date dia mes ano) = show dia ++ "/" ++ show mes ++ "/" ++ show ano


b) *(Valor 0,5 ponto)* Outra tarefa importante sobre o tipo data é comparação entre valores. Para isso,
implemente uma instância de `Ord` para o tipo `Date`. Para implementar a instância de
`Ord` basta implementar a função `<=` para datas.

--Estratégia: 
    Para verificar se a primeira data é menor ou igual a outra eu faço uma análise do fim pro inicio. Primeiro verifico se o ano for maior.
    Se for, a data é maior, caso contrário, verifico se o ano é igual e o mes é maior, se for a data é maior, caso contrario verifico se
    o dia é maior e o mes e o ano é igual, caso sejam a data é maior, caso contrario a data é menor ou igual;

> instance Ord Date where
>    (Date d1 m1 a1) <= (Date d2 m2 a2) 
>       | a1 > a2  = False
>       | m1 > m2 && a1 == a2 = False
>       | d1 > d2 && m1 == m2 && a1 == a2 = False
>       | otherwise = True

c) *(Valor 1,0 ponto)* A função a seguir obtém o valor da data atual:

> currentDate :: IO Date
> currentDate
>       = f <$> getCurrentTime
>         where
>           g (y,m,d) = Date d m (fromInteger y)
>           f = g . toGregorian . utctDay

Observe que essa função utiliza o tipo `IO` e,
portanto, realiza uma operação de entrada e saída.
Além disso, ela deve ser chamada dentro de um bloco `do`.

Usando a função `currentDate` como modelo, implemente a função

--Estratégia:
    Como estratégia eu considerei que todos os meses possuem 30 dias (visto que eu procurei na internet e não achei alguma
    função que adicione 7 dias ap tipo Date ~ Encontrei, entretanto, uma que adicione a variável tipo Day, porem dá erro de
    tipo). Analisei se os dias haviam passado de 30 e também se o mês havia passado de 12.
    Visitei esse site: https://docs.w3cub.com/haskell~7/libraries/time-1.5.0.1/data-time-calendar


> sevenDaysAfter :: IO Date
> sevenDaysAfter = f <$> getCurrentTime
>         where
>           g (y,m,d) = calculaSeteDias (d + 7) m (fromInteger y) 
>           f = g . toGregorian . utctDay
>           calculaSeteDias :: Int -> Int -> Int -> Date
>           calculaSeteDias d' m' y'
>               | d' > 30 && m' == 12 = Date (d' - 30) 1 (y'+1)
>               | d' > 30 && m' < 12 = Date (d'-30) (m'+1) y'
>               | otherwise = Date d' m' y'
                       

que retorna a data correspondente a sete dias depois da data
atual.

d) *(Valor 1,0 ponto)* Considerando o formato textual de datas, implemente
um parser para o tipo `Date`.

--Estratégia:
    Para a solução dessa questão, visitei ao site https://stackoverflow.com/questions/2468410/convert-string-to-integer-float-in-haskell
    para pegar referências e, além disso, peguei como base o conteúdo explicado na última aula síncrona do dia (21/07/2021)
    disponível no drive/moodle. A ideia foi ler repetidadamente dois primeiros valores, ler e ignorar a barra, repetir para
    os dois outros valores e depois ler repetidadamente os 4 ultimos valores; São lidos como lista de CHAR, então para
    converter para Int utilizo a função read (conforme exemplificado no site linkado);

> parseDate :: Parser Char Date
> parseDate =  dataConvertida
>   where
>       dataConvertida = f <$> two <*> slash <*> two <*> slash <*> four
>       two = repeatParser 2 digitChar
>       four = repeatParser 4 digitChar
>       slash = symbol '/'
>       f d _ m _ y = Date (read d) (read m) (read y)


> repeatParser :: Int -> Parser s a -> Parser s [a]
> repeatParser 0 _ = pure []
> repeatParser n p = (:) <$> p <*> repeatParser (n - 1) p

As próximas questões irão envolver o tipo `Task` que representa
uma tarefa armazenada em um arquivo fornecido como entrada.

> data Task
>    = Task {
>        deadline    :: Date
>      , description :: String
>      }  deriving (Eq, Ord)

O significado dos campos do tipo `Task` é como se segue: `deadline`
especifica a data limite para a realização da tarefa e `description`
a descrição textual da tarefa em questão.

Tarefas são representadas textualmente de forma simples: primeiro
especificamos a data limite para a tarefa, seguida de um ou mais espaços
e de sua descrição. Usamos o caractere de ';' para separar diferentes
tarefas em uma mesma string.
A seguir, apresentamos um exemplo deste formato de tarefas:

```
28/06/2021 Tarefa 1 ;
26/07/2021 Tarefa 2 ;
02/08/2021 Tarefa 3 ;
```


*Questão 2.* *(Valor 1,0 ponto)* Desenvolva uma instância de `Show` para o tipo `Task` que
produza uma string idêntica à sua descrição textual.

--Estratégia:
    utilizando o show da Data feito anteriormente, concacteno com a string com a descricao da tarefa;

> instance Show Task where
>    show (Task deadl descricao )= show deadl ++ " " ++ descricao;


*Questão 3.* *(Valor 3,0 pontos)*Com base no formato do arquivo de tarefas, construa um parser
que o processe e retorne uma lista das tarefas nele armazenadas.

--Estratégia:
    para a realização dessa atividade, consultei dois colegas a Enya e o Andre em relação ao funcionamento da listOf
    sua sintaxe e como se comporta e tratamentos de espacos e quebras de linha; A ideia é pegar a string de entrada e fazer o parser pra saber se a formatação está
    como desejada, caso esteja é adicionado à lista de task;

> taskFileParser :: Parser Char [Task]
> taskFileParser = f <$> listOf taskParser (symbol ';') <*> pv
>   where
>       f = (\x _ -> x)
>       pv = symbol ';'

> taskParser :: Parser Char Task
> taskParser = f <$> many(espaco <|> quebraLinha) <*> parseDate <*> many (symbol ' ') <*> greedy descricao 
>   where
>       espaco = symbol ' '
>       quebraLinha = symbol '\n'      
>       descricao = sat isSymbol
>       isSymbol :: Char -> Bool
>       isSymbol s = if (s == ';') then False else True
>       f _ d _ des  = Task d des


*Questão 4.* *(Valor 1,0 ponto)* O objetivo desta questão é a produção de um relatório contendo
as tarefas atrasadas, que devem ser concluídas na data atual e que
devem ser concluídas em até 7 dias. O tipo `Report` agrupa essas informações:

> data Report
>   = Report {
>       late  :: [Task]
>     , today :: [Task]
>     , nexts :: [Task]
>     } deriving Show

Desenvolva a função

--Estratégia:
    A estratégia foi ler, a partir de uma lista de tarefas, tarefa por tarefa e gerar um Report novo que passei
    no inicio com todos os valores vazios; Ao tentar comparar com a data atual, utilizando o CurrentDate, deu erro  
    de tipo  por esperar um tipo Date e receber IO Date. Tentei achar na internet material auxiliar, porém não o consegui.
    Então, utilizei como método de comparação dos prazos das atvidades uma data do tipo Date FIXA no dia de hoje (26/07/2021).
    Comparei as datas verificando se elas eram maiores ou menores em relação uma a outra;

> menor :: Date -> Date -> Bool
> menor (Date d1 m1 a1)  (Date d2 m2 a2) 
>       | a1 > a2  = False
>       | m1 > m2 && a1 == a2 = False
>       | d1 >= d2 && m1 == m2 && a1 == a2 = False
>       | otherwise = True
>
> report :: [Task] -> Report
> report listT = analiseR listT (Report [] [] []) 
>   where
>       analiseR :: [Task] -> Report -> Report
>       analiseR [] r = r
>       analiseR (x : xs) r =  analiseR xs (verificaData x r)
>       verificaData :: Task -> Report -> Report
>       verificaData (Task d des) (Report l t n)
>           | (d <= (Date 26 07 2021)) == False = (Report l t ((Task d des) : n))
>           | (menor d (Date 26 07 2021)) == True = (Report ((Task d des) : l) t n)
>           | otherwise = (Report l ((Task d des) : t) n)

*Questão 5.* *(Valor 1,0 ponto)* O resultado final da ferramenta é um relatório classificando as tarefas.
Considerando o seguinte arquivo de modelo:

```
18/06/2021 Tarefa 1 ;
26/07/2021 Tarefa 2 ;
30/07/2021 Tarefa 3 ;
```

Temos que a Tarefa 1 está atrasada, a Tarefa 2 possui deadline para hoje e a
Tarefa 3 deve ser concluída em até 7 dias. Sua ferramenta deverá apresentar
o seguinte relatório

````
Tarefas atrasadas:

18/06/2021 Tarefa 1 ;

Tarefas para hoje:

26/07/2021 Tarefa 2;

Tarefas para concluir em uma semana:

30/07/2021 Tarefa 3
````

A partir da descrição anterior, implemente a função:

--Estratégia:
    A estratégia foi pegar do report cada lista referente às tarefas atrasadas, que iriam vencer hoje ou as que ainda 
    há prazo para serem realizadas e imprimir conforme o modelo acima.


> printReport :: Report -> String
> printReport (Report l t n) = "Tarefas atrasadas: \n\n" ++ printL l ++  "Tarefas para hoje: \n\n"
>                                ++ printT t ++ "Tarefas para concluir em uma semana: \n\n" ++ printN n
>   where
>       printL :: [Task] -> String
>       printL [] = ""
>       printL (x : xs) = printL xs ++ show x ++ " ;\n\n" 
>       printT :: [Task] -> String
>       printT [] = ""
>       printT (x' : xs') = printL xs' ++ show x' ++ ";\n\n" 
>       printN :: [Task] -> String
>       printN [] = ""
>       printN (x'' : xs'') = printL xs'' ++ show x'' ++ "\n\n" 

que gera uma string no formato apresentado para os dados do relatório
(valor do tipo `Report`).


*Questão 6.* *(Valor 1,0 ponto)* De posse de todas as implementações anteriores, implemente
a função `main` de sua ferramenta:

--Estratégia:
    Para a realização dessa estratégia consultei minha colega Enya sobre possiveis soluções.
    A ideia é ler o arquivo atraves dos argumentos, pegar o argumento referente ao caminho do arquivo, e fazer o Parser
    com o arquivo e vai retornar a lista de tuplas (com a lista de task e uma lista char). A primeira tupla é a que contem
    a lista completa, portanto pego a primeira tupla e pego o primeiro elemento da tupla que é a lista de task e crio O
    report atraves dela e gero o printReport e escrevo na tela; 

> main :: IO ()
> main = 
>       do
>        args <- getArgs
>        contents <- readFile (fileName args)
>        let ln = runParser taskFileParser contents
>        putStrLn $ printReport(report (pegarTask ln))

> pegarTask :: [(a, b)] -> a
> pegarTask x = fst (head x) 

> fileName :: [String] -> String
> fileName [] = ""
> fileName (h : _) = h

A partir de um nome de arquivo, sua ferramenta deverá lê-lo, realizar
seu parsing e exibir o relatório de tarefas. Para obter o nome de arquivo,
você deverá usar a função `getArgs`, para obter os argumentos passados
por linha de comando para sua ferramenta.

Para executar seu programa usando o stack e passar argumentos de linha
de comando basta:

```
stack exec prova02-exe -- argumento
```

em que argumento é o valor que você deseja passar como argumento adicional para
a execução de seu programa.
